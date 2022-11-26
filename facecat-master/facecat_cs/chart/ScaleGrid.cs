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
    /// ������
    /// </summary>
    [Serializable()]
    public class ScaleGrid : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        ~ScaleGrid() {
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

        protected int m_distance = 30;

        /// <summary>
        /// ��ȡ�����þ���
        /// </summary>
        public virtual int Distance {
            get { return m_distance; }
            set { m_distance = value; }
        }

        protected long m_gridColor = FCColor.argb(80, 0, 0);

        /// <summary>
        /// ��ȡ�����������ߵ���ɫ
        /// </summary>
        public virtual long GridColor {
            get { return m_gridColor; }
            set { m_gridColor = value; }
        }

        protected int m_lineStyle = 2;

        /// <summary>
        /// ��ȡ�����û�ȡ�����ú��������ߵ���ʽ
        /// </summary>
        public virtual int LineStyle {
            get { return m_lineStyle; }
            set { m_lineStyle = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected bool m_visible = true;

        /// <summary>
        /// ��ȡ�������Ƿ�ɼ�
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
            else if (name == "distance") {
                type = "int";
                value = FCStr.convertIntToStr(Distance);
            }
            else if (name == "gridcolor") {
                type = "color";
                value = FCStr.convertColorToStr(GridColor);
            }
            else if (name == "linestyle") {
                type = "int";
                value = FCStr.convertIntToStr(LineStyle);
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
            propertyNames.AddRange(new String[] { "AllowUserPaint", "Distance", "GridColor", "LineStyle", "Visible" });
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
            else if (name == "distance") {
                Distance = FCStr.convertStrToInt(value);
            }
            else if (name == "gridcolor") {
                GridColor = FCStr.convertStrToColor(value);
            }
            else if (name == "linestyle") {
                LineStyle = FCStr.convertStrToInt(value);
            }
            else if (name == "visible") {
                Visible = FCStr.convertStrToBool(value);
            }
        }
    }
}
