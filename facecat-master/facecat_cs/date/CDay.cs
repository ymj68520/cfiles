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

namespace FaceCat {
    /// <summary>
    /// ��
    /// </summary>
    [Serializable()]
    public class CDay {
        /// <summary>
        /// ������
        /// </summary>
        /// <param name="year">��</param>
        /// <param name="month">��</param>
        /// <param name="day">��</param>
        public CDay(int year, int month, int day) {
            m_year = year;
            m_month = month;
            m_day = day;
        }

        private int m_day;

        /// <summary>
        /// ��ȡ��
        /// </summary>
        public int Day {
            get { return m_day; }
        }

        private int m_month;

        /// <summary>
        /// ��ȡ��
        /// </summary>
        public int Month {
            get { return m_month; }
        }

        private int m_year;

        /// <summary>
        /// ��ȡ��
        /// </summary>
        public int Year {
            get { return m_year; }
        }

        /// <summary>
        /// �������
        /// </summary>
        public void delete() {
        }
    }
}
