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
    /// �����
    /// </summary>
    public class FCGridColumn : FCButton {
        /// <summary>
        /// ������
        /// </summary>
        public FCGridColumn() {
            Width = 100;
        }

        /// <summary>
        /// ������
        /// </summary>
        /// <param name="text">����</param>
        public FCGridColumn(String text) {
            Text = text;
            Width = 100;
        }

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

        protected bool m_allowSort = true;

        /// <summary>
        /// ��ȡ�������Ƿ��������
        /// </summary>
        public virtual bool AllowSort {
            get { return m_allowSort; }
            set { m_allowSort = value; }
        }

        protected FCHorizontalAlign m_cellAlign = FCHorizontalAlign.Left;

        /// <summary>
        /// ��ȡ���������ݵĺ���������ʽ
        /// </summary>
        public virtual FCHorizontalAlign CellAlign {
            get { return m_cellAlign; }
            set { m_cellAlign = value; }
        }

        protected String m_columnType = "";

        /// <summary>
        /// ��ȡ�������е�����
        /// </summary>
        public virtual String ColumnType {
            get { return m_columnType; }
            set { m_columnType = value; }
        }

        protected bool m_frozen = false;

        /// <summary>
        /// ��ȡ�������Ƿ񶳽�
        /// </summary>
        public virtual bool Frozen {
            get { return m_frozen; }
            set { m_frozen = value; }
        }

        protected FCGrid m_grid;

        /// <summary>
        /// ��ȡ�����ñ��
        /// </summary>
        public virtual FCGrid Grid {
            get { return m_grid; }
            set { m_grid = value; }
        }

        protected FCRect m_headerRect;

        /// <summary>
        /// ��ȡ������ͷ���ľ���
        /// </summary>
        public virtual FCRect HeaderRect {
            get { return m_headerRect; }
            set { m_headerRect = value; }
        }

        protected int m_index = -1;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual int Index {
            get { return m_index; }
            set { m_index = value; }
        }

        protected FCGridColumnSortMode m_sortMode = FCGridColumnSortMode.None;

        /// <summary>
        /// ��ȡ����������״̬��0:������ 1:���� 2:����
        /// </summary>
        public virtual FCGridColumnSortMode SortMode {
            get { return m_sortMode; }
            set { m_sortMode = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "FCGridColumn";
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
            else if (name == "allowsort") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowSort);
            }
            else if (name == "cellalign") {
                type = "enum:FCHorizontalAlign";
                value = FCStr.convertHorizontalAlignToStr(CellAlign);
            }
            else if (name == "columntype") {
                type = "text";
                value = ColumnType;
            }
            else if (name == "frozen") {
                type = "bool";
                value = FCStr.convertBoolToStr(Frozen);
            }
            else {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "AllowResize", "AllowSort", "CellAlign", "ColumnType", "Frozen" });
            return propertyNames;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            base.onClick(touchInfo);
            if (m_resizeState == 0) {
                switch (m_sortMode) {
                    case FCGridColumnSortMode.None:
                    case FCGridColumnSortMode.Desc:
                        m_grid.sortColumn(m_grid, this, FCGridColumnSortMode.Asc);
                        break;
                    case FCGridColumnSortMode.Asc:
                        m_grid.sortColumn(m_grid, this, FCGridColumnSortMode.Desc);
                        break;
                }
            }
        }

        /// <summary>
        /// �϶���ʼ����
        /// </summary>
        /// <returns>�Ƿ��϶�</returns>
        public override bool onDragBegin() {
            return m_resizeState == 0;
        }

        /// <summary>
        /// �϶��з���
        /// </summary>
        public override void onDragging() {
            base.onDragging();
            if (m_grid != null) {
                ArrayList<FCGridColumn> columns = m_grid.getColumns();
                int columnSize = columns.size();
                for (int i = 0; i < columnSize; i++) {
                    FCGridColumn column = columns.get(i);
                    if (column == this) {
                        FCGridColumn lastColumn = null;
                        FCGridColumn nextColumn = null;
                        int lastIndex = i - 1;
                        int nextIndex = i + 1;
                        while (lastIndex >= 0) {
                            FCGridColumn thatColumn = columns.get(lastIndex);
                            if (thatColumn.Visible) {
                                lastColumn = thatColumn;
                                break;
                            }
                            else {
                                lastIndex--;
                            }
                        }
                        while (nextIndex < columnSize) {
                            FCGridColumn thatColumn = columns.get(nextIndex);
                            if (thatColumn.Visible) {
                                nextColumn = thatColumn;
                                break;
                            }
                            else {
                                nextIndex++;
                            }
                        }
                        //������
                        FCNative native = Native;
                        int clientX = native.clientX(this);
                        if (lastColumn != null) {
                            int lastClientX = native.clientX(lastColumn);
                            if (clientX < lastClientX + lastColumn.Width / 2) {
                                columns.set(lastIndex, this);
                                columns.set(i, lastColumn);
                                m_grid.update();
                                break;
                            }
                        }
                        if (nextColumn != null) {
                            int nextClientX = native.clientX(nextColumn);
                            if (clientX + column.Width > nextClientX + nextColumn.Width / 2) {
                                columns.set(nextIndex, this);
                                columns.set(i, nextColumn);
                                m_grid.update();
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        /// <summary>
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            if (touchInfo.m_firstTouch && touchInfo.m_clicks == 1) {
                FCPoint mp = touchInfo.m_firstPoint;
                if (m_allowResize) {
                    if (m_index > 0 && mp.x < 5) {
                        m_resizeState = 1;
                        m_beginWidth = Grid.getColumn(m_index - 1).Width;
                    }
                    else if (mp.x > Width - 5) {
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
                FCPoint mp = touchInfo.m_firstPoint;
                if (m_resizeState > 0) {
                    FCPoint curPoint = Native.TouchPoint;
                    int newWidth = m_beginWidth + (curPoint.x - m_touchDownPoint.x);
                    if (newWidth > 0) {
                        if (m_resizeState == 1) {
                            Grid.getColumn(m_index - 1).Width = newWidth;
                        }
                        else if (m_resizeState == 2) {
                            Width = newWidth;
                        }
                    }
                    if (m_grid != null) {
                        m_grid.update();
                        m_grid.invalidate();
                    }
                }
                else {
                    if ((m_index > 0 && mp.x < 5) || mp.x > Width - 5) {
                        Cursor = FCCursors.SizeWE;
                    }
                    else {
                        Cursor = FCCursors.Arrow;
                    }
                }
                if (IsDragging) {
                    Cursor = FCCursors.Arrow;
                }
            }
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInfo) {
            base.onTouchUp(touchInfo);
            Cursor = FCCursors.Arrow;
            m_resizeState = 0;
            if (m_grid != null) {
                m_grid.invalidate();
            }
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            base.onPaintForeground(paint, clipRect);
            if (Native != null && m_grid != null) {
                FCRect rect = new FCRect(0, 0, Width, Height);
                int tLeft = rect.right - 15;
                int midTop = rect.top + (rect.bottom - rect.top) / 2;
                long textColor = getPaintingTextColor();
                //����
                if (m_sortMode == FCGridColumnSortMode.Asc) {
                    FCPoint[] points = new FCPoint[3] 
                    { 
                        new FCPoint(tLeft + 5, midTop - 5), 
                        new FCPoint(tLeft, midTop + 5), 
                        new FCPoint(tLeft + 10, midTop + 5) 
                    };
                    paint.fillPolygon(textColor, points);
                }
                //����
                else if (m_sortMode == FCGridColumnSortMode.Desc) {
                    FCPoint[] points = new FCPoint[3] 
                    { 
                        new FCPoint(tLeft + 5, midTop + 5), 
                        new FCPoint(tLeft, midTop - 5), 
                        new FCPoint(tLeft + 10, midTop - 5) 
                    };
                    paint.fillPolygon(textColor, points);
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
            else if (name == "allowsort") {
                AllowSort = FCStr.convertStrToBool(value);
            }
            else if (name == "cellalign") {
                CellAlign = FCStr.convertStrToHorizontalAlign(value);
            }
            else if (name == "columntype") {
                ColumnType = value;
            }
            else if (name == "frozen") {
                Frozen = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
