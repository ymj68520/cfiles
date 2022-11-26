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

namespace FaceCat
{
    /// <summary>
    /// ����
    /// </summary>
    [Serializable()]
    public class CYears
    {
        /// <summary>
        /// ��ļ���
        /// </summary>
        private HashMap<int, CYear> m_years = new HashMap<int, CYear>();

        /// <summary>
        /// ��ȡ��
        /// </summary>
        /// <param name="year">���</param>
        /// <returns>��</returns>
        public CYear getYear(int year)
        {
            if (!m_years.containsKey(year))
            {
                m_years.put(year, new CYear(year));
            }
            return m_years.get(year);
        }

        /// <summary>
        /// �������
        /// </summary>
        public void delete()
        {
            foreach (CYear year in m_years.Values)
            {
                year.delete();
            }
            m_years.clear();
            m_years = null;
        }
    }
}
