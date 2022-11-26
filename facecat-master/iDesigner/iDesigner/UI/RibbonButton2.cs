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
    public class RibbonButton2 : FCButton
    {
        /// <summary>
        /// ������ť
        /// </summary>
        public RibbonButton2()
        {
            BorderColor = FCColor.None;
            TextColor = FCDraw.FCCOLORS_TEXTCOLOR4;
            Font = new FCFont("΢���ź�", 12, false, false, false);
        }

        /// <summary>
        /// ��ȡ���ڻ��Ƶı���ɫ
        /// </summary>
        /// <returns></returns>
        protected override long getPaintingBackColor()
        {
            if (Native.PushedControl == this)
            {
                return FCColor.reverse(null, FCDraw.FCCOLORS_BACKCOLOR8);
            }
            else if (Native.HoveredControl == this)
            {
                return FCColor.ratioColor(null, FCDraw.FCCOLORS_BACKCOLOR8, 0.95);
            }
            else
            {
                return FCDraw.FCCOLORS_BACKCOLOR8;
            }
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            int width = Width - 1, height = Height - 1;
            FCRect drawRect = new FCRect(0, 0, width, height);
            paint.fillRoundRect(getPaintingBackColor(), drawRect, 4);
        }
    }
}
