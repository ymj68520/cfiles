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
using System.Net.Sockets;

namespace FaceCat {
    public class SOCKDATA {
        public byte[] m_buffer = null;
        public int m_bufferRemain;
        public bool m_get;
        public int m_head;
        public int m_headSize = 4;
        public byte[] m_headStr = new byte[4];
        public int m_index;
        public int m_len;
        public int m_pos;
        public int m_hSocket;
        public Socket m_socket;
        public byte[] m_str = null;
        public int m_strRemain;
        public bool m_submit;
    }

    public enum ConnectStatus {
        SUCCESS,
        CONNECT_PROXY_FAIL,
        NOT_CONNECT_PROXY,
        CONNECT_SERVER_FAIL
    }
}
