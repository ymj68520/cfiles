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
using System.Text;
using System.Windows.Forms;

namespace FaceCat {
    /// <summary>
    /// ��ֵ��ʾ�ؼ�
    /// </summary>
    public class FCSpin : FCTextBox {
        /// <summary>
        /// ������ֵ��ʾ�ؼ�
        /// </summary>
        public FCSpin() {
            m_downButtoTouchDownEvent = new FCTouchEvent(DownButtonTouchDown);
            m_downButtoTouchUpEvent = new FCTouchEvent(DownButtonTouchUp);
            m_upButtonTouchDownEvent = new FCTouchEvent(upButtonTouchDown);
            m_upButtonTouchUpEvent = new FCTouchEvent(upButtonTouchUp);
        }

        /// <summary>
        /// ���°�ť�Ĵ������º���
        /// </summary>
        private FCTouchEvent m_downButtoTouchDownEvent;

        /// <summary>
        /// ���°�ť�Ĵ���̧����
        /// </summary>
        private FCTouchEvent m_downButtoTouchUpEvent;

        /// <summary>
        /// TICKֵ
        /// </summary>
        private int m_tick = 0;

        /// <summary>
        /// ���ID
        /// </summary>
        private int m_timerID = getNewTimerID();

        /// <summary>
        /// ���ϰ�ť�Ĵ������º���
        /// </summary>
        private FCTouchEvent m_upButtonTouchDownEvent;

        /// <summary>
        /// ���ϰ�ť�Ĵ���̧����
        /// </summary>
        private FCTouchEvent m_upButtonTouchUpEvent;

        protected bool m_autoFormat = true;

        /// <summary>
        /// ��ȡ�������Ƿ��Զ���ʽ��
        /// </summary>
        public virtual bool AutoFormat {
            get { return m_autoFormat; }
            set { m_autoFormat = value; }
        }

        protected int m_digit = 0;

        /// <summary>
        /// ��ȡ�����ñ���С����λ��
        /// </summary>
        public virtual int Digit {
            get { return m_digit; }
            set {
                m_digit = value;
                if (m_autoFormat) {
                    if (m_text == "") {
                        m_text = "0";
                    }
                    double text = FCStr.convertStrToDouble(m_text);
                    Text = getValueByDigit(Value, m_digit);
                }
            }
        }

        protected FCButton m_downButton;

        /// <summary>
        /// ��ȡ���°�ť
        /// </summary>
        public virtual FCButton DownButton {
            get { return m_downButton; }
        }

        protected bool m_isAdding;

        /// <summary>
        /// ��ȡ�������Ƿ���������
        /// </summary>
        public virtual bool IsAdding {
            get { return m_isAdding; }
            set {
                m_isAdding = value;
                if (m_isAdding) {
                    m_tick = 0;
                    startTimer(m_timerID, 10);
                }
                else {
                    stopTimer(m_timerID);
                }
            }
        }

        protected bool m_isReducing;

        /// <summary>
        /// ��ȡ�������Ƿ����ڼ���
        /// </summary>
        public virtual bool IsReducing {
            get { return m_isReducing; }
            set {
                m_isReducing = value;
                if (m_isReducing) {
                    m_tick = 0;
                    startTimer(m_timerID, 10);
                }
                else {
                    stopTimer(m_timerID);
                }
            }
        }

        protected double m_maximum = 100;

        /// <summary>
        /// ��ȡ���������ֵ
        /// </summary>
        public virtual double Maximum {
            get { return m_maximum; }
            set {
                m_maximum = value;
                if (Value > value) {
                    Value = value;
                }
            }
        }

        protected double m_minimum = 0;

        /// <summary>
        /// ��ȡ��������Сֵ
        /// </summary>
        public virtual double Minimum {
            get { return m_minimum; }
            set {
                m_minimum = value;
                if (Value < value) {
                    Value = value;
                }
            }
        }

        protected bool m_showThousands;

        /// <summary>
        /// ��ȡ�������Ƿ���ʾǧ��λ
        /// </summary>
        public bool ShowThousands {
            get { return m_showThousands; }
            set { m_showThousands = value; }
        }

        protected double m_step = 1;

