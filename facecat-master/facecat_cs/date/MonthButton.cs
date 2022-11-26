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
    /// �µİ�ť
    /// </summary>
    public class MonthButton {
        /// <summary>
        /// �����µİ�ť
        /// </summary>
        /// <param name="calendar">�����µİ�ť</param>
        public MonthButton(FCCalendar calendar) {
            m_calendar = calendar;
        }

        protected FCRect m_bounds;

        /// <summary>
        /// ��ȡ��������ʾ����
        /// </summary>
        public virtual FCRect Bounds {
            get { return m_bounds; }
            set { m_bounds = value; }
        }

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ�����������ؼ�
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        protected int m_month;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        public virtual int Month {
            get { return m_month; }
            set { m_month = value; }
        }

        protected bool m_visible = true;

        /// <summary>
        /// ��ȡ�������Ƿ�ɼ�
        /// </summary>
        public virtual bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        protected int m_year;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        public virtual int Year {
            get { return m_year; }
            set { m_year = value; }
        }

        /// <summary>
        /// ��ȡ�µ�����
        /// </summary>
        /// <returns>�µ�����</returns>
        public virtual String GetMonthStr() {
            switch (m_month) {
                case 1:
                    return "һ��";
                case 2:
                    return "����";
                case 3:
                    return "����";
                case 4:
                    return "����";
                case 5:
                    return "����";
                case 6:
                    return "����";
                case 7:
                    return "����";
                case 8:
                    return "����";
                case 9:
                    return "����";
                case 10:
                    return "ʮ��";
                case 11:
                    return "ʮһ��";
                case 12:
                    return "ʮ����";
                default:
                    return "";
            }
        }

        /// <summary>
        /// ��ȡ���Ƶı���ɫ
        /// </summary>
        /// <returns>����ɫ</returns>
        protected virtual long getPaintingBackColor() {
            return FCColor.Back;
        }

        /// <summary>
        /// ��ȡ���Ƶı�����ɫ
        /// </summary>
        /// <returns>������ɫ</returns>
        protected virtual long getPaintingBorderColor() {
            return FCColor.Border;
        }

        /// <summary>
        /// ��ȡҪ���Ƶ�ǰ��ɫ
        /// </summary>
        /// <returns></returns>
        protected virtual long getPaintingTextColor() {
            return FCColor.Text;
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onClick(FCTouchInfo touchInfo) {
            if (m_calendar != null) {
                CMonth month = m_calendar.Years.getYear(m_calendar.MonthDiv.Year).Months.get(m_month);
                m_calendar.Mode = FCCalendarMode.Day;
                m_calendar.SelectedDay = month.Days.get(1);
                m_calendar.update();
                m_calendar.invalidate();
            }
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaintBackGround(FCPaint paint, FCRect clipRect) {
            long backColor = getPaintingBackColor();
            paint.fillRect(backColor, m_bounds);
        }

        /// <summary>
        /// �ػ���߷���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaintBorder(FCPaint paint, FCRect clipRect) {
            long borderColor = getPaintingBorderColor();
            paint.drawLine(borderColor, 1, 0, m_bounds.left, m_bounds.bottom - 1, m_bounds.right - 1, m_bounds.bottom - 1);
            paint.drawLine(borderColor, 1, 0, m_bounds.right - 1, m_bounds.top, m_bounds.right - 1, m_bounds.bottom - 1);
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaintForeground(FCPaint paint, FCRect clipRect) {
            int width = m_bounds.right - m_bounds.left;
            int height = m_bounds.bottom - m_bounds.top;
            String monthStr = GetMonthStr();
            FCFont font = m_calendar.Font;
            FCSize textSize = paint.textSize(monthStr, font);
            //��������ˢ
            FCRect tRect = new FCRect();
            tRect.left = m_bounds.left + (width - textSize.cx) / 2;
            tRect.top = m_bounds.top + (height - textSize.cy) / 2;
            tRect.right = tRect.left + textSize.cx;
            tRect.bottom = tRect.top + textSize.cy;
            paint.drawText(monthStr, getPaintingTextColor(), font, tRect);
        }
    }
}
