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
    /// �˵���
    /// </summary>
    public class FCMenuItem : FCButton {
        /// <summary>
        /// �����˵���
        /// </summary>
        public FCMenuItem() {
            Font = new FCFont("����", 12, false, false, false);
            Size = new FCSize(200, 25);
        }

        /// <summary>
        /// �����˵���
        /// </summary>
        /// <param name="text">����</param>
        public FCMenuItem(String text) {
            Font = new FCFont("����", 12, false, false, false);
            Size = new FCSize(200, 25);
            Text = text;
        }

        /// <summary>
        /// ���в˵���
        /// </summary>
        public ArrayList<FCMenuItem> m_items = new ArrayList<FCMenuItem>();

        protected bool m_checked = false;

        /// <summary>
        /// ��ȡ�������Ƿ�ѡ��
        /// </summary>
        public virtual bool Checked {
            get { return m_checked; }
            set { m_checked = value; }
        }

        protected FCMenu m_dropDownMenu;

        /// <summary>
        /// ��ȡ�������������
        /// </summary>
        public virtual FCMenu DropDownMenu {
            get { return m_dropDownMenu; }
            set { m_dropDownMenu = value; }
        }

        protected FCMenuItem m_parentItem;

        /// <summary>
        /// ��ȡ�����ø��˵���
        /// </summary>
        public virtual FCMenuItem ParentItem {
            get { return m_parentItem; }
            set { m_parentItem = value; }
        }

        protected FCMenu m_parentMenu;

        /// <summary>
        /// ��ȡ���������ڲ˵�
        /// </summary>
        public virtual FCMenu ParentMenu {
            get { return m_parentMenu; }
            set { m_parentMenu = value; }
        }

        protected String m_value;

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        public virtual String Value {
            get { return m_value; }
            set { m_value = value; }
        }

        /// <summary>
        /// ����Ӳ˵���
        /// </summary>
        /// <param name="item">�˵���</param>
        public void addItem(FCMenuItem item) {
            item.ParentItem = this;
            item.ParentMenu = ParentMenu;
            item.onAddingItem(-1);
            m_items.add(item);
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
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "MenuItem";
        }

        /// <summary>
        /// ��ȡ���е���
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
            if (name == "checked") {
                type = "bool";
                value = FCStr.convertBoolToStr(Checked);
            }
            else if (name == "value") {
                type = "String";
                value = Value;
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
            propertyNames.AddRange(new String[] { "Checked", "Value" });
            return propertyNames;
        }

        /// <summary>
        /// ������
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="item">�˵���</param>
        public void insertItem(int index, FCMenuItem item) {
            item.ParentItem = this;
            item.ParentMenu = ParentMenu;
            item.onAddingItem(index);
            m_items.Insert(index, item);
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="index">������</param>
        public virtual void onAddingItem(int index) {
            FCMenu dropDownMenu = null;
            if (m_parentItem != null) {
                dropDownMenu = m_parentItem.DropDownMenu;
                if (dropDownMenu == null) {
                    dropDownMenu = m_parentMenu.createDropDownMenu();
                    dropDownMenu.Visible = false;
                    m_parentItem.DropDownMenu = dropDownMenu;
                    dropDownMenu.ParentItem = m_parentItem;
                    m_parentMenu.Native.addControl(dropDownMenu);
                }
            }
            else {
                dropDownMenu = m_parentMenu;
            }
            if (dropDownMenu != null) {
                if (index != -1) {
                    //������
                    dropDownMenu.insertControl(index, this);
                }
                else {
                    //�����
                    dropDownMenu.addControl(this);
                }
                //����ӽڵ�
                int itemSize = m_items.size();
                for (int i = 0; i < itemSize; i++) {
                    m_items.get(i).onAddingItem(-1);
                }
            }
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            base.onClick(touchInfo);
            if (m_parentMenu != null) {
                m_parentMenu.onMenuItemClick(this, touchInfo);
            }
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
            if (m_parentMenu != null) {
                m_parentMenu.onMenuItemTouchMove(this, touchInfo);
            }
        }

        /// <summary>
        /// �ػ�ǰ������ 
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            int width = Width, height = Height;
            if (width > 0 && height > 0) {
                int right = width;
                int midY = height / 2;
                String text = Text;
                int tRight = 0;
                long textColor = getPaintingTextColor();
                if (text != null && text.Length > 0) {
                    FCFont font = Font;
                    FCSize tSize = paint.textSize(text, font);
                    FCRect tRect = new FCRect();
                    tRect.left = 10;
                    tRect.top = midY - tSize.cy / 2 + 2;
                    tRect.right = tRect.left + tSize.cx;
                    tRect.bottom = tRect.top + tSize.cy;
                    paint.drawText(text, textColor, font, tRect);
                    tRight = tRect.right + 4;
                }
                //����ѡ��
                if (m_checked) {
                    FCRect eRect = new FCRect(tRight, height / 2 - 4, tRight + 8, height / 2 + 4);
                    paint.fillEllipse(textColor, eRect);
                }
                //���Ӳ˵�����ʾ��ͷ
                if (m_items.size() > 0) {
                    FCPoint point1 = new FCPoint(), point2 = new FCPoint(), point3 = new FCPoint();
                    FCMenu menu = m_parentMenu;
                    if (m_parentItem != null) {
                        menu = m_parentItem.DropDownMenu;
                    }
                    FCLayoutStyle layoutStyle = menu.LayoutStyle;
                    //����
                    if (layoutStyle == FCLayoutStyle.LeftToRight || layoutStyle == FCLayoutStyle.RightToLeft) {
                        point1.x = right - 25;
                        point1.y = midY - 2;
                        point2.x = right - 14;
                        point2.y = midY - 2;
                        point3.x = right - 20;
                        point3.y = midY + 4;
                    }
                    //����
                    else {
                        point1.x = right - 15;
                        point1.y = midY;
                        point2.x = right - 25;
                        point2.y = midY - 5;
                        point3.x = right - 25;
                        point3.y = midY + 5;
                    }
                    FCPoint[] points = new FCPoint[] { point1, point2, point3 };
                    paint.fillPolygon(textColor, points);
                }
            }
        }

        /// <summary>
        /// �Ƴ����
        /// </summary>
        public virtual void onRemovingItem() {
            FCMenu dropDownMenu = null;
            if (m_parentItem != null) {
                dropDownMenu = m_parentItem.DropDownMenu;
            }
            else {
                dropDownMenu = m_parentMenu;
            }
            if (dropDownMenu != null) {
                if (m_items != null && m_items.size() > 0) {
                    int itemSize = m_items.size();
                    for (int i = 0; i < itemSize; i++) {
                        m_items.get(i).onRemovingItem();
                    }
                }
                dropDownMenu.removeControl(this);
            }
            if (m_dropDownMenu != null) {
                m_parentMenu.Native.removeControl(m_dropDownMenu);
                m_dropDownMenu.delete();
                m_dropDownMenu = null;
            }
        }

        /// <summary>
        /// �Ƴ��Ӳ˵���
        /// </summary>
        /// <param name="item">�Ӳ˵���</param>
        public void RemoveItem(FCMenuItem item) {
            item.onRemovingItem();
            m_items.remove(item);
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "checked") {
                Checked = FCStr.convertStrToBool(value);
            }
            else if (name == "value") {
                Value = value;
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
