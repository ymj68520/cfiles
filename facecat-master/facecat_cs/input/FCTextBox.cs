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
using System.Windows.Forms;

namespace FaceCat {
    /// <summary>
    /// �ַ���
    /// </summary>
    public struct FCWordLine {
        /// <summary>
        /// ������
        /// </summary>
        /// <param name="start">��ʼ����</param>
        /// <param name="end">��������</param>
        public FCWordLine(int start, int end) {
            m_start = start;
            m_end = end;
        }

        /// <summary>
        /// ��������
        /// </summary>
        public int m_end;

        /// <summary>
        /// ��ʼ����
        /// </summary>
        public int m_start;
    }

    /// <summary>
    /// �ı���ؼ�
    /// </summary>
    public class FCTextBox : FCDiv {
        /// <summary>
        /// �����ؼ�
        /// </summary>
        public FCTextBox() {
            this.Cursor = FCCursors.IBeam;
            FCSize size = new FCSize(100, 20);
            Size = size;
            TabStop = true;
        }

        /// <summary>
        /// �����Ƿ���
        /// </summary>
        protected bool m_isKeyDown;

        /// <summary>
        /// �Ƿ�������
        /// </summary>
        protected bool m_isTouchDown;

        /// <summary>
        /// ����ƫ����
        /// </summary>
        protected int m_offsetX = 0;

        /// <summary>
        /// ���־��η�Χ
        /// </summary>
        protected ArrayList<FCRectF> m_ranges = new ArrayList<FCRectF>();

        /// <summary>
        /// ����ջ
        /// </summary>
        protected Stack<String> m_redoStack = new Stack<String>();

        /// <summary>
        /// �Ƿ���ʾ���
        /// </summary>
        protected bool m_showCursor = false;

        /// <summary>
        /// ��ʼ�ƶ�������
        /// </summary>
        protected int m_startMovingIndex = -1;

        /// <summary>
        /// �����ƶ�������
        /// </summary>
        protected int m_stopMovingIndex = -1;

        /// <summary>
        /// �����Ƿ�ı�
        /// </summary>
        protected bool m_textChanged = false;

        /// <summary>
        /// �����˸Ƶ��
        /// </summary>
        protected int TICK = 500;

        /// <summary>
        /// ���ID
        /// </summary>
        private int m_timerID = getNewTimerID();

        /// <summary>
        /// ����ջ
        /// </summary>
        protected Stack<String> m_undoStack = new Stack<String>();

        /// <summary>
        /// ���ִ�С
        /// </summary>
        protected ArrayList<FCSizeF> m_wordsSize = new ArrayList<FCSizeF>();

        /// <summary>
        /// ��ȡ����
        /// </summary>
        public virtual int LinesCount {
            get { return m_lines.size(); }
        }

        protected int m_lineHeight = 20;

        /// <summary>
        /// ��ȡ�������и�
        /// </summary>
        public virtual int LineHeight {
            get { return m_lineHeight; }
            set { m_lineHeight = value; }
        }

        protected ArrayList<FCWordLine> m_lines = new ArrayList<FCWordLine>();

        /// <summary>
        /// ��ȡ����
        /// </summary>
        public virtual ArrayList<FCWordLine> Lines {
            get { return m_lines; }
        }

        protected bool m_multiline = false;

        /// <summary>
        /// ��ȡ�������Ƿ������ʾ
        /// </summary>
        public virtual bool Multiline {
            get { return m_multiline; }
            set {
                if (m_multiline != value) {
                    m_multiline = value;
                    m_textChanged = true;
                }
                ShowVScrollBar = m_multiline;
            }
        }

        protected char m_passwordChar;

        /// <summary>
        /// ��ȡ�����������ַ�
        /// </summary>
        public virtual char PasswordChar {
            get { return m_passwordChar; }
            set {
                m_passwordChar = value;
                m_textChanged = true;
            }
        }

        protected bool m_readOnly = false;

        /// <summary>
        /// ��ȡ�������Ƿ�ֻ��
        /// </summary>
        public virtual bool ReadOnly {
            get { return m_readOnly; }
            set { m_readOnly = value; }
        }

        protected bool m_rightToLeft;

        /// <summary>
        /// ��ȡ�������Ƿ�����������
        /// </summary>
        public virtual bool RightToLeft {
            get { return m_rightToLeft; }
            set {
                m_rightToLeft = value;
                m_textChanged = true;
            }
        }

        /// <summary>
        /// ��ȡѡ�е�����
        /// </summary>
        public virtual String SelectionText {
            get {
                String text = Text;
                if (text == null) {
                    text = "";
                }
                int textLength = text.Length;
                if (textLength > 0 && m_selectionStart != textLength) {
                    String selectedText = text.Substring(m_selectionStart, m_selectionLength);
                    return selectedText;
                }
                return String.Empty;
            }
        }

        protected long m_selectionBackColor = FCColor.argb(10, 36, 106);

        /// <summary>
        /// ��ȡ������ѡ�еı���ɫ
        /// </summary>
        public virtual long SelectionBackColor {
            get { return m_selectionBackColor; }
            set { m_selectionBackColor = value; }
        }

        protected long m_selectionTextColor = FCColor.argb(255, 255, 255);

        /// <summary>
        /// ��ȡ������ѡ�е�ǰ��ɫ
        /// </summary>
        public virtual long SelectionTextColor {
            get { return m_selectionTextColor; }
            set { m_selectionTextColor = value; }
        }

        protected int m_selectionLength;

        /// <summary>
        /// ��ȡ������ѡ�г���
        /// </summary>
        public virtual int SelectionLength {
            get { return m_selectionLength; }
            set { m_selectionLength = value; }
        }

        protected int m_selectionStart = -1;

        /// <summary>
        /// ��ȡ������ѡ�п�ʼλ��
        /// </summary>
        public virtual int SelectionStart {
            get { return m_selectionStart; }
            set {
                m_selectionStart = value;
                if (m_selectionStart > Text.Length) {
                    m_selectionStart = Text.Length;
                }
            }
        }

        protected String m_tempText;

        /// <summary>
        /// ��ȡ��������ʱ����
        /// </summary>
        public virtual String TempText {
            get { return m_tempText; }
            set { m_tempText = value; }
        }

        protected long m_tempTextColor = FCColor.DisabledText;

        /// <summary>
        /// ��ȡ��������ʱ���ֵ���ɫ
        /// </summary>
        public virtual long TempTextColor {
            get { return m_tempTextColor; }
            set { m_tempTextColor = value; }
        }

        protected FCHorizontalAlign m_textAlign = FCHorizontalAlign.Left;

        /// <summary>
        /// ��ȡ���������ݵĺ���������ʽ
        /// </summary>
        public virtual FCHorizontalAlign TextAlign {
            get { return m_textAlign; }
            set { m_textAlign = value; }
        }

        protected bool m_wordWrap = false;

        /// <summary>
        /// ��ȡ�����ö��б༭�ؼ��Ƿ���������
        /// </summary>
        public virtual bool WordWrap {
            get { return m_wordWrap; }
            set {
                if (m_wordWrap != value) {
                    m_wordWrap = value;
                    m_textChanged = true;
                }
                ShowHScrollBar = !m_wordWrap;
            }
        }

        /// <summary>
        /// �ж��Ƿ�����ظ�
        /// </summary>
        /// <returns>�Ƿ�����ظ�</returns>
        public bool canRedo() {
            if (m_redoStack.Count > 0) {
                return true;
            }
            return false;
        }

        /// <summary>
        /// �ж��Ƿ���Գ���
        /// </summary>
        /// <returns>�Ƿ���Գ���</returns>
        public bool canUndo() {
            if (m_undoStack.Count > 0) {
                return true;
            }
            return false;
        }

        /// <summary>
        /// ����
        /// </summary>
        public void clearRedoUndo() {
            m_undoStack.Clear();
            m_redoStack.Clear();
        }

