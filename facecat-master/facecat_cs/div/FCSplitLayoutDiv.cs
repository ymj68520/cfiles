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
    /// �ָ�ֿؼ�
    /// </summary>
    public class FCSplitLayoutDiv : FCLayoutDiv {
        /// <summary>
        /// �����ָ�ֿؼ�
        /// </summary>
        public FCSplitLayoutDiv() {
            m_splitterDraggingEvent = new FCEvent(SplitterDragging);
        }

        /// <summary>
        /// �ָ�ٷֱ�
        /// </summary>
        protected float m_splitPercent = -1;

        protected FCEvent m_splitterDraggingEvent;

        protected FCView m_firstControl;

        /// <summary>
        /// ��ȡ�����õ�һ���ؼ�
        /// </summary>
        public virtual FCView FirstControl {
            get { return m_firstControl; }
            set { m_firstControl = value; }
        }

        protected FCView m_secondControl;

        /// <summary>
        /// ��ȡ�����õڶ����ؼ�
        /// </summary>
        public virtual FCView SecondControl {
            get { return m_secondControl; }
            set { m_secondControl = value; }
        }

        protected FCSizeType m_splitMode = FCSizeType.AbsoluteSize;

        /// <summary>
        /// ��ȡ�����÷ָ�ģʽ
        /// </summary>
        public virtual FCSizeType SplitMode {
            get { return m_splitMode; }
            set { m_splitMode = value; }
        }

        protected FCButton m_splitter;

        /// <summary>
        /// ��ȡ�ָť
        /// </summary>
        public virtual FCButton Splitter {
            get { return m_splitter; }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_splitterDraggingEvent != null) {
                    if (m_splitter != null) {
                        m_splitter.removeEvent(m_splitterDraggingEvent, FCEventID.DRAGGING);
                        m_splitterDraggingEvent = null;
                    }
                }
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "SplitLayoutDiv";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "candragsplitter") {
                type = "bool";
                if (m_splitter != null) {
                    value = FCStr.convertBoolToStr(m_splitter.AllowDrag);
                }
                else {
                    value = "False";
                }
            }
            else if (name == "splitmode") {
                type = "enum:FCSizeType";
                if (SplitMode == FCSizeType.AbsoluteSize) {
                    value = "AbsoluteSize";
                }
                else {
                    value = "PercentSize";
                }
            }
            else if (name.IndexOf("splitter-") != -1) {
                if (m_splitter != null) {
                    m_splitter.getProperty(name.Substring(9), ref value, ref type);
                }
            }
            else if (name == "splitterposition") {
                type = "str";
                if (m_splitter != null) {
                    if (m_layoutStyle == FCLayoutStyle.TopToBottom || m_layoutStyle == FCLayoutStyle.BottomToTop) {
                        value = FCStr.convertIntToStr(m_splitter.Top);
                        if (m_splitter.Height > 0) {
                            value = value + "," + FCStr.convertIntToStr(m_splitter.Height);
                        }
                    } else {
                        value = FCStr.convertIntToStr(m_splitter.Left);
                        if (m_splitter.Width > 0) {
                            value = value + "," + FCStr.convertIntToStr(m_splitter.Width);
                        }
                    }
                }
            }
            else if (name == "splittervisible") {
                type = "bool";
                if (m_splitter != null) {
                    value = FCStr.convertBoolToStr(m_splitter.Visible);
                }
                else {
                    value = "False";
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
            propertyNames.AddRange(new String[] { "CanDragSplitter", "SplitMode", "Splitter", "SplitterPosition", "SplitterVisible" });
            return propertyNames;
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            if (m_splitter == null) {
                FCHost host = Native.Host;
                m_splitter = host.createInternalControl(this, "splitter") as FCButton;
                m_splitter.addEvent(m_splitterDraggingEvent, FCEventID.DRAGGING);
                addControl(m_splitter);
            }
            m_oldSize = Size;
        }

        /// <summary>
        /// ���ò���
        /// </summary>
        /// <returns></returns>
        public override bool onResetLayout() {
            bool reset = false;
            if (Native != null && m_splitter != null && m_firstControl != null && m_secondControl != null) {
                FCRect splitRect = new FCRect();
                int width = Width, height = Height;
                FCRect fRect = new FCRect();
                FCRect sRect = new FCRect();
                FCSize splitterSize = new FCSize(0, 0);
                if (m_splitter.Visible) {
                    splitterSize.cx = m_splitter.Width;
                    splitterSize.cy = m_splitter.Height;
                }
                FCLayoutStyle layoutStyle = LayoutStyle;
                switch (layoutStyle) {
                    //���¶���
                    case FCLayoutStyle.BottomToTop:
                        //���Դ�С
                        if (m_splitMode == FCSizeType.AbsoluteSize || m_oldSize.cy == 0) {
                            splitRect.left = 0;
                            splitRect.top = height - (m_oldSize.cy - m_splitter.Top);
                            splitRect.right = width;
                            splitRect.bottom = splitRect.top + splitterSize.cy;
                        }
                        //�ٷֱȴ�С
                        else if (m_splitMode == FCSizeType.PercentSize) {
                            splitRect.left = 0;
                            if (m_splitPercent == -1) {
                                m_splitPercent = (float)m_splitter.Top / m_oldSize.cy;
                            }
                            splitRect.top = (int)(height * m_splitPercent);
                            splitRect.right = width;
                            splitRect.bottom = splitRect.top + splitterSize.cy;
                        }
                        fRect.left = 0;
                        fRect.top = splitRect.bottom;
                        fRect.right = width;
                        fRect.bottom = height;
                        sRect.left = 0;
                        sRect.top = 0;
                        sRect.right = width;
                        sRect.bottom = splitRect.top;
                        break;
                    //��������
                    case FCLayoutStyle.LeftToRight:
                        //���Դ�С
                        if (m_splitMode == FCSizeType.AbsoluteSize || m_oldSize.cx == 0) {
                            splitRect.left = m_splitter.Left;
                            splitRect.top = 0;
                            splitRect.right = m_splitter.Left + splitterSize.cx;
                            splitRect.bottom = height;
                        }
                        //�ٷֱȴ�С
                        else if (m_splitMode == FCSizeType.PercentSize) {
                            if (m_splitPercent == -1) {
                                m_splitPercent = (float)m_splitter.Left / m_oldSize.cx;
                            }
                            splitRect.left = (int)(width * m_splitPercent);
                            splitRect.top = 0;
                            splitRect.right = splitRect.left + splitterSize.cx;
                            splitRect.bottom = height;
                        }
                        fRect.left = 0;
                        fRect.top = 0;
                        fRect.right = splitRect.left;
                        fRect.bottom = height;
                        sRect.left = splitRect.right;
                        sRect.top = 0;
                        sRect.right = width;
                        sRect.bottom = height;
                        break;
                    //��������
                    case FCLayoutStyle.RightToLeft:
                        //���Դ�С
                        if (m_splitMode == FCSizeType.AbsoluteSize || m_oldSize.cx == 0) {
                            splitRect.left = width - (m_oldSize.cx - m_splitter.Left);
                            splitRect.top = 0;
                            splitRect.right = splitRect.left + splitterSize.cx;
                            splitRect.bottom = height;
                        }
                        //�ٷֱȴ�С
                        else if (m_splitMode == FCSizeType.PercentSize) {
                            if (m_splitPercent == -1) {
                                m_splitPercent = (float)m_splitter.Left / m_oldSize.cx;
                            }
                            splitRect.left = (int)(width * m_splitPercent);
                            splitRect.top = 0;
                            splitRect.right = splitRect.left + splitterSize.cx;
                            splitRect.bottom = height;
                        }
                        fRect.left = splitRect.right;
                        fRect.top = 0;
                        fRect.right = width;
                        fRect.bottom = height;
                        sRect.left = 0;
                        sRect.top = 0;
                        sRect.right = splitRect.left;
                        sRect.bottom = height;
                        break;
                    //���϶���
                    case FCLayoutStyle.TopToBottom:
                        //���Դ�С
                        if (m_splitMode == FCSizeType.AbsoluteSize || m_oldSize.cy == 0) {
                            splitRect.left = 0;
                            splitRect.top = m_splitter.Top;
                            splitRect.right = width;
                            splitRect.bottom = splitRect.top + splitterSize.cy;
                        }
                        //�ٷֱȴ�С
                        else if (m_splitMode == FCSizeType.PercentSize) {
                            splitRect.left = 0;
                            if (m_splitPercent == -1) {
                                m_splitPercent = (float)m_splitter.Top / m_oldSize.cy;
                            }
                            splitRect.top = (int)(height * m_splitPercent);
                            splitRect.right = width;
                            splitRect.bottom = splitRect.top + splitterSize.cy;
                        }
                        fRect.left = 0;
                        fRect.top = 0;
                        fRect.right = width;
                        fRect.bottom = splitRect.top;
                        sRect.left = 0;
                        sRect.top = splitRect.bottom;
                        sRect.right = width;
                        sRect.bottom = height;
                        break;
                }
                if (m_splitter.Visible) {
                    FCRect spRect = m_splitter.Bounds;
                    if (spRect.left != splitRect.left || spRect.top != splitRect.top || spRect.right != splitRect.right || spRect.bottom != splitRect.bottom) {
                        m_splitter.Bounds = splitRect;
                        reset = true;
                    }
                    if (m_splitter.AllowDrag) {
                        if (layoutStyle == FCLayoutStyle.LeftToRight || layoutStyle == FCLayoutStyle.RightToLeft) {
                            m_splitter.Cursor = FCCursors.SizeWE;
                        }
                        else {
                            m_splitter.Cursor = FCCursors.SizeNS;
                        }
                        m_splitter.bringToFront();
                    }
                }
                FCRect fcRect = m_firstControl.Bounds;
                if (fcRect.left != fRect.left || fcRect.top != fRect.top || fcRect.right != fRect.right || fcRect.bottom != fRect.bottom) {
                    reset = true;
                    m_firstControl.Bounds = fRect;
                    m_firstControl.update();
                }
                FCRect scRect = m_secondControl.Bounds;
                if (scRect.left != sRect.left || scRect.top != sRect.top || scRect.right != sRect.right || scRect.bottom != sRect.bottom) {
                    reset = true;
                    m_secondControl.Bounds = sRect;
                    m_secondControl.update();
                }
            }
            m_oldSize = Size;
            return reset;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "candragsplitter") {
                if (m_splitter != null) {
                    m_splitter.AllowDrag = FCStr.convertStrToBool(value);
                }
            }
            else if (name == "splitmode") {
                value = value.ToLower();
                if (value == "absolutesize") {
                    SplitMode = FCSizeType.AbsoluteSize;
                }
                else {
                    SplitMode = FCSizeType.PercentSize;
                }
            }
            else if (name.IndexOf("splitter-") != -1) {
                if (m_splitter != null) {
                    m_splitter.setProperty(name.Substring(9), value);
                }
            }
            else if (name == "splitterposition") {
                if (m_splitter != null) {
                    String[] strs = value.Split(new String[] { "," }, StringSplitOptions.RemoveEmptyEntries);
                    if (strs.Length == 4) {
                        m_splitter.Bounds = FCStr.convertStrToRect(value);
                    } else if (strs.Length <= 2) {
                        int pos = FCStr.convertStrToInt(strs[0]);
                        int lWidth = 0;
                        if (strs.Length == 2) {
                            lWidth = FCStr.convertStrToInt(strs[1]);
                        }
                        int width = Width, height = Height;
                        if (m_layoutStyle == FCLayoutStyle.TopToBottom || m_layoutStyle == FCLayoutStyle.BottomToTop) {
                            m_splitter.Bounds = new FCRect(0, pos, width, pos + lWidth);
                        } else {
                            m_splitter.Bounds = new FCRect(pos, 0, pos + lWidth, height);
                        }
                    }
                }
            }
            else if (name == "splittervisible") {
                if (m_splitter != null) {
                    m_splitter.Visible = FCStr.convertStrToBool(value);
                }
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// �϶�������
        /// </summary>
        /// <param name="sender">�ؼ�</param>
        public void SplitterDragging(object sender) {
            m_splitPercent = -1;
            update();
            invalidate();
        }

        /// <summary>
        /// ���ָ��·���
        /// </summary>
        public override void update() {
            onResetLayout();
            int controlsSize = m_controls.size();
            for (int i = 0; i < controlsSize; i++) {
                m_controls.get(i).update();
            }
        }
    }
}
