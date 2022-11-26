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
    /// ͼ��
    /// </summary>
    public class FCDiv : FCView {
        /// <summary>
        /// ����֧�ֹ������Ŀؼ�
        /// </summary>
        public FCDiv() {
            m_scrollButtonKeyDownEvent = new FCKeyEvent(scrollButtonKeyDown);
            m_scrollButtonTouchWheelEvent = new FCTouchEvent(scrollButtonTouchWheel);
            FCSize size = new FCSize(200, 200);
            Size = size;
        }

        /// <summary>
        /// �Ƿ����ڹ���2
        /// </summary>
        private bool m_isDragScrolling2;

        /// <summary>
        /// �Ƿ�׼���϶�����
        /// </summary>
        private bool m_readyToDragScroll;

        /// <summary>
        /// ������ť�����¼������¼�
        /// </summary>
        private FCKeyEvent m_scrollButtonKeyDownEvent;

        /// <summary>
        /// ������ť���������¼�
        /// </summary>
        private FCTouchEvent m_scrollButtonTouchWheelEvent;

        /// <summary>
        /// ��ʼ�ƶ���λ��
        /// </summary>
        private FCPoint m_startMovePoint;

        /// <summary>
        /// ��ʼ�ƶ��ĺ���λ��
        /// </summary>
        private int m_startMovePosX;

        /// <summary>
        /// ��ʼ�ƶ�������λ��
        /// </summary>
        private int m_startMovePosY;

        /// <summary>
        /// ��ʼ�ƶ�ʱ��
        /// </summary>
        private DateTime m_startMoveTime;

        protected bool m_allowDragScroll = false;

        /// <summary>
        /// ��ȡ�������Ƿ������϶�����
        /// </summary>
        public virtual bool AllowDragScroll {
            get { return m_allowDragScroll; }
            set { m_allowDragScroll = value; }
        }

        protected FCHScrollBar m_hScrollBar;

        /// <summary>
        /// ��ȡ���������
        /// </summary>
        public virtual FCHScrollBar HScrollBar {
            get {
                if (Native != null && m_showHScrollBar) {
                    if (m_hScrollBar == null) {
                        FCHost host = Native.Host;
                        m_hScrollBar = host.createInternalControl(this, "hscrollbar") as FCHScrollBar;
                        addControl(m_hScrollBar);
                        //ע�ᰴť���¼�
                        m_hScrollBar.AddButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_hScrollBar.AddButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                        m_hScrollBar.BackButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_hScrollBar.BackButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                        m_hScrollBar.ReduceButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_hScrollBar.ReduceButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                        m_hScrollBar.ScrollButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_hScrollBar.ScrollButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                    }
                    return m_hScrollBar;
                }
                return null;
            }
        }

        protected bool m_showHScrollBar = false;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ���������
        /// </summary>
        public virtual bool ShowHScrollBar {
            get { return m_showHScrollBar; }
            set { m_showHScrollBar = value; }
        }

        private bool m_isDragScrolling;

        /// <summary>
        /// ��ȡ�Ƿ����ڱ��϶�
        /// </summary>
        public virtual bool IsDragScrolling {
            get { return m_isDragScrolling; }
        }

        protected bool m_showVScrollBar = false;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ���������
        /// </summary>
        public virtual bool ShowVScrollBar {
            get { return m_showVScrollBar; }
            set { m_showVScrollBar = value; }
        }

        protected FCVScrollBar m_vScrollBar;

        /// <summary>
        /// ��ȡ���������
        /// </summary>
        public virtual FCVScrollBar VScrollBar {
            get {
                if (Native != null && m_showVScrollBar) {
                    if (m_vScrollBar == null) {
                        FCHost host = Native.Host;
                        m_vScrollBar = host.createInternalControl(this, "vscrollbar") as FCVScrollBar;
                        addControl(m_vScrollBar);
                        //ע�ᰴť���¼�
                        m_vScrollBar.AddButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_vScrollBar.AddButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                        m_vScrollBar.BackButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_vScrollBar.BackButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                        m_vScrollBar.ReduceButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_vScrollBar.ReduceButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                        m_vScrollBar.ScrollButton.addEvent(m_scrollButtonKeyDownEvent, FCEventID.KEYDOWN);
                        m_vScrollBar.ScrollButton.addEvent(m_scrollButtonTouchWheelEvent, FCEventID.TOUCHWHEEL);
                    }
                    return m_vScrollBar;
                }
                return null;
            }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                m_scrollButtonKeyDownEvent = null;
                m_scrollButtonTouchWheelEvent = null;
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ���ݵĸ߶�
        /// </summary>
        /// <returns>�߶�</returns>
        public virtual int getContentHeight() {
            FCHScrollBar hScrollBar = HScrollBar;
            FCVScrollBar vScrollBar = VScrollBar;
            int hmax = 0;
            ArrayList<FCView> controls = m_controls;
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls[i];
                if (control.Visible && control != hScrollBar && control != vScrollBar) {
                    int bottom = control.Bottom;
                    if (bottom > hmax) {
                        hmax = bottom;
                    }
                }
            }
            return hmax;
        }

        /// <summary>
        /// ��ȡ���ݵĿ��
        /// </summary>
        /// <returns>���</returns>
        public virtual int getContentWidth() {
            FCHScrollBar hScrollBar = HScrollBar;
            FCVScrollBar vScrollBar = VScrollBar;
            int wmax = 0;
            ArrayList<FCView> controls = m_controls;
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls[i];
                if (control.Visible && control != hScrollBar && control != vScrollBar) {
                    int right = control.Right;
                    if (right > wmax) {
                        wmax = right;
                    }
                }
            }
            return wmax;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "Div";
        }

        /// <summary>
        /// ��ȡ��ʾƫ������
        /// </summary>
        /// <returns>����</returns>
        public override FCPoint getDisplayOffset() {
            FCPoint offset = new FCPoint();
            if (Visible) {
                offset.x = (m_hScrollBar != null && m_hScrollBar.Visible) ? m_hScrollBar.Pos : 0;
                offset.y = (m_vScrollBar != null && m_vScrollBar.Visible) ? m_vScrollBar.Pos : 0;
            }
            return offset;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "allowdragscroll") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowDragScroll);
            }
            else if (name == "showhscrollbar") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowHScrollBar);
            }
            else if (name == "showvscrollbar") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowVScrollBar);
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
            propertyNames.AddRange(new String[] { "AllowDragScroll", "ShowHScrollBar", "ShowVScrollBar" });
            return propertyNames;
        }

        /// <summary>
        /// ���¹���һ��
        /// </summary>
        public virtual void lineDown() {
            if (m_vScrollBar != null && m_vScrollBar.Visible) {
                m_vScrollBar.lineAdd();
            }
        }

        /// <summary>
        /// �������һ��
        /// </summary>
        public virtual void lineLeft() {
            if (m_hScrollBar != null && m_hScrollBar.Visible) {
                m_hScrollBar.lineReduce();
            }
        }

        /// <summary>
        /// ���ҹ���һ��
        /// </summary>
        public virtual void LineRight() {
            if (m_hScrollBar != null && m_hScrollBar.Visible) {
                m_hScrollBar.lineAdd();
            }
        }

        /// <summary>
        /// ���Ϲ���һ��
        /// </summary>
        public virtual void lineUp() {
            if (m_vScrollBar != null && m_vScrollBar.Visible) {
                m_vScrollBar.lineReduce();
            }
        }

        /// <summary>
        /// �϶�׼������
        /// </summary>
        /// <param name="startOffset">�����϶���ƫ��������</param>
        public override void onDragReady(ref FCPoint startOffset) {
            startOffset.x = 0;
            startOffset.y = 0;
        }

        /// <summary>
        /// �϶���������
        /// </summary>
        public virtual void onDragScrollEnd() {
            m_isDragScrolling = false;
            if (m_readyToDragScroll) {
                DateTime nowTime = DateTime.Now;
                FCPoint newPoint = Native.TouchPoint;
                if (m_hScrollBar != null && m_hScrollBar.Visible) {
                    m_hScrollBar.onAddSpeedScrollStart(m_startMoveTime.Ticks, nowTime.Ticks, m_startMovePoint.x, newPoint.x);
                }
                if (m_vScrollBar != null && m_vScrollBar.Visible) {
                    m_vScrollBar.onAddSpeedScrollStart(m_startMoveTime.Ticks, nowTime.Ticks, m_startMovePoint.y, newPoint.y);
                }
                m_readyToDragScroll = false;
                invalidate();
            }
        }

        /// <summary>
        /// �϶�������
        /// </summary>
        public virtual void onDragScrolling() {
            int width = Width, height = Height;
            if (m_allowDragScroll && m_readyToDragScroll) {
                if (!onDragScrollPermit()) {
                    m_readyToDragScroll = false;
                    return;
                }
                bool paint = false;
                FCPoint newPoint = Native.TouchPoint;
                if (m_hScrollBar != null && m_hScrollBar.Visible) {
                    if (Math.Abs(newPoint.x - m_startMovePoint.x) > width / 10) {
                        m_isDragScrolling2 = true;
                    }
                    int newPos = m_startMovePosX + m_startMovePoint.x - newPoint.x;
                    if (newPos != m_hScrollBar.Pos) {
                        m_hScrollBar.Pos = newPos;
                        m_hScrollBar.update();
                        paint = true;
                    }
                }
                if (m_vScrollBar != null && m_vScrollBar.Visible) {
                    if (Math.Abs(newPoint.y - m_startMovePoint.y) > height / 10) {
                        m_isDragScrolling2 = true;
                    }
                    int newPos = m_startMovePosY + m_startMovePoint.y - newPoint.y;
                    if (newPos != m_vScrollBar.Pos) {
                        m_vScrollBar.Pos = newPos;
                        m_vScrollBar.update();
                        paint = true;
                    }
                }
                if (paint) {
                    m_isDragScrolling = true;
                    invalidate();
                }
            }
        }

        /// <summary>
        /// �϶�������ɼ��
        /// </summary>
        public virtual bool onDragScrollPermit() {
            FCView focusedControl = Native.FocusedControl;
            if (focusedControl != null) {
                if (focusedControl.IsDragging) {
                    return false;
                }
                if (focusedControl is FCGridColumn) {
                    return false;
                }
                if (focusedControl.Parent != null) {
                    if (focusedControl.Parent is FCScrollBar) {
                        return false;
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// �϶�������ʼ
        /// </summary>
        public virtual void onDragScrollStart() {
            m_isDragScrolling = false;
            m_isDragScrolling2 = false;
            FCView focusedControl = Native.FocusedControl;
            if (m_hScrollBar != null && m_hScrollBar.Visible) {
                if (focusedControl == m_hScrollBar.AddButton
                    || focusedControl == m_hScrollBar.ReduceButton
                    || focusedControl == m_hScrollBar.BackButton
                    || focusedControl == m_hScrollBar.ScrollButton) {
                    m_hScrollBar.AddSpeed = 0;
                    return;
                }
            }
            if (m_vScrollBar != null && m_vScrollBar.Visible) {
                if (focusedControl == m_vScrollBar.AddButton
             || focusedControl == m_vScrollBar.ReduceButton
             || focusedControl == m_vScrollBar.BackButton
             || focusedControl == m_vScrollBar.ScrollButton) {
                    m_vScrollBar.AddSpeed = 0;
                    return;
                }
            }
            if (m_allowDragScroll) {
                if (m_hScrollBar != null && m_hScrollBar.Visible) {
                    m_startMovePosX = m_hScrollBar.Pos;
                    m_hScrollBar.AddSpeed = 0;
                    m_readyToDragScroll = true;
                }
                if (m_vScrollBar != null && m_vScrollBar.Visible) {
                    m_startMovePosY = m_vScrollBar.Pos;
                    m_vScrollBar.AddSpeed = 0;
                    m_readyToDragScroll = true;
                }
                if (m_readyToDragScroll) {
                    m_startMovePoint = Native.TouchPoint;
                    m_startMoveTime = DateTime.Now;
                }
            }
        }

        /// <summary>
        /// ���̰��·���
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyDown(char key) {
            base.onKeyDown(key);
            FCHost host = Native.Host;
            if (!host.isKeyPress(0x10) && !host.isKeyPress(0x11) && !host.isKeyPress(0x12)) {
                //����
                if (key == 38) {
                    lineUp();
                }
                //����
                else if (key == 40) {
                    lineDown();
                }
                invalidate();
            }
        }

        /// <summary>
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            if (!m_allowPreviewsEvent) {
                onDragScrollStart();
            }
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
            if (!m_allowPreviewsEvent) {
                onDragScrolling();
            }
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInfo) {
            base.onTouchUp(touchInfo);
            if (!m_allowPreviewsEvent) {
                onDragScrollEnd();
            }
        }

        /// <summary>
        /// ������������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchWheel(FCTouchInfo touchInfo) {
            base.onTouchWheel(touchInfo);
            if (touchInfo.m_delta > 0) {
                lineUp();
                invalidate();
            }
            else if (touchInfo.m_delta < 0) {
                lineDown();
                invalidate();
            }
        }

        /// <summary>
        /// Ԥ�������¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <param name="touchInfo">������Ϣ</param>
        /// <returns>״̬</returns>
        public override bool onPreviewsTouchEvent(int eventID, FCTouchInfo touchInfo) {
            if (callPreviewsTouchEvents(FCEventID.PREVIEWSTOUCHEVENT, eventID, touchInfo)) {
                return true;
            }
            if (m_allowPreviewsEvent) {
                if (eventID == FCEventID.TOUCHDOWN) {
                    onDragScrollStart();
                }
                else if (eventID == FCEventID.TOUCHMOVE) {
                    onDragScrolling();
                }
                else if (eventID == FCEventID.TOUCHUP) {
                    bool state = m_isDragScrolling;
                    onDragScrollEnd();
                    if (state && !m_isDragScrolling2) {
                        return false;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// ���·�һҳ
        /// </summary>
        public virtual void pageDown() {
            if (m_vScrollBar != null && m_vScrollBar.Visible) {
                m_vScrollBar.pageAdd();
            }
        }

        /// <summary>
        /// ����һҳ
        /// </summary>
        public virtual void pageLeft() {
            if (m_hScrollBar != null && m_hScrollBar.Visible) {
                m_hScrollBar.pageReduce();
            }
        }

        /// <summary>
        /// ���ҷ�һҳ
        /// </summary>
        public virtual void pageRight() {
            if (m_hScrollBar != null && m_hScrollBar.Visible) {
                m_hScrollBar.pageAdd();
            }
        }

        /// <summary>
        /// ���Ϸ�һҳ
        /// </summary>
        public virtual void pageUp() {
            if (m_vScrollBar != null && m_vScrollBar.Visible) {
                m_vScrollBar.pageReduce();
            }
        }

        /// <summary>
        /// ������ť���̰����¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="key">����</param>
        protected void scrollButtonKeyDown(object sender, char key) {
            onKeyDown(key);
        }

        /// <summary>
        /// ������ť���������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        protected void scrollButtonTouchWheel(object sender, FCTouchInfo touchInfo) {
            FCTouchInfo newTouchInfo = touchInfo.clone();
            newTouchInfo.m_firstPoint = TouchPoint;
            newTouchInfo.m_secondPoint = TouchPoint;
            onTouchWheel(newTouchInfo);
        }

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "allowdragscroll") {
                AllowDragScroll = FCStr.convertStrToBool(value);
            }
            else if (name == "showhscrollbar") {
                ShowHScrollBar = FCStr.convertStrToBool(value);
            }
            else if (name == "showvscrollbar") {
                ShowVScrollBar = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public override void update() {
            base.update();
            updateScrollBar();
        }

        /// <summary>
        /// ���¹������Ĳ���
        /// </summary>
        public virtual void updateScrollBar() {
            if (Native != null) {
                FCHScrollBar hScrollBar = HScrollBar;
                FCVScrollBar vScrollBar = VScrollBar;
                if (Visible) {
                    int width = Width, height = Height;
                    //�������ߴ�         
                    int hBarHeight = (hScrollBar != null) ? hScrollBar.Height : 0;
                    int vBarWidth = (vScrollBar != null) ? vScrollBar.Width : 0;
                    int wmax = getContentWidth(), hmax = getContentHeight();
                    if (hScrollBar != null) {
                        hScrollBar.ContentSize = wmax;
                        hScrollBar.Size = new FCSize(width - vBarWidth, hBarHeight);
                        hScrollBar.PageSize = width - vBarWidth;
                        hScrollBar.Location = new FCPoint(0, height - hBarHeight);
                        if (wmax <= width) {
                            hScrollBar.Visible = false;
                        }
                        else {
                            hScrollBar.Visible = true;
                        }
                    }
                    if (vScrollBar != null) {
                        vScrollBar.ContentSize = hmax;
                        vScrollBar.Size = new FCSize(vBarWidth, height - hBarHeight);
                        vScrollBar.PageSize = height - hBarHeight;
                        vScrollBar.Location = new FCPoint(width - vBarWidth, 0);
                        int vh = (hScrollBar != null && hScrollBar.Visible) ? height - hBarHeight : height;
                        if (hmax <= vh) {
                            vScrollBar.Visible = false;
                        }
                        else {
                            vScrollBar.Visible = true;
                        }
                    }
                    //�޸ĳߴ�
                    if (hScrollBar != null && vScrollBar != null) {
                        if (hScrollBar.Visible && !vScrollBar.Visible) {
                            hScrollBar.Width = width;
                            hScrollBar.PageSize = width;
                        }
                        else if (!hScrollBar.Visible && vScrollBar.Visible) {
                            vScrollBar.Height = height;
                            vScrollBar.PageSize = height;
                        }
                    }
                    if (hScrollBar != null && hScrollBar.Visible) {
                        hScrollBar.update();
                    }
                    if (vScrollBar != null && vScrollBar.Visible) {
                        vScrollBar.update();
                    }
                }
            }
        }
    }
}
