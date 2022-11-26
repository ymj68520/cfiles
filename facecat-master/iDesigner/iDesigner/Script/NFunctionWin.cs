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
    public class NFunctionWin : CFunction
    {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="id">ID</param>
        /// <param name="name">����</param>
        public NFunctionWin(FCScript indicator, int id, String name)
        {
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
        private static String FUNCTIONS = "BEEP,EXECUTE";

        /// <summary>
        /// ǰ׺
        /// </summary>
        private static String PREFIX = "WIN.";

        /// <summary>
        /// ��ʼ����
        /// </summary>
        private const int STARTINDEX = 3000;

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
                    return WIN_BEEP(var);
                case STARTINDEX + 1:
                    return WIN_EXECUTE(var);
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
        public static void addFunctions(FCScript indicator, FCNative native)
        {
            String[] functions = FUNCTIONS.Split(new String[] { "," }, StringSplitOptions.RemoveEmptyEntries);
            int functionsSize = functions.Length;
            for (int i = 0; i < functionsSize; i++)
            {
                indicator.addFunction(new NFunctionWin(indicator, STARTINDEX + i, PREFIX + functions[i]));
            }
        }


        /// <summary>
        /// Windows��������
        /// </summary_
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double WIN_BEEP(CVariable var)
        {
            int frequency = 0, duration = 0;
            int vlen = var.m_parameters.Length;
            if (vlen >= 1)
            {
                frequency = (int)m_indicator.getValue(var.m_parameters[0]);
            }
            if (vlen >= 2)
            {
                duration = (int)m_indicator.getValue(var.m_parameters[1]);
            }
            Console.Beep(frequency, duration);
            return 0;
        }

        /// <summary>
        /// Windows��ִ�г���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double WIN_EXECUTE(CVariable var)
        {
            WinHostEx.execute(m_indicator.getText(var.m_parameters[0]));
            return 1;
        }
    }
}