/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu);
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.IO;
using System.Web;
using System.Threading;
using OwLib;
using System.Net.Sockets;
using FaceCat;

namespace FaceCat {
    /// <summary>
    /// Http����
    /// </summary>
    public class FCHttpData {
        public bool m_close;
        public int m_contentLength;
        public String m_contentType = "";
        public byte[] m_body;
        public String m_method = "";
        public HashMap<string, string> m_parameters = new HashMap<string, string>();
        public byte[] m_resBytes;
        public String m_resStr;
        public String m_remoteIP;
        public int m_remotePort;
        public int m_socketID;
        public int m_statusCode = 200;
        public String m_url = "";
    }

    /// <summary>
    /// �ļ�Http����
    /// </summary>
    public class HttpFileData {
        /// <summary>
        /// ��
        /// </summary>
        public byte[] m_buffer;

        /// <summary>
        /// ���յ�����
        /// </summary>
        public long m_recvLength;

        /// <summary>
        /// �ܳ���
        /// </summary>
        public long m_totalLength;
    }

    /// <summary>
    /// Node����
    /// </summary>
    public class FCHttpMonitor {
        /// <summary>
        /// ����Node����
        /// </summary>
        /// <param name="fileName">�ļ���</param>
        public FCHttpMonitor(string fileName) {
            m_fileName = fileName;
        }

        /// <summary>
        /// �򵥷���
        /// </summary>
        public static HashMap<String, FCHttpEasyService> m_easyServices = new HashMap<String, FCHttpEasyService>();

        /// <summary>
        /// �ļ�����
        /// </summary>
        private String m_fileName;

        /// <summary>
        /// �ű�����
        /// </summary>
        public Stack<FCScript> m_indicators = new Stack<FCScript>();

        /// <summary>
        /// ���ݼ���
        /// </summary>
        public HashMap<int, FCHttpData> m_httpDatas = new HashMap<int, FCHttpData>();

        private FCScript m_indicator;

        /// <summary>
        /// ��ȡ���ű�
        /// </summary>
        public FCScript Indicator {
            get { return m_indicator; }
        }

        private Socket m_listener;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        public Socket Listener {
            get { return m_listener; }
        }

        private static FCHttpMonitor m_mainMonitor;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns></returns>
        public static FCHttpMonitor MainMonitor {
            get { return m_mainMonitor; }
        }

        private int m_port = 8080;

        /// <summary>
        /// ��ȡ�����ö˿�
        /// </summary>
        public int Port {
            get { return m_port; }
            set { m_port = value; }
        }

        private string m_script;

        /// <summary>
        /// ��ȡ�ű�
        /// </summary>
        public string Script {
            get { return m_script; }
        }

        private FCNative m_native;

        /// <summary>
        /// ��ȡXML����
        /// </summary>
        public FCNative Native {
            get { return m_native; }
        }

        private bool m_useScript;

        /// <summary>
        /// �Ƿ�ʹ�ýű�
        /// </summary>
        public bool UseScript {
            get { return m_useScript; }
        }

