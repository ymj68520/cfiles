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
using System.Net;
using System.IO;
using FaceCat;
using System.IO.Compression;

namespace FaceCat {
    /// <summary>
    /// HTTP����
    /// </summary>
    public class FCHttpHardService : FCServerService {
        /// <summary>
        /// ����HTTP����
        /// </summary>
        public FCHttpHardService() {
            ServiceID = SERVICEID_HTTPHARD;
        }

        /// <summary>
        /// �û��Ự����ID
        /// </summary>
        public const int SERVICEID_HTTPHARD = 20;

        /// <summary>
        /// POST����ID
        /// </summary>
        public const int FUNCTIONID_HTTPHARD_TEST = 0;

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="message">��Ϣ</param>
        public override void onReceive(FCMessage message) {
            base.onReceive(message);
            sendToListener(message);
        }

        /// <summary>
        /// ������Ϣ
        /// </summary>
        /// <param name="message">��Ϣ</param>
        public override int send(FCMessage message) {
            FCBinary bw = new FCBinary();
            byte[] body = message.m_body;
            int bodyLength = message.m_bodyLength;
            int uncBodyLength = bodyLength;
            lock (m_compressTypes) {
                if (m_compressTypes.ContainsKey(message.m_socketID)) {
                    message.m_compressType = m_compressTypes.get(message.m_socketID);
                }
            }
            if (message.m_compressType == COMPRESSTYPE_GZIP) {
                using (MemoryStream cms = new MemoryStream()) {
                    using (GZipStream gzip = new GZipStream(cms, CompressionMode.Compress)) {
                        gzip.Write(body, 0, body.Length);
                    }
                    body = cms.ToArray();
                    bodyLength = body.Length;
                }
            }
            int len = sizeof(int) * 4 + bodyLength + sizeof(short) * 3 + sizeof(byte) * 2;
            bw.writeInt(len);
            bw.writeShort((short)message.m_groupID);
            bw.writeShort((short)message.m_serviceID);
            bw.writeShort((short)message.m_functionID);
            bw.writeInt(message.m_sessionID);
            bw.writeInt(message.m_requestID);
            bw.writeByte((byte)message.m_state);
            bw.writeByte((byte)message.m_compressType);
            bw.writeInt(uncBodyLength);
            bw.writeBytes(body);
            byte[] bytes = bw.getBytes();
            lock (FCHttpMonitor.MainMonitor.m_httpDatas) {
                FCHttpMonitor.MainMonitor.m_httpDatas.get(message.m_socketID).m_resBytes = bytes;
            }
            int ret = bytes.Length;
            UpFlow += ret;
            bw.close();
            onClientClose(message.m_socketID, 0);
            return ret;
        }
    }
}
