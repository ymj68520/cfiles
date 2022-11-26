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
    /// ��ť�ؼ�
    /// </summary>
    public class FCButton : FCView {
        /// <summary>
        /// ������ť
        /// </summary>
        public FCButton() {
            FCSize size = new FCSize(60, 20);
            Size = size;
        }

        protected String m_disabledBackImage;

        /// <summary>
        /// ��ȡ�����ò�����ʱ�ı���ͼƬ
        /// </summary>
        public virtual String DisabledBackImage {
            get { return m_disabledBackImage; }
            set { m_disabledBackImage = value; }
        }

        protected String m_hoveredBackImage;

        /// <summary>
        /// ��ȡ�����ô�����ͣʱ�ı���ͼƬ
        /// </summary>
        public virtual String HoveredBackImage {
            get { return m_hoveredBackImage; }
            set { m_hoveredBackImage = value; }
        }

        private String m_pushedBackImage;

        /// <summary>
        /// ��ȡ�����ô�������ʱ�ı���ͼƬ
        /// </summary>
        public virtual String PushedBackImage {
            get { return m_pushedBackImage; }
            set { m_pushedBackImage = value; }
        }

        protected FCContentAlignment m_textAlign = FCContentAlignment.MiddleCenter;

        /// <summary>
        /// ��ȡ���������ֵĲ��ַ�ʽ
        /// </summary>
        public virtual FCContentAlignment TextAlign {
            get { return m_textAlign; }
            set { m_textAlign = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "Button";
        }

        /// <summary>
        /// ��ȡҪ���Ƶı���ɫ
        /// </summary>
        /// <returns>����ɫ</returns>
        protected override long getPaintingBackColor() {
            long backColor = base.getPaintingBackColor();
            if (backColor != FCColor.None && isPaintEnabled(this)) {
                FCNative native = Native;
                if (this == native.PushedControl) {
                    backColor = FCColor.Pushed;
                }
                else if (this == native.HoveredControl) {
                    backColor = FCColor.Hovered;
                }
            }
            return backColor;
        }

        /// <summary>
        /// ��ȡ���ڻ��Ƶı���ͼƬ
        /// </summary>
        protected override String getPaintingBackImage() {
            String backImage = null;
            if (isPaintEnabled(this)) {
                FCNative native = Native;
                if (this == native.PushedControl) {
                    backImage = m_pushedBackImage;
                }
                else if (this == native.HoveredControl) {
                    backImage = m_hoveredBackImage;
                }
            }
            else {
                backImage = m_disabledBackImage;
            }
            if (backImage != null) {
                return backImage;
            }
            else {
                return base.getPaintingBackImage();
            }
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "disabledbackimage") {
                type = "text";
                value = DisabledBackImage;
            }
            else if (name == "hoveredbackimage") {
                type = "text";
                value = HoveredBackImage;
            }
            else if (name == "pushedbackimage") {
                type = "text";
                value = PushedBackImage;
            }
            else if (name == "textalign") {
                type = "enum:FCContentAlignment";
                value = FCStr.convertContentAlignmentToStr(TextAlign);
            }
            else {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "DisabledBackImage", "HoveredBackImage", "PushedBackImage", "TextAlign" });
            return propertyNames;
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
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
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
                    long textColor = getPaintingTextColor();
                    if (AutoEllipsis && (tRect.right > clipRect.right || tRect.bottom > clipRect.bottom)) {
                        if (tRect.right > clipRect.right) {
                            tRect.right = clipRect.right;
                        }
                        if (tRect.bottom > clipRect.bottom) {
                            tRect.bottom = clipRect.bottom;
                        }
                        paint.drawTextAutoEllipsis(text, textColor, font, tRect);
                    }
                    else {
                        paint.drawText(text, textColor, font, tRect);
                    }
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "disabledbackimage") {
                DisabledBackImage = value;
            }
            else if (name == "hoveredbackimage") {
                HoveredBackImage = value;
            }
            else if (name == "pushedbackimage") {
                PushedBackImage = value;
            }
            else if (name == "textalign") {
                TextAlign = FCStr.convertStrToContentAlignment(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
