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
    /// ��ѡ��ؼ�
    /// </summary>
    public class FCCheckBox : FCButton {
        /// <summary>
        /// ������ѡ��
        /// </summary>
        public FCCheckBox() {
            BackColor = FCColor.None;
            BorderColor = FCColor.None;
        }

        protected FCHorizontalAlign m_buttonAlign = FCHorizontalAlign.Left;

        /// <summary>
        /// ��ȡ���������ݵĺ���������ʽ
        /// </summary>
        public virtual FCHorizontalAlign ButtonAlign {
            get { return m_buttonAlign; }
            set { m_buttonAlign = value; }
        }

        protected long m_buttonBackColor = FCColor.Border;

        /// <summary>
        /// ��ȡ�����ð�ť�ı���ɫ
        /// </summary>
        public virtual long ButtonBackColor {
            get { return m_buttonBackColor; }
            set { m_buttonBackColor = value; }
        }

        protected long m_buttonBorderColor = FCColor.Border;

        /// <summary>
        /// ��ȡ�����ð�ť�ı�����ɫ
        /// </summary>
        public virtual long ButtonBorderColor {
            get { return m_buttonBorderColor; }
            set { m_buttonBorderColor = value; }
        }

        protected FCSize m_buttonSize = new FCSize(16, 16);

        /// <summary>
        /// ��ȡ�����ð�ť�ĳߴ�
        /// </summary>
        public virtual FCSize ButtonSize {
            get { return m_buttonSize; }
            set { m_buttonSize = value; }
        }

        protected bool m_checked;

        /// <summary>
        /// ��ȡ�������Ƿ�ѡ��
        /// </summary>
        public virtual bool Checked {
            get { return m_checked; }
            set {
                if (m_checked != value) {
                    m_checked = value;
                    onCheckedChanged();
                }
            }
        }

        protected String m_checkedBackImage;

        /// <summary>
        /// ��ȡ������ѡ��ʱ�ı���ͼ
        /// </summary>
        public virtual String CheckedBackImage {
            get { return m_checkedBackImage; }
            set { m_checkedBackImage = value; }
        }

        protected String m_checkHoveredBackImage;

        /// <summary>
        /// ��ȡ�����ô�����ͣ��ѡ��ʱ�ı���ͼƬ
        /// </summary>
        public virtual String CheckHoveredBackImage {
            get { return m_checkHoveredBackImage; }
            set { m_checkHoveredBackImage = value; }
        }

        protected String m_checkPushedBackImage;

        /// <summary>
        /// ��ȡ�����ô���������ѡ��ʱ�ı���ͼƬ
        /// </summary>
        public virtual String CheckPushedBackImage {
            get { return m_checkPushedBackImage; }
            set { m_checkPushedBackImage = value; }
        }

        protected String m_disableCheckedBackImage;

        /// <summary>
        /// ��ȡ�����ò�����ʱ��ѡ�б���ͼƬ
        /// </summary>
        public virtual String DisableCheckedBackImage {
            get { return m_disableCheckedBackImage; }
            set { m_disableCheckedBackImage = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "CheckBox";
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "CheckedChanged" });
            return eventNames;
        }

        /// <summary>
        /// ��ȡ�����õı���ɫ
        /// </summary>
        /// <returns>����ɫ</returns>
        protected override long getPaintingBackColor() {
            long backColor = BackColor;
            if (backColor != FCColor.None && FCColor.DisabledBack != FCColor.None) {
                if (!isPaintEnabled(this)) {
                    return FCColor.DisabledBack;
                }
            }
            return backColor;
        }

        /// <summary>
        /// ��ȡҪ���Ƶİ�ť�ı���ɫ
        /// </summary>
        /// <returns>��ť�ı���ɫ</returns>
        protected virtual long getPaintingButtonBackColor() {
            long buttonBackColor = m_buttonBackColor;
            if (buttonBackColor != FCColor.None && FCColor.DisabledBack != FCColor.None) {
                if (!isPaintEnabled(this)) {
                    return FCColor.DisabledBack;
                }
            }
            return buttonBackColor;
        }

        /// <summary>
        /// ��ȡҪ���Ƶİ�ť������ɫ
        /// </summary>
        /// <returns>���ߵ���ɫ</returns>
        protected virtual long getPaintingButtonBorderColor() {
            return m_buttonBorderColor;
        }

        /// <summary>
        /// ��ȡ���ڻ��Ƶı���ͼƬ
        /// </summary>
        protected override String getPaintingBackImage() {
            String backImage = null;
            FCNative native = Native;
            if (m_checked) {
                if (Enabled) {
                    if (this == native.PushedControl) {
                        backImage = m_checkPushedBackImage;
                    }
                    else if (this == native.HoveredControl) {
                        backImage = m_checkHoveredBackImage;
                    }
                    else {
                        backImage = m_checkedBackImage;
                    }
                }
                else {
                    backImage = m_disableCheckedBackImage;
                }
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
            if (name == "buttonalign") {
                type = "enum:FCHorizontalAlign";
                value = FCStr.convertHorizontalAlignToStr(ButtonAlign);
            }
            else if (name == "buttonbackcolor") {
                type = "color";
                value = FCStr.convertColorToStr(ButtonBackColor);
            }
            else if (name == "buttonbordercolor") {
                type = "color";
                value = FCStr.convertColorToStr(ButtonBorderColor);
            }
            else if (name == "buttonsize") {
                type = "size";
                value = FCStr.convertSizeToStr(ButtonSize);
            }
            else if (name == "checked") {
                type = "bool";
                value = FCStr.convertBoolToStr(Checked);
            }
            else if (name == "checkedbackimage") {
                type = "text";
                value = CheckedBackImage;
            }
            else if (name == "checkhoveredbackimage") {
                type = "text";
                value = CheckHoveredBackImage;
            }
            else if (name == "checkpushedbackimage") {
                type = "text";
                value = CheckPushedBackImage;
            }
            else if (name == "disablecheckedbackimage") {
                type = "text";
                value = DisableCheckedBackImage;
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
            propertyNames.AddRange(new String[] { "ButtonAlign", "ButtonBackColor","ButtonBorderColor", "ButtonSize", "Checked", "CheckedBackImage",
            "CheckHoveredBackimage", "CheckPushedBackImage", "DisableCheckedBackImage"});
            return propertyNames;
        }

        /// <summary>
        /// ѡ�иı䷽��
        /// </summary>
        public virtual void onCheckedChanged() {
            callEvents(FCEventID.CHECKEDCHANGED);
            update();
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            Checked = !Checked;
            callTouchEvents(FCEventID.CLICK, touchInfo);
            invalidate();
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect) {
            FCRect rect = new FCRect(0, 0, Width, Height);
            //���Ʊ���ɫ
            paint.fillRoundRect(getPaintingBackColor(), rect, m_cornerRadius);
        }

        /// <summary>
        /// �ػ�ѡ�а�ť����
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaintCheckButton(FCPaint paint, FCRect clipRect) {
            //���Ʊ���ͼ
            String bkImage = getPaintingBackImage();
            if (bkImage != null && bkImage.Length > 0) {
                paint.drawImage(bkImage, clipRect);
            }
            else {
                if (m_checked) {
                    FCRect innerRect = new FCRect(clipRect.left + 2, clipRect.top + 2, clipRect.right - 3, clipRect.bottom - 3);
                    if (clipRect.right - clipRect.left < 4 || clipRect.bottom - clipRect.top < 4) {
                        innerRect = clipRect;
                    }
                    paint.fillRect(getPaintingButtonBackColor(), innerRect);
                }
                paint.drawRect(getPaintingButtonBorderColor(), 1, 0, clipRect);
            }
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            String text = Text;
            int width = Width, height = Height;
            if (width > 0 && height > 0) {
                FCRect buttonRect = new FCRect(5, (height - m_buttonSize.cy) / 2, 5 + m_buttonSize.cx, (height + m_buttonSize.cy) / 2);
                FCPoint tLocation = new FCPoint();
                FCSize tSize = new FCSize();
                FCFont font = Font;
                if (text != null && text.Length > 0) {
                    tSize = paint.textSize(text, font);
                    tLocation.x = buttonRect.right + 5;
                    tLocation.y = (height - tSize.cy) / 2;
                }
                //����
                if (m_buttonAlign == FCHorizontalAlign.Center) {
                    buttonRect.left = (width - m_buttonSize.cx) / 2;
                    buttonRect.right = (width + m_buttonSize.cx) / 2;
                    tLocation.x = buttonRect.right + 5;
                }
                //Զ��
                else if (m_buttonAlign == FCHorizontalAlign.Right) {
                    buttonRect.left = width - m_buttonSize.cx - 5;
                    buttonRect.right = width - 5;
                    tLocation.x = buttonRect.left - tSize.cx - 5;
                }
                //���Ʊ���ͼ
                onPaintCheckButton(paint, buttonRect);
                //��������
                if (text != null && text.Length > 0) {
                    FCRect tRect = new FCRect(tLocation.x, tLocation.y, tLocation.x + tSize.cx + 1, tLocation.y + tSize.cy);
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
            if (name == "buttonalign") {
                ButtonAlign = FCStr.convertStrToHorizontalAlign(value);
            }
            else if (name == "buttonbackcolor") {
                ButtonBackColor = FCStr.convertStrToColor(value);
            }
            else if (name == "buttonbordercolor") {
                ButtonBorderColor = FCStr.convertStrToColor(value);
            }
            else if (name == "buttonsize") {
                ButtonSize = FCStr.convertStrToSize(value);
            }
            else if (name == "checked") {
                Checked = FCStr.convertStrToBool(value);
            }
            else if (name == "checkedbackimage") {
                CheckedBackImage = value;
            }
            else if (name == "checkhoveredbackimage") {
                CheckHoveredBackImage = value;
            }
            else if (name == "checkpushedbackimage") {
                CheckPushedBackImage = value;
            }
            else if (name == "disablecheckedbackimage") {
                DisableCheckedBackImage = value;
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
