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
using System.Threading;
using System.IO;
using System.Net;
using System.Web;
using FaceCat;
using System.Runtime.InteropServices;

namespace OwLib {
    /// <summary>
    /// HTTP��صĿ�
    /// </summary>
    public class CFunctionHttp : CFunction {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="id">ID</param>
        /// <param name="name">����</param>
        public CFunctionHttp(FCScript indicator, int id, String name) {
            m_indicator = indicator;
            m_ID = id;
            m_name = name;
        }

        /// <summary>
        /// HTTP����
        /// </summary>
        public FCHttpData m_data;

        /// <summary>
        /// ָ��
        /// </summary>
        public FCScript m_indicator;

        /// <summary>
        /// ����
        /// </summary>
        private static string FUNCTIONS =
            "POSTSTRING,QUERYSTRING,WRITE,ADDPORT,GETREQUESTURL,GETREQUESTMETHOD"
            + ",GETCONTENTTYPE,SETSTATUSCODE,GETSERVICENAME,CHECKSCRIPT,CLOSE,HARDREQUEST,EASYREQUEST,GETREMOTEIP,GETREMOTEPORT";

        /// <summary>
        /// ǰ׺
        /// </summary>
        private static string PREFIX = "HTTP.";

        /// <summary>
        /// ��ʼ����
        /// </summary>
        private const int STARTINDEX = 4000;

        /// <summary>
        /// ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        public override double onCalculate(CVariable var) {
            switch (var.m_functionID) {
                case STARTINDEX:
                    return HTTP_POSTSTRING(var);
                case STARTINDEX + 1:
                    return HTTP_QUERYSTRING(var);
                case STARTINDEX + 2:
                    return HTTP_WRITE(var);
                case STARTINDEX + 3:
                    return HTTP_ADDPORT(var);
                case STARTINDEX + 4:
                    return HTTP_GETREQUESTURL(var);
                case STARTINDEX + 5:
                    return HTTP_GETREQUESTMETHOD(var);
                case STARTINDEX + 6:
                    return HTTP_GETCONTENTTYPE(var);
                case STARTINDEX + 7:
                    return HTTP_SETSTATUSCODE(var);
                case STARTINDEX + 8:
                    return HTTP_GETSERVICENAME(var);
                case STARTINDEX + 9:
                    return HTTP_CHECKSCRIPT(var);
                case STARTINDEX + 10:
                    return HTTP_CLOSE(var);
                case STARTINDEX + 11:
                    return HTTP_HARDREQUEST(var);
                case STARTINDEX + 12:
                    return HTTP_EASYREQUEST(var);
                case STARTINDEX + 13:
                    return HTTP_GETREMOTEIP(var);
                case STARTINDEX + 14:
                    return HTTP_GETREMOTEPORT(var);
                default:
                    return 0;
            }
        }

        /// <summary>
        /// ��ӷ���
        /// </summary>
        /// <param name="indicator">������</param>
        /// <returns>ָ��</returns>
        public static void addFunctions(FCScript indicator) {
            string[] functions = FUNCTIONS.Split(new string[] { "," }, StringSplitOptions.RemoveEmptyEntries);
            int functionsSize = functions.Length;
            for (int i = 0; i < functionsSize; i++) {
                indicator.addFunction(new CFunctionHttp(indicator, STARTINDEX + i, PREFIX + functions[i]));
            }
        }

        /// <summary>
        /// ���ǰ׺
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_ADDPORT(CVariable var) {
            FCHttpMonitor.MainMonitor.Port = (int)m_indicator.getValue(var.m_parameters[0]);
            return 0;
        }

        /// <summary>
        /// ���ű�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_CHECKSCRIPT(CVariable var) {
            FCHttpMonitor.MainMonitor.checkScript();
            return 0;
        }

        /// <summary>
        /// HTTP�ر�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_CLOSE(CVariable var) {
            m_data.m_close = true;
            return 0;
        }

        /// <summary>
        /// ����GET����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_EASYREQUEST(CVariable var) {
            return FCHttpMonitor.m_easyServices.get(m_indicator.getText(var.m_parameters[0])).onReceive(m_data);
        }

        /// <summary>
        /// ��ȡ�������ͷ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_GETCONTENTTYPE(CVariable var) {
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + m_data.m_contentType + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ��ȡIP
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_GETREMOTEIP(CVariable var) {
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + m_data.m_remoteIP + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ��ȡPort
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>Port</returns>
        private double HTTP_GETREMOTEPORT(CVariable var) {
            return m_data.m_remotePort;
        }

        /// <summary>
        /// ��ȡ���󷽷�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_GETREQUESTMETHOD(CVariable var) {
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + m_data.m_method + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ��ȡ����URL
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_GETREQUESTURL(CVariable var) {
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + m_data.m_url + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_GETSERVICENAME(CVariable var) {
            String url = m_data.m_url;
            int sindex = url.LastIndexOf('/');
            int eindex = url.IndexOf('?');
            String text = "";
            if (eindex != -1) {
                text = url.Substring(sindex + 1, eindex - sindex - 1);
            }
            else {
                if (sindex + 1 == url.Length) {
                    url = url.Substring(0, url.Length - 1);
                    sindex = url.LastIndexOf('/');
                }
                text = url.Substring(sindex + 1);
            }
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + text + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ����������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_HARDREQUEST(CVariable var) {
            FCServerService.callBack(m_data.m_socketID, 0, m_data.m_body, m_data.m_body.Length);
            return 0;
        }

        /// <summary>
        /// ����������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_POSTREQUEST(CVariable var) {
            FCServerService.callBack(m_data.m_socketID, 0, m_data.m_body, m_data.m_body.Length);
            return 0;
        }

        /// <summary>
        /// HTTP��ȡPOST����Ĳ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_POSTSTRING(CVariable var) {
            String text = "";
            if (m_data.m_body != null) {
                text = Encoding.Default.GetString(m_data.m_body);
            }
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + text + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// HTTP��ȡGET����Ĳ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_QUERYSTRING(CVariable var) {
            String name = m_indicator.getText(var.m_parameters[1]).ToLower();
            string text = "";
            if (m_data.m_parameters.ContainsKey(name)) {
                text = m_data.m_parameters[name];
            }
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + text + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ������Ӧ״̬��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_SETSTATUSCODE(CVariable var) {
            m_data.m_statusCode = (int)m_indicator.getValue(var.m_parameters[0]);
            return 0;
        }

        /// <summary>
        /// HTTP��Ӧд��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double HTTP_WRITE(CVariable var) {
            int len = var.m_parameters.Length;
            for (int i = 0; i < len; i++) {
                String text = m_indicator.getText(var.m_parameters[i]);
                m_data.m_resStr += text;
            }
            return 0;
        }
    }
}