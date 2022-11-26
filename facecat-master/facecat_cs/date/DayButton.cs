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
    /// ���ڰ�ť
    /// </summary>
    public class DayButton {
        /// <summary>
        /// �����յİ�ť
        /// </summary>
        /// <param name="calendar">�����ؼ�</param>
        public DayButton(FCCalendar calendar) {
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

        protected CDay m_day;

        /// <summary>
        /// ��ȡ�����ñ��������
        /// </summary>
        public virtual CDay Day {
            get { return m_day; }
            set { m_day = value; }
        }

        protected bool m_inThisMonth;

        /// <summary>
        /// ��ȡ�������Ƿ��ڱ���
        /// </summary>
        public virtual bool InThisMonth {
            get { return m_inThisMonth; }
            set { m_inThisMonth = value; }
        }

        protected bool m_selected;

        /// <summary>
        /// ��ȡ�������Ƿ�ѡ��
        /// </summary>
        public virtual bool Selected {
            get { return m_selected; }
            set { m_selected = value; }
        }

        protected bool m_visible = true;

        /// <summary>
        /// ��ȡ�������Ƿ�ɼ�
        /// </summary>
        public virtual bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        /// <summary>
        /// ��ȡ���Ƶı���ɫ
        /// </summary>
        /// <returns>����ɫ</returns>
        protected virtual long getPaintingBackColor() {
            if (m_selected) {
                return FCColor.Pushed;
            }
            else {
                if (m_inThisMonth) {
                    return FCColor.Hovered;
                }
                else {
                    return FCColor.Back;
                }
            }
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
        /// ��������¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onClick(FCTouchInfo touchInfo) {
            if (m_calendar != null && m_day != null) {
                m_calendar.SelectedDay = m_day;
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
            if (m_day != null) {
                int width = m_bounds.right - m_bounds.left;
                int height = m_bounds.bottom - m_bounds.top;
                String dayStr = m_day.Day.ToString();
                FCFont font = m_calendar.Font;
                FCSize textSize = paint.textSize(dayStr, font);
                FCRect tRect = new FCRect();
                tRect.left = m_bounds.left + (width - textSize.cx) / 2;
                tRect.top = m_bounds.top + (height - textSize.cy) / 2;
                tRect.right = tRect.left + textSize.cx;
                tRect.bottom = tRect.top + textSize.cy;
                paint.drawText(dayStr, getPaintingTextColor(), font, tRect);
            }
        }
    }
}
