/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using FaceCat;

namespace FaceCat
{
    /// <summary>
    /// ͸����ť
    /// </summary>
    public class RibbonButton : FCButton
    {
        /// <summary>
        /// ����͸����ť
        /// </summary>
        public RibbonButton()
        {
            BackColor = FCColor.None;
            BorderColor = FCColor.None;
            Font = new FCFont("΢���ź�", 12, false, false, false);
        }

        private int m_angle = 90;

        /// <summary>
        /// ��ȡ�����ý���Ƕ�
        /// </summary>
        public int Angle
        {
            get { return m_angle; }
            set { m_angle = value; }
        }

        private int m_arrowType;

        /// <summary>
        /// ��ȡ�����ü�ͷ����
        /// </summary>
        public int ArrowType
        {
            get { return m_arrowType; }
            set { m_arrowType = value; }
        }

        private bool m_isClose;

        /// <summary>
        /// ��ȡ�������Ƿ��ǹرհ�ť
        /// </summary>
        public bool IsClose
        {
            get { return m_isClose; }
            set { m_isClose = value; }
        }

        /// <summary>
        /// ��ȡ�������Ƿ�ѡ��
        /// </summary>
        public bool Selected
        {
            get
            {
                FCView parent = Parent;
                if (parent != null)
                {
                    FCTabControl tabControl = parent as FCTabControl;
                    if (tabControl != null)
                    {
                        FCTabPage selectedTabPage = tabControl.SelectedTabPage;
                        if (selectedTabPage != null)
                        {
                            if (this == selectedTabPage.HeaderButton)
                            {
                                return true;
                            }
                        }
                    }
                }
                return false;
            }
        }

        /// <summary>
        /// ��ȡҪ���Ƶı���ͼƬ
        /// </summary>
        /// <returns>����ͼƬ</returns>
        protected override String getPaintingBackImage()
        {
            return FCDraw.getCloseButtonImage();
        }

        /// <summary>
        /// ��ȡҪ���Ƶ�ǰ��ɫ
        /// </summary>
        /// <returns>ǰ��ɫ</returns>
        protected override long getPaintingTextColor()
        {
            if (Enabled)
            {
                if (Selected)
                {
                    return FCDraw.FCCOLORS_TEXTCOLOR4;
                }
                else
                {
                    return FCDraw.FCCOLORS_TEXTCOLOR;
                }
            }
            else
            {
                return FCDraw.FCCOLORS_TEXTCOLOR2;
            }
        }

        /// <summary>
        /// �ػ汳��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            int width = Width;
            int height = Height;
            int mw = width / 2;
            int mh = height / 2;
            FCRect drawRect = new FCRect(0, 0, width, height);
            if (m_isClose)
            {
                long lineColor = FCDraw.FCCOLORS_LINECOLOR;
                FCRect ellipseRect = new FCRect(1, 1, width - 2, height - 2);
                paint.fillEllipse(FCDraw.FCCOLORS_UPCOLOR, ellipseRect);
                paint.drawLine(lineColor, 2, 0, 4, 4, width - 7, height - 7);
                paint.drawLine(lineColor, 2, 0, 4, height - 7, width - 7, 3);
            }
            else
            {
                int cornerRadius = 3;
                if (m_arrowType > 0)
                {
                    cornerRadius = 0;
                }
                FCView parent = Parent;
                if (parent != null)
                {
                    FCTabControl tabControl = parent as FCTabControl;
                    if (tabControl != null)
                    {
                        cornerRadius = 0;
                    }
                }
                paint.fillGradientRect(FCDraw.FCCOLORS_BACKCOLOR, FCDraw.FCCOLORS_BACKCOLOR2, drawRect, cornerRadius, m_angle);
                paint.drawRoundRect(FCColor.Border, 1, 0, drawRect, cornerRadius);
            }
            if (m_arrowType > 0)
            {
                FCPoint[] points = new FCPoint[3];
                int dSize = Math.Min(width, height) / 4;
                switch (m_arrowType)
                {
                    //����
                    case 1:
                        points[0] = new FCPoint(mw - dSize, mh);
                        points[1] = new FCPoint(mw + dSize, mh - dSize);
                        points[2] = new FCPoint(mw + dSize, mh + dSize);
                        break;
                    //����
                    case 2:
                        points[0] = new FCPoint(mw + dSize, mh);
                        points[1] = new FCPoint(mw - dSize, mh - dSize);
                        points[2] = new FCPoint(mw - dSize, mh + dSize);
                        break;
                    //����
                    case 3:
                        points[0] = new FCPoint(mw, mh - dSize);
                        points[1] = new FCPoint(mw - dSize, mh + dSize);
                        points[2] = new FCPoint(mw + dSize, mh + dSize);
                        break;
                    //����
                    case 4:
                        points[0] = new FCPoint(mw, mh + dSize);
                        points[1] = new FCPoint(mw - dSize, mh - dSize);
                        points[2] = new FCPoint(mw + dSize, mh - dSize);
                        break;
                }
                paint.fillPolygon(FCDraw.FCCOLORS_TEXTCOLOR, points);
            }
            //����ѡ��Ч��
            if (paint.supportTransparent())
            {
                if (Selected)
                {
                    paint.fillRect(FCDraw.FCCOLORS_BACKCOLOR8, drawRect);
                }
                else
                {
                    FCNative native = Native;
                    if (this == native.PushedControl)
                    {
                        paint.fillRect(FCDraw.FCCOLORS_BACKCOLOR4, drawRect);
                    }
		            else if (this == native.HoveredControl)
                    {
                        paint.fillRect(FCDraw.FCCOLORS_BACKCOLOR3, drawRect);
                    }
                }
            }
        }
    }
}
