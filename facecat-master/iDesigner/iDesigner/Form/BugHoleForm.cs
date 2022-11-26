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
using FaceCat;
using System.Runtime.InteropServices;

namespace FaceCat
{
    /// <summary>
    /// �涴����
    /// </summary>
    public partial class BugHoleForm : Form
    {
        /// <summary>
        /// �����涴����
        /// </summary>
        public BugHoleForm()
        {
            InitializeComponent();
        }

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

        private double m_scaleFactor = 1;

        /// <summary>
        /// ��ȡ��������������
        /// </summary>
        public double ScaleFactor
        {
            get { return m_scaleFactor; }
            set { m_scaleFactor = value; }
        }

        private WindowXmlEx m_window;

        /// <summary>
        /// ��ȡ�����ô���
        /// </summary>
        public WindowXmlEx Window
        {
            get { return m_window; }
            set { m_window = value; }
        }

        /// <summary>
        /// ��Ӿ���
        /// </summary>
        /// <param name="native">��</param>
        /// <param name="target">Ŀ��</param>
        public void addBugHole(FCNative native, FCView target)
        {
            if (m_native == null)
            {
                m_native = new FCNative();
                m_native.MirrorMode = FCMirrorMode.BugHole;
                m_native.Paint = new GdiPlusPaintEx();
                m_native.Host = new WinHostEx();
                m_native.Host.Native = m_native;
                m_native.ResourcePath = WinHostEx.getAppPath() + "\\config";
                m_host = m_native.Host as WinHostEx;
                m_host.HWnd = Handle;
                //���óߴ�
                m_native.AllowScaleSize = true;
                m_native.DisplaySize = new FCSize(ClientSize.Width, ClientSize.Height);
                resetScaleSize(getClientSize());
            }
            m_native.addMirror(native, target);
            m_native.update();
            m_native.invalidate();
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
        /// ����ر��¼�
        /// </summary>
        /// <param name="e"></param>
        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            base.OnFormClosing(e);
            List<FCView> controls = m_native.getControls();
            List<FCView> removeControls = new List<FCView>();
            int controlsSize = controls.Count;
            for (int i = 0; i < controlsSize; i++)
            {
                removeControls.Add(controls[i]);
            }
            for (int i = 0; i < controlsSize; i++)
            {
                m_native.removeMirror(removeControls[i]);
            }
            removeControls.Clear();
            if (m_native != null)
            {
                m_native.delete();
                m_native = null;
            }
            if (m_window != null)
            {
                WindowXmlEx window = m_window;
                m_window = null;
                window.close();
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
                double scaleFactor = ScaleFactor;
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
                ScaleFactor = scaleFactor;
                resetScaleSize(getClientSize());
                Invalidate();
            }
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
                resetScaleSize(getClientSize());
                Invalidate();
            }
        }

        /// <summary>
        /// �������ųߴ�
        /// </summary>
        /// <param name="clientSize">�ͻ��˴�С</param>
        public void resetScaleSize(FCSize clientSize)
        {
            FCNative native = Native;
            if (native != null)
            {
                native.ScaleSize = new FCSize((int)(clientSize.cx * m_scaleFactor), (int)(clientSize.cy * m_scaleFactor));
                native.update();
            }
        }

        /// <summary>
        /// ��Ϣ
        /// </summary>
        /// <param name="m"></param>
        protected override void WndProc(ref Message m)
        {
            if (m_host != null)
            {
                if (m_host.onMessage(ref m) > 0)
                {
                    return;
                }
            }
            base.WndProc(ref m);
        }
    }
}