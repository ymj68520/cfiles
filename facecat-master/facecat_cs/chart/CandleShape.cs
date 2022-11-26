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
    /// K��
    /// </summary>
    [Serializable()]
    public class CandleShape : BaseShape {
        /// <summary>
        /// ����K��
        /// </summary>
        public CandleShape() {
            ZOrder = 1;
        }

        protected int m_closeField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ���������̼��ֶ�
        /// </summary>
        public virtual int CloseField {
            get { return m_closeField; }
            set { m_closeField = value; }
        }

        protected int m_colorField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ɫ���ֶ�
        /// </summary>
        public virtual int ColorField {
            get { return m_colorField; }
            set { m_colorField = value; }
        }

        protected String m_closeFieldText;

        /// <summary>
        /// ��ȡ���������̼۵���ʾ����
        /// </summary>
        public virtual String CloseFieldText {
            get {
                return m_closeFieldText;
            }
            set { m_closeFieldText = value; }
        }

        protected long m_downColor = FCColor.argb(82, 255, 255);

        /// <summary>
        /// ��ȡ���������ߵ���ɫ
        /// </summary>
        public virtual long DownColor {
            get { return m_downColor; }
            set { m_downColor = value; }
        }

        protected int m_highField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������߼��ֶ�
        /// </summary>
        public virtual int HighField {
            get { return m_highField; }
            set { m_highField = value; }
        }

        protected String m_highFieldText;

        /// <summary>
        /// ��ȡ��������߼۵���ʾ����
        /// </summary>
        public virtual String HighFieldText {
            get {
                return m_highFieldText;
            }
            set { m_highFieldText = value; }
        }

        protected int m_lowField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ͼ��ֶ�
        /// </summary>
        public virtual int LowField {
            get { return m_lowField; }
            set { m_lowField = value; }
        }

        protected String m_lowFieldText;

        /// <summary>
        /// ��ȡ��������ͼ۵���ʾ����
        /// </summary>
        public virtual String LowFieldText {
            get {
                return m_lowFieldText;
            }
            set { m_lowFieldText = value; }
        }

        protected int m_openField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ�����ÿ��̼��ֶ�
        /// </summary>
        public virtual int OpenField {
            get { return m_openField; }
            set { m_openField = value; }
        }

        private String m_openFieldText;

        /// <summary>
        /// ��ȡ�����ÿ��̼۵���ʾ����
        /// </summary>
        public virtual String OpenFieldText {
            get {
                return m_openFieldText;
            }
            set { m_openFieldText = value; }
        }

        protected bool m_showMaxMin = true;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ�����Сֵ
        /// </summary>
        public virtual bool ShowMaxMin {
            get { return m_showMaxMin; }
            set { m_showMaxMin = value; }
        }

        protected CandleStyle m_style = CandleStyle.Rect;

        /// <summary>
        /// ��ȡ����������������
        /// </summary>
        public virtual CandleStyle Style {
            get { return m_style; }
            set { m_style = value; }
        }

        protected int m_styleField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ʽ�ֶ�
        /// -10000:���� 0:���߿�������ʵ�� 1:���ľ��� 2:ʵ�ľ��� 3:������ 4:������ 5:������
        /// </summary>
        public virtual int StyleField {
            get { return m_styleField; }
            set { m_styleField = value; }
        }

        protected long m_tagColor = FCColor.argb(255, 255, 255);

        /// <summary>
        /// ��ȡ�����������Сֵ��ǩ����ɫ
        /// </summary>
        public virtual long TagColor {
            get { return m_tagColor; }
            set { m_tagColor = value; }
        }

        protected long m_upColor = FCColor.argb(255, 82, 82);

        /// <summary>
        /// ��ȡ������������ɫ
        /// </summary>
        public virtual long UpColor {
            get { return m_upColor; }
            set { m_upColor = value; }
        }

        /// <summary>
        /// ��ȡ�����ֶ�
        /// </summary>
        /// <returns></returns>
        public override int getBaseField() {
            return m_closeField;
        }

        /// <summary>
        /// ���ֶ����ƻ�ȡ�ֶα���
        /// </summary>
        /// <param name="fieldName">�ֶ�����</param>
        /// <returns>�ֶα���</returns>
        public override String getFieldText(int fieldName) {
            if (fieldName == m_closeField) {
                return CloseFieldText;
            }
            else if (fieldName == m_highField) {
                return HighFieldText;
            }
            else if (fieldName == m_lowField) {
                return LowFieldText;
            }
            else if (fieldName == m_openField) {
                return OpenFieldText;
            }
            else {
                return null;
            }
        }

        /// <summary>
        /// ��ȡ�����ֶ�
        /// </summary>
        /// <returns></returns>
        public override int[] getFields() {
            return new int[] { m_closeField, m_highField, m_lowField, m_openField };
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "closefield") {
                type = "int";
                value = FCStr.convertIntToStr(CloseField);
            }
            else if (name == "colorfield") {
                type = "int";
                value = FCStr.convertIntToStr(ColorField);
            }
            else if (name == "closefieldtext") {
                type = "String";
                value = CloseFieldText;
            }
            else if (name == "downcolor") {
                type = "color";
                value = FCStr.convertColorToStr(DownColor);
            }
            else if (name == "highfield") {
                type = "int";
                value = FCStr.convertIntToStr(HighField);
            }
            else if (name == "highfieldtext") {
                type = "String";
                value = HighFieldText;
            }
            else if (name == "lowfield") {
                type = "int";
                value = FCStr.convertIntToStr(LowField);
            }
            else if (name == "lowfieldtext") {
                type = "String";
                value = LowFieldText;
            }
            else if (name == "openfield") {
                type = "int";
                value = FCStr.convertIntToStr(OpenField);
            }
            else if (name == "openfieldtext") {
                type = "String";
                value = OpenFieldText;
            }
            else if (name == "showmaxmin") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowMaxMin);
            }
            else if (name == "style") {
                type = "enum:CandleStyle";
                CandleStyle style = Style;
                if (style == CandleStyle.American) {
                    value = "American";
                }
                else if (style == CandleStyle.CloseLine) {
                    value = "CloseLine";
                }
                else if (style == CandleStyle.Tower) {
                    value = "Tower";
                }
                else {
                    value = "Rect";
                }
            }
            else if (name == "stylefield") {
                type = "int";
                value = FCStr.convertIntToStr(StyleField);
            }
            else if (name == "tagcolor") {
                type = "double";
                value = FCStr.convertDoubleToStr(TagColor);
            }
            else if (name == "upcolor") {
                type = "color";
                value = FCStr.convertDoubleToStr(UpColor);
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
            propertyNames.AddRange(new String[] { "CloseField", "ColorField", "CloseFieldText", "DownColor", "DownColor",
            "HighFieldText", "LowField", "LowFieldText", "OpenField", "OpenFieldText", "ShowMaxMin", "Style", "StyleField",
            "TagColor", "UpColor"});
            return propertyNames;
        }

        /// <summary>
        /// ��ȡѡ�е����ɫ
        /// </summary>
        /// <returns>��ɫ</returns>
        public override long getSelectedColor() {
            return m_downColor;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "closefield") {
                CloseField = FCStr.convertStrToInt(value);
            }
            else if (name == "colorfield") {
                ColorField = FCStr.convertStrToInt(value);
            }
            else if (name == "closefieldtext") {
                CloseFieldText = value;
            }
            else if (name == "downcolor") {
                DownColor = FCStr.convertStrToColor(value);
            }
            else if (name == "highfield") {
                HighField = FCStr.convertStrToInt(value);
            }
            else if (name == "highfieldtext") {
                HighFieldText = value;
            }
            else if (name == "lowfield") {
                LowField = FCStr.convertStrToInt(value);
            }
            else if (name == "lowfieldtext") {
                LowFieldText = value;
            }
            else if (name == "openfield") {
                OpenField = FCStr.convertStrToInt(value);
            }
            else if (name == "openfieldtext") {
                OpenFieldText = value;
            }
            else if (name == "showmaxmin") {
                ShowMaxMin = FCStr.convertStrToBool(value);
            }
            else if (name == "style") {
                value = value.ToLower();
                if (value == "american") {
                    Style = CandleStyle.American;
                }
                else if (value == "closeline") {
                    Style = CandleStyle.CloseLine;
                }
                else if (value == "tower") {
                    Style = CandleStyle.Tower;
                }
                else {
                    Style = CandleStyle.Rect;
                }
            }
            else if (name == "stylefield") {
                StyleField = FCStr.convertStrToInt(value);
            }
            else if (name == "tagcolor") {
                TagColor = FCStr.convertStrToColor(value);
            }
            else if (name == "upcolor") {
                UpColor = FCStr.convertStrToColor(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
