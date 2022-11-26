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
using System.IO.Compression;
using OwLib;
using System.IO;
using System.Runtime.InteropServices;
using System.Threading;

namespace FaceCat
{
    /// <summary>
    /// HTTP��POST����
    /// </summary>
    public class FCHttpPostService : FCClientService
    {
        /// <summary>
        /// ����HTTP����
        /// </summary>
        public FCHttpPostService()
        {
        }

        private bool m_isSyncSend;
        /// <summary>
        /// ��ȡ���������Ƿ�ͬ������
        /// </summary>
        public bool IsSyncSend
        {
            get { return m_isSyncSend; }
            set { m_isSyncSend = value; }
        }

        private int m_timeout = 10;
        /// <summary>
        /// ��ȡ��������Timeoutʱ��
        /// </summary>
        public int Timeout
        {
            get { return m_timeout; }
            set { m_timeout = value; }
        }

        private string m_url;

        /// <summary>
        /// ��ȡ�����õ�ַ
        /// </summary>
        public string Url
        {
            get { return m_url; }
            set { m_url = value; }
        }

        /// <summary>
        /// �첽��������
        /// </summary>
        /// <param name="obj"></param>
        public void asynSend(Object obj)
        {
            FCMessage message = obj as FCMessage;
            if (message == null)
            {
                return;
            }
            sendRequest(message);
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="message">��Ϣ</param>
        public override void onReceive(FCMessage message)
        {
            base.onReceive(message);
            sendToListener(message);
        }

        /// <summary>
        /// ����POST����
        /// </summary>
        /// <param name="url">��ַ</param>
        /// <param name="data">����</param>
        /// <returns>���</returns>
        public String post(String url)
        {
            return post(url, "");
        }

        /// <summary>
        /// ����POST����
        /// </summary>
        /// <param name="url">��ַ</param>
        /// <param name="data">����</param>
        /// <returns>���</returns>
        public String post(String url, String data)
        {
            byte[] sendDatas = Encoding.Default.GetBytes(data);
            byte[] bytes = post(url, sendDatas);
            if (bytes != null)
            {
                return Encoding.Default.GetString(bytes);
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// ����POST����
        /// </summary>
        /// <param name="url">��ַ</param>
        /// <param name="data">����</param>
        /// <returns>���</returns>
        public byte[] post(String url, byte[] sendDatas)
        {
            HttpWebRequest request = null;
            Stream reader = null;
            HttpWebResponse response = null;
            try
            {
                request = (HttpWebRequest)WebRequest.Create(url);
                request.Method = "POST";
                //request.Timeout = m_timeout;
                request.ContentType = "application/x-www-form-urlencoded";
                if (sendDatas != null)
                {
                    request.ContentLength = sendDatas.Length;
                    Stream writer = request.GetRequestStream();
                    writer.Write(sendDatas, 0, sendDatas.Length);
                    writer.Close();
                }
                response = (HttpWebResponse)request.GetResponse();
                reader = response.GetResponseStream();
                long contentLength = response.ContentLength;
                byte[] recvDatas = new byte[contentLength];
                for (int i = 0; i < contentLength; i++)
                {
                    recvDatas[i] = (byte)reader.ReadByte();
                }
                return recvDatas;
            }
            catch (Exception ex)
            {
                return null;
            }
            finally
            {
                if (response != null)
                {
                    response.Close();
                }
                if (reader != null)
                {
                    reader.Close();
                }
            }
        }

        /// <summary>
        /// ����POST����
        /// </summary>
        /// <param name="message">��Ϣ</param>
        /// <returns>������Ϣ</returns>
        public override int send(FCMessage message)
        {
            if (!m_isSyncSend)
            {
                Thread thread = new Thread(asynSend);
                thread.Start(message);
                return 1;
            }
            else
            {
                return sendRequest(message);
            }
        }

        /// <summary>
        /// ����POST����
        /// </summary>
        /// <param name="message">��Ϣ</param>
        /// <returns>������Ϣ</returns>
        public int sendRequest(FCMessage message)
        {
            FCBinary bw = new FCBinary();
            byte[] body = message.m_body;
            int bodyLength = message.m_bodyLength;
            int uncBodyLength = bodyLength;
            if (message.m_compressType == COMPRESSTYPE_GZIP)
            {
                using (MemoryStream cms = new MemoryStream())
                {
                    using (GZipStream gzip = new GZipStream(cms, CompressionMode.Compress))
                    {
                        gzip.Write(body, 0, body.Length);
                    }
                    body = cms.ToArray();
                    bodyLength = body.Length;
                }
            }
            int len = sizeof(int) * 4 + bodyLength + sizeof(short) * 3 + sizeof(byte) * 2;
            bw.writeInt(len);
            bw.writeShort((short)message.m_groupID);
            bw.writeShort((short)message.m_serviceID);
            bw.writeShort((short)message.m_functionID);
            bw.writeInt(message.m_sessionID);
            bw.writeInt(message.m_requestID);
            bw.writeByte((byte)message.m_state);
            bw.writeByte((byte)message.m_compressType);
            bw.writeInt(uncBodyLength);
            bw.writeBytes(body);
            byte[] bytes = bw.getBytes();
            int length = bytes.Length;
            HttpWebRequest webReq = (HttpWebRequest)WebRequest.Create(m_url);
            webReq.Method = "POST";
            webReq.ContentType = "application/x-www-form-urlencoded";
            webReq.ContentLength = bytes.Length;
            if (bytes != null)
            {
                Stream writer = webReq.GetRequestStream();
                writer.Write(bytes, 0, bytes.Length);
                writer.Close();
            }
            HttpWebResponse response = (HttpWebResponse)webReq.GetResponse();
            Stream reader = response.GetResponseStream();
            long contentLength = response.ContentLength;
            byte[] dataArray = new byte[contentLength];
            for (int i = 0; i < contentLength; i++)
            {
                dataArray[i] = (byte)reader.ReadByte();
            }
            response.Close();
            reader.Dispose();
            bw.close();
            int ret = dataArray.Length;
            UpFlow += ret;
            FCClientService.callBack(message.m_socketID, 0, dataArray, ret);
            return ret;
        }
    }
}
