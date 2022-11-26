/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using FaceCat;

namespace FaceCat
{
    /// <summary>
    /// ������صĿ�
    /// </summary>
    public class NFunctionUI : CFunction
    {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="id">ID</param>
        /// <param name="name">����</param>
        /// <param name="withParameters">�Ƿ��в���</param>
        public NFunctionUI(FCScript indicator, int id, String name, FCUIXml xml)
        {
            m_indicator = indicator;
            m_ID = id;
            m_name = name;
            m_xml = xml;
        }

        /// <summary>
        /// ָ��
        /// </summary>
        public FCScript m_indicator;

        /// <summary>
        /// XML����
        /// </summary>
        public FCUIXml m_xml;

        /// <summary>
        /// ����
        /// </summary>
        private static String FUNCTIONS = "GETPROPERTY,SETPROPERTY,GETSENDER,ALERT,INVALIDATE,SHOWWINDOW,CLOSEWINDOW,STARTTIMER,STOPTIMER,GETMOUSEBUTTON,GETMOUSEPOINT,GETCLICKS,GETKEY,GETCOOKIE,SETCOOKIE,SHOWRIGHTMENU,ADDBARRAGE,UPDATE";

        /// <summary>
        /// ǰ׺
        /// </summary>
        private static String PREFIX = "";

        /// <summary>
        /// ��ʼ����
        /// </summary>
        private const int STARTINDEX = 2000;

        /// <summary>
        /// ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        public override double onCalculate(CVariable var)
        {
            switch (var.m_functionID)
            {
                case STARTINDEX + 0:
                    return GETPROPERTY(var);
                case STARTINDEX + 1:
                    return SETPROPERTY(var);
                case STARTINDEX + 2:
                    return GETSENDER(var);
                case STARTINDEX + 3:
                    return ALERT(var);
                case STARTINDEX + 4:
                    return INVALIDATE(var);
                case STARTINDEX + 5:
                    return SHOWWINDOW(var);
                case STARTINDEX + 6:
                    return CLOSEWINDOW(var);
                case STARTINDEX + 7:
                    return STARTTIMER(var);
                case STARTINDEX + 8:
                    return STOPTIMER(var);
                case STARTINDEX + 9:
                    return GETMOUSEBUTTON(var);
                case STARTINDEX + 10:
                    return GETMOUSEPOINT(var);
                case STARTINDEX + 11:
                    return GETCLICKS(var);
                case STARTINDEX + 12:
                    return GETKEY(var);
                case STARTINDEX + 13:
                    return GETCOOKIE(var);
                case STARTINDEX + 14:
                    return SETCOOKIE(var);
                case STARTINDEX + 15:
                    return SHOWRIGHTMENU(var);
                case STARTINDEX + 16:
                    return ADDBARRAGE(var);
                case STARTINDEX + 17:
                    return UPDATE(var);
                default:
                    return 0;
            }
        }

        /// <summary>
        /// ��ӷ���
        /// </summary>
        /// <param name="indicator">������</param>
        /// <param name="native">�ű�</param>
        /// <param name="xml">XML</param>
        /// <returns>ָ��</returns>
        public static void addFunctions(FCScript indicator, FCUIXml xml)
        {
            String[] functions = FUNCTIONS.Split(new String[] { "," }, StringSplitOptions.RemoveEmptyEntries);
            int functionsSize = functions.Length;
            for (int i = 0; i < functionsSize; i++)
            {
                indicator.addFunction(new NFunctionUI(indicator, STARTINDEX + i, PREFIX + functions[i], xml));
            }
        }

        /// <summary>
        /// ��ʾ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        public double ADDBARRAGE(CVariable var)
        {
            String text = "";
            int len = var.m_parameters.Length;
            for (int i = 0; i < len; i++)
            {
                text += m_indicator.getText(var.m_parameters[i]);
            }
            return 1;
        }

        /// <summary>
        /// ������ʾ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double ALERT(CVariable var)
        {
            double result = 0;
            int len = var.m_parameters.Length;
            if (len == 1)
            {
                if (DialogResult.OK == MessageBox.Show(m_indicator.getText(var.m_parameters[0])))
                {
                    result = 1;
                }
            }
            else
            {
                if (DialogResult.OK == MessageBox.Show(m_indicator.getText(var.m_parameters[0]),
                    m_indicator.getText(var.m_parameters[1])))
                {
                    result = 1;
                }
            }
            return result;
        }

