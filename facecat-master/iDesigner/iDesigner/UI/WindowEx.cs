/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using FaceCat;
using System.Drawing;

namespace FaceCat
{
    /// <summary>
    /// ����״̬
    /// </summary>
    public enum WindowStateA
    {
        /// <summary>
        /// ��ͨ
        /// </summary>
        Normal,
        /// <summary>
        /// ���
        /// </summary>
        Max,
        /// <summary>
        /// ��С��
        /// </summary>
        Min
    }

    /// <summary>
    /// �ػ洰��
    /// </summary>
    public class WindowEx : FCWindow
    {
        /// <summary>
        /// ��������
        /// </summary>
        public WindowEx()
        {
            BackColor = FCColor.None;
            BorderColor = FCDraw.FCCOLORS_LINECOLOR3;
            CaptionHeight = 25;
            Font = new FCFont("΢���ź�", 14, false, false, false);
            TextColor = FCColor.None;
            Opacity = 0;
            ShadowColor = FCDraw.FCCOLORS_BACKCOLOR5;
            ShadowSize = 0;
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        private int m_animateDirection = -1;

        /// <summary>
        /// ��������
        /// </summary>
        private int m_animateType = 0;

        /// <summary>
        /// ��ͨ�ߴ�
        /// </summary>
        private FCPoint m_normalLocation;

        /// <summary>
        /// ��ͨ�ߴ�
        /// </summary>
        private FCSize m_normalSize;

        /// <summary>
        /// �������
        /// </summary>
        private Random m_rd = new Random();

        /// <summary>
        /// ���ID
        /// </summary>
        private int m_timerID = FCView.getNewTimerID();

        private bool m_animateMoving;

        /// <summary>
        /// ��ȡ�Ƿ����ڶ����ƶ�
        /// </summary>
        public bool AnimateMoving
        {
            get { return m_animateMoving; }
        }

        private WindowButton m_closeButton;

        /// <summary>
        /// ��ȡ�����ùرհ�ť
        /// </summary>
        public WindowButton CloseButton
        {
            get { return m_closeButton; }
            set { m_closeButton = value; }
        }

        private bool m_isChildWindow;

        /// <summary>
        /// ��ȡ�������Ƿ��Ӵ���
        /// </summary>
        public bool IsChildWindow
        {
            get { return m_isChildWindow; }
            set { m_isChildWindow = value; }
        }

        private WindowButton m_maxOrRestoreButton;

        /// <summary>
        /// ��ȡ��������󻯰�ť
        /// </summary>
        public WindowButton MaxOrRestoreButton
        {
            get { return m_maxOrRestoreButton; }
            set { m_maxOrRestoreButton = value; }
        }

        private WindowButton m_minButton;

        /// <summary>
        /// ��ȡ��������С����ť
        /// </summary>
        public WindowButton MinButton
        {
            get { return m_minButton; }
            set { m_minButton = value; }
        }

        private bool m_showMaxBox = true;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ��󻯰�ť
        /// </summary>
        public bool ShowMaxBox
        {
            get { return m_showMaxBox; }
            set
            {
                m_showMaxBox = value;
                if (m_maxOrRestoreButton != null)
                {
                    m_maxOrRestoreButton.Visible = value;
                }
            }
        }

        private bool m_showMinBox = true;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾ��С����ť
        /// </summary>
        public bool ShowMinBox
        {
            get
            {
                return m_showMinBox;
            }
            set
            {
                m_showMinBox = value;
                if (m_minButton != null)
                {
                    m_minButton.Visible = value;
                }
            }
        }

        private WindowStateA m_windowState = WindowStateA.Normal;

        /// <summary>
        /// ��ȡ�����õ�ǰ��״̬
        /// </summary>
        public WindowStateA WindowState
        {
            get { return m_windowState; }
            set { m_windowState = value; }
        }

        /// <summary>
        /// �Զ�����ʽ����
        /// </summary>
        public void animateHide()
        {
            m_animateType = 1;
            FCNative native = Native;
            FCHost host = native.Host;
            m_animateDirection = m_rd.Next(0, 4);
            startTimer(m_timerID, 10);
            m_animateMoving = true;
            host.AllowOperate = false;
        }

        /// <summary>
        /// �Զ�����ʽ��ʾ
        /// </summary>
        /// <param name="showDialog">�Ƿ�Ի����</param>
        public void animateShow(bool showDialog)
        {
            m_animateType = 0;
            FCNative native = Native;
            FCHost host = native.Host;
            FCSize nativeSize = native.DisplaySize;
            int width = Width, height = Height, mx = (nativeSize.cx - width) / 2, my = (nativeSize.cy - height) / 2, x = mx, y = my;
            m_animateDirection = m_rd.Next(0, 4);
            switch (m_animateDirection)
            {
                case 0:
                    x = -width;
                    break;
                case 1:
                    x = nativeSize.cx;
                    break;
                case 2:
                    y = -height;
                    break;
                case 3:
                    y = nativeSize.cy;
                    break;
            }
            FCPoint location = new FCPoint(x, y);
            Location = location;
            if (showDialog)
            {
                base.showDialog();
            }
            else
            {
                show();
            }
            update();
            startTimer(m_timerID, 10);
            m_animateMoving = true;
            host.AllowOperate = false;
        }

        /// <summary>
        /// �����ť����
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="click">�������</param>
        /// <param name="delta">���ֹ���ֵ</param>
        private void clickButton(object sender, FCTouchInfo touchInto)
        {
            if (touchInto.m_firstTouch && touchInto.m_clicks == 1)
            {
                FCView control = sender as FCView;
                String name = control.Name;
                if (name == "btnMaxOrRestore")
                {
                    maxOrRestore();
                }
                else if (name == "btnMin")
                {
                    min();
                }
            }
        }

        /// <summary>
        /// ���ٿؼ�����
        /// </summary>
        public override void delete()
        {
            if (!IsDeleted)
            {
                m_animateMoving = false;
                stopTimer(m_timerID);
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="name">����</param>
        /// <param name="value">ֵ</param>
        /// <param name="type">����</param>
        public override void getProperty(String name, ref String value, ref String type)
        {
            if (name == "showmaxbox")
            {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowMaxBox);
            }
            else if (name == "showminbox")
            {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowMinBox);
            }
            else if (name == "windowstate")
            {
                type = "enum:WindowStateA";
                WindowStateA windowState = WindowState;
                if (windowState == WindowStateA.Max)
                {
                    value = "Max";
                }
                else if (windowState == WindowStateA.Min)
                {
                    value = "Min";
                }
                else if (windowState == WindowStateA.Normal)
                {
                    value = "Normal";
                }
            }
            else
            {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getPropertyNames()
        {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "ShowMaxBox", "ShowMinBox", "WindowState" });
            return propertyNames;
        }

        /// <summary>
        /// �ؼ���ӷ���
        /// </summary>
        public override void onAdd()
        {
            base.onAdd();
            if (m_closeButton == null)
            {
                m_closeButton = new WindowButton();
                m_closeButton.Name = "btnClose";
                FCSize buttonSize = new FCSize(20, 20);
                m_closeButton.Size = buttonSize;
                addControl(m_closeButton);
            }
            if (m_maxOrRestoreButton == null)
            {
                m_maxOrRestoreButton = new WindowButton();
                m_maxOrRestoreButton.Name = "btnMaxOrRestore";
                m_maxOrRestoreButton.Style = WindowButtonStyle.Max;
                FCSize buttonSize = new FCSize(20, 20);
                m_maxOrRestoreButton.Size = buttonSize;
                addControl(m_maxOrRestoreButton);
                m_maxOrRestoreButton.Visible = m_showMaxBox;
                m_maxOrRestoreButton.addEvent(new FCTouchEvent(clickButton), FCEventID.CLICK);
            }
            if (m_minButton == null)
            {
                m_minButton = new WindowButton();
                m_minButton.Name = "btnMin";
                m_minButton.Style = WindowButtonStyle.Min;
                FCSize buttonSize = new FCSize(20, 20);
                m_minButton.Size = buttonSize;
                addControl(m_minButton);
                m_minButton.Visible = m_showMinBox;
                m_minButton.addEvent(new FCTouchEvent(clickButton), FCEventID.CLICK);
            }
        }

        /// <summary>
        /// �϶���ʼ����
        /// </summary>
        /// <param name="startOffset">ƫ��������</param>
        public override void onDragReady(ref FCPoint startOffset)
        {
            startOffset.x = 0;
            startOffset.y = 0;
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            int width = Width;
            int height = Height;
            FCRect rect = new FCRect(0, 0, width, height);
            long backColor = FCDraw.FCCOLORS_WINDOWBACKCOLOR;
            long textColor = FCDraw.FCCOLORS_WINDOWTEXTCOLOR;
            if (paint.supportTransparent())
            {
                backColor = FCDraw.FCCOLORS_WINDOWBACKCOLOR2;
            }
            long borderColor = FCDraw.FCCOLORS_BACKCOLOR8;
            FCPoint[] points1 = new FCPoint[6];
            int dw1 = 30;
            int dw2 = 50;
            int dSize = 10;
            int dSize2 = 20;
            points1[0] = new FCPoint(dSize, dw1 + dSize);
            points1[1] = new FCPoint(dSize + dw1, dSize);
            points1[2] = new FCPoint(width - dSize, dSize);
            points1[3] = new FCPoint(width - dSize, height - dw2 - dSize2);
            points1[4] = new FCPoint(width - dSize - dw2, height - dSize2);
            points1[5] = new FCPoint(dSize, height - dSize2);
            if (FCDraw.m_style == 0)
            {
                paint.fillGradientPolygon(FCDraw.FCCOLORS_BACKCOLOR, FCDraw.FCCOLORS_BACKCOLOR2, points1, 45);
            }
            paint.fillPolygon(backColor, points1);
            paint.drawPolygon(borderColor, 3, 0, points1);
            paint.drawLine(borderColor, 2, 0, width - dSize - 30, 1, width - 1, 1);
            paint.drawLine(borderColor, 2, 0, width - 1, 1, width - 1, dSize * 2);
            paint.drawLine(borderColor, 2, 0, width - dSize - 20, dSize + 5, width - dSize - 5, dSize + 5);
            paint.drawLine(borderColor, 2, 0, width - dSize - 5, dSize + 5, width - dSize - 5, dSize + 20);
            FCPoint[] points2 = new FCPoint[4];
            points2[0] = new FCPoint(dSize + 10, dSize + dw1 + 30);
            points2[1] = new FCPoint(dSize + 10, dSize + dw1 + 2);
            points2[2] = new FCPoint(dSize + dw1 + 2, dSize + 10);
            points2[3] = new FCPoint(dSize + dw1 + 30, dSize + 10);
            paint.drawPolyline(borderColor, 2, 0, points2);
            paint.drawLine(borderColor, 2, 0, dSize + dw1 + 31, dSize + 10, dSize + dw1 + 50, dSize + 10);
            paint.drawLine(borderColor, 2, 0, dSize + dw1 + 10, dSize + 18, dSize + dw1 + 40, dSize + 18);
            paint.drawLine(borderColor, 2, 0, dSize + 10, height - dSize * 2 - 8, dSize + 60, height - dSize * 2 - 8);
            FCPoint[] points3 = new FCPoint[4];
            points3[0] = new FCPoint(dSize + 14, height - dSize2 - 8);
            points3[1] = new FCPoint(dSize + 18, height - dSize2 - 12);
            points3[2] = new FCPoint(dSize + 30, height - dSize2 - 12);
            points3[3] = new FCPoint(dSize + 34, height - dSize2 - 8);
            paint.fillPolygon(borderColor, points3);
            FCPoint[] points4 = new FCPoint[6];
            points4[0] = new FCPoint(dSize, height - dSize2 - 20);
            points4[1] = new FCPoint(dSize - 8, height - dSize2 - 10);
            points4[2] = new FCPoint(dSize - 8, height - 4 - dSize);
            points4[3] = new FCPoint(dSize + 16, height - 4 - dSize);
            points4[4] = new FCPoint(dSize + 20, height - dSize2);
            points4[5] = new FCPoint(dSize, height - dSize2);
            paint.fillPolygon(borderColor, points4);
            FCPoint[] points5 = new FCPoint[4];
            points5[0] = new FCPoint(width - dSize, height - dSize2 - dw2 - 20);
            points5[1] = new FCPoint(width - dSize - 4, height - dSize2 - dw2 - 16);
            points5[2] = new FCPoint(width - dSize - 4, height - dSize2 - dw2);
            points5[3] = new FCPoint(width - dSize, height - dSize2 - dw2);
            paint.fillPolygon(borderColor, points5);
            FCPoint[] points6 = new FCPoint[4];
            points6[0] = new FCPoint(width - dSize, height - dSize2 - dw2);
            points6[1] = new FCPoint(width - dSize - 4, height - dSize2 - dw2 - 2);
            points6[2] = new FCPoint(width - dSize - 22, height - dSize2 - dw2 + 16);
            points6[3] = new FCPoint(width - dSize - 20, height - dSize2 - dw2 + 22);
            paint.fillPolygon(borderColor, points6);
            FCPoint[] points7 = new FCPoint[3];
            points7[0] = new FCPoint(width - 1, height - dSize2 - dw2 - 30);
            points7[1] = new FCPoint(width - 1, height - dSize2 - dw2 + 3);
            points7[2] = new FCPoint(width - 1 - dw2 + 20, height - dSize2 - 16);
            paint.drawPolyline(borderColor, 2, 0, points7);
            FCPoint[] points8 = new FCPoint[3];
            points8[0] = new FCPoint(width - 1 - dw2 + 19, height - dSize2 - 15);
            points8[1] = new FCPoint(width - dSize - dw2 + 1, height - dSize + 3);
            points8[2] = new FCPoint(width - dSize - dw2 - 25, height - dSize + 3);
            paint.drawPolyline(borderColor, 2, 0, points8);
            FCPoint[] points9 = new FCPoint[6];
            points9[0] = new FCPoint(width - dSize - dw2 + 1, height - dSize + 3);
            points9[1] = new FCPoint(width - dSize - dw2 - 14, height - dSize + 3);
            points9[2] = new FCPoint(width - dSize - dw2 - 10, height - dSize + 8);
            points9[3] = new FCPoint(width - dSize - dw2 + 3, height - dSize + 8);
            points9[4] = new FCPoint(width - dSize - dw2 + 16, height - dSize - 6);
            points9[5] = new FCPoint(width - dSize - dw2 + 16, height - dSize - 14);
            paint.fillPolygon(borderColor, points9);

            int rwidth = width * 3 / 5;
            if (rwidth > width - dSize * 2 - dw2)
            {
                rwidth = width - dSize2 * 2 - dw2;
            }
            FCPoint[] points10 = new FCPoint[4];
            points10[0] = new FCPoint(rwidth - 8, height - dSize2 - 6);
            points10[1] = new FCPoint(rwidth - 12, height - dSize2);
            points10[2] = new FCPoint(rwidth + 12, height - dSize2);
            points10[3] = new FCPoint(rwidth + 8, height - dSize2 - 6);
            paint.fillPolygon(borderColor, points10);
            rwidth = width * 7 / 10;
            if (rwidth > width - 30)
            {
                rwidth = width - 30;
            }
            FCPoint[] points11 = new FCPoint[4];
            points11[0] = new FCPoint(rwidth - 16, dSize - 6);
            points11[1] = new FCPoint(rwidth - 20, dSize);
            points11[2] = new FCPoint(rwidth + 20, dSize);
            points11[3] = new FCPoint(rwidth + 16, dSize - 6);
            paint.fillPolygon(borderColor, points11);
            FCDraw.drawText(paint, Text, textColor, Font, 100, 15);
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID)
        {
            base.onTimer(timerID);
            if (m_timerID == timerID)
            {
                FCNative native = Native;
                FCHost host = native.Host;
                FCSize nativeSize = native.DisplaySize;
                int x = Left, y = Top, width = Width, height = Height;
                if (m_animateType == 0)
                {
                    int xSub = nativeSize.cx / 4;
                    int ySub = nativeSize.cy / 4;
                    int mx = (nativeSize.cx - width) / 2;
                    int my = (nativeSize.cy - height) / 2;
                    float opacity = Opacity;
                    opacity += 0.1F;
                    if (opacity > 1)
                    {
                        opacity = 1;
                    }
                    Opacity = opacity;
                    bool stop = false;
                    switch (m_animateDirection)
                    {
                        //��������
                        case 0:
                            if (x + xSub >= mx)
                            {
                                x = mx;
                                stop = true;
                            }
                            else
                            {
                                x += xSub;
                            }
                            break;
                        //��������
                        case 1:
                            if (x - xSub <= mx)
                            {
                                x = mx;
                                stop = true;
                            }
                            else
                            {
                                x -= xSub;
                            }
                            break;
                        //��������
                        case 2:
                            if (y + ySub >= my)
                            {
                                y = my;
                                stop = true;
                            }
                            else
                            {
                                y += ySub;
                            }
                            break;
                        //��������
                        case 3:
                            if (y - ySub <= my)
                            {
                                y = my;
                                stop = true;
                            }
                            else
                            {
                                y -= ySub;
                            }
                            break;
                    }
                    if (stop)
                    {
                        Opacity = 1;
                        m_animateMoving = false;
                        stopTimer(m_timerID);
                        host.AllowOperate = true;
                    }
                }
                else
                {
                    int xSub = nativeSize.cx / 4;
                    int ySub = nativeSize.cy / 4;
                    float opacity = Opacity;
                    opacity -= 0.1F;
                    if (opacity < 0)
                    {
                        opacity = 0;
                    }
                    Opacity = opacity;
                    bool stop = false;
                    switch (m_animateDirection)
                    {
                        //��������
                        case 0:
                            if (x - xSub <= -width)
                            {
                                x = 0;
                                stop = true;
                            }
                            else
                            {
                                x -= xSub;
                            }
                            break;
                        //��������
                        case 1:
                            if (x + xSub >= nativeSize.cx)
                            {
                                x = 0;
                                stop = true;
                            }
                            else
                            {
                                x += xSub;
                            }
                            break;
                        //��������
                        case 2:
                            if (y - ySub <= -height)
                            {
                                y = 0;
                                stop = true;
                            }
                            else
                            {
                                y -= ySub;
                            }
                            break;
                        //��������
                        case 3:
                            if (y + ySub >= nativeSize.cy)
                            {
                                y = 0;
                                stop = true;
                            }
                            else
                            {
                                y += ySub;
                            }
                            break;
                    }
                    if (stop)
                    {
                        Opacity = 0;
                        m_animateMoving = false;
                        stopTimer(m_timerID);
                        host.AllowOperate = true;
                        hide();
                    }
                }
                FCPoint location = new FCPoint(x, y);
                Location = location;
                native.invalidate();
            }
        }

        /// <summary>
        /// ��󻯻�ָ�
        /// </summary>
        public void max()
        {
            m_normalLocation = Location;
            m_normalSize = Size;
            Dock = FCDockStyle.Fill;
            m_windowState = WindowStateA.Max;
            FCPoint maxLocation = new FCPoint(0, 0);
            Location = maxLocation;
            FCSize maxSize = Native.DisplaySize;
            Size = maxSize;
            m_maxOrRestoreButton.Style = WindowButtonStyle.Restore;
            Native.update();
            Native.invalidate();
        }

        /// <summary>
        /// ��󻯻�ָ�
        /// </summary>
        public void maxOrRestore()
        {
            if (m_windowState == WindowStateA.Normal)
            {
                max();
            }
            else
            {
                restore();
            }
        }

        /// <summary>
        /// ��С��
        /// </summary>
        public void min()
        {
            m_normalLocation = Location;
            m_normalSize = Size;
            Dock = FCDockStyle.None;
            m_windowState = WindowStateA.Min;
            m_maxOrRestoreButton.Style = WindowButtonStyle.Restore;
            FCSize minSize = new FCSize(150, CaptionHeight);
            Size = minSize;
            update();
            Native.invalidate();
        }

        /// <summary>
        /// �ָ�
        /// </summary>
        public void restore()
        {
            Dock = FCDockStyle.None;
            m_windowState = WindowStateA.Normal;
            Location = m_normalLocation;
            Size = m_normalSize;
            m_maxOrRestoreButton.Style = WindowButtonStyle.Max;
            Native.update();
            Native.invalidate();
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">����</param>
        /// <param name="value">ֵ</param>
        public override void setProperty(String name, String value)
        {
            if (name == "showmaxbox")
            {
                ShowMaxBox = FCStr.convertStrToBool(value);
            }
            else if (name == "showminbox")
            {
                ShowMinBox = FCStr.convertStrToBool(value);
            }
            else if (name == "windowstate")
            {
                String str = value.ToLower();
                if (str == "max")
                {
                    WindowState = WindowStateA.Max;
                }
                else if (str == "min")
                {
                    WindowState = WindowStateA.Min;
                }
                else if (str == "normal")
                {
                    WindowState = WindowStateA.Normal;
                }
            }
            else
            {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ���ָı䷽��
        /// </summary>
        public override void update()
        {
            base.update();
            int width = Width;
            if (m_closeButton != null)
            {
                FCPoint location = new FCPoint(width - 26, 2);
                m_closeButton.Location = location;
            }
            if (m_maxOrRestoreButton != null && m_maxOrRestoreButton.Visible)
            {
                FCPoint location = new FCPoint(width - 48, 2);
                m_maxOrRestoreButton.Location = location;
            }
            if (m_minButton != null && m_minButton.Visible)
            {
                FCPoint location = new FCPoint(width - 70, 2);
                if (m_maxOrRestoreButton != null && !m_maxOrRestoreButton.Visible)
                {
                    location.x = width - 48;
                }
                m_minButton.Location = location;
            }
        }
    }
}
