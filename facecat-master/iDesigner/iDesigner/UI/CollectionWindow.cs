/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using FaceCat;
using System.Xml;

namespace FaceCat {
    /// <summary>
    /// ���ϱ༭����
    /// </summary>
    public class CollectionWindow : WindowXmlEx {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="native">������</param>
        public CollectionWindow(FCNative native) {
            load(native, "CollectionWindow", "windowCollection");
            m_tvCollection = getTree("tvCollection");
            m_tvCollection.AllowDragRow = true;
            m_gridProperty = getGrid("gridProperty") as PropertyGrid;
            m_gridProperty.CollectionWindow = this;
            //ע�����¼�
            registerEvents(m_window);
        }

        /// <summary>
        /// ���Ա�
        /// </summary>
        private PropertyGrid m_gridProperty;

        /// <summary>
        /// ���ѡ���иı��¼�
        /// </summary>
        private FCEvent m_gridSelectedRowsChangedEvent;

        /// <summary>
        /// ���ϱ�
        /// </summary>
        private FCTree m_tvCollection;

        private String m_collectionName;

        /// <summary>
        /// ��ȡ�����ü��ϵ�����
        /// </summary>
        public String CollectionName {
            get { return m_collectionName; }
            set {
                m_collectionName = value;
                m_window.Text += " " + m_collectionName;
            }
        }

        private DesignerDiv m_designerDiv;

        /// <summary>
        /// ��ȡ�����ñ༭��ͼ
        /// </summary>
        public DesignerDiv DesignerDiv {
            get { return m_designerDiv; }
            set { m_designerDiv = value; }
        }

        private FCView m_target;

        /// <summary>
        /// ��ȡ������Ŀ��ؼ�
        /// </summary>
        public FCView Target {
            get { return m_target; }
            set { m_target = value; }
        }

        private UIXmlEx m_xml;

        /// <summary>
        /// ��ȡ������XML����
        /// </summary>
        public UIXmlEx Xml {
            get { return m_xml; }
            set { m_xml = value; }
        }

        /// <summary>
        /// �����
        /// </summary>
        public void addClass() {
            XmlDocument xmlDoc = m_xml.XmlDoc;
            if (m_collectionName == "TabPages") {
                FCTabControl tabControl = m_target as FCTabControl;
                FCTabPage tabPage = new FCTabPage();
                tabControl.addControl(tabPage);
                String newControlName = UITemplate.CreateControlName(tabPage, m_xml);
                tabPage.Name = newControlName;
                tabPage.Text = newControlName;
                XmlNode tabControlNode = m_xml.Nodes[tabControl];
                XmlNode tabpageNode = m_xml.XmlDoc.CreateNode(XmlNodeType.Element, "div", "");
                tabControlNode.AppendChild(tabpageNode);
                XmlAttribute xmlAtr1 = xmlDoc.CreateAttribute("name");
                xmlAtr1.Value = tabPage.Text;
                tabpageNode.Attributes.Append(xmlAtr1);
                XmlAttribute xmlAtr2 = xmlDoc.CreateAttribute("text");
                xmlAtr2.Value = tabPage.Text;
                tabpageNode.Attributes.Append(xmlAtr2);
                XmlAttribute xmlAtr3 = xmlDoc.CreateAttribute("type");
                xmlAtr3.Value = "tabpage";
                tabpageNode.Attributes.Append(xmlAtr3);
                m_xml.m_controls.Add(tabPage);
                m_xml.Nodes[tabPage] = tabpageNode;
                FCTreeNode node = new FCTreeNode();
                node.setString(tabPage.Name);
                m_tvCollection.appendNode(node);
                node.Row.Tag = tabPage;
                m_tvCollection.update();
                m_tvCollection.selectNextRow();
                tabControl.update();
            } else if (m_collectionName == "Columns") {
                FCGrid grid = m_target as FCGrid;
                FCGridColumn column = new FCGridColumn();
                grid.addColumn(column);
                String newControlName = UITemplate.CreateControlName(column, m_xml);
                column.Name = newControlName;
                column.Text = newControlName;
                XmlNode gridNode = m_xml.Nodes[grid];
                XmlNode columnsNode = null;
                foreach (XmlNode subNode in gridNode.ChildNodes) {
                    if (subNode.Name.ToLower() == "columns" || subNode.Name.ToLower() == "tr") {
                        columnsNode = subNode;
                        break;
                    }
                }
                if (columnsNode == null) {
                    columnsNode = xmlDoc.CreateNode(XmlNodeType.Element, "tr", "");
                    gridNode.AppendChild(columnsNode);
                }
                XmlNode columnNode = m_xml.XmlDoc.CreateNode(XmlNodeType.Element, "th", "");
                columnNode.InnerText = column.Text;
                columnsNode.AppendChild(columnNode);
                XmlAttribute xmlAtr1 = xmlDoc.CreateAttribute("name");
                xmlAtr1.Value = column.Text;
                columnNode.Attributes.Append(xmlAtr1);
                m_xml.m_controls.Add(column);
                m_xml.Nodes[column] = columnNode;
                FCTreeNode node = new FCTreeNode();
                node.setString(column.Name);
                m_tvCollection.appendNode(node);
                node.Row.Tag = column;
                grid.update();
            }
            m_tvCollection.update();
            m_tvCollection.selectNextRow();
            Native.invalidate();
            m_designerDiv.saveUndo();
        }

