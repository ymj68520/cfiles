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
    /// ����ģʽ
    /// </summary>
    public enum FCCalendarMode {
        /// <summary>
        /// ѡ����
        /// </summary>
        Day,
        /// <summary>
        /// ѡ����
        /// </summary>
        Month,
        /// <summary>
        /// ѡ����
        /// </summary>
        Year
    }

    /// <summary>
    /// �����ؼ�
    /// </summary>
    public partial class FCCalendar : FCView {
        /// <summary>
        /// ���������ؼ�
        /// </summary>
        public FCCalendar() {
            m_years = new CYears();
            FCSize size = new FCSize(200, 200);
            Size = size;
        }

        /// <summary>
        /// ��ǰ���·�
        /// </summary>
        protected int m_month;

        /// <summary>
        /// ���ID
        /// </summary>
        private int m_timerID = getNewTimerID();

        /// <summary>
        /// ��ǰ�����
        /// </summary>
        protected int m_year;

        protected DayDiv m_dayDiv;

        /// <summary>
        /// ��ȡ���������ڲ�
        /// </summary>
        public virtual DayDiv DayDiv {
            get { return m_dayDiv; }
            set { m_dayDiv = value; }
        }

        protected HeadDiv m_headDiv;

        /// <summary>
        /// ��ȡ������ͷ����
        /// </summary>
        public virtual HeadDiv HeadDiv {
            get { return m_headDiv; }
            set { m_headDiv = value; }
        }

        protected FCCalendarMode m_mode = FCCalendarMode.Day;

        /// <summary>
        /// ��ȡ������������ģʽ
        /// </summary>
        public virtual FCCalendarMode Mode {
            get { return m_mode; }
            set {
                if (m_mode != value) {
                    FCCalendarMode oldMode = m_mode;
                    m_mode = value;
                    //��
                    if (m_mode == FCCalendarMode.Month) {
                        if (m_dayDiv != null) {
                            m_dayDiv.hide();
                        }
                        if (m_yearDiv != null) {
                            m_yearDiv.hide();
                        }
                        if (m_monthDiv == null) {
                            m_monthDiv = new MonthDiv(this);
                        }
                        if (oldMode == FCCalendarMode.Day) {
                            m_monthDiv.selectYear(m_year);
                        }
                        m_monthDiv.show();
                    }
                    //��
                    else if (m_mode == FCCalendarMode.Year) {
                        if (m_dayDiv != null) {
                            m_dayDiv.hide();
                        }
                        int startYear = m_year;
                        if (m_monthDiv != null) {
                            startYear = m_monthDiv.Year;
                            m_monthDiv.hide();
                        }
                        if (m_yearDiv == null) {
                            m_yearDiv = new YearDiv(this);
                        }
                        m_yearDiv.selectStartYear(startYear);
                        m_yearDiv.show();
                    }
                    else {
                        if (m_monthDiv != null) {
                            m_monthDiv.hide();
                        }
                        if (m_yearDiv != null) {
                            m_yearDiv.hide();
                        }
                        m_dayDiv.show();
                    }
                }
            }
        }

        /// <summary>
        /// ��ȡ�������·�
        /// </summary>
        public virtual CMonth Month {
            get { return m_years.getYear(m_year).Months.get(m_month); }
            set {
                m_year = value.Year;
                m_month = value.Month;
                update();
            }
        }

        /// <summary>
        /// �·ݲ�
        /// </summary>
        protected MonthDiv m_monthDiv;

        /// <summary>
        /// ��ȡ�������·ݲ�
        /// </summary>
        public virtual MonthDiv MonthDiv {
            get { return m_monthDiv; }
            set { m_monthDiv = value; }
        }

        protected CDay m_selectedDay;

        /// <summary>
        /// ��ȡѡ������
        /// </summary>
        public virtual CDay SelectedDay {
            set {
                if (m_selectedDay != value) {
                    m_selectedDay = value;
                    if (m_dayDiv != null) {
                        m_dayDiv.selectedDay(m_selectedDay);
                    }
                    invalidate();
                    onSelectedTimeChanged();
                }
            }
            get { return m_selectedDay; }
        }

        protected TimeDiv m_timeDiv;

        /// <summary>
        /// ��ȡ������ʱ���
        /// </summary>
        public virtual TimeDiv TimeDiv {
            get { return m_timeDiv; }
            set { m_timeDiv = value; }
        }

        protected bool m_useAnimation;

        /// <summary>
        /// ��ȡ�������Ƿ�ʹ�ö���
        /// </summary>
        public virtual bool UseAnimation {
            get { return m_useAnimation; }
            set {
                m_useAnimation = value;
                if (m_useAnimation) {
                    startTimer(m_timerID, 20);
                }
                else {
                    stopTimer(m_timerID);
                }
            }
        }

        protected YearDiv m_yearDiv;

        /// <summary>
        /// ��ȡ��������ݲ�
        /// </summary>
        public virtual YearDiv YearDiv {
            get { return m_yearDiv; }
            set { m_yearDiv = value; }
        }

        protected CYears m_years;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual CYears Years {
            get { return m_years; }
            set {
                m_years = value;
                update();
                SelectedDay = Month.Days.get(1);
            }
        }

        /// <summary>
        /// �����¼�
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_dayDiv != null) {
                    m_dayDiv.delete();
                }
                if (m_monthDiv != null) {
                    m_monthDiv.delete();
                }
                if (m_yearDiv != null) {
                    m_yearDiv.delete();
                }
                stopTimer(m_timerID);
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "Calendar";
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "SelectedTimeChanged" });
            return eventNames;
        }

        /// <summary>
        /// �������»�ȡ�ϸ���
        /// </summary>
        /// <param name="year">��</param>
        /// <param name="month">��</param>
        /// <returns>�ϸ���</returns>
        public CMonth getLastMonth(int year, int month) {
            int lastMonth = month - 1;
            int lastYear = year;
            if (lastMonth == 0) {
                lastMonth = 12;
                lastYear -= 1;
            }
            return m_years.getYear(lastYear).Months.get(lastMonth);
        }

        /// <summary>
        /// ��ȡ�¸���
        /// </summary>
        /// <param name="year">��</param>
        /// <param name="month">��</param>
        /// <returns>�¸���</returns>
        public CMonth getNextMonth(int year, int month) {
            int nextMonth = month + 1;
            int nextYear = year;
            if (nextMonth == 13) {
                nextMonth = 1;
                nextYear += 1;
            }
            return m_years.getYear(nextYear).Months.get(nextMonth);
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        /// <param name="type">����</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "selectedday") {
                type = "string";
                value = String.Format("{0}-{1}-{2}", m_year, m_month, m_selectedDay.Day);
            }
            else if (name == "useanimation") {
                type = "bool";
                value = FCStr.convertBoolToStr(UseAnimation);
            }
            else {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.add("SeletedDay");
            propertyNames.add("UseAnimation");
            return propertyNames;
        }

        /// <summary>
        /// �ص��ϸ���
        /// </summary>
        public void goLastMonth() {
            SelectedDay = getLastMonth(m_year, m_month).Days.get(1);
        }

        /// <summary>
        /// ǰ���¸���
        /// </summary>
        public void goNextMonth() {
            SelectedDay = getNextMonth(m_year, m_month).Days.get(1);
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            base.onClick(touchInfo);
            if (m_dayDiv != null) {
                m_dayDiv.onClick(touchInfo);
            }
            if (m_monthDiv != null) {
                m_monthDiv.onClick(touchInfo);
            }
            if (m_yearDiv != null) {
                m_yearDiv.onClick(touchInfo);
            }
        }

        /// <summary>
        /// �ؼ�������¼�
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            FCHost host = Native.Host;
            if (m_dayDiv == null) {
                m_dayDiv = new DayDiv(this);
            }
            if (m_timeDiv == null) {
                m_timeDiv = new TimeDiv(this);
            }
            if (m_headDiv == null) {
                m_headDiv = host.createInternalControl(this, "headdiv") as HeadDiv;
                addControl(m_headDiv);
            }
            if (m_useAnimation) {
                startTimer(m_timerID, 20);
            }
            else {
                stopTimer(m_timerID);
            }
            if (m_years != null && m_year == 0 && m_month == 0) {
                DateTime date = DateTime.Now;
                m_year = date.Year;
                m_month = date.Month;
                SelectedDay = m_years.getYear(m_year).Months.get(m_month).Days.get(date.Day);
            }
        }

        /// <summary>
        /// ���̷���
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyDown(char key) {
            base.onKeyDown(key);
            FCHost host = Native.Host;
            if (!host.isKeyPress(0x10) && !host.isKeyPress(0x11) && !host.isKeyPress(0x12)) {
                CMonth thisMonth = Month;
                CMonth lastMonth = getLastMonth(m_year, m_month);
                CMonth nextMonth = getNextMonth(m_year, m_month);
                int today = m_selectedDay.Day;
                if (key >= 37 && key <= 40) {
                    switch ((int)key) {
                        case 37:
                            if (m_selectedDay == thisMonth.FirstDay) {
                                SelectedDay = lastMonth.LastDay;
                            }
                            else {
                                SelectedDay = thisMonth.Days.get(today - 1);
                            }
                            break;
                        case 38:
                            if (today <= 7) {
                                SelectedDay = lastMonth.Days.get(lastMonth.Days.size() - (7 - today));
                            }
                            else {
                                SelectedDay = thisMonth.Days.get(m_selectedDay.Day - 7);
                            }
                            break;
                        case 39:
                            if (m_selectedDay == thisMonth.LastDay) {
                                SelectedDay = nextMonth.FirstDay;
                            }
                            else {
                                SelectedDay = thisMonth.Days.get(today + 1);
                            }
                            break;
                        case 40:
                            if (today > thisMonth.Days.size() - 7) {
                                SelectedDay = nextMonth.Days.get(7 - (thisMonth.Days.size() - today));
                            }
                            else {
                                SelectedDay = thisMonth.Days.get(today + 7);
                            }
                            break;
                    }
                }
            }
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect) {
            base.onPaintBackground(paint, clipRect);
            if (m_dayDiv != null) {
                m_dayDiv.onPaint(paint, clipRect);
            }
            if (m_monthDiv != null) {
                m_monthDiv.onPaint(paint, clipRect);
            }
            if (m_yearDiv != null) {
                m_yearDiv.onPaint(paint, clipRect);
            }
            if (m_timeDiv != null) {
                m_timeDiv.onPaint(paint, clipRect);
            }
        }

        /// <summary>
        /// ѡ�����ڸ��ķ���
        /// </summary>
        public virtual void onSelectedTimeChanged() {
            callEvents(FCEventID.SELECTEDTIMECHANGED);
        }

        /// <summary>
        /// ����¼�
        /// </summary>
        /// <param name="timerID">�����</param>
        public override void onTimer(int timerID) {
            base.onTimer(timerID);
            if (m_timerID == timerID) {
                if (m_dayDiv != null) {
                    m_dayDiv.onTimer();
                }
                if (m_monthDiv != null) {
                    m_monthDiv.onTimer();
                }
                if (m_yearDiv != null) {
                    m_yearDiv.onTimer();
                }
                if (m_timeDiv != null) {
                    m_timeDiv.onTimer();
                }
            }
        }

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "selectedday") {
                DateTime date = Convert.ToDateTime(value);
                m_year = date.Year;
                m_month = date.Month;
                SelectedDay = m_years.getYear(m_year).Months.get(m_month).Days.get(date.Day);
            }
            else if (name == "useanimation") {
                UseAnimation = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ���²���
        /// </summary>
        public override void update() {
            base.update();
            if (m_dayDiv != null) {
                m_dayDiv.update();
            }
            if (m_headDiv != null) {
                m_headDiv.bringToFront();
                m_headDiv.update();
            }
            if (m_monthDiv != null) {
                m_monthDiv.update();
            }
            if (m_yearDiv != null) {
                m_yearDiv.update();
            }
            if (m_timeDiv != null) {
                m_timeDiv.update();
            }
        }
    }
}
