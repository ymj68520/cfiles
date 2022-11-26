/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;
using System.Xml;
using System.IO;
using System.Windows.Forms;
using FaceCat;

namespace FaceCat
{
    /// <summary>
    /// ��������ӿؼ�ί��
    /// </summary>
    /// <param name="sender">������</param>
    /// <param name="type">�ؼ�����</param>
    public delegate void ToolBoxListAddControlEvent(object sender, String type);

    /// <summary>
    /// �������б�ؼ�
    /// </summary>
    public class ToolBoxList : FCLayoutDiv
    {
        /// <summary>
        /// ��������
        /// </summary>
        public ToolBoxList()
        {
            BorderColor = FCColor.None;
            LayoutStyle = FCLayoutStyle.TopToBottom;
            Padding = new FCPadding(5, 3, 5, 0);
            ShowVScrollBar = true;
        }

        public const int EVENTID_TOOLBOXADDCONTROL = 10000;

        /// <summary>
        /// ��ӿؼ��¼�����
        /// </summary>
        protected List<ToolBoxListAddControlEvent> m_createControlEvents;

        /// <summary>
        /// �϶���
        /// </summary>
        private ImageButton m_dragingItem;

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
        /// ע���¼�
        /// </summary>
        /// <param name="func">����ָ��</param>
        /// <param name="eventID">�¼�ID</param>
        public override void addEvent(object func, int eventID) {
            switch (eventID) {
                case EVENTID_TOOLBOXADDCONTROL:
                    ToolBoxListAddControlEvent toolBoxAddControlEvent = (ToolBoxListAddControlEvent)func;
                    if (toolBoxAddControlEvent != null) {
                        if (m_createControlEvents == null) {
                            m_createControlEvents = new List<ToolBoxListAddControlEvent>();
                        }
                        m_createControlEvents.Add(toolBoxAddControlEvent);
                    }
                    break;
                default:
                    base.addEvent(func, eventID);
                    break;
            }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType()
        {
            return "ToolBoxList";
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad()
        {
            base.onLoad();
            //�����϶���
            if (m_dragingItem == null)
            {
                m_dragingItem = new ImageButton();
                m_dragingItem.Size = new FCSize(20, 20);
                m_dragingItem.Visible = false;
                Native.addControl(m_dragingItem);
                String toolBoxItems = "Button;Calendar;CheckBox;ComboBox;DateTimePicker;Div;Grid;GroupBox;Label;LayoutDiv;LinkLabel;RadioButton;Spin;SplitLayoutDiv;TabControl;TableLayoutDiv;TextBox;Tree;Window";
                String toolBoxItemsText = "��ť;����;��ѡ��;�����б�;����ѡ��;ͼ��;���;��Ͽ�;��ǩ;���ֲ�;������;��ѡ��ť;��ֵ�ı���;�ָ��;��ҳ��;��񲼾ֲ�;�ı���;����;����";
                String[] items = toolBoxItems.Split(new String[] { ";" }, StringSplitOptions.RemoveEmptyEntries);
                String[] items2 = toolBoxItemsText.Split(new String[] { ";" }, StringSplitOptions.RemoveEmptyEntries);
                int itemsSize = items.Length;
                for (int i = 0; i < itemsSize; i++)
                {
                    String item = items[i];
                    String itemText = items2[i];
                    //������ť�ؼ�
                    ImageButton toolBoxControlButton = new ImageButton();
                    addControl(toolBoxControlButton);
                    toolBoxControlButton.Name = item;
                    toolBoxControlButton.Text = itemText + "(" + item + ")";
                    toolBoxControlButton.Tag = item.ToLower();
                    toolBoxControlButton.BackImage = "file='\\images\\" + item + ".bmp' highcolor='255,0,255' lowcolor='255,0,255'";
                    //ע���¼�
                    toolBoxControlButton.addEvent(new FCTouchEvent(toolBoxItemTouchDown), FCEventID.TOUCHDOWN);
                    toolBoxControlButton.addEvent(new FCTouchEvent(toolBoxItemTouchMove), FCEventID.TOUCHMOVE);
                    toolBoxControlButton.addEvent(new FCTouchEvent(toolBoxItemTouchUp), FCEventID.TOUCHUP);
                }
            }
        }

        /// <summary>
        /// �����ؼ�����
        /// </summary>
        /// <param name="type">����</param>
        public virtual void onCreateControl(String type)
        {
            if (m_createControlEvents != null)
            {
                List<ToolBoxListAddControlEvent> eventsCopy = new List<ToolBoxListAddControlEvent>();
                int eventSize = m_createControlEvents.Count;
                for (int i = 0; i < eventSize; i++)
                {
                    eventsCopy.Add(m_createControlEvents[i]);
                }
                eventSize = eventsCopy.Count;
                for (int i = 0; i < eventSize; i++)
                {
                    eventsCopy[i](this, type);
                }
            }
        }

        /// <summary>
        /// �ػ汳������
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintBackground(FCPaint paint, FCRect clipRect)
        {
            if (FCDraw.m_style == 0)
            {
                int width = Width, height = Height;
                FCRect drawRect = new FCRect(0, 0, width, height);
                paint.fillGradientRect(FCDraw.FCCOLORS_BACKCOLOR, FCDraw.FCCOLORS_BACKCOLOR2, drawRect, 0, 0);
            }
            else
            {
                base.onPaintBackground(paint, clipRect);
            }
        }

        /// <summary>
        /// ȡ��ע���¼�
        /// </summary>
        /// <param name="func">����ָ��</param>
        /// <param name="eventID">�¼�ID</param>
        public override void removeEvent(object func, int eventID) {
            switch (eventID) {
                case EVENTID_TOOLBOXADDCONTROL:
                    ToolBoxListAddControlEvent toolBoxAddControlEvent = (ToolBoxListAddControlEvent)func;
                    if (toolBoxAddControlEvent != null) {
                        m_createControlEvents.Remove(toolBoxAddControlEvent);
                    }
                    break;
                default:
                    base.removeEvent(func, eventID);
                    break;
            }
        }

        /// <summary>
        /// �ؼ�����갴���¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        private void toolBoxItemTouchDown(object sender, FCTouchInfo touchInto)
        {
            if (touchInto.m_firstTouch && touchInto.m_clicks == 1)
            {
                if (m_xml != null)
                {
                    FCPoint mp = touchInto.m_firstPoint;
                    FCView control = sender as FCView;
                    m_dragingItem.Visible = true;
                    m_dragingItem.Text = control.Tag.ToString();
                    m_dragingItem.Location = control.pointToNative(mp);
                    m_dragingItem.BackImage = "file='\\images\\" + control.Name + ".bmp' highcolor='255,0,255' lowcolor='255,0,255'";
                    Native.invalidate();
                }
            }
        }

        /// <summary>
        /// �ؼ�������ƶ��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        private void toolBoxItemTouchMove(object sender, FCTouchInfo touchInto)
        {
            if (m_dragingItem.Visible)
            {
                FCView control = sender as FCView;
                FCPoint mp = touchInto.m_firstPoint;
                FCPoint location = control.pointToNative(mp);
                location.x += 10;
                location.y -= 16;
                m_dragingItem.Location = location;
                Native.invalidate();
            }
        }

        /// <summary>
        /// �ؼ������̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="mp">����</param>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        private void toolBoxItemTouchUp(object sender, FCTouchInfo touchInto)
        {
            if (m_dragingItem.Visible)
            {
                m_dragingItem.Visible = false;
                onCreateControl(m_dragingItem.Text);
                Native.invalidate();
            }
        }
    }
}
