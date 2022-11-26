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

namespace FaceCat {
    /// <summary>
    /// �¼���Ϣ
    /// </summary>
    public class FCEventInfo {
        /// <summary>
        /// ����
        /// </summary>
        private HashMap<int, String> m_functions = new HashMap<int, String>();

        /// <summary>
        /// ����¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <param name="function">����</param>
        public void addEvent(int eventID, String function) {
            m_functions.put(eventID, function);
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <returns>����</returns>
        public String getFunction(int eventID) {
            if (m_functions.containsKey(eventID)) {
                return m_functions.get(eventID);
            }
            return "";
        }

        /// <summary>
        /// �Ƴ��¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        public void removeEvent(int eventID) {
            if (m_functions.containsKey(eventID)) {
                m_functions.remove(eventID);
            }
        }
    }

    /// <summary>
    /// �¼�
    /// </summary>
    public class FCUIEvent {
        /// <summary>
        /// �����¼�
        /// </summary>
        /// <param name="xml">XML����</param>
        public FCUIEvent(FCUIXml xml) {
            m_xml = xml;
        }

        /// <summary>
        /// �¼�����
        /// </summary>
        protected HashMap<FCView, FCEventInfo> m_events = new HashMap<FCView, FCEventInfo>();

        private int m_clicks;

        /// <summary>
        /// ��ȡ�����õ������
        /// </summary>
        public int Clicks {
            get { return m_clicks; }
            set { m_clicks = value; }
        }

        private bool m_isDeleted = false;

        /// <summary>
        /// ��ȡ�Ƿ�����
        /// </summary>
        public bool IsDeleted {
            get { return m_isDeleted; }
        }

        private char m_key;

        /// <summary>
        /// ��ȡ�����ð���
        /// </summary>
        public char Key {
            get { return m_key; }
            set { m_key = value; }
        }

        private FCUIScript m_script;

        /// <summary>
        /// ��ȡ�����ýű�
        /// </summary>
        public FCUIScript Script {
            get { return m_script; }
            set { m_script = value; }
        }

        private String m_sender;

        /// <summary>
        /// ��ȡ�����õ�����
        /// </summary>
        public String Sender {
            get { return m_sender; }
            set { m_sender = value; }
        }

        private FCTouchInfo m_touchInfo;

        /// <summary>
        /// ��ȡ�����ô�������İ���
        /// </summary>
        public FCTouchInfo TouchInfo {
            get { return m_touchInfo; }
            set { m_touchInfo = value; }
        }

        private FCUIXml m_xml;

        /// <summary>
        /// ��ȡ������XML����
        /// </summary>
        public FCUIXml Xml {
            get { return m_xml; }
            set { m_xml = value; }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public virtual void delete() {
            if (!m_isDeleted) {
                m_isDeleted = true;
            }
        }

        /// <summary>
        /// ��ӿؼ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callAdd(object sender) {
            callFunction(sender, FCEventID.ADD);
        }

        /// <summary>
        /// ��ӱ�����ɫ�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callBackColorChanged(object sender) {
            callFunction(sender, FCEventID.BACKCOLORCHANGED);
        }

        /// <summary>
        /// ��ӱ���ͼƬ�ı�ʱ��
        /// </summary>
        /// <param name="sender">������</param>
        public void CallBackImageChanged(object sender) {
            callFunction(sender, FCEventID.BACKIMAGECHANGED);
        }

        /// <summary>
        /// �ַ������¼�
        /// </summary>
        /// <param name="ch">�ַ�</param>
        /// <param name="sender">������</param>
        public void callChar(object sender, char ch) {
            m_key = ch;
            callFunction(sender, FCEventID.CHAR);
        }

