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
    /// �������ؼ�
    /// </summary>
    public class FCScrollBar : FCView {
        /// <summary>
        /// ����������
        /// </summary>
        public FCScrollBar() {
            m_addButtonTouchDownEvent = new FCTouchEvent(addButtonTouchDown);
            m_addButtonTouchUpEvent = new FCTouchEvent(addButtonTouchUp);
            m_scrollButtonDraggingEvent = new FCEvent(scrollButtonDragging);
            m_reduceButtonTouchDownEvent = new FCTouchEvent(reduceButtonTouchDown);
            m_reduceButtonTouchUpEvent = new FCTouchEvent(reduceButtonTouchUp);
            CanFocus = false;
            DisplayOffset = false;
            FCSize size = new FCSize(10, 10);
            Size = size;
            TopMost = true;
        }

        /// <summary>
        /// ������ť�İ����¼�
        /// </summary>
        private FCTouchEvent m_addButtonTouchDownEvent;

        /// <summary>
        /// ������ť��̧���¼�
        /// </summary>
        private FCTouchEvent m_addButtonTouchUpEvent;

        protected int m_addSpeed;

        /// <summary>
        /// ��ȡ�����õ�ǰ�ļ��ٶ�
        /// </summary>
        public virtual int AddSpeed {
            get { return m_addSpeed; }
            set {
                m_addSpeed = value;
                if (m_addSpeed != 0) {
                    startTimer(m_timerID, 10);
                }
                else {
                    stopTimer(m_timerID);
                }
            }
        }

        protected bool m_isAdding;

        /// <summary>
        /// ��ȡ�������Ƿ���������
        /// </summary>
        public virtual bool IsAdding {
            get { return m_isAdding; }
            set {
                m_isAdding = value;
                m_tick = 0;
                if (m_isAdding) {
                    startTimer(m_timerID, 100);
                }
                else {
                    stopTimer(m_timerID);
                }
            }
        }

        protected bool m_isReducing;

        /// <summary>
        /// ��ȡ�������Ƿ����ڼ���
        /// </summary>
        public virtual bool IsReducing {
            get { return m_isReducing; }
            set {
                m_isReducing = value;
                m_tick = 0;
                if (m_isReducing) {
                    startTimer(m_timerID, 100);
                }
                else {
                    stopTimer(m_timerID);
                }
            }
        }

        /// <summary>
        /// ������ť�İ����¼�
        /// </summary>
        private FCTouchEvent m_reduceButtonTouchDownEvent;

        /// <summary>
        /// ������ť��̧���¼�
        /// </summary>
        private FCTouchEvent m_reduceButtonTouchUpEvent;

        /// <summary>
        /// ������ť��ק�¼�
        /// </summary>
        private FCEvent m_scrollButtonDraggingEvent;

        /// <summary>
        /// ������
        /// </summary>
        private int m_tick;

        /// <summary>
        /// ���ID
        /// </summary>
        private int m_timerID = getNewTimerID();

        protected FCButton m_addButton;

        /// <summary>
        /// ������ť
        /// </summary>
        public virtual FCButton AddButton {
            get { return m_addButton; }
        }

        protected FCButton m_backButton;

        /// <summary>
        /// ��ȡ����������ť
        /// </summary>
        public virtual FCButton BackButton {
            get { return m_backButton; }
        }

        protected int m_contentSize = 0;

        /// <summary>
        /// ��ȡ���������ݳߴ�
        /// </summary>
        public virtual int ContentSize {
            get { return m_contentSize; }
            set { m_contentSize = value; }
        }

        protected int m_lineSize = 10;

        /// <summary>
        /// ÿ�ι������гߴ�
        /// </summary>
        public virtual int LineSize {
            get { return m_lineSize; }
            set { m_lineSize = value; }
        }

        protected int m_pageSize;

        /// <summary>
        /// ��ȡ������ҳ�ĳߴ�
        /// </summary>
        public virtual int PageSize {
            get { return m_pageSize; }
            set { m_pageSize = value; }
        }

        protected int m_pos;

        /// <summary>
        /// ��ȡ�����ù�������
        /// </summary>
        public virtual int Pos {
            get { return m_pos; }
            set {
                m_pos = value;
                if (m_pos > m_contentSize - m_pageSize) {
                    m_pos = m_contentSize - m_pageSize;
                }
                if (m_pos < 0) {
                    m_pos = 0;
                }
            }
        }

        protected FCButton m_reduceButton;

        /// <summary>
        /// ������ť
        /// </summary>
        public virtual FCButton ReduceButton {
            get { return m_reduceButton; }
        }

        protected FCButton m_scrollButton;

        /// <summary>
        /// ��ȡ������ť
        /// </summary>
        public virtual FCButton ScrollButton {
            get { return m_scrollButton; }
        }

        /// <summary>
        /// ����������ť�����¼��ص��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void addButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            onAddButtonTouchDown(touchInfo);
        }

        /// <summary>
        /// ����������ţ̌���¼��ص��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void addButtonTouchUp(object sender, FCTouchInfo touchInfo) {
            onAddButtonTouchUp(touchInfo);
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                stopTimer(m_timerID);
                if (m_addButton != null) {
                    if (m_addButtonTouchDownEvent != null) {
                        m_addButton.removeEvent(m_addButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_addButtonTouchDownEvent = null;
                    }
                    if (m_addButtonTouchUpEvent != null) {
                        m_addButton.removeEvent(m_addButtonTouchUpEvent, FCEventID.TOUCHUP);
                        m_addButtonTouchUpEvent = null;
                    }
                }
                if (m_scrollButton != null) {
                    if (m_scrollButtonDraggingEvent != null) {
                        m_scrollButton.removeEvent(m_scrollButtonDraggingEvent, FCEventID.DRAGGING);
                        m_scrollButtonDraggingEvent = null;
                    }
                }
                if (m_reduceButton != null) {
                    if (m_reduceButtonTouchDownEvent != null) {
                        m_reduceButton.removeEvent(m_reduceButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_reduceButtonTouchDownEvent = null;
                    }
                    if (m_reduceButtonTouchUpEvent != null) {
                        m_reduceButton.removeEvent(m_reduceButtonTouchUpEvent, FCEventID.TOUCHUP);
                        m_reduceButtonTouchUpEvent = null;
                    }
                }
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "ScrollBar";
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "Scrolled" });
            return eventNames;
        }

        /// <summary>
        /// �б�󷽷�
        /// </summary>
        public virtual void lineAdd() {
            m_pos += m_lineSize;
            if (m_pos > m_contentSize - m_pageSize) {
                m_pos = m_contentSize - m_pageSize;
            }
            update();
            onScrolled();
        }

        /// <summary>
        /// �б�С����
        /// </summary>
        public virtual void lineReduce() {
            m_pos -= m_lineSize;
            if (m_pos < 0) {
                m_pos = 0;
            }
            update();
            onScrolled();
        }

        /// <summary>
        /// ����������ť�����¼�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onAddButtonTouchDown(FCTouchInfo touchInfo) {
            lineAdd();
            IsAdding = true;
        }

        /// <summary>
        /// ����������ţ̌���¼�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onAddButtonTouchUp(FCTouchInfo touchInfo) {
            IsAdding = false;
        }

        /// <summary>
        /// ���ٹ�������
        /// </summary>
        public virtual void onAddSpeedScrollEnd() {
        }

        /// <summary>
        /// �Զ����ٹ�����ʼ
        /// </summary>
        public virtual void onAddSpeedScrollStart(long startTime, long nowTime, int start, int end) {
            int diff = (int)((nowTime - startTime) / 10000);
            if (diff > 0 && diff < 800) {
                int sub = 5000 * (Math.Abs(start - end) / 20) / diff;
                if (start > end) {
                    AddSpeed += sub;
                }
                else if (start < end) {
                    AddSpeed += -sub;
                }
            }
        }

        /// <summary>
        /// �Զ����ٹ�����
        /// </summary>
        public virtual int onAddSpeedScrolling() {
            int sub = m_addSpeed / 10;
            if (sub == 0) {
                sub = m_addSpeed > 0 ? 1 : -1;
            }
            return sub;
        }

        /// <summary>
        /// �϶���������
        /// </summary>
        public virtual void onDragScroll() {
            if (m_scrollButton.Left < 0) {
                m_scrollButton.Left = 0;
            }
            if (m_scrollButton.Top < 0) {
                m_scrollButton.Top = 0;
            }
            if (m_scrollButton.Right > m_backButton.Width) {
                m_scrollButton.Left = m_backButton.Width - m_scrollButton.Width;
            }
            if (m_scrollButton.Bottom > m_backButton.Height) {
                m_scrollButton.Top = m_backButton.Height - m_scrollButton.Height;
            }
        }

        /// <summary>
        /// �ؼ���ӷ���
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            //��Ӱ�ť
            FCHost host = Native.Host;
            if (m_addButton == null) {
                m_addButton = host.createInternalControl(this, "addbutton") as FCButton;
                m_addButton.addEvent(m_addButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                m_addButton.addEvent(m_addButtonTouchUpEvent, FCEventID.TOUCHUP);
                addControl(m_addButton);
            }
            if (m_backButton == null) {
                m_backButton = host.createInternalControl(this, "backbutton") as FCButton;
                addControl(m_backButton);
            }
            if (m_reduceButton == null) {
                m_reduceButton = host.createInternalControl(this, "reducebutton") as FCButton;
                m_reduceButton.addEvent(m_reduceButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                m_reduceButton.addEvent(m_reduceButtonTouchUpEvent, FCEventID.TOUCHUP);
                addControl(m_reduceButton);
            }
            if (m_scrollButton == null) {
                m_scrollButton = host.createInternalControl(this, "scrollbutton") as FCButton;
                m_scrollButton.AllowDrag = true;
                m_scrollButton.addEvent(m_scrollButtonDraggingEvent, FCEventID.DRAGGING);
                m_backButton.addControl(m_scrollButton);
            }
        }

        /// <summary>
        /// ����������ť�����¼�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onReduceButtonTouchDown(FCTouchInfo touchInfo) {
            lineReduce();
            IsReducing = true;
        }

        /// <summary>
        /// ����������ţ̌���¼��ص�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onReduceButtonTouchUp(FCTouchInfo touchInfo) {
            IsReducing = false;
        }

        /// <summary>
        /// ��������
        /// </summary>
        public virtual void onScrolled() {
            callEvents(FCEventID.SCROLLED);
            FCView parent = Parent;
            if (parent != null) {
                parent.invalidate();
            }
        }

        /// <summary>
        /// ���ص�����
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID) {
            base.onTimer(timerID);
            if (m_timerID == timerID) {
                if (m_isAdding) {
                    if (m_tick > 5) {
                        pageAdd();
                    }
                    else {
                        lineAdd();
                    }
                }
                if (m_isReducing) {
                    if (m_tick > 5) {
                        pageReduce();
                    }
                    else {
                        lineReduce();
                    }
                }
                if (m_addSpeed != 0) {
                    int sub = onAddSpeedScrolling();
                    Pos += sub;
                    update();
                    onScrolled();
                    m_addSpeed -= sub;
                    if (Math.Abs(m_addSpeed) < 3) {
                        m_addSpeed = 0;
                    }
                    if (m_addSpeed == 0) {
                        onAddSpeedScrollEnd();
                        stopTimer(m_timerID);
                        if (Parent != null) {
                            Parent.invalidate();
                        }
                    }
                }
                m_tick++;
            }
        }

        /// <summary>
        /// �ɼ�״̬�ı䷽��
        /// </summary>
        public override void onVisibleChanged() {
            base.onVisibleChanged();
            if (!Visible) {
                m_pos = 0;
            }
        }

        /// <summary>
        /// ҳ��󷽷�
        /// </summary>
        public virtual void pageAdd() {
            m_pos += m_pageSize;
            if (m_pos > m_contentSize - m_pageSize) {
                m_pos = m_contentSize - m_pageSize;
            }
            update();
            onScrolled();
        }

        /// <summary>
        /// ҳ��С����
        /// </summary>
        public virtual void pageReduce() {
            m_pos -= m_pageSize;
            if (m_pos < 0) {
                m_pos = 0;
            }
            update();
            onScrolled();
        }

        /// <summary>
        /// ����������ť�����¼��ص�����
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void reduceButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            onReduceButtonTouchDown(touchInfo);
        }

        /// <summary>
        /// ����������ţ̌���¼��ص�����
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void reduceButtonTouchUp(object sender, FCTouchInfo touchInfo) {
            onReduceButtonTouchUp(touchInfo);
        }

        /// <summary>
        /// ������ť���϶��¼��ص�����
        /// </summary>
        /// <param name="sender">������</param>
        public void scrollButtonDragging(object sender) {
            onDragScroll();
        }

        /// <summary>
        /// ��������ʼ
        /// </summary>
        public void scrollToBegin() {
            m_pos = 0;
            update();
            onScrolled();
        }

        /// <summary>
        /// ����������
        /// </summary>
        public void scrollToEnd() {
            m_pos = m_contentSize - m_pageSize;
            if (m_pos < 0) {
                m_pos = 0;
            }
            update();
            onScrolled();
        }
    }
}
