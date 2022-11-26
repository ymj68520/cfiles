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
    /// �����б�ؼ����б�
    /// </summary>
    public class FCComboBoxMenu : FCMenu {
        /// <summary>
        /// �����б�
        /// </summary>
        public FCComboBoxMenu() {

        }

        protected FCComboBox m_comboBox;

        /// <summary>
        /// ��ȡ�������б�ؼ�
        /// </summary>
        public virtual FCComboBox ComboBox {
            get { return m_comboBox; }
            set { m_comboBox = value; }
        }

        /// <summary>
        /// �Ƿ��Զ�����
        /// </summary>
        /// <returns>�Ƿ�����</returns>
        public override bool onAutoHide() {
            if (m_comboBox != null && m_comboBox.Focused) {
                return false;
            }
            return true;
        }
    }

    /// <summary>
    /// �����б�ؼ�
    /// </summary>
    public class FCComboBox : FCTextBox {
        /// <summary>
        /// ���������б�
        /// </summary>
        public FCComboBox() {
            m_dropDownButtonTouchDownEvent = new FCTouchEvent(dropDownButtonTouchDown);
            m_menuItemClickEvent = new FCMenuItemTouchEvent(menuItemClick);
            m_menuKeyDownEvent = new FCKeyEvent(MenuKeyDown);
        }

        /// <summary>
        /// ������ť�ĵ������
        /// </summary>
        private FCTouchEvent m_dropDownButtonTouchDownEvent;

        /// <summary>
        /// �����˵��ĵ������
        /// </summary>
        private FCMenuItemTouchEvent m_menuItemClickEvent;

        /// <summary>
        /// �����˵��İ�������
        /// </summary>
        private FCKeyEvent m_menuKeyDownEvent;

        protected FCButton m_dropDownButton;

        /// <summary>
        /// ��ȡ������ť
        /// </summary>
        public virtual FCButton DropDownButton {
            get { return m_dropDownButton; }
        }

        protected FCComboBoxMenu m_dropDownMenu;

        /// <summary>
        /// ��ȡ�����˵�
        /// </summary>
        public virtual FCComboBoxMenu DropDownMenu {
            get { return m_dropDownMenu; }
        }

        /// <summary>
        /// ��ȡ������ѡ�е�����
        /// </summary>
        public virtual int SelectedIndex {
            get {
                if (m_dropDownMenu != null) {
                    ArrayList<FCMenuItem> items = m_dropDownMenu.getItems();
                    int itemSize = items.size();
                    for (int i = 0; i < itemSize; i++) {
                        FCMenuItem item = items.get(i);
                        if (item.Checked) {
                            return i;
                        }
                    }
                }
                return -1;
            }
            set {
                if (m_dropDownMenu != null) {
                    ArrayList<FCMenuItem> items = m_dropDownMenu.getItems();
                    int itemSize = items.size();
                    bool changed = false;
                    for (int i = 0; i < itemSize; i++) {
                        FCMenuItem item = items.get(i);
                        if (i == value) {
                            if (!item.Checked) {
                                //ѡ�в���������
                                item.Checked = true;
                                changed = true;
                            }
                            Text = item.Text;
                        }
                        else {
                            item.Checked = false;
                        }
                    }
                    if (changed) {
                        onSelectedIndexChanged();
                    }
                }
            }
        }

        /// <summary>
        /// ��ȡ������ѡ�е�����
        /// </summary>
        public virtual String SelectedText {
            get {
                if (m_dropDownMenu != null) {
                    ArrayList<FCMenuItem> items = m_dropDownMenu.getItems();
                    int itemSize = items.size();
                    for (int i = 0; i < itemSize; i++) {
                        FCMenuItem item = items.get(i);
                        if (item.Checked) {
                            return item.Text;
                        }
                    }
                }
                return null;
            }
            set {
                if (m_dropDownMenu != null) {
                    ArrayList<FCMenuItem> items = m_dropDownMenu.getItems();
                    int itemSize = items.size();
                    bool changed = false;
                    for (int i = 0; i < itemSize; i++) {
                        FCMenuItem item = items.get(i);
                        if (item.Text == value) {
                            //ѡ�в���������
                            if (!item.Checked) {
                                item.Checked = true;
                                changed = true;
                            }
                            Text = item.Text;
                        }
                        else {
                            item.Checked = false;
                        }
                    }
                    if (changed) {
                        onSelectedIndexChanged();
                    }
                }
            }
        }

        /// <summary>
        /// ��ȡ������ѡ�е�ֵ
        /// </summary>
        public virtual String SelectedValue {
            get {
                if (m_dropDownMenu != null) {
                    ArrayList<FCMenuItem> items = m_dropDownMenu.getItems();
                    int itemSize = items.size();
                    for (int i = 0; i < itemSize; i++) {
                        FCMenuItem item = items.get(i);
                        if (item.Checked) {
                            return item.Value;
                        }
                    }
                }
                return null;
            }
            set {
                if (m_dropDownMenu != null) {
                    ArrayList<FCMenuItem> items = m_dropDownMenu.getItems();
                    int itemSize = items.size();
                    bool changed = false;
                    for (int i = 0; i < itemSize; i++) {
                        FCMenuItem item = items.get(i);
                        if (item.Value == value) {
                            //ѡ�в���������
                            if (!item.Checked) {
                                item.Checked = true;
                                changed = true;
                            }
                            Text = item.Text;
                        }
                        else {
                            item.Checked = false;
                        }
                    }
                    if (changed) {
                        onSelectedIndexChanged();
                    }
                }
            }
        }

        /// <summary>
        /// ��Ӳ˵���
        /// </summary>
        /// <param name="item">�˵���</param>
        public void addItem(FCMenuItem item) {
            if (m_dropDownMenu != null) {
                m_dropDownMenu.addItem(item);
            }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_dropDownButton != null) {
                    if (m_dropDownButtonTouchDownEvent != null) {
                        m_dropDownButton.removeEvent(m_dropDownButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_dropDownButtonTouchDownEvent = null;
                    }
                }
                if (m_dropDownMenu != null) {
                    if (m_menuItemClickEvent != null) {
                        m_dropDownMenu.removeEvent(m_menuItemClickEvent, FCEventID.MENUITEMCLICK);
                        m_menuItemClickEvent = null;
                    }
                    if (m_menuKeyDownEvent != null) {
                        m_dropDownMenu.removeEvent(m_menuKeyDownEvent, FCEventID.KEYDOWN);
                        m_menuKeyDownEvent = null;
                    }
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
        private void dropDownButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            onDropDownOpening();
        }

        /// <summary>
        /// ������в˵���
        /// </summary>
        public void clearItems() {
            if (m_dropDownMenu != null) {
                m_dropDownMenu.clearItems();
            }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "ComboBox";
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "SelectedIndexChanged" });
            return eventNames;
        }

        /// <summary>
        /// ��ȡ�˵���
        /// </summary>
        /// <returns>�˵����</returns>
        public ArrayList<FCMenuItem> getItems() {
            if (m_dropDownMenu != null) {
                return m_dropDownMenu.getItems();
            }
            return null;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "selectedindex") {
                type = "int";
                value = FCStr.convertIntToStr(SelectedIndex);
            }
            else if (name == "selectedtext") {
                type = "text";
                value = SelectedText;
            }
            else if (name == "selectedvalue") {
                type = "text";
                value = SelectedValue;
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
            propertyNames.AddRange(new String[] { "SelectedIndex", "SelectedText", "SelectedValue" });
            return propertyNames;
        }

        /// <summary>
        /// ����˵���
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="item">�˵���</param>
        public void insertItem(int index, FCMenuItem item) {
            if (m_dropDownMenu != null) {
                m_dropDownMenu.insertItem(index, item);
            }
        }

        /// <summary>
        /// �˵���ĵ������
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="item">�˵���</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void menuItemClick(object sender, FCMenuItem item, FCTouchInfo touchInfo) {
            Text = item.Text;
            ArrayList<FCMenuItem> items = getItems();
            int itemSize = items.size();
            for (int i = 0; i < itemSize; i++) {
                if (items.get(i) == item) {
                    SelectedIndex = i;
                    break;
                }
            }
            SelectionStart = Text.Length;
            invalidate();
        }

        /// <summary>
        /// �����˵��İ�������
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="key">����</param>
        private void MenuKeyDown(object sender, char key) {
            if (key == 13) {
                onSelectedIndexChanged();
            }
        }

        /// <summary>
        /// �˵���������
        /// </summary>
        public virtual void onDropDownOpening() {
            if (m_dropDownMenu != null) {
                m_dropDownMenu.Native = Native;
                FCPoint nativePoint = pointToNative(new FCPoint(0, Height));
                m_dropDownMenu.Location = nativePoint;
                m_dropDownMenu.Size = new FCSize(Width, m_dropDownMenu.getContentHeight());
                m_dropDownMenu.Width = Width;
                m_dropDownMenu.Visible = true;
                m_dropDownMenu.bringToFront();
                m_dropDownMenu.invalidate();
            }
        }

        /// <summary>
        /// ���̰��·���
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyDown(char key) {
            base.onKeyDown(key);
            FCHost host = Native.Host;
            if (!host.isKeyPress(0x10) && !host.isKeyPress(0x11) && !host.isKeyPress(0x12)) {
                if (LinesCount <= 1) {
                    if (key == 13 || key == 38 || key == 40) {
                        if (m_dropDownMenu != null) {
                            m_dropDownMenu.onKeyDown(key);
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            FCHost host = Native.Host;
            if (m_dropDownButton == null) {
                m_dropDownButton = host.createInternalControl(this, "dropdownbutton") as FCButton;
                addControl(m_dropDownButton);
                m_dropDownButton.addEvent(m_dropDownButtonTouchDownEvent, FCEventID.TOUCHDOWN);
            }
            if (m_dropDownMenu == null) {
                m_dropDownMenu = host.createInternalControl(this, "dropdownmenu") as FCComboBoxMenu;
                Native.addControl(m_dropDownMenu);
                m_dropDownMenu.Visible = false;
                m_dropDownMenu.addEvent(m_menuItemClickEvent, FCEventID.MENUITEMCLICK);
                m_dropDownMenu.addEvent(m_menuKeyDownEvent, FCEventID.KEYDOWN);
            }
            else {
                m_dropDownMenu.Native = Native;
            }
        }

        /// <summary>
        /// ѡ�������ı䷽��
        /// </summary>
        public virtual void onSelectedIndexChanged() {
            callEvents(FCEventID.SELECTEDINDEXCHANGED);
        }

        /// <summary>
        /// �������ַ���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchWheel(FCTouchInfo touchInfo) {
            base.onTouchWheel(touchInfo);
            if (LinesCount <= 1) {
                if (m_dropDownMenu != null) {
                    FCTouchInfo newTouchInfo = touchInfo.clone();
                    newTouchInfo.m_firstPoint = m_dropDownMenu.TouchPoint;
                    newTouchInfo.m_secondPoint = m_dropDownMenu.TouchPoint;
                    m_dropDownMenu.onTouchWheel(newTouchInfo);
                }
            }
        }

        /// <summary>
        /// �Ƴ��˵���
        /// </summary>
        /// <param name="item">�˵���</param>
        public void removeItem(FCMenuItem item) {
            if (m_dropDownMenu != null) {
                m_dropDownMenu.removeItem(item);
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "selectedindex") {
                SelectedIndex = FCStr.convertStrToInt(value);
            }
            else if (name == "selectedtext") {
                SelectedText = value;
            }
            else if (name == "selectedvalue") {
                SelectedValue = value;
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
                m_dropDownButton.Location = new FCPoint(width - dWidth, 0);
                m_dropDownButton.Size = new FCSize(dWidth, height);
                Padding = new FCPadding(0, 0, dWidth, 0);
            }
        }
    }
}
