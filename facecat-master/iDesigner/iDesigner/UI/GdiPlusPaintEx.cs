/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using FaceCat;
using System.Drawing;
using System.IO;
using System.Drawing.Imaging;

namespace FaceCat
{
    /// <summary>
    /// ��ͼ����
    /// </summary>
    public class GdiPlusPaintEx : GdiPlusPaint
    {
        /// <summary>
        /// ��ȡ��ɫ
        /// </summary>
        /// <param name="dwPenColor">������ɫ</param>
        /// <returns>�����ɫ</returns>
        public override long getPaintColor(long dwPenColor)
        {
            return FCDraw.GetColor(dwPenColor);
        }
    }
}
