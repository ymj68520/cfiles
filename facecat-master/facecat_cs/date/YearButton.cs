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
    /// ��İ�ť
    /// </summary>
    public class YearButton {
        /// <summary>
        /// �����µİ�ť
        /// </summary>
        /// <param name="calendar">�����ؼ�</param>
        public YearButton(FCCalendar calendar) {
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
                m_calendar.Mode = FCCalendarMode.Month;
                m_calendar.MonthDiv.selectYear(m_year);
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
            String yearStr = m_year.ToString();
            FCFont font = m_calendar.Font;
            FCSize textSize = paint.textSize(yearStr, font);
            //��������ˢ
            FCRect tRect = new FCRect();
            tRect.left = m_bounds.left + (width - textSize.cx) / 2;
            tRect.top = m_bounds.top + (height - textSize.cy) / 2;
            tRect.right = tRect.left + textSize.cx;
            tRect.bottom = tRect.top + textSize.cy;
            paint.drawText(yearStr, getPaintingTextColor(), font, tRect);
        }
    }
}
