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
    /// ��״ͼ
    /// </summary>
    [Serializable()]
    public class BarShape : BaseShape {
        /// <summary>
        /// ������״ͼ
        /// </summary>
        public BarShape() {
            ZOrder = 0;
        }

        protected int m_colorField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ɫ���ֶ�
        /// </summary>
        public virtual int ColorField {
            get { return m_colorField; }
            set { m_colorField = value; }
        }

        protected long m_downColor = FCColor.argb(82, 255, 255);

        /// <summary>
        /// ��ȡ���������ߵ���ɫ
        /// </summary>
        public virtual long DownColor {
            get { return m_downColor; }
            set { m_downColor = value; }
        }

        protected int m_fieldName = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ�������ֶ�����
        /// </summary>
        public virtual int FieldName {
            get { return m_fieldName; }
            set { m_fieldName = value; }
        }

        protected int m_fieldName2 = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ�������ֶ�����2
        /// </summary>
        public virtual int FieldName2 {
            get { return m_fieldName2; }
            set { m_fieldName2 = value; }
        }

        protected String m_fieldText = String.Empty;

        /// <summary>
        /// ��ȡ��������ʾ�ı�������
        /// </summary>
        public virtual String FieldText {
            get {
                return m_fieldText;
            }
            set { m_fieldText = value; }
        }

        private String m_fieldText2 = String.Empty;

        /// <summary>
        /// ��ȡ��������ʾ�ı�������2
        /// </summary>
        public virtual String FieldText2 {
            get { return m_fieldText2; }
            set { m_fieldText2 = value; }
        }

        protected float m_lineWidth = 1;

        /// <summary>
        /// ��ȡ�������ߵĿ��
        /// </summary>
        public virtual float LineWidth {
            get { return m_lineWidth; }
            set { m_lineWidth = value; }
        }

        protected BarStyle m_style = BarStyle.Rect;

        /// <summary>
        /// ��ȡ��������������ʽ
        /// </summary>
        public virtual BarStyle Style {
            get { return m_style; }
            set { m_style = value; }
        }

        protected int m_styleField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ʽ�ֶ�
        /// -10000:���� -1:���߿��ľ��� 0:ʵ�ľ��� 1:ʵ�߿��ľ���  2:��
        /// </summary>
        public virtual int StyleField {
            get { return m_styleField; }
            set { m_styleField = value; }
        }

        protected long m_upColor = FCColor.argb(255, 82, 82);

        /// <summary>
        /// ��ȡ���������ߵ���ɫ
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
            return m_fieldName;
        }

        /// <summary>
        /// ���ֶ����ƻ�ȡ�ֶα���
        /// </summary>
        /// <param name="fieldName">�ֶ�����</param>
        /// <returns>�ֶα���</returns>
        public override String getFieldText(int fieldName) {
            if (fieldName == m_fieldName) {
                return FieldText;
            }
            else if (fieldName == m_fieldName2) {
                return FieldText2;
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
            if (m_fieldName2 == FCDataTable.NULLFIELD) {
                return new int[] { m_fieldName };
            }
            else {
                return new int[] { m_fieldName, m_fieldName2 };
            }
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "colorfield") {
                type = "int";
                value = FCStr.convertIntToStr(ColorField);
            }
            else if (name == "downcolor") {
                type = "color";
                value = FCStr.convertColorToStr(DownColor);
            }
            else if (name == "fieldname") {
                type = "int";
                value = FCStr.convertIntToStr(FieldName);
            }
            else if (name == "fieldname2") {
                type = "int";
                value = FCStr.convertIntToStr(FieldName2);
            }
            else if (name == "fieldtext") {
                type = "String";
                value = FieldText;
            }
            else if (name == "fieldtext2") {
                type = "String";
                value = FieldText2;
            }
            else if (name == "linewidth") {
                type = "float";
                value = FCStr.convertFloatToStr(LineWidth);
            }
            else if (name == "style") {
                type = "enum:BarStyle";
                BarStyle style = Style;
                if (style == BarStyle.Line) {
                    value = "Line";
                }
                else {
                    value = "Rect";
                }
            }
            else if (name == "stylefield") {
                type = "int";
                value = FCStr.convertIntToStr(StyleField);
            }
            else if (name == "upcolor") {
                type = "double";
                value = FCStr.convertColorToStr(UpColor);
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
            propertyNames.AddRange(new String[] { "ColorField", "DownColor", "FieldName", "FieldName2",
            "FieldText", "FieldText2", "LineWidth", "Style", "StyleField", "UpColor" });
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
            if (name == "colorfield") {
                ColorField = FCStr.convertStrToInt(value);
            }
            else if (name == "downcolor") {
                DownColor = FCStr.convertStrToColor(value);
            }
            else if (name == "fieldname") {
                FieldName = FCStr.convertStrToInt(value);
            }
            else if (name == "fieldname2") {
                FieldName2 = FCStr.convertStrToInt(value);
            }
            else if (name == "fieldtext") {
                FieldText = value;
            }
            else if (name == "fieldtext2") {
                FieldText2 = value;
            }
            else if (name == "linewidth") {
                LineWidth = FCStr.convertStrToFloat(value);
            }
            else if (name == "style") {
                value = value.ToLower();
                if (value == "line") {
                    Style = BarStyle.Line;
                }
                else {
                    Style = BarStyle.Rect;
                }
            }
            else if (name == "stylefield") {
                StyleField = FCStr.convertStrToInt(value);
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
