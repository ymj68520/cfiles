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
    public class CYear {
        /// <summary>
        /// ������
        /// </summary>
        /// <param name="year">���</param>
        public CYear(int year) {
            m_year = year;
            CreateMonths();
        }

        private HashMap<int, CMonth> m_months = new HashMap<int, CMonth>();

        /// <summary>
        /// ��ȡ�������µļ���
        /// </summary>
        public HashMap<int, CMonth> Months {
            get { return m_months; }
        }

        private int m_year;

        /// <summary>
        /// ��ȡ���
        /// </summary>
        public int Year {
            get { return m_year; }
        }

        /// <summary>
        /// ������
        /// </summary>
        private void CreateMonths() {
            for (int i = 1; i <= 12; i++) {
                m_months.put(i, new CMonth(m_year, i));
            }
        }

        /// <summary>
        /// �������
        /// </summary>
        public void delete() {
            foreach (CMonth month in m_months.Values) {
                month.delete();
            }
            m_months.clear();

        }
    }
}
