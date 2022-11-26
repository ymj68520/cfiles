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
    /// ������
    /// </summary>
    public class HeadDiv : FCView {
        /// <summary>
        /// ������
        /// </summary>
        /// <param name="calendar">����</param>
        public HeadDiv(FCCalendar calendar) {
            m_calendar = calendar;
            Font = new FCFont("����", 14, true, false, false);
            Height = 55;
        }

        protected String[] m_weekDays = new String[] { "����", "��һ", "�ܶ�", "����", "����", "����", "����" };

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

        protected DateTitle m_dateTitle;

        /// <summary>
        /// ��ȡ���������ڱ���
        /// </summary>
        public virtual DateTitle DateTitle {
            get { return m_dateTitle; }
            set { m_dateTitle = value; }
        }

        protected ArrowButton m_lastBtn;

        /// <summary>
        /// ��ȡ�����õ��ϸ����ڵİ�ť
        /// </summary>
        public virtual ArrowButton LastBtn {
            get { return m_lastBtn; }
            set { m_lastBtn = value; }
        }

        protected ArrowButton m_nextBtn;

        /// <summary>
        /// ��ȡ�����õ��¸����ڵİ�ť
        /// </summary>
        public virtual ArrowButton NextBtn {
            get { return m_nextBtn; }
            set { m_nextBtn = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "HeadDiv";
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            FCHost host = Native.Host;
            if (m_dateTitle == null) {
                m_dateTitle = host.createInternalControl(m_calendar, "datetitle") as DateTitle;
                addControl(m_dateTitle);
            }
            if (m_lastBtn == null) {
                m_lastBtn = host.createInternalControl(m_calendar, "lastbutton") as ArrowButton;
                addControl(m_lastBtn);
            }
            if (m_nextBtn == null) {
                m_nextBtn = host.createInternalControl(m_calendar, "nextbutton") as ArrowButton;
                addControl(m_nextBtn);
            }
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect) {
            int width = Width, height = Height;
            FCRect rect = new FCRect(0, 0, width, height);
            paint.fillRoundRect(getPaintingBackColor(), rect, m_cornerRadius);
        }

        /// <summary>
        /// �ػ���߷���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBorder(FCPaint paint, FCRect clipRect) {
            int width = Width, height = Height;
            paint.drawLine(getPaintingBorderColor(), 1, 0, 0, height - 1, width, height - 1);
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            int width = Width, height = Height;
            FCCalendarMode mode = m_calendar.Mode;
            //�����ڱ���
            if (mode == FCCalendarMode.Day) {
                float left = 0;
                FCSize weekDaySize = new FCSize();
                FCFont font = Font;
                long textColor = getPaintingTextColor();
                for (int i = 0; i < m_weekDays.Length; i++) {
                    weekDaySize = paint.textSize(m_weekDays[i], font);
                    float textX = left + (width / 7F) / 2F - weekDaySize.cx / 2F;
                    float textY = height - weekDaySize.cy;
                    FCRect tRect = new FCRect(textX, textY, textX + weekDaySize.cx, textY + weekDaySize.cy);
                    paint.drawText(m_weekDays[i], textColor, font, tRect);
                    left += Width / 7F;
                }
            }
        }

        /// <summary>
        /// ���ָ��·���
        /// </summary>
        public override void update() {
            base.update();
            int width = Width, height = Height;
            if (m_dateTitle != null) {
                m_dateTitle.Location = new FCPoint((width - m_dateTitle.Width) / 2, (height - m_dateTitle.Height) / 2);
            }
            if (m_lastBtn != null) {
                m_lastBtn.Location = new FCPoint(2, (height - m_lastBtn.Height) / 2);
            }
            if (m_nextBtn != null) {
                m_nextBtn.Location = new FCPoint(width - m_nextBtn.Width - 2, (height - m_nextBtn.Height) / 2);
            }
        }
    }
}
