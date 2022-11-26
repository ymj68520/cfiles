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
    /// ����е���ʽ
    /// </summary>
    public class FCGridRowStyle {
        protected long m_backColor = FCColor.Back;

        /// <summary>
        /// ��ȡ
        /// </summary>
        public virtual long BackColor {
            get { return m_backColor; }
            set { m_backColor = value; }
        }

        protected FCFont m_font = new FCFont("Simsun", 14, false, false, false);

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual FCFont Font {
            get { return m_font; }
            set { m_font = value; }
        }

        protected long m_hoveredBackColor = FCColor.argb(150, 150, 150);

        /// <summary>
        /// ��ȡ�����ô�����ͣ�еı���ɫ
        /// </summary>
        public virtual long HoveredBackColor {
            get { return m_hoveredBackColor; }
            set { m_hoveredBackColor = value; }
        }

        protected long m_hoveredTextColor = FCColor.Text;

        /// <summary>
        /// ��ȡ�����ô�����ͣ�е�ǰ��ɫ
        /// </summary>
        public virtual long HoveredTextColor {
            get { return m_hoveredTextColor; }
            set { m_hoveredTextColor = value; }
        }

        protected long m_selectedBackColor = FCColor.argb(100, 100, 100);

        /// <summary>
        /// ��ȡ������ѡ���еı���ɫ
        /// </summary>
        public virtual long SelectedBackColor {
            get { return m_selectedBackColor; }
            set { m_selectedBackColor = value; }
        }

        protected long m_selectedTextColor = FCColor.Text;

        /// <summary>
        /// ��ȡ������ѡ���е�ǰ��ɫ
        /// </summary>
        public virtual long SelectedTextColor {
            get { return m_selectedTextColor; }
            set { m_selectedTextColor = value; }
        }

        protected long m_textColor = FCColor.Text;

        /// <summary>
        /// ��ȡ������ǰ��ɫ
        /// </summary>
        public virtual long TextColor {
            get { return m_textColor; }
            set { m_textColor = value; }
        }
    }

    /// <summary>
    /// ��Ԫ��
    /// </summary>
    public class FCGridRow : FCProperty {
        /// <summary>
        /// ������
        /// </summary>
        public FCGridRow() {
        }

        /// <summary>
        /// ��������
        /// </summary>
        ~FCGridRow() {
            delete();
        }

        /// <summary>
        /// ���е�Ԫ��
        /// </summary>
        public ArrayList<FCGridCell> m_cells = new ArrayList<FCGridCell>();

        /// <summary>
        /// �༭״̬
        /// </summary>
        public int m_editState;

        protected bool m_allowEdit;

        /// <summary>
        /// ��ȡ�������Ƿ�����༭
        /// </summary>
        public virtual bool AllowEdit {
            get { return m_allowEdit; }
            set { m_allowEdit = value; }
        }

        protected FCRect m_bounds;

        /// <summary>
        /// ��ȡ��������ʾ����
        /// </summary>
        public virtual FCRect Bounds {
            get { return m_bounds; }
            set { m_bounds = value; }
        }

        protected FCView m_editButton;

        /// <summary>
        /// ��ȡ�����ñ༭��ť
        /// </summary>
        public virtual FCView EditButton {
            get { return m_editButton; }
            set { m_editButton = value; }
        }

        protected FCGrid m_grid;

        /// <summary>
        /// ��ȡ���������ڱ��
        /// </summary>
        public virtual FCGrid Grid {
            get { return m_grid; }
            set { m_grid = value; }
        }

        protected int height = 20;

        /// <summary>
        /// ��ȡ�������и�
        /// </summary>
        public virtual int Height {
            get { return height; }
            set { height = value; }
        }

        protected int m_horizontalOffset = 0;

        /// <summary>
        /// ��ȡ�����ú����������
        /// </summary>
        public virtual int HorizontalOffset {
            get { return m_horizontalOffset; }
            set { m_horizontalOffset = value; }
        }

        protected int m_index = -1;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual int Index {
            get { return m_index; }
            set { m_index = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected object m_tag = null;

        /// <summary>
        /// ��ȡ������TAGֵ
        /// </summary>
        public virtual object Tag {
            get { return m_tag; }
            set { m_tag = value; }
        }

        protected bool m_visible = true;

        /// <summary>
        /// ��ȡ�������Ƿ�ɼ�
        /// </summary>
        public virtual bool Visible {
            get { return m_visible; }
            set { m_visible = value; }
        }

        protected int m_visibleIndex = -1;

        /// <summary>
        /// ��ȡ�����ÿɼ�����
        /// </summary>
        public virtual int VisibleIndex {
            get { return m_visibleIndex; }
            set { m_visibleIndex = value; }
        }

        /// <summary>
        /// ��ӵ�Ԫ��
        /// </summary>
        /// <param name="column">������</param>
        /// <param name="cell">��Ԫ��</param>
        public void addCell(FCGridColumn column, FCGridCell cell) {
            cell.Grid = m_grid;
            cell.Column = column;
            cell.Row = this;
            m_cells.add(cell);
            cell.onAdd();
        }

        /// <summary>
        /// ��ӵ�Ԫ��
        /// </summary>
        /// <param name="columnIndex">������</param>
        /// <param name="cell">��Ԫ��</param>
        public void addCell(int columnIndex, FCGridCell cell) {
            cell.Grid = m_grid;
            cell.Column = m_grid.getColumn(columnIndex);
            cell.Row = this;
            m_cells.add(cell);
            cell.onAdd();
        }

        /// <summary>
        /// ��ӵ�Ԫ��
        /// </summary>
        /// <param name="columnName">����</param>
        /// <param name="cell">��Ԫ��</param>
        public void addCell(String columnName, FCGridCell cell) {
            cell.Grid = m_grid;
            cell.Column = m_grid.getColumn(columnName);
            cell.Row = this;
            m_cells.add(cell);
            cell.onAdd();
        }

        /// <summary>
        /// �����Ԫ��
        /// </summary>
        public void clearCells() {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                m_cells.get(i).onRemove();
                m_cells.get(i).delete();
            }
            m_cells.clear();
        }

        /// <summary>
        /// ���ٶ���
        /// </summary>
        public void delete() {
            if (!m_isDeleted) {
                m_editButton = null;
                m_isDeleted = !m_isDeleted;
                int cellSize = m_cells.size();
                for (int i = 0; i < cellSize; i++) {
                    m_cells.get(i).delete();
                }
                m_cells.clear();
            }
        }

        /// <summary>
        /// �����л�ȡ��Ԫ��
        /// </summary>
        /// <param name="column">��</param>
        /// <returns>��Ԫ��</returns>
        public FCGridCell getCell(FCGridColumn column) {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                if (m_cells.get(i).Column == column) {
                    return m_cells.get(i);
                }
            }
            return null;
        }

        /// <summary>
        /// �����е�������ȡ��Ԫ��
        /// </summary>
        /// <returns>��Ԫ��</returns>
        public FCGridCell getCell(int columnIndex) {
            int cellsSize = m_cells.size();
            if (cellsSize > 0) {
                if (columnIndex >= 0 && columnIndex < cellsSize) {
                    if (m_cells.get(columnIndex).Column.Index == columnIndex) {
                        return m_cells.get(columnIndex);
                    }
                }
                for (int i = 0; i < cellsSize; i++) {
                    if (m_cells.get(i).Column.Index == columnIndex) {
                        return m_cells.get(i);
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// �����е����ƻ�ȡ��Ԫ��
        /// </summary>
        /// <param name="columnName">����</param>
        /// <returns>��Ԫ��</returns>
        public FCGridCell getCell(String columnName) {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                if (m_cells.get(i).Column.Name == columnName) {
                    return m_cells.get(i);
                }
            }
            return null;
        }

        /// <summary>
        /// ��ȡ���е�Ԫ��
        /// </summary>
        /// <returns>���е�Ԫ��</returns>
        public ArrayList<FCGridCell> getCells() {
            return m_cells;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "allowedit") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowEdit);
            }
            else if (name == "height") {
                type = "int";
                value = FCStr.convertIntToStr(Height);
            }
            else if (name == "visible") {
                type = "int";
                value = FCStr.convertBoolToStr(Visible);
            }
            else {
                type = "undefined";
                value = "";
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "AllowEdit", "EditorWidth", "Height", "Visible" });
            return propertyNames;
        }

        /// <summary>
        /// ����з���
        /// </summary>
        public virtual void onAdd() {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                m_cells.get(i).onAdd();
            }
        }


        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        /// <param name="isAlternate">�Ƿ�����</param>
        public virtual void onPaint(FCPaint paint, FCRect clipRect, bool isAlternate) {

        }

        /// <summary>
        /// �ػ���߷���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        /// <param name="isAlternate">�Ƿ�����</param>
        public virtual void onPaintBorder(FCPaint paint, FCRect clipRect, bool isAlternate) {

        }

        /// <summary>
        /// �Ƴ��з���
        /// </summary>
        public virtual void onRemove() {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                m_cells.get(i).onRemove();
            }
        }

        /// <summary>
        /// �Ƴ���Ԫ��
        /// </summary>
        /// <param name="column">��</param>
        public void removeCell(FCGridColumn column) {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                FCGridCell cell = m_cells.get(i);
                if (cell.Column == column) {
                    m_cells.remove(cell);
                    cell.onRemove();
                    break;
                }
            }
        }

        /// <summary>
        /// �Ƴ���Ԫ��
        /// </summary>
        /// <param name="columnIndex">������</param>
        public void removeCell(int columnIndex) {
            int cellSize = m_cells.size();
            if (columnIndex >= 0 && columnIndex < cellSize) {
                FCGridCell cell = m_cells.get(columnIndex);
                if (cell.Column.Index == columnIndex) {
                    m_cells.remove(cell);
                    cell.onRemove();
                    return;
                }
                for (int i = 0; i < cellSize; i++) {
                    cell = m_cells.get(i);
                    if (cell.Column.Index == columnIndex) {
                        m_cells.remove(cell);
                        cell.onRemove();
                        break;
                    }
                }
            }
        }

        /// <summary>
        /// �Ƴ���Ԫ��
        /// </summary>
        /// <param name="columnName">����</param>
        public void removeCell(String columnName) {
            int cellSize = m_cells.size();
            for (int i = 0; i < cellSize; i++) {
                FCGridCell cell = m_cells.get(i);
                if (cell.Column.Name == columnName) {
                    m_cells.remove(cell);
                    cell.onRemove();
                    break;
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "allowedit") {
                AllowEdit = FCStr.convertStrToBool(value);
            }
            else if (name == "height") {
                Height = FCStr.convertStrToInt(value);
            }
            else if (name == "visible") {
                Visible = FCStr.convertStrToBool(value);
            }
        }
    }
}
