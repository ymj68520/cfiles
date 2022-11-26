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
    /// ������ͷ���
    /// </summary>
    public class FCBandedGrid : FCGrid {
        /// <summary>
        /// ����������ͷ���
        /// </summary>
        public FCBandedGrid() {
        }

        /// <summary>
        /// ����
        /// </summary>
        protected ArrayList<FCGridBand> m_bands = new ArrayList<FCGridBand>();

        /// <summary>
        /// ��ȡ���пɼ����Ŀ��
        /// </summary>
        protected virtual int AllVisibleBandsWidth {
            get {
                int allVisibleBandsWidth = 0;
                int bandsSize = m_bands.size();
                for (int i = 0; i < bandsSize; i++) {
                    FCGridBand band = m_bands.get(i);
                    if (band.Visible) {
                        allVisibleBandsWidth += band.Width;
                    }
                }
                return allVisibleBandsWidth;
            }
        }

        /// <summary>
        /// ��ӱ���
        /// </summary>
        /// <param name="band">����</param>
        public void addBand(FCGridBand band) {
            band.Grid = this;
            m_bands.add(band);
            int bandSize = m_bands.size();
            for (int i = 0; i < bandSize; i++) {
                m_bands.get(i).Index = i;
            }
            addControl(band);
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="column">��</param>
        public override void addColumn(FCGridColumn column) {
            FCBandedFCGridColumn bandedColumn = column as FCBandedFCGridColumn;
            if (bandedColumn != null) {
                column.Grid = this;
                m_columns.add(column);
                addControl(column);
            }
        }

        /// <summary>
        /// �������
        /// </summary>
        public void clearBands() {
            int bandsSize = m_bands.size();
            for (int i = 0; i < bandsSize; i++) {
                FCGridBand band = m_bands.get(i);
                removeControl(band);
                band.delete();
            }
            m_bands.clear();
        }

        /// <summary>
        /// ������е���
        /// </summary>
        public override void clearColumns() {
        }

        /// <summary>
        /// ��ȡ�����б�
        /// </summary>
        /// <returns>��������</returns>
        public ArrayList<FCGridBand> getBands() {
            return m_bands;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "BandedGrid";
        }

        /// <summary>
        /// ��ȡ���ݵĿ��
        /// </summary>
        /// <returns>���</returns>
        public override int getContentWidth() {
            FCHScrollBar hScrollBar = HScrollBar;
            FCVScrollBar vScrollBar = VScrollBar;
            int wmax = 0;
            ArrayList<FCView> controls = m_controls;
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                if (control.Visible && control != hScrollBar && control != vScrollBar) {
                    int right = control.Right;
                    if (right > wmax) {
                        wmax = right;
                    }
                }
            }
            int allVisibleBandsWidth = AllVisibleBandsWidth;
            return wmax > allVisibleBandsWidth ? wmax : allVisibleBandsWidth;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="band">����</param>
        public void insertBand(int index, FCGridBand band) {
            band.Grid = this;
            m_bands.Insert(index, band);
            int bandSize = m_bands.size();
            for (int i = 0; i < bandSize; i++) {
                m_bands.get(i).Index = i;
            }
            addControl(band);
        }

        /// <summary>
        /// ���ÿؼ����ɼ�����
        /// </summary>
        public override void onSetEmptyClipRegion() {
            //���ؿؼ�
            ArrayList<FCView> controls = m_controls;
            int controlsSize = controls.size();
            FCRect emptyClipRect = new FCRect();
            for (int i = 0; i < controlsSize; i++) {
                FCView control = controls.get(i);
                FCScrollBar scrollBar = control as FCScrollBar;
                FCGridColumn gridColumn = control as FCGridColumn;
                FCGridBand gridBand = control as FCGridBand;
                if (control != EditTextBox && scrollBar == null && gridColumn == null && gridBand == null) {
                    control.Region = emptyClipRect;
                }
            }
        }

        /// <summary>
        /// �Ƴ�����
        /// </summary>
        /// <param name="band">����</param>
        public void removeBand(FCGridBand band) {
            if (m_bands.Contains(band)) {
                m_bands.remove(band);
                int bandSize = m_bands.size();
                for (int i = 0; i < bandSize; i++) {
                    m_bands.get(i).Index = i;
                }
                removeControl(band);
            }
        }

        /// <summary>
        /// �Ƴ���ͷ
        /// </summary>
        /// <param name="column">��ͷ</param>
        public override void removeColumn(FCGridColumn column) {
            FCBandedFCGridColumn bandedColumn = column as FCBandedFCGridColumn;
            if (bandedColumn != null) {
                m_columns.remove(column);
                removeControl(column);
            }
        }

        /// <summary>
        /// ������ͷ����
        /// </summary>
        public override void resetHeaderLayout() {
            int left = 0, top = 0, scrollH = 0;
            FCHScrollBar hScrollBar = HScrollBar;
            if (hScrollBar != null && hScrollBar.Visible) {
                scrollH = -hScrollBar.Pos;
            }
            int headerHeight = HeaderVisible ? HeaderHeight : 0;
            int horizontalOffset = HorizontalOffset;
            int verticalOffset = VerticalOffset;
            int bandsSize = m_bands.size();
            for (int i = 0; i < bandsSize; i++) {
                FCGridBand band = m_bands.get(i);
                if (band.Visible) {
                    int bandHeight = headerHeight < band.Height ? headerHeight : band.Height;
                    FCRect bandRect = new FCRect(left + horizontalOffset, top + verticalOffset,
                       left + horizontalOffset + band.Width, top + bandHeight + verticalOffset);
                    bool hasFrozenColumn = false;
                    ArrayList<FCBandedFCGridColumn> childColumns = band.getAllChildColumns();
                    int childColumnsSize = childColumns.size();
                    for (int j = 0; j < childColumnsSize; j++) {
                        if (childColumns.get(j).Frozen) {
                            hasFrozenColumn = true;
                            break;
                        }
                    }
                    if (!hasFrozenColumn) {
                        bandRect.left += scrollH;
                        bandRect.right += scrollH;
                    }
                    band.Bounds = bandRect;
                    band.resetHeaderLayout();
                    left += band.Width;
                }
            }
        }

        /// <summary>
        /// ���²���
        /// </summary>
        public override void update() {
            if (!m_lockUpdate) {
                int bandsSize = m_bands.size();
                //������е���
                int col = 0;
                for (int i = 0; i < bandsSize; i++) {
                    FCGridBand band = m_bands.get(i);
                    ArrayList<FCBandedFCGridColumn> childColumns = band.getAllChildColumns();
                    int childColumnsSize = childColumns.size();
                    for (int j = 0; j < childColumnsSize; j++) {
                        FCBandedFCGridColumn column = childColumns.get(j);
                        column.Index = col;
                        col++;
                    }
                }
            }
            base.update();
        }
    }
}
