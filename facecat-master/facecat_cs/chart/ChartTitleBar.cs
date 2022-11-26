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
    /// ͼ�������
    /// </summary>
    [Serializable()]
    public class ChartTitleBar : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        ~ChartTitleBar() {
            delete();
        }

        protected bool m_allowUserPaint;

        /// <summary>
        /// ��ȡ�������Ƿ������û���ͼ
        /// </summary>
        public virtual bool AllowUserPaint {
            get { return m_allowUserPaint; }
            set { m_allowUserPaint = value; }
        }

        protected FCFont m_font = new FCFont();

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual FCFont Font {
            get { return m_font; }
            set { m_font = value; }
        }

        protected int m_height = 22;

        /// <summary>
        /// ��ȡ�����ñ���߶�
        /// </summary>
        public virtual int Height {
            get { return m_height; }
            set { m_height = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected int m_maxLine = 3;

        /// <summary>
        /// ��ȡ����������������
        /// </summary>
        public virtual int MaxLine {
            get { return m_maxLine; }
            set { m_maxLine = value; }
        }

        protected bool m_showUnderLine = true;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ�����������
        /// </summary>
        public virtual bool ShowUnderLine {
            get { return m_showUnderLine; }
            set { m_showUnderLine = value; }
        }

        protected String m_text = String.Empty;

        /// <summary>
        /// ��ȡ�����ò�ı���
        /// </summary>
        public virtual String Text {
            get { return m_text; }
            set { m_text = value; }
        }

        protected long m_textColor = FCColor.argb(255, 255, 255);

        /// <summary>
        /// ��ȡ�����ñ����������ɫ
        /// </summary>
        public virtual long TextColor {
            get { return m_textColor; }
            set { m_textColor = value; }
        }

        protected ArrayList<CTitle> m_titles = new ArrayList<CTitle>();

        /// <summary>
        /// ��ȡ�����ñ���
        /// </summary>
        public virtual ArrayList<CTitle> Titles {
            get { return m_titles; }
            set { m_titles = value; }
        }

        protected long m_underLineColor = FCColor.argb(80, 0, 0);

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ����������ߵ���ɫ
        /// </summary>
        public virtual long UnderLineColor {
            get { return m_underLineColor; }
            set { m_underLineColor = value; }
        }

        protected bool m_visible = true;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ����
        /// </summary>
        public virtual bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        /// <summary>
        /// ������Դ
        /// </summary>
        public void delete() {
            m_isDeleted = true;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "allowuserpaint") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowUserPaint);
            }
            else if (name == "font") {
                type = "font";
                value = FCStr.convertFontToStr(Font);
            }
            else if (name == "textcolor") {
                type = "color";
                value = FCStr.convertColorToStr(TextColor);
            }
            else if (name == "height") {
                type = "int";
                value = FCStr.convertIntToStr(Height);
            }
            else if (name == "maxline") {
                type = "int";
                value = FCStr.convertIntToStr(MaxLine);
            }
            else if (name == "showunderline") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowUnderLine);
            }
            else if (name == "text") {
                type = "String";
                value = Text;
            }
            else if (name == "underlinecolor") {
                type = "color";
                value = FCStr.convertColorToStr(UnderLineColor);
            }
            else if (name == "visible") {
                type = "bool";
                value = FCStr.convertBoolToStr(Visible);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "AllowUserPaint", "Font", "Height", "MaxLine", "ShowUnderLine",
            "Text", "TextColor", "UnderLineColor", "Visible"});
            return propertyNames;
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="div">ͼ��</param>
        /// <param name="rect">����</param>
        public virtual void onPaint(FCPaint paint, ChartDiv div, FCRect rect) {

        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "allowuserpaint") {
                AllowUserPaint = FCStr.convertStrToBool(value);
            }
            else if (name == "font") {
                Font = FCStr.convertStrToFont(value);
            }
            else if (name == "height") {
                Height = FCStr.convertStrToInt(value);
            }
            else if (name == "maxline") {
                MaxLine = FCStr.convertStrToInt(value);
            }
            else if (name == "showunderline") {
                ShowUnderLine = FCStr.convertStrToBool(value);
            }
            else if (name == "text") {
                Text = value;
            }
            else if (name == "textclor") {
                TextColor = FCStr.convertStrToColor(value);
            }
            else if (name == "underlinecolor") {
                UnderLineColor = FCStr.convertStrToColor(value);
            }
            else if (name == "visible") {
                Visible = FCStr.convertStrToBool(value);
            }
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    [Serializable()]
    public class CTitle : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="fieldName">�ֶ�����</param>
        /// <param name="fieldText">�ֶ�����</param>
        /// <param name="textColor">������ɫ</param>
        /// <param name="digit">����С��λ��</param>
        /// <param name="visible">�Ƿ�ɼ�</param>
        public CTitle(int fieldName, String fieldText, long textColor, int digit, bool visible) {
            m_fieldName = fieldName;
            m_fieldText = fieldText;
            m_textColor = textColor;
            m_digit = digit;
            m_visible = visible;
        }

        private int m_digit = 2;

        /// <summary>
        /// ��ȡ�����ñ���С����λ��
        /// </summary>
        public int Digit {
            get { return m_digit; }
            set { m_digit = value; }
        }

        private int m_fieldName;

        /// <summary>
        /// ��ȡ�������ֶ�����
        /// </summary>
        public int FieldName {
            get { return m_fieldName; }
            set { m_fieldName = value; }
        }

        private String m_fieldText;

        /// <summary>
        /// ��ȡ�������ֶ�����
        /// </summary>
        public String FieldText {
            get { return m_fieldText; }
            set { m_fieldText = value; }
        }

        private TextMode m_fieldTextMode = TextMode.Full;

        /// <summary>
        /// ��ȡ�����ñ�����ʾģʽ
        /// </summary>
        public TextMode FieldTextMode {
            get { return m_fieldTextMode; }
            set { m_fieldTextMode = value; }
        }

        private String m_fieldTextSeparator = " ";

        /// <summary>
        /// ��ȡ�����ñ���ķָ���
        /// </summary>
        public String FieldTextSeparator {
            get { return m_fieldTextSeparator; }
            set { m_fieldTextSeparator = value; }
        }

        private long m_textColor;

        /// <summary>
        /// ��ȡ���������ֵ���ɫ
        /// </summary>
        public long TextColor {
            get { return m_textColor; }
            set { m_textColor = value; }
        }

        private bool m_visible;

        /// <summary>
        /// ��ȡ�������Ƿ�ɼ�
        /// </summary>
        public bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "digit") {
                type = "int";
                value = FCStr.convertIntToStr(Digit);
            }
            else if (name == "fieldname") {
                type = "int";
                value = FCStr.convertIntToStr(FieldName);
            }
            else if (name == "fieldtext") {
                type = "text";
                value = FieldText;
            }
            else if (name == "fieldtextmode") {
                type = "enum:TextMode";
                TextMode fieldTextMode = FieldTextMode;
                if (fieldTextMode == TextMode.Field) {
                    value = "field";
                }
                else if (fieldTextMode == TextMode.Full) {
                    value = "full";
                }
                else if (fieldTextMode == TextMode.None) {
                    value = "none";
                }
                else {
                    value = "value";
                }
            }
            else if (name == "fieldtextseparator") {
                value = FieldTextSeparator;
            }
            else if (name == "textcolor") {
                type = "color";
                value = FCStr.convertColorToStr(TextColor);
            }
            else if (name == "visible") {
                type = "bool";
                value = FCStr.convertBoolToStr(Visible);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "Digit", "FieldName", "FieldText", "FieldTextMode", "FieldTextSeparator", "TextColor", "Visible" });
            return propertyNames;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "digit") {
                Digit = FCStr.convertStrToInt(value);
            }
            else if (name == "fieldname") {
                FieldName = FCStr.convertStrToInt(value);
            }
            else if (name == "fieldtext") {
                FieldText = value;
            }
            else if (name == "fieldtextmode") {
                value = value.ToLower();
                if (value == "field") {
                    FieldTextMode = TextMode.Field;
                }
                else if (value == "full") {
                    FieldTextMode = TextMode.Full;
                }
                else if (value == "none") {
                    FieldTextMode = TextMode.None;
                }
                else {
                    FieldTextMode = TextMode.Value;
                }
            }
            else if (name == "fieldtextseparator") {
                FieldTextSeparator = value;
            }
            else if (name == "textcolor") {
                TextColor = FCStr.convertStrToColor(value);
            }
            else if (name == "visible") {
                Visible = FCStr.convertStrToBool(value);
            }
        }
    }
}