        /// <summary>
        /// ��ȡ��������ֵ��������
        /// </summary>
        public virtual double Step {
            get { return m_step; }
            set { m_step = value; }
        }

        /// <summary>
        /// ��ȡ�������ı�
        /// </summary>
        public override String Text {
            get { return base.Text; }
            set {
                base.Text = FormatNum(value.Replace(",", ""));
            }
        }

        protected FCButton m_upButton;

        /// <summary>
        /// ��ȡ���ϰ�ť
        /// </summary>
        public virtual FCButton UpButton {
            get { return m_upButton; }
            set { m_upButton = value; }
        }

        /// <summary>
        /// ��ȡ�����õ�����ֵ
        /// </summary>
        public virtual double Value {
            get {
                return FCStr.convertStrToDouble(Text.Replace(",", ""));
            }
            set {
                if (value > m_maximum) {
                    value = m_maximum;
                }
                if (value < m_minimum) {
                    value = m_minimum;
                }
                double oldValue = Value;
                Text = FormatNum(getValueByDigit(value, m_digit));
                onValueChanged();
            }
        }

        /// <summary>
        /// ����ָ�����ȵ���ֵ
        /// </summary>
        public void Add() {
            Value += m_step;
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                if (m_downButton != null) {
                    if (m_downButtoTouchDownEvent != null) {
                        m_downButton.removeEvent(m_downButtoTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_downButtoTouchDownEvent = null;
                    }
                    if (m_downButtoTouchUpEvent != null) {
                        m_downButton.removeEvent(m_downButtoTouchUpEvent, FCEventID.TOUCHUP);
                        m_downButtoTouchUpEvent = null;
                    }
                }
                if (m_upButton != null) {
                    if (m_upButtonTouchDownEvent != null) {
                        m_upButton.removeEvent(m_upButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_upButtonTouchDownEvent = null;
                    }
                    if (m_upButtonTouchUpEvent != null) {
                        m_upButton.removeEvent(m_upButtonTouchUpEvent, FCEventID.TOUCHUP);
                        m_upButtonTouchUpEvent = null;
                    }
                }
            }
            base.delete();
        }

        /// <summary>
        /// ���°�ť�Ĵ��������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void DownButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            reduce();
            IsReducing = true;
            invalidate();
        }

        /// <summary>
        /// ���°�ť�Ĵ���̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void DownButtonTouchUp(object sender, FCTouchInfo touchInfo) {
            IsReducing = false;
        }

        /// <summary>
        /// ���ı�ת��Ϊǧ��λ��ʾ
        /// </summary>
        /// <param name="inputText">��������</param>
        /// <returns>ǧ��λ����</returns>
        public String FormatNum(string inputText) {
            if (m_showThousands) {
                inputText = inputText.Replace(",", "");
                string theNewText = "";
                int pos = 0;
                bool hasMinusSign = false;
                if (inputText.IndexOf("-") == 0) {
                    hasMinusSign = true;
                    inputText = inputText.Substring(1);
                }
                string textAfterDot = string.Empty;
                bool hasDot = false;
                if (inputText.Contains(".")) {
                    hasDot = true;
                    textAfterDot = inputText.Substring(inputText.IndexOf(".") + 1);
                    inputText = inputText.Remove(inputText.IndexOf("."));
                }
                pos = inputText.Length;
                while (pos >= 0) {
                    int logicPos = inputText.Length - pos;
                    if ((logicPos % 3) == 0 && logicPos > 1) {
                        if (theNewText == "") {
                            theNewText = inputText.Substring(pos, 3);
                        }
                        else {
                            theNewText = inputText.Substring(pos, 3) + "," + theNewText;
                        }
                    }
                    else {
                        if (pos == 0) {
                            if (theNewText == "") {
                                theNewText = inputText.Substring(pos, (logicPos % 3));
                            }
                            else {
                                theNewText = inputText.Substring(pos, (logicPos % 3)) + "," + theNewText;
                            }

                        }
                    }
                    --pos;
                }
                if (hasMinusSign) {
                    theNewText = "-" + theNewText;
                }
                if (hasDot) {
                    theNewText = theNewText + "." + textAfterDot;
                }
                if (theNewText.IndexOf(".") == 0) {
                    theNewText = "0" + theNewText;
                }
                if (theNewText.IndexOf("-.") == 0) {
                    theNewText = theNewText.Insert(1, "0");
                }
                return theNewText;
            }
            else {
                return inputText;
            }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "Spin";
        }

