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
using System.Text;
using System.Drawing;

namespace FaceCat {
    /// <summary>
    /// ����
    /// </summary>
    [Serializable()]
    public class TextShape : BaseShape {
        /// <summary>
        /// ��������
        /// </summary>
        public TextShape() {
            ZOrder = 4;
        }

        protected int m_colorField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ɫ�ֶ�
        /// </summary>
        public virtual int ColorField {
            get { return m_colorField; }
            set { m_colorField = value; }
        }

        protected int m_fieldName = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ�������ֶ�
        /// </summary>
        public virtual int FieldName {
            get { return m_fieldName; }
            set { m_fieldName = value; }
        }

        protected FCFont m_font = new FCFont();

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual FCFont Font {
            get { return m_font; }
            set { m_font = value; }
        }

        protected int m_styleField = FCDataTable.NULLFIELD;

        /// <summary>
        /// ��ȡ��������ʽ�ֶ�
        /// -10000:����
        /// </summary>
        public virtual int StyleField {
            get { return m_styleField; }
            set { m_styleField = value; }
        }

        protected String m_text;

        /// <summary>
        /// ��ȡ�����û��Ƶ�����
        /// </summary>
        public virtual String Text {
            get { return m_text; }
            set { m_text = value; }
        }

        protected long m_textColor = FCColor.argb(255, 255, 255);

        /// <summary>
        /// ��ȡ������ǰ��ɫ
        /// </summary>
        public virtual long TextColor {
            get { return m_textColor; }
            set { m_textColor = value; }
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
            else if (name == "fieldname") {
                type = "int";
                value = FCStr.convertIntToStr(FieldName);
            }
            else if (name == "font") {
                type = "font";
                value = FCStr.convertFontToStr(Font);
            }
            else if (name == "stylefield") {
                type = "int";
                value = FCStr.convertIntToStr(StyleField);
            }
            else if (name == "text") {
                type = "String";
                value = Text;
            }
            else if (name == "textcolor") {
                type = "color";
                value = FCStr.convertColorToStr(TextColor);
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
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "ColorField", "FieldName", "Font", "StyleField", "Text", "TextColor" });
            return propertyNames;
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
            else if (name == "fieldname") {
                FieldName = FCStr.convertStrToInt(value);
            }
            else if (name == "font") {
                Font = FCStr.convertStrToFont(value);
            }
            else if (name == "stylefield") {
                StyleField = FCStr.convertStrToInt(value);
            }
            else if (name == "text") {
                Text = value;
            }
            else if (name == "textcolor") {
                TextColor = FCStr.convertStrToColor(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