        /// <summary>
        /// ѡ�иı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callCheckedChanged(object sender) {
            callFunction(sender, FCEventID.CHECKEDCHANGED);
        }

        /// <summary>
        /// ��������¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callClick(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.CLICK);
        }

        /// <summary>
        /// �����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callCopy(object sender) {
            callFunction(sender, FCEventID.COPY);
        }

        /// <summary>
        /// �����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callCut(object sender) {
            callFunction(sender, FCEventID.CUT);
        }

        /// <summary>
        /// Dock�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callDockChanged(object sender) {
            callFunction(sender, FCEventID.DOCKCHANGED);
        }

        /// <summary>
        /// ˫���¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callDoubleClick(object sender) {
            callFunction(sender, FCEventID.DOUBLECLICK);
        }

        /// <summary>
        /// �϶���ʼ�¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <returns>�Ƿ��϶�</returns>
        public void callDragBegin(object sender) {
            callFunction(sender, FCEventID.DRAGBEGIN);
        }

        /// <summary>
        /// �϶������¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void CallDragEnd(object sender) {
            callFunction(sender, FCEventID.DRAGEND);
        }

        /// <summary>
        /// �����϶��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callDragging(object sender) {
            callFunction(sender, FCEventID.DRAGGING);
        }

        /// <summary>
        /// ���øı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callEnableChanged(object sender) {
            callFunction(sender, FCEventID.ENABLECHANGED);
        }

        /// <summary>
        /// ����ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFontChanged(object sender) {
            callFunction(sender, FCEventID.FONTCHANGED);
        }

        /// <summary>
        /// ���÷���
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="eventID">�¼�ID</param>
        public virtual String callFunction(object sender, int eventID) {
            FCView control = sender as FCView;
            if (m_events.containsKey(control)) {
                FCEventInfo eventInfo = m_events.get(control);
                String function = eventInfo.getFunction(eventID);
                if (function != null && function.Length > 0) {
                    FCUIScript script = m_xml.Script;
                    if (script != null) {
                        m_sender = control.Name;
                        String result = script.callFunction(function);
                        m_sender = "";
                        return result;
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// ��ý����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callGotFocus(object sender) {
            callFunction(sender, FCEventID.GOTFOCUS);
        }

        /// <summary>
        /// ��Ԫ�����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFCGridCellClick(object sender) {
            callFunction(sender, FCEventID.GRIDCELLCLICK);
        }

        /// <summary>
        /// ��Ԫ��༭��ʼ�¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFCGridCellEditBegin(object sender) {
            callFunction(sender, FCEventID.GRIDCELLEDITBEGIN);
        }

        /// <summary>
        /// ��Ԫ��༭�����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFCGridCellEditEnd(object sender) {
            callFunction(sender, FCEventID.GRIDCELLEDITEND);
        }

        /// <summary>
        /// ��Ԫ���������¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFCGridCellTouchDown(object sender) {
            callFunction(sender, FCEventID.GRIDCELLTOUCHDOWN);
        }

        /// <summary>
        /// ��Ԫ�����ƶ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFCGridCellTouchMove(object sender) {
            callFunction(sender, FCEventID.GRIDCELLTOUCHMOVE);
        }

        /// <summary>
        /// ��Ԫ����̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callFCGridCellTouchUp(object sender) {
            callFunction(sender, FCEventID.GRIDCELLTOUCHUP);
        }

        /// <summary>
        /// �ڿؼ��߳��е����¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="args">����</param>
        public void callInvoke(object sender, object args) {
            callFunction(sender, FCEventID.INVOKE);
        }

        /// <summary>
        /// �ؼ������¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callLoad(object sender) {
            callFunction(sender, FCEventID.LOAD);
        }

        /// <summary>
        /// λ�øı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callLocationChanged(object sender) {
            callFunction(sender, FCEventID.LOCATIONCHANGED);
        }

        /// <summary>
        /// ��ʧ�����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callLostFocus(object sender) {
            callFunction(sender, FCEventID.LOSTFOCUS);
        }

        /// <summary>
        /// ���̰����¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="key">����</param>
        public void callKeyDown(object sender, char key) {
            m_key = key;
            callFunction(sender, FCEventID.KEYDOWN);
        }

        /// <summary>
        /// ���̵����¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="key">����</param>
        public void CallKeyUp(object sender, char key) {
            m_key = key;
            callFunction(sender, FCEventID.KEYUP);
        }

        /// <summary>
        /// ��߽�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callMarginChanged(object sender) {
            callFunction(sender, FCEventID.MARGINCHANGED);
        }

        /// <summary>
        /// �˵������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="item">�˵���</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callMenuItemClick(object sender, FCMenuItem item, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.MENUITEMCLICK);
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callTouchDown(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.TOUCHDOWN);
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callTouchEnter(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.TOUCHENTER);
        }

        /// <summary>
        /// �����뿪�¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callTouchLeave(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.TOUCHLEAVE);
        }

        /// <summary>
        /// �����ƶ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callTouchMove(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.TOUCHMOVE);
        }

        /// <summary>
        /// ����̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callTouchUp(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.TOUCHUP);
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        public void callTouchWheel(object sender, FCTouchInfo touchInfo) {
            m_touchInfo = touchInfo;
            callFunction(sender, FCEventID.TOUCHWHEEL);
        }

        /// <summary>
        /// �ڱ߽�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public void callPaddingChanged(object sender, FCPaint paint, FCRect clipRect) {
            callFunction(sender, FCEventID.PADDINGCHANGED);
        }

        /// <summary>
        /// �ػ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public void callPaint(object sender, FCPaint paint, FCRect clipRect) {
            callFunction(sender, FCEventID.TOUCHWHEEL);
        }

        /// <summary>
        /// �ػ�����¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public void callPaintBorder(object sender, FCPaint paint, FCRect clipRect) {
            callFunction(sender, FCEventID.PAINTBORDER);
        }

        /// <summary>
        /// ���ؼ������仯
        /// </summary>
        /// <param name="sender">������</param>
        public void callParentChanged(object sender) {
            callFunction(sender, FCEventID.PARENTCHANGED);
        }

        /// <summary>
        /// �����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callPaste(object sender) {
            callFunction(sender, FCEventID.PASTE);
        }

        /// <summary>
        /// �������仯�¼�
        /// </summary>
        /// <param name="sender"></param>
        public void CallRegionChanged(object sender) {
            callFunction(sender, FCEventID.REGIONCHANGED);
        }

        /// <summary>
        /// �Ƴ��ؼ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callRemove(object sender) {
            callFunction(sender, FCEventID.REMOVE);
        }

        /// <summary>
        /// ѡ�����ڸı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callSelectedTimeChanged(object sender) {
            callFunction(sender, FCEventID.SELECTEDTIMECHANGED);
        }

        /// <summary>
        /// ѡ�������ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callSelectedIndexChanged(object sender) {
            callFunction(sender, FCEventID.SELECTEDINDEXCHANGED);
        }

        /// <summary>
        /// ѡ��ҳ�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void CallSelectedTabPageChanged(object sender) {
            callFunction(sender, FCEventID.SELECTEDTABPAGECHANGED);
        }

        /// <summary>
        /// �����¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callScrolled(object sender) {
            callFunction(sender, FCEventID.SCROLLED);
        }

        /// <summary>
        /// �ߴ�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callSizeChanged(object sender) {
            callFunction(sender, FCEventID.SIZECHANGED);
        }

        /// <summary>
        /// Tab�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callTabIndexChanged(object sender) {
            callFunction(sender, FCEventID.TABINDEXCHANGED);
        }

        /// <summary>
        /// Tabͣ���¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void CallTabStop(object sender) {
            callFunction(sender, FCEventID.TABSTOP);
        }

        /// <summary>
        /// �ı��ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callTextChanged(object sender) {
            callFunction(sender, FCEventID.TEXTCHANGED);
        }

        /// <summary>
        /// ǰ��ɫ�ı��¼�
        /// </summary>
        /// <param name="sender"></param>
        public void callTextColorChanged(object sender) {
            callFunction(sender, FCEventID.TEXTCOLORCHANGED);
        }

        /// <summary>
        /// ���ص��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="timerID">���</param>
        public void callTimer(object sender, int timerID) {
            callFunction(sender, FCEventID.TIMER);
        }

        /// <summary>
        /// ��ֵ�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callValueChanged(object sender) {
            callFunction(sender, FCEventID.VALUECHANGED);
        }

        /// <summary>
        /// �ɼ�״̬�ı��¼�
        /// </summary>
        /// <param name="sender">������</param>
        public void callVisibleChanged(object sender) {
            callFunction(sender, FCEventID.VISIBLECHANGED);
        }

        /// <summary>
        /// �����ѹر��¼�
        /// </summary>
        /// <param name="sender"></param>
        public void callWindowClosed(object sender) {
            callFunction(sender, FCEventID.WINDOWCLOSED);
        }

        /// <summary>
        /// ��ȡ�¼���ID
        /// </summary>
        /// <param name="eventName">�¼�����</param>
        /// <returns>�¼���ID</returns>
        public virtual int getEventID(String eventName) {
            String lowerName = eventName.ToLower();
            if (lowerName == "onadd") return FCEventID.ADD;
            else if (lowerName == "onbackcolorchanged") return FCEventID.BACKCOLORCHANGED;
            else if (lowerName == "onbackimagechanged") return FCEventID.BACKIMAGECHANGED;
            else if (lowerName == "onchar") return FCEventID.CHAR;
            else if (lowerName == "oncheckedchanged") return FCEventID.CHECKEDCHANGED;
            else if (lowerName == "onclick") return FCEventID.CLICK;
            else if (lowerName == "oncopy") return FCEventID.COPY;
            else if (lowerName == "oncut") return FCEventID.CUT;
            else if (lowerName == "ondockchanged") return FCEventID.DOCKCHANGED;
            else if (lowerName == "ondoubleclick") return FCEventID.DOUBLECLICK;
            else if (lowerName == "ondragbegin") return FCEventID.DRAGBEGIN;
            else if (lowerName == "ondragend") return FCEventID.DRAGEND;
            else if (lowerName == "ondragging") return FCEventID.DRAGGING;
            else if (lowerName == "onenablechanged") return FCEventID.ENABLECHANGED;
            else if (lowerName == "onfontchanged") return FCEventID.FONTCHANGED;
            else if (lowerName == "ontextcolorchanged") return FCEventID.TEXTCOLORCHANGED;
            else if (lowerName == "ongotfocus") return FCEventID.GOTFOCUS;
            else if (lowerName == "ongridcellclick") return FCEventID.GRIDCELLCLICK;
            else if (lowerName == "ongridcelleditbegin") return FCEventID.GRIDCELLEDITBEGIN;
            else if (lowerName == "ongridcelleditend") return FCEventID.GRIDCELLEDITEND;
            else if (lowerName == "ongridcelltouchdown") return FCEventID.GRIDCELLTOUCHDOWN;
            else if (lowerName == "ongridcelltouchmove") return FCEventID.GRIDCELLTOUCHMOVE;
            else if (lowerName == "ongridcelltouchup") return FCEventID.GRIDCELLTOUCHUP;
            else if (lowerName == "oninvoke") return FCEventID.INVOKE;
            else if (lowerName == "onkeydown") return FCEventID.KEYDOWN;
            else if (lowerName == "onkeyup") return FCEventID.KEYUP;
            else if (lowerName == "onload") return FCEventID.LOAD;
            else if (lowerName == "onlocationchanged") return FCEventID.LOCATIONCHANGED;
            else if (lowerName == "onlostfocus") return FCEventID.LOSTFOCUS;
            else if (lowerName == "onmarginchanged") return FCEventID.MARGINCHANGED;
            else if (lowerName == "onmenuitemclick") return FCEventID.MENUITEMCLICK;
            else if (lowerName == "ontouchdown") return FCEventID.TOUCHDOWN;
            else if (lowerName == "ontouchenter") return FCEventID.TOUCHENTER;
            else if (lowerName == "ontouchleave") return FCEventID.TOUCHLEAVE;
            else if (lowerName == "ontouchmove") return FCEventID.TOUCHMOVE;
            else if (lowerName == "ontouchup") return FCEventID.TOUCHUP;
            else if (lowerName == "onmousewheel") return FCEventID.TOUCHWHEEL;
            else if (lowerName == "onpaddingchanged") return FCEventID.PADDINGCHANGED;
            else if (lowerName == "onpaint") return FCEventID.PAINT;
            else if (lowerName == "onpaintborder") return FCEventID.PAINTBORDER;
            else if (lowerName == "onparentchanged") return FCEventID.PARENTCHANGED;
            else if (lowerName == "onpaste") return FCEventID.PASTE;
            else if (lowerName == "onregionchanged") return FCEventID.REGIONCHANGED;
            else if (lowerName == "onremove") return FCEventID.REMOVE;
            else if (lowerName == "onselectedtimechanged") return FCEventID.SELECTEDTIMECHANGED;
            else if (lowerName == "onselectedindexchanged") return FCEventID.SELECTEDINDEXCHANGED;
            else if (lowerName == "onselectedtabpagechanged") return FCEventID.SELECTEDTABPAGECHANGED;
            else if (lowerName == "onsizechanged") return FCEventID.SIZECHANGED;
            else if (lowerName == "ontabindexchanged") return FCEventID.TABINDEXCHANGED;
            else if (lowerName == "ontabstop") return FCEventID.TABSTOP;
            else if (lowerName == "ontextchanged") return FCEventID.TEXTCHANGED;
            else if (lowerName == "ontimer") return FCEventID.TIMER;
            else if (lowerName == "onvaluechanged") return FCEventID.VALUECHANGED;
            else if (lowerName == "onvisiblechanged") return FCEventID.VISIBLECHANGED;
            else if (lowerName == "onscrolled") return FCEventID.SCROLLED;
            else if (lowerName == "onwindowclosed") return FCEventID.WINDOWCLOSED;
            return -1;
        }

        /// <summary>
        /// ע���¼�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <param name="eventName">�¼�����</param>
        /// <param name="function">����</param>
        public virtual void registerEvent(FCView control, String eventName, String function) {
            int eventID = getEventID(eventName);
            if (eventID != -1) {
                FCEventInfo eventInfo = null;
                if (m_events.containsKey(control)) {
                    eventInfo = m_events.get(control);
                }
                else {
                    eventInfo = new FCEventInfo();
                    m_events.put(control, eventInfo);
                }
                eventInfo.addEvent(eventID, function);
                switch (eventID) {
                    case FCEventID.ADD: {
                            FCEvent cEvent = new FCEvent(callAdd);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.BACKCOLORCHANGED: {
                            FCEvent cEvent = new FCEvent(callBackColorChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.BACKIMAGECHANGED: {
                            FCEvent cEvent = new FCEvent(CallBackImageChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.CHAR: {
                            FCKeyEvent cEvent = new FCKeyEvent(callChar);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.CHECKEDCHANGED: {
                            FCEvent cEvent = new FCEvent(callCheckedChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.CLICK: {
                            FCTouchEvent cEvent = new FCTouchEvent(callClick);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.COPY: {
                            FCEvent cEvent = new FCEvent(callCopy);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.CUT: {
                            FCEvent cEvent = new FCEvent(callCut);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.DOCKCHANGED: {
                            FCEvent cEvent = new FCEvent(callDockChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.DOUBLECLICK: {
                            FCEvent cEvent = new FCEvent(callDoubleClick);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.DRAGBEGIN: {
                            FCEvent cEvent = new FCEvent(callDragBegin);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.DRAGEND: {
                            FCEvent cEvent = new FCEvent(CallDragEnd);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.DRAGGING: {
                            FCEvent cEvent = new FCEvent(callDragging);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.ENABLECHANGED: {
                            FCEvent cEvent = new FCEvent(callEnableChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.FONTCHANGED: {
                            FCEvent cEvent = new FCEvent(callFontChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TEXTCOLORCHANGED: {
                            FCEvent cEvent = new FCEvent(callTextColorChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GOTFOCUS: {
                            FCEvent cEvent = new FCEvent(callGotFocus);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GRIDCELLCLICK: {
                            FCEvent cEvent = new FCEvent(callFCGridCellClick);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GRIDCELLEDITBEGIN: {
                            FCEvent cEvent = new FCEvent(callFCGridCellEditBegin);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GRIDCELLEDITEND: {
                            FCEvent cEvent = new FCEvent(callFCGridCellEditEnd);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GRIDCELLTOUCHDOWN: {
                            FCEvent cEvent = new FCEvent(callFCGridCellTouchDown);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GRIDCELLTOUCHMOVE: {
                            FCEvent cEvent = new FCEvent(callFCGridCellTouchMove);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.GRIDCELLTOUCHUP: {
                            FCEvent cEvent = new FCEvent(callFCGridCellTouchUp);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.INVOKE: {
                            FCInvokeEvent cEvent = new FCInvokeEvent(callInvoke);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.KEYDOWN: {
                            FCKeyEvent cEvent = new FCKeyEvent(callKeyDown);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.KEYUP: {
                            FCKeyEvent cEvent = new FCKeyEvent(CallKeyUp);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.LOAD: {
                            FCEvent cEvent = new FCEvent(callLoad);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.LOCATIONCHANGED: {
                            FCEvent cEvent = new FCEvent(callLocationChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.LOSTFOCUS: {
                            FCEvent cEvent = new FCEvent(callLostFocus);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.MARGINCHANGED: {
                            FCEvent cEvent = new FCEvent(callMarginChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.MENUITEMCLICK: {
                            FCMenuItemTouchEvent cEvent = new FCMenuItemTouchEvent(callMenuItemClick);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TOUCHDOWN: {
                            FCTouchEvent cEvent = new FCTouchEvent(callTouchDown);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TOUCHENTER: {
                            FCTouchEvent cEvent = new FCTouchEvent(callTouchEnter);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TOUCHLEAVE: {
                            FCTouchEvent cEvent = new FCTouchEvent(callTouchLeave);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TOUCHMOVE: {
                            FCTouchEvent cEvent = new FCTouchEvent(callTouchMove);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TOUCHUP: {
                            FCTouchEvent cEvent = new FCTouchEvent(callTouchUp);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TOUCHWHEEL: {
                            FCTouchEvent cEvent = new FCTouchEvent(callTouchWheel);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.PADDINGCHANGED: {
                            FCPaintEvent cEvent = new FCPaintEvent(callPaddingChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.PAINT: {
                            FCPaintEvent cEvent = new FCPaintEvent(callPaint);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.PAINTBORDER: {
                            FCPaintEvent cEvent = new FCPaintEvent(callPaintBorder);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.PARENTCHANGED: {
                            FCEvent cEvent = new FCEvent(callParentChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.PASTE: {
                            FCEvent cEvent = new FCEvent(callPaste);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.REGIONCHANGED: {
                            FCEvent cEvent = new FCEvent(CallRegionChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.REMOVE: {
                            FCEvent cEvent = new FCEvent(callRemove);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.SCROLLED: {
                            FCEvent cEvent = new FCEvent(callScrolled);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.SELECTEDTIMECHANGED: {
                            FCEvent cEvent = new FCEvent(callSelectedTimeChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.SELECTEDINDEXCHANGED: {
                            FCEvent cEvent = new FCEvent(callSelectedIndexChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.SELECTEDTABPAGECHANGED: {
                            FCEvent cEvent = new FCEvent(CallSelectedTabPageChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.SIZECHANGED: {
                            FCEvent cEvent = new FCEvent(callSizeChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TABINDEXCHANGED: {
                            FCEvent cEvent = new FCEvent(callTabIndexChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TABSTOP: {
                            FCEvent cEvent = new FCEvent(CallTabStop);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TEXTCHANGED: {
                            FCEvent cEvent = new FCEvent(callTextChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.TIMER: {
                            FCTimerEvent cEvent = new FCTimerEvent(callTimer);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.VALUECHANGED: {
                            FCEvent cEvent = new FCEvent(callVisibleChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.VISIBLECHANGED: {
                            FCEvent cEvent = new FCEvent(callVisibleChanged);
                            control.addEvent(cEvent, eventID);
                            break;
                        }
                    case FCEventID.WINDOWCLOSED: {
                            FCEvent cEvent = new FCEvent(callWindowClosed);
                            control.addEvent(cEvent, eventID);
                            break;
                        }

                }
            }
        }
    }
}
