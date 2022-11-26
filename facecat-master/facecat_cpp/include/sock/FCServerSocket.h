/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSERVERSOCKET_H__
#define __FCSERVERSOCKET_H__
#pragma once
#include "..\\..\\stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include "FCServerSockets.h"
#pragma comment (lib,"winmm")

namespace FaceCat{
	typedef enum{
		RECV_POSTED
	}OPERATION_TYPE;

	typedef struct
	{
		WSAOVERLAPPED  overlap;
		WSABUF         Buffer;
		char           szMessage[1024];
		DWORD          NumberOfBytesRecvd;
		DWORD          Flags;
		OPERATION_TYPE OperationType;
	}PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

	class SOCKDATA{
	public:
		SOCKDATA();
		~SOCKDATA();
		char *m_buffer;
		int m_bufferRemain;
		bool m_get;
		int m_head;
		int m_headSize;
		char m_headStr[4];
		int m_index;
		int m_len;
		int m_pos;
		SOCKET m_socket;
		char *m_str;
		int m_strRemain;
		bool m_submit;
	};

	/*
	* ������׽�������
	*/
	class FCServerSocket{
	public:
		SOCKADDR_IN m_addr;
		HANDLE m_completionPort;
		vector<SOCKDATA*> m_datas;
		SOCKET m_hSocket;
		int m_port;
		RecvMsg m_recvEvent;
		WriteServerLog m_writeLogEvent;
	public:
		FCServerSocket();
		virtual ~FCServerSocket();
		int close(int socketID);
		int closeClient(int socketID);
		int recv(SOCKDATA *data);
		static int send(int socketID, const char *str, int len);
		int sendTo(const char *str, int len);
		int startTCP(int port);
		int startUDP(int port);
		void writeLog(int socketID, int localSID, int state, const char *log);
	public:
		static void wSStart();
		static void wSStop();
	};
}
#endif