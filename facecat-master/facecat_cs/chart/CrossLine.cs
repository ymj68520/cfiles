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
    /// ʮ����
    /// </summary>
    public class CrossLine : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        ~CrossLine() {
            delete();
        }

        protected bool m_allowDoubleClick = true;

        /// <summary>
        /// ��ȡ�������Ƿ�����˫������
        /// </summary>
        public virtual bool AllowDoubleClick {
            get { return m_allowDoubleClick; }
            set { m_allowDoubleClick = value; }
        }

        protected bool m_allowUserPaint;

        /// <summary>
        /// ��ȡ�������Ƿ������û���ͼ
        /// </summary>
        public virtual bool AllowUserPaint {
            get { return m_allowUserPaint; }
            set { m_allowUserPaint = value; }
        }

        protected AttachVScale m_attachVScale = AttachVScale.Left;

        /// <summary>
        /// ��ȡ���������������ỹ������
        /// </summary>
        public virtual AttachVScale AttachVScale {
            get { return m_attachVScale; }
            set { m_attachVScale = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected long m_lineColor = FCColor.argb(100, 100, 100);

        /// <summary>
        /// ��ȡ������ʮ���ߵ���ɫ
        /// </summary>
        public virtual long LineColor {
            get { return m_lineColor; }
            set { m_lineColor = value; }
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
            else if (name == "allowdoubleclick") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowDoubleClick);
            }
            else if (name == "attachvscale") {
                type = "enum:AttachVScale";
                if (AttachVScale == AttachVScale.Left) {
                    value = "Left";
                }
                else {
                    value = "Right";
                }
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
            propertyNames.AddRange(new String[] { "AllowUserPaint", "AllowDoubleClick", "AttachVScale", "LineColor" });
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
            else if (name == "allowdoubleclick") {
                AllowDoubleClick = FCStr.convertStrToBool(value);
            }
            else if (name == "attachvscale") {
                value = value.ToLower();
                if (value == "left") {
                    AttachVScale = AttachVScale.Left;
                }
                else {
                    AttachVScale = AttachVScale.Right;
                }
            }
            else if (name == "linecolor") {
                LineColor = FCStr.convertStrToColor(value);
            }
        }
    }
}
