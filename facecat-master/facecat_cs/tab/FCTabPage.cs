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
    /// ��ҳ�пؼ�
    /// </summary>
    public class FCTabPage : FCDiv {
        /// <summary>
        /// ������ҳ��
        /// </summary>
        public FCTabPage() {
            m_dragHeaderBeginEvent = new FCEvent(DragHeaderBegin);
            m_dragHeaderEndEvent = new FCEvent(DragHeaderEnd);
            m_draggingHeaderEvent = new FCEvent(DraggingHeader);
            m_headerTouchDownEvent = new FCTouchEvent(HeaderTouchDown);
        }

        /// <summary>
        /// ��ʼ�϶�ҳͷ��ť�¼�
        /// </summary>
        private FCEvent m_dragHeaderBeginEvent;

        /// <summary>
        /// �����϶�ҳͷ��ť�¼�
        /// </summary>
        private FCEvent m_dragHeaderEndEvent;

        /// <summary>
        /// ҳͷ��ť�϶����¼�
        /// </summary>
        private FCEvent m_draggingHeaderEvent;

        /// <summary>
        /// ҳͷ�Ĵ��������¼�
        /// </summary>
        private FCTouchEvent m_headerTouchDownEvent;

        protected FCButton m_headerButton;

        /// <summary>
        /// ��ȡ������ҳͷ��ť
        /// </summary>
        public virtual FCButton HeaderButton {
            get { return m_headerButton; }
            set { m_headerButton = value; }
        }

        protected FCPoint m_headerLocation;

        /// <summary>
        /// ��ȡ������ͷ����λ��
        /// </summary>
        public virtual FCPoint HeaderLocation {
            get { return m_headerLocation; }
            set { m_headerLocation = value; }
        }

        /// <summary>
        /// ��ȡ������ͷ���Ƿ�ɼ�
        /// </summary>
        public virtual bool HeaderVisible {
            get {
                if (m_headerButton != null) {
                    return m_headerButton.Visible;
                }
                else {
                    return false;
                }
            }
            set {
                if (m_headerButton != null) {
                    m_headerButton.Visible = value;
                }
            }
        }

        protected FCTabControl m_tabControl;

        /// <summary>
        /// ��ȡ�����ö�ҳ�пؼ�
        /// </summary>
        public virtual FCTabControl TabControl {
            get { return m_tabControl; }
            set { m_tabControl = value; }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_dragHeaderBeginEvent != null) {
                    if (m_headerButton != null) {
                        m_headerButton.removeEvent(m_dragHeaderBeginEvent, FCEventID.DRAGBEGIN);
                    }
                    m_dragHeaderBeginEvent = null;
                }
                if (m_dragHeaderEndEvent != null) {
                    if (m_headerButton != null) {
                        m_headerButton.removeEvent(m_dragHeaderEndEvent, FCEventID.DRAGEND);
                    }
                    m_dragHeaderEndEvent = null;
                }
                if (m_draggingHeaderEvent != null) {
                    if (m_headerButton != null) {
                        m_headerButton.removeEvent(m_draggingHeaderEvent, FCEventID.DRAGGING);
                    }
                    m_draggingHeaderEvent = null;
                }
                if (m_headerTouchDownEvent != null) {
                    if (m_headerButton != null) {
                        m_headerButton.removeEvent(m_headerTouchDownEvent, FCEventID.TOUCHDOWN);
                    }
                    m_headerTouchDownEvent = null;
                }
                m_headerButton = null;
            }
            base.delete();
        }

        /// <summary>
        /// ��ʼ�϶�ҳͷ��ť����
        /// </summary>
        /// <param name="sender">������</param>
        protected void DragHeaderBegin(object sender) {
            if (m_tabControl != null) {
                m_tabControl.onDragTabHeaderBegin(this);
            }
        }

        /// <summary>
        /// �����϶�ҳͷ��ť����
        /// </summary>
        /// <param name="sender">������</param>
        protected void DragHeaderEnd(object sender) {
            if (m_tabControl != null) {
                m_tabControl.onDragTabHeaderEnd(this);
            }
        }

        /// <summary>
        /// ҳͷ��ť�϶��з���
        /// </summary>
        /// <param name="sender">������</param>
        protected void DraggingHeader(object sender) {
            if (m_tabControl != null) {
                m_tabControl.onDraggingTabHeader(this);
            }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "TabPage";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "headersize") {
                type = "size";
                if (m_headerButton != null) {
                    value = FCStr.convertSizeToStr(m_headerButton.Size);
                }
                else {
                    value = "0,0";
                }
            }
            else if (name == "headervisible") {
                type = "bool";
                value = FCStr.convertBoolToStr(HeaderVisible);
            }
            else if (name.IndexOf("header-") != -1) {
                if (m_headerButton != null) {
                    m_headerButton.getProperty(name.Substring(7), ref value, ref type);
                }
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
            propertyNames.AddRange(new String[] { "Header", "HeaderSize", "HeaderVisible" });
            return propertyNames;
        }

        /// <summary>
        /// ҳͷ�������·���
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        protected void HeaderTouchDown(object sender, FCTouchInfo touchInfo) {
            if (m_tabControl != null) {
                m_tabControl.SelectedTabPage = this;
                m_tabControl.invalidate();
            }
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            if (m_tabControl != null) {
                if (m_headerButton == null) {
                    FCHost host = Native.Host;
                    m_headerButton = host.createInternalControl(this, "headerbutton") as FCButton;
                    m_headerButton.addEvent(m_dragHeaderBeginEvent, FCEventID.DRAGBEGIN);
                    m_headerButton.addEvent(m_dragHeaderEndEvent, FCEventID.DRAGEND);
                    m_headerButton.addEvent(m_draggingHeaderEvent, FCEventID.DRAGGING);
                    m_headerButton.addEvent(m_headerTouchDownEvent, FCEventID.TOUCHDOWN);
                }
                if (!m_tabControl.containsControl(m_headerButton)) {
                    m_tabControl.addControl(m_headerButton);
                }

            }
        }

        /// <summary>
        /// ���ָı䷽��
        /// </summary>
        public override void onTextChanged() {
            base.onTextChanged();
            if (m_headerButton != null) {
                m_headerButton.Text = Text;
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "headersize") {
                if (m_headerButton != null) {
                    m_headerButton.setProperty("size", value);
                }
            }
            else if (name == "headervisible") {
                HeaderVisible = FCStr.convertStrToBool(value);
            }
            else if (name.IndexOf("header-") != -1) {
                if (m_headerButton != null) {
                    m_headerButton.setProperty(name.Substring(7), value);
                }
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
