/*��������èFaceCat��� v1.0
 ����è��ʼ��-�󶴳���Ա-����KOL-�յ� (΢�ź�:suade1984);
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;
using System.Xml;
using FaceCat;

namespace FaceCat
{
    /// <summary>
    /// ������
    /// </summary>
    public partial class MainForm : Form
    {
        /// <summary>
        /// ��������
        /// </summary>
        public MainForm()
        {
            InitializeComponent();
            //����XML������
            m_designer = new Designer();
            //���ӿؼ���
            m_designer.createNative();
            m_designer.Script = new DesignerScript(m_designer);
            m_native = m_designer.Native;
            m_native.Paint = new GdiPlusPaintEx();
            m_native.Host = new WinHostEx();
            m_native.Host.Native = m_native;
            m_native.ResourcePath = WinHostEx.getAppPath() + "\\config";
            m_host = m_native.Host as WinHostEx;
            m_host.HWnd = Handle;
            //���óߴ�
            m_native.AllowScaleSize = true;
            m_native.DisplaySize = new FCSize(ClientSize.Width, ClientSize.Height);
            m_designer.resetScaleSize(getClientSize());
            m_native.invalidate();
            //����Xml
            m_host.LoadingDesigner = true;
            m_designer.load(Path.Combine(DataCenter.GetAppPath(), "config\\MainFrame.html"));
            m_host.LoadingDesigner = false;
            
        }

        /// <summary>
        /// �����
        /// </summary>
        private Designer m_designer;

        private WinHostEx m_host;

        /// <summary>
        /// ��ȡ�������豸������
        /// </summary>
        public WinHostEx Host
        {
            get { return m_host; }
            set { m_host = value; }
        }

        private FCNative m_native;

        /// <summary>
        /// ��ȡ�����÷�����
        /// </summary>
        public FCNative Native
        {
            get { return m_native; }
            set { m_native = value; }
        }

        /// <summary>
        /// ��ȡ�ͻ��˳ߴ�
        /// </summary>
        /// <returns>�ͻ��˳ߴ�</returns>
        public FCSize getClientSize()
        {
            return new FCSize(ClientSize.Width, ClientSize.Height);
        }

        /// <summary>
        /// �ļ����·���
        /// </summary>
        /// <param name="e">����</param>
        protected override void OnDragDrop(DragEventArgs e)
        {
            base.OnDragDrop(e);
            StringBuilder filesName = new StringBuilder("");
            Array files = (System.Array)e.Data.GetData(DataFormats.FileDrop);//������������ת��Ϊ����洢  
            foreach (object i in files)
            {
                String str = i.ToString();
                if (FCFile.isFileExist(str))
                {
                    m_designer.openFile(str);
                }
            }
        }

        /// <summary>
        /// �ļ����뷽��
        /// </summary>
        /// <param name="e">����</param>
        protected override void OnDragEnter(DragEventArgs e)
        {
            base.OnDragEnter(e);
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        /// <summary>
        /// ����رշ���
        /// </summary>
        /// <param name="e">����</param>
        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            if (m_designer.hasModify())
            {
                if (MessageBox.Show("�Ƿ񱣴����޸ĵ��ĵ���", "��ʾ", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                {
                    m_designer.saveAll();
                }
            }
            m_designer.exit();
            Environment.Exit(0);
        }

        /// <summary>
        /// �ߴ�ı䷽��
        /// </summary>
        /// <param name="e">����</param>
        protected override void OnSizeChanged(EventArgs e)
        {
            base.OnSizeChanged(e);
            if (m_host != null)
            {
                m_designer.resetScaleSize(getClientSize());
                Invalidate();
            }
        }

        /// <summary>
        /// ����������
        /// </summary>
        /// <param name="e">����</param>
        protected override void OnMouseWheel(MouseEventArgs e)
        {
            base.OnMouseWheel(e);
            if (m_host.isKeyPress(0x11))
            {
                double scaleFactor = m_designer.ScaleFactor;
                if (e.Delta > 0)
                {
                    if (scaleFactor > 0.2)
                    {
                        scaleFactor -= 0.1;
                    }
                }
                else if (e.Delta < 0)
                {
                    if (scaleFactor < 10)
                    {
                        scaleFactor += 0.1;
                    }
                }
                m_designer.ScaleFactor = scaleFactor;
                m_designer.resetScaleSize(getClientSize());
                Invalidate();
            }
        }


        /// <summary>
        /// ��Ϣѭ��
        /// </summary>
        /// <param name="m">��Ϣ</param>
        protected override void WndProc(ref Message m)
        {
            if (m_designer != null)
            {
                if (m_designer.wndProc(ref m))
                {
                    return;
                }
            }
            base.WndProc(ref m);
        }
    }
}