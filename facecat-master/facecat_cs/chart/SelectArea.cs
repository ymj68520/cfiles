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
    /// ѡ������
    /// </summary>
    public class SelectArea : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        ~SelectArea() {
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

        protected long m_backColor = FCColor.None;

        /// <summary>
        /// ��ȡ�����ñ���ɫ
        /// </summary>
        public virtual long BackColor {
            get { return m_backColor; }
            set { m_backColor = value; }
        }

        protected FCRect m_bounds;

        /// <summary>
        /// ��ȡ������ѡ�п������
        /// </summary>
        public virtual FCRect Bounds {
            get { return m_bounds; }
            set { m_bounds = value; }
        }

        protected bool m_canResize;

        /// <summary>
        /// ��ȡ�������Ƿ���Ըı�ѡ�п�Ĵ�С
        /// </summary>
        public virtual bool CanResize {
            get { return m_canResize; }
            set { m_canResize = value; }
        }

        protected bool m_enabled = true;

        /// <summary>
        /// ��ȡ�������Ƿ���Գ���ѡ�п�
        /// </summary>
        public virtual bool Enabled {
            get { return m_enabled; }
            set { m_enabled = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected long m_lineColor = FCColor.argb(255, 255, 255);

        /// <summary>
        /// ��ȡ������ѡ�п����ɫ
        /// </summary>
        public virtual long LineColor {
            get { return m_lineColor; }
            set { m_lineColor = value; }
        }

        protected bool m_visible;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾѡ�п�
        /// </summary>
        public virtual bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        /// <summary>
        /// �ر�
        /// </summary>
        public void close() {
            m_visible = false;
            m_canResize = false;
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
            else if (name == "enabled") {
                type = "bool";
                value = FCStr.convertBoolToStr(Enabled);
            }
            else if (name == "linecolor") {
                type = "color";
                value = FCStr.convertColorToStr(LineColor);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "AllowUserPaint", "Enabled", "LineColor" });
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
            else if (name == "enabled") {
                Enabled = FCStr.convertStrToBool(value);
            }
            else if (name == "linecolor") {
                LineColor = FCStr.convertStrToColor(value);
            }
        }
    }
}
