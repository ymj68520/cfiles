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
    /// ����ؼ��߽�
    /// </summary>
    public class FCWindowFrame : FCView {
        /// <summary>
        /// ��������ؼ�
        /// </summary>
        public FCWindowFrame() {
            BackColor = FCColor.None;
            BorderColor = FCColor.None;
            Dock = FCDockStyle.Fill;
        }

        /// <summary>
        /// �Ƿ��������
        /// </summary>
        /// <param name="point">����</param>
        /// <returns>�Ƿ����</returns>
        public override bool containsPoint(FCPoint point) {
            ArrayList<FCView> controls = m_controls;
            int controlsSize = controls.size();
            for (int i = 0; i < controlsSize; i++) {
                FCWindow window = controls.get(i) as FCWindow;
                if (window != null && window.Frame == this) {
                    if (window.IsDialog) {
                        return true;
                    }
                    else {
                        return window.containsPoint(point);
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "WindowFrame";
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        public override void invalidate() {
            if (m_native != null) {
                ArrayList<FCView> controls = m_controls;
                int controlsSize = controls.size();
                for (int i = 0; i < controlsSize; i++) {
                    FCWindow window = controls.get(i) as FCWindow;
                    if (window != null) {
                        m_native.invalidate(window.getDynamicPaintRect());
                        break;
                    }
                }
            }
        }

        /// <summary>
        /// ���Ʊ�������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect) {
            base.onPaintBackground(paint, clipRect);
            if (paint.supportTransparent()) {
                ArrayList<FCView> controls = m_controls;
                int controlsSize = controls.size();
                for (int i = 0; i < controlsSize; i++) {
                    FCWindow window = controls.get(i) as FCWindow;
                    if (window != null) {
                        long shadowColor = window.ShadowColor;
                        int shadowSize = window.ShadowSize;
                        if (shadowColor != FCColor.None && shadowSize > 0 && window.IsDialog && window.Frame == this) {
                            FCRect bounds = window.Bounds;
                            FCRect leftShadow = new FCRect(bounds.left - shadowSize, bounds.top - shadowSize, bounds.left, bounds.bottom + shadowSize);
                            paint.fillRect(shadowColor, leftShadow);
                            FCRect rightShadow = new FCRect(bounds.right, bounds.top - shadowSize, bounds.right + shadowSize, bounds.bottom + shadowSize);
                            paint.fillRect(shadowColor, rightShadow);
                            FCRect topShadow = new FCRect(bounds.left, bounds.top - shadowSize, bounds.right, bounds.top);
                            paint.fillRect(shadowColor, topShadow);
                            FCRect bottomShadow = new FCRect(bounds.left, bounds.bottom, bounds.right, bounds.bottom + shadowSize);
                            paint.fillRect(shadowColor, bottomShadow);
                            break;
                        }
                    }
                }
            }
        }
    }
}
