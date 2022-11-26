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
    /// ���ֿؼ�
    /// </summary>
    public class FCLayoutDiv : FCDiv {
        /// <summary>
        /// �������ֿؼ�
        /// </summary>
        public FCLayoutDiv() {
        }

        protected bool m_autoWrap = false;

        /// <summary>
        /// ��ȡ�������Ƿ��Զ�����
        /// </summary>
        public virtual bool AutoWrap {
            get { return m_autoWrap; }
            set { m_autoWrap = value; }
        }

        protected FCLayoutStyle m_layoutStyle = FCLayoutStyle.LeftToRight;

        /// <summary>
        /// ��ȡ����������ģʽ
        /// </summary>
        public virtual FCLayoutStyle LayoutStyle {
            get { return m_layoutStyle; }
            set { m_layoutStyle = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "LayoutDiv";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "autowrap") {
                type = "bool";
                value = FCStr.convertBoolToStr(AutoWrap);
            }
            else if (name == "layoutstyle") {
                type = "enum:FCLayoutStyle";
                value = FCStr.convertLayoutStyleToStr(LayoutStyle);
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
            propertyNames.AddRange(new String[] { "AutoWrap", "LayoutStyle" });
            return propertyNames;
        }

        /// <summary>
        /// ���ò���
        /// </summary>
        public virtual bool onResetLayout() {
            bool reset = false;
            if (Native != null) {
                FCPadding padding = Padding;
                int left = padding.left, top = padding.top;
                int width = Width - padding.left - padding.right;
                int height = Height - padding.top - padding.bottom;
                int controlSize = m_controls.size();
                for (int i = 0; i < controlSize; i++) {
                    FCView control = m_controls.get(i);
                    if (control.Visible && control != HScrollBar && control != VScrollBar) {
                        FCSize size = control.Size;
                        int cLeft = control.Left, cTop = control.Top, cWidth = size.cx, cHeight = size.cy;
                        int nLeft = cLeft, nTop = cTop, nWidth = cWidth, nHeight = cHeight;
                        FCPadding margin = control.Margin;
                        switch (m_layoutStyle) {
                            //���¶���
                            case FCLayoutStyle.BottomToTop: {
                                    if (i == 0) {
                                        top = padding.top + height;
                                    }
                                    int lWidth = 0;
                                    if (m_autoWrap) {
                                        lWidth = size.cx;
                                        int lTop = top - margin.top - cHeight - margin.bottom;
                                        if (lTop < padding.top) {
                                            left += cWidth + margin.left;
                                            top = height - padding.top;
                                        }
                                    }
                                    else {
                                        lWidth = width - margin.left - margin.right;
                                    }
                                    top -= cHeight + margin.bottom;
                                    nLeft = left + margin.left;
                                    nWidth = lWidth;
                                    nTop = top;
                                    break;
                                }
                            //��������
                            case FCLayoutStyle.LeftToRight: {
                                    int lHeight = 0;
                                    if (m_autoWrap) {
                                        lHeight = size.cy;
                                        int lRight = left + margin.left + cWidth + margin.right;
                                        if (lRight > width) {
                                            left = padding.left;
                                            top += cHeight + margin.top;
                                        }
                                    }
                                    else {
                                        lHeight = height - margin.top - margin.bottom;
                                    }
                                    left += margin.left;
                                    nLeft = left;
                                    nTop = top + margin.top;
                                    nHeight = lHeight;
                                    left += cWidth + margin.right;
                                    break;
                                }
                            //��������
                            case FCLayoutStyle.RightToLeft: {
                                    if (i == 0) {
                                        left = width - padding.left;
                                    }
                                    int lHeight = 0;
                                    if (m_autoWrap) {
                                        lHeight = size.cy;
                                        int lLeft = left - margin.left - cWidth - margin.right;
                                        if (lLeft < padding.left) {
                                            left = width - padding.left;
                                            top += cHeight + margin.top;
                                        }
                                    }
                                    else {
                                        lHeight = height - margin.top - margin.bottom;
                                    }
                                    left -= cWidth + margin.left;
                                    nLeft = left;
                                    nTop = top + margin.top;
                                    nHeight = lHeight;
                                    break;
                                }
                            //���϶���
                            case FCLayoutStyle.TopToBottom: {
                                    int lWidth = 0;
                                    if (m_autoWrap) {
                                        lWidth = size.cx;
                                        int lBottom = top + margin.top + cHeight + margin.bottom;
                                        if (lBottom > height) {
                                            left += cWidth + margin.left + margin.right;
                                            top = padding.top;
                                        }
                                    }
                                    else {
                                        lWidth = width - margin.left - margin.right;
                                    }
                                    top += margin.top;
                                    nTop = top;
                                    nLeft = left + margin.left;
                                    nWidth = lWidth;
                                    top += cHeight + margin.bottom;
                                    break;
                                }
                        }
                        //��������
                        if (cLeft != nLeft || cTop != nTop || cWidth != nWidth || cHeight != nHeight) {
                            FCRect rect = new FCRect(nLeft, nTop, nLeft + nWidth, nTop + nHeight);
                            control.Bounds = rect;
                            reset = true;
                        }
                    }
                }
            }
            return reset;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "autowrap") {
                AutoWrap = FCStr.convertStrToBool(value);
            }
            else if (name == "layoutstyle") {
                LayoutStyle = FCStr.convertStrToLayoutStyle(value);
            }
            else {
                base.setProperty(name, value);
            }
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
            updateScrollBar();
        }
    }
}
