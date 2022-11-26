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

namespace FaceCat {
    /// <summary>
    /// �ؼ��¼�
    /// </summary>
    /// <param name="sender">������</param>
    /// <param name="cancel">�Ƿ��˳�</param>
    public delegate void FCWindowClosingEvent(object sender, ref bool cancel);

    /// <summary>
    /// ����ؼ�
    /// </summary>
    public class FCWindow : FCView {
        /// <summary>
        /// ��������ؼ�
        /// </summary>
        public FCWindow() {
            AllowDrag = true;
            IsWindow = true;
            Visible = false;
        }

        /// <summary>
        /// �����ߴ�ĵ�
        /// </summary>
        private int m_resizePoint = -1;

        /// <summary>
        /// �ƶ���ʼ��
        /// </summary>
        private FCPoint m_startTouchPoint;

        /// <summary>
        /// �ƶ���ʼʱ�Ŀؼ�����
        /// </summary>
        private FCRect m_startRect;

        protected int m_borderWidth = 2;

        /// <summary>
        /// ��ȡ�����ñ߿�Ŀ��
        /// </summary>
        public virtual int BorderWidth {
            get { return m_borderWidth; }
            set { m_borderWidth = value; }
        }

        protected bool m_canResize = false;

        /// <summary>
        /// ��ȡ�������Ƿ���Ե����ߴ�
        /// </summary>
        public virtual bool CanResize {
            get { return m_canResize; }
            set { m_canResize = value; }
        }

        protected int m_captionHeight = 20;

        /// <summary>
        /// ��ȡ�����ñ������ĸ߶�
        /// </summary>
        public virtual int CaptionHeight {
            get { return m_captionHeight; }
            set { m_captionHeight = value; }
        }

        /// <summary>
        /// ��ȡ�ͻ��˵�����
        /// </summary>
        public virtual FCRect ClientSize {
            get {
                int width = Width, height = Height - m_captionHeight;
                if (height < 0) {
                    height = 0;
                }
                return new FCRect(0, m_captionHeight, width, height);
            }
        }

        protected FCWindowFrame m_frame;

        /// <summary>
        /// ��ȡ�����ô����
        /// </summary>
        public virtual FCWindowFrame Frame {
            get { return m_frame; }
            set { m_frame = value; }
        }

        protected bool m_isDialog;

        /// <summary>
        /// ��ȡ�������Ƿ�Ự����
        /// </summary>
        public virtual bool IsDialog {
            get { return m_isDialog; }
        }

        protected long m_shadowColor = FCColor.argb(25, 255, 255, 255);

        /// <summary>
        /// ��ȡ��������Ӱ����ɫ
        /// </summary>
        public virtual long ShadowColor {
            get { return m_shadowColor; }
            set { m_shadowColor = value; }
        }

        protected int m_shadowSize = 10;

        /// <summary>
        /// ��ȡ��������Ӱ�Ĵ�С
        /// </summary>
        public virtual int ShadowSize {
            get { return m_shadowSize; }
            set { m_shadowSize = value; }
        }

        /// <summary>
        /// ���ؼ��ŵ���ǰ��ʾ
        /// </summary>
        public override void bringToFront() {
            base.bringToFront();
            if (m_frame != null) {
                m_frame.bringToFront();
            }
        }

        /// <summary>
        /// �����¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <param name="cancel">�Ƿ��˳�</param>
        protected void callWindowClosingEvents(int eventID, ref bool cancel) {
            if (m_events != null && m_events.containsKey(eventID)) {
                ArrayList<object> events = m_events[eventID];
                int eventSize = events.size();
                for (int i = 0; i < eventSize; i++) {
                    FCWindowClosingEvent func = events.get(i) as FCWindowClosingEvent;
                    if (func != null) {
                        func(this, ref cancel);
                    }
                }
            }
        }

        /// <summary>
        /// �رմ���
        /// </summary>
        public virtual void close() {
            bool cancel = false;
            onWindowClosing(ref cancel);
            if (!cancel) {
                if (m_frame != null) {
                    m_frame.removeControl(this);
                    Native.removeControl(m_frame);
                    m_frame.delete();
                    m_frame = null;
                    Parent = null;
                }
                else {
                    Native.removeControl(this);
                }
                onWindowClosed();
            }
        }

        /// <summary>
        /// ���ٿؼ�����
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_frame != null) {
                    m_frame.removeControl(this);
                    Native.removeControl(m_frame);
                    m_frame.delete();
                    m_frame = null;
                }
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns></returns>
        public override String getControlType() {
            return "Window";
        }

