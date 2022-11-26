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

namespace FaceCat
{
    public partial class PreViewForm : Form
    {
        /// <summary>
        /// ��������
        /// </summary>
        public PreViewForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// �ؼ�������
        /// </summary>
        private WinHostEx m_host;

        /// <summary>
        /// ������
        /// </summary>
        private FCNative m_native;

        /// <summary>
        /// ������
        /// </summary>
        private UIXmlEx3 m_xml;

        /// <summary>
        /// ��ȡ�ͻ��˳ߴ�
        /// </summary>
        /// <returns>�ͻ��˳ߴ�</returns>
        public FCSize getClientSize()
        {
            return new FCSize(ClientSize.Width, ClientSize.Height);
        }

        /// <summary>
        /// ����XML
        /// </summary>
        /// <param name="fileName">�ļ���</param>
        public void loadFile(String fileName)
        {
            //����XML������
            m_xml = new UIXmlEx3();
            //���ӿؼ���
            m_xml.createNative();
            m_native = m_xml.Native;
            m_xml.Script = new DesignerScript(m_xml);
            m_native.Paint = new GdiPlusPaintEx();
            m_native.Host = new WinHostEx();
            m_native.Host.Native = m_native;
            m_host = m_native.Host as WinHostEx;
            m_host.HWnd = Handle;
            m_native.AllowScaleSize = true;
            m_native.DisplaySize = new FCSize(ClientSize.Width, ClientSize.Height);
            m_xml.resetScaleSize(getClientSize());
            m_native.invalidate();
            m_xml.loadFile(fileName, null);
            m_native.update();
            m_native.invalidate();
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
                m_xml.resetScaleSize(getClientSize());
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
                double scaleFactor = m_xml.ScaleFactor;
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
                m_xml.ScaleFactor = scaleFactor;
                m_xml.resetScaleSize(getClientSize());
                Invalidate();
            }
        }


        /// <summary>
        /// ��Ϣѭ��
        /// </summary>
        /// <param name="m">��Ϣ</param>
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