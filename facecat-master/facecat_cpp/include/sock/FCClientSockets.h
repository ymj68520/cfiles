/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCLIENTSOCKETS_H__
#define __FCCLIENTSOCKETS_H__
#pragma once
#include "..\\..\\stdafx.h"
using namespace std;  

namespace FaceCat{ 
	typedef void (__stdcall *RecvMsg)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteClientLog)(int socketID, int localSID, int state, const char *log);

	/*
	* �ͻ����׽������ӹ���
	*/
	class FCClientSockets{
	public:
		static void __stdcall recvServerMsg(int socketID, int localSID, const char *str, int len);
		static void __stdcall writeLog(int socketID, int localSID, int state, const char *log);
	public:
		static int close(int socketID);
		static int connect(int type, int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout);
		static void registerLog(WriteClientLog writeLogCallBack);
		static void registerRecv(RecvMsg recvMsgCallBack);
		static int send(int socketID, const char *str, int len);
		static int sendTo(int socketID, const char *str, int len);
	};
}

#endif