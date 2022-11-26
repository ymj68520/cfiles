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
    /// ͼƬ��ť
    /// </summary>
    public class ImageButton : FCButton
    {
        /// <summary>
        /// ���������䰴ť
        /// </summary>
        public ImageButton()
        {
            BackColor = FCColor.None;
            BorderColor = FCDraw.FCCOLORS_LINECOLOR2;
            Font = new FCFont("΢���ź�", 12, false, false, false);
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
            String text = Text;
            FCFont font = Font;
            FCSize tSize = paint.textSize(text, font);
            int drawWidth = tSize.cx + 20;
            FCRect drawRect = new FCRect(0, 0, width, height);
            FCNative native = Native;
            //���Ʊ���
            if (this == native.HoveredControl)
            {
                paint.fillGradientRect(FCDraw.FCCOLORS_BACKCOLOR5, FCDraw.FCCOLORS_BACKCOLOR6, drawRect, 2, 90);
            }
            //����ͼ��
            String backImage = getPaintingBackImage();
            FCRect imageRect = new FCRect(2, (height - 16) / 2, 18, (height + 16) / 2);
            if (backImage != null && backImage.Length > 0)
            {
                paint.fillRect(getPaintingBackColor(), imageRect);
                paint.drawImage(getPaintingBackImage(), imageRect);
            }
            //��������
            FCRect tRect = new FCRect();
            tRect.left = imageRect.right + 4;
            tRect.top = (height - tSize.cy) / 2;
            tRect.right = tRect.left + tSize.cx;
            tRect.bottom = tRect.top + tSize.cy;
            paint.drawText(text, getPaintingTextColor(), font, tRect);
            //���Ʊ���
            if (this == native.HoveredControl)
            {
                paint.drawRoundRect(getPaintingBorderColor(), 1, 0, drawRect, 2);
            }
            if (Enabled)
            {
                if (this == native.PushedControl)
                {
                    paint.fillRect(FCDraw.FCCOLORS_BACKCOLOR4, drawRect);
                }
                else if (this == native.HoveredControl)
                {
                    paint.fillRect(FCDraw.FCCOLORS_BACKCOLOR3, drawRect);
                }

            }
            else
            {
                paint.fillRect(FCDraw.FCCOLORS_BACKCOLOR7, drawRect);
            }
        }

        /// <summary>
        /// ���Ʊ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBorder(FCPaint paint, FCRect clipRect)
        {
        }

        /// <summary>
        /// ����ǰ��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect)
        {
        }
    }
}