        /// <summary>
        /// ���ű�
        /// </summary>
        public void checkScript() {
            String newScript = "";
            FCFile.read(m_fileName, ref newScript);
            if (m_script != newScript) {
                Console.WriteLine("��⵽�ű����޸�...");
                m_script = newScript;
                lock (m_indicators) {
                    while (true) {
                        try {
                            FCScript indicator = m_indicators.Pop();
                            indicator.delete();
                        }
                        catch {
                            break;
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="param">����</param>
        private static void readData(object param) {
            Socket socket = (Socket)param;
            FCHttpMonitor nodeService = FCHttpMonitor.MainMonitor;
            int newSocketID = (int)socket.Handle;
            try {
                byte[] buffer = new byte[102400];
                int len = socket.Receive(buffer);
                MemoryStream memoryStream = new MemoryStream(buffer);
                StreamReader reader = new StreamReader(memoryStream);
                FCHttpData data = new FCHttpData();
                data.m_remoteIP = ((IPEndPoint)socket.RemoteEndPoint).Address.ToString();
                data.m_remotePort = ((IPEndPoint)socket.RemoteEndPoint).Port;
                String requestHeader;
                int contentLength = 0;
                string parameters = "";
                while ((requestHeader = reader.ReadLine()) != null && !String.IsNullOrEmpty(requestHeader)) {
                    String lowerHeader = requestHeader.ToLower();
                    if (lowerHeader.IndexOf("get") == 0) {
                        int end = lowerHeader.IndexOf("http/");
                        data.m_method = "GET";
                        parameters = requestHeader.Substring(5, end - 6);
                    }
                    else if (lowerHeader.IndexOf("post") == 0) {
                        int end = lowerHeader.IndexOf("http/");
                        data.m_method = "POST";
                        parameters = requestHeader.Substring(5, end - 6);
                    }
                    else if (lowerHeader.IndexOf("accept: ") == 0) {
                        try {
                            data.m_contentType = requestHeader.Substring(8, requestHeader.IndexOf(',') - 8);
                        }
                        catch { }
                    }
                    else if (lowerHeader.IndexOf("content-type:") == 0) {
                        data.m_contentType = requestHeader.Substring(14);
                    }
                    else if (lowerHeader.IndexOf("host:") == 0) {
                        data.m_url = requestHeader.Substring(requestHeader.IndexOf(':') + 2);
                    }
                    else if (lowerHeader.IndexOf("content-length") == 0) {
                        int begin = lowerHeader.IndexOf("content-length:") + "content-length:".Length;
                        String postParamterLength = requestHeader.Substring(begin).Trim();
                        contentLength = Convert.ToInt32(postParamterLength);
                    }
                }
                if (contentLength > 0) {
                    int idx = 0, ide = 0;
                    data.m_body = new byte[contentLength];
                    while (idx < contentLength) {
                        int recvData = reader.Read();
                        if (recvData != -1) {
                            if (recvData != 0) {
                                ide++;
                            }
                            idx++;
                        }
                        else {
                            break;
                        }
                    }
                    reader.Close();
                    memoryStream.Dispose();
                    if (ide == 0) {
                        socket.Receive(data.m_body);
                    }
                    else {
                        for (int i = 0; i < contentLength; i++) {
                            data.m_body[i] = buffer[len - contentLength + i];
                        }
                    }
                    data.m_contentLength = contentLength;
                }
                else {
                    reader.Close();
                    memoryStream.Dispose();
                }
                if (data.m_method.Length == 0) {
                    return;
                }
                int cindex = parameters.IndexOf('?');
                if (cindex != -1) {
                    data.m_url = data.m_url + "/" + parameters;
                    parameters = parameters.Substring(cindex + 1);
                    String[] strs = parameters.Split(new string[] { "&" }, StringSplitOptions.RemoveEmptyEntries);
                    int strsSize = strs.Length;
                    for (int i = 0; i < strsSize; i++) {
                        String[] subStrs = strs[i].Split(new string[] { "=" }, StringSplitOptions.RemoveEmptyEntries);
                        data.m_parameters.put(subStrs[0].ToLower(), subStrs[1]);
                    }
                }
                else {
                    data.m_url += "/" + parameters;
                }
                FCScript indicator = null;
                if (nodeService.UseScript) {
                    try {
                        lock (nodeService.m_indicators) {
                            indicator = nodeService.m_indicators.Pop();
                        }
                    }
                    catch {
                        indicator = CFunctionEx.CreateScript(nodeService.Script, nodeService.Native);
                    }
                    ArrayList<CFunction> functions = indicator.getFunctions();
                    int functionsSize = functions.Count;
                    for (int i = 0; i < functionsSize; i++) {
                        CFunctionHttp function = functions.get(i) as CFunctionHttp;
                        if (function != null) {
                            function.m_data = data;
                        }
                    }
                }
                data.m_socketID = newSocketID;
                lock (nodeService.m_httpDatas) {
                    nodeService.m_httpDatas.put(newSocketID, data);
                }
                if (indicator != null) {
                    indicator.callFunction("ONHTTPREQUEST();");
                }
                if (data.m_close) {
                    return;
                }
                int resContentLength = 0;
                if (data.m_resBytes != null) {
                    resContentLength = data.m_resBytes.Length;
                }
                else {
                    if (data.m_resStr != null) {
                        resContentLength = Encoding.Default.GetBytes(data.m_resStr).Length;
                    }
                }
                StringBuilder bld = new StringBuilder();
                bld.Append("HTTP/1.0 " + data.m_statusCode.ToString() + " OK\r\n");
                bld.Append(String.Format("Content-Length: {0}\r\n", resContentLength));
                bld.Append("Connection: close\r\n\r\n");
                if (data.m_resBytes != null) {
                    socket.Send(Encoding.Default.GetBytes(bld.ToString()));
                    socket.Send(data.m_resBytes);
                }
                else {
                    bld.Append(data.m_resStr);
                    socket.Send(Encoding.Default.GetBytes(bld.ToString()));
                }
                if (indicator != null) {
                    lock (nodeService.m_indicators) {
                        nodeService.m_indicators.Push(indicator);
                    }
                }
            }
            catch (Exception ex) {
                Console.WriteLine(ex.Message + "\r\n" + ex.StackTrace);
            }
            finally {
                lock (nodeService.m_httpDatas) {
                    nodeService.m_httpDatas.Remove(newSocketID);
                }
                socket.Close();
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        public void start() {
            m_useScript = FCFile.isFileExist(m_fileName);
            if (m_useScript) {
                m_native = new FCNative();
                FCFile.read(m_fileName, ref m_script);
                m_indicator = CFunctionEx.CreateScript(m_script, m_native);
                Console.WriteLine(m_script);
            }
            try {
                //string host = "127.0.0.1";
                //IPAddress ip = IPAddress.Parse(host);
                if (m_indicator != null) {
                    m_indicator.callFunction("ONHTTPSERVERSTARTING('" + m_fileName + "');");
                }
                IPEndPoint ipe = new IPEndPoint(IPAddress.Any, m_port);

                m_listener = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                m_listener.Bind(ipe);
                m_listener.Listen(0);
            }
            catch (Exception ex) {
                if (m_indicator != null) {
                    m_indicator.callFunction("ONHTTPSERVERSTARTFAIL('" + ex.Message + "\r\n" + ex.StackTrace + "');");
                }
                return;
            }
            int minThreadNum = 0, portThreadNum = 0, maxThreadNum = 0;
            ThreadPool.GetMaxThreads(out maxThreadNum, out portThreadNum);
            ThreadPool.GetMinThreads(out minThreadNum, out portThreadNum);
            if (m_indicator != null) {
                m_indicator.callFunction("ONHTTPSERVERSTART(" + FCStr.convertIntToStr(maxThreadNum) + "," + FCStr.convertIntToStr(minThreadNum) + ");");
            }
            while (true) {
                Socket socket = m_listener.Accept();
                ThreadPool.QueueUserWorkItem(new WaitCallback(readData), socket);
            }
            m_listener.Close();
        }
    }
}