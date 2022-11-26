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
    /// ������
    /// </summary>
    public class FCBandedFCGridColumn : FCGridColumn {
        /// <summary>
        /// ����������
        /// </summary>
        public FCBandedFCGridColumn() {
        }

        protected FCGridBand m_band;

        /// <summary>
        /// ��ȡ�����ñ���
        /// </summary>
        public virtual FCGridBand Band {
            get { return m_band; }
            set { m_band = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "BandedFCGridColumn";
        }

        /// <summary>
        /// �϶���ʼ����
        /// </summary>
        /// <returns>�Ƿ��϶�</returns>
        public override bool onDragBegin() {
            return m_resizeState == 0;
        }

        /// <summary>
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            callTouchEvents(FCEventID.TOUCHDOWN, touchInfo);
            if (m_band != null) {
                if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1) {
                    FCPoint mp = touchInfo.m_firstPoint;
                    if (AllowResize) {
                        ArrayList<FCBandedFCGridColumn> bandColumns = m_band.getColumns();
                        int columnsSize = bandColumns.size();
                        int index = -1;
                        for (int i = 0; i < columnsSize; i++) {
                            if (this == bandColumns.get(i)) {
                                index = i;
                                break;
                            }
                        }
                        if (index > 0 && mp.x < 5) {
                            m_resizeState = 1;
                            m_beginWidth = bandColumns.get(index - 1).Width;
                        }
                        else if (index < columnsSize - 1 && mp.x > Width - 5) {
                            m_resizeState = 2;
                            m_beginWidth = Width;
                        }
                        m_touchDownPoint = Native.TouchPoint;
                    }
                }
            }
            invalidate();
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            callTouchEvents(FCEventID.TOUCHMOVE, touchInfo);
            FCGrid grid = Grid;
            if (m_band != null && grid != null) {
                FCPoint mp = touchInfo.m_firstPoint;
                if (AllowResize) {
                    ArrayList<FCBandedFCGridColumn> bandColumns = m_band.getColumns();
                    int columnsSize = bandColumns.size();
                    int index = -1;
                    int width = Width;
                    for (int i = 0; i < columnsSize; i++) {
                        if (this == bandColumns.get(i)) {
                            index = i;
                            break;
                        }
                    }
                    if (m_resizeState > 0) {
                        FCPoint curPoint = Native.TouchPoint;
                        int newWidth = m_beginWidth + (curPoint.x - m_touchDownPoint.x);
                        if (newWidth > 0) {
                            if (m_resizeState == 1) {
                                FCBandedFCGridColumn leftColumn = bandColumns.get(index - 1);
                                int leftWidth = leftColumn.Width;
                                leftColumn.Width = newWidth;
                                width += leftWidth - newWidth;
                                Width = width;
                            }
                            else if (m_resizeState == 2) {
                                Width = newWidth;
                                FCBandedFCGridColumn rightColumn = bandColumns.get(index + 1);
                                int rightWidth = rightColumn.Width;
                                rightWidth += width - newWidth;
                                rightColumn.Width = rightWidth;
                            }
                        }
                        grid.invalidate();
                        return;
                    }
                    else {
                        FCCursors oldCursor = Cursor;
                        FCCursors newCursor = oldCursor;
                        if ((index > 0 && mp.x < 5) || (index < columnsSize - 1 && mp.x > width - 5)) {
                            newCursor = FCCursors.SizeWE;
                        }
                        else {
                            newCursor = FCCursors.Arrow;
                        }
                        if (oldCursor != newCursor) {
                            Cursor = newCursor;
                            invalidate();
                        }
                    }
                    if (!IsDragging) {
                        Cursor = FCCursors.Arrow;
                    }
                }
            }
        }
    }
}
