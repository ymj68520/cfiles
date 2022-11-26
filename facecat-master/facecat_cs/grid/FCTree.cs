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
    /// ���ؼ�
    /// </summary>
    public class FCTree : FCGrid {
        /// <summary>
        /// ������
        /// </summary>
        public FCTree() {
            GridLineColor = FCColor.None;
        }

        /// <summary>
        /// �����ƶ��Ľڵ�
        /// </summary>
        protected FCTreeNode m_movingNode;

        /// <summary>
        /// �ӽڵ�
        /// </summary>
        public ArrayList<FCTreeNode> m_nodes = new ArrayList<FCTreeNode>();

        protected bool m_checkBoxes;

        /// <summary>
        /// ��ȡ�������Ƿ��ڽڵ�����ʾ��ѡ��
        /// </summary>
        public virtual bool CheckBoxes {
            get { return m_checkBoxes; }
            set { m_checkBoxes = value; }
        }

        protected FCSize m_checkBoxSize = new FCSize(14, 14);

        /// <summary>
        /// ��ȡ�����ø�ѡ��Ĵ�С
        /// </summary>
        public virtual FCSize CheckBoxSize {
            get { return m_checkBoxSize; }
            set { m_checkBoxSize = value; }
        }

        protected String m_checkedImage;

        /// <summary>
        /// ��ȡ�����ø�ѡ��ѡ��ʱ��ͼƬ
        /// </summary>
        public virtual String CheckedImage {
            get { return m_checkedImage; }
            set { m_checkedImage = value; }
        }

        protected String m_collapsedNodeImage;

        /// <summary>
        /// ��ȡ�������۵��ڵ��ͼƬ
        /// </summary>
        public virtual String CollapsedNodeImage {
            get { return m_collapsedNodeImage; }
            set { m_collapsedNodeImage = value; }
        }

        protected String m_expendedNodeImage;

        /// <summary>
        /// ��ȡ������չ���ڵ��ͼƬ
        /// </summary>
        public virtual String ExpendedNodeImage {
            get { return m_expendedNodeImage; }
            set { m_expendedNodeImage = value; }
        }

        protected FCSize m_nodeSize = new FCSize(14, 14);

        /// <summary>
        /// ��ȡ�����ýڵ�Ĵ�С
        /// </summary>
        public virtual FCSize NodeSize {
            get { return m_nodeSize; }
            set { m_nodeSize = value; }
        }

        /// <summary>
        /// ��ȡ������ѡ�еĽڵ�
        /// </summary>
        public virtual ArrayList<FCTreeNode> SelectedNodes {
            get {
                ArrayList<FCTreeNode> selectedNodes = new ArrayList<FCTreeNode>();
                ArrayList<FCGridRow> selectedRows = SelectedRows;
                int selectedRowsSize = selectedRows.size();
                for (int i = 0; i < selectedRowsSize; i++) {
                    ArrayList<FCGridCell> cells = selectedRows.get(i).m_cells;
                    int cellsSize = cells.size();
                    for (int j = 0; j < cellsSize; j++) {
                        FCTreeNode node = cells.get(j) as FCTreeNode;
                        if (node != null) {
                            selectedNodes.add(node);
                            break;
                        }
                    }
                }
                return selectedNodes;
            }
            set {
                int selectedNodesSize = value.size();
                ArrayList<FCGridRow> selectedRows = new ArrayList<FCGridRow>();
                for (int i = 0; i < selectedNodesSize; i++) {
                    selectedRows.add(value.get(i).Row);
                }
                SelectedRows = selectedRows;
            }
        }

        protected String m_unCheckedImage;

        /// <summary>
        /// ��ȡ�����ø�ѡ��δѡ��ʱ��ͼƬ
        /// </summary>
        public virtual String UnCheckedImage {
            get { return m_unCheckedImage; }
            set { m_unCheckedImage = value; }
        }

        /// <summary>
        /// ��ӽڵ�
        /// </summary>
        /// <param name="node">�ڵ�</param>
        public void appendNode(FCTreeNode node) {
            node.Tree = this;
            node.onAddingNode(-1);
            m_nodes.add(node);
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
            int nodesSize = m_nodes.size();
            if (nodesSize > 0) {
                for (int i = 0; i < nodesSize; i++) {
                    m_nodes.get(i).collapse();
                }
            }
        }

        /// <summary>
        /// �۵��ڵ�
        /// </summary>
        public void CollapseAll() {
            int nodesSize = m_nodes.size();
            if (nodesSize > 0) {
                for (int i = 0; i < nodesSize; i++) {
                    m_nodes.get(i).collapseAll();
                }
            }
        }

        /// <summary>
        /// ������Դ
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                m_nodes.clear();
            }
            base.delete();
        }

        /// <summary>
        /// չ���ڵ�
        /// </summary>
        public void expend() {
            int nodesSize = m_nodes.size();
            if (nodesSize > 0) {
                for (int i = 0; i < nodesSize; i++) {
                    m_nodes.get(i).expend();
                }
            }
        }

        /// <summary>
        /// չ���ڵ�
        /// </summary>
        public void expendAll() {
            int nodesSize = m_nodes.size();
            if (nodesSize > 0) {
                for (int i = 0; i < nodesSize; i++) {
                    m_nodes.get(i).expendAll();
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
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "Tree";
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
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "checkboxes") {
                type = "bool";
                value = FCStr.convertBoolToStr(CheckBoxes);
            }
            else if (name == "checkboxsize") {
                type = "size";
                value = FCStr.convertSizeToStr(CheckBoxSize);
            }
            else if (name == "checkedimage") {
                type = "String";
                value = CheckedImage;
            }
            else if (name == "collapsednodeimage") {
                type = "String";
                value = CollapsedNodeImage;
            }
            else if (name == "expendednodeimage") {
                type = "String";
                value = ExpendedNodeImage;
            }
            else if (name == "uncheckedimage") {
                type = "String";
                value = UnCheckedImage;
            }
            else if (name == "nodesize") {
                type = "size";
                value = FCStr.convertSizeToStr(NodeSize);
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
            propertyNames.AddRange(new String[] { "CheckBoxes", "CheckBoxSize", "CheckedImage", "CollapsedNodeImage", "ExpendedNodeImage", "UnCheckedImage", "NodeSize" });
            return propertyNames;
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
            node.Tree = this;
            node.onAddingNode(rowIndex);
            m_nodes.Insert(index, node);
        }

        /// <summary>
        /// ��Ԫ�������·���
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onCellTouchDown(FCGridCell cell, FCTouchInfo touchInfo) {
            base.onCellTouchDown(cell, touchInfo);
            FCPoint mp = touchInfo.m_firstPoint;
            FCTreeNode node = cell as FCTreeNode;
            if (node != null) {
                int scrollH = 0;
                FCHScrollBar hscrollBar = HScrollBar;
                if (hscrollBar != null && hscrollBar.Visible) {
                    scrollH = hscrollBar.Pos;
                }
                FCRect headerRect = node.TargetColumn.Bounds;
                headerRect.left += HorizontalOffset - scrollH;
                headerRect.top += VerticalOffset - scrollH;
                int left = headerRect.left;
                //��ѡ��
                if (m_checkBoxes) {
                    int cw = m_checkBoxSize.cx;
                    if (mp.x >= left && mp.x <= left + cw) {
                        node.Checked = !node.Checked;
                        return;
                    }
                    left += cw + 10;
                }
                //�۵��ڵ�
                ArrayList<FCTreeNode> childNodes = node.getChildNodes();
                if (childNodes != null && childNodes.size() > 0) {
                    int nw = m_nodeSize.cx;
                    if (mp.x >= left && mp.x <= left + nw) {
                        if (node.Expended) {
                            node.collapse();
                        }
                        else {
                            node.expend();
                        }
                        update();
                        return;
                    }
                }
                //�ƶ�
                if (node.AllowDragOut) {
                    m_movingNode = node;
                }
            }
        }

        /// <summary>
        /// ��Ԫ�����ƶ�����
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onCellTouchMove(FCGridCell cell, FCTouchInfo touchInfo) {
            base.onCellTouchMove(cell, touchInfo);
            if (m_movingNode != null) {
                invalidate();
            }
        }

        /// <summary>
        /// ��Ԫ����̧�𷽷�
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onCellTouchUp(FCGridCell cell, FCTouchInfo touchInfo) {
            base.onCellTouchUp(cell, touchInfo);
            FCPoint mp = touchInfo.m_firstPoint;
            if (m_movingNode != null) {
                FCGridRow curRow = getRow(mp);
                //�ƶ�
                if (curRow != null) {
                    FCTreeNode curNode = curRow.getCell(0) as FCTreeNode;
                    if (curNode.AllowDragIn && m_movingNode != curNode) {
                        FCTreeNode curNodeParent = curNode.Parent;
                        FCTreeNode movingNodeParent = m_movingNode.Parent;
                        if (movingNodeParent != null) {
                            movingNodeParent.removeNode(m_movingNode);
                        }
                        else {
                            removeNode(m_movingNode);
                        }
                        //�и��ڵ�
                        if (curNodeParent != null) {
                            if (movingNodeParent == curNodeParent) {
                                curNodeParent.insertNode(curNodeParent.getNodeIndex(curNode), m_movingNode);
                            }
                            else {
                                curNode.appendNode(m_movingNode);
                            }
                        }
                        //�޸��ڵ�
                        else {
                            if (movingNodeParent == curNodeParent) {
                                insertNode(getNodeIndex(curNode), m_movingNode);
                            }
                            else {
                                curNode.appendNode(m_movingNode);
                            }
                        }
                        curNode.expend();
                    }
                }
                m_movingNode = null;
                update();
            }
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            base.onPaintForeground(paint, clipRect);
            //�����ƶ��Ľڵ�
            if (m_movingNode != null) {
                FCFont font = Font;
                FCPoint mp = TouchPoint;
                FCSize tSize = paint.textSize(m_movingNode.Text, font);
                FCRect tRect = new FCRect(mp.x, mp.y, mp.x + tSize.cx, mp.y + tSize.cy);
                paint.drawText(m_movingNode.Text, TextColor, font, tRect);
            }
        }

        /// <summary>
        /// ���Ʊ༭�ı���
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintEditTextBox(FCGridCell cell, FCPaint paint, FCRect rect, FCRect clipRect) {
            FCTextBox editTextBox = EditTextBox;
            if (editTextBox != null) {
                FCTreeNode node = cell as FCTreeNode;
                if (node != null) {
                    int indent = node.Indent;
                    rect.left += indent;
                    if (rect.right < rect.left) {
                        rect.right = rect.left;
                    }
                    editTextBox.Bounds = rect;
                    editTextBox.DisplayOffset = false;
                    editTextBox.bringToFront();
                }
                else {
                    base.onPaintEditTextBox(cell, paint, rect, clipRect);
                }
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
            if (name == "checkboxes") {
                CheckBoxes = FCStr.convertStrToBool(value);
            }
            else if (name == "checkboxsize") {
                CheckBoxSize = FCStr.convertStrToSize(value);
            }
            else if (name == "checkedimage") {
                CheckedImage = value;
            }
            else if (name == "collapsednodeimage") {
                CollapsedNodeImage = value;
            }
            else if (name == "expendednodeimage") {
                ExpendedNodeImage = value;
            }
            else if (name == "uncheckedimage") {
                UnCheckedImage = value;
            }
            else if (name == "nodesize") {
                NodeSize = FCStr.convertStrToSize(value);
            }
            else {
                base.setProperty(name, value);
            }
        }
    }
}
