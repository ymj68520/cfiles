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
    /// ���Խӿ�
    /// </summary>
    public interface FCProperty {
        /// <summary>
        /// �����������ƻ�ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        /// <param name="type">��������</param>
        void getProperty(String name, ref String value, ref String type);

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        ArrayList<String> getPropertyNames();

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        void setProperty(String name, String value);
    }
}
