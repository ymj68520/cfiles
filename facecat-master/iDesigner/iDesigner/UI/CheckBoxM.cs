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
    /// ��ѡ����չ
    /// </summary>
    public class CheckBoxM : FCCheckBox
    {
        /// <summary>
        /// ������ѡ��
        /// </summary>
        public CheckBoxM()
        {
            ButtonSize = new FCSize(40, 14);
            BorderColor = FCColor.Border;
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintCheckButton(FCPaint paint, FCRect clipRect)
        {
            bool isChecked = Checked;
            long backColor = FCDraw.FCCOLORS_BACKCOLOR4;
            if (isChecked)
            {
                backColor = FCDraw.FCCOLORS_BACKCOLOR9;
            }
            long backColor2 = FCDraw.FCCOLORS_TEXTCOLOR4;
            long borderColor = getPaintingBorderColor();
            paint.fillRoundRect(backColor, clipRect, 4);
            FCSize buttonSize = ButtonSize;
            if (isChecked)
            {
                FCRect pRect = new FCRect(clipRect.left + buttonSize.cx / 2 - 1, clipRect.top - 1, clipRect.right + 1, clipRect.bottom + 1);
                paint.fillRoundRect(backColor2, pRect, 4);
                paint.drawRoundRect(backColor, 1, 0, pRect, 4);
            }
            else
            {
                FCRect pRect = new FCRect(clipRect.left - 1, clipRect.top - 1, clipRect.left + buttonSize.cx / 2 + 1, clipRect.bottom + 1);
                paint.fillRoundRect(backColor2, pRect, 4);
                paint.drawRoundRect(backColor, 1, 0, pRect, 4);
            }
        }
    }
}
