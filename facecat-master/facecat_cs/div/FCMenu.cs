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
    /// ����˵��¼�
    /// </summary>
    /// <param name="sender">������</param>
    /// <param name="item">�˵���</param>
    /// <param name="touchInfo">������Ϣ</param>
    public delegate void FCMenuItemTouchEvent(object sender, FCMenuItem item, FCTouchInfo touchInfo);

    /// <summary>
    /// �˵��ؼ�
    /// </summary>
    public class FCMenu : FCLayoutDiv {
        /// <summary>
        /// �����ؼ�
        /// </summary>
        public FCMenu() {
            AutoSize = true;
            LayoutStyle = FCLayoutStyle.TopToBottom;
            MaximumSize = new FCSize(2000, 500);
            ShowHScrollBar = true;
            ShowVScrollBar = true;
            TopMost = true;
            FCSize size = new FCSize(200, 200);
            Size = size;
        }

        /// <summary>
        /// �˵���
        /// </summary>
        public ArrayList<FCMenuItem> m_items = new ArrayList<FCMenuItem>();

        /// <summary>
        /// �����
        /// </summary>
        private int m_timerID = getNewTimerID();

        protected bool m_autoHide = true;

        /// <summary>
        /// ��ȡ�������Ƿ��Զ�����
        /// </summary>
        public virtual bool AutoHide {
            get { return m_autoHide; }
            set { m_autoHide = value; }
        }

        protected FCMenuItem m_parentItem;

        /// <summary>
        /// ��ȡ�����ø��˵���
        /// </summary>
        public virtual FCMenuItem ParentItem {
            get { return m_parentItem; }
            set { m_parentItem = value; }
        }

        protected bool m_popup;

        /// <summary>
        /// ��ȡ�������Ƿ񵯳�
        /// </summary>
        public virtual bool Popup {
            get { return m_popup; }
            set {
                m_popup = value;
                if (m_popup) {
                    Visible = false;
                }
            }
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="item">�˵���</param>
        public void addItem(FCMenuItem item) {
            item.ParentMenu = this;
            item.onAddingItem(-1);
            m_items.add(item);
        }

        /// <summary>
        /// �Զ���Ӧλ�úʹ�С
        /// </summary>
        /// <param name="menu">�˵�</param>
        protected void adjust(FCMenu menu) {
            FCNative native = Native;
            if (AutoSize) {
                int contentHeight = menu.getContentHeight();
                int maximumHeight = MaximumSize.cy;
                menu.Height = Math.Min(contentHeight, maximumHeight);
            }
            FCPoint mPoint = menu.Location;
            FCSize mSize = menu.Size;
            FCSize nSize = native.DisplaySize;
            if (mPoint.x < 0) {
                mPoint.x = 0;
            }
            if (mPoint.y < 0) {
                mPoint.y = 0;
            }
            if (mPoint.x + mSize.cx > nSize.cx) {
                mPoint.x = nSize.cx - mSize.cx;
            }
            if (mPoint.y + mSize.cy > nSize.cy) {
                mPoint.y = nSize.cy - mSize.cy;
            }
            menu.Location = mPoint;
            menu.update();
        }

        /// <summary>
        /// ���ò˵��Ĵ����¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <param name="item">�˵���</param>
        /// <param name="touchInfo">������Ϣ</param>
        protected void callMenuItemTouchEvent(int eventID, FCMenuItem item, FCTouchInfo touchInfo) {
            if (m_events != null && m_events.containsKey(eventID)) {
                ArrayList<object> events = m_events.get(eventID);
                int eventSize = events.size();
                for (int i = 0; i < eventSize; i++) {
                    FCMenuItemTouchEvent func = events.get(i) as FCMenuItemTouchEvent;
                    if (func != null) {
                        func(this, item, touchInfo);
                    }
                }
            }
        }

        /// <summary>
        /// ���ͼ���Ƿ���н���
        /// </summary>
        /// <param name="items">�ؼ�����</param>
        /// <returns>�Ƿ��н���</returns>
        protected bool checkDivFocused(ArrayList<FCMenuItem> items) {
            int itemSize = items.size();
            for (int i = 0; i < items.size(); i++) {
                FCMenuItem item = items.get(i);
                FCMenu dropDownMenu = item.DropDownMenu;
                if (dropDownMenu != null) {
                    if (checkFocused(dropDownMenu)) {
                        return true;
                    }
                }
                ArrayList<FCMenuItem> subItems = item.getItems();
                bool focused = checkDivFocused(subItems);
                if (focused) {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// ��齹��
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>�Ƿ��н���</returns>
        protected bool checkFocused(FCView control) {
            if (control.Focused) {
                return true;
            }
            else {
                ArrayList<FCView> subControls = control.getControls();
                if (subControls != null && subControls.size() > 0) {
                    int subControlSize = subControls.size();
                    for (int i = 0; i < subControlSize; i++) {
                        bool focused = checkFocused(subControls.get(i));
                        if (focused) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }

        /// <summary>
        /// ������е���
        /// </summary>
        public void clearItems() {
            ArrayList<FCMenuItem> itemsCopy = new ArrayList<FCMenuItem>();
            int itemSize = m_items.size();
            for (int i = 0; i < itemSize; i++) {
                itemsCopy.add(m_items.get(i));
            }
            int copySize = itemsCopy.size();
            for (int i = 0; i < copySize; i++) {
                itemsCopy.get(i).onRemovingItem();
                itemsCopy.get(i).delete();
            }
            m_items.clear();
        }

        /// <summary>
        /// �ر�����ؼ�
        /// </summary>
        /// <param name="items">�˵�����</param>
        /// <returns>�Ƿ�رճɹ�</returns>
        protected bool closeMenus(ArrayList<FCMenuItem> items) {
            int itemSize = items.size();
            bool close = false;
            for (int i = 0; i < itemSize; i++) {
                FCMenuItem item = items.get(i);
                ArrayList<FCMenuItem> subItems = item.getItems();
                if (closeMenus(subItems)) {
                    close = true;
                }
                FCMenu dropDownMenu = item.DropDownMenu;
                if (dropDownMenu != null && dropDownMenu.Visible) {
                    dropDownMenu.hide();
                    close = true;
                }
            }
            return close;
        }

        /// <summary>
        /// �����˵�
        /// </summary>
        /// <returns>���ֿؼ�</returns>
        public virtual FCMenu createDropDownMenu() {
            FCMenu menu = new FCMenu();
            menu.Popup = true;
            menu.ShowHScrollBar = true;
            menu.ShowVScrollBar = true;
            return menu;
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                stopTimer(m_timerID);
                clearItems();
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "Menu";
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "MenuItemClick" });
            return eventNames;
        }

        /// <summary>
        /// ��ȡ���еĲ˵���
        /// </summary>
        /// <returns></returns>
        public ArrayList<FCMenuItem> getItems() {
            return m_items;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "popup") {
                type = "bool";
                value = FCStr.convertBoolToStr(Popup);
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
            propertyNames.AddRange(new String[] { "Popup" });
            return propertyNames;
        }

        /// <summary>
        /// ������
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="item">�˵���</param>
        public void insertItem(int index, FCMenuItem item) {
            item.ParentMenu = this;
            item.onAddingItem(index);
            m_items.Insert(index, item);
        }

        /// <summary>
        /// �Ƿ񲻴����Զ�����
        /// </summary>
        /// <returns>�Ƿ񲻴���</returns>
        public virtual bool onAutoHide() {
            return true;
        }

        /// <summary>
        /// �˵��������
        /// </summary>
        /// <param name="item">�˵���</param>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onMenuItemClick(FCMenuItem item, FCTouchInfo touchInfo) {
            if (item.getItems().size() == 0) {
                callMenuItemTouchEvent(FCEventID.MENUITEMCLICK, item, touchInfo);
                bool close = closeMenus(m_items);
                if (m_popup) {
                    hide();
                }
                else {
                    Native.invalidate();
                }
            }
            else {
                onMenuItemTouchMove(item, touchInfo);
            }
        }

        /// <summary>
        /// �˵������ƶ�����
        /// </summary>
        /// <param name="item">�˵���</param>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onMenuItemTouchMove(FCMenuItem item, FCTouchInfo touchInfo) {
            FCNative native = Native;
            ArrayList<FCMenuItem> items = null;
            FCMenuItem parentItem = item.ParentItem;
            if (parentItem != null) {
                items = parentItem.getItems();
            }
            else {
                items = m_items;
            }
            //�ر��������
            bool close = closeMenus(items);
            if (item.getItems().size() > 0) {
                FCMenu dropDownMenu = item.DropDownMenu;
                //��ȡλ�úʹ�С
                if (dropDownMenu != null) {
                    dropDownMenu.Native = native;
                    FCLayoutStyle layoutStyle = LayoutStyle;
                    FCPoint location = new FCPoint(native.clientX(item) + item.Width, native.clientY(item));
                    if (layoutStyle == FCLayoutStyle.LeftToRight || layoutStyle == FCLayoutStyle.RightToLeft) {
                        location.x = native.clientX(item);
                        location.y = native.clientY(item) + item.Height;
                    }
                    //���õ���λ��
                    dropDownMenu.Opacity = Opacity;
                    dropDownMenu.Location = location;
                    dropDownMenu.bringToFront();
                    dropDownMenu.focus();
                    dropDownMenu.show();
                    adjust(dropDownMenu);
                }
            }
            native.invalidate();
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            bool close = closeMenus(m_items);
            Native.invalidate();
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID) {
            base.onTimer(timerID);
            if (m_timerID == timerID) {
                if (m_autoHide && m_parentItem == null && Visible) {
                    if (!checkFocused(this) && !checkDivFocused(m_items) && onAutoHide()) {
                        bool close = closeMenus(m_items);
                        if (m_popup) {
                            hide();
                        }
                        else {
                            Native.invalidate();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// �ɼ�״̬�ı䷽��
        /// </summary>
        public override void onVisibleChanged() {
            base.onVisibleChanged();
            if (Visible) {
                if (m_popup) {
                    FCHScrollBar hScrollBar = HScrollBar;
                    FCVScrollBar vScrollBar = VScrollBar;
                    if (hScrollBar != null) {
                        hScrollBar.Pos = 0;
                    }
                    if (vScrollBar != null) {
                        vScrollBar.Pos = 0;
                    }
                    focus();
                    //������ʾλ��
                    adjust(this);
                }
                startTimer(m_timerID, 10);
            }
            else {
                stopTimer(m_timerID);
                bool close = closeMenus(m_items);
                FCNative native = Native;
                if (native != null) {
                    native.invalidate();
                }
            }
        }

        /// <summary>
        /// �Ƴ��˵���
        /// </summary>
        /// <param name="item">�˵���</param>
        public void removeItem(FCMenuItem item) {
            item.onRemovingItem();
            m_items.remove(item);
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "popup") {
                Popup = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
