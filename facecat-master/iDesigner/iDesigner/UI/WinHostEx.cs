/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using FaceCat;

namespace FaceCat
{
    /// <summary>
    /// ���������
    /// </summary>
    public class WinHostEx : WinHost
    {
        private bool loadingDesigner = false;

        /// <summary>
        /// ��ȡ�������Ƿ�Ϊ������ļ���
        /// </summary>
        public bool LoadingDesigner
        {
            get { return loadingDesigner; }
            set { loadingDesigner = value; }
        }

        /// <summary>
        /// �����ڲ��ؼ�
        /// </summary>
        /// <param name="parent">���ؼ�</param>
        /// <param name="clsid">�ؼ���ʶ</param>
        /// <returns>�ڲ��ؼ�</returns>
        public override FCView createInternalControl(FCView parent, String clsid)
        {
            //�����ؼ�
            FCCalendar calendar = parent as FCCalendar;
            if (calendar != null)
            {
                if (clsid == "datetitle")
                {
                    return new DateTitle(calendar);
                }
                else if (clsid == "headdiv")
                {
                    HeadDiv headDiv = new HeadDiv(calendar);
                    headDiv.Width = parent.Width;
                    headDiv.Dock = FCDockStyle.Top;
                    return headDiv;
                }
                else if (clsid == "lastbutton")
                {
                    return new ArrowButton(calendar);
                }
                else if (clsid == "nextbutton")
                {
                    ArrowButton nextBtn = new ArrowButton(calendar);
                    nextBtn.ToLast = false;
                    return nextBtn;
                }
            }
            //�ָ��
            FCSplitLayoutDiv splitLayoutDiv = parent as FCSplitLayoutDiv;
            if (splitLayoutDiv != null)
            {
                if (clsid == "splitter")
                {
                    FCButton splitter = new FCButton();
                    splitter.BackColor = FCColor.Border;
                    splitter.BorderColor = FCColor.Border;
                    splitter.Size = new FCSize(5, 5);
                    return splitter;
                }
            }
            //������
            FCScrollBar scrollBar = parent as FCScrollBar;
            if (scrollBar != null)
            {
                scrollBar.BorderColor = FCColor.None;
                scrollBar.BackColor = FCColor.None;
                if (clsid == "addbutton")
                {
                    RibbonButton addButton = new RibbonButton();
                    addButton.Size = new FCSize(10, 10);
                    if (scrollBar is FCHScrollBar)
                    {
                        addButton.ArrowType = 2;
                    }
                    else if (scrollBar is FCVScrollBar)
                    {
                        addButton.ArrowType = 4;
                    }
                    return addButton;
                }
                else if (clsid == "backbutton")
                {
                    FCButton backButton = new FCButton();
                    backButton.BorderColor = FCColor.None;
                    backButton.BackColor = FCColor.None;
                    return backButton;
                }
                else if (clsid == "scrollbutton")
                {
                    RibbonButton scrollButton = new RibbonButton();
                    scrollButton.AllowDrag = true;
                    if (scrollBar is FCVScrollBar)
                    {
                        scrollButton.Angle = 0;
                    }
                    return scrollButton;
                }
                else if (clsid == "reducebutton")
                {
                    RibbonButton reduceButton = new RibbonButton();
                    reduceButton.Size = new FCSize(10, 10);
                    if (scrollBar is FCHScrollBar)
                    {
                        reduceButton.ArrowType = 1;
                    }
                    else if (scrollBar is FCVScrollBar)
                    {
                        reduceButton.ArrowType = 3;
                    }
                    return reduceButton;
                }
            }
            //ҳ��
            FCTabPage tabPage = parent as FCTabPage;
            if (tabPage != null)
            {
                if (clsid == "headerbutton")
                {
                    RibbonButton button = new RibbonButton();
                    button.AllowDrag = true;
                    FCSize size = new FCSize(100, 20);
                    button.Size = size;
                    return button;
                }
            }
            //�����б�
            FCComboBox comboBox = parent as FCComboBox;
            if (comboBox != null)
            {
                if (clsid == "dropdownbutton")
                {
                    RibbonButton dropDownButton = new RibbonButton();
                    dropDownButton.ArrowType = 4;
                    dropDownButton.DisplayOffset = false;
                    int width = comboBox.Width;
                    int height = comboBox.Height;
                    FCPoint location = new FCPoint(width - 20, 0);
                    dropDownButton.Location = location;
                    FCSize size = new FCSize(20, height);
                    dropDownButton.Size = size;
                    return dropDownButton;
                }
                else if (clsid == "dropdownmenu")
                {
                    FCComboBoxMenu comboBoxMenu = new FCComboBoxMenu();
                    comboBoxMenu.ComboBox = comboBox;
                    comboBoxMenu.Popup = true;
                    FCSize size = new FCSize(100, 200);
                    comboBoxMenu.Size = size;
                    return comboBoxMenu;
                }
            }
            //����ѡ��
            FCDateTimePicker datePicker = parent as FCDateTimePicker;
            if (datePicker != null)
            {
                if (clsid == "dropdownbutton")
                {
                    RibbonButton dropDownButton = new RibbonButton();
                    dropDownButton.ArrowType = 4;
                    dropDownButton.DisplayOffset = false;
                    int width = datePicker.Width;
                    int height = datePicker.Height;
                    FCPoint location = new FCPoint(width - 16, 0);
                    dropDownButton.Location = location;
                    FCSize size = new FCSize(16, height);
                    dropDownButton.Size = size;
                    return dropDownButton;
                }
                else if (clsid == "dropdownmenu")
                {
                    FCMenu dropDownMenu = new FCMenu();
                    dropDownMenu.Padding = new FCPadding(1);
                    dropDownMenu.Popup = true;
                    FCSize size = new FCSize(200, 200);
                    dropDownMenu.Size = size;
                    return dropDownMenu;
                }
            }
            //����ѡ��
            FCSpin spin = parent as FCSpin;
            if (spin != null)
            {
                if (clsid == "downbutton")
                {
                    RibbonButton downButton = new RibbonButton();
                    downButton.DisplayOffset = false;
                    downButton.ArrowType = 4;
                    FCSize size = new FCSize(16, 16);
                    downButton.Size = size;
                    return downButton;
                }
                else if (clsid == "upbutton")
                {
                    RibbonButton upButton = new RibbonButton();
                    upButton.DisplayOffset = false;
                    upButton.ArrowType = 3;
                    FCSize size = new FCSize(16, 16);
                    upButton.Size = size;
                    return upButton;
                }
            }
            //������
            FCDiv div = parent as FCDiv;
            if (div != null)
            {
                if (clsid == "hscrollbar")
                {
                    FCHScrollBar hScrollBar = new FCHScrollBar();
                    hScrollBar.Visible = false;
                    hScrollBar.Size = new FCSize(10, 10);
                    return hScrollBar;
                }
                else if (clsid == "vscrollbar")
                {
                    FCVScrollBar vScrollBar = new FCVScrollBar();
                    vScrollBar.Visible = false;
                    vScrollBar.Size = new FCSize(10, 10);
                    return vScrollBar;
                }
            }
            //���
            FCGrid grid = parent as FCGrid;
            if (grid != null)
            {
                if (clsid == "edittextbox")
                {
                    return new FCTextBox();
                }
            }
            return base.createInternalControl(parent, clsid);
        }

        /// <summary>
        /// ִ�г���
        /// </summary>
        /// <param name="cmd">����</param>
        public static void execute(String cmd)
        {
            try
            {
                Process.Start(cmd);
            }
            catch { }
        }

        public override void invalidate()
        {
            base.invalidate();
        }
    }
}
