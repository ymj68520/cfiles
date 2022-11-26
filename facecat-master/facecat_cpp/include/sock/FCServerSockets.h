/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSERVERSOCKETS_H__
#define __FCSERVERSOCKETS_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat
{
	typedef void (__stdcall *RecvMsg)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteServerLog)(int socketID, int localSID, int state, const char *str);

	/*
	* ������׽������ӹ���
	*/
	class FCServerSockets
	{
	public:
		static void __stdcall recvClientMsg(int socketID, int localSID, const char *str, int len);
		static void __stdcall writeLog(int socketID, int localSID, int state, const char *log);
	public:
		static int close(int socketID);
		static int closeClient(int socketID, int clientSocketID);
		static void registerLog(WriteServerLog writeLogCallBack);
		static void registerRecv(RecvMsg recvMsgCallBack);
		static int send(int socketID, const char *str, int len);
		static int sendTo(int socketID, const char *str, int len);
		static int start(int type, int port);
	};
}
#endif