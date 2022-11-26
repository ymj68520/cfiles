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
    /// ���������ĸ���
    /// </summary>
    [Serializable()]
    public class BaseShape : FCProperty {
        /// <summary>
        /// ��������
        /// </summary>
        ~BaseShape() {
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
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected bool m_selected = false;

        /// <summary>
        /// ��ȡ�������Ƿ�ѡ��
        /// </summary>
        public virtual bool Selected {
            get { return m_selected; }
            set { m_selected = value; }
        }

        protected bool m_visible = true;

        /// <summary>
        /// ��ȡ������ͼ���Ƿ�ɼ�
        /// </summary>
        public virtual bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        protected int m_zOrder;

        /// <summary>
        /// ��ȡ�����û�ͼ˳��
        /// </summary>
        public virtual int ZOrder {
            get { return m_zOrder; }
            set { m_zOrder = value; }
        }

        /// <summary>
        /// ������Դ�ķ���
        /// </summary>
        public virtual void delete() {
            if (!m_isDeleted) {
                m_isDeleted = true;
            }
        }

        /// <summary>
        /// ��ȡ�����ֶ�
        /// </summary>
        /// <returns></returns>
        public virtual int getBaseField() {
            return -1;
        }

        /// <summary>
        /// ���ֶ����ƻ�ȡ�ֶα���
        /// </summary>
        /// <param name="fieldName">�ֶ�����</param>
        /// <returns>�ֶα���</returns>
        public virtual String getFieldText(int fieldName) {
            return "";
        }

        /// <summary>
        /// ��ȡ�����ֶ�
        /// </summary>
        /// <returns></returns>
        public virtual int[] getFields() {
            return null;
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
            else if (name == "attachvscale") {
                type = "enum:AttachVScale";
                if (AttachVScale == AttachVScale.Left) {
                    value = "Left";
                }
                else {
                    value = "Right";
                }
            }
            else if (name == "selected") {
                type = "bool";
                value = FCStr.convertBoolToStr(Selected);
            }
            else if (name == "visible") {
                type = "bool";
                value = FCStr.convertBoolToStr(Visible);
            }
            else if (name == "zorder") {
                type = "int";
                value = FCStr.convertIntToStr(ZOrder);
            }
            else {
                type = "undefined";
                value = "";
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "AllowUserPaint", "AttachVScale", "Selected", "Visible", "ZOrder" });
            return propertyNames;
        }

        /// <summary>
        /// ��ȡѡ�е����ɫ
        /// </summary>
        /// <returns>��ɫ</returns>
        public virtual long getSelectedColor() {
            return 0;
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
            else if (name == "attachvscale") {
                value = value.ToLower();
                if (value == "left") {
                    AttachVScale = AttachVScale.Left;
                }
                else {
                    AttachVScale = AttachVScale.Right;
                }
            }
            else if (name == "selected") {
                Selected = FCStr.convertStrToBool(value);
            }
            else if (name == "visible") {
                Visible = FCStr.convertStrToBool(value);
            }
            else if (name == "zorder") {
                ZOrder = FCStr.convertStrToInt(value);
            }
        }
    }
}
