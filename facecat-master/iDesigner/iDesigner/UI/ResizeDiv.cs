/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;
using FaceCat;
using System.Windows.Forms;

namespace FaceCat
{
    /// <summary>
    /// �����ؼ���С��ͼ��
    /// </summary>
    public class ResizeDiv : FCView
    {
        /// <summary>
        /// ����ͼ��
        /// </summary>
        public ResizeDiv()
        {
            AllowDrag = true;
            BorderColor = FCColor.None;
        }

        /// <summary>
        /// �����ߴ��Ĵ�С
        /// </summary>
        private const int RESIZEPOINT_SIZE = 6;

        /// <summary>
        /// ����
        /// </summary>
        private int m_direction;

        /// <summary>
        /// �����ǩ
        /// </summary>
        private FCLabel m_lblXY;

        /// <summary>
        /// ��С��ǩ
        /// </summary>
        private FCLabel m_lblWH;

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        private int m_offsetX = 0;

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        private int m_offsetY = 0;

        /// <summary>
        /// λ��1
        /// </summary>
        private FCPoint m_point1;

        /// <summary>
        /// λ��2
        /// </summary>
        private FCPoint m_point2;

        /// <summary>
        /// �������
        /// </summary>
        private Random m_random = new Random();

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

        /// <summary>
        /// �ƶ�����
        /// </summary>
        private int m_step = 1;

        /// <summary>
        /// Ŀ���б�
        /// </summary>
        private List<FCView> m_targets = new List<FCView>();

        /// <summary>
        /// ����
        /// </summary>
        private int m_tick;

        private bool m_acceptTouch = true;

        /// <summary>
        /// ��ȡ�������Ƿ������궯��
        /// </summary>
        public bool AcceptTouch
        {
            get { return m_acceptTouch; }
            set { m_acceptTouch = value; }
        }

        private DesignerDiv m_designerDiv;

        /// <summary>
        /// ��ȡ�����ñ༭��ͼ
        /// </summary>
        public DesignerDiv DesignerDiv
        {
            get { return m_designerDiv; }
            set { m_designerDiv = value; }
        }

        private UIXmlEx m_xml;

        /// <summary>
        /// ��ȡ������XML����
        /// </summary>
        public UIXmlEx Xml
        {
            get { return m_xml; }
            set { m_xml = value; }
        }

        /// <summary>
        /// ���Ŀ��
        /// </summary>
        /// <param name="targets">Ŀ���б�</param>
        public void addTargets(List<FCView> targets)
        {
            int targetsSize = targets.Count;
            for (int i = 0; i < targetsSize; i++)
            {
                m_targets.Add(targets[i]);
            }
        }

        /// <summary>
        /// ���Ŀ��
        /// </summary>
        public void clearTargets()
        {
            m_targets.Clear();
        }

        /// <summary>
        /// �˳��϶�
        /// </summary>
        public void cancelDragging()
        {
            if (IsDragging)
            {
                FCNative native = Native;
                native.cancelDragging();
                invalidate();
            }
        }