        /// <summary>
        /// ��ȡ�¼������б�
        /// </summary>
        /// <returns>�����б�</returns>
        public override ArrayList<String> getEventNames() {
            ArrayList<String> eventNames = base.getEventNames();
            eventNames.AddRange(new String[] { "ValueChanged" });
            return eventNames;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "autoformat") {
                type = "int";
                value = FCStr.convertBoolToStr(AutoFormat);
            }
            else if (name == "digit") {
                type = "int";
                value = FCStr.convertDoubleToStr(Digit);
            }
            else if (name == "maximum") {
                type = "double";
                value = FCStr.convertDoubleToStr(Maximum);
            }
            else if (name == "minimum") {
                type = "double";
                value = FCStr.convertDoubleToStr(Minimum);
            }
            else if (name == "showthousands") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowThousands);
            }
            else if (name == "step") {
                type = "double";
                value = FCStr.convertDoubleToStr(Step);
            }
            else if (name == "value") {
                type = "double";
                value = FCStr.convertDoubleToStr(Value);
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
            propertyNames.AddRange(new String[] { "AutoFormat", "Digit", "Maximum", "Minimum", "ShowThousands", "Step" });
            return propertyNames;
        }

        /// <summary>
        /// ���ݱ���С����λ�ý�double��ת��ΪString��
        /// </summary>
        /// <param name="value">ֵ</param>
        /// <param name="digit">����С����</param>
        /// <returns>��ֵ�ַ�</returns>
        private String getValueByDigit(double value, int digit) {
            if (digit > 0) {
                StringBuilder format = new StringBuilder();
                format.Append("0");
                format.Append(".");
                for (int i = 0; i < digit; i++) {
                    format.Append("0");
                }
                return value.ToString(format.ToString());
            }
            else {
                return value.ToString("0");
            }
        }

        /// <summary>
        /// �������ַ���
        /// </summary>
        /// <param name="ch">�ַ�</param>
        public override void onChar(char ch) {
            if (m_autoFormat) {
                callEvents(FCEventID.CHAR);
                FCHost host = Native.Host;
                if (!host.isKeyPress(0x11)) {
                    bool flag = false;
                    if (SelectionLength > 0) {
                        flag = true;
                    }
                    char inputCharacter = ch;
                    int curPos = SelectionStart;
                    bool cursorIsLast = false;
                    if (curPos == m_text.Length) {
                        cursorIsLast = true;
                    }
                    int exCount = 0;
                    if (inputCharacter == 8) {
                        if (SelectionLength > 0) {
                            if (SelectionStart > 0 && m_text[SelectionStart - 1] == ',') {
                                SelectionStart = SelectionStart - 1;
                                SelectionLength = SelectionLength + 1;
                                curPos = SelectionStart;
                            }
                            Text = FormatNum(Text);
                            SelectionStart = curPos;
                        }
                        else {
                            if (SelectionStart > 0 && m_text[SelectionStart - 1] == ',') {
                                SelectionStart = SelectionStart - 1;
                                curPos = SelectionStart;
                            }

                            if (SelectionStart > 0 && m_text[SelectionStart - 1] == '.') {
                                string sub = m_text.Substring(SelectionStart);
                                exCount = sub.Length / 3;
                            }
                            int length = m_text.Length - curPos;
                            string oriText = Text;
                            int diff = 0;
                            if (oriText.StartsWith(",")) {
                                oriText = oriText.Substring(1);
                                diff = 1;
                            }
                            m_text = FormatNum(Text);
                            if (Text.Length + diff - exCount - length > 0) {
                                SelectionStart = m_text.Length + diff - exCount - length;
                            }
                        }
                        invalidate();
                        return;
                    }
                    if (inputCharacter == 46) {
                        if (m_text.Contains(".")) {
                            if (m_text.IndexOf(".") != m_text.Length - 1) {
                                SelectionStart = m_text.IndexOf(".") + 1;
                            }
                            invalidate();
                            return;
                        }
                    }
                    int backLength = m_text.Length - curPos;
                    if (inputCharacter == 46) {
                        string sub = m_text.Substring(SelectionStart);
                        exCount = sub.Length - sub.Replace(",", "").Length;
                        insertWord(ch.ToString());
                        onTextChanged();
                        onValueChanged();
                        invalidate();
                        return;
                    }
                    bool removeCharFlag = false;
                    if (m_selectionLength > 0 && m_selectionLength == m_text.Length) {
                        m_text = "";
                        SelectionLength = 0;
                    }
                    else if (m_text.StartsWith("0.")) {
                        if (SelectionStart == 0) {
                            removeCharFlag = true;
                            m_text = m_text.Substring(1);
                            SelectionLength = 0;
                        }
                    }
                    String oldText = Text;
                    int index = m_text.IndexOf(".");
                    if (m_selectionLength == 0 && index < SelectionStart) {
                        m_selectionLength = 1;
                    }
                    insertWord(ch.ToString());
                    int selectionStart = SelectionStart;
                    setRegion();
                    m_selectionLength = 0;
                    String newText = Text;
                    if (newText.Length > 0 && selectionStart > newText.Length) {
                        SelectionStart = newText.Length;
                    }
                    if (((m_text.IndexOf(".") != -1) && (m_text.IndexOf(".") < selectionStart)) || flag) {
                        SelectionStart = selectionStart;
                    }
                    else {
                        if (cursorIsLast == true) {
                            SelectionStart = m_text.Length + 1;
                        }
                        else {
                            if (m_text.Length + exCount - backLength >= 0) {
                                SelectionStart = m_text.Length + exCount - backLength;
                            }
                        }
                    }
                    if (removeCharFlag) {
                        SelectionStart = SelectionStart + 1;
                    }
                    m_showCursor = true;
                    onTextChanged();
                    onValueChanged();
                    invalidate();
                }
            }
            else {
                base.onChar(ch);
            }
        }

        /// <summary>
        /// ���̰��·���
        /// </summary>
        /// <param name="key">����</param>
        public override void onKeyDown(char key) {
            if (m_autoFormat) {
                if (key == 8 || key == 46) {
                    String text = Text;
                    if (text.Length > 0) {
                        int curPos = SelectionStart;
                        if (text.IndexOf(".") != -1 && text.IndexOf(".") == curPos - 1 && SelectionLength <= 1) {
                            SelectionStart = curPos - 1;
                            curPos = SelectionStart;
                        }
                        if (SelectionStart == 0) {
                            int len = SelectionLength + 1;
                            if (len > text.Length) {
                                len = text.Length;
                            }
                            m_text = text.Substring(len);
                        }
                        else {
                            deleteWord();
                        }
                        bool deleteAll = m_text.Length == 0;
                        setRegion();
                        if (curPos > 0) {
                            SelectionStart = curPos - 1;
                        }
                        else {
                            SelectionStart = curPos;
                        }
                        if (deleteAll) {
                            SelectionStart = m_text.Length;
                            SelectionLength = 0;
                        }
                        else if (curPos == 0 && m_text.IndexOf("0.") == 0) {
                            SelectionStart = m_text.Length;
                        }
                        m_showCursor = true;
                        onTextChanged();
                        onValueChanged();
                        invalidate();
                        return;
                    }
                }
            }
            base.onKeyDown(key);
            FCHost host = Native.Host;
            if (!host.isKeyPress(0x10) && !host.isKeyPress(0x11) && !host.isKeyPress(0x12)) {
                if (key == 38) {
                    Add();
                    invalidate();
                }
                else if (key == 40) {
                    reduce();
                    invalidate();
                }
            }
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            base.onLoad();
            FCHost host = Native.Host;
            if (m_downButton == null) {
                m_downButton = host.createInternalControl(this, "downbutton") as FCButton;
                m_downButton.addEvent(m_downButtoTouchDownEvent, FCEventID.TOUCHDOWN);
                m_downButton.addEvent(m_downButtoTouchUpEvent, FCEventID.TOUCHUP);
                addControl(m_downButton);
            }
            if (m_upButton == null) {
                m_upButton = host.createInternalControl(this, "upbutton") as FCButton;
                m_upButton.addEvent(m_upButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                m_upButton.addEvent(m_upButtonTouchUpEvent, FCEventID.TOUCHUP);
                addControl(m_upButton);
            }
            update();
        }

        /// <summary>
        /// ������������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onTouchWheel(FCTouchInfo touchInfo) {
            base.onTouchMove(touchInfo);
            if (touchInfo.m_delta > 0) {
                Add();
            }
            else {
                reduce();
            }
            invalidate();
        }

        /// <summary>
        /// ճ������
        /// </summary>
        public override void onPaste() {
            if (m_autoFormat) {
                callEvents(FCEventID.PASTE);
                FCHost host = Native.Host;
                String insert = host.paste();
                if (insert != null && insert.Length > 0) {
                    insertWord(insert);
                    Text = FormatNum(getValueByDigit(Value, m_digit));
                    onTextChanged();
                    onValueChanged();
                    invalidate();
                }
            }
            else {
                base.onPaste();
            }
        }

        /// <summary>
        /// ����¼�
        /// </summary>
        /// <param name="timerID">���ID</param>
        public override void onTimer(int timerID) {
            base.onTimer(timerID);
            if (timerID == m_timerID) {
                if (m_tick > 20) {
                    if (m_tick > 50 || m_tick % 3 == 1) {
                        if (m_isAdding) {
                            Add();
                            invalidate();
                        }
                        else if (m_isReducing) {
                            reduce();
                            invalidate();
                        }
                    }
                }
                m_tick++;
            }
        }

        /// <summary>
        /// ��ֵ�ı䷽��
        /// </summary>
        public virtual void onValueChanged() {
            callEvents(FCEventID.VALUECHANGED);
        }

        /// <summary>
        /// ����ָ�����ȵ���ֵ
        /// </summary>
        public void reduce() {
            Value -= m_step;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "autoformat") {
                AutoFormat = FCStr.convertStrToBool(value);
            }
            else if (name == "digit") {
                Digit = FCStr.convertStrToInt(value);
            }
            else if (name == "maximum") {
                Maximum = FCStr.convertStrToDouble(value);
            }
            else if (name == "minimum") {
                Minimum = FCStr.convertStrToDouble(value);
            }
            else if (name == "showthousands") {
                ShowThousands = FCStr.convertStrToBool(value);
            }
            else if (name == "step") {
                Step = FCStr.convertStrToDouble(value);
            }
            else if (name == "value") {
                Value = FCStr.convertStrToDouble(value);
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        public void setRegion() {
            string textValue = m_text.Replace(",", "");
            if (textValue == null || textValue == "") {
                textValue = "0";
            }
            if (textValue.IndexOf(".") != -1 && textValue.IndexOf(".") == 0) {
                textValue = "0" + textValue;
            }
            double value = FCStr.convertStrToDouble(textValue);
            if (value > Maximum) {
                value = Maximum;
            }
            if (value < Minimum) {
                value = Minimum;
            }
            Text = FormatNum(getValueByDigit(value, m_digit));
        }

        /// <summary>
        /// ���ϰ�ť�Ĵ��������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void upButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            Add();
            IsAdding = true;
            invalidate();
        }

        /// <summary>
        /// ���ϰ�ť�Ĵ���̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void upButtonTouchUp(object sender, FCTouchInfo touchInfo) {
            IsAdding = false;
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public override void update() {
            base.update();
            int width = Width, height = Height;
            int uBottom = 0;
            if (m_upButton != null) {
                int uWidth = m_upButton.Width;
                FCPoint location = new FCPoint(width - uWidth, 0);
                m_upButton.Location = location;
                FCSize size = new FCSize(uWidth, height / 2);
                m_upButton.Size = size;
                uBottom = m_upButton.Bottom;
                FCPadding oldPadding = Padding;
                FCPadding padding = new FCPadding(oldPadding.left, oldPadding.top, uWidth + 3, oldPadding.bottom);
                Padding = padding;
            }
            if (m_downButton != null) {
                int dWidth = m_downButton.Width;
                FCPoint location = new FCPoint(width - dWidth, uBottom);
                m_downButton.Location = location;
                FCSize size = new FCSize(dWidth, height - uBottom);
                m_downButton.Size = size;
            }
        }
    }
}
