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
    /// ������С������
    /// </summary>
    public enum FCSizeType {
        /// <summary>
        /// ���Դ�С
        /// </summary>
        AbsoluteSize,
        /// <summary>
        /// �Զ����
        /// </summary>
        AutoFill,
        /// <summary>
        /// �ٷֱȴ�С
        /// </summary>
        PercentSize
    }

    /// <summary>
    /// �е���ʽ
    /// </summary>
    public class FCColumnStyle : FCProperty {
        /// <summary>
        /// �����е���ʽ
        /// </summary>
        /// <param name="sizeType">������С������</param>
        /// <param name="width">���</param>
        public FCColumnStyle(FCSizeType sizeType, float width) {
            m_sizeType = sizeType;
            m_width = width;
        }

        protected FCSizeType m_sizeType = FCSizeType.AbsoluteSize;

        /// <summary>
        /// ��ȡ�����õ�����С������
        /// </summary>
        public virtual FCSizeType SizeType {
            get { return m_sizeType; }
            set { m_sizeType = value; }
        }

        protected float m_width;

        /// <summary>
        /// ��ȡ�����ÿ��
        /// </summary>
        public virtual float Width {
            get { return m_width; }
            set { m_width = value; }
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "sizetype") {
                type = "enum:FCSizeType";
                if (m_sizeType == FCSizeType.AbsoluteSize) {
                    value = "absolutesize";
                }
                else if (m_sizeType == FCSizeType.AutoFill) {
                    value = "autofill";
                }
                else if (m_sizeType == FCSizeType.PercentSize) {
                    value = "percentsize";
                }
            }
            else if (name == "width") {
                type = "float";
                value = FCStr.convertFloatToStr(Width);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.add("SizeType");
            propertyNames.add("Width");
            return propertyNames;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "sizetype") {
                String lowerStr = value.ToLower();
                if (value == "absolutesize") {
                    m_sizeType = FCSizeType.AbsoluteSize;
                }
                else if (value == "autofill") {
                    m_sizeType = FCSizeType.AutoFill;
                }
                else if (value == "percentsize") {
                    m_sizeType = FCSizeType.PercentSize;
                }
            }
            else if (name == "width") {
                Width = FCStr.convertStrToFloat(value);
            }
        }
    }

    /// <summary>
    /// �е���ʽ
    /// </summary>
    public class FCRowStyle {
        /// <summary>
        /// �����е���ʽ
        /// </summary>
        /// <param name="sizeType">������С������</param>
        /// <param name="height">�߶�</param>
        public FCRowStyle(FCSizeType sizeType, float height) {
            m_sizeType = sizeType;
            m_height = height;
        }

        protected float m_height;

        /// <summary>
        /// ��ȡ�����ÿ��
        /// </summary>
        public virtual float Height {
            get { return m_height; }
            set { m_height = value; }
        }

        protected FCSizeType m_sizeType = FCSizeType.AbsoluteSize;

        /// <summary>
        /// ��ȡ�����õ�����С������
        /// </summary>
        public virtual FCSizeType SizeType {
            get { return m_sizeType; }
            set { m_sizeType = value; }
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "sizetype") {
                type = "enum:FCSizeType";
                if (m_sizeType == FCSizeType.AbsoluteSize) {
                    value = "absolutesize";
                }
                else if (m_sizeType == FCSizeType.AutoFill) {
                    value = "autofill";
                }
                else if (m_sizeType == FCSizeType.PercentSize) {
                    value = "percentsize";
                }
            }
            else if (name == "height") {
                type = "float";
                value = FCStr.convertFloatToStr(Height);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.add("SizeType");
            propertyNames.add("Height");
            return propertyNames;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "sizetype") {
                String lowerStr = value.ToLower();
                if (value == "absolutesize") {
                    m_sizeType = FCSizeType.AbsoluteSize;
                }
                else if (value == "autofill") {
                    m_sizeType = FCSizeType.AutoFill;
                }
                else if (value == "percentsize") {
                    m_sizeType = FCSizeType.PercentSize;
                }
            }
            else if (name == "height") {
                Height = FCStr.convertStrToFloat(value);
            }
        }
    }

    /// <summary>
    /// ��񲼾ֿؼ�
    /// </summary>
    public class FCTableLayoutDiv : FCDiv {
        /// <summary>
        /// �������ֿؼ�
        /// </summary>
        public FCTableLayoutDiv() {
        }

        /// <summary>
        /// �еļ���
        /// </summary>
        protected ArrayList<int> m_columns = new ArrayList<int>();

        /// <summary>
        /// �еļ���
        /// </summary>
        protected ArrayList<int> m_rows = new ArrayList<int>();

        /// <summary>
        /// ���ؼ�
        /// </summary>
        protected ArrayList<FCView> m_tableControls = new ArrayList<FCView>();

        protected int m_columnsCount;

        /// <summary>
        /// ��ȡ�������е�����
        /// </summary>
        public virtual int ColumnsCount {
            get { return m_columnsCount; }
            set { m_columnsCount = value; }
        }

        protected ArrayList<FCColumnStyle> m_columnStyles = new ArrayList<FCColumnStyle>();

        /// <summary>
        /// ��ȡ�������е���ʽ
        /// </summary>
        public virtual ArrayList<FCColumnStyle> ColumnStyles {
            get { return m_columnStyles; }
            set { m_columnStyles = value; }
        }

        protected int m_rowsCount;

        /// <summary>
        /// ��ȡ�������е�����
        /// </summary>
        public virtual int RowsCount {
            get { return m_rowsCount; }
            set { m_rowsCount = value; }
        }

        protected ArrayList<FCRowStyle> m_rowStyles = new ArrayList<FCRowStyle>();

        /// <summary>
        /// ��ȡ�������е���ʽ
        /// </summary>
        public virtual ArrayList<FCRowStyle> RowStyles {
            get { return m_rowStyles; }
            set { m_rowStyles = value; }
        }

        /// <summary>
        /// ��ӿؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public override void addControl(FCView control) {
            ArrayList<FCView> controls = m_controls;
            int controlsSize = controls.size();
            base.addControl(control);
            int column = controlsSize % m_columnsCount;
            int row = controlsSize / m_columnsCount;
            m_columns.add(column);
            m_rows.add(row);
            m_tableControls.add(control);
        }

        /// <summary>
        /// ��ӿؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <param name="column">��</param>
        /// <param name="row">��</param>
        public virtual void addControl(FCView control, int column, int row) {
            base.addControl(control);
            m_columns.add(column);
            m_rows.add(row);
            m_tableControls.add(control);
        }

        /// <summary>
        /// ������Դ����
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                m_columns.clear();
                m_columnStyles.clear();
                m_rows.clear();
                m_rowStyles.clear();
                m_tableControls.clear();
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "TableLayoutDiv";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "columnscount") {
                type = "int";
                value = FCStr.convertIntToStr(ColumnsCount);
            }
            else if (name == "rowscount") {
                type = "int";
                value = FCStr.convertIntToStr(RowsCount);
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
            propertyNames.add("ColumnsCount");
            propertyNames.add("RowsCount");
            return propertyNames;
        }

        /// <summary>
        /// ���ò���
        /// </summary>
        public virtual bool OnResetLayout() {
            if (Native != null) {
                if (m_columnsCount > 0 && m_rowsCount > 0 && m_columnStyles.size() > 0 && m_rowStyles.size() > 0) {
                    int width = Width, height = Height;
                    int tabControlsSize = m_tableControls.size();
                    //��ȡ���еĿ��
                    int[] columnWidths = new int[m_columnsCount];
                    int[] rowHeights = new int[m_rowsCount];
                    //��ȡ�еĿ��
                    int allWidth = 0, allHeight = 0;
                    for (int i = 0; i < m_columnsCount; i++) {
                        FCColumnStyle columnStyle = m_columnStyles.get(i);
                        int cWidth = 0;
                        FCSizeType sizeType = columnStyle.SizeType;
                        float sWidth = columnStyle.Width;
                        if (sizeType == FCSizeType.AbsoluteSize) {
                            cWidth = (int)(sWidth);
                        }
                        else if (sizeType == FCSizeType.AutoFill) {
                            cWidth = width - allWidth;
                        }
                        else if (sizeType == FCSizeType.PercentSize) {
                            cWidth = (int)(width * sWidth);
                        }
                        columnWidths[i] = cWidth;
                        allWidth += cWidth;
                    }
                    for (int i = 0; i < m_rowsCount; i++) {
                        FCRowStyle rowStyle = m_rowStyles.get(i);
                        //��ȡ�еĸ߶�
                        int rHeight = 0;
                        FCSizeType sizeType = rowStyle.SizeType;
                        float sHeight = rowStyle.Height;
                        if (sizeType == FCSizeType.AbsoluteSize) {
                            rHeight = (int)(sHeight);
                        }
                        else if (sizeType == FCSizeType.AutoFill) {
                            rHeight = height - allHeight;
                        }
                        else if (sizeType == FCSizeType.PercentSize) {
                            rHeight = (int)(height * sHeight);
                        }
                        rowHeights[i] = rHeight;
                        allHeight += rHeight;
                    }
                    //���ƿؼ��Ĵ�С��λ��
                    for (int i = 0; i < tabControlsSize; i++) {
                        FCView control = m_tableControls.get(i);
                        int column = m_columns[i];
                        int row = m_rows[i];
                        FCPadding margin = control.Margin;
                        //��ȡ�������������
                        int cLeft = 0, cTop = 0;
                        for (int j = 0; j < column; j++) {
                            cLeft += columnWidths[j];
                        }
                        for (int j = 0; j < row; j++) {
                            cTop += rowHeights[j];
                        }
                        int cRight = cLeft + columnWidths[column] - margin.right;
                        int cBottom = cTop + rowHeights[row] - margin.bottom;
                        cLeft += margin.left;
                        cTop += margin.top;
                        if (cRight < cLeft) {
                            cRight = cLeft;
                        }
                        if (cBottom < cTop) {
                            cBottom = cTop;
                        }
                        control.Bounds = new FCRect(cLeft, cTop, cRight, cBottom);
                    }
                }
            }
            return true;
        }

        /// <summary>
        /// �Ƴ��ؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public override void removeControl(FCView control) {
            int tabControlsSize = m_tableControls.size();
            int index = -1;
            for (int i = 0; i < tabControlsSize; i++) {
                if (control == m_tableControls.get(i)) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                m_columns.removeAt(index);
                m_rows.removeAt(index);
                m_tableControls.removeAt(index);
            }
            base.removeControl(control);
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "columnscount") {
                ColumnsCount = FCStr.convertStrToInt(value);
            }
            else if (name == "rowscount") {
                RowsCount = FCStr.convertStrToInt(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ���ָ��·���
        /// </summary>
        public override void update() {
            OnResetLayout();
            int controlsSize = m_controls.size();
            for (int i = 0; i < controlsSize; i++) {
                m_controls.get(i).update();
            }
            updateScrollBar();
        }
    }
}
