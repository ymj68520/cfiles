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

namespace FaceCat {
    /// <summary>
    /// �ű��ӿ���
    /// </summary>
    public interface FCUIScript {
        /// <summary>
        /// ��ȡ�Ƿ�����
        /// </summary>
        bool IsDeleted {
            get;
        }

        /// <summary>
        /// ��ȡ������XML����
        /// </summary>
        FCUIXml Xml {
            get;
            set;
        }

        /// <summary>
        /// ���÷���
        /// </summary>
        /// <param name="function">�����ı�</param>
        /// <returns>����ֵ</returns>
        String callFunction(String function);

        /// <summary>
        /// ���ٶ���
        /// </summary>
        void delete();

        /// <summary>
        /// ���ýű�
        /// </summary>
        /// <param name="text">�ű�</param>
        void setText(String text);
    }
}
