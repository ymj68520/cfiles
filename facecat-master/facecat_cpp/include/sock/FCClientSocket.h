/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCLIENTSOCKET_H__
#define __FCCLIENTSOCKET_H__
#pragma once
#include "..\\..\\stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include <time.h> 
#include <string>  
#include <vector>  
#include "CBase64.h"
#include "FCClientSockets.h"
using namespace std;  

namespace FaceCat{ 
	enum ConnectStatus{  
		SUCCESS,  
		CONNECT_PROXY_FAIL,  
		NOT_CONNECT_PROXY,  
		CONNECT_SERVER_FAIL  
	};

	struct TSock4req1{   
		char VN;   
		char CD;   
		unsigned short Port;   
		unsigned long IPAddr;   
		char other;   
	};   
  
	struct TSock4ans1{   
		char VN;   
		char CD;   
	};  
  
	struct TSock5req1{   
		char Ver;   
		char nMethods;   
		char Methods;   
	};   
  
	struct TSock5ans1{   
		char Ver;   
		char Method;   
	};   
  
	struct TSock5req2{   
		char Ver;   
		char Cmd;   
		char Rsv;   
		char Atyp;   
		char other;   
	};   
  
	struct TSock5ans2{   
		char Ver;   
		char Rep;   
		char Rsv;   
		char Atyp;   
		char other;   
	};   
  
	struct TAuthreq{   
		char Ver;   
		char Ulen;   
		char Name;   
		char PLen;   
		char Pass;   
	};   
  
	struct TAuthans{   
		char Ver;   
		char Status;   
	};   
  
	/*
	* �ͻ����׽�������
	*/
	class FCClientSocket{
		bool m_blnProxyServerOk;
		string m_ip;
		u_short m_port;
		string m_proxyDomain;
		int m_proxyType;  
		string m_proxyIp;  
		u_short m_proxyPort; 
		string m_proxyUserName;  
		string m_proxyUserPwd;
		int m_timeout;
	private:
		ConnectStatus connectStandard();
		ConnectStatus connectByHttp();  
		ConnectStatus connectBySock4();  
		ConnectStatus connectBySock5(); 
		void createSocket();
	public:
		SOCKADDR_IN m_addr;
		SOCKET m_hSocket;
		RecvMsg m_recvEvent;
		int m_type;
		WriteClientLog m_writeLogEvent;
	public:
		FCClientSocket(int type, int proxyType, const string &ip, u_short port, const string &proxyIp, u_short proxyPort, const string &proxyUserName, const string &proxyUserPwd, const string &proxyDomain, int timeout);
		virtual ~FCClientSocket();
	public:
		int close(int socketID);
		ConnectStatus connect(); 
		ConnectStatus connectProxyServer();
		static string getHostIP(const char* ip);
		static int send(int socketID, const char *str, int len);
		int sendTo(const char *str, int len);
		void writeLog(int socketID, int localSID, int state, const char *log);
	};  
}

#endif