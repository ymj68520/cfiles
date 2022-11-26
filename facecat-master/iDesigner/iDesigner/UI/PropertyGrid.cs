/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;
using FaceCat;
using System.Windows.Forms;
using System.Drawing;

namespace FaceCat
{
    /// <summary>
    /// �����б�ؼ�
    /// </summary>
    public class PropertyGrid : FCGrid
    {
        /// <summary>
        /// ��������
        /// </summary>
        public PropertyGrid()
        {
            BackColor = FCColor.Back;
            GridLineColor = FCColor.Border;
            RowStyle.HoveredBackColor = FCDraw.FCCOLORS_HOVEREDROWCOLOR;
            RowStyle.SelectedBackColor = FCDraw.FCCOLORS_SELECTEDROWCOLOR;
            RowStyle.SelectedTextColor = FCDraw.FCCOLORS_TEXTCOLOR4;
            RowStyle.Font = new FCFont("΢���ź�", 12, false, false, false);
            FCGridRowStyle alternateRowStyle = new FCGridRowStyle();
            alternateRowStyle.BackColor = FCDraw.FCCOLORS_ALTERNATEROWCOLOR;
            alternateRowStyle.HoveredBackColor = FCDraw.FCCOLORS_HOVEREDROWCOLOR;
            alternateRowStyle.SelectedBackColor = FCDraw.FCCOLORS_SELECTEDROWCOLOR;
            alternateRowStyle.SelectedTextColor = FCDraw.FCCOLORS_TEXTCOLOR4;
            alternateRowStyle.Font = new FCFont("΢���ź�", 12, false, false, false);
            AlternateRowStyle = alternateRowStyle;
            m_assembly = Assembly.Load("facecat_net");
            String content = "";
            FCFile.read(DataCenter.GetAppPath() + "\\config\\CN_PROPERTIES.txt", ref content);
            String[] strs = content.Split(new String[] { "\r\n" }, StringSplitOptions.RemoveEmptyEntries);
            int strsSize = strs.Length;
            for (int i = 0; i < strsSize; i++)
            {
                String[] subStrs = strs[i].Split(new String[] { "=" }, StringSplitOptions.RemoveEmptyEntries);
                m_chNames[subStrs[0].ToLower()] = subStrs[1];
            }
        }

        /// <summary>
        /// ����
        /// </summary>
        private Assembly m_assembly;

        /// <summary>
        /// ��������
        /// </summary>
        private Dictionary<String, String> m_chNames = new Dictionary<String, String>();

        /// <summary>
        /// Ӣ��������
        /// </summary>
        private FCGridColumn m_enNameColumn;

        /// <summary>
        /// ����������
        /// </summary>
        private FCGridColumn m_nameColumn;

        /// <summary>
        /// �����
        /// </summary>
        private FCGridColumn m_orderColumn;

        /// <summary>
        /// �Ƿ�������������
        /// </summary>
        private bool m_settingProperty;

        /// <summary>
        /// Ŀ���б�
        /// </summary>
        private List<FCView> m_targets = new List<FCView>();

        /// <summary>
        /// ����ֵ��
        /// </summary>
        private FCGridColumn m_valueColumn;

        private CollectionWindow m_collectionWindow;

        /// <summary>
        /// ��ȡ�����ü��ϱ༭����
        /// </summary>
        public CollectionWindow CollectionWindow
        {
            get { return m_collectionWindow; }
            set { m_collectionWindow = value; }
        }

        private DesignerDiv m_designerDiv;

        /// <summary>
        /// ��ȡ�����ñ༭��ͼ
        /// </summary>
        public DesignerDiv DesignerDiv
        {
            get { return m_designerDiv; }
            set { m_designerDiv = value; }
        }

        private UIXmlEx m_xml;

        /// <summary>
        /// ��ȡ������XML����
        /// </summary>
        public UIXmlEx Xml
        {
            get { return m_xml; }
            set { m_xml = value; }
        }

        /// <summary>
        /// ���Ŀ��
        /// </summary>
        /// <param name="targets">Ŀ���б�</param>
        public void addTargets(List<FCView> targets)
        {
            int targetsSize = targets.Count;
            for (int i = 0; i < targetsSize; i++)
            {
                m_targets.Add(targets[i]);
            }
            createProperties();
        }

        /// <summary>
        /// ��ѡ��״̬�л��¼�
        /// </summary>
        /// <param name="sender">������</param>
        private void checkBoxCheckedChanged(object sender)
        {
            if (m_xml != null)
            {
                if (!m_settingProperty)
                {
                    m_settingProperty = true;
                    FCCheckBox checkBox = sender as FCCheckBox;
                    if (checkBox != null)
                    {
                        m_designerDiv.saveUndo();
                        String name = checkBox.Tag.ToString();
                        String value = checkBox.Checked ? "True" : "False";
                        int targetsSize = m_targets.Count;
                        for (int i = 0; i < targetsSize; i++)
                        {
                            FCView target = m_targets[i];
                            m_xml.setProperty(target, name, value);
                            target.update();
                        }
                        Native.update();
                        Native.invalidate();
                    }
                    m_settingProperty = false;
                }
            }
        }

        /// <summary>
        /// ���Ŀ��
        /// </summary>
        public void clearTargets()
        {
            //�����ϴα༭�Ŀؼ�����
            FCTextBox editTextBox = EditTextBox;
            if (editTextBox != null)
            {
                if (editTextBox.Tag != null)
                {
                    FCGridCell editingCell = EditTextBox.Tag as FCGridCell;
                    if (editingCell != null)
                    {
                        FCGridCell nameCell = editingCell.Row.getCell("PROPERTYNAME");
                        if (nameCell != null)
                        {
                            String cellName = nameCell.Name;
                            String cellValue = editTextBox.Text;
                            int targetsSize = m_targets.Count;
                            for (int i = 0; i < targetsSize; i++)
                            {
                                m_xml.setProperty(m_targets[i], cellName, cellValue);
                                if (m_collectionWindow != null)
                                {
                                    m_collectionWindow.onPropertyChanged(cellName, cellValue);
                                }
                            }
                        }
                    }
                }
                editTextBox.Visible = false;
            }
            m_targets.Clear();
        }

