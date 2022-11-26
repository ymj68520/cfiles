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
    /// ���ڵ�
    /// </summary>
    public class FCTreeNode : FCGridControlCell {
        /// <summary>
        /// �����ڵ�
        /// </summary>
        public FCTreeNode() {
        }

        /// <summary>
        /// ��������
        /// </summary>
        ~FCTreeNode() {
            m_nodes.clear();
        }

        /// <summary>
        /// �ӽڵ�
        /// </summary>
        public ArrayList<FCTreeNode> m_nodes = new ArrayList<FCTreeNode>();

        /// <summary>
        /// ����
        /// </summary>
        protected String m_text;

        protected bool m_allowDragIn = false;

        /// <summary>
        /// ��ȡ�������Ƿ��������ڵ�
        /// </summary>
        public virtual bool AllowDragIn {
            get { return m_allowDragIn; }
            set { m_allowDragIn = value; }
        }

        protected bool m_allowDragOut = false;

        /// <summary>
        /// ��ȡ�������Ƿ�����ϳ��ڵ�
        /// </summary>
        public virtual bool AllowDragOut {
            get { return m_allowDragOut; }
            set { m_allowDragOut = value; }
        }

        protected bool m_checked = false;

        /// <summary>
        /// ��ȡ�����ø�ѡ���Ƿ�ѡ��
        /// </summary>
        public virtual bool Checked {
            get { return m_checked; }
            set {
                if (m_checked != value) {
                    m_checked = value;
                    checkChildNodes(m_nodes, m_checked);
                }
            }
        }

        protected bool m_expended = true;

        /// <summary>
        /// ��ȡ�������Ƿ�չ���ڵ�
        /// </summary>
        public virtual bool Expended {
            get { return m_expended; }
            set { m_expended = value; }
        }

        protected FCTreeNode m_parent;

        /// <summary>
        /// ��ȡ�����ø��ڵ�
        /// </summary>
        public virtual FCTreeNode Parent {
            get { return m_parent; }
            set { m_parent = value; }
        }

        protected FCGridColumn m_targetColumn;

        /// <summary>
        /// ��ȡ������Ŀ����
        /// </summary>
        public virtual FCGridColumn TargetColumn {
            get { return m_targetColumn; }
            set { m_targetColumn = value; }
        }

        protected int m_indent;

        /// <summary>
        /// ��ȡ������������
        /// </summary>
        public virtual int Indent {
            get { return m_indent; }
        }

        protected FCTree m_tree;

        /// <summary>
        /// ��ȡ���������ؼ�
        /// </summary>
        public virtual FCTree Tree {
            get { return m_tree; }
            set { m_tree = value; }
        }

        protected String m_value;

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        public virtual String Value {
            get { return m_value; }
            set { m_value = value; }
        }

        /// <summary>
        /// ��ӽڵ�
        /// </summary>
        /// <param name="node">�ڵ�</param>
        public void appendNode(FCTreeNode node) {
            node.Parent = this;
            node.Tree = m_tree;
            node.onAddingNode(-1);
            m_nodes.add(node);
        }

        /// <summary>
        /// ѡ�������ӽڵ�
        /// </summary>
        /// <param name="nodes">�ڵ㼯��</param>
        /// <param name="isChecked">�Ƿ�ѡ��</param>
        protected void checkChildNodes(ArrayList<FCTreeNode> nodes, bool isChecked) {
            int nodeSize = m_nodes.size();
            for (int i = 0; i < nodeSize; i++) {
                FCTreeNode node = nodes.get(i);
                node.Checked = isChecked;
                ArrayList<FCTreeNode> childNodes = node.getChildNodes();
                if (childNodes != null && childNodes.size() > 0) {
                    checkChildNodes(childNodes, isChecked);
                }
            }
        }

        /// <summary>
        /// ������нڵ�
        /// </summary>
        public void clearNodes() {
            while (m_nodes.size() > 0) {
                removeNode(m_nodes.get(m_nodes.size() - 1));
            }
        }

        /// <summary>
        /// �۵��ڵ�
        /// </summary>
        public void collapse() {
            if (m_nodes.size() > 0) {
                m_expended = false;
                collapseChildNodes(m_nodes, false);
            }
        }

        /// <summary>
        /// �۵����нڵ�
        /// </summary>
        public void collapseAll() {
            if (m_nodes.size() > 0) {
                m_expended = false;
                collapseChildNodes(m_nodes, true);
            }
        }

        /// <summary>
        /// �۵��ӽڵ�
        /// </summary>
        /// <param name="nodes">�ڵ㼯��</param>
        /// <param name="expendAll">�Ƿ��۵����ӽڵ�</param>
        protected void collapseChildNodes(ArrayList<FCTreeNode> nodes, bool collapseAll) {
            int nodeSize = nodes.size();
            for (int i = 0; i < nodeSize; i++) {
                FCTreeNode node = nodes.get(i);
                if (collapseAll) {
                    node.Expended = false;
                }
                node.Row.Visible = false;
                ArrayList<FCTreeNode> childNodes = node.getChildNodes();
                if (childNodes != null && childNodes.size() > 0) {
                    collapseChildNodes(childNodes, collapseAll);
                }
            }
        }

        /// <summary>
        /// չ���ڵ�
        /// </summary>
        public void expend() {
            if (m_nodes.size() > 0) {
                m_expended = true;
                expendChildNodes(m_nodes, true, false);
            }
        }

        /// <summary>
        /// չ�����нڵ�
        /// </summary>
        public void expendAll() {
            if (m_nodes.size() > 0) {
                m_expended = true;
                expendChildNodes(m_nodes, true, true);
            }
        }

        /// <summary>
        /// չ�����еĽڵ�
        /// </summary>
        /// <param name="nodes">�ڵ㼯��</param>
        /// <param name="parentExpened">���ڵ��Ƿ�չ��</param>
        /// <param name="expendAll">���ӽڵ��Ƿ�չ��</param>
        protected void expendChildNodes(ArrayList<FCTreeNode> nodes, bool parentExpened, bool expendAll) {
            int nodeSize = nodes.size();
            for (int i = 0; i < nodeSize; i++) {
                FCTreeNode node = nodes.get(i);
                bool pExpended = parentExpened;
                if (expendAll) {
                    pExpended = true;
                    node.Row.Visible = true;
                    node.Expended = true;
                }
                else {
                    if (parentExpened) {
                        node.Row.Visible = true;
                    }
                    else {
                        node.Row.Visible = false;
                    }
                    if (!node.Expended) {
                        pExpended = false;
                    }
                }
                ArrayList<FCTreeNode> childNodes = node.getChildNodes();
                if (childNodes != null && childNodes.size() > 0) {
                    expendChildNodes(childNodes, pExpended, expendAll);
                }
            }
        }

        /// <summary>
        /// ��ȡ�ӽڵ�
        /// </summary>
        /// <returns>�ӽڵ�</returns>
        public ArrayList<FCTreeNode> getChildNodes() {
            return m_nodes;
        }

        /// <summary>
        /// ��ȡ���ڵ������
        /// </summary>
        /// <param name="nodes">�ڵ�</param>
        /// <returns>����</returns>
        protected FCTreeNode getLastNode(ArrayList<FCTreeNode> nodes) {
            int size = nodes.size();
            if (size > 0) {
                for (int i = size - 1; i >= 0; i--) {
                    FCTreeNode lastNode = nodes.get(i);
                    if (lastNode.Row != null) {
                        ArrayList<FCTreeNode> childNodes = lastNode.getChildNodes();
                        FCTreeNode subLastNode = getLastNode(childNodes);
                        if (subLastNode != null) {
                            return subLastNode;
                        }
                        else {
                            return lastNode;
                        }
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// ��ȡ�ڵ������
        /// </summary>
        /// <param name="node">�ڵ�</param>
        /// <returns>����</returns>
        public int getNodeIndex(FCTreeNode node) {
            int nodeSize = m_nodes.size();
            for (int i = 0; i < nodeSize; i++) {
                if (m_nodes.get(i) == node) {
                    return i;
                }
            }
            return -1;
        }

        /// <summary>
        /// ��ȡҪ���Ƶ��ı�
        /// </summary>
        /// <returns>Ҫ���Ƶ��ı�</returns>
        public override String getPaintText() {
            return Text;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "allowdragin") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowDragIn);
            }
            else if (name == "allowdragout") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowDragOut);
            }
            else if (name == "checked") {
                type = "bool";
                value = FCStr.convertBoolToStr(Checked);
            }
            else if (name == "expended") {
                type = "bool";
                value = FCStr.convertBoolToStr(Expended);
            }
            else if (name == "value") {
                type = "String";
                value = Value;
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
            propertyNames.AddRange(new String[] { "AllowDragIn", "AllowDragOut", "Checked", "Expended", "Value" });
            return propertyNames;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_text;
        }

        /// <summary>
        /// ����ڵ�
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="node">�ڵ�</param>
        public void insertNode(int index, FCTreeNode node) {
            int rowIndex = -1;
            if (index == 0) {
                if (node.Parent != null) {
                    rowIndex = node.Parent.Row.Index + 1;
                }
                else {
                    rowIndex = 0;
                }
            }
            else {
                if (m_nodes.size() > 0) {
                    rowIndex = m_nodes.get(index).Row.Index;
                }
            }
            node.Tree = m_tree;
            node.Parent = this;
            node.onAddingNode(rowIndex);
            m_nodes.Insert(index, node);
        }

        /// <summary>
        /// ���ڵ��Ƿ�ɼ�
        /// </summary>
        /// <param name="node">�ڵ�</param>
        /// <returns>�Ƿ�ɼ�</returns>
        public bool isNodeVisible(FCTreeNode node) {
            FCTreeNode parentNode = node.Parent;
            if (parentNode != null) {
                if (!parentNode.Expended) {
                    return false;
                }
                else {
                    return isNodeVisible(parentNode);
                }
            }
            else {
                return true;
            }
        }

        /// <summary>
        /// ��ӽڵ�
        /// </summary>
        /// <param name="index">������</param>
        public virtual void onAddingNode(int index) {
            FCGridRow row = Row;
            if (Row == null) {
                //������
                row = new FCGridRow();
                FCTreeNode parentNode = m_parent;
                if (parentNode == null) {
                    if (index != -1) {
                        //������
                        m_tree.insertRow(index, row);
                        //�����е�����
                        ArrayList<FCGridRow> rows = m_tree.getRows();
                        int rowSize = rows.size();
                        for (int i = 0; i < rowSize; i++) {
                            rows.get(i).Index = i;
                        }
                    }
                    else {
                        //�����
                        m_tree.addRow(row);
                        //��������
                        ArrayList<FCGridRow> rows = m_tree.getRows();
                        row.Index = rows.size() - 1;
                    }
                    row.addCell(0, this);
                    m_targetColumn = m_tree.getColumn(0);
                }
                else {
                    //��ȡ������
                    int rowIndex = parentNode.Row.Index + 1;
                    if (index != -1) {
                        rowIndex = index;
                    }
                    else {
                        //�����ϸ��ڵ�      
                        FCTreeNode lastNode = getLastNode(parentNode.getChildNodes());
                        if (lastNode != null) {
                            if (lastNode.Row == null) {
                                return;
                            }
                            rowIndex = lastNode.Row.Index + 1;
                        }
                    }
                    //������
                    m_tree.insertRow(rowIndex, row);
                    ArrayList<FCGridRow> rows = m_tree.getRows();
                    int rowSize = rows.size();
                    //��������
                    if (rowIndex == rowSize - 1) {
                        row.Index = rowIndex;
                    }
                    else {
                        for (int i = 0; i < rowSize; i++) {
                            rows.get(i).Index = i;
                        }
                    }
                    row.addCell(0, this);
                    m_targetColumn = m_tree.getColumn(parentNode.m_targetColumn.Index + 1);
                }
                ColSpan = m_tree.getColumns().size();
                //����ӽڵ�
                if (m_nodes != null && m_nodes.size() > 0) {
                    int nodeSize = m_nodes.size();
                    for (int i = 0; i < nodeSize; i++) {
                        m_nodes.get(i).onAddingNode(-1);
                    }
                }
                row.Visible = isNodeVisible(this);
            }
        }

        /// <summary>
        /// ���Ƹ�ѡ��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        public virtual void onPaintCheckBox(FCPaint paint, FCRect rect) {
            if (m_checked) {
                if (m_tree.CheckedImage != null && m_tree.CheckedImage.Length > 0) {
                    paint.drawImage(m_tree.CheckedImage, rect);
                }
                else {
                    paint.fillRect(FCColor.argb(0, 0, 0), rect);
                }
            }
            else {
                if (m_tree.UnCheckedImage != null && m_tree.UnCheckedImage.Length > 0) {
                    paint.drawImage(m_tree.UnCheckedImage, rect);
                }
                else {
                    paint.drawRect(FCColor.argb(0, 0, 0), 1, 0, rect);
                }
            }
        }

        /// <summary>
        /// ���ƽڵ�
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        public virtual void onPaintNode(FCPaint paint, FCRect rect) {
            if (m_expended) {
                if (m_tree.ExpendedNodeImage != null && m_tree.ExpendedNodeImage.Length > 0) {
                    paint.drawImage(m_tree.ExpendedNodeImage, rect);
                    return;
                }
            }
            else {
                if (m_tree.CollapsedNodeImage != null && m_tree.CollapsedNodeImage.Length > 0) {
                    paint.drawImage(m_tree.CollapsedNodeImage, rect);
                    return;
                }
            }
            int width = rect.right - rect.left;
            int height = rect.bottom - rect.top;
            FCPoint[] points = new FCPoint[3];
            //չ��
            if (m_expended) {
                points[0] = new FCPoint(rect.left, rect.top);
                points[1] = new FCPoint(rect.left + width, rect.top);
                points[2] = new FCPoint(rect.left + width / 2, rect.top + height);
            }
            //�۵�
            else {
                points[0] = new FCPoint(rect.left, rect.top);
                points[1] = new FCPoint(rect.left, rect.top + height);
                points[2] = new FCPoint(rect.left + width, rect.top + height / 2);
            }
            FCGrid grid = Grid;
            paint.fillPolygon(grid.TextColor, points);
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        /// <param name="isAlternate">�Ƿ�����</param>
        public override void onPaint(FCPaint paint, FCRect rect, FCRect clipRect, bool isAlternate) {
            int clipW = clipRect.right - clipRect.left;
            int clipH = clipRect.bottom - clipRect.top;
            FCGrid grid = Grid;
            FCGridRow row = Row;
            if (clipW > 0 && clipH > 0 && grid != null && Column != null && row != null && TargetColumn != null) {
                int width = rect.right - rect.left;
                int height = rect.bottom - rect.top;
                int scrollH = 0;
                FCHScrollBar hscrollBar = grid.HScrollBar;
                if (hscrollBar != null && hscrollBar.Visible) {
                    scrollH = hscrollBar.Pos;
                }
                FCFont font = null;
                long backColor = FCColor.None;
                long textColor = FCColor.None;
                bool autoEllipsis = m_tree.AutoEllipsis;
                FCGridCellStyle style = Style;
                if (style != null) {
                    if (style.AutoEllipsis) {
                        autoEllipsis = style.AutoEllipsis;
                    }
                    backColor = style.BackColor;
                    if (style.Font != null) {
                        font = style.Font;
                    }
                    textColor = style.TextColor;
                }
                FCGridRowStyle rowStyle = grid.RowStyle;
                if (isAlternate) {
                    FCGridRowStyle alternateRowStyle = grid.AlternateRowStyle;
                    if (alternateRowStyle != null) {
                        rowStyle = alternateRowStyle;
                    }
                }
                if (rowStyle != null) {
                    bool selected = false;
                    ArrayList<FCGridRow> selectedRows = grid.SelectedRows;
                    int selectedRowsSize = selectedRows.size();
                    for (int i = 0; i < selectedRowsSize; i++) {
                        if (selectedRows[i] == row) {
                            selected = true;
                            break;
                        }
                    }
                    if (backColor == FCColor.None) {
                        //ѡ��
                        if (selected) {
                            backColor = rowStyle.SelectedBackColor;
                        }
                        //��ͣ
                        else if (Row == Grid.HoveredRow) {
                            backColor = rowStyle.HoveredBackColor;
                        }
                        //��ͨ
                        else {
                            backColor = rowStyle.BackColor;
                        }
                    }
                    if (font == null) {
                        font = rowStyle.Font;
                    }
                    if (textColor == FCColor.None) {
                        //ѡ��
                        if (selected) {
                            textColor = rowStyle.SelectedTextColor;
                        }
                        //��ͣ
                        else if (Row == Grid.HoveredRow) {
                            textColor = rowStyle.HoveredTextColor;
                        }
                        //��ͨ
                        else {
                            textColor = rowStyle.TextColor;
                        }
                    }
                }
                //���Ʊ���
                paint.fillRect(backColor, rect);
                FCRect headerRect = TargetColumn.Bounds;
                headerRect.left += Grid.HorizontalOffset - scrollH;
                headerRect.top += Grid.VerticalOffset - scrollH;
                int left = headerRect.left;
                //���Ƹ�ѡ��
                if (m_tree.CheckBoxes) {
                    int cw = m_tree.CheckBoxSize.cx;
                    int ch = m_tree.CheckBoxSize.cy;
                    FCRect checkBoxRect = new FCRect();
                    checkBoxRect.left = left;
                    checkBoxRect.top = rect.top + (height - ch) / 2;
                    checkBoxRect.right = checkBoxRect.left + cw;
                    checkBoxRect.bottom = checkBoxRect.top + ch;
                    onPaintCheckBox(paint, checkBoxRect);
                    left += cw + 10;
                }
                //�����۵�չ���ı�־
                int nw = m_tree.NodeSize.cx;
                int nh = m_tree.NodeSize.cy;
                if (m_nodes.size() > 0) {
                    FCRect nodeRect = new FCRect();
                    nodeRect.left = left;
                    nodeRect.top = rect.top + (height - nh) / 2;
                    nodeRect.right = nodeRect.left + nw;
                    nodeRect.bottom = nodeRect.top + nh;
                    onPaintNode(paint, nodeRect);
                }
                left += nw + 10;
                m_indent = left;
                String text = getPaintText();
                //��������
                if (text != null) {
                    FCSize tSize = paint.textSize(text, font);
                    FCRect tRect = new FCRect();
                    tRect.left = left;
                    tRect.top = rect.top + (row.Height - tSize.cy) / 2;
                    tRect.right = tRect.left + tSize.cx;
                    tRect.bottom = tRect.top + tSize.cy;
                    if (autoEllipsis && (tRect.right < clipRect.right || tRect.bottom < clipRect.bottom)) {
                        if (tRect.right < clipRect.right) {
                            tRect.right = clipRect.right;
                        }
                        if (tRect.bottom < clipRect.bottom) {
                            tRect.bottom = clipRect.bottom;
                        }
                        paint.drawTextAutoEllipsis(text, textColor, font, tRect);
                    }
                    else {
                        paint.drawText(text, textColor, font, tRect);
                    }
                }
            }
            onPaintControl(paint, rect, clipRect);
        }

        /// <summary>
        /// �Ƴ��ڵ㷽��
        /// </summary>
        public virtual void onRemovingNode() {
            m_indent = 0;
            FCGridRow row = Row;
            if (row != null) {
                if (m_nodes != null && m_nodes.size() > 0) {
                    int nodeSize = m_nodes.size();
                    for (int i = 0; i < nodeSize; i++) {
                        m_nodes.get(i).onRemovingNode();
                    }
                }
                m_tree.removeRow(row);
                row.clearCells();
                Row = null;
                ArrayList<FCGridRow> rows = m_tree.getRows();
                int rowSize = rows.size();
                for (int i = 0; i < rowSize; i++) {
                    rows.get(i).Index = i;
                }
                m_targetColumn = null;
            }
        }

        /// <summary>
        /// �Ƴ��ڵ�
        /// </summary>
        /// <param name="node">�ڵ�</param>
        public void removeNode(FCTreeNode node) {
            node.onRemovingNode();
            m_nodes.remove(node);
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "allowdragin") {
                AllowDragIn = FCStr.convertStrToBool(value);
            }
            else if (name == "allowdragout") {
                AllowDragOut = FCStr.convertStrToBool(value);
            }
            else if (name == "checked") {
                Checked = FCStr.convertStrToBool(value);
            }
            else if (name == "expended") {
                Expended = FCStr.convertStrToBool(value);
            }
            else if (name == "value") {
                Value = value;
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_text = value;
        }
    }
}