        /// <summary>
        /// ��������ƶ�
        /// </summary>
        public void cursorDown() {
            FCHost host = Native.Host;
            int scol = -1, srow = -1;
            int rangeSize = m_ranges.size();
            int start = m_selectionStart + m_selectionLength < rangeSize - 1 ? m_selectionStart + m_selectionLength : rangeSize - 1;
            if (host.isKeyPress(0x10)) {
                start = m_stopMovingIndex;
            }
            else {
                if (m_selectionLength > 0) {
                    m_selectionLength = 1;
                }
            }
            int lineCount = m_lines.size();
            bool check = false;
            for (int i = 0; i < lineCount; i++) {
                FCWordLine line = m_lines[i];
                for (int j = line.m_start; j <= line.m_end; j++) {
                    if (j >= start && j < rangeSize) {
                        int col = j - line.m_start;
                        if (j == start) {
                            if (i != 0 && j == line.m_start) {
                                check = true;
                                srow = i - 1;
                                scol = line.m_end + 1;
                            }
                            else {
                                if (i != lineCount - 1) {
                                    check = true;
                                    int idx = j - line.m_start;
                                    scol = m_lines[i + 1].m_start + idx + 1;
                                    srow = i;
                                    continue;
                                }
                            }
                        }
                        if (check) {
                            if (i == srow + 1) {
                                if (host.isKeyPress(0x10)) {
                                    setMovingIndex(m_startMovingIndex, j);
                                }
                                else {
                                    if (scol > line.m_end) {
                                        scol = line.m_end + 1;
                                    }
                                    m_selectionStart = scol;
                                    m_selectionLength = 0;
                                    m_startMovingIndex = m_selectionStart;
                                    m_stopMovingIndex = m_selectionStart;
                                }
                                m_showCursor = true;
                                startTimer(m_timerID, TICK);
                                return;
                            }
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ����ƶ������Ҷ�
        /// </summary>
        public void cursorEnd() {
            FCHost host = Native.Host;
            int rangeSize = m_ranges.size();
            int start = m_selectionStart + m_selectionLength < rangeSize - 1 ? m_selectionStart + m_selectionLength : rangeSize - 1;
            if (host.isKeyPress(0x10)) {
                start = m_stopMovingIndex;
            }
            int lineCount = m_lines.size();
            for (int i = 0; i < lineCount; i++) {
                FCWordLine line = m_lines[i];
                for (int j = line.m_start; j <= line.m_end; j++) {
                    if (j == start) {
                        if (j == line.m_start && i > 0) {
                            line = m_lines[i - 1];
                        }
                        if (host.isKeyPress(0x10)) {
                            setMovingIndex(m_startMovingIndex, line.m_end + 1);
                        }
                        else {
                            m_selectionStart = line.m_end + 1;
                            m_selectionLength = 0;
                            m_startMovingIndex = m_selectionStart;
                            m_stopMovingIndex = m_selectionStart;
                        }
                        m_showCursor = true;
                        startTimer(m_timerID, TICK);
                        return;
                    }
                }
            }
        }

        /// <summary>
        /// ����ƶ��������
        /// </summary>
        public void cursorHome() {
            FCHost host = Native.Host;
            int rangeSize = m_ranges.size();
            int start = m_selectionStart < rangeSize - 1 ? m_selectionStart : rangeSize - 1;
            if (host.isKeyPress(0x10)) {
                start = m_stopMovingIndex;
            }
            int lineCount = m_lines.size();
            for (int i = 0; i < lineCount; i++) {
                FCWordLine line = m_lines[i];
                for (int j = line.m_start; j <= line.m_end; j++) {
                    if (j == start) {
                        if (j == line.m_start && i > 0) {
                            line = m_lines[i - 1];
                        }
                        if (host.isKeyPress(0x10)) {
                            setMovingIndex(m_startMovingIndex, line.m_start + 1);
                        }
                        else {
                            m_selectionStart = line.m_start + 1;
                            m_selectionLength = 0;
                            m_startMovingIndex = m_selectionStart;
                            m_stopMovingIndex = m_selectionStart;
                        }
                        m_showCursor = true;
                        startTimer(m_timerID, TICK);
                        return;
                    }
                }
            }
        }

        /// <summary>
        /// ��������ƶ�
        /// </summary>
        public void cursorLeft() {
            FCHost host = Native.Host;
            if (host.isKeyPress(0x10)) {
                setMovingIndex(m_startMovingIndex, m_stopMovingIndex - 1);
            }
            else {
                if (m_selectionStart > 0) {
                    m_selectionStart -= 1;
                }
                m_selectionLength = 0;
                m_startMovingIndex = m_selectionStart;
                m_stopMovingIndex = m_selectionStart;
            }
        }

        /// <summary>
        /// ��������ƶ�
        /// </summary>
        public void cursorRight() {
            FCHost host = Native.Host;
            if (host.isKeyPress(0x10)) {
                setMovingIndex(m_startMovingIndex, m_stopMovingIndex + 1);
            }
            else {
                int rangeSize = m_ranges.size();
                int start = m_selectionStart + m_selectionLength < rangeSize - 1 ? m_selectionStart + m_selectionLength : rangeSize - 1;
                if (start < rangeSize) {
                    m_selectionStart = start + 1;
                }
                m_selectionLength = 0;
                m_startMovingIndex = m_selectionStart;
                m_stopMovingIndex = m_selectionStart;
            }
        }

        /// <summary>
        /// ��������ƶ�
        /// </summary>
        public void cursorUp() {
            FCHost host = Native.Host;
            int scol = -1, srow = -1;
            int rangeSize = m_ranges.size();
            int start = m_selectionStart < rangeSize - 1 ? m_selectionStart : rangeSize - 1;
            if (host.isKeyPress(0x10)) {
                start = m_stopMovingIndex;
            }
            else {
                if (m_selectionLength > 0) {
                    m_selectionLength = 1;
                }
            }
            int lineCount = m_lines.size();
            bool check = false;
            for (int i = lineCount - 1; i >= 0; i--) {
                FCWordLine line = m_lines[i];
                for (int j = line.m_end; j >= line.m_start; j--) {
                    if (j >= 0 && j <= start) {
                        int col = j - line.m_start;
                        if (i != 0 && j == start) {
                            check = true;
                            if (i != lineCount - 1 && j == line.m_start) {
                                srow = i;
                                scol = m_lines[i - 1].m_start;
                            }
                            else {
                                int idx = j - line.m_start;
                                scol = m_lines[i - 1].m_start + idx - 1;
                                if (scol < 0) {
                                    scol = 0;
                                }
                                srow = i;
                            }
                            continue;
                        }
                        if (check) {
                            if (i == srow - 1 && col <= scol) {
                                if (host.isKeyPress(0x10)) {
                                    setMovingIndex(m_startMovingIndex, j);
                                }
                                else {
                                    if (scol > line.m_end) {
                                        scol = line.m_end + 1;
                                    }
                                    m_selectionStart = scol;
                                    m_selectionLength = 0;
                                    m_startMovingIndex = m_selectionStart;
                                    m_stopMovingIndex = m_selectionStart;
                                }
                                m_showCursor = true;
                                startTimer(m_timerID, TICK);
                                return;
                            }
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ɾ���ַ�
        /// </summary>
        public virtual void deleteWord() {
            String text = Text;
            if (text == null) {
                text = "";
            }
            int textLength = text.Length;
            if (textLength > 0) {
                int oldLines = m_lines.size();
                String left = "", right = "";
                int rightIndex = -1;
                if (m_selectionLength > 0) {
                    left = m_selectionStart > 0 ? text.Substring(0, m_selectionStart) : "";
                    rightIndex = m_selectionStart + m_selectionLength;
                }
                else {
                    left = m_selectionStart > 0 ? text.Substring(0, m_selectionStart - 1) : "";
                    rightIndex = m_selectionStart + m_selectionLength;
                    if (m_selectionStart > 0) {
                        m_selectionStart -= 1;
                    }
                }
                if (rightIndex < textLength) {
                    right = text.Substring(rightIndex);
                }
                String newText = left + right;
                m_text = newText;
                textLength = newText.Length;
                if (textLength == 0) {
                    m_selectionStart = 0;
                }
                else {
                    if (m_selectionStart > textLength) {
                        m_selectionStart = textLength;
                    }
                }
                m_selectionLength = 0;
            }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                stopTimer(m_timerID);
                m_lines.clear();
                m_ranges.clear();
                m_redoStack.Clear();
                m_undoStack.Clear();
                m_wordsSize.clear();
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ���ݵĸ߶�
        /// </summary>
        /// <returns>�߶�</returns>
        public override int getContentHeight() {
            int hmax = base.getContentHeight();
            int cheight = 0;
            int rangeSize = m_ranges.size();
            for (int i = 0; i < rangeSize; i++) {
                if (cheight < m_ranges[i].bottom) {
                    cheight = (int)m_ranges[i].bottom;
                }
            }
            return hmax > cheight ? hmax : cheight;
        }

        /// <summary>
        /// ��ȡ���ݵĿ��
        /// </summary>
        /// <returns>���</returns>
        public override int getContentWidth() {
            int wmax = base.getContentWidth();
            int cwidth = 0;
            int rangeSize = m_ranges.size();
            for (int i = 0; i < rangeSize; i++) {
                if (cwidth < m_ranges[i].right) {
                    cwidth = (int)m_ranges[i].right;
                }
            }
            return wmax > cwidth ? wmax : cwidth;
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "TextBox";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "lineheight") {
                type = "int";
                value = FCStr.convertIntToStr(LineHeight);
            }
            else if (name == "multiline") {
                type = "bool";
                value = FCStr.convertBoolToStr(Multiline);
            }
            else if (name == "passwordchar") {
                type = "text";
                value = PasswordChar.ToString();
            }
            else if (name == "readonly") {
                type = "bool";
                value = FCStr.convertBoolToStr(ReadOnly);
            }
            else if (name == "righttoleft") {
                type = "bool";
                value = FCStr.convertBoolToStr(RightToLeft);
            }
            else if (name == "selectionbackcolor") {
                type = "color";
                value = FCStr.convertColorToStr(SelectionBackColor);
            }
            else if (name == "selectiontextcolor") {
                type = "color";
                value = FCStr.convertColorToStr(SelectionTextColor);
            }
            else if (name == "temptext") {
                type = "text";
                value = TempText;
            }
            else if (name == "temptextcolor") {
                type = "color";
                value = FCStr.convertColorToStr(TempTextColor);
            }
            else if (name == "textalign") {
                type = "enum:FCHorizontalAlign";
                value = FCStr.convertHorizontalAlignToStr(TextAlign);
            }
            else if (name == "wordwrap") {
                type = "bool";
                value = FCStr.convertBoolToStr(WordWrap);
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
            propertyNames.AddRange(new String[] { "LineHeight", "Multiline", "PasswordChar", "ReadOnly", "RightToLeft", "SelectionBackColor", "SelectionTextColor", "TempText", "TempTextColor", "TextAlign", "WordWrap" });
            return propertyNames;
        }

        /// <summary>
        /// �ж��ַ������������Ƿ�ɼ�
        /// </summary>
        /// <param name="index">�ַ�����</param>
        /// <param name="visiblePercent">�ɼ��ٷֱ�</param>
        /// <returns>�Ƿ�ɼ�</returns>
        public bool isLineVisible(int index, double visiblePercent) {
            int rangeSize = m_ranges.size();
            if (rangeSize > 0) {
                if (index >= 0 && index < rangeSize) {
                    int top = 0, scrollV = 0, sch = 0;
                    FCHScrollBar hScrollBar = HScrollBar;
                    FCVScrollBar vScrollBar = VScrollBar;
                    if (hScrollBar != null && hScrollBar.Visible) {
                        sch = hScrollBar.Height;
                    }
                    if (vScrollBar != null && vScrollBar.Visible) {
                        scrollV = -vScrollBar.Pos;
                    }
                    top = scrollV;
                    int cell = 1;
                    int floor = Height - cell - sch - 1;
                    FCRectF indexRect = m_ranges[index];
                    int indexTop = (int)indexRect.top + scrollV;
                    int indexBottom = (int)indexRect.bottom + scrollV;
                    return lineVisible(indexTop, indexBottom, cell, floor, m_lineHeight, visiblePercent);
                }
            }
            return false;
        }


        /// <summary>
        /// �����ַ�
        /// </summary>
        /// <param name="str">�ַ���</param>
        public virtual void insertWord(String str) {
            String text = Text;
            if (text == null) {
                text = "";
            }
            if (text.Length == 0 || m_selectionStart == text.Length) {
                text = text + str;
                m_text = text;
                m_selectionStart = text.Length;
            }
            else {
                int sIndex = m_selectionStart > text.Length ? text.Length : m_selectionStart;
                String left = sIndex > 0 ? text.Substring(0, sIndex) : "";
                String right = "";
                int rightIndex = m_selectionStart + (m_selectionLength == 0 ? 0 : m_selectionLength);
                if (rightIndex < text.Length) {
                    right = text.Substring(rightIndex);
                }
                text = left + str + right;
                m_text = text;
                m_selectionStart += str.Length;
                if (m_selectionStart > text.Length) {
                    m_selectionStart = text.Length;
                }
                m_selectionLength = 0;
            }
        }

        /// <summary>
        /// �ж����Ƿ�ɼ�
        /// </summary>
        /// <param name="indexTop"></param>
        /// <param name="indexBottom"></param>
        /// <param name="cell"></param>
        /// <param name="floor"></param>
        /// <param name="lineHeight"></param>
        /// <param name="visiblePercent"></param>
        /// <returns></returns>
        public virtual bool lineVisible(int indexTop, int indexBottom, int cell, int floor, int lineHeight, double visiblePercent) {
            if (indexTop < cell) {
                indexTop = cell;
            }
            else if (indexTop > floor) {
                indexTop = floor;
            }
            if (indexBottom < cell) {
                indexBottom = cell;
            }
            else if (indexBottom > floor) {
                indexBottom = floor;
            }
            if (indexBottom - indexTop > lineHeight * visiblePercent) {
                return true;
            }
            return false;
        }

        /// <summary>
        /// �ı����뷽��
        /// </summary>
        /// <param name="ch">����</param>
        public override void onChar(char ch) {
            if (!m_readOnly) {
                base.onChar(ch);
                FCHost host = Native.Host;
                if (!host.isKeyPress(0x11)) {
                    int oldLines = m_lines.size();
                    if (ch != 8 || (!m_multiline && ch == 13)) {
                        String redotext = Text;
                        insertWord(ch.ToString());
                        onTextChanged();
                        if (m_textChanged) {
                            if (redotext != null) {
                                m_undoStack.Push(redotext);
                            }
                        }
                    }
                    invalidate();
                    int newLines = m_lines.size();
                    if (newLines != oldLines) {
                        FCVScrollBar vScrollBar = VScrollBar;
                        if (vScrollBar != null) {
                            vScrollBar.Pos += m_lineHeight * (newLines - oldLines);
                            invalidate();
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        public override void onCopy() {
            String selectionText = SelectionText;
            if (selectionText != null && selectionText.Length > 0) {
                FCHost host = Native.Host;
                host.copy(selectionText);
                base.onCopy();
            }
        }

        /// <summary>
        /// ����
        /// </summary>
        public override void onCut() {
            if (!m_readOnly) {
                onCopy();
                int oldLines = m_lines.size();
                String redotext = Text;
                deleteWord();
                onTextChanged();
                if (m_textChanged) {
                    if (redotext != null) {
                        m_undoStack.Push(redotext);
                    }
                }
                invalidate();
                int newLines = m_lines.size();
                if (newLines != oldLines) {
                    FCVScrollBar vScrollBar = VScrollBar;
                    if (vScrollBar != null) {
                        vScrollBar.Pos += m_lineHeight * (newLines - oldLines);
                        invalidate();
                    }
                }
                base.onCut();
            }
        }

        /// <summary>
        /// ��ȡ���㷽��
        /// </summary>
        public override void onGotFocus() {
            base.onGotFocus();
            m_showCursor = true;
            invalidate();
            startTimer(m_timerID, TICK);
        }

        /// <summary>
        /// ���̷���
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyDown(char key) {
            m_isKeyDown = true;
            FCHost host = Native.Host;
            if (host.isKeyPress(0x11)) {
                base.onKeyDown(key);
                //ȫѡ
                if (key == 65) {
                    selectAll();
                }
                //����
                else if (key == 89) {
                    redo();
                }
                //����
                else if (key == 90) {
                    undo();
                }
            }
            else {
                if (key >= 35 && key <= 40) {
                    if (key == 38 || key == 40) {
                        callKeyEvents(FCEventID.KEYDOWN, key);
                        if (m_lines.size() > 1) {
                            int offset = 0;
                            //��������ƶ�
                            if (key == 38) {
                                cursorUp();
                                if (!isLineVisible(m_stopMovingIndex, 0.6)) {
                                    offset = -m_lineHeight;
                                }
                            }
                            //��������ƶ�
                            else if (key == 40) {
                                cursorDown();
                                if (!isLineVisible(m_stopMovingIndex, 0.6)) {
                                    offset = m_lineHeight;
                                }
                            }
                            FCVScrollBar vScrollBar = VScrollBar;
                            if (vScrollBar != null && vScrollBar.Visible) {
                                vScrollBar.Pos += offset;
                                vScrollBar.update();
                            }
                        }
                    }
                    else {
                        base.onKeyDown(key);
                        //����ƶ������Ҷ�
                        if (key == 35) {
                            cursorEnd();
                        }
                        //����ƶ��������
                        else if (key == 36) {
                            cursorHome();
                        }
                        //��������ƶ�
                        else if (key == 37) {
                            cursorLeft();
                        }
                        //��������ƶ�
                        else if (key == 39) {
                            cursorRight();
                        }
                    }
                }
                else {
                    base.onKeyDown(key);
                    //ȡ������
                    if (key == 27) {
                        Focused = false;
                    }
                    //ɾ��
                    else if (key == 8 || key == 46) {
                        if (!m_readOnly) {
                            int oldLines = m_lines.size();
                            String redotext = Text;
                            deleteWord();
                            onTextChanged();
                            if (m_textChanged) {
                                if (redotext != null) {
                                    m_undoStack.Push(redotext);
                                }
                            }
                            invalidate();
                            int newLines = m_lines.size();
                            if (newLines != oldLines) {
                                FCVScrollBar vScrollBar = VScrollBar;
                                if (vScrollBar != null) {
                                    vScrollBar.Pos += m_lineHeight * (newLines - oldLines);
                                    invalidate();
                                }
                            }
                        }
                    }
                }
            }
            invalidate();
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyUp(char key) {
            base.onKeyUp(key);
            FCHost host = Native.Host;
            if (!host.isKeyPress(0x10) && !m_isTouchDown) {
                m_startMovingIndex = m_selectionStart;
                m_stopMovingIndex = m_selectionStart;
            }
            m_isKeyDown = false;
        }

        /// <summary>
        /// ��ʧ���㷽��
        /// </summary>
        public override void onLostFocus() {
            base.onLostFocus();
            stopTimer(m_timerID);
            m_isKeyDown = false;
            m_showCursor = false;
            m_selectionLength = 0;
            invalidate();
        }

        /// <summary>
        /// �������·���
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchDown(FCTouchInfo touchInfo) {
            base.onTouchDown(touchInfo);
            if (touchInfo.m_firstTouch) {
                FCPoint mp = touchInfo.m_firstPoint;
                //����
                if (touchInfo.m_clicks == 1) {
                    int sIndex = -1;
                    int linesCount = m_lines.size();
                    m_selectionLength = 0;
                    m_startMovingIndex = -1;
                    m_stopMovingIndex = -1;
                    if (linesCount > 0) {
                        FCHScrollBar hScrollBar = HScrollBar;
                        FCVScrollBar vScrollBar = VScrollBar;
                        int scrollH = (hScrollBar != null && hScrollBar.Visible) ? hScrollBar.Pos : 0;
                        int scrollV = (vScrollBar != null && vScrollBar.Visible) ? vScrollBar.Pos : 0;
                        scrollH += m_offsetX;
                        int x = mp.x + scrollH, y = mp.y + scrollV;
                        FCRectF lastRange = new FCRectF();
                        int rangeSize = m_ranges.size();
                        if (rangeSize > 0) {
                            lastRange = m_ranges[rangeSize - 1];
                        }
                        for (int i = 0; i < linesCount; i++) {
                            FCWordLine line = m_lines[i];
                            for (int j = line.m_start; j <= line.m_end; j++) {
                                FCRectF rect = m_ranges[j];
                                if (i == linesCount - 1) {
                                    rect.bottom += 3;
                                }
                                if (y >= rect.top && y <= rect.bottom) {
                                    float sub = (rect.right - rect.left) / 2;
                                    if ((x >= rect.left - sub && x <= rect.right - sub)
                                        || (j == line.m_start && x <= rect.left + sub)
                                        || (j == line.m_end && x >= rect.right - sub)) {
                                        if (j == line.m_end && x >= rect.right - sub) {
                                            sIndex = j + 1;
                                        }
                                        else {
                                            sIndex = j;
                                        }
                                        break;
                                    }
                                }
                            }
                            if (sIndex != -1) {
                                break;
                            }
                        }
                        if (sIndex == -1) {
                            if ((y >= lastRange.top && y <= lastRange.bottom && x > lastRange.right) || (y >= lastRange.bottom)) {
                                sIndex = rangeSize;
                            }
                        }
                    }
                    if (sIndex != -1) {
                        m_selectionStart = sIndex;
                    }
                    else {
                        m_selectionStart = 0;
                    }
                    m_startMovingIndex = m_selectionStart;
                    m_stopMovingIndex = m_selectionStart;
                }
                //˫��
                else if (touchInfo.m_clicks == 2) {
                    if (!m_multiline) {
                        selectAll();
                    }
                }
            }
            m_isTouchDown = true;
            m_showCursor = true;
            startTimer(m_timerID, TICK);
            invalidate();
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchMove(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
            if (m_isTouchDown) {
                int linesCount = m_lines.size();
                if (linesCount > 0) {
                    int eIndex = -1;
                    FCHScrollBar hScrollBar = HScrollBar;
                    FCVScrollBar vScrollBar = VScrollBar;
                    int scrollH = (hScrollBar != null && hScrollBar.Visible) ? hScrollBar.Pos : 0;
                    int scrollV = (vScrollBar != null && vScrollBar.Visible) ? vScrollBar.Pos : 0;
                    scrollH += m_offsetX;
                    FCPoint point = touchInfo.m_firstPoint;
                    if (point.x < 0) {
                        point.x = 0;
                    }
                    if (point.y < 0) {
                        point.y = 0;
                    }
                    int x = point.x + scrollH, y = point.y + scrollV;
                    FCRectF lastRange = new FCRectF();
                    int rangeSize = m_ranges.size();
                    if (rangeSize > 0) {
                        lastRange = m_ranges[rangeSize - 1];
                    }
                    for (int i = 0; i < linesCount; i++) {
                        FCWordLine line = m_lines[i];
                        for (int j = line.m_start; j <= line.m_end; j++) {
                            FCRectF rect = m_ranges[j];
                            if (i == linesCount - 1) {
                                rect.bottom += 3;
                            }
                            if (eIndex == -1) {
                                if (y >= rect.top && y <= rect.bottom) {
                                    float sub = (rect.right - rect.left) / 2;
                                    if ((x >= rect.left - sub && x <= rect.right - sub)
                                        || (j == line.m_start && x <= rect.left + sub)
                                        || (j == line.m_end && x >= rect.right - sub)) {
                                        if (j == line.m_end && x >= rect.right - sub) {
                                            eIndex = j + 1;
                                        }
                                        else {
                                            eIndex = j;
                                        }
                                    }
                                }
                            }
                        }
                        if (eIndex != -1) {
                            break;
                        }
                    }
                    if (eIndex != -1) {
                        m_stopMovingIndex = eIndex;
                    }
                    if (m_startMovingIndex == m_stopMovingIndex) {
                        m_selectionStart = m_startMovingIndex;
                        m_selectionLength = 0;
                    }
                    else {
                        m_selectionStart = m_startMovingIndex < m_stopMovingIndex ? m_startMovingIndex : m_stopMovingIndex;
                        m_selectionLength = Math.Abs(m_startMovingIndex - m_stopMovingIndex);
                    }
                    invalidate();
                }
            }
        }

        /// <summary>
        /// ����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchUp(FCTouchInfo touchInfo) {
            m_isTouchDown = false;
            base.onTouchUp(touchInfo);
        }

        /// <summary>
        /// �ػ�ǰ������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintForeground(FCPaint paint, FCRect clipRect) {
            int width = Width, height = Height;
            if (width > 0 && height > 0) {
                int lineHeight = m_multiline ? m_lineHeight : height;
                FCPadding padding = Padding;
                FCHost host = Native.Host;
                FCRect rect = new FCRect(0, 0, width, height);
                FCFont font = Font;
                FCSizeF tSize = paint.textSizeF(" ", font);
                FCHScrollBar hScrollBar = HScrollBar;
                FCVScrollBar vScrollBar = VScrollBar;
                int vWidth = (vScrollBar != null && vScrollBar.Visible) ? (vScrollBar.Width - padding.left - padding.right) : 0;
                int scrollH = ((hScrollBar != null && hScrollBar.Visible) ? hScrollBar.Pos : 0);
                int scrollV = ((vScrollBar != null && vScrollBar.Visible) ? vScrollBar.Pos : 0);
                float strX = padding.left + 1;
                //��������
                String text = Text;
                if (text == null) {
                    text = "";
                }
                int length = text.Length;
                FCSizeF bSize = paint.textSizeF("0", font);
                if (m_textChanged) {
                    int line = 0, count = 0;
                    //��ȡ��������
                    m_textChanged = !m_textChanged;
                    m_lines.clear();
                    m_ranges.clear();
                    m_wordsSize.clear();
                    for (int i = 0; i < length; i++) {
                        if (i == 0) {
                            count = 0;
                            line++;
                            strX = padding.left + 1;
                            m_lines.add(new FCWordLine(i, i));
                        }
                        char ch = text[i];
                        String dch = ch.ToString();
                        //�Ʊ��
                        if (ch == 9) {
                            int addCount = 4 - count % 4;
                            tSize.cx = bSize.cx * addCount;
                            tSize.cy = bSize.cy;
                            count += addCount;
                        }
                        else {
                            //�����滻
                            if (m_passwordChar != 0) {
                                dch = m_passwordChar.ToString();
                            }
                            tSize = paint.textSizeF(dch, font);
                            if (ch == 10) {
                                tSize.cx = 0;
                            }
                            count++;
                        }
                        //�ж��Ƿ����
                        if (m_multiline) {
                            bool isNextLine = false;
                            if (ch == 13) {
                                isNextLine = true;
                                tSize.cx = 0;
                            }
                            else {
                                //�Ƿ��Զ�����
                                if (m_wordWrap) {
                                    if (strX + tSize.cx > width - vWidth) {
                                        isNextLine = true;
                                    }
                                }
                            }
                            //����
                            if (isNextLine) {
                                count = 0;
                                line++;
                                strX = padding.left + 1;
                                m_lines.add(new FCWordLine(i, i));
                            }
                            else {
                                m_lines[line - 1] = new FCWordLine(m_lines[line - 1].m_start, i);
                            }
                        }
                        else {
                            m_lines[line - 1] = new FCWordLine(m_lines[line - 1].m_start, i);
                        }
                        if (ch > 1000) {
                            tSize.cx += 1;
                        }
                        //��������
                        FCRectF rangeRect = new FCRectF(strX, padding.top + (line - 1) * lineHeight, strX + tSize.cx, padding.top + line * lineHeight);
                        m_ranges.add(rangeRect);
                        m_wordsSize.add(tSize);
                        strX = rangeRect.right;
                    }
                    //��������
                    if (m_rightToLeft) {
                        int lcount = m_lines.size();
                        for (int i = 0; i < lcount; i++) {
                            FCWordLine ln = m_lines[i];
                            float lw = width - vWidth - (m_ranges[ln.m_end].right - m_ranges[ln.m_start].left) - 2;
                            if (lw > 0) {
                                for (int j = ln.m_start; j <= ln.m_end; j++) {
                                    FCRectF rangeRect = m_ranges[j];
                                    rangeRect.left += lw;
                                    rangeRect.right += lw;
                                    m_ranges[j] = rangeRect;
                                }
                            }
                        }
                    }
                    update();
                }
                scrollH += m_offsetX;
                FCRect tempRect = new FCRect();
                int rangesSize = m_ranges.size();
                int offsetX = m_offsetX;
                //�жϵ�ǰ�����Ƿ�ɼ�
                if (!m_multiline) {
                    FCRectF firstRange = new FCRectF();
                    FCRectF lastRange = new FCRectF();
                    if (rangesSize > 0) {
                        firstRange = m_ranges[0];
                        lastRange = m_ranges[rangesSize - 1];
                    }
                    scrollH -= offsetX;
                    //����
                    if (m_textAlign == FCHorizontalAlign.Center) {
                        offsetX = -(int)(width - padding.right - (lastRange.right - firstRange.left)) / 2;
                    }
                    //Զ��
                    else if (m_textAlign == FCHorizontalAlign.Right) {
                        offsetX = -(int)(width - padding.right - (lastRange.right - firstRange.left) - 3);
                    }
                    //����
                    else {
                        //��ʾ�����߽�
                        if (lastRange.right > width - padding.right) {
                            //��ȡ���ǿɼ�������
                            int alwaysVisibleIndex = m_selectionStart + m_selectionLength;
                            if (m_startMovingIndex != -1) {
                                alwaysVisibleIndex = m_startMovingIndex;
                            }
                            if (m_stopMovingIndex != -1) {
                                alwaysVisibleIndex = m_stopMovingIndex;
                            }
                            if (alwaysVisibleIndex > rangesSize - 1) {
                                alwaysVisibleIndex = rangesSize - 1;
                            }
                            if (alwaysVisibleIndex != -1) {
                                FCRectF alwaysVisibleRange = m_ranges[alwaysVisibleIndex];
                                int cw = width - padding.left - padding.right;
                                if (alwaysVisibleRange.left - offsetX > cw - 10) {
                                    offsetX = (int)alwaysVisibleRange.right - cw + 3;
                                    if (offsetX < 0) {
                                        offsetX = 0;
                                    }
                                }
                                else if (alwaysVisibleRange.left - offsetX < 10) {
                                    offsetX -= (int)bSize.cx * 4;
                                    if (offsetX < 0) {
                                        offsetX = 0;
                                    }
                                }
                                if (offsetX > lastRange.right - cw) {
                                    offsetX = (int)lastRange.right - cw + 3;
                                }
                            }
                        }
                        //��ʾδ�����߽�
                        else {
                            if (m_textAlign == FCHorizontalAlign.Right) {
                                offsetX = -(int)(width - padding.right - (lastRange.right - firstRange.left) - 3);
                            }
                            else {
                                offsetX = 0;
                            }
                        }
                    }
                    m_offsetX = offsetX;
                    scrollH += m_offsetX;
                }
                int lineCount = m_lines.size();
                //���ƾ��κ��ַ�
                ArrayList<FCRectF> selectedRanges = new ArrayList<FCRectF>();
                ArrayList<FCRect> selectedWordsRanges = new ArrayList<FCRect>();
                ArrayList<char> selectedWords = new ArrayList<char>();
                for (int i = 0; i < lineCount; i++) {
                    FCWordLine line = m_lines[i];
                    for (int j = line.m_start; j <= line.m_end; j++) {
                        char ch = text[j];
                        if (ch != 9) {
                            //�����滻
                            if (m_passwordChar > 0) {
                                ch = m_passwordChar;
                            }
                        }
                        //��ȡ��������
                        FCRectF rangeRect = m_ranges[j];
                        rangeRect.left -= scrollH;
                        rangeRect.top -= scrollV;
                        rangeRect.right -= scrollH;
                        rangeRect.bottom -= scrollV;
                        FCRect rRect = new FCRect(rangeRect.left, rangeRect.top + (lineHeight - m_wordsSize[j].cy) / 2,
                            rangeRect.right, rangeRect.top + (lineHeight + m_wordsSize[j].cy) / 2);
                        if (rRect.right == rRect.left) {
                            rRect.right = rRect.left + 1;
                        }
                        //��������
                        if (host.getIntersectRect(ref tempRect, ref rRect, ref rect) > 0) {
                            if (m_selectionLength > 0) {
                                if (j >= m_selectionStart && j < m_selectionStart + m_selectionLength) {
                                    selectedWordsRanges.add(rRect);
                                    selectedRanges.add(rangeRect);
                                    selectedWords.add(ch);
                                    continue;
                                }
                            }
                            paint.drawText(ch.ToString(), getPaintingTextColor(), font, rRect);
                        }
                    }
                }
                //����ѡ������
                int selectedRangesSize = selectedRanges.size();
                if (selectedRangesSize > 0) {
                    int sIndex = 0;
                    float right = 0;
                    for (int i = 0; i < selectedRangesSize; i++) {
                        FCRectF rRect = selectedRanges[i];
                        FCRectF sRect = selectedRanges[sIndex];
                        bool newLine = rRect.top != sRect.top;
                        if (newLine || i == selectedRangesSize - 1) {
                            int eIndex = (i == selectedRangesSize - 1) ? i : i - 1;
                            FCRectF eRect = selectedRanges[eIndex];
                            FCRect unionRect = new FCRect(sRect.left, sRect.top, eRect.right + 1, sRect.bottom + 1);
                            if (newLine) {
                                unionRect.right = (int)right;
                            }
                            paint.fillRect(m_selectionBackColor, unionRect);
                            for (int j = sIndex; j <= eIndex; j++) {
                                paint.drawText(selectedWords[j].ToString(), m_selectionTextColor, font, selectedWordsRanges[j]);
                            }
                            sIndex = i;
                        }
                        right = rRect.right;
                    }
                    selectedRanges.clear();
                    selectedWords.clear();
                    selectedWordsRanges.clear();
                }
                //���ƹ��
                if (Focused && !m_readOnly && m_selectionLength == 0 && (m_isKeyDown || m_showCursor)) {
                    int index = m_selectionStart;
                    if (index < 0) {
                        index = 0;
                    }
                    if (index > length) {
                        index = length;
                    }
                    //��ȡ����λ��
                    int cursorX = offsetX;
                    int cursorY = 0;
                    if (length > 0) {
                        if (index == 0) {
                            if (rangesSize > 0) {
                                cursorX = (int)m_ranges[0].left;
                                cursorY = (int)m_ranges[0].top;
                            }
                        }
                        else {
                            cursorX = (int)Math.Ceiling(m_ranges[index - 1].right) + 2;
                            cursorY = (int)Math.Ceiling(m_ranges[index - 1].top);
                        }
                        cursorY += lineHeight / 2 - (int)tSize.cy / 2;
                    }
                    else {
                        cursorY = lineHeight / 2 - (int)tSize.cy / 2;
                    }
                    //������˸���
                    if (m_isKeyDown || m_showCursor) {
                        FCRect cRect = new FCRect(cursorX - scrollH - 1, cursorY - scrollV, cursorX - scrollH + 1, cursorY + tSize.cy - scrollV);
                        paint.fillRect(TextColor, cRect);
                    }
                }
                else {
                    if (!Focused && text.Length == 0) {
                        if (m_tempText != null && m_tempText.Length > 0) {
                            FCSize pSize = paint.textSize(m_tempText, font);
                            FCRect pRect = new FCRect();
                            pRect.left = padding.left;
                            pRect.top = (lineHeight - pSize.cy) / 2;
                            pRect.right = pRect.left + pSize.cx;
                            pRect.bottom = pRect.top + pSize.cy;
                            paint.drawText(m_tempText, m_tempTextColor, font, pRect);
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ճ������
        /// </summary>
        public override void onPaste() {
            if (!m_readOnly) {
                FCHost host = Native.Host;
                String insert = host.paste();
                if (insert != null && insert.Length > 0) {
                    int oldLines = m_lines.size();
                    String redotext = Text;
                    insertWord(insert);
                    onTextChanged();
                    if (m_textChanged) {
                        if (redotext != null) {
                            m_undoStack.Push(redotext);
                        }
                    }
                    invalidate();
                    int newLines = m_lines.size();
                    if (newLines != oldLines) {
                        FCVScrollBar vScrollBar = VScrollBar;
                        if (vScrollBar != null) {
                            vScrollBar.Pos += m_lineHeight * (newLines - oldLines);
                            invalidate();
                        }
                    }
                    update();
                    base.onPaste();
                }
            }
        }

        /// <summary>
        /// ��ʹ��TAB�л�����
        /// </summary>
        public override void onTabStop() {
            base.onTabStop();
            if (!m_multiline) {
                if (Text != null) {
                    int textSize = Text.Length;
                    if (textSize > 0) {
                        m_selectionStart = 0;
                        m_selectionLength = textSize;
                        onTimer(m_timerID);
                    }
                }
            }
        }

        /// <summary>
        /// ���ֳߴ�ı��¼�
        /// </summary>
        public override void onSizeChanged() {
            base.onSizeChanged();
            if (m_wordWrap) {
                m_textChanged = true;
                invalidate();
            }
        }

        /// <summary>
        /// ���ָı䷽��
        /// </summary>
        public override void onTextChanged() {
            m_textChanged = true;
            base.onTextChanged();
        }

        /// <summary>
        /// ���ص�����
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID) {
            base.onTimer(timerID);
            if (m_timerID == timerID) {
                if (Visible && Focused && !m_textChanged) {
                    m_showCursor = !m_showCursor;
                    invalidate();
                }
            }
        }

        /// <summary>
        /// �ظ�
        /// </summary>
        /// <returns>�ظ�����</returns>
        public void redo() {
            if (canRedo()) {
                m_undoStack.Push(Text);
                Text = m_redoStack.Pop();
            }
        }

        /// <summary>
        /// ȫѡ
        /// </summary>
        public void selectAll() {
            m_selectionStart = 0;
            if (Text != null) {
                m_selectionLength = Text.Length;
            }
            else {
                m_selectionLength = 0;
            }
        }

        /// <summary>
        /// �����ƶ�����
        /// </summary>
        /// <param name="sIndex">��ʼ����</param>
        /// <param name="eIndex">��������</param>
        private void setMovingIndex(int sIndex, int eIndex) {
            int textSize = Text.Length;
            if (textSize > 0) {
                if (sIndex < 0) {
                    sIndex = 0;
                }
                if (sIndex > textSize) {
                    sIndex = textSize;
                }
                if (eIndex < 0) {
                    eIndex = 0;
                }
                if (eIndex > textSize) {
                    eIndex = textSize;
                }
                m_startMovingIndex = sIndex;
                m_stopMovingIndex = eIndex;
                m_selectionStart = Math.Min(m_startMovingIndex, m_stopMovingIndex);
                m_selectionLength = Math.Abs(m_startMovingIndex - m_stopMovingIndex);
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "lineheight") {
                LineHeight = FCStr.convertStrToInt(value);
            }
            else if (name == "multiline") {
                Multiline = FCStr.convertStrToBool(value);
            }
            else if (name == "passwordchar") {
                PasswordChar = Convert.ToChar(value);
            }
            else if (name == "readonly") {
                ReadOnly = FCStr.convertStrToBool(value);
            }
            else if (name == "righttoleft") {
                RightToLeft = FCStr.convertStrToBool(value);
            }
            else if (name == "selectionbackcolor") {
                SelectionBackColor = FCStr.convertStrToColor(value);
            }
            else if (name == "selectiontextcolor") {
                SelectionTextColor = FCStr.convertStrToColor(value);
            }
            else if (name == "temptext") {
                TempText = value;
            }
            else if (name == "temptextcolor") {
                TempTextColor = FCStr.convertStrToColor(value);
            }
            else if (name == "textalign") {
                TextAlign = FCStr.convertStrToHorizontalAlign(value);
            }
            else if (name == "wordwrap") {
                WordWrap = FCStr.convertStrToBool(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ����
        /// </summary>
        /// <returns>��������</returns>
        public void undo() {
            if (canUndo()) {
                if (Text != null) {
                    m_redoStack.Push(Text);
                }
                Text = m_undoStack.Pop();
            }
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public override void update() {
            FCNative native = Native;
            if (native != null) {
                FCVScrollBar vScrollBar = VScrollBar;
                if (vScrollBar != null) {
                    vScrollBar.LineSize = m_lineHeight;
                }
            }
            base.update();
        }
    }
}
