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

namespace FaceCat {
    /// <summary>
    /// ����
    /// </summary>
    public class FCGridBand : FCButton {
        /// <summary>
        /// ��������
        /// </summary>
        public FCGridBand() {
            Width = 100;
        }

        /// <summary>
        /// �ӱ���
        /// </summary>
        protected ArrayList<FCGridBand> m_bands = new ArrayList<FCGridBand>();

        /// <summary>
        /// �ӱ����
        /// </summary>
        protected ArrayList<FCBandedFCGridColumn> m_columns = new ArrayList<FCBandedFCGridColumn>();

        /// <summary>
        /// ��ʼ���
        /// </summary>
        protected int m_beginWidth = 0;

        /// <summary>
        /// ������С״̬��1:��� 2:�Ҳ�
        /// </summary>
        protected int m_resizeState;

        /// <summary>
        /// ��������ʱ������
        /// </summary>
        protected FCPoint m_touchDownPoint;

        protected bool m_allowResize = false;

        /// <summary>
        /// ��ȡ�������Ƿ���Ե�����С
        /// </summary>
        public virtual bool AllowResize {
            get { return m_allowResize; }
            set { m_allowResize = value; }
        }

        protected FCBandedGrid m_grid;

        /// <summary>
        /// ��ȡ�����ñ��
        /// </summary>
        public virtual FCBandedGrid Grid {
            get { return m_grid; }
            set { m_grid = value; }
        }
        protected int m_index = -1;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual int Index {
            get { return m_index; }
            set { m_index = value; }
        }

        protected FCGridBand m_parentBand;

        /// <summary>
        /// ��ȡ�����ø�����
        /// </summary>
        public virtual FCGridBand ParentBand {
            get { return m_parentBand; }
            set { m_parentBand = value; }
        }

        /// <summary>
        /// ��ӱ���
        /// </summary>
        /// <param name="band">����</param>
        public void AddBand(FCGridBand band) {
            band.Grid = m_grid;
            band.ParentBand = this;
            m_bands.add(band);
            int bandSize = m_bands.size();
            for (int i = 0; i < bandSize; i++) {
                m_bands.get(i).Index = i;
            }
            m_grid.addControl(band);
        }

        /// <summary>
        /// ��ӱ����
        /// </summary>
        /// <param name="column">�����</param>
        public void AddColumn(FCBandedFCGridColumn column) {
            column.Band = this;
            m_columns.add(column);
            m_grid.addColumn(column);
        }

        /// <summary>
        /// �������
        /// </summary>
        public void ClearBands() {
            int bandsSize = m_bands.size();
            for (int i = 0; i < bandsSize; i++) {
                FCGridBand band = m_bands.get(i);
                m_grid.removeControl(band);
                band.delete();
            }
            m_bands.clear();
        }

        /// <summary>
        /// �����
        /// </summary>
        public void clearColumns() {
            int columnsSize = m_columns.size();
            for (int i = 0; i < columnsSize; i++) {
                FCBandedFCGridColumn column = m_columns.get(i);
                m_grid.removeColumn(column);
                column.delete();
            }
            m_columns.clear();
        }

        /// <summary>
        /// ��ȡ���е��ӱ����
        /// </summary>
        /// <returns>��ͷ����</returns>
        public ArrayList<FCBandedFCGridColumn> getAllChildColumns() {
            ArrayList<FCBandedFCGridColumn> columns = new ArrayList<FCBandedFCGridColumn>();
            int columnsSize = m_columns.size();
            for (int i = 0; i < columnsSize; i++) {
                FCBandedFCGridColumn column = m_columns.get(i);
                columns.add(column);
            }
            int bandsSize = m_bands.size();
            for (int i = 0; i < bandsSize; i++) {
                FCGridBand band = m_bands.get(i);
                ArrayList<FCBandedFCGridColumn> childColumns = band.getAllChildColumns();
                int childColumnsSize = childColumns.size();
                for (int j = 0; j < childColumnsSize; j++) {
                    FCBandedFCGridColumn childColumn = childColumns[j];
                    columns.add(childColumn);
                }
            }
            return columns;
        }

        /// <summary>
        /// ��ȡ�����б�
        /// </summary>
        /// <returns>��������</returns>
        public ArrayList<FCGridBand> getBands() {
            return m_bands;
        }

