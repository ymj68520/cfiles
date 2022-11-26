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
    /// ��ʾ��
    /// </summary>
    public class ChartToolTip : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        ~ChartToolTip() {
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

        protected long m_backColor = FCColor.argb(255, 255, 128);

        /// <summary>
        /// ��ȡ��������ʾ��ı���ɫ
        /// </summary>
        public virtual long BackColor {
            get { return m_backColor; }
            set { m_backColor = value; }
        }

        protected long m_borderColor = FCColor.argb(255, 255, 80);

        /// <summary>
        /// ��ȡ�����ñ��ߵ���ɫ
        /// </summary>
        public virtual long BorderColor {
            get { return m_borderColor; }
            set { m_borderColor = value; }
        }

        protected FCFont m_font = new FCFont();

        /// <summary>
        /// ��ȡ��������ʾ�������
        /// </summary>
        public virtual FCFont Font {
            get { return m_font; }
            set { m_font = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected long m_textColor = FCColor.argb(0, 0, 0);

        /// <summary>
        /// ��ȡ��������ʾ���������ɫ
        /// </summary>
        public virtual long TextColor {
            get { return m_textColor; }
            set { m_textColor = value; }
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
            else if (name == "backcolor") {
                type = "color";
                value = FCStr.convertColorToStr(BackColor);
            }
            else if (name == "bordercolor") {
                type = "color";
                value = FCStr.convertColorToStr(BorderColor);
            }
            else if (name == "font") {
                type = "font";
                value = FCStr.convertFontToStr(Font);
            }
            else if (name == "textcolor") {
                type = "color";
                value = FCStr.convertColorToStr(TextColor);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "AllowUserPaint", "BackColor", "BorderColor", "Font", "TextColor" });
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
            else if (name == "backcolor") {
                BackColor = FCStr.convertStrToColor(value);
            }
            else if (name == "bordercolor") {
                BorderColor = FCStr.convertStrToColor(value);
            }
            else if (name == "font") {
                Font = FCStr.convertStrToFont(value);
            }
            else if (name == "textcolor") {
                TextColor = FCStr.convertStrToColor(value);
            }
        }
    }
}
