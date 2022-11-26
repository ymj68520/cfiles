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

namespace FaceCat {
    /// <summary>
    /// ������صĿ�
    /// </summary>
    public class CFunctionBase : CFunction {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="id">ID</param>
        /// <param name="name">����</param>
        public CFunctionBase(FCScript indicator, int id, String name) {
            m_indicator = indicator;
            m_ID = id;
            m_name = name;
        }

        /// <summary>
        /// ָ��
        /// </summary>
        public FCScript m_indicator;

        /// <summary>
        /// ����
        /// </summary>
        private static string FUNCTIONS = "IN,OUT,SLEEP,TEST";

        /// <summary>
        /// ǰ׺
        /// </summary>
        private static string PREFIX = "";

        /// <summary>
        /// ��ʼ����
        /// </summary>
        private const int STARTINDEX = 1000;

        /// <summary>
        /// ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        public override double onCalculate(CVariable var) {
            switch (var.m_functionID) {
                case STARTINDEX:
                    return IN(var);
                case STARTINDEX + 1:
                    return OUT(var);
                case STARTINDEX + 2:
                    return SLEEP(var);
                case STARTINDEX + 3: {
                        double value = m_indicator.getValue(var.m_parameters[0]);
                        return 0;
                    }
                default: return 0;
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
                indicator.addFunction(new CFunctionBase(indicator, STARTINDEX + i, PREFIX + functions[i]));
            }
        }

        /// <summary>
        /// ���뺯��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double IN(CVariable var) {
            CVariable newVar = new CVariable(m_indicator);
            newVar.m_expression = "'" + Console.ReadLine() + "'";
            m_indicator.setVariable(var.m_parameters[0], newVar);
            return 0;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double OUT(CVariable var) {
            int len = var.m_parameters.Length;
            for (int i = 0; i < len; i++) {
                string text = m_indicator.getText(var.m_parameters[i]);
                Console.Write(text);
            }
            Console.WriteLine("");
            return 0;
        }

        /// <summary>
        /// ˯��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double SLEEP(CVariable var) {
            Thread.Sleep((int)m_indicator.getValue(var.m_parameters[0]));
            return 1;
        }
    }
}