        /// <summary>
        /// �����ť����
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="click">�������</param>
        /// <param name="delta">���ֹ���ֵ</param>
        private void clickButton(object sender, FCTouchInfo touchInto) {
            if (touchInto.m_firstTouch && touchInto.m_clicks == 1) {
                FCView control = sender as FCView;
                String name = control.Name;
                if (name == "btnAddClass") {
                    addClass();
                } else if (name == "btnDeleteClass") {
                    deleteClass();
                }
            }
        }

        /// <summary>
        /// ɾ����
        /// </summary>
        public void deleteClass() {
            List<FCGridRow> selectedRows = m_tvCollection.SelectedRows;
            int selectedRowsSize = selectedRows.Count;
            if (selectedRowsSize > 0) {
                if (m_collectionName == "TabPages") {
                    FCTabControl tabControl = m_target as FCTabControl;
                    FCTabPage tabPage = selectedRows[0].Tag as FCTabPage;
                    m_xml.removeControl(tabPage);
                    m_tvCollection.removeRow(selectedRows[0]);
                    m_tvCollection.update();
                    tabControl.update();
                } else if (m_collectionName == "Columns") {
                    FCGrid grid = m_target as FCGrid;
                    FCGridColumn column = selectedRows[0].Tag as FCGridColumn;
                    grid.removeColumn(column);
                    m_xml.m_controls.Remove(column);
                    m_xml.Nodes[column].ParentNode.RemoveChild(m_xml.Nodes[column]);
                    m_xml.Nodes.Remove(column);
                    m_tvCollection.removeRow(selectedRows[0]);
                    m_tvCollection.update();
                    grid.update();
                }
                Native.invalidate();
                m_designerDiv.saveUndo();
            }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_tvCollection != null) {
                    m_tvCollection.removeEvent(m_gridSelectedRowsChangedEvent, FCEventID.GRIDSELECTEDROWSCHANGED);
                    m_gridSelectedRowsChangedEvent = null;
                    m_tvCollection = null;
                }
                base.delete();
            }
        }

        /// <summary>
        /// ���ѡ���иı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        private void gridSelectedRowsChanged(object sender) {
            onGridSelectedRowsChanged();
        }

        /// <summary>
        /// ���ѡ���иı䷽��
        /// </summary>
        public void onGridSelectedRowsChanged() {
            List<FCGridRow> selectedRows = m_tvCollection.SelectedRows;
            int selectedRowsSize = selectedRows.Count;
            if (selectedRowsSize > 0) {
                if (selectedRows[0].Tag != null) {
                    List<FCView> targets = new List<FCView>();
                    if (m_collectionName == "TabPages") {
                        FCTabPage tabPage = selectedRows[0].Tag as FCTabPage;
                        targets.Add(tabPage);
                    } else if (m_collectionName == "Columns") {
                        FCGridColumn column = selectedRows[0].Tag as FCGridColumn;
                        targets.Add(column);
                    }
                    m_gridProperty.clearTargets();
                    m_gridProperty.addTargets(targets);
                }
            }
        }

        /// <summary>
        /// ���Ըı䷽��
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public void onPropertyChanged(String name, String value) {
            if (name.ToLower() == "text") {
                List<FCGridRow> selectedRows = m_tvCollection.SelectedRows;
                int selectedRowsSize = selectedRows.Count;
                if (selectedRowsSize > 0) {
                    FCTreeNode node = selectedRows[0].getCell(0) as FCTreeNode;
                    node.Text = value;
                }
            }
        }

        /// <summary>
        /// ע���¼�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        private void registerEvents(FCView control) {
            FCTouchEvent clickButtonEvent = new FCTouchEvent(clickButton);
            List<FCView> controls = control.getControls();
            int controlsSize = controls.Count;
            for (int i = 0; i < controlsSize; i++) {
                FCView subControl = controls[i];
                FCButton button = subControl as FCButton;
                FCGrid grid = subControl as FCGrid;
                if (button != null) {
                    button.addEvent(clickButtonEvent, FCEventID.CLICK);
                } else if (grid != null && grid != m_gridProperty) {
                    FCGridRowStyle rowStyle = new FCGridRowStyle();
                    grid.RowStyle = rowStyle;
                    rowStyle.BackColor = FCColor.None;
                    rowStyle.SelectedBackColor = FCDraw.FCCOLORS_SELECTEDROWCOLOR;
                    rowStyle.HoveredBackColor = FCDraw.FCCOLORS_HOVEREDROWCOLOR;
                    rowStyle.SelectedTextColor = FCDraw.FCCOLORS_TEXTCOLOR4;
                }
                registerEvents(subControl);
            }
        }

        /// <summary>
        /// ��ʾ
        /// </summary>
        public override void showDialog() {
            if (m_collectionName == "TabPages") {
                FCTabControl tabControlA = m_target as FCTabControl;
                List<FCTabPage> tabPages = tabControlA.getTabPages();
                int tabPagesSize = tabPages.Count;
                for (int i = 0; i < tabPagesSize; i++) {
                    FCTabPage tabPage = tabPages[i];
                    FCTreeNode node = new FCTreeNode();
                    node.setString(tabPage.Text);
                    m_tvCollection.appendNode(node);
                    node.Row.Tag = tabPage;
                }
            } else if (m_collectionName == "Columns") {
                FCGrid grid = m_target as FCGrid;
                List<FCGridColumn> columns = grid.getColumns();
                int columnsSize = columns.Count;
                for (int i = 0; i < columnsSize; i++) {
                    FCGridColumn column = columns[i];
                    FCTreeNode node = new FCTreeNode();
                    node.setString(column.Text);
                    m_tvCollection.appendNode(node);
                    node.Row.Tag = column;
                }
            }
            m_tvCollection.update();
            m_gridSelectedRowsChangedEvent = new FCEvent(gridSelectedRowsChanged);
            m_gridProperty.Xml = m_xml;
            m_gridProperty.DesignerDiv = m_designerDiv;
            m_tvCollection.addEvent(m_gridSelectedRowsChangedEvent, FCEventID.GRIDSELECTEDROWSCHANGED);
            if (m_tvCollection.getRows().Count > 0) {
                ArrayList<FCGridRow> selectedRows = new ArrayList<FCGridRow>();
                selectedRows.Add(m_tvCollection.getRow(0));
                m_tvCollection.SelectedRows = selectedRows;
            }
            base.showDialog();
        }
    }
}
