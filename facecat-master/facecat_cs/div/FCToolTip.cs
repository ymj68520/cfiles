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
    /// ��ʾ��ǩ
    /// </summary>
    public class FCToolTip : FCLabel {
        /// <summary>
        /// ������ǩ
        /// </summary>
        public FCToolTip() {
            AutoSize = true;
            BackColor = FCColor.argb(255, 255, 40);
            BorderColor = FCColor.Border;
            TopMost = true;
            Visible = false;
        }

        /// <summary>
        /// ��һ�δ�����λ��
        /// </summary>
        private FCPoint m_lastTouchPoint;

        /// <summary>
        /// ���ID
        /// </summary>
        private int m_timerID = getNewTimerID();

        /// <summary>
        /// ʣ�ౣ����ʾ������
        /// </summary>
        protected int m_remainAutoPopDelay;

        /// <summary>
        /// ʣ���ӳ���ʾ������
        /// </summary>
        protected int m_remainInitialDelay;

        protected int m_autoPopDelay = 5000;

        /// <summary>
        /// ��ʾ������ʾ��ʱ�䳤��
        /// </summary>
        public virtual int AutoPopDelay {
            get { return m_autoPopDelay; }
            set { m_autoPopDelay = value; }
        }

        protected int m_initialDelay = 500;

        /// <summary>
        /// ��ȡ�����ô�����ֹʱ�ӳ���ʾ�ĺ�����
        /// </summary>
        public virtual int InitialDelay {
            get { return m_initialDelay; }
            set { m_initialDelay = value; }
        }

        protected bool m_showAlways;

        /// <summary>
        /// ��ȡ�������Ƿ�������ʾ
        /// </summary>
        public virtual bool ShowAlways {
            get { return m_showAlways; }
            set { m_showAlways = value; }
        }

        protected bool m_useAnimation;

        /// <summary>
        /// ��ȡ�������Ƿ�����ʾ����ʱʹ�ö���
        /// </summary>
        public virtual bool UseAnimation {
            get { return m_useAnimation; }
            set { m_useAnimation = value; }
        }

        /// <summary>
        /// ���ٿؼ�����
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                stopTimer(m_timerID);
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns></returns>
        public override String getControlType() {
            return "ToolTip";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "autopopupdelay") {
                type = "int";
                value = FCStr.convertIntToStr(AutoPopDelay);
            }
            else if (name == "initialdelay") {
                type = "int";
                value = FCStr.convertIntToStr(InitialDelay);
            }
            else if (name == "showalways") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowAlways);
            }
            else if (name == "useanimation") {
                type = "bool";
                value = FCStr.convertBoolToStr(UseAnimation);
            }
            else {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "AutoPopupDelay", "InitialDelay", "ShowAlways", "UseAnimation" });
            return propertyNames;
        }

        /// <summary>
        /// ���ؿؼ�
        /// </summary>
        public override void hide() {
            Visible = false;
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            m_lastTouchPoint = TouchPoint;
            startTimer(m_timerID, 10);
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID) {
            base.onTimer(timerID);
            if (m_timerID == timerID) {
                FCPoint mp = TouchPoint;
                if (!m_showAlways) {
                    if (m_lastTouchPoint.x != mp.x || m_lastTouchPoint.y != mp.y) {
                        Visible = false;
                    }
                }
                m_lastTouchPoint = mp;
                if (m_remainAutoPopDelay > 0) {
                    m_remainAutoPopDelay -= 10;
                    if (m_remainAutoPopDelay <= 0) {
                        Visible = false;
                    }
                }
                if (m_remainInitialDelay > 0) {
                    m_remainInitialDelay -= 10;
                    if (m_remainInitialDelay <= 0) {
                        Visible = true;
                    }
                }
            }
        }

        /// <summary>
        /// �ɼ�״̬�ı䷽��
        /// </summary>
        public override void onVisibleChanged() {
            base.onVisibleChanged();
            if (m_native != null) {
                if (Visible) {
                    m_native.addControl(this);
                    m_remainAutoPopDelay = m_autoPopDelay;
                    m_remainInitialDelay = 0;
                }
                else {
                    m_native.removeControl(this);
                    startTimer(m_timerID, 10);
                    m_remainAutoPopDelay = 0;
                    m_remainInitialDelay = 0;
                }
                Native.invalidate();
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "autopopupdelay") {
                AutoPopDelay = FCStr.convertStrToInt(value);
            }
            else if (name == "initialdelay") {
                InitialDelay = FCStr.convertStrToInt(value);
            }
            else if (name == "showalways") {
                ShowAlways = FCStr.convertStrToBool(value);
            }
            else if (name == "useanimation") {
                UseAnimation = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ��ʾ�ؼ�
        /// </summary>
        public override void show() {
            m_remainAutoPopDelay = 0;
            m_remainInitialDelay = m_initialDelay;
            Visible = m_initialDelay == 0;
            Native.invalidate();
        }
    }
}
