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
    /// ���尴ť��ʽ
    /// </summary>
    public enum WindowButtonStyle
    {
        Close, //�ر�
        Max, //���
        Min, //��С��
        Restore //�ָ�
    }

    /// <summary>
    /// ���尴ť
    /// </summary>
    public class WindowButton : FCButton
    {
        /// <summary>
        /// ������ť
        /// </summary>
        public WindowButton()
        {
            TextColor = FCDraw.FCCOLORS_LINECOLOR;
            Size = new FCSize(150, 150);
        }

        private bool m_isEllipse = true;

        /// <summary>
        /// ��ȡ�������Ƿ���Բ�ΰ�ť
        /// </summary>
        public bool IsEllipse
        {
            get { return m_isEllipse; }
            set { m_isEllipse = value; }
        }

        private WindowButtonStyle m_style = WindowButtonStyle.Close;

        /// <summary>
        /// ��ȡ��������ʽ
        /// </summary>
        public WindowButtonStyle Style
        {
            get { return m_style; }
            set { m_style = value; }
        }

        /// <summary>
        /// ��ȡ���ڻ��Ƶı���ɫ
        /// </summary>
        /// <returns></returns>
        protected override long getPaintingBackColor()
        {
            FCNative native = Native;
            if (m_style == WindowButtonStyle.Close)
            {
                if (native.PushedControl == this)
                {
                    return FCColor.argb(255, 0, 0);
                }
                else if (native.HoveredControl == this)
                {
                    return FCColor.argb(255, 150, 150);
                }
                else
                {
                    return FCColor.argb(255, 80, 80);
                }
            }
            else if (m_style == WindowButtonStyle.Min)
            {
                if (native.PushedControl == this)
                {
                    return FCColor.argb(0, 255, 0);
                }
                else if (native.HoveredControl == this)
                {
                    return FCColor.argb(150, 255, 150);
                }
                else
                {
                    return FCColor.argb(80, 255, 80);
                }
            }
            else
            {
                if (native.PushedControl == this)
                {
                    return FCColor.argb(255, 255, 0);
                }
                else if (native.HoveredControl == this)
                {
                    return FCColor.argb(255, 255, 150);
                }
                else
                {
                    return FCColor.argb(255, 255, 80);
                }
            }
        }

        /// <summary>
        /// ���Ʊ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            int width = Width, height = Height;
            float xRate = (float)width / 200;
            float yRate = (float)height / 200;
            FCRect drawRect = new FCRect(0, 0, width - 1, height - 1);
            if (m_isEllipse)
            {
                paint.fillEllipse(getPaintingBackColor(), drawRect);
            }
            else
            {
                paint.fillRect(getPaintingBackColor(), drawRect);
            }
            long textColor = getPaintingTextColor();
            float lineWidth = 10 * xRate;
            if (m_style == WindowButtonStyle.Close)
            {
                paint.setLineCap(2, 2);
                paint.drawLine(textColor, lineWidth, 0, (int)(135 * xRate), (int)(70 * yRate), (int)(70 * xRate), (int)(135 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(70 * xRate), (int)(70 * yRate), (int)(135 * xRate), (int)(135 * yRate));
            }
            else if (m_style == WindowButtonStyle.Max)
            {
                paint.setLineCap(2, 2);
                paint.drawLine(textColor, lineWidth, 0, (int)(80 * xRate), (int)(80 * yRate), (int)(60 * xRate), (int)(60 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(125 * xRate), (int)(145 * yRate), (int)(145 * xRate), (int)(145 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(145 * xRate), (int)(125 * yRate), (int)(145 * xRate), (int)(145 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(125 * xRate), (int)(125 * yRate), (int)(145 * xRate), (int)(145 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(60 * xRate), (int)(80 * yRate), (int)(60 * xRate), (int)(60 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(80 * xRate), (int)(60 * yRate), (int)(60 * xRate), (int)(60 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(125 * xRate), (int)(80 * yRate), (int)(145 * xRate), (int)(60 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(145 * xRate), (int)(80 * yRate), (int)(145 * xRate), (int)(60 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(125 * xRate), (int)(60 * yRate), (int)(145 * xRate), (int)(60 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(80 * xRate), (int)(125 * yRate), (int)(60 * xRate), (int)(145 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(60 * xRate), (int)(125 * yRate), (int)(60 * xRate), (int)(145 * yRate));
                paint.drawLine(textColor, lineWidth, 0, (int)(80 * xRate), (int)(145 * yRate), (int)(60 * xRate), (int)(145 * yRate));
            }
            else if (m_style == WindowButtonStyle.Min)
            {
                paint.setLineCap(2, 2);
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(60 * yRate), (int)(105 * xRate), (int)(135 * xRate), (int)(105 * yRate));
            }
            else if (m_style == WindowButtonStyle.Restore)
            {
                paint.setLineCap(2, 2);
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(90 * yRate), (int)(90 * xRate), (int)(70 * xRate), (int)(70 * yRate));
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(90 * yRate), (int)(90 * xRate), (int)(70 * xRate), (int)(90 * yRate));
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(90 * yRate), (int)(90 * xRate), (int)(90 * xRate), (int)(70 * yRate));
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(115 * yRate), (int)(115 * xRate), (int)(135 * xRate), (int)(135 * yRate));
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(115 * yRate), (int)(115 * xRate), (int)(135 * xRate), (int)(115 * yRate));
                paint.drawLine(textColor, lineWidth, (int)(0 * xRate), (int)(115 * yRate), (int)(115 * xRate), (int)(115 * xRate), (int)(135 * yRate));
            }
            paint.setLineCap(0, 0);
        }

        /// <summary>
        /// ���Ʊ��߷���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBorder(FCPaint paint, FCRect clipRect)
        {
            int width = Width, height = Height;
            FCRect drawRect = new FCRect(0, 0, width, height);
            if (m_isEllipse)
            {
                paint.drawEllipse(getPaintingBorderColor(), 1, 0, drawRect);
            }
            else
            {
                paint.drawRect(getPaintingBorderColor(), 1, 0, drawRect);
            }
        }
    }
}