        /// <summary>
        /// �Ƿ�����ƶ�
        /// </summary>
        /// <returns>�Ƿ�����ƶ�</returns>
        public bool canDragTargets()
        {
            int targetsSize = m_targets.Count;
            if (targetsSize == 1)
            {
                if (m_targets[0].Parent.Parent is DesignerDiv)
                {
                    return false;
                }
                if (m_targets[0] is FCTabPage)
                {
                    return false;
                }
                if (m_targets[0].Parent is FCSplitLayoutDiv || m_targets[0].Parent is FCLayoutDiv)
                {
                    return false;
                }
            }
            if (m_resizePoint != -1 && m_resizePoint != 8)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// <summary>
        /// �Ƿ�������ô�С
        /// </summary>
        /// <returns>�Ƿ�������ô�С</returns>
        public bool canResizeTargets()
        {
            int targetsSize = m_targets.Count;
            if (targetsSize == 1)
            {
                if (m_targets[0] is FCTabPage)
                {
                    return false;
                }
                if (m_targets[0].Parent is FCSplitLayoutDiv || m_targets[0].Parent is FCLayoutDiv)
                {
                    return false;
                }
            }
            if (m_resizePoint != -1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// <summary>
        /// �ж��Ƿ��������
        /// </summary>
        /// <param name="point">����</param>
        /// <returns>�����</returns>
        public override bool containsPoint(FCPoint point)
        {
            return m_acceptTouch;
        }

        /// <summary>
        /// ����ת��Ϊ��������
        /// </summary>
        /// <param name="bounds">����</param>
        /// <returns>��������</returns>
        public FCRect convertBoundsToPRect(FCRect bounds)
        {
            FCRect pRect = bounds;
            int nSize = 3;
            if (pRect.right - pRect.left > 6)
            {
                pRect.left += nSize;
                pRect.right -= nSize;
            }
            if (pRect.bottom - pRect.top > 6)
            {
                pRect.top += nSize;
                pRect.bottom -= nSize;
            }
            return pRect;
        }

        /// <summary>
        /// ��������ת��Ϊ����
        /// </summary>
        /// <param name="pRect">��������</param>
        /// <returns>����</returns>
        public FCRect convertPRectToBounds(FCRect pRect)
        {
            FCRect bounds = pRect;
            int nSize = 3;
            bounds.left -= nSize;
            bounds.top -= nSize;
            bounds.right += nSize;
            bounds.bottom += nSize;
            return bounds;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType()
        {
            return "ResizeDiv";
        }

        /// <summary>
        /// ��ȡ���
        /// </summary>
        /// <param name="resizePoint">������С�ĵ�</param>
        /// <returns>���</returns>
        private FCCursors getCursor(int resizePoint)
        {
            switch (resizePoint)
            {
                case 0:
                    return FCCursors.SizeWE;
                case 1:
                    return FCCursors.SizeNS;
                case 2:
                    return FCCursors.SizeWE;
                case 3:
                    return FCCursors.SizeNS;
                case 4:
                    return FCCursors.SizeNWSE;
                case 5:
                    return FCCursors.SizeNESW;
                case 6:
                    return FCCursors.SizeNESW;
                case 7:
                    return FCCursors.SizeNWSE;
                case 8:
                    return FCCursors.SizeAll;
                default:
                    return FCCursors.Arrow;
            }
        }

        /// <summary>
        /// ��ȡƫ������
        /// </summary>
        /// <returns>ƫ������</returns>
        public FCPoint getOffsetPoint()
        {
            FCPoint offset = new FCPoint();
            FCView parent = Parent;
            if (parent != null)
            {
                FCTabPage designerDiv = parent as FCTabPage;
                offset.x += (designerDiv.HScrollBar != null ? designerDiv.HScrollBar.Pos : 0);
                offset.y += (designerDiv.VScrollBar != null ? designerDiv.VScrollBar.Pos : 0);
            }
            return offset;
        }

        /// <summary>
        /// �����������ȡ��������
        /// </summary>
        /// <param name="point1">����1</param>
        /// <param name="point2">����2</param>
        /// <returns>��������</returns>
        public FCRect getRectangle(FCPoint point1, FCPoint point2)
        {
            int minX = Math.Min(point1.x, point2.x);
            int maxX = Math.Max(point1.x, point2.x);
            int minY = Math.Min(point1.y, point2.y);
            int maxY = Math.Max(point1.y, point2.y);
            return new FCRect(minX, minY, maxX, maxY);
        }

        /// <summary>
        /// ��ȡ�����ߴ�ĵ�
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�����ߴ�ĵ�</returns>
        private int getResizePoint(FCPoint mp)
        {
            FCRect[] pRects = getResizePoints();
            int rsize = pRects.Length;
            for (int i = rsize - 1; i >= 0; i--)
            {
                FCRect rect = pRects[i];
                if (mp.x >= rect.left && mp.x <= rect.right
                    && mp.y >= rect.top && mp.y <= rect.bottom)
                {
                    return i;
                }
            }
            int targetsSize = m_targets.Count;
            if (targetsSize > 0)
            {
                int width = Width, height = Height;
                if (mp.x >= 0 && mp.x <= width && mp.y >= 0 && mp.y <= height)
                {
                    bool inBorder = false;
                    int size = RESIZEPOINT_SIZE;
                    if (mp.x <= size
                    || mp.x >= width - size
                    || mp.y <= size
                    || mp.y >= height - size)
                    {
                        inBorder = true;
                    }
                    if (targetsSize == 1)
                    {
                        if (m_xml.isContainer(m_targets[0]))
                        {
                            if (inBorder)
                            {
                                return 8;
                            }
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else
                    {
                        if (inBorder)
                        {
                            return 8;
                        }
                    }
                }
            }
            return -1;
        }

        /// <summary>
        /// ��ȡ�����ߴ�ĵ�
        /// </summary>
        /// <returns>���μ���</returns>
        private FCRect[] getResizePoints()
        {
            int width = Width - 1;
            int height = Height - 1;
            FCRect[] points = new FCRect[9];
            int size = RESIZEPOINT_SIZE;
            //��
            points[0] = new FCRect(0, height / 2 - size, size, height / 2 + size);
            //��
            points[1] = new FCRect(width / 2 - size, 0, width / 2 + size, size);
            //��
            points[2] = new FCRect(width - size, height / 2 - size, width, height / 2 + size);
            //��
            points[3] = new FCRect(width / 2 - size, height - size, width / 2 + size, height);
            //����
            points[4] = new FCRect(0, 0, size, size);
            //����
            points[5] = new FCRect(0, height - size, size, height);
            //����
            points[6] = new FCRect(width - size, 0, width, size);
            //����
            points[7] = new FCRect(width - size, height - size, width, height);
            return points;
        }

        /// <summary>
        /// ��ȡĿ���б�
        /// </summary>
        /// <returns>Ŀ���б�</returns>
        public List<FCView> getTargets()
        {
            List<FCView> targets = new List<FCView>();
            int targetsSize = m_targets.Count;
            for (int i = 0; i < targetsSize; i++)
            {
                targets.Add(m_targets[i]);
            }
            return targets;
        }

        /// <summary>
        /// �Ƿ����ڵ����ߴ�
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>���ڵ����ߴ�</returns>
        public bool isResizing(FCPoint mp)
        {
            FCNative native = Native;
            int clientX = native.clientX(this);
            int clientY = native.clientY(this);
            int width = Width, height = Height;
            if (mp.x >= clientX && mp.x <= clientX + width && mp.y >= clientY && mp.y <= clientY + height)
            {
                mp.x -= clientX;
                mp.y -= clientY;
                if (getResizePoint(TouchPoint) != -1)
                {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// �ؼ����ط���
        /// </summary>
        public override void onLoad()
        {
            base.onLoad();
            if (m_lblXY == null)
            {
                m_lblXY = m_native.findControl("lblXY") as FCLabel;
            }
            if (m_lblWH == null)
            {
                m_lblWH = m_native.findControl("lblWH") as FCLabel;
            }
            startTimer(getNewTimerID(), 100);
        }

        /// <summary>
        /// �϶���ʼ����
        /// </summary>
        /// <returns>�Ƿ񲻴���</returns>
        public override bool onDragBegin()
        {
            int targetsSize = m_targets.Count;
            if (targetsSize == 1)
            {
                if (m_targets[0].Parent.Parent is DesignerDiv)
                {
                    return false;
                }
            }
            if (m_resizePoint == 8)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// �϶��з���
        /// </summary>
        public override void onDragging()
        {
            int targetsSize = m_targets.Count;
            base.onDragging();
            refreshStatusBar();
            Parent.update();
        }

        /// <summary>
        /// �϶���������
        /// </summary>
        public override void onDragEnd()
        {
            base.onDragEnd();
            int targetsSize = m_targets.Count;
            FCView divDesigner = Parent;
            //�ж�����
            FCNative native = Native;
            m_designerDiv.saveUndo();
            FCPoint mp = Native.TouchPoint;
            for (int i = 0; i < targetsSize; i++)
            {
                FCView target = m_targets[i];
                FCView parent = target.Parent;
                bool outControl = false;
                FCPoint oldNativeLocation = target.pointToNative(new FCPoint(0, 0));
                if (parent != null)
                {
                    if (divDesigner != null)
                    {
                        //�����µĿؼ�
                        m_acceptTouch = false;
                        FCView newParent = native.findControl(mp, divDesigner);
                        m_acceptTouch = true;
                        if (newParent != null && m_xml.isContainer(newParent) && newParent != this && newParent != parent
                            && target != newParent)
                        {
                            //�Ƴ��ؼ�
                            m_xml.removeControl(target);
                            //��ӿؼ�
                            m_xml.addControl(target, newParent);
                            parent = newParent;
                            outControl = true;
                        }
                    }
                }
                if (outControl || canDragTargets())
                {
                    FCRect newRect = convertBoundsToPRect(Bounds);
                    oldNativeLocation.x += newRect.left - m_startRect.left;
                    oldNativeLocation.y += newRect.top - m_startRect.top;
                    m_xml.setProperty(target, "location", FCStr.convertPointToStr(target.Parent.pointToControl(oldNativeLocation)));
                    target.update();
                }
            }
            m_designerDiv.Designer.refreshProperties();
            refreshStatusBar();
            divDesigner.update();
        }

        /// <summary>
        /// ���̰��·���
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyDown(char key)
        {
            base.onKeyDown(key);
            if (!IsDragging)
            {
                if (key >= 37 && key <= 40)
                {
                    int targetsSize = m_targets.Count;
                    if (targetsSize > 0 && canDragTargets())
                    {
                        FCPoint location = Location;
                        //����
                        if (key == 37)
                        {
                            location.x -= m_step;
                            m_offsetX -= m_step;
                        }
                        //����
                        else if (key == 38)
                        {
                            location.y -= m_step;
                            m_offsetY -= m_step;
                        }
                        //����
                        else if (key == 39)
                        {
                            location.x += m_step;
                            m_offsetX += m_step;
                        }
                        //����
                        else if (key == 40)
                        {
                            location.y += m_step;
                            m_offsetY += m_step;
                        }
                        m_step += 1;
                        Location = location;
                        Parent.update();
                        refreshStatusBar();
                        Parent.invalidate();
                    }
                }
                else
                {
                    //ɾ���ؼ�
                    if (key == 46)
                    {
                        int targetsSize = m_targets.Count;
                        if (targetsSize > 0)
                        {
                            m_designerDiv.saveUndo();
                            for (int i = 0; i < targetsSize; i++)
                            {
                                FCView target = m_targets[i];
                                m_xml.removeControl(target);
                            }
                            m_targets.Clear();
                            Visible = false;
                            Parent.invalidate();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyUp(char key)
        {
            if (!IsDragging)
            {
                m_step = 1;
                base.onKeyUp(key);
                if (m_offsetX != 0 || m_offsetY != 0)
                {
                    int targetsSize = m_targets.Count;
                    if (targetsSize > 0)
                    {
                        m_designerDiv.saveUndo();
                        for (int i = 0; i < targetsSize; i++)
                        {
                            FCView target = m_targets[i];
                            FCPoint oldLocation = target.Location;
                            oldLocation.x += m_offsetX;
                            oldLocation.y += m_offsetY;
                            m_xml.setProperty(target, "location", FCStr.convertPointToStr(oldLocation));
                            target.update();
                        }
                        m_designerDiv.Designer.refreshProperties();
                    }
                    refreshStatusBar();
                    Parent.invalidate();
                }
            }
            m_offsetX = 0;
            m_offsetY = 0;
        }

        /// <summary>
        /// ��갴�·���
        /// </summary>
        /// <param name="touchInto">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInto)
        {
            base.onTouchDown(touchInto);
            m_point1 = Native.TouchPoint;
            m_point2 = Native.TouchPoint;
            //ѡ�е�
            if (touchInto.m_firstTouch && touchInto.m_clicks == 1)
            {
                FCPoint mp = touchInto.m_firstPoint;
                if (canResizeTargets())
                {
                    m_resizePoint = getResizePoint(mp);
                    if (m_resizePoint != -1)
                    {
                        Cursor = getCursor(m_resizePoint);
                        m_startTouchPoint = Native.TouchPoint;
                        m_startRect = convertBoundsToPRect(Bounds);
                    }
                }
            }
            refreshStatusBar();
            invalidate();
        }

        /// <summary>
        /// ����ƶ�����
        /// </summary>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        public override void onTouchMove(FCTouchInfo touchInto)
        {
            base.onTouchMove(touchInto);
            m_point2 = Native.TouchPoint;
            if (m_resizePoint != -1 && m_resizePoint != 8)
            {
                FCPoint mp = Native.TouchPoint;
                int left = m_startRect.left, top = m_startRect.top, right = m_startRect.right, bottom = m_startRect.bottom;
                switch (m_resizePoint)
                {
                    //��
                    case 0:
                        left = left + mp.x - m_startTouchPoint.x;
                        break;
                    //��
                    case 1:
                        top = top + mp.y - m_startTouchPoint.y;
                        break;
                    //��
                    case 2:
                        right = right + mp.x - m_startTouchPoint.x;
                        break;
                    //��
                    case 3:
                        bottom = bottom + mp.y - m_startTouchPoint.y;
                        break;
                    //����
                    case 4:
                        left = left + mp.x - m_startTouchPoint.x;
                        top = top + mp.y - m_startTouchPoint.y;
                        break;
                    //����
                    case 5:
                        left = left + mp.x - m_startTouchPoint.x;
                        bottom = bottom + mp.y - m_startTouchPoint.y;
                        break;
                    //����
                    case 6:
                        right = right + mp.x - m_startTouchPoint.x;
                        top = top + mp.y - m_startTouchPoint.y;
                        break;
                    //����
                    case 7:
                        right = right + mp.x - m_startTouchPoint.x;
                        bottom = bottom + mp.y - m_startTouchPoint.y;
                        break;
                }
                FCRect bounds = new FCRect(left, top, right, bottom);
                Bounds = convertPRectToBounds(bounds);
                m_designerDiv.invalidate();
            }
            else
            {
                Cursor = getCursor(getResizePoint(TouchPoint));
                invalidate();
            }
        }

        /// <summary>
        /// ���̧�𷽷�
        /// </summary>
        /// <param name="touchInto">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInto)
        {
            m_point2 = Native.TouchPoint;
            base.onTouchUp(touchInto);
            if (!IsDragging)
            {
                FCView divDesigner = Parent;
                if (m_resizePoint != -1)
                {
                    FCRect nowRect = convertBoundsToPRect(Bounds);
                    //�ƶ��ؼ�
                    int targetsSize = m_targets.Count;
                    if (targetsSize > 0)
                    {
                        m_designerDiv.saveUndo();
                        for (int i = 0; i < targetsSize; i++)
                        {
                            FCView target = m_targets[i];
                            FCPoint oldLocation = target.Location;
                            FCSize oldSize = target.Size;
                            oldLocation.x += nowRect.left - m_startRect.left;
                            oldLocation.y += nowRect.top - m_startRect.top;
                            oldSize.cx += (nowRect.right - nowRect.left) - (m_startRect.right - m_startRect.left);
                            oldSize.cy += (m_startRect.top - m_startRect.bottom) - (nowRect.top - nowRect.bottom);
                            if (oldSize.cx < 4)
                            {
                                oldSize.cx = 4;
                            }
                            else if (oldSize.cy < 4)
                            {
                                oldSize.cy = 4;
                            }
                            m_xml.setProperty(target, "location", FCStr.convertPointToStr(oldLocation));
                            m_xml.setProperty(target, "size", FCStr.convertSizeToStr(oldSize));
                            target.update();
                        }
                    }
                    m_designerDiv.Designer.refreshProperties();
                }
                else
                {
                    if (m_targets.Count == 1)
                    {
                        if (Math.Abs(m_point1.x - m_point2.x) > 5 && Math.Abs(m_point1.y - m_point2.y) > 5)
                        {
                            //��ȡѡ�пؼ�
                            FCView target = m_targets[0];
                            FCRect moveRect = getRectangle(pointToControl(m_point1), pointToControl(m_point2));
                            List<FCView> newTargets = new List<FCView>();
                            List<FCView> subControls = target.getControls();
                            int left = 0, top = 0, right = 0, bottom = 0, idx = 0;
                            int subControlsSize = subControls.Count;
                            for (int i = 0; i < subControlsSize; i++)
                            {
                                FCView subControl = subControls[i];
                                FCRect bounds = subControl.Bounds;
                                FCRect tempRect = new FCRect();
                                if (Native.Host.getIntersectRect(ref tempRect, ref moveRect, ref bounds) > 0)
                                {
                                    newTargets.Add(subControl);
                                    if (idx == 0)
                                    {
                                        left = bounds.left;
                                        top = bounds.top;
                                        right = bounds.right;
                                        bottom = bounds.bottom;
                                    }
                                    else
                                    {
                                        if (left > bounds.left)
                                        {
                                            left = bounds.left;
                                        }
                                        if (top > bounds.top)
                                        {
                                            top = bounds.top;
                                        }
                                        if (right < bounds.right)
                                        {
                                            right = bounds.right;
                                        }
                                        if (bottom < bounds.bottom)
                                        {
                                            bottom = bounds.bottom;
                                        }
                                    }
                                    idx++;
                                }
                            }
                            if (newTargets.Count > 0)
                            {
                                FCPoint p1 = target.pointToNative(new FCPoint(left, top));
                                FCPoint p2 = target.pointToNative(new FCPoint(right, bottom));
                                p1 = divDesigner.pointToControl(p1);
                                p2 = divDesigner.pointToControl(p2);
                                Bounds = convertPRectToBounds(new FCRect(p1.x, p1.y, p2.x, p2.y));
                                clearTargets();
                                addTargets(newTargets);
                                m_designerDiv.Designer.refreshProperties(newTargets);
                            }
                        }
                    }
                }
            }
            refreshStatusBar();
            m_resizePoint = -1;
            Cursor = FCCursors.Arrow;
            FCNative native = Native;
            native.Host.setCursor(FCCursors.Arrow);
            native.update();
            native.invalidate();
        }
        
        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            int width = Width;
            int height = Height;
            FCNative native = Native;
            FCRect drawRect = convertBoundsToPRect(new FCRect(0, 0, width, height));
            //����ѡ�еĵ�
            int resizePoint = m_resizePoint != -1 ? m_resizePoint : getResizePoint(TouchPoint);
            if (width > 4 && height > 4)
            {
                long borderColor = FCDraw.FCCOLORS_BACKCOLOR8;
                //���ƶ�Ŀ��
                int targetsSize = m_targets.Count;
                if (targetsSize > 1)
                {
                    for (int i = 0; i < targetsSize; i++)
                    {
                        FCView target = m_targets[i];
                        FCPoint clientLocation = pointToControl(new FCPoint(Native.clientX(target), Native.clientY(target)));
                        paint.drawRect(borderColor, 2, 0,
                            new FCRect(clientLocation.x, clientLocation.y,
                            clientLocation.x + target.Width,
                            clientLocation.y + target.Height));
                    }
                }
                if (resizePoint != -1 && resizePoint != 8)
                {
                    paint.fillGradientRect(FCDraw.FCCOLORS_BACKCOLOR5, FCDraw.FCCOLORS_BACKCOLOR6, drawRect, 0, 90);
                    paint.drawRect(borderColor, 1, 2, drawRect);
                    int thick = 4;
                    List<int> positions = new List<int>();
                    //��������
                    if (resizePoint < 4)
                    {
                        positions.Add(resizePoint);
                    }
                    else
                    {
                        switch (resizePoint)
                        {
                            //����
                            case 4:
                                positions.Add(0);
                                positions.Add(1);
                                break;
                            //����
                            case 5:
                                positions.Add(0);
                                positions.Add(3);
                                break;
                            //����
                            case 6:
                                positions.Add(1);
                                positions.Add(2);
                                break;
                            //����
                            case 7:
                                positions.Add(2);
                                positions.Add(3);
                                break;
                        }
                    }
                    //����ѡ�е�
                    int positionsSize = positions.Count;
                    for (int i = 0; i < positionsSize; i++)
                    {
                        switch (positions[i])
                        {
                            //��
                            case 0:
                                paint.fillRect(borderColor, new FCRect(0, 0, thick, height));
                                break;
                            //��
                            case 1:
                                paint.fillRect(borderColor, new FCRect(0, 0, width, thick));
                                break;
                            //��
                            case 2:
                                paint.fillRect(borderColor, new FCRect(width - thick, 0, width, height));
                                break;
                            //��
                            case 3:
                                paint.fillRect(borderColor, new FCRect(0, height - thick, width, height));
                                break;
                        }
                    }
                }
                else
                {
                    if (Native.PushedControl == this)
                    {
                        if (Math.Abs(m_point1.x - m_point2.x) > 5 && Math.Abs(m_point1.y - m_point2.y) > 5)
                        {
                            FCRect moveRect = getRectangle(pointToControl(m_point1), pointToControl(m_point2));
                            paint.drawRect(borderColor, 2, 0, moveRect);
                        }
                    }
                    paint.drawRect(borderColor, 2, 2, drawRect);
                    FCRect[] pRects = getResizePoints();
                    int pRectsSize = pRects.Length;
                    for (int p = 0; p < pRectsSize; p++)
                    {
                        paint.fillRect(borderColor, pRects[p]);
                    }
                    //���ƶ���
                    if (resizePoint == -1)
                    {
                        if (m_tick < 20)
                        {
                            if (m_tick > 2 && m_tick < 18)
                            {
                                int xTick = width / 20;
                                int yTick = height / 20;
                                int tWidth = width / 3, tHeight = height / 3;
                                int nSize = RESIZEPOINT_SIZE;
                                paint.setLineCap(2, 2);
                                int a = (10 - Math.Abs(m_tick - 10)) * 20;
                                paint.drawLine(FCColor.argb(a, m_random.Next(0, 256), m_random.Next(0, 256), m_random.Next(0, 256)), m_random.Next(1, 10),
                                    0, xTick * m_tick - tWidth / 2, (m_direction == 1 ? nSize : height - nSize), xTick * m_tick + tWidth / 2, (m_direction == 1 ? nSize : height - nSize));
                                paint.drawLine(FCColor.argb(a, m_random.Next(0, 256), m_random.Next(0, 256), m_random.Next(0, 256)), m_random.Next(1, 10),
                                    0, width - xTick * m_tick - tWidth / 2, (m_direction == 0 ? nSize : height - nSize), width - (xTick * m_tick - tWidth / 2), (m_direction == 0 ? nSize : height - nSize));
                                paint.drawLine(FCColor.argb(a, m_random.Next(0, 256), m_random.Next(0, 256), m_random.Next(0, 256)), m_random.Next(1, 10),
                                    0, (m_direction == 1 ? nSize : width - nSize), height - yTick * m_tick - tHeight / 2, (m_direction == 1 ? nSize : width - nSize), height - (yTick * m_tick - tHeight / 2));
                                paint.drawLine(FCColor.argb(a, m_random.Next(0, 256), m_random.Next(0, 256), m_random.Next(0, 256)), m_random.Next(1, 10),
                                    0, (m_direction == 0 ? nSize : width - nSize), yTick * m_tick - tHeight / 2, (m_direction == 0 ? nSize : width - nSize), yTick * m_tick + tHeight / 2);
                                paint.setLineCap(0, 0);
                            }
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ����¼�
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID)
        {
            base.onTimer(timerID);
            if (m_direction == 0)
            {
                m_tick++;
                if (m_tick >= 40)
                {
                    m_direction = 1;
                }
            }
            else if (m_direction == 1)
            {
                m_tick--;
                if (m_tick <= 0)
                {
                    m_direction = 0; 
                }
            }
            int resizePoint = m_resizePoint != -1 ? m_resizePoint : getResizePoint(TouchPoint);
            if (resizePoint == -1 && m_tick < 21)
            {
                invalidate();
            }
        }

        /// <summary>
        /// ˢ��״̬��
        /// </summary>
        public void refreshStatusBar()
        {
            if (m_targets.Count > 0)
            {
                FCView target = m_targets[0];
                int clientX = m_native.clientX(target);
                int clientY = m_native.clientY(target);
                int thisClientX = m_native.clientX(this);
                int thisClientY = m_native.clientY(this);
                FCPoint location = target.Location;
                FCSize size = target.Size;
                m_lblXY.Text = String.Format("����:{0} ��:{1} ", location.x + (thisClientX - clientX), location.y + (thisClientY - clientY));
                m_lblWH.Text = String.Format("��:{0} ��:{1} ", size.cx, size.cy);
            }
            else
            {
                m_lblXY.Text = "����:0 ��:0";
                m_lblWH.Text = "��:0 ��:0";
            }
        }
    }
}