        /// <summary>
        /// �����б�ؼ������ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        private void comboBoxSelectedIndexChanged(object sender)
        {
            if (m_xml != null)
            {
                if (!m_settingProperty)
                {
                    m_settingProperty = true;
                    FCComboBox comboBox = sender as FCComboBox;
                    if (comboBox != null)
                    {
                        m_designerDiv.saveUndo();
                        String name = comboBox.Tag.ToString();
                        String value = comboBox.SelectedText;
                        int targetsSize = m_targets.Count;
                        for (int i = 0; i < targetsSize; i++)
                        {
                            FCView target = m_targets[i];
                            m_xml.setProperty(target, name, value);
                            target.update();
                        }
                        Native.update();
                        Native.invalidate();
                    }
                    m_settingProperty = false;
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        public void createProperties()
        {
            WinHostEx host = Native.Host as WinHostEx;
            host.LoadingDesigner = true;
            int rowSize = m_rows.Count;
            if (rowSize > 0)
            {
                //���������
                for (int i = 0; i < rowSize; i++)
                {
                    m_rows[i].clearCells();
                    m_rows[i].delete();
                }
                m_rows.Clear();
            }
            int targetsSize = m_targets.Count;
            if (targetsSize > 0)
            {
                FCView target = m_targets[0];
                //��ȡ��������
                List<String> propertiesName = UIXmlEx.getUnionProperties(m_targets);
                Dictionary<String, String> addProperties = new Dictionary<String, String>();
                if (targetsSize == 1)
                {
                    if (target is FCTabControl)
                    {
                        addProperties["TabPages"] = "collection";
                    }
                    else if (target is FCGrid)
                    {
                        addProperties["Columns"] = "collection";
                    }
                    foreach (String addName in addProperties.Keys)
                    {
                        propertiesName.Add(addName);
                    }
                }
                propertiesName.Sort();
                int psize = propertiesName.Count;
                for (int i = 0; i < psize; i++)
                {
                    String name = propertiesName[i];
                    String value = "";
                    String type = "";
                    if (addProperties.ContainsKey(name))
                    {
                        value = "�����Ա༭...";
                        type = addProperties[name];
                    }
                    else
                    {
                        target.getProperty(name.ToLower(), ref value, ref type);
                    }
                    String text = name;
                    if (m_chNames.ContainsKey(name.ToLower()))
                    {
                        text = m_chNames[name.ToLower()];
                    }
                    if (value == null) value = "";
                    FCGridRow row = new FCGridRow();
                    addRow(row);
                    //���
                    GridNoCell orderCell = new GridNoCell();
                    row.addCell("NO", orderCell);
                    //��������
                    FCGridStringCell nameCell = new FCGridStringCell(text);
                    nameCell.Name = name;
                    row.addCell("PROPERTYNAME", nameCell);
                    //Ӣ������
                    FCGridStringCell enNameCell = new FCGridStringCell(name);
                    row.addCell("ENNAME", enNameCell);
                    //����ֵ
                    //����
                    if (type == "bool")
                    {
                        FCGridCheckBoxCell checkBoxCell = new FCGridCheckBoxCell();
                        checkBoxCell.Control = new CheckBoxM();
                        row.addCell("PROPERTYVALUE", checkBoxCell);
                        checkBoxCell.setBool(value.ToLower() == "true" ? true : false);
                        checkBoxCell.CheckBox.Tag = name;
                        checkBoxCell.CheckBox.ButtonAlign = FCHorizontalAlign.Left;
                        checkBoxCell.CheckBox.addEvent(new FCEvent(checkBoxCheckedChanged), FCEventID.CHECKEDCHANGED);
                    }
                    //ö��
                    else if (type.StartsWith("enum:"))
                    {
                        String strEnum = "FaceCat." + type.Replace("enum:", "");
                        String[] names = Enum.GetNames(m_assembly.GetType(strEnum));
                        FCGridComboBoxCell comboBoxCell = new FCGridComboBoxCell();
                        row.addCell("PROPERTYVALUE", comboBoxCell);
                        comboBoxCell.ComboBox.BackColor = FCColor.None;
                        int nameSize = names.Length;
                        for (int j = 0; j < nameSize; j++)
                        {
                            comboBoxCell.ComboBox.DropDownMenu.addItem(new FCMenuItem(names[j]));
                        }
                        comboBoxCell.ComboBox.SelectedText = value;
                        comboBoxCell.ComboBox.ReadOnly = true;
                        comboBoxCell.ComboBox.Tag = name;
                        comboBoxCell.ComboBox.addEvent(new FCEvent(comboBoxSelectedIndexChanged), FCEventID.SELECTEDINDEXCHANGED);
                    }
                    //����
                    else if (type == "collection")
                    {
                        FCGridButtonCell buttonCell = new FCGridButtonCell();
                        row.addCell("PROPERTYVALUE", buttonCell);
                        buttonCell.setString(value);
                        buttonCell.Button.Tag = name;
                        buttonCell.Button.BackColor = FCColor.None;
                        buttonCell.Button.TextAlign = FCContentAlignment.MiddleLeft;
                        buttonCell.Button.Font = new FCFont("΢���ź�", 12, false, false, false);
                    }
                    //��ɫ
                    else if (type == "color")
                    {
                        GridColorCell colorCell = new GridColorCell();
                        colorCell.AllowEdit = true;
                        row.addCell("PROPERTYVALUE", colorCell);
                        colorCell.setString(value);
                        colorCell.Button.Font = new FCFont("΢���ź�", 12, true, false, false);
                    }
                    //����
                    else if (type == "font")
                    {
                        GridFontCell fontCell = new GridFontCell();
                        fontCell.AllowEdit = true;
                        row.addCell("PROPERTYVALUE", fontCell);
                        fontCell.setString(value);
                        fontCell.Button.Font = new FCFont("΢���ź�", 12, true, false, false);
                    }
                    //�����
                    else
                    {
                        FCGridStringCell textCell = new FCGridStringCell();
                        textCell.AllowEdit = true;
                        row.addCell("PROPERTYVALUE", textCell);
                        textCell.Text = value;
                    }
                }
                propertiesName.Clear();
                update();
                invalidate();
            }
            host.LoadingDesigner = false;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType()
        {
            return "PropertyGrid";
        }

        /// <summary>
        /// ��ȡGdi����
        /// </summary>
        /// <param name="font">����</param>
        /// <returns>Gdi����</returns>
        public Font getFont(FCFont font)
        {
            if (font.m_strikeout)
            {
                if (font.m_bold && font.m_underline && font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Underline | FontStyle.Italic | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else if (font.m_bold && font.m_underline)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Underline | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else if (font.m_bold && font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Italic | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else if (font.m_underline && font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Underline | FontStyle.Italic | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else if (font.m_bold)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else if (font.m_underline)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Underline | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else if (font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Italic | FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
                else
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Strikeout, GraphicsUnit.Pixel);
                }
            }
            else
            {
                if (font.m_bold && font.m_underline && font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Underline | FontStyle.Italic, GraphicsUnit.Pixel);
                }
                else if (font.m_bold && font.m_underline)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Underline, GraphicsUnit.Pixel);
                }
                else if (font.m_bold && font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Pixel);
                }
                else if (font.m_underline && font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Underline | FontStyle.Italic, GraphicsUnit.Pixel);
                }
                else if (font.m_bold)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Bold, GraphicsUnit.Pixel);
                }
                else if (font.m_underline)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Underline, GraphicsUnit.Pixel);
                }
                else if (font.m_italic)
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, FontStyle.Italic, GraphicsUnit.Pixel);
                }
                else
                {
                    return new Font(font.m_fontFamily, font.m_fontSize, GraphicsUnit.Pixel);
                }
            }
        }

        /// <summary>
        /// ��ȡĿ���б�
        /// </summary>
        /// <returns>Ŀ���б�</returns>
        public List<FCView> getTargets()
        {
            List<FCView> targets = new List<FCView>();
            int targetsSize = m_targets.Count;
            for (int i = 0; i < targetsSize; i++)
            {
                targets.Add(m_targets[i]);
            }
            return targets;
        }

        /// <summary>
        /// ��Ԫ�����¼�
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        public override void onCellClick(FCGridCell cell, FCTouchInfo touchInto)
        {       
            base.onCellClick(cell, touchInto);
            List<FCGridRow> rows = m_rows;
            int rowsSize = rows.Count;
            for (int i = 0; i < rowsSize; i++)
            {
                FCGridRow row = rows[i];
                List<FCGridCell> cells = row.getCells();
                int cellsSize = cells.Count;
                for (int j = 0; j < cellsSize; j++)
                {
                    FCGridControlCell cCell = cells[j] as FCGridControlCell;
                    if (cCell != null)
                    {
                        if (row == cell.Row)
                        {
                            cCell.Control.TextColor = FCDraw.FCCOLORS_TEXTCOLOR4;
                        }
                        else
                        {
                            cCell.Control.TextColor = FCColor.Text;
                        }
                    }
                }
            }   
            if (touchInto.m_firstTouch)
            {
                if (touchInto.m_clicks == 1)
                {
                    if (!cell.AllowEdit && cell is GridColorCell)
                    {
                        GridColorCell colorCell = cell as GridColorCell;
                        ColorDialog colorDialog = new ColorDialog();
                        colorDialog.AllowFullOpen = true;
                        colorDialog.AnyColor = true;
                        colorDialog.SolidColorOnly = false;
                        int a = 0, r = 0, g = 0, b = 0;
                        FCColor.toArgb(Native.Paint, FCStr.convertStrToColor(colorCell.getString()), ref a, ref r, ref g, ref b);
                        colorDialog.Color = Color.FromArgb(a, r, g, b);
                        if (colorDialog.ShowDialog() == DialogResult.OK)
                        {
                            Color newColor = colorDialog.Color;
                            a = newColor.A;
                            r = newColor.R;
                            g = newColor.G;
                            b = newColor.B;
                            colorCell.setString(FCStr.convertColorToStr(FCColor.argb(a, r, g, b)));
                            FCGridCell nameCell = cell.Row.getCell("PROPERTYNAME");
                            if (nameCell != null)
                            {
                                m_designerDiv.saveUndo();
                                String name = nameCell.Name;
                                String value = cell.Text;
                                int targetsSize = m_targets.Count;
                                for (int i = 0; i < targetsSize; i++)
                                {
                                    FCView target = m_targets[i];
                                    m_xml.setProperty(target, name, value);
                                    if (m_collectionWindow != null)
                                    {
                                        m_collectionWindow.onPropertyChanged(name, value);
                                    }
                                    target.update();
                                }
                                //�ָ���ȷ��ֵ
                                String rightValue = "", type = "";
                                for (int i = 0; i < targetsSize; i++)
                                {
                                    m_targets[i].getProperty(name.ToLower(), ref rightValue, ref type);
                                }
                                cell.Text = rightValue;
                                Native.update();
                                Native.invalidate();
                            }
                        }
                        colorDialog.Dispose();
                    }
                    //���嵥Ԫ��
                    else if (!cell.AllowEdit && cell is GridFontCell)
                    {
                        GridFontCell fontCell = cell as GridFontCell;
                        FontDialog fontDialog = new FontDialog();
                        fontDialog.Font = getFont(FCStr.convertStrToFont(fontCell.getString()));
                        if (fontDialog.ShowDialog() == DialogResult.OK)
                        {
                            Font newFont = fontDialog.Font;
                            fontCell.setString(FCStr.convertFontToStr(new FCFont(newFont.Name, newFont.Size, newFont.Bold, newFont.Underline, newFont.Italic, newFont.Strikeout)));
                            FCGridCell nameCell = cell.Row.getCell("PROPERTYNAME");
                            if (nameCell != null)
                            {
                                m_designerDiv.saveUndo();
                                String name = nameCell.Name;
                                String value = cell.Text;
                                int targetsSize = m_targets.Count;
                                for (int i = 0; i < targetsSize; i++)
                                {
                                    FCView target = m_targets[i];
                                    m_xml.setProperty(target, name, value);
                                    if (m_collectionWindow != null)
                                    {
                                        m_collectionWindow.onPropertyChanged(name, value);
                                    }
                                    target.update();
                                }
                                //�ָ���ȷ��ֵ
                                String rightValue = "", type = "";
                                for (int i = 0; i < targetsSize; i++)
                                {
                                    m_targets[i].getProperty(name.ToLower(), ref rightValue, ref type);
                                }
                                cell.Text = rightValue;
                                Native.update();
                                Native.invalidate();
                            }
                        }
                    }
                    //�����༭��
                    else if (cell is FCGridButtonCell)
                    {
                        FCButton cButton = (cell as FCGridButtonCell).Button;
                        if (cButton.Tag != null)
                        {
                            String collectionName = cButton.Tag.ToString();
                            int targetsSize = m_targets.Count;
                            if (targetsSize > 0)
                            {
                                FCView target = m_targets[0];
                                CollectionWindow collectionWindow = new CollectionWindow(m_native);
                                collectionWindow.CollectionName = collectionName;
                                collectionWindow.DesignerDiv = m_designerDiv;
                                collectionWindow.Target = target;
                                collectionWindow.Xml = m_xml;
                                collectionWindow.IsWinForm = false;
                                collectionWindow.showDialog();
                            }
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ��Ԫ��ʼ�༭
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        public override void onCellEditBegin(FCGridCell cell)
        {
            base.onCellEditBegin(cell);
        }

        /// <summary>
        /// ��Ԫ��༭����
        /// </summary>
        /// <param name="cell">��Ԫ��</param>
        public override void onCellEditEnd(FCGridCell cell)
        {
            base.onCellEditEnd(cell);
            if (cell != null)
            {
                if (cell.Row.m_cells.Count > 0)
                {
                    FCGridCell nameCell = cell.Row.getCell("PROPERTYNAME");
                    if (nameCell != null)
                    {
                        m_designerDiv.saveUndo();
                        String name = nameCell.Name;
                        String value = cell.Text;
                        int targetsSize = m_targets.Count;
                        for (int i = 0; i < targetsSize; i++)
                        {
                            FCView target = m_targets[i];
                            m_xml.setProperty(target, name, value);
                            if (m_collectionWindow != null)
                            {
                                m_collectionWindow.onPropertyChanged(name, value);
                            }
                            target.update();
                        }
                        //�ָ���ȷ��ֵ
                        String rightValue = "", type = "";
                        for (int i = 0; i < targetsSize; i++)
                        {
                            m_targets[i].getProperty(name.ToLower(), ref rightValue, ref type);
                        }
                        cell.Text = rightValue;
                        Native.update();
                        Native.invalidate();
                    }
                }
            }
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad()
        {
            base.onLoad();
            String sortStr = "1432";
            UserCookie cookie = new UserCookie();
            if (DataCenter.UserCookieService.GetCookie("PROPERTYGRIDCOLUMNS", ref cookie) > 0)
            {
                sortStr = cookie.m_value;
            }
            foreach (char ch in sortStr)
            {
                switch (ch)
                {
                    case '1':
                        //���������
                        if (m_orderColumn == null)
                        {
                            m_orderColumn = new GridColumnEx();
                            m_orderColumn.TextColor = FCDraw.FCCOLORS_TEXTCOLOR;
                            m_orderColumn.Font = new FCFont("΢���ź�", 12, false, false, false);
                            m_orderColumn.Text = "���";
                            m_orderColumn.Name = "NO";
                            m_orderColumn.Width = 30;
                            m_orderColumn.AllowResize = true;
                            m_orderColumn.AllowSort = false;
                            m_orderColumn.AllowDrag = true;
                            m_orderColumn.BackColor = FCDraw.FCCOLORS_BACKCOLOR;
                            addColumn(m_orderColumn);
                        }
                        break;
                    case '2':
                        //����������
                        if (m_nameColumn == null)
                        {
                            m_nameColumn = new GridColumnEx();
                            m_nameColumn.TextColor = FCDraw.FCCOLORS_TEXTCOLOR;
                            m_nameColumn.Font = new FCFont("΢���ź�", 12, false, false, false);
                            m_nameColumn.Text = "��������";
                            m_nameColumn.Name = "PROPERTYNAME";
                            m_nameColumn.Width = 120;
                            m_nameColumn.AllowResize = true;
                            m_nameColumn.AllowDrag = true;
                            m_nameColumn.BackColor = FCDraw.FCCOLORS_BACKCOLOR;
                            addColumn(m_nameColumn);
                        }
                        break;
                    case '3':
                        //��������ֵ��
                        if (m_valueColumn == null)
                        {
                            m_valueColumn = new GridColumnEx();
                            m_valueColumn.TextColor = FCDraw.FCCOLORS_TEXTCOLOR;
                            m_valueColumn.Font = new FCFont("΢���ź�", 12, false, false, false);
                            m_valueColumn.Text = "����ֵ";
                            m_valueColumn.Name = "PROPERTYVALUE";
                            m_valueColumn.Width = 120;
                            m_valueColumn.AllowResize = true;
                            m_valueColumn.AllowDrag = true;
                            m_valueColumn.BackColor = FCDraw.FCCOLORS_BACKCOLOR;
                            addColumn(m_valueColumn);
                        }
                        break;
                    case '4':
                        //����Ӣ��������
                        if (m_enNameColumn == null)
                        {
                            m_enNameColumn = new GridColumnEx();
                            m_enNameColumn.TextColor = FCDraw.FCCOLORS_TEXTCOLOR;
                            m_enNameColumn.Font = new FCFont("΢���ź�", 12, false, false, false);
                            m_enNameColumn.Text = "Ӣ������";
                            m_enNameColumn.Name = "ENNAME";
                            m_enNameColumn.Width = 120;
                            m_enNameColumn.AllowResize = true;
                            m_enNameColumn.AllowDrag = true;
                            m_enNameColumn.BackColor = FCDraw.FCCOLORS_BACKCOLOR;
                            addColumn(m_enNameColumn);
                        }
                        break;
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        public void save()
        {
            List<FCGridColumn> columns = m_columns;
            int columnsSize = columns.Count;
            String sortStr = "";
            for (int i = 0; i < columnsSize; i++)
            {
                FCGridColumn column = columns[i];
                if (column == m_orderColumn)
                {
                    sortStr += "1";
                }
                else if (column == m_nameColumn)
                {
                    sortStr += "2";
                }
                else if (column == m_valueColumn)
                {
                    sortStr += "3";
                }
                else if (column == m_enNameColumn)
                {
                    sortStr += "4";
                }
            }
            UserCookie cookie = new UserCookie();
            cookie.m_key = "PROPERTYGRIDCOLUMNS";
            cookie.m_value = sortStr;
            DataCenter.UserCookieService.AddCookie(cookie);
        }
    }

    /// <summary>
    /// ��ɫ��Ԫ��
    /// </summary>
    public class GridColorCell : FCGridButtonCell
    {
        /// <summary>
        /// ������ɫ��Ԫ��
        /// </summary>
        public GridColorCell()
        {
        }

        /// <summary>
        /// ֵ
        /// </summary>
        protected String m_value;

        /// <summary>
        /// ��ȡҪ���õ�����
        /// </summary>
        /// <returns></returns>
        public override String getPaintText()
        {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�ı�
        /// </summary>
        /// <returns>ֵ</returns>
        public override String getString()
        {
            return m_value;
        }

        /// <summary>
        /// ���ƿؼ�����
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintControl(FCPaint paint, FCRect rect, FCRect clipRect)
        {
            if (m_control != null)
            {
                m_control.Text = "C";
                m_control.BorderColor = FCColor.Border;
                if (m_value != null)
                {
                    m_control.BackColor = FCStr.convertStrToColor(m_value);
                    m_control.TextColor = FCColor.reverse(paint, m_control.BackColor);
                }
                int buttonWidth = 30;
                FCRect bounds = new FCRect(rect.right - 1 - buttonWidth, rect.top + 1, rect.right - 2, rect.bottom - 1);
                m_control.Bounds = bounds;
                m_control.Region = new FCRect(0, 0, bounds.right - bounds.left, bounds.bottom - bounds.top);
            }
        }

        /// <summary>
        /// �ؼ������̧�𷽷�
        /// </summary>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        public override void onControlTouchUp(FCTouchInfo touchInto)
        {
            m_allowEdit = false;
            base.onControlTouchUp(touchInto);
            m_allowEdit = true;
        }

        /// <summary>
        /// �����ı�
        /// </summary>
        /// <param name="value">ֵ</param>
        public override void setString(String value)
        {
            m_value = value;
        }
    }

    /// <summary>
    /// ���嵥Ԫ��
    /// </summary>
    public class GridFontCell : FCGridButtonCell
    {
        /// <summary>
        /// ������ɫ��Ԫ��
        /// </summary>
        public GridFontCell()
        {
        }

        /// <summary>
        /// ֵ
        /// </summary>
        protected String m_value;

        /// <summary>
        /// ��ȡҪ���õ�����
        /// </summary>
        /// <returns></returns>
        public override String getPaintText()
        {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�ı�
        /// </summary>
        /// <returns>ֵ</returns>
        public override String getString()
        {
            return m_value;
        }

        /// <summary>
        /// ���ƿؼ�����
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintControl(FCPaint paint, FCRect rect, FCRect clipRect)
        {
            if (m_control != null)
            {
                m_control.Text = "A";
                m_control.BorderColor = FCColor.Border;
                int buttonWidth = 30;
                FCRect bounds = new FCRect(rect.right - 1 - buttonWidth, rect.top + 1, rect.right - 2, rect.bottom - 1);
                m_control.Bounds = bounds;
                m_control.Region = new FCRect(0, 0, bounds.right - bounds.left, bounds.bottom - bounds.top);
            }
        }

        /// <summary>
        /// �ؼ������̧�𷽷�
        /// </summary>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        public override void onControlTouchUp(FCTouchInfo touchInto)
        {
            m_allowEdit = false;
            base.onControlTouchUp(touchInto);
            m_allowEdit = true;
        }

        /// <summary>
        /// �����ı�
        /// </summary>
        /// <param name="value">ֵ</param>
        public override void setString(String value)
        {
            m_value = value;
        }
    }

    /// <summary>
    /// �����ŵ�Ԫ��
    /// </summary>
    public class GridNoCell : FCGridIntCell
    {
        /// <summary>
        /// ��ȡ��ʾ�ı�
        /// </summary>
        /// <param name="text">�ı�</param>
        /// <returns>����ı�</returns>
        public override String getPaintText()
        {
            return (Row.Index + 1).ToString();
        }
    }

    /// <summary>
    /// �������չ
    /// </summary>
    public class GridColumnEx : FCGridColumn
    {
        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            int width = Width, height = Height;
            FCRect drawRect = new FCRect(0, 0, width, height);
            paint.fillGradientRect(FCDraw.FCCOLORS_BACKCOLOR, FCDraw.FCCOLORS_BACKCOLOR2, drawRect, 0, 90);
        }
    }
}
