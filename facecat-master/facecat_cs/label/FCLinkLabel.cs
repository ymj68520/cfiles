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
    /// �����ӿؼ���Ϊ
    /// </summary>
    public enum FCLinkBehavior {
        /// <summary>
        /// ������ʾ�»���
        /// </summary>
        AlwaysUnderLine,
        /// <summary>
        /// ������ͣʱ��ʾ�»���
        /// </summary>
        HoverUnderLine,
        /// <summary>
        /// ���ǲ���ʾ�»���
        /// </summary>
        NeverUnderLine
    }

    /// <summary>
    /// �����ӿؼ�
    /// </summary>
    public partial class FCLinkLabel : FCLabel {
        /// <summary>
        /// ���������ӿؼ�
        /// </summary>
        public FCLinkLabel() {
            Cursor = FCCursors.Hand;
        }

        /// <summary>
        /// �Ƿ��ѷ���
        /// </summary>
        protected bool m_visited = false;

        protected long m_activeLinkColor = FCColor.argb(255, 0, 0);

        /// <summary>
        /// ��ȡ�����õ���������ʱ����ɫ
        /// </summary>
        public virtual long ActiveLinkColor {
            get { return m_activeLinkColor; }
            set { m_activeLinkColor = value; }
        }

        protected long m_disabledLinkColor = FCColor.argb(133, 133, 133);

        /// <summary>
        /// ��ȡ�����ó����ӱ�����ʱ����ɫ
        /// </summary>
        public virtual long DisabledLinkColor {
            get { return m_disabledLinkColor; }
            set { m_disabledLinkColor = value; }
        }

        protected FCLinkBehavior m_linkBehavior = FCLinkBehavior.AlwaysUnderLine;

        /// <summary>
        /// ��ȡ�������»��ߵ���ʾ��ʽ
        /// </summary>
        public virtual FCLinkBehavior LinkBehavior {
            get { return m_linkBehavior; }
            set { m_linkBehavior = value; }
        }

        protected long m_linkColor = FCColor.argb(0, 0, 255);

        /// <summary>
        /// ��ȡ�����ó����Ӵ���Ĭ��ʱ����ɫ
        /// </summary>
        public virtual long LinkColor {
            get { return m_linkColor; }
            set { m_linkColor = value; }
        }

        protected bool m_linkVisited = false;

        /// <summary>
        /// ��ȡ�������Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
        /// </summary>
        public virtual bool LinkVisited {
            get { return m_linkVisited; }
            set { m_linkVisited = value; }
        }

        protected long m_visitedLinkColor = FCColor.argb(128, 0, 128);

        /// <summary>
        /// ��ȡ�ѷ��ʵĳ����ӵ���ɫ
        /// </summary>
        public virtual long VisitedLinkColor {
            get { return m_visitedLinkColor; }
            set { m_visitedLinkColor = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "LinkLabel";
        }

        /// <summary>
        /// ��ȡҪ���Ƶĳ�������ɫ
        /// </summary>
        /// <returns>ǰ��ɫ</returns>
        protected virtual long getPaintingLinkColor() {
            if (Enabled) {
                FCNative native = Native;
                if (this == native.HoveredControl) {
                    return m_activeLinkColor;
                }
                else if (this == native.PushedControl) {
                    return m_activeLinkColor;
                }
                else {
                    if (m_linkVisited && m_visited) {
                        return m_visitedLinkColor;
                    }
                    else {
                        return m_linkColor;
                    }
                }
            }
            else {
                return m_disabledLinkColor;
            }
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "activelinkcolor") {
                type = "color";
                value = FCStr.convertColorToStr(ActiveLinkColor);
            }
            else if (name == "disabledlinkcolor") {
                type = "color";
                value = FCStr.convertColorToStr(DisabledLinkColor);
            }
            else if (name == "linkbehavior") {
                type = "enum:FCLinkBehavior";
                FCLinkBehavior linkBehavior = LinkBehavior;
                if (linkBehavior == FCLinkBehavior.AlwaysUnderLine) {
                    value = "AlwaysUnderLine";
                }
                else if (linkBehavior == FCLinkBehavior.HoverUnderLine) {
                    value = "HoverUnderLine";
                }
                else {
                    value = "NeverUnderLine";
                }
            }
            else if (name == "linkcolor") {
                type = "color";
                value = FCStr.convertColorToStr(LinkColor);
            }
            else if (name == "linkvisited") {
                type = "bool";
                value = FCStr.convertBoolToStr(LinkVisited);
            }
            else if (name == "visitedlinkcolor") {
                type = "color";
                value = FCStr.convertColorToStr(VisitedLinkColor);
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
            propertyNames.AddRange(new String[] { "ActiveLinkColor", "DisabledLinkColor", "LinkBehavior", "LinkColor", "LinkVisited", "VisitedLinkColor" });
            return propertyNames;
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            base.onClick(touchInfo);
            if (m_linkVisited) {
                m_visited = true;
            }
        }

        /// <summary>
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            invalidate();
        }

        /// <summary>
        /// �������뷽��
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchEnter(FCTouchInfo touchInfo) {
            base.onTouchEnter(touchInfo);
            invalidate();
        }

        /// <summary>
        /// �����뿪����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchLeave(FCTouchInfo touchInfo) {
            base.onTouchLeave(touchInfo);
            invalidate();
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInfo) {
            base.onTouchUp(touchInfo);
            invalidate();
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            String text = Text;
            //��������
            if (text != null && text.Length > 0) {
                int width = Width, height = Height;
                if (width > 0 && height > 0) {
                    FCFont font = Font;
                    FCSize tSize = paint.textSize(text, font);
                    long linkColor = getPaintingLinkColor();
                    FCPoint tPoint = new FCPoint((width - tSize.cx) / 2, (height - tSize.cy) / 2);
                    FCPadding padding = Padding;
                    switch (m_textAlign) {
                        case FCContentAlignment.BottomCenter:
                            tPoint.y = height - tSize.cy;
                            break;
                        case FCContentAlignment.BottomLeft:
                            tPoint.x = padding.left;
                            tPoint.y = height - tSize.cy - padding.bottom;
                            break;
                        case FCContentAlignment.BottomRight:
                            tPoint.x = width - tSize.cx - padding.right;
                            tPoint.y = height - tSize.cy - padding.bottom;
                            break;
                        case FCContentAlignment.MiddleLeft:
                            tPoint.x = padding.left;
                            break;
                        case FCContentAlignment.MiddleRight:
                            tPoint.x = width - tSize.cx - padding.right;
                            break;
                        case FCContentAlignment.TopCenter:
                            tPoint.y = padding.top;
                            break;
                        case FCContentAlignment.TopLeft:
                            tPoint.x = padding.left;
                            tPoint.y = padding.top;
                            break;
                        case FCContentAlignment.TopRight:
                            tPoint.x = width - tSize.cx - padding.right;
                            tPoint.y = padding.top;
                            break;
                    }
                    FCRect tRect = new FCRect(tPoint.x, tPoint.y, tPoint.x + tSize.cx, tPoint.y + tSize.cy);
                    if (AutoEllipsis && (tRect.right > clipRect.right || tRect.bottom > clipRect.bottom)) {
                        if (tRect.right > clipRect.right) {
                            tRect.right = clipRect.right;
                        }
                        if (tRect.bottom > clipRect.bottom) {
                            tRect.bottom = clipRect.bottom;
                        }
                        paint.drawTextAutoEllipsis(text, linkColor, font, tRect);
                    }
                    else {
                        paint.drawText(text, linkColor, font, tRect);
                    }
                    //���»���
                    FCNative native = Native;
                    if (m_linkBehavior == FCLinkBehavior.AlwaysUnderLine || (m_linkBehavior == FCLinkBehavior.HoverUnderLine && (this == native.PushedControl || this == native.HoveredControl))) {
                        paint.drawLine(linkColor, 1, 0, tPoint.x, tPoint.y + tSize.cy, tPoint.x + tSize.cx, tPoint.y + tSize.cy);
                    }
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "activelinkcolor") {
                ActiveLinkColor = FCStr.convertStrToColor(value);
            }
            else if (name == "disabledlinkcolor") {
                DisabledLinkColor = FCStr.convertStrToColor(value);
            }
            else if (name == "linkbehavior") {
                value = value.ToLower();
                if (value == "alwaysunderline") {
                    LinkBehavior = FCLinkBehavior.AlwaysUnderLine;
                }
                else if (value == "hoverunderline") {
                    LinkBehavior = FCLinkBehavior.HoverUnderLine;
                }
                else {
                    LinkBehavior = FCLinkBehavior.NeverUnderLine;
                }
            }
            else if (name == "linkcolor") {
                LinkColor = FCStr.convertStrToColor(value);
            }
            else if (name == "linkvisited") {
                LinkVisited = FCStr.convertStrToBool(value);
            }
            else if (name == "visitedlinkcolor") {
                VisitedLinkColor = FCStr.convertStrToColor(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
