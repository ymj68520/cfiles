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
using OwLib;
using System.Windows.Forms;
using System.Threading;
using System.Diagnostics;
using System.Net;
using System.Web;
using System.IO;
using FaceCat;

namespace FaceCat {
    /// <summary>
    /// ��ʾ����
    /// </summary>
    public class CFunctionEx : CFunction {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="id">ID</param>
        /// <param name="name">����</param>
        /// <param name="native">XML����</param>
        public CFunctionEx(FCScript indicator, int id, String name, FCNative native) {
            m_indicator = indicator;
            m_ID = id;
            m_name = name;
            m_native = native;
        }

        /// <summary>
        /// ָ��
        /// </summary>
        public FCScript m_indicator;

        /// <summary>
        /// XML����
        /// </summary>
        public FCNative m_native;

        /// <summary>
        /// ���з���
        /// </summary>
        private const String FUNCTIONS = "CREATETHREAD,ISAPPALIVE";

        /// <summary>
        /// ��ʼ����
        /// </summary>
        private const int STARTINDEX = 1000000;

        /// <summary>
        /// ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        public override double onCalculate(CVariable var) {
            switch (var.m_functionID) {
                case STARTINDEX:
                    return CREATETHREAD(var);
                default:
                    return 0;
            }
        }

        /// <summary>
        /// ����ָ��
        /// </summary>
        /// <param name="native">������</param>
        /// <param name="script">�ű�</param>
        /// <returns>ָ��</returns>
        public static FCScript CreateScript(String script, FCNative native) {
            FCScript indicator = new FCScript();
            FCDataTable table = new FCDataTable();
            indicator.DataSource = table;
            CFunctionBase.addFunctions(indicator);
            CFunctionHttp.addFunctions(indicator);
            int index = STARTINDEX;
            string[] functions = FUNCTIONS.Split(new string[] { "," }, StringSplitOptions.RemoveEmptyEntries);
            int functionsSize = functions.Length;
            for (int i = 0; i < functionsSize; i++) {
                indicator.addFunction(new CFunctionEx(indicator, index + i, functions[i], native));
            }
            indicator.Script = script;
            table.addColumn(0);
            table.set(0, 0, 0);
            indicator.onCalculate(0);
            return indicator;
        }

        /// <summary>
        /// �����߳�
        /// </summary>
        /// <param name="param">����</param>
        private void createThread(object param) {
            FCScript indicator = CreateScript(FCHttpMonitor.MainMonitor.Script, m_native);
            indicator.callFunction(param.ToString());
            indicator.delete();
        }

        /// <summary>
        /// �����߳�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double CREATETHREAD(CVariable var) {
            Thread thread = new Thread(new ParameterizedThreadStart(createThread));
            thread.Start(m_indicator.getText(var.m_parameters[0]));
            return 0;
        }
    }
}
