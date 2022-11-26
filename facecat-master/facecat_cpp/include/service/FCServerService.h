/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSERVERSERVICE_H__
#define __FCSERVERSERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include <string>
#include <map>
using namespace std;

#define  COMPRESSTYPE_NONE			  0
#define  COMPRESSTYPE_GZIP			  1

static int m_requestID = 10000;

namespace FaceCat{	
	/**
	 * ��Ϣ�ṹ
	 */
	struct FCMessage{
	public:
	    /**
		 * ������Ϣ
		 */
		FCMessage();
		/**
		* ������Ϣ
		* @param  groupID  ��ID
		* @param  serviceID  ����ID
		* @param  functionID  ����ID
		* @param  sessionID  ��¼ID
		* @param  requestID  ����ID
		* @param  socketID  ����ID
		* @param  state  ״̬
		* @param  compressType  ѹ������
		* @param  bodyLength  ���峤��
		* @param  body  ����
		*/
		FCMessage(int groupID, int serviceID, int functionID, int sessionID, int requestID, int socketID, int state, int compressType, int bodyLength, char *body);
		int m_groupID;   
		int m_serviceID;   
		int m_functionID;  
		int m_sessionID;   
		int m_requestID;   
		int m_socketID; 
		int m_state;
		int m_compressType;
		int m_bodyLength;  
		char *m_body;
		/**
		 * ��������
		 */
		void copy(FCMessage *message)
		{
			m_groupID = message->m_groupID;
			m_serviceID = message->m_serviceID;
			m_functionID = message->m_functionID;
			m_sessionID = message->m_sessionID;
			m_requestID= message->m_requestID;
			m_socketID = message->m_socketID;
			m_state = message->m_state;
			m_compressType = message->m_compressType;
			m_bodyLength = message->m_bodyLength;
			m_body = message->m_body;
		}
	};

	typedef void (__stdcall *MessageCallBack)(int socketID, int localSID, const char *str, int len);

	typedef void (__stdcall *WriteLogCallBack)(int socketID, int localSID, int state, const char *log);

	typedef void (__stdcall *ListenerMessageCallBack)(FCMessage *message, Object pInvoke);

	typedef int (*funcCloseServer)(int);

	typedef void (*funcRegisterCallBack)(MessageCallBack);

	typedef void (*funcRegisterLog)(WriteLogCallBack);

	typedef int (*funcSendByServer)(int, const char*, int);

	typedef int (*funcStartServer)(int, int);

	/*
	* ��Ϣ����
	*/
	class FCMessageListener{
	private:
	    /**
		 * �����ص��б�
		 */
		vector<ListenerMessageCallBack> m_callBacks;
		vector<Object> m_callBackInvokes;
	public:
	    /**
		 * ������Ϣ����
		 */
		FCMessageListener();
		virtual ~FCMessageListener();
	public:
	    /**
		 * ��ӻص�
		 */
		void add(ListenerMessageCallBack callBack, Object pInvoke);
		/**
		 * �ص�����
		 */
		void callBack(FCMessage *message);
		/**
		 * �������
		 */
		void clear();
		/**
		 * �Ƴ��ص�
		 */
		void remove(ListenerMessageCallBack callBack);
	};

	/*
	* �׽�����
	*/
	class FCSocketArray{
	private:
	    /**
		 * �׽���ID��
		 */
		vector<int> m_sockets;
	public:
		FCSocketArray();
		virtual ~FCSocketArray();
	public:
	    /**
		 * ����׽���ID
		 */
		void addSocket(int socketID);
		/**
		* ��ȡ�׽����б�
		* @param  socketList  �׽����б�
		*/
		void getSocketList(vector<int> *socketList);
		/**
		 * �Ƴ��׽���ID
		 */
		void removeSocket(int socketID);
	};

