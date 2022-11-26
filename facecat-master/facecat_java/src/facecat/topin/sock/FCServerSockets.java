/*捂脸猫FaceCat框架 v1.0
 1.创始人-矿洞程序员-上海宁米科技创始人-脉脉KOL-陶德 (微信号:suade1984);
 2.联合创始人-上海宁米科技创始人-袁立涛(微信号:wx627378127);
 3.联合创始人-河北思尔企业管理咨询有限公司合伙人-肖添龙(微信号:xiaotianlong_luu);
 4.联合开发者-陈晓阳(微信号:chenxiaoyangzxy)，助理-朱炜(微信号:cnnic_zhu);
 5.该框架开源协议为BSD，欢迎对我们的创业活动进行各种支持，欢迎更多开发者加入。
 包含C/C++,Java,C#,iOS,MacOS,Linux六个版本的图形和通讯服务框架。
 */
package facecat.topin.sock;

import java.io.*;
import java.util.*;

/*
* 服务端套接字连接管理
*/
public class FCServerSockets {

    private static FCSocketListener m_listener;

    private static HashMap<Integer, FCServerSocket> m_servers = new HashMap<Integer, FCServerSocket>();

    private static int m_socketID;

    public static int close(int socketID) {
        int ret = -1;
        if (m_servers.containsKey(socketID)) {
            FCServerSocket server = m_servers.get(socketID);
            ret = server.close();
            m_servers.remove(socketID);
        }
        return ret;
    }

    public static int closeClient(int socketID) {
        int ret = -1;
        if (m_servers.containsKey(socketID)) {
            FCServerSocket server = m_servers.get(socketID);
            ret = server.closeClient(socketID);
            m_servers.remove(socketID);
        }
        return ret;
    }

    public static void recvClientMsg(int socketID, int localSID, byte[] str, int len) {
        m_listener.callBack(socketID, localSID, str, len);
    }

    public static int send(int socketID, int localSID, byte[] str, int len) {
        int ret = -1;
        if (m_servers.containsKey(localSID)) {
            FCServerSocket server = m_servers.get(localSID);
            ret = server.send(socketID, str, len);
        }
        return ret;
    }

    public static int sendTo(int localSID, byte[] str, int len) {
        int ret = -1;
        if (m_servers.containsKey(localSID)) {
            FCServerSocket server = m_servers.get(localSID);
            ret = server.sendTo(str, len);
        }
        return ret;
    }

    public static int setListener(FCSocketListener listener) {
        m_listener = listener;
        return 1;
    }

    public static int start(int type, int port) {
        try {
            FCServerSocket server = new FCServerSocket();
            if (type == 0) {
                server.startTCP(port);
            } else if (type == 1) {
                server.startUDP(port);
            }
            m_socketID++;
            Integer socketID = (Integer) m_socketID;
            server.m_hSocket = m_socketID;
            m_servers.put(socketID, server);
            return m_socketID;
        } catch (Exception ex) {
            return -1;
        }
    }

    public static void writeServerLog(int socketID, int localSID, int state, String log) {
        m_listener.writeLog(socketID, localSID, state, log);
    }
}
