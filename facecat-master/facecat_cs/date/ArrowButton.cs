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
    /// �л����ϸ��µİ�ť
    /// </summary>
    public class ArrowButton : FCButton {
        /// <summary>
        /// ������ť
        /// </summary>
        public ArrowButton(FCCalendar calendar) {
            m_calendar = calendar;
            BorderColor = FCColor.None;
            BackColor = FCColor.None;
            Size = new FCSize(16, 16);
        }

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ�����������ؼ�
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        protected bool m_toLast = true;

        /// <summary>
        /// ��ȡ�������Ƿ�ǰ���ϸ���
        /// </summary>
        public virtual bool ToLast {
            get { return m_toLast; }
            set { m_toLast = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "ArrowButton";
        }

        /// <summary>
        /// ��������¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            base.onClick(touchInfo);
            if (m_calendar != null) {
                FCCalendarMode mode = m_calendar.Mode;
                //��
                if (mode == FCCalendarMode.Day) {
                    if (m_toLast) {
                        m_calendar.goLastMonth();
                    }
                    else {
                        m_calendar.goNextMonth();
                    }
                }
                //��
                else if (mode == FCCalendarMode.Month) {
                    MonthDiv monthDiv = m_calendar.MonthDiv;
                    if (monthDiv != null) {
                        int year = monthDiv.Year;
                        if (m_toLast) {
                            monthDiv.selectYear(year - 1);
                        }
                        else {
                            monthDiv.selectYear(year + 1);
                        }
                    }
                }
                //��
                else if (mode == FCCalendarMode.Year) {
                    YearDiv yearDiv = m_calendar.YearDiv;
                    if (yearDiv != null) {
                        int year = yearDiv.StartYear;
                        if (m_toLast) {
                            yearDiv.selectStartYear(year - 12);
                        }
                        else {
                            yearDiv.selectStartYear(year + 12);
                        }
                    }
                }
                m_calendar.invalidate();
            }
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            int width = Width, height = Height;
            FCPoint p1 = new FCPoint(), p2 = new FCPoint(), p3 = new FCPoint();
            //�����������λ��
            if (m_toLast) {
                p1.x = 0;
                p1.y = height / 2;
                p2.x = width;
                p2.y = 0;
                p3.x = width;
                p3.y = height;
            }
            else {
                p1.x = 0;
                p1.y = 0;
                p2.x = 0;
                p2.y = height;
                p3.x = width;
                p3.y = height / 2;
            }
            FCPoint[] points = new FCPoint[3];
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;
            paint.fillPolygon(getPaintingTextColor(), points);
        }
    }
}
