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
    /// ���ڲ�
    /// </summary>
    public class MonthDiv {
        /// <summary>
        /// �������ڲ�
        /// </summary>
        public MonthDiv(FCCalendar calendar) {
            m_calendar = calendar;
            onLoad();
        }

        /// <summary>
        /// �����ķ���
        /// </summary>
        protected int m_am_Direction;

        /// <summary>
        /// ������ǰ֡��
        /// </summary>
        protected int m_am_Tick;

        /// <summary>
        /// ������֡��
        /// </summary>
        protected int m_am_TotalTick = 40;

        /// <summary>
        /// �µİ�ť
        /// </summary>
        public ArrayList<MonthButton> m_monthButtons = new ArrayList<MonthButton>();

        /// <summary>
        /// �µĶ�����ť
        /// </summary>
        public ArrayList<MonthButton> m_monthButtons_am = new ArrayList<MonthButton>();

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ�����������ؼ�
        /// </summary>
        public FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        protected int m_year;

        /// <summary>
        /// ��ȡ���
        /// </summary>
        public virtual int Year {
            get { return m_year; }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public virtual void delete() {
            m_monthButtons.clear();
            m_monthButtons_am.clear();
        }

        /// <summary>
        /// ����
        /// </summary>
        public virtual void hide() {
            int monthButtonSize = m_monthButtons.size();
            for (int i = 0; i < monthButtonSize; i++) {
                MonthButton monthButton = m_monthButtons.get(i);
                monthButton.Visible = false;
            }
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onClick(FCTouchInfo touchInfo) {
            FCPoint mp = touchInfo.m_firstPoint;
            int monthButtonsSize = m_monthButtons.size();
            for (int i = 0; i < monthButtonsSize; i++) {
                MonthButton monthButton = m_monthButtons.get(i);
                if (monthButton.Visible) {
                    FCRect bounds = monthButton.Bounds;
                    if (mp.x >= bounds.left && mp.x <= bounds.right && mp.y >= bounds.top && mp.y <= bounds.bottom) {
                        monthButton.onClick(touchInfo);
                        return;
                    }
                }
            }
            int monthButtonAmSize = m_monthButtons_am.size();
            for (int i = 0; i < monthButtonAmSize; i++) {
                MonthButton monthButton = m_monthButtons_am.get(i);
                if (monthButton.Visible) {
                    FCRect bounds = monthButton.Bounds;
                    if (mp.x >= bounds.left && mp.x <= bounds.right && mp.y >= bounds.top && mp.y <= bounds.bottom) {
                        monthButton.onClick(touchInfo);
                        return;
                    }
                }
            }
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public virtual void onLoad() {
            if (m_calendar != null) {
                FCHost host = m_calendar.Native.Host;
                if (m_monthButtons.size() == 0 || m_monthButtons_am.size() == 0) {
                    m_monthButtons.clear();
                    m_monthButtons_am.clear();
                    for (int i = 0; i < 12; i++) {
                        MonthButton monthButton = new MonthButton(m_calendar);
                        monthButton.Month = i + 1;
                        m_monthButtons.add(monthButton);
                        MonthButton monthButtonAm = new MonthButton(m_calendar);
                        monthButtonAm.Month = i + 1;
                        monthButtonAm.Visible = false;
                        m_monthButtons_am.add(monthButtonAm);
                    }
                }
            }
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaint(FCPaint paint, FCRect clipRect) {
            int monthButtonsSize = m_monthButtons.size();
            for (int i = 0; i < monthButtonsSize; i++) {
                MonthButton monthButton = m_monthButtons.get(i);
                if (monthButton.Visible) {
                    FCRect bounds = monthButton.Bounds;
                    monthButton.onPaintBackGround(paint, bounds);
                    monthButton.onPaintForeground(paint, bounds);
                    monthButton.onPaintBorder(paint, bounds);
                }
            }
            int monthButtonAmSize = m_monthButtons_am.size();
            for (int i = 0; i < monthButtonAmSize; i++) {
                MonthButton monthButton = m_monthButtons_am.get(i);
                if (monthButton.Visible) {
                    FCRect bounds = monthButton.Bounds;
                    monthButton.onPaintBackGround(paint, bounds);
                    monthButton.onPaintForeground(paint, bounds);
                    monthButton.onPaintBorder(paint, bounds);
                }
            }
        }

        /// <summary>
        /// ��������ͼ��
        /// </summary>
        /// <param name="state">״̬</param>
        public virtual void onResetDiv(int state) {
            if (m_calendar != null) {
                int thisYear = m_year;
                int lastYear = m_year - 1;
                int nextYear = m_year + 1;
                int left = 0;
                int headHeight = m_calendar.HeadDiv.Height;
                int top = headHeight;
                int width = m_calendar.Width;
                int height = m_calendar.Height;
                height -= m_calendar.TimeDiv.Height;
                int monthButtonHeight = height - top;
                if (monthButtonHeight < 1) {
                    monthButtonHeight = 1;
                }
                int toY = 0;
                ArrayList<MonthButton> monthButtons = new ArrayList<MonthButton>();
                if (m_am_Direction == 1) {
                    toY = monthButtonHeight * m_am_Tick / m_am_TotalTick;
                    if (state == 1) {
                        thisYear = nextYear;
                        lastYear = thisYear - 1;
                        nextYear = thisYear + 1;
                    }
                }
                else if (m_am_Direction == 2) {
                    toY = -monthButtonHeight * m_am_Tick / m_am_TotalTick;
                    if (state == 1) {
                        thisYear = lastYear;
                        lastYear = thisYear - 1;
                        nextYear = thisYear + 1;
                    }
                }
                if (state == 0) {
                    monthButtons = m_monthButtons;
                }
                else if (state == 1) {
                    monthButtons = m_monthButtons_am;
                }
                int dheight = monthButtonHeight / 3;
                int buttonSize = monthButtons.size();
                for (int i = 0; i < buttonSize; i++) {
                    if (i == 8) {
                        dheight = height - top;
                    }
                    MonthButton monthButton = monthButtons.get(i);
                    monthButton.Year = thisYear;
                    int vOffSet = 0;
                    if (state == 1) {
                        if (m_am_Tick > 0) {
                            monthButton.Visible = true;
                            if (m_am_Direction == 1) {
                                vOffSet = toY - monthButtonHeight;
                            }
                            else if (m_am_Direction == 2) {
                                vOffSet = toY + monthButtonHeight;
                            }
                        }
                        else {
                            monthButton.Visible = false;
                            continue;
                        }
                    }
                    else {
                        vOffSet = toY;
                    }
                    if ((i + 1) % 4 == 0) {
                        FCPoint dp = new FCPoint(left, top + vOffSet);
                        FCSize ds = new FCSize(width - left, dheight);
                        monthButton.Bounds = new FCRect(dp.x, dp.y, dp.x + ds.cx, dp.y + ds.cy);
                        left = 0;
                        if (i != 0 && i != buttonSize - 1) {
                            top += dheight;
                        }
                    }
                    else {
                        FCPoint dp = new FCPoint(left, top + vOffSet);
                        FCSize ds = new FCSize(width / 4 + ((i + 1) % 4) % 2, dheight);
                        monthButton.Bounds = new FCRect(dp.x, dp.y, dp.x + ds.cx, dp.y + ds.cy);
                        left += ds.cx;
                    }
                }
            }
        }

        /// <summary>
        /// ���������
        /// </summary>
        public virtual void onTimer() {
            if (m_am_Tick > 0) {
                m_am_Tick = (int)((double)m_am_Tick * 2 / 3);
                if (m_calendar != null) {
                    m_calendar.update();
                    m_calendar.invalidate();
                }
            }
        }

        /// <summary>
        /// ѡ�����
        /// </summary>
        /// <param name="year">���</param>
        public void selectYear(int year) {
            if (m_calendar != null) {
                if (m_year != year) {
                    if (year > m_year) {
                        m_am_Direction = 1;
                    }
                    else {
                        m_am_Direction = 2;
                    }
                    if (m_calendar.UseAnimation) {
                        m_am_Tick = m_am_TotalTick;
                    }
                    m_year = year;
                }
            }
        }

        /// <summary>
        /// ��ʾ
        /// </summary>
        public virtual void show() {
            int monthButtonSize = m_monthButtons.size();
            for (int i = 0; i < monthButtonSize; i++) {
                MonthButton monthButton = m_monthButtons.get(i);
                monthButton.Visible = true;
            }
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public virtual void update() {
            onResetDiv(0);
            onResetDiv(1);
        }
    }
}
