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
    /// ʱ���
    /// </summary>
    public class TimeDiv {
        /// <summary>
        /// ����ʱ���
        /// </summary>
        public TimeDiv(FCCalendar calendar) {
            m_calendar = calendar;
            onLoad();
        }

        /// <summary>
        /// Сʱ�����
        /// </summary>
        protected FCSpin m_spinHour;

        /// <summary>
        /// ���������
        /// </summary>
        protected FCSpin m_spinMinute;

        /// <summary>
        /// �������
        /// </summary>
        protected FCSpin m_spinSecond;

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ�����������ؼ�
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        protected int m_height = 40;

        /// <summary>
        /// ��ȡ�����ø߶�
        /// </summary>
        public virtual int Height {
            get { return m_height; }
            set { m_height = value; }
        }

        /// <summary>
        /// ��ȡ������Сʱ
        /// </summary>
        public virtual int Hour {
            get {
                if (m_spinHour != null) {
                    return (int)m_spinHour.Value;
                }
                else {
                    return 0;
                }
            }
            set {
                if (m_spinHour != null) {
                    m_spinHour.Value = value;
                }
            }
        }

        /// <summary>
        /// ��ȡ�����÷���
        /// </summary>
        public virtual int Minute {
            get {
                if (m_spinMinute != null) {
                    return (int)m_spinMinute.Value;
                }
                else {
                    return 0;
                }
            }
            set {
                if (m_spinMinute != null) {
                    m_spinMinute.Value = value;
                }
            }
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        public virtual int Second {
            get {
                if (m_spinSecond != null) {
                    return (int)m_spinSecond.Value;
                }
                else {
                    return 0;
                }
            }
            set {
                if (m_spinSecond != null) {
                    m_spinSecond.Value = value;
                }
            }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public virtual void delete() {
            m_spinHour = null;
            m_spinMinute = null;
            m_spinSecond = null;
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
        /// ��ӿؼ�����
        /// </summary>
        public virtual void onLoad() {
            if (m_calendar != null) {
                FCHost host = m_calendar.Native.Host;
                if (m_spinHour == null) {
                    m_spinHour = new FCSpin();
                    m_spinHour.Maximum = 23;
                    m_spinHour.TextAlign = FCHorizontalAlign.Right;
                    m_calendar.addControl(m_spinHour);
                    m_spinHour.addEvent(new FCEvent(selectedTimeChanged), FCEventID.VALUECHANGED);
                }
                if (m_spinMinute == null) {
                    m_spinMinute = new FCSpin();
                    m_spinMinute.Maximum = 59;
                    m_spinMinute.TextAlign = FCHorizontalAlign.Right;
                    m_calendar.addControl(m_spinMinute);
                    m_spinMinute.addEvent(new FCEvent(selectedTimeChanged), FCEventID.VALUECHANGED);
                }
                if (m_spinSecond == null) {
                    m_spinSecond = new FCSpin();
                    m_spinSecond.Maximum = 59;
                    m_spinSecond.TextAlign = FCHorizontalAlign.Right;
                    m_calendar.addControl(m_spinSecond);
                    m_spinSecond.addEvent(new FCEvent(selectedTimeChanged), FCEventID.VALUECHANGED);
                }
            }
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaint(FCPaint paint, FCRect clipRect) {
            int width = m_calendar.Width, height = m_calendar.Height;
            int top = height - m_height;
            FCRect rect = new FCRect(0, height - m_height, width, height);
            paint.fillRect(getPaintingBackColor(), rect);
            if (m_height > 0) {
                long textColor = getPaintingTextColor();
                FCFont font = m_calendar.Font;
                FCSize tSize = paint.textSize("ʱ", font);
                FCRect tRect = new FCRect();
                tRect.left = width / 3 - tSize.cx;
                tRect.top = top + m_height / 2 - tSize.cy / 2;
                tRect.right = tRect.left + tSize.cx;
                tRect.bottom = tRect.top + tSize.cy;
                paint.drawText("ʱ", textColor, font, tRect);
                tSize = paint.textSize("��", font);
                tRect.left = width * 2 / 3 - tSize.cx;
                tRect.top = top + m_height / 2 - tSize.cy / 2;
                tRect.right = tRect.left + tSize.cx;
                tRect.bottom = tRect.top + tSize.cy;
                paint.drawText("��", textColor, font, tRect);
                tSize = paint.textSize("��", font);
                tRect.left = width - tSize.cx - 5;
                tRect.top = top + m_height / 2 - tSize.cy / 2;
                tRect.right = tRect.left + tSize.cx;
                tRect.bottom = tRect.top + tSize.cy;
                paint.drawText("��", textColor, font, tRect);
            }
        }

        /// <summary>
        /// ��ֵ�޸��¼�
        /// </summary>
        public virtual void onSelectedTimeChanged() {
            if (m_calendar != null) {
                m_calendar.onSelectedTimeChanged();
            }
        }

        /// <summary>
        /// ���������
        /// </summary>
        public virtual void onTimer() {
        }

        /// <summary>
        /// ��ֵ�޸��¼�
        /// </summary>
        /// <param name="sender">������</param>
        protected void selectedTimeChanged(object sender) {
            onSelectedTimeChanged();
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public virtual void update() {
            if (m_height > 0) {
                int width = m_calendar.Width, height = m_calendar.Height;
                int top = height - m_height;
                int left = 5;
                if (m_spinHour != null) {
                    m_spinHour.Visible = true;
                    m_spinHour.Location = new FCPoint(left, top + m_height / 2 - m_spinHour.Height / 2);
                    m_spinHour.Width = (width - 15) / 3 - 20;
                }
                if (m_spinMinute != null) {
                    m_spinMinute.Visible = true;
                    m_spinMinute.Location = new FCPoint(width / 3 + 5, top + m_height / 2 - m_spinMinute.Height / 2);
                    m_spinMinute.Width = (width - 15) / 3 - 20;
                }
                if (m_spinSecond != null) {
                    m_spinSecond.Visible = true;
                    m_spinSecond.Location = new FCPoint(width * 2 / 3 + 5, top + m_height / 2 - m_spinSecond.Height / 2);
                    m_spinSecond.Width = (width - 15) / 3 - 20;

                }
            }
            else {
                if (m_spinHour != null) {
                    m_spinHour.Visible = false;
                }
                if (m_spinMinute != null) {
                    m_spinMinute.Visible = false;
                }
                if (m_spinSecond != null) {
                    m_spinSecond.Visible = false;
                }
            }
        }
    }
}