        /// <summary>
        /// ��ȡ�������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        public int GETCLICKS(CVariable var)
        {
            return m_xml.Event.Clicks;
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        public int GETKEY(CVariable var)
        {
            return (int)m_xml.Event.Key;
        }

        /// <summary>
        /// ��ȡ��갴��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        public int GETMOUSEBUTTON(CVariable var)
        {
            if (m_xml.Event.TouchInfo.m_firstTouch)
            {
                return 1;
            }
            else if (m_xml.Event.TouchInfo.m_secondTouch)
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��갴��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        public int GETMOUSEPOINT(CVariable var)
        {
            FCPoint touchPoint = m_xml.Event.TouchInfo.m_firstPoint;
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = touchPoint.x.ToString();
            m_indicator.setVariable(var.m_parameters[0], newVar);
            CVariable newVar2 = new CVariable(m_indicator);
            newVar2.m_expression = touchPoint.y.ToString();
            m_indicator.setVariable(var.m_parameters[1], newVar2);
            return 1;
        }


        /// <summary>
        /// ��ȡCOOKIE
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double GETCOOKIE(CVariable var)
        {
            String cookieName = m_indicator.getText(var.m_parameters[1]);
            UserCookieService cookieService = DataCenter.UserCookieService;
            UserCookie cookie = new UserCookie();
            if (cookieService.GetCookie(cookieName, ref cookie) > 0)
            {
                CVariable newVar = new CVariable(m_indicator);
                newVar.m_expression = "'" + cookie.m_value + "'";
                m_indicator.setVariable(var.m_parameters[0], newVar);
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        public double GETPROPERTY(CVariable var)
        {
            DesignerScript designerScript = m_xml.Script as DesignerScript;
            String name = m_indicator.getText(var.m_parameters[1]);
            String propertyName = m_indicator.getText(var.m_parameters[2]);
            String text = designerScript.getProperty(name, propertyName);
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + text + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ��ȡ������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        public double GETSENDER(CVariable var)
        {
            DesignerScript designerScript = m_xml.Script as DesignerScript;
            String text = designerScript.getSender();
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + text + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// ˢ�½���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double INVALIDATE(CVariable var)
        {
            if (m_xml != null)
            {
                int pLen = var.m_parameters != null ? var.m_parameters.Length : 0;
                if (pLen == 0)
                {
                    m_xml.Native.invalidate();
                }
                else
                {
                    FCView control = m_xml.findControl(m_indicator.getText(var.m_parameters[0]));
                    if (control != null)
                    {
                        control.invalidate();
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// ����COOKIE
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private double SETCOOKIE(CVariable var)
        {
            String cookieName = m_indicator.getText(var.m_parameters[0]);
            UserCookieService cookieService = DataCenter.UserCookieService;
            UserCookie cookie = new UserCookie();
            cookie.m_key = cookieName;
            cookie.m_value = m_indicator.getText(var.m_parameters[1]);
            return cookieService.AddCookie(cookie);
        }


        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double SETPROPERTY(CVariable var)
        {
            DesignerScript designerScript = m_xml.Script as DesignerScript;
            String name = m_indicator.getText(var.m_parameters[0]);
            String propertyName = m_indicator.getText(var.m_parameters[1]);
            String propertyValue = m_indicator.getText(var.m_parameters[2]);
            designerScript.setProperty(name, propertyName, propertyValue);
            return 0;
        }

        /// <summary>
        /// �رմ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double CLOSEWINDOW(CVariable var)
        {
            WindowXmlEx windowXmlEx = m_xml as WindowXmlEx;
            if (windowXmlEx != null)
            {
                windowXmlEx.close();
            }
            return 0;
        }

        /// <summary>
        /// ��ʾ�Ҽ��˵�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double SHOWRIGHTMENU(CVariable var)
        {
            DesignerScript designerScript = m_xml.Script as DesignerScript;
            FCNative native = m_xml.Native;
            FCView control = m_xml.findControl(designerScript.getSender());
            int clientX = native.clientX(control);
            int clientY = native.clientY(control);
            FCMenu menu = m_xml.getMenu(m_indicator.getText(var.m_parameters[0]));
            menu.Location = new FCPoint(clientX, clientY + control.Height);
            menu.Visible = true;
            menu.Focused = true;
            menu.bringToFront();
            native.invalidate();
            return 0;
        }

        /// <summary>
        /// ��ʾ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double SHOWWINDOW(CVariable var)
        {
            String xmlName = m_indicator.getText(var.m_parameters[0]);
            String windowName = m_indicator.getText(var.m_parameters[1]);
            WindowXmlEx window = null;
            if (xmlName == "project")
            {
                window = new ProjectWindow(m_xml.Native);
            }
            else
            {
                window = new WindowXmlEx();
                window.load(m_xml.Native, xmlName, windowName);
            }
            window.showDialog();
            return 0;
        }

        /// <summary>
        /// ��ʼ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double STARTTIMER(CVariable var)
        {
            FCView control = m_xml.findControl(m_indicator.getText(var.m_parameters[0]));
            control.startTimer((int)m_indicator.getValue(var.m_parameters[1]), (int)m_indicator.getValue(var.m_parameters[2]));
            return 0;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double STOPTIMER(CVariable var)
        {
            FCView control = m_xml.findControl(m_indicator.getText(var.m_parameters[0]));
            control.stopTimer((int)m_indicator.getValue(var.m_parameters[1]));
            return 0;
        }

        /// <summary>
        /// ���²���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double UPDATE(CVariable var)
        {
            if (m_xml != null)
            {
                int pLen = var.m_parameters != null ? var.m_parameters.Length : 0;
                if (pLen == 0)
                {
                    m_xml.Native.update();
                }
                else
                {
                    FCView control = m_xml.findControl(m_indicator.getText(var.m_parameters[0]));
                    if (control != null)
                    {
                        control.update();
                    }
                }
            }
            return 0;
        }
    }
}