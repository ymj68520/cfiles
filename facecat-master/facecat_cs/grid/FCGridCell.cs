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
    /// ��Ԫ����ʽ
    /// </summary>
    public class FCGridCellStyle {
        protected FCHorizontalAlign m_align = FCHorizontalAlign.Inherit;

        /// <summary>
        /// ��ȡ���������ݵĺ���������ʽ
        /// </summary>
        public virtual FCHorizontalAlign Align {
            get { return m_align; }
            set { m_align = value; }
        }

        protected bool m_autoEllipsis;

        /// <summary>
        /// ��ȡ�������Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
        /// </summary>
        public virtual bool AutoEllipsis {
            get { return m_autoEllipsis; }
            set { m_autoEllipsis = value; }
        }

        protected long m_backColor = FCColor.None;

        /// <summary>
        /// ��ȡ
        /// </summary>
        public virtual long BackColor {
            get { return m_backColor; }
            set { m_backColor = value; }
        }

        protected FCFont m_font;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual FCFont Font {
            get { return m_font; }
            set { m_font = value; }
        }

        protected long m_textColor = FCColor.None;

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
    public class FCGridCell : FCProperty {
        /// <summary>
        /// ������Ԫ��
        /// </summary>
        public FCGridCell() {
        }


        /// <summary>
        /// ��������
        /// </summary>
        ~FCGridCell() {
            delete();
        }

        protected bool m_allowEdit;

        /// <summary>
        /// ��ȡ�������Ƿ�ɱ༭
        /// </summary>
        public virtual bool AllowEdit {
            get { return m_allowEdit; }
            set { m_allowEdit = value; }
        }

        protected int colSpan = 1;

        /// <summary>
        /// ��ȡ�����ÿ�Խ������
        /// </summary>
        public virtual int ColSpan {
            get { return colSpan; }
            set { colSpan = value; }
        }

        protected FCGridColumn m_column;

        /// <summary>
        /// ��ȡ������������
        /// </summary>
        public virtual FCGridColumn Column {
            get { return m_column; }
            set { m_column = value; }
        }

        protected FCGrid m_grid;

        /// <summary>
        /// ��ȡ�����ñ��
        /// </summary>
        public virtual FCGrid Grid {
            get { return m_grid; }
            set { m_grid = value; }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        protected String m_name;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual String Name {
            get { return m_name; }
            set { m_name = value; }
        }

        protected FCGridRow m_row;

        /// <summary>
        /// ��ȡ������������
        /// </summary>
        public FCGridRow Row {
            get { return m_row; }
            set { m_row = value; }
        }

        protected int rowSpan = 1;

        /// <summary>
        /// ��ȡ�����ÿ�Խ������
        /// </summary>
        public virtual int RowSpan {
            get { return rowSpan; }
            set { rowSpan = value; }
        }

        protected FCGridCellStyle m_style;

        /// <summary>
        /// ��ȡ��������ʽ
        /// </summary>
        public virtual FCGridCellStyle Style {
            get { return m_style; }
            set { m_style = value; }
        }

        protected object m_tag = null;

        /// <summary>
        /// ��ȡ������TAGֵ
        /// </summary>
        public virtual object Tag {
            get { return m_tag; }
            set { m_tag = value; }
        }

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual String Text {
            get { return getString(); }
            set { setString(value); }
        }

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public virtual int compareTo(FCGridCell cell) {
            return 0;
        }

        /// <summary>
        /// ������Դ
        /// </summary>
        public virtual void delete() {
            m_isDeleted = true;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public virtual bool getBool() {
            return false;
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public virtual double getDouble() {
            return 0;
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public virtual float getFloat() {
            return 0;
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public virtual int getInt() {
            return 0;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public virtual long getLong() {
            return 0;
        }

        /// <summary>
        /// ��ȡҪ���Ƶ�����
        /// </summary>
        /// <returns>Ҫ���Ƶ�����</returns>
        public virtual String getPaintText() {
            return Text;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "align") {
                type = "enum:FCHorizontalAlign";
                FCGridCellStyle style = Style;
                if (style != null) {
                    value = FCStr.convertHorizontalAlignToStr(style.Align);
                }
            }
            else if (name == "allowedit") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowEdit);
            }
            else if (name == "autoellipsis") {
                type = "bool";
                FCGridCellStyle style = Style;
                if (style != null) {
                    value = FCStr.convertBoolToStr(style.AutoEllipsis);
                }
            }
            else if (name == "backcolor") {
                type = "color";
                FCGridCellStyle style = Style;
                if (style != null) {
                    value = FCStr.convertColorToStr(style.BackColor);
                }
            }
            else if (name == "colspan") {
                type = "int";
                value = FCStr.convertIntToStr(ColSpan);
            }
            else if (name == "font") {
                type = "font";
                FCGridCellStyle style = Style;
                if (style != null && style.Font != null) {
                    value = FCStr.convertFontToStr(style.Font);
                }
            }
            else if (name == "name") {
                type = "String";
                value = Name;
            }
            else if (name == "rowspan") {
                type = "int";
                value = FCStr.convertIntToStr(RowSpan);
            }
            else if (name == "text") {
                type = "String";
                value = Text;
            }
            else if (name == "textcolor") {
                type = "color";
                FCGridCellStyle style = Style;
                if (style != null) {
                    value = FCStr.convertColorToStr(style.TextColor);
                }
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
            propertyNames.AddRange(new String[] { "Align", "AllowEdit", "AutoEllipsis", "BackColor", "ColSpan", "Font", "Name", "RowSpan", "Text", "TextColor"});
            return propertyNames;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public virtual String getString() {
            return "";
        }

        /// <summary>
        /// ��ӵ�Ԫ�񷽷�
        /// </summary>
        public virtual void onAdd() {
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        /// <param name="isAlternate">�Ƿ�����</param>
        public virtual void onPaint(FCPaint paint, FCRect rect, FCRect clipRect, bool isAlternate) {
            int clipW = clipRect.right - clipRect.left;
            int clipH = clipRect.bottom - clipRect.top;
            if (clipW > 0 && clipH > 0) {
                if (m_grid != null && m_row != null && m_column != null) {
                    //�ж�ѡ��
                    String text = getPaintText();
                    bool selected = false;
                    if (m_grid.SelectionMode == FCGridSelectionMode.SelectCell) {
                        ArrayList<FCGridCell> selectedCells = m_grid.SelectedCells;
                        int selectedCellSize = selectedCells.size();
                        for (int i = 0; i < selectedCellSize; i++) {
                            if (selectedCells.get(i) == this) {
                                selected = true;
                                break;
                            }
                        }
                    }
                    else if (m_grid.SelectionMode == FCGridSelectionMode.SelectFullColumn) {
                        ArrayList<FCGridColumn> selectedColumns = m_grid.SelectedColumns;
                        int selectedColumnsSize = selectedColumns.size();
                        for (int i = 0; i < selectedColumnsSize; i++) {
                            if (selectedColumns.get(i) == m_column) {
                                selected = true;
                                break;
                            }
                        }
                    }
                    else if (m_grid.SelectionMode == FCGridSelectionMode.SelectFullRow) {
                        ArrayList<FCGridRow> selectedRows = m_grid.SelectedRows;
                        int selectedRowsSize = selectedRows.size();
                        for (int i = 0; i < selectedRowsSize; i++) {
                            if (selectedRows.get(i) == m_row) {
                                selected = true;
                                break;
                            }
                        }
                    }
                    //��ȡ��ɫ
                    FCFont font = null;
                    long backColor = FCColor.None;
                    long textColor = FCColor.None;
                    bool autoEllipsis = m_grid.AutoEllipsis;
                    FCHorizontalAlign horizontalAlign = m_column.CellAlign;
                    if (m_style != null) {
                        if (m_style.AutoEllipsis) {
                            autoEllipsis = m_style.AutoEllipsis;
                        }
                        backColor = m_style.BackColor;
                        if (m_style.Font != null) {
                            font = m_style.Font;
                        }
                        textColor = m_style.TextColor;
                        if (m_style.Align != FCHorizontalAlign.Inherit) {
                            horizontalAlign = m_style.Align;
                        }
                    }
                    FCGridRowStyle rowStyle = m_grid.RowStyle;
                    if (isAlternate) {
                        FCGridRowStyle alternateRowStyle = m_grid.AlternateRowStyle;
                        if (alternateRowStyle != null) {
                            rowStyle = alternateRowStyle;
                        }
                    }
                    if (rowStyle != null) {
                        if (backColor == FCColor.None) {
                            if (selected) {
                                backColor = rowStyle.SelectedBackColor;
                            }
                            else if (m_row == m_grid.HoveredRow) {
                                backColor = rowStyle.HoveredBackColor;
                            }
                            else {
                                backColor = rowStyle.BackColor;
                            }
                        }
                        if (font == null) {
                            font = rowStyle.Font;
                        }
                        if (textColor == FCColor.None) {
                            if (selected) {
                                textColor = rowStyle.SelectedTextColor;
                            }
                            else if (m_row == m_grid.HoveredRow) {
                                textColor = rowStyle.HoveredTextColor;
                            }
                            else {
                                textColor = rowStyle.TextColor;
                            }
                        }
                    }
                    paint.fillRect(backColor, rect);
                    FCSize tSize = paint.textSize(text, font);
                    FCPoint tPoint = new FCPoint(rect.left + 1, rect.top + clipH / 2 - tSize.cy / 2);
                    int width = rect.right - rect.left;
                    if (tSize.cx < width) {
                        if (horizontalAlign == FCHorizontalAlign.Center) {
                            tPoint.x = rect.left + (rect.right - rect.left - tSize.cx) / 2;
                        }
                        else if (horizontalAlign == FCHorizontalAlign.Right) {
                            tPoint.x = rect.right - tSize.cx - 2;
                        }
                    }
                    FCRect tRect = new FCRect(tPoint.x, tPoint.y, tPoint.x + tSize.cx, tPoint.y + tSize.cy);
                    if (autoEllipsis && (tRect.right > clipRect.right || tRect.bottom > clipRect.bottom)) {
                        if (tRect.right > clipRect.right) {
                            tRect.right = clipRect.right;
                        }
                        if (tRect.bottom > clipRect.bottom) {
                            tRect.bottom = clipRect.bottom;
                        }
                        paint.drawTextAutoEllipsis(text, textColor, font, tRect);
                    }
                    else {
                        paint.drawText(text, textColor, font, tRect);
                    }
                }
            }
        }

        /// <summary>
        /// �Ƴ���Ԫ�񷽷�
        /// </summary>
        public virtual void onRemove() {
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public virtual void setBool(bool value) {
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public virtual void setDouble(double value) {
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public virtual void setFloat(float value) {
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public virtual void setInt(int value) {
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public virtual void setLong(long value) {
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "align") {
                if (m_style == null) {
                    m_style = new FCGridCellStyle();
                }
                m_style.Align = FCStr.convertStrToHorizontalAlign(value);
            }
            else if (name == "allowedit") {
                AllowEdit = FCStr.convertStrToBool(value);
            }
            else if (name == "autoellipsis") {
                if (m_style == null) {
                    m_style = new FCGridCellStyle();
                }
                m_style.AutoEllipsis = FCStr.convertStrToBool(value);
            }
            else if (name == "backcolor") {
                if (m_style == null) {
                    m_style = new FCGridCellStyle();
                }
                m_style.BackColor = FCStr.convertStrToColor(value);
            }
            else if (name == "colspan") {
                ColSpan = FCStr.convertStrToInt(value);
            }
            else if (name == "font") {
                if (m_style == null) {
                    m_style = new FCGridCellStyle();
                }
                m_style.Font = FCStr.convertStrToFont(value);
            }
            else if (name == "textcolor") {
                if (m_style == null) {
                    m_style = new FCGridCellStyle();
                }
                m_style.TextColor = FCStr.convertStrToColor(value);
            }
            else if (name == "name") {
                Name = value;
            }
            else if (name == "rowspan") {
                RowSpan = FCStr.convertStrToInt(value);
            }
            else if (name == "text") {
                Text = value;
            }
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public virtual void setString(String value) {
        }
    }

    /// <summary>
    /// �ؼ���Ԫ��
    /// </summary>
    public class FCGridControlCell : FCGridCell {
        /// <summary>
        /// ������Ԫ��
        /// </summary>
        public FCGridControlCell() {
            m_touchDownEvent = new FCTouchEvent(controlTouchDown);
            m_touchMoveEvent = new FCTouchEvent(controlTouchMove);
            m_touchUpEvent = new FCTouchEvent(controlToucheUp);
            m_touchWheelEvent = new FCTouchEvent(controlTouchWheel);
        }

        /// <summary>
        /// ��������
        /// </summary>
        ~FCGridControlCell() {
            if (m_control != null) {
                m_control.delete();
                m_control = null;
            }
            m_touchDownEvent = null;
            m_touchMoveEvent = null;
            m_touchUpEvent = null;
            m_touchWheelEvent = null;
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        private FCTouchEvent m_touchDownEvent;

        /// <summary>
        /// �����ƶ��¼�
        /// </summary>
        private FCTouchEvent m_touchMoveEvent;

        /// <summary>
        /// ����̧���¼�
        /// </summary>
        private FCTouchEvent m_touchUpEvent;

        /// <summary>
        /// ���������¼�
        /// </summary>
        private FCTouchEvent m_touchWheelEvent;

        protected FCView m_control;

        /// <summary>
        /// ��ȡ�����ÿؼ�
        /// </summary>
        public virtual FCView Control {
            get { return m_control; }
            set { m_control = value; }
        }

        /// <summary>
        /// ��ȡҪ���Ƶ�����
        /// </summary>
        /// <returns>Ҫ���Ƶ�����</returns>
        public override String getPaintText() {
            return "";
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            if (m_control != null) {
                return m_control.Text;
            }
            else {
                return "";
            }
        }

        /// <summary>
        /// �ؼ����������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        protected void controlTouchDown(object sender, FCTouchInfo touchInfo) {
            onControlTouchDown(touchInfo);
        }

        /// <summary>
        /// �ؼ������ƶ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        protected void controlTouchMove(object sender, FCTouchInfo touchInfo) {
            onControlTouchMove(touchInfo);
        }

        /// <summary>
        /// �ؼ�����̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        protected void controlToucheUp(object sender, FCTouchInfo touchInfo) {
            onControlTouchUp(touchInfo);
        }

        /// <summary>
        /// �ؼ��������ֹ����¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        protected void controlTouchWheel(object sender, FCTouchInfo touchInfo) {
            onControlTouchWheel(touchInfo);
        }

        /// <summary>
        /// ��ӵ�Ԫ�񷽷�
        /// </summary>
        public override void onAdd() {
            FCGrid grid = Grid;
            if (m_control != null && grid != null) {
                grid.addControl(m_control);
                m_control.addEvent(m_touchDownEvent, FCEventID.TOUCHDOWN);
                m_control.addEvent(m_touchMoveEvent, FCEventID.TOUCHMOVE);
                m_control.addEvent(m_touchUpEvent, FCEventID.TOUCHUP);
                m_control.addEvent(m_touchWheelEvent, FCEventID.TOUCHWHEEL);
            }
        }

        /// <summary>
        /// �ؼ��������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onControlTouchDown(FCTouchInfo touchInfo) {
            FCGrid grid = Grid;
            if (m_control != null && grid != null) {
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_firstPoint));
                newTouchInfo.m_secondPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_secondPoint));
                grid.onTouchDown(newTouchInfo);
            }
        }

        /// <summary>
        /// �ؼ������ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onControlTouchMove(FCTouchInfo touchInfo) {
            FCGrid grid = Grid;
            if (m_control != null && grid != null) {
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_firstPoint));
                newTouchInfo.m_secondPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_secondPoint));
                grid.onTouchMove(newTouchInfo);
            }
        }

        /// <summary>
        /// �ؼ�����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onControlTouchUp(FCTouchInfo touchInfo) {
            FCGrid grid = Grid;
            if (m_control != null && grid != null) {
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_firstPoint));
                newTouchInfo.m_secondPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_secondPoint));
                grid.onTouchUp(newTouchInfo);
            }
        }

        /// <summary>
        /// �ؼ��������ֹ�������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public virtual void onControlTouchWheel(FCTouchInfo touchInfo) {
            FCGrid grid = Grid;
            if (m_control != null && grid != null) {
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_firstPoint));
                newTouchInfo.m_secondPoint = grid.pointToControl(m_control.pointToNative(touchInfo.m_secondPoint));
                grid.onTouchWheel(newTouchInfo);
            }
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        /// <param name="isAlternate">�Ƿ�����</param>
        public override void onPaint(FCPaint paint, FCRect rect, FCRect clipRect, bool isAlternate) {
            base.onPaint(paint, rect, clipRect, isAlternate);
            onPaintControl(paint, rect, clipRect);
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaintControl(FCPaint paint, FCRect rect, FCRect clipRect) {
            if (m_control != null) {
                FCRect bounds = new FCRect(rect.left + 1, rect.top + 1, rect.right - 1, rect.bottom - 1);
                m_control.Bounds = bounds;
                clipRect.left -= rect.left;
                clipRect.top -= rect.top;
                clipRect.right -= rect.left;
                clipRect.bottom -= rect.top;
                m_control.Region = clipRect;
            }
        }

        /// <summary>
        /// �Ƴ���Ԫ�񷽷�
        /// </summary>
        public override void onRemove() {
            FCGrid grid = Grid;
            if (m_control != null && grid != null) {
                m_control.removeEvent(m_touchDownEvent, FCEventID.TOUCHDOWN);
                m_control.removeEvent(m_touchMoveEvent, FCEventID.TOUCHMOVE);
                m_control.removeEvent(m_touchUpEvent, FCEventID.TOUCHUP);
                m_control.removeEvent(m_touchWheelEvent, FCEventID.TOUCHWHEEL);
                grid.removeControl(m_control);
            }
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            if (m_control != null) {
                m_control.Text = value;
            }
        }
    }
}
