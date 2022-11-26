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
    public class CMonth {
        /// <summary>
        /// ������
        /// </summary>
        /// <param name="year">��</param>
        /// <param name="month">��</param>
        public CMonth(int year, int month) {
            m_year = year;
            m_month = month;
            createDays();
        }

        private HashMap<int, CDay> m_days = new HashMap<int, CDay>();

        /// <summary>
        /// ��ȡ�������յļ���
        /// </summary>
        public HashMap<int, CDay> Days {
            get { return m_days; }
        }

        /// <summary>
        /// ��ȡ�µ�����
        /// </summary>
        public int DaysInMonth {
            get {
                return DateTime.DaysInMonth(m_year, m_month);
            }
        }

        /// <summary>
        /// ��ȡ���µĵ�һ��
        /// </summary>
        public CDay FirstDay {
            get {
                return m_days.get(1);
            }
        }

        /// <summary>
        /// ��ȡ���µ����һ��
        /// </summary>
        public CDay LastDay {
            get {
                return m_days.get(m_days.size());
            }
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
        /// �����յļ���
        /// </summary>
        private void createDays() {
            int daysInMonth = DaysInMonth;
            for (int i = 1; i <= daysInMonth; i++) {
                m_days.put(i, new CDay(m_year, m_month, i));
            }
        }

        /// <summary>
        /// �������
        /// </summary>
        public void delete() {
            foreach (CDay day in m_days.Values) {
                day.delete();
            }
            m_days.clear();
        }
    }
}