        /// <summary>
        /// ��ȡ��ͷ
        /// </summary>
        /// <returns>��ͷ����</returns>
        public ArrayList<FCBandedFCGridColumn> getColumns() {
            return m_columns;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "FCGridBand";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "allowresize") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowResize);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "AllowResize" });
            return propertyNames;
        }

        /// <summary>
        /// ���ٿؼ�
        /// </summary>
        public override void delete() {
            ClearBands();
            clearColumns();
            base.delete();
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="band">����</param>
        public void insertBand(int index, FCGridBand band) {
            band.Grid = m_grid;
            band.ParentBand = this;
            m_bands.Insert(index, band);
            int bandSize = m_bands.size();
            for (int i = 0; i < bandSize; i++) {
                m_bands.get(i).Index = i;
            }
            m_grid.addControl(band);
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="column">�����</param>
        public void insertColumn(int index, FCBandedFCGridColumn column) {
            column.Band = this;
            m_columns.Insert(index, column);
            m_grid.addColumn(column);
        }

        /// <summary>
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1) {
                if (m_allowResize) {
                    ArrayList<FCGridBand> bands = null;
                    if (m_parentBand != null) {
                        bands = m_parentBand.getBands();
                    }
                    else {
                        bands = m_grid.getBands();
                    }
                    int bandsSize = bands.size();
                    if (m_index > 0 && touchInfo.m_firstPoint.x < 5) {
                        m_resizeState = 1;
                        m_beginWidth = bands[m_index - 1].Width;
                    }
                    else if ((m_parentBand == null || m_index < bandsSize - 1) && touchInfo.m_firstPoint.x > Width - 5) {
                        m_resizeState = 2;
                        m_beginWidth = Width;
                    }
                    m_touchDownPoint = Native.TouchPoint;
                }
            }
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
            if (m_allowResize) {
                ArrayList<FCGridBand> bands = null;
                if (m_parentBand != null) {
                    bands = m_parentBand.getBands();
                }
                else {
                    bands = m_grid.getBands();
                }
                int bandsSize = bands.size();
                int width = Width;
                if (m_resizeState > 0) {
                    FCPoint curPoint = Native.TouchPoint;
                    int newWidth = m_beginWidth + (curPoint.x - m_touchDownPoint.x);
                    if (newWidth > 0) {
                        if (m_resizeState == 1) {
                            FCGridBand leftBand = bands[m_index - 1];
                            int leftWidth = leftBand.Width;
                            leftBand.Width = newWidth;
                            width += leftWidth - newWidth;
                            Width = width;
                        }
                        else if (m_resizeState == 2) {
                            Width = newWidth;
                            if (m_index < bandsSize - 1) {
                                FCGridBand rightBand = bands[m_index + 1];
                                int rightWidth = rightBand.Width;
                                rightWidth += width - newWidth;
                                rightBand.Width = rightWidth;
                            }
                            else {
                                if (m_grid != null) {
                                    m_grid.resetHeaderLayout();
                                    m_grid.update();
                                }
                            }
                        }
                    }
                    if (m_grid != null) {
                        m_grid.invalidate();
                    }
                }
                else {
                    if ((m_index > 0 && touchInfo.m_firstPoint.x < 5) || ((m_parentBand == null || m_index < bandsSize - 1) && touchInfo.m_firstPoint.x > width - 5)) {
                        Cursor = FCCursors.SizeWE;
                    }
                    else {
                        Cursor = FCCursors.Arrow;
                    }
                }
            }
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInfo) {
            base.onTouchUp(touchInfo);
            if (m_resizeState != 0) {
                Cursor = FCCursors.Arrow;
                m_resizeState = 0;
                if (m_grid != null) {
                    m_grid.invalidate();
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
                m_grid.removeControl(band);
            }
        }

        /// <summary>
        /// �Ƴ������
        /// </summary>
        /// <param name="column">�����</param>
        public void removeColumn(FCBandedFCGridColumn column) {
            if (m_columns.Contains(column)) {
                m_columns.remove(column);
                m_grid.removeColumn(column);
            }
        }

        /// <summary>
        /// ������ͷ����
        /// </summary>
        public virtual void resetHeaderLayout() {
            int bandsSize = m_bands.size();
            FCRect bounds = Bounds;
            int left = bounds.left;
            int width = Width;
            if (bandsSize == 0) {
                int scrollH = 0;
                FCHScrollBar hScrollBar = Grid.HScrollBar;
                if (hScrollBar != null && hScrollBar.Visible) {
                    scrollH = -hScrollBar.Pos;
                }
                int columnsSize = m_columns.size();
                for (int i = 0; i < columnsSize; i++) {
                    FCBandedFCGridColumn column = m_columns.get(i);
                    if (column.Visible) {
                        int columnWidth = column.Width;
                        if (i == columnsSize - 1 || left + columnWidth > width + bounds.left) {
                            columnWidth = width + bounds.left - left;
                        }
                        FCRect cellRect = new FCRect(left, bounds.bottom, left + columnWidth, bounds.bottom + column.Height);
                        column.Bounds = cellRect;
                        cellRect.left -= scrollH;
                        cellRect.right -= scrollH;
                        column.HeaderRect = cellRect;
                        left += columnWidth;
                    }
                }
            }
            else {
                for (int i = 0; i < bandsSize; i++) {
                    FCGridBand band = m_bands.get(i);
                    if (band.Visible) {
                        int bandWidth = band.Width;
                        if (i == bandsSize - 1 || left + bandWidth > width + bounds.left) {
                            bandWidth = width + bounds.left - left;
                        }
                        FCRect cellRect = new FCRect(left, bounds.bottom, left + bandWidth, bounds.bottom + band.Height);
                        band.Bounds = cellRect;
                        band.resetHeaderLayout();
                        left += bandWidth;
                    }
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "allowresize") {
                AllowResize = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
