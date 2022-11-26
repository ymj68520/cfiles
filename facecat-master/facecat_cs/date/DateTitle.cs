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
    /// ���ڱ���
    /// </summary>
    public class DateTitle : FCButton {
        /// <summary>
        /// �������ڱ���
        /// </summary>
        /// <param name="calendar">�����ؼ�</param>
        public DateTitle(FCCalendar calendar) {
            m_calendar = calendar;
            BackColor = FCColor.None;
            BorderColor = FCColor.None;
            Font = new FCFont("����", 22, true, false, false);
            Size = new FCSize(180, 30);
        }

        /// <summary>
        /// ����
        /// </summary>
        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "DateTitle";
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            base.onClick(touchInfo);
            if (m_calendar != null) {
                FCCalendarMode mode = m_calendar.Mode;
                //��
                if (mode == FCCalendarMode.Day) {
                    m_calendar.Mode = FCCalendarMode.Month;
                }
                //��
                else if (mode == FCCalendarMode.Month) {
                    m_calendar.Mode = FCCalendarMode.Year;
                }
                m_calendar.update();
                m_calendar.invalidate();
            }
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            if (m_calendar != null) {
                int width = Width, height = Height;
                FCFont font = Font;
                String text = "";
                FCCalendarMode mode = m_calendar.Mode;
                //��
                if (mode == FCCalendarMode.Day) {
                    CMonth month = m_calendar.Month;
                    text = month.Year.ToString() + "��" + month.Month.ToString() + "��";
                }
                //��
                else if (mode == FCCalendarMode.Month) {
                    text = m_calendar.MonthDiv.Year.ToString() + "��";
                }
                //��
                else if (mode == FCCalendarMode.Year) {
                    int startYear = m_calendar.YearDiv.StartYear;
                    text = startYear.ToString() + "�� - " + (startYear + 12).ToString() + "��";
                }
                FCSize tSize = paint.textSize(text, font);
                FCRect tRect = new FCRect();
                tRect.left = (width - tSize.cx) / 2;
                tRect.top = (height - tSize.cy) / 2;
                tRect.right = tRect.left + tSize.cx + 1;
                tRect.bottom = tRect.top + tSize.cy + 1;
                paint.drawText(text, getPaintingTextColor(), font, tRect);
            }
        }
    }
}
