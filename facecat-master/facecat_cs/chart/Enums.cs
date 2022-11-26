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
    /// ���������
    /// </summary>
    public enum AttachVScale {
        /// <summary>
        /// ����
        /// </summary>
        Left,
        /// <summary>
        /// ����
        /// </summary>
        Right
    }

    /// <summary>
    /// ��״ͼ��ʽ
    /// </summary>
    public enum BarStyle {
        /// <summary>
        /// ����
        /// </summary>
        Line,
        /// <summary>
        /// ����
        /// </summary>
        Rect,
    }

    /// <summary>
    /// K�ߵ���ʽ
    /// </summary>
    public enum CandleStyle {
        /// <summary>
        /// ������
        /// </summary>
        American,
        /// <summary>
        /// ������
        /// </summary>
        CloseLine,
        /// <summary>
        /// ����
        /// </summary>
        Rect,
        /// <summary>
        /// ������
        /// </summary>
        Tower
    }

    /// <summary>
    /// ʮ���ߵ��ƶ���ʽ
    /// </summary>
    public enum CrossLineMoveMode {
        /// <summary>
        /// ����������ƶ�
        /// </summary>
        AfterClick,
        /// <summary>
        /// ���津��
        /// </summary>
        FollowTouch
    }

    /// <summary>
    /// ���ڵ�����
    /// </summary>
    public enum DateType {
        /// <summary>
        /// ��
        /// </summary>
        Day = 2,
        /// <summary>
        /// Сʱ
        /// </summary>
        Hour = 3,
        /// <summary>
        /// ����
        /// </summary>
        Millisecond = 6,
        /// <summary>
        /// ����
        /// </summary>
        Minute = 4,
        /// <summary>
        /// ��
        /// </summary>
        Month = 1,
        /// <summary>
        /// ��
        /// </summary>
        Second = 5,
        /// <summary>
        /// ��
        /// </summary>
        Year = 0
    }

    /// <summary>
    /// X�������
    /// </summary>
    public enum HScaleType {
        /// <summary>
        /// ����
        /// </summary>
        Date,
        /// <summary>
        /// ����
        /// </summary>
        Number
    }

    /// <summary>
    /// ���ֵ���ʽ
    /// </summary>
    public enum NumberStyle {
        /// <summary>
        /// ��׼
        /// </summary>
        Standard,
        /// <summary>
        /// ���»�������
        /// </summary>
        UnderLine
    }

    /// <summary>
    /// ���ߵ���ʽ
    /// </summary>
    public enum PolylineStyle {
        /// <summary>
        /// ԲȦ
        /// </summary>
        Cycle,
        /// <summary>
        /// ����
        /// </summary>
        DashLine,
        /// <summary>
        /// ϸ��ͼ
        /// </summary>
        DotLine,
        /// <summary>
        /// ʵ��
        /// </summary>
        SolidLine
    }

    /// <summary>
    /// ѡ�е�
    /// </summary>
    public enum SelectedPoint {
        /// <summary>
        /// Բ
        /// </summary>
        Ellipse,
        /// <summary>
        /// ����
        /// </summary>
        Rectangle
    }

    /// <summary>
    /// ��������ʽ
    /// </summary>
    public enum SortType {
        /// <summary>
        /// ����
        /// </summary>
        ASC,
        /// <summary>
        /// ����
        /// </summary>
        DESC,
        /// <summary>
        /// ������
        /// </summary>
        NONE
    }

    /// <summary>
    /// ͼ�α����ģʽ
    /// </summary>
    public enum TextMode {
        /// <summary>
        /// ��ʾ�ֶ�
        /// </summary>
        Field,
        /// <summary>
        /// ��ʾ����
        /// </summary>
        Full,
        /// <summary>
        /// ����ʾ
        /// </summary>
        None,
        /// <summary>
        /// ��ʾֵ
        /// </summary>
        Value
    }

    /// <summary>
    /// ��������ϵ
    /// </summary>
    public enum VScaleSystem {
        /// <summary>
        /// ��������
        /// </summary>
        Logarithmic,
        /// <summary>
        /// ��׼
        /// </summary>
        Standard
    }

    /// <summary>
    /// ������������
    /// </summary>
    public enum VScaleType {
        /// <summary>
        /// �ȷ�
        /// </summary>
        Divide,
        /// <summary>
        /// �Ȳ�
        /// </summary>
        EqualDiff,
        /// <summary>
        /// �ȱ�
        /// </summary>
        EqualRatio,
        /// <summary>
        /// �ƽ�ָ�
        /// </summary>
        GoldenRatio,
        /// <summary>
        /// �ٷֱ�
        /// </summary>
        Percent
    }
}
