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
    /// ����
    /// </summary>
    [Serializable()]
    public class PolylineShape : BaseShape {
        /// <summary>
        /// ��������
        /// </summary>
        public PolylineShape() {
            ZOrder = 2;
        }

        protected long m_color = FCColor.argb(255, 255, 0);

        /// <summary>
        /// ��ȡ�������ߵ���ɫ
        /// </summary>
        public virtual long Color {
            get { return m_color; }
            set { m_color = value; }
        }

        protected int m_colorField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ɫ���ֶ�
        /// </summary>
        public virtual int ColorField {
            get { return m_colorField; }
            set { m_colorField = value; }
        }

        protected int m_fieldName = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ�������ֶ�����
        /// </summary>
        public virtual int FieldName {
            get { return m_fieldName; }
            set { m_fieldName = value; }
        }

        protected String m_fieldText = String.Empty;

        /// <summary>
        /// ��ȡ��������ʾ�ı�������
        /// </summary>
        public virtual String FieldText {
            get { return m_fieldText; }
            set { m_fieldText = value; }
        }

        protected long m_fillColor = FCColor.None;

        /// <summary>
        /// ��ȡ���������ɫ
        /// </summary>
        public virtual long FillColor {
            get { return m_fillColor; }
            set { m_fillColor = value; }
        }

        protected PolylineStyle m_style = PolylineStyle.SolidLine;

        /// <summary>
        /// ��ȡ��������ʽ
        /// </summary>
        public virtual PolylineStyle Style {
            get { return m_style; }
            set { m_style = value; }
        }

        protected float m_width = 1;

        /// <summary>
        /// ��ȡ�������ߵĿ��
        /// </summary>
        public virtual float Width {
            get { return m_width; }
            set { m_width = value; }
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
            else {
                return null;
            }
        }

        /// <summary>
        /// ��ȡ�����ֶ�
        /// </summary>
        /// <returns></returns>
        public override int[] getFields() {
            return new int[] { m_fieldName };
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "color") {
                type = "color";
                value = FCStr.convertColorToStr(Color);
            }
            else if (name == "colorfield") {
                type = "int";
                value = FCStr.convertIntToStr(ColorField);
            }
            else if (name == "fieldname") {
                type = "int";
                value = FCStr.convertIntToStr(FieldName);
            }
            else if (name == "fieldtext") {
                type = "String";
                value = FieldText;
            }
            else if (name == "fillcolor") {
                type = "color";
                value = FCStr.convertColorToStr(FillColor);
            }
            else if (name == "style") {
                type = "enum:PolylineStyle";
                PolylineStyle style = Style;
                if (style == PolylineStyle.Cycle) {
                    value = "Cycle";
                }
                else if (style == PolylineStyle.DashLine) {
                    value = "DashLine";
                }
                else if (style == PolylineStyle.DotLine) {
                    value = "DotLine";
                }
                else {
                    value = "SolidLine";
                }
            }
            else if (name == "width") {
                type = "float";
                value = FCStr.convertFloatToStr(Width);
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
            propertyNames.AddRange(new String[] { "Color", "ColorField", "FieldName", "FieldText",
            "FillColor", "Style", "Width"});
            return propertyNames;
        }

        /// <summary>
        /// ��ȡѡ�е����ɫ
        /// </summary>
        /// <returns>��ɫ</returns>
        public override long getSelectedColor() {
            return m_color;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "color") {
                Color = FCStr.convertStrToColor(value);
            }
            else if (name == "colorfield") {
                ColorField = FCStr.convertStrToInt(value);
            }
            else if (name == "fieldname") {
                FieldName = FCStr.convertStrToInt(value);
            }
            else if (name == "fieldtext") {
                FieldText = value;
            }
            else if (name == "fillcolor") {
                FillColor = FCStr.convertStrToColor(value);
            }
            else if (name == "style") {
                value = value.ToLower();
                if (value == "cyle") {
                    Style = PolylineStyle.Cycle;
                }
                else if (value == "dashline") {
                    Style = PolylineStyle.DashLine;
                }
                else if (value == "dotline") {
                    Style = PolylineStyle.DotLine;
                }
                else {
                    Style = PolylineStyle.SolidLine;
                }
            }
            else if (name == "width") {
                Width = FCStr.convertStrToFloat(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
