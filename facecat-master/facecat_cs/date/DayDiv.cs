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
    public class DayDiv {
        /// <summary>
        /// �������ڲ�
        /// </summary>
        public DayDiv(FCCalendar calendar) {
            m_calendar = calendar;
            onLoad();
        }

        /// <summary>
        /// ���ʱ�����µ���
        /// </summary>
        protected int m_am_ClickRowFrom;

        /// <summary>
        /// ���ʱ�ĵ��µ���
        /// </summary>
        protected int m_am_ClickRowTo;

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
        /// ���ڲ�ļ���
        /// </summary>
        public ArrayList<DayButton> m_dayButtons = new ArrayList<DayButton>();

        /// <summary>
        /// �������ڲ�ļ���
        /// </summary>
        public ArrayList<DayButton> m_dayButtons_am = new ArrayList<DayButton>();

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ�����������ؼ�
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public virtual void delete() {
            m_dayButtons.clear();
            m_dayButtons_am.clear();
        }

        /// <summary>
        /// ����
        /// </summary>
        public virtual void hide() {
            int dayButtonSize = m_dayButtons.size();
            for (int i = 0; i < dayButtonSize; i++) {
                DayButton dayButton = m_dayButtons.get(i);
                dayButton.Visible = false;
            }
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onClick(FCTouchInfo touchInfo) {
            FCPoint mp = touchInfo.m_firstPoint;
            int dayButtonsSize = m_dayButtons.size();
            for (int i = 0; i < dayButtonsSize; i++) {
                DayButton dayButton = m_dayButtons.get(i);
                if (dayButton.Visible) {
                    FCRect bounds = dayButton.Bounds;
                    if (mp.x >= bounds.left && mp.x <= bounds.right && mp.y >= bounds.top && mp.y <= bounds.bottom) {
                        dayButton.onClick(touchInfo);
                        return;
                    }
                }
            }
            int dayButtonAmSize = m_dayButtons_am.size();
            for (int i = 0; i < dayButtonAmSize; i++) {
                DayButton dayButton = m_dayButtons_am.get(i);
                if (dayButton.Visible) {
                    FCRect bounds = dayButton.Bounds;
                    if (mp.x >= bounds.left && mp.x <= bounds.right && mp.y >= bounds.top && mp.y <= bounds.bottom) {
                        dayButton.onClick(touchInfo);
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
                if (m_dayButtons.size() == 0 || m_dayButtons_am.size() == 0) {
                    m_dayButtons.clear();
                    m_dayButtons_am.clear();
                    for (int i = 0; i < 42; i++) {
                        DayButton dayButton = new DayButton(m_calendar);
                        m_dayButtons.add(dayButton);
                        DayButton dayButtonAm = new DayButton(m_calendar);
                        dayButtonAm.Visible = false;
                        m_dayButtons_am.add(dayButtonAm);
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
            int dayButtonsSize = m_dayButtons.size();
            for (int i = 0; i < dayButtonsSize; i++) {
                DayButton dayButton = m_dayButtons.get(i);
                if (dayButton.Visible) {
                    FCRect bounds = dayButton.Bounds;
                    dayButton.onPaintBackGround(paint, bounds);
                    dayButton.onPaintForeground(paint, bounds);
                    dayButton.onPaintBorder(paint, bounds);
                }
            }
            int dayButtonAmSize = m_dayButtons_am.size();
            for (int i = 0; i < dayButtonAmSize; i++) {
                DayButton dayButton = m_dayButtons_am.get(i);
                if (dayButton.Visible) {
                    FCRect bounds = dayButton.Bounds;
                    dayButton.onPaintBackGround(paint, bounds);
                    dayButton.onPaintForeground(paint, bounds);
                    dayButton.onPaintBorder(paint, bounds);
                }
            }
        }

        /// <summary>
        /// ��������ͼ��
        /// </summary>
        /// <param name="state">״̬</param>
        public virtual void onResetDiv(int state) {
            if (m_calendar != null) {
                int size = 0;
                CMonth thisMonth = m_calendar.Month;
                CMonth lastMonth = m_calendar.getLastMonth(thisMonth.Year, thisMonth.Month);
                CMonth nextMonth = m_calendar.getNextMonth(thisMonth.Year, thisMonth.Month);
                int left = 0;
                int headHeight = m_calendar.HeadDiv.Height;
                int top = headHeight;
                int width = m_calendar.Width;
                int height = m_calendar.Height;
                height -= m_calendar.TimeDiv.Height;
                int dayButtonHeight = height - top;
                if (dayButtonHeight < 1) dayButtonHeight = 1;
                int subH = 0, toY = 0;
                ArrayList<DayButton> dayButtons = new ArrayList<DayButton>();
                if (m_am_Direction == 1) {
                    subH = (6 - (m_am_ClickRowTo - m_am_ClickRowFrom)) * (dayButtonHeight / 6);
                    toY = -height + subH + headHeight;
                    toY = toY * m_am_Tick / m_am_TotalTick;
                    if (state == 1) {
                        thisMonth = nextMonth;
                        lastMonth = m_calendar.getLastMonth(thisMonth.Year, thisMonth.Month);
                        nextMonth = m_calendar.getNextMonth(thisMonth.Year, thisMonth.Month);
                    }
                }
                else if (m_am_Direction == 2) {
                    subH = (6 - (m_am_ClickRowFrom - m_am_ClickRowTo)) * (dayButtonHeight / 6);
                    toY = height - subH - headHeight;
                    toY = toY * m_am_Tick / m_am_TotalTick;
                    if (state == 1) {
                        thisMonth = lastMonth;
                        lastMonth = m_calendar.getLastMonth(thisMonth.Year, thisMonth.Month);
                        nextMonth = m_calendar.getNextMonth(thisMonth.Year, thisMonth.Month);
                    }
                }
                if (state == 0) {
                    dayButtons = m_dayButtons;
                }
                else if (state == 1) {
                    dayButtons = m_dayButtons_am;
                }
                int dheight = dayButtonHeight / 6;
                HashMap<int, CDay> days = thisMonth.Days;
                CDay firstDay = days.get(1);
                int startDayOfWeek = (int)new DateTime(firstDay.Year, firstDay.Month, firstDay.Day).DayOfWeek;
                int buttonSize = dayButtons.size();
                for (int i = 0; i < buttonSize; i++) {
                    if (i == 35) {
                        dheight = height - top;
                    }
                    DayButton dayButton = dayButtons.get(i);
                    int vOffSet = 0;
                    if (state == 1) {
                        if (m_am_Tick > 0) {
                            dayButton.Visible = true;
                            if (m_am_Direction == 1) {
                                vOffSet = toY + dayButtonHeight;
                            }
                            else if (m_am_Direction == 2) {
                                vOffSet = toY - dayButtonHeight;
                            }
                        }
                        else {
                            dayButton.Visible = false;
                            continue;
                        }
                    }
                    else {
                        vOffSet = toY;
                    }
                    if ((i + 1) % 7 == 0) {
                        FCPoint dp = new FCPoint(left, top + vOffSet);
                        FCSize ds = new FCSize(width - left, dheight);
                        dayButton.Bounds = new FCRect(dp.x, dp.y, dp.x + ds.cx, dp.y + ds.cy);
                        left = 0;
                        if (i != 0 && i != size - 1) {
                            top += dheight;
                        }
                    }
                    else {
                        FCPoint dp = new FCPoint(left, top + vOffSet);
                        FCSize ds = new FCSize(width / 7 + ((i + 1) % 7) % 2, dheight);
                        dayButton.Bounds = new FCRect(dp.x, dp.y, dp.x + ds.cx, dp.y + ds.cy);
                        left += ds.cx;
                    }
                    CDay cDay = null;
                    dayButton.InThisMonth = false;
                    if (i >= startDayOfWeek && i <= startDayOfWeek + days.size() - 1) {
                        cDay = days.get(i - startDayOfWeek + 1);
                        dayButton.InThisMonth = true;
                    }
                    else if (i < startDayOfWeek) {
                        cDay = lastMonth.Days.get(lastMonth.Days.size() - startDayOfWeek + i + 1);
                    }
                    else if (i > startDayOfWeek + days.size() - 1) {
                        cDay = nextMonth.Days.get(i - startDayOfWeek - days.size() + 1);
                    }
                    int day = cDay.Day;
                    dayButton.Day = cDay;
                    if (state == 0 && dayButton.Day != null && dayButton.Day == m_calendar.SelectedDay) {
                        dayButton.Selected = true;
                    }
                    else {
                        dayButton.Selected = false;
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
        /// ѡ������
        /// </summary>
        /// <param name="selectedDay">����</param>
        public void selectedDay(CDay selectedDay) {
            if (m_calendar != null) {
                CMonth m = m_calendar.Years.getYear(selectedDay.Year).Months.get(selectedDay.Month);
                CMonth thisMonth = m_calendar.Month;
                if (m != thisMonth) {
                    if (thisMonth.Year * 12 + thisMonth.Month > m.Year * 12 + m.Month) {
                        m_am_Direction = 1;
                    }
                    else {
                        m_am_Direction = 2;
                    }
                    int dayButtonSize = m_dayButtons.size();
                    for (int i = 0; i < dayButtonSize; i++) {
                        DayButton dayButton = m_dayButtons.get(i);
                        if ((m_am_Direction == 1 && dayButton.Day == thisMonth.FirstDay)
                            || m_am_Direction == 2 && dayButton.Day == thisMonth.LastDay) {
                            m_am_ClickRowFrom = i / 7;
                            if (i % 7 != 0) {
                                m_am_ClickRowFrom += 1;
                            }
                        }
                    }
                    m_calendar.Month = m;
                    onResetDiv(0);
                    int mdayButtonSize = m_dayButtons_am.size();
                    for (int i = 0; i < mdayButtonSize; i++) {
                        DayButton dayButtonAm = m_dayButtons_am.get(i);
                        if ((m_am_Direction == 1 && dayButtonAm.Day == m.LastDay)
                        || (m_am_Direction == 2 && dayButtonAm.Day == m.FirstDay)) {
                            m_am_ClickRowTo = i / 7;
                            if (i % 7 != 0) {
                                m_am_ClickRowTo += 1;
                            }
                        }
                    }
                    if (m_calendar.UseAnimation) {
                        m_am_Tick = m_am_TotalTick;
                    }
                }
                else {
                    int dayButtonSize = m_dayButtons.size();
                    for (int i = 0; i < dayButtonSize; i++) {
                        DayButton dayButton = m_dayButtons.get(i);
                        if (dayButton.Day != selectedDay) {
                            dayButton.Selected = false;
                        }
                    }
                    m_calendar.Month = m;
                }
            }
        }

        /// <summary>
        /// ��ʾ
        /// </summary>
        public virtual void show() {
            int dayButtonSize = m_dayButtons.size();
            for (int i = 0; i < dayButtonSize; i++) {
                DayButton dayButton = m_dayButtons.get(i);
                dayButton.Visible = true;
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