	/*
	* �����SOCKET����
	*/
	class FCServerService{
	protected:
		/*
		* ѹ������
		*/
		int m_compressType;
		/**
		 * ѹ�����ͼ���
		 */
		map<int, int> m_compressTypes;
		/**
		 * ��ID
		 */
		int m_groupID;
		/**
		 * �����߼���
		 */
		map<int, FCMessageListener*> m_listeners;
		/**
		 * �����ID
		 */
		int m_serviceID;
		/**
		 * ��¼ID
		 */
		int m_sessionID;
		/**
		 * �ȴ���Ϣ����
		 */
		map<int, FCMessage*> m_waitMessages;
	protected:
		FCLock m_lock;
	public:
		/**
		* �ر�
		* @param  socketID  ����ID
		*/
		static int closeServer(int socketID);
		/**
		* ע��ص�
		* @param  callBack  �ص�����
		*/
		static void registerCallBack(MessageCallBack callBack);
		/**
		* ע����־
		* @param  callBack  �ص�����
		*/
		static void registerLog(WriteLogCallBack callBack);
		/**
		* ������Ϣ
		* @param  socketID  ����ID
		* @param  str  ����
		* @param  len  ����
		*/
		static int sendByServer(int socketID, const char *str, int len);
		/**
		* ����
		* @param  port  �˿�
		*/
		static int startServer(int type, int port);
	public:
		FCServerService();
		virtual ~FCServerService();
		/**
		 * ��ȡѹ������
		 */
		int getCompressType();
		/**
		 * ����ѹ������
		 */
		void setCompressType(int compressType);
		/**
		 * ��ȡ��������
		 */
		static Long getDownFlow();
		/**
		 * ������������
		 */
		static void setDownFlow(Long downFlow);
		/**
		 * ��ȡ��ID
		 */
		int getGroupID();
		/**
		 * ������ID
		 */
		void setGroupID(int groupID);
		/**
		 * ��ȡ�����ID
		 */
		int getServiceID();
		/**
		 * ���÷����ID
		 */
		void setServiceID(int serviceID);
		/**
		 * ��ȡ��¼ID
		 */
		int getSessionID();
		/**
		 * ���õ�¼ID
		 */
		void setSessionID(int sessionID);
		/**
		 * ��ȡ�ϴ�����
		 */
		static Long getUpFlow();
		/**
		 * �����ϴ�����
		 */
		static void setUpFlow(Long upFlow);
	public:
		/**
		* ��ӷ���
		* @param  service  ����
		*/
		static void addService(FCServerService *service);
		/*
		* ���ݻص�
		*/
		static void __stdcall callBack(int socketID, int localSID, const char *str, int len);
		/**
		 * ��ȡ����ID
		 */
		static int getRequestID();
		/**
		* ��ȡ���еķ���
		* @param  service  ����
		*/
		static void getServices(vector<FCServerService*> *services);
		/**
		* ���ֻ�Ծ
		* @param  socketID  �׽���ID
		*/
		virtual int keepAlive(int socketID);
		/**
		* �յ���Ϣ
		* @param  br  ��
		* @param  socketID  �׽���ID
		* @param  localSID  �����׽���ID
		* @param  len  ����
		*/
		virtual void onCallBack(FCBinary *binary, int socketID, int localSID, int len);
		/**
		* �ͻ��˹رշ���
		* @param  socketID  ����ID
		* @param  localSID  ��������ID
		*/
		virtual void onClientClose(int socketID, int localSID);
		/**
		* ��������
		* @param  message  ��Ϣ
		*/
		virtual void onReceive(FCMessage *message);
		/**
		 * �ȴ���Ϣ�Ĵ���
		 */
		virtual void onWaitMessageHandle(FCMessage *message);
		/**
		 * ע�����ݼ���
		 */
		virtual void registerListener(int requestID, ListenerMessageCallBack callBack, Object pInvoke);
		/**
		 * ע��ȴ�
		 */
		virtual void registerWait(int requestID, FCMessage *message);
		/**
		 * ������Ϣ
		 */
		virtual int send(FCMessage *message);
		/**
		 * ���͵�������
		 */
		virtual void sendToListener(FCMessage *message);
		/**
		 * ȡ��ע�����ݼ���
		 */
		virtual void unRegisterListener(int requestID);
		/**
		 * ȡ��ע�����
		 */
		virtual void unRegisterListener(int requestID, ListenerMessageCallBack callBack);
		/**
		 * ȡ��ע��ȴ�
		 */
		virtual void unRegisterWait(int requestID);
		/**
		 * �ȴ���Ϣ
		 */
		virtual int waitMessage(int requestID, int timeout);
		/**
		* д��־
		* @param  socketID  ����ID
		* @param  localSID  ��������ID
		* @param  state  ״̬
		* @param  log  ��־
		*/
		static void __stdcall writeServerLog(int socketID, int localSID, int state, const char *log);
	};
}

#endif