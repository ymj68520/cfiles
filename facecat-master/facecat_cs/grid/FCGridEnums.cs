/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu);
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

using System;

namespace FaceCat {
    /// <summary>
    /// ���������ʽ
    /// </summary>
    public enum FCGridColumnSortMode {
        /// <summary>
        /// ����
        /// </summary>
        Asc,
        /// <summary>
        /// ����
        /// </summary>
        Desc,
        /// <summary>
        /// ������
        /// </summary>
        None
    }

    /// <summary>
    /// ���ѡ��ģʽ
    /// </summary>
    public enum FCGridSelectionMode {
        /// <summary>
        /// ѡ�е�Ԫ��
        /// </summary>
        SelectCell,
        /// <summary>
        /// ѡ������
        /// </summary>
        SelectFullColumn,
        /// <summary>
        /// ѡ������
        /// </summary>
        SelectFullRow,
        /// <summary>
        /// ��ѡ��
        /// </summary>
        SelectNone
    }

    /// <summary>
    /// ��Ԫ��༭ģʽ
    /// </summary>
    public enum FCGridCellEditMode {
        /// <summary>
        /// ˫��
        /// </summary>
        DoubleClick,
        /// <summary>
        /// ��Ч
        /// </summary>
        None,
        /// <summary>
        /// ����
        /// </summary>
        SingleClick
    }
}