        /// <summary>
        /// ��ȡ��̬��ͼ����
        /// </summary>
        /// <returns>����</returns>
        public FCRect getDynamicPaintRect() {
            FCSize oldSize = m_oldSize;
            if (oldSize.cx == 0 && oldSize.cy == 0) {
                oldSize = Size;
            }
            FCRect oldRect = new FCRect(m_oldLocation.x, m_oldLocation.y, m_oldLocation.x + oldSize.cx, m_oldLocation.y + oldSize.cy);
            FCRect rect = new FCRect(m_location.x, m_location.y, m_location.x + Width, m_location.y + Height);
            FCRect paintRect = new FCRect(Math.Min(oldRect.left, rect.left) - m_shadowSize - 10,
            Math.Min(oldRect.top, rect.top) - m_shadowSize - 10,
            Math.Max(oldRect.right, rect.right) + m_shadowSize + 10,
            Math.Max(oldRect.bottom, rect.bottom) + m_shadowSize + 10);
            return paintRect;
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "WindowClosed", "WindowClosing" });
            return eventNames;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        /// <param name="type">����</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "borderwidth") {
                type = "int";
                value = FCStr.convertIntToStr(BorderWidth);
            }
            else if (name == "canresize") {
                type = "bool";
                value = FCStr.convertBoolToStr(CanResize);
            }
            else if (name == "captionheight") {
                type = "int";
                value = FCStr.convertIntToStr(CaptionHeight);
            }
            else if (name == "shadowcolor") {
                type = "color";
                value = FCStr.convertColorToStr(ShadowColor);
            }
            else if (name == "shadowsize") {
                type = "int";
                value = FCStr.convertIntToStr(ShadowSize);
            }
            else {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ�����б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "BorderWidth", "CanResize", "CaptionHeight", "ShadowColor", "ShadowSize" });
            return propertyNames;
        }

        /// <summary>
        /// ��ȡ����״̬
        /// </summary>
        /// <param name="state">״ֵ̬</param>
        /// <returns>����״̬</returns>
        protected FCCursors getResizeCursor(int state) {
            switch (state) {
                case 0:
                    return FCCursors.SizeNWSE;
                case 1:
                    return FCCursors.SizeNESW;
                case 2:
                    return FCCursors.SizeNESW;
                case 3:
                    return FCCursors.SizeNWSE;
                case 4:
                    return FCCursors.SizeWE;
                case 5:
                    return FCCursors.SizeNS;
                case 6:
                    return FCCursors.SizeWE;
                case 7:
                    return FCCursors.SizeNS;
                default:
                    return FCCursors.Arrow;
            }
        }

        /// <summary>
        /// ��ȡ�����ߴ�ĵ�
        /// </summary>
        /// <returns>���μ���</returns>
        protected FCRect[] getResizePoints() {
            int width = Width, height = Height;
            FCRect[] points = new FCRect[8];
            //����
            points[0] = new FCRect(0, 0, m_borderWidth * 2, m_borderWidth * 2);
            //����
            points[1] = new FCRect(0, height - m_borderWidth * 2, m_borderWidth * 2, height);
            //����
            points[2] = new FCRect(width - m_borderWidth * 2, 0, width, m_borderWidth * 2);
            //����
            points[3] = new FCRect(width - m_borderWidth * 2, height - m_borderWidth * 2, width, height);
            //��
            points[4] = new FCRect(0, 0, m_borderWidth, height);
            //��
            points[5] = new FCRect(0, 0, width, m_borderWidth);
            //��
            points[6] = new FCRect(width - m_borderWidth, 0, width, height);
            //��
            points[7] = new FCRect(0, height - m_borderWidth, width, height);
            return points;
        }

        /// <summary>
        /// ��ȡ�����ߴ��״̬
        /// </summary>
        /// <returns>״̬</returns>
        protected int getResizeState() {
            FCPoint mp = TouchPoint;
            FCRect[] pRects = getResizePoints();
            int rsize = pRects.Length;
            for (int i = 0; i < rsize; i++) {
                FCRect rect = pRects[i];
                if (mp.x >= rect.left && mp.x <= rect.right
                    && mp.y >= rect.top && mp.y <= rect.bottom) {
                    return i;
                }
            }
            return -1;
        }

        /// <summary>
        /// ������ʼ����
        /// </summary>
        /// <returns>�Ƿ��Ѵ���</returns>
        public override bool onDragBegin() {
            FCPoint mp = TouchPoint;
            int width = Width, height = Height;
            if (mp.y > m_captionHeight) {
                return false;
            }
            if (m_resizePoint != -1) {
                return false;
            }
            return base.onDragBegin();
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
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            //ѡ�е�
            if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1) {
                if (m_canResize) {
                    m_resizePoint = getResizeState();
                    Cursor = getResizeCursor(m_resizePoint);
                    m_startTouchPoint = Native.TouchPoint;
                    m_startRect = Bounds;
                }
            }
            invalidate();
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
            if (m_canResize) {
                FCPoint nowPoint = Native.TouchPoint;
                if (m_resizePoint != -1) {
                    int left = m_startRect.left, top = m_startRect.top, right = m_startRect.right, bottom = m_startRect.bottom;
                    windowResize(m_resizePoint, ref left, ref top, ref right, ref bottom, ref nowPoint, ref m_startTouchPoint);
                    FCRect bounds = new FCRect(left, top, right, bottom);
                    Bounds = bounds;
                    Native.invalidate();
                }
                else {
                    Cursor = getResizeCursor(getResizeState());
                }
            }
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInfo) {
            base.onTouchUp(touchInfo);
            m_resizePoint = -1;
            invalidate();
        }

        /// <summary>
        /// ����ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            String text = Text;
            if (text != null && text.Length > 0) {
                int width = Width;
                FCFont font = Font;
                FCSize tSize = paint.textSize(text, font);
                FCPoint strPoint = new FCPoint();
                strPoint.x = 5;
                strPoint.y = (m_captionHeight - tSize.cy) / 2;
                FCRect tRect = new FCRect(strPoint.x, strPoint.y, strPoint.x + tSize.cx, strPoint.y + tSize.cy);
                paint.drawText(text, getPaintingTextColor(), font, tRect);
            }
        }

        /// <summary>
        /// �ɼ�״̬�ı䷽��
        /// </summary>
        public override void onVisibleChanged() {
            base.onVisibleChanged();
            FCNative native = Native;
            if (native != null) {
                if (Visible) {
                    if (m_frame == null) {
                        m_frame = new FCWindowFrame();
                    }
                    native.removeControl(this);
                    native.addControl(m_frame);
                    m_frame.Size = native.DisplaySize;
                    if (!m_frame.containsControl(this)) {
                        m_frame.addControl(this);
                    }
                }
                else {
                    if (m_frame != null) {
                        m_frame.removeControl(this);
                        native.removeControl(m_frame);
                    }
                }
            }
        }

        /// <summary>
        /// �������ڹرշ���
        /// </summary>
        /// <param name="cancel">�Ƿ��˳�</param>
        public virtual void onWindowClosing(ref bool cancel) {
            callWindowClosingEvents(FCEventID.WINDOWCLOSING, ref cancel);
        }

        /// <summary>
        /// ����رշ���
        /// </summary>
        public virtual void onWindowClosed() {
            callEvents(FCEventID.WINDOWCLOSED);
        }

        /// <summary>
        /// ���ؼ��ŵ���������ʾ
        /// </summary>
        public override void sendToBack() {
            base.sendToBack();
            if (m_frame != null) {
                m_frame.sendToBack();
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "borderwidth") {
                BorderWidth = FCStr.convertStrToInt(value);
            }
            else if (name == "canresize") {
                CanResize = FCStr.convertStrToBool(value);
            }
            else if (name == "captionheight") {
                CaptionHeight = FCStr.convertStrToInt(value);
            }
            else if (name == "shadowcolor") {
                ShadowColor = FCStr.convertStrToColor(value);
            }
            else if (name == "shadowsize") {
                ShadowSize = FCStr.convertStrToInt(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// �ԻỰ��ʽ��ʾ
        /// </summary>
        public virtual void showDialog() {
            m_isDialog = true;
            show();
        }

        /// <summary>
        /// ����ߴ�ı�
        /// </summary>
        /// <param name="resizePoint"></param>
        /// <param name="left"></param>
        /// <param name="top"></param>
        /// <param name="right"></param>
        /// <param name="bottom"></param>
        /// <param name="nowPoint"></param>
        /// <param name="startTouchPoint"></param>
        public virtual void windowResize(int resizePoint, ref int left, ref int top, ref int right, ref int bottom, ref FCPoint nowPoint, ref FCPoint startTouchPoint) {
            switch (resizePoint) {
                case 0:
                    left = left + nowPoint.x - startTouchPoint.x;
                    top = top + nowPoint.y - startTouchPoint.y;
                    break;
                case 1:
                    left = left + nowPoint.x - startTouchPoint.x;
                    bottom = bottom + nowPoint.y - startTouchPoint.y;
                    break;
                case 2:
                    right = right + nowPoint.x - startTouchPoint.x;
                    top = top + nowPoint.y - startTouchPoint.y;
                    break;
                case 3:
                    right = right + nowPoint.x - startTouchPoint.x;
                    bottom = bottom + nowPoint.y - startTouchPoint.y;
                    break;
                case 4:
                    left = left + nowPoint.x - startTouchPoint.x;
                    break;
                case 5:
                    top = top + nowPoint.y - startTouchPoint.y;
                    break;
                case 6:
                    right = right + nowPoint.x - startTouchPoint.x;
                    break;
                case 7:
                    bottom = bottom + nowPoint.y - startTouchPoint.y;
                    break;
            }
        }
    }
}
