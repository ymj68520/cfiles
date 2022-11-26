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
    /// ���ڿؼ�
    /// </summary>
    public class FCDateTimePicker : FCTextBox {
        /// <summary>
        /// �������ڿؼ�
        /// </summary>
        public FCDateTimePicker() {
            m_dropDownButtonTouchDownEvent = new FCTouchEvent(DropDownButtonTouchDown);
            m_selectedTimeChangedEvent = new FCEvent(selectedTimeChanged);
        }

        /// <summary>
        /// ������ť�������ָ��
        /// </summary>
        private FCTouchEvent m_dropDownButtonTouchDownEvent;

        /// <summary>
        /// ѡ�����ڸı亯��ָ��
        /// </summary>
        private FCEvent m_selectedTimeChangedEvent;

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ����
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
        }

        protected String m_customFormat = "yyyy-MM-dd";

        /// <summary>
        /// ��ȡ���������ڸ�ʽ
        /// </summary>
        public virtual String CustomFormat {
            get { return m_customFormat; }
            set { m_customFormat = value; }
        }

        protected FCButton m_dropDownButton;

        /// <summary>
        /// ��ȡ������ť
        /// </summary>
        public virtual FCButton DropDownButton {
            get { return m_dropDownButton; }
        }

        protected FCMenu m_dropDownMenu;

        /// <summary>
        /// ��ȡ�����˵�
        /// </summary>
        public virtual FCMenu DropDownMenu {
            get { return m_dropDownMenu; }
        }

        protected bool m_showTime = true;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾʱ��
        /// </summary>
        public virtual bool ShowTime {
            get { return m_showTime; }
            set { m_showTime = value; }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <returns></returns>
        public virtual FCCalendar CreateCalendar() {
            FCCalendar calendar = new FCCalendar();
            calendar.Dock = FCDockStyle.Fill;
            return calendar;
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_calendar != null) {
                    if (m_selectedTimeChangedEvent != null) {
                        m_calendar.removeEvent(m_selectedTimeChangedEvent, FCEventID.SELECTEDTIMECHANGED);
                        m_selectedTimeChangedEvent = null;
                    }
                }
                if (m_dropDownButton != null) {
                    if (m_dropDownButtonTouchDownEvent != null) {
                        m_dropDownButton.removeEvent(m_dropDownButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_dropDownButtonTouchDownEvent = null;
                    }
                }
                if (m_dropDownMenu != null) {
                    Native.removeControl(m_dropDownMenu);
                    m_dropDownMenu.delete();
                    m_dropDownMenu = null;
                }
            }
            base.delete();
        }

        /// <summary>
        /// ������ť�ĵ������
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void DropDownButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            onDropDownOpening();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "DateTimePicker";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        /// <param name="type">����</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "customformat") {
                type = "string";
                value = CustomFormat;
            }
            else if (name == "showtime") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowTime);
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
            propertyNames.add("CustomFormat");
            propertyNames.add("ShowTime");
            return propertyNames;
        }

        /// <summary>
        /// �����˵���ʾ����
        /// </summary>
        public virtual void onDropDownOpening() {
            //���������˵�������
            if (m_dropDownMenu == null) {
                FCHost host = Native.Host;
                m_dropDownMenu = host.createInternalControl(this, "dropdownmenu") as FCMenu;
                Native.addControl(m_dropDownMenu);
                if (m_calendar == null) {
                    m_calendar = CreateCalendar();
                    m_dropDownMenu.addControl(m_calendar);
                    m_calendar.Size = m_dropDownMenu.Size;
                    m_calendar.addEvent(m_selectedTimeChangedEvent, FCEventID.SELECTEDTIMECHANGED);
                }
            }
            if (m_calendar != null && !m_showTime) {
                m_calendar.TimeDiv.Height = 0;
            }
            m_dropDownMenu.Native = Native;
            FCPoint nativePoint = pointToNative(new FCPoint(0, Height));
            m_dropDownMenu.Location = nativePoint;
            m_dropDownMenu.Visible = true;
            if (m_calendar != null) {
                m_calendar.Mode = FCCalendarMode.Day;
            }
            m_dropDownMenu.bringToFront();
            m_dropDownMenu.invalidate();
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            if (m_dropDownButton == null) {
                FCHost host = Native.Host;
                m_dropDownButton = host.createInternalControl(this, "dropdownbutton") as FCButton;
                addControl(m_dropDownButton);
                m_dropDownButton.addEvent(m_dropDownButtonTouchDownEvent, FCEventID.TOUCHDOWN);
            }
            if (m_dropDownMenu != null) {
                m_dropDownMenu.Native = Native;
            }
        }

        /// <summary>
        /// ��ֵ�ı䷽��
        /// </summary>
        public virtual void onSelectedTimeChanged() {
            callEvents(FCEventID.SELECTEDTIMECHANGED);
            if (m_calendar != null) {
                CDay selectedDay = m_calendar.SelectedDay;
                if (selectedDay != null) {
                    DateTime date = new DateTime(selectedDay.Year, selectedDay.Month, selectedDay.Day, m_calendar.TimeDiv.Hour,
                        m_calendar.TimeDiv.Minute, m_calendar.TimeDiv.Second);
                    Text = date.ToString(m_customFormat);
                    invalidate();
                }
            }
        }

        /// <summary>
        /// ѡ�����ڸı��¼��ص�����
        /// </summary>
        /// <param name="sender">������</param>
        private void selectedTimeChanged(object sender) {
            onSelectedTimeChanged();
        }

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "customformat") {
                CustomFormat = value;
            }
            else if (name == "showtime") {
                ShowTime = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public override void update() {
            base.update();
            int width = Width, height = Height;
            if (m_dropDownButton != null) {
                int dWidth = m_dropDownButton.Width;
                Padding = new FCPadding(0, 0, dWidth, 0);
                m_dropDownButton.Location = new FCPoint(width - dWidth, 0);
                m_dropDownButton.Size = new FCSize(dWidth, height);
            }
        }
    }
}
