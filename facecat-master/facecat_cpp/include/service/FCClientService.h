/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCLIENTSERVICE_H__
#define __FCCLIENTSERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include "FCServerService.h"
#include <string>
#include <map>
using namespace std;

#define  DOWNHELPER_AGENTNAME         "SECURITY"  
#define  LEN_OF_BUFFER_FOR_QUERYINFO  128  
#define  MAX_DOWNLOAD_REQUEST_TIME    10   

namespace FaceCat{
	/*
	* �ͻ���SOCKET����
	*/
	class FCClientService{
	private:
		FCLock m_lock;
		/**
		 * ѹ������
		 */
		int m_compressType;
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
	public:
		/**
		* �ر�
		* @param  socketID  ����ID
		*/
		static int closeClient(int socketID);
		/**
		* ����
		* @param  proxyType  ��������
		* @param  ip  ��ַ
		* @param  port  �˿�
		* @param  proxyIp  �����ַ
		* @param  proxyPort  ����˿�
		* @param  proxyUserName  ��������
		* @param  proxyUserPwd  ��������
		* @param  proxyDomain  ������
		* @param  timeout  ��ʱ
		*/
		static int connectToServer(int type, int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout);
		/**
		 * ע��ص�
		 */
		static void registerCallBack(MessageCallBack callBack);
		/**
		 * ע����־
		 */
		static void registerLog(WriteLogCallBack callBack);
		/**
		* ������Ϣ
		* @param  socketID  ����ID
		* @param  str   ����
		* @param  len  ����
		*/
		static int sendByClient(int socketID, const char *str, int len);
	public:
		/*
		* ���캯��
		*/
		FCClientService();
		/*
		* ��������
		*/
		virtual ~FCClientService();
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
		static void addService(FCClientService *service);
		/**
		* �ص�����
		* @param  socketID  ����ID
		* @param  localSID  ��������ID
		* @param  str  ����
		* @param  len  ����
		*/
		static void __stdcall callBack(int socketID, int localSID, const char *str, int len);
		/**
		 * ��ȡ����ID
		 */
		static int getRequestID();
		/**
		 * ��ȡ���еķ���
		 */
		static void getServices(vector<FCClientService*> *services);
		/**
		 * ���ֻ�Ծ
		 */
		int keepAlive(int socketID);
		/**
		 * �յ���Ϣ
		 */
		virtual void onCallBack(FCBinary *binary, int socketID, int localSID, int len);
		/**
		 * ��������
		 */
		virtual void onReceive(FCMessage *message);
		/**
		 * �ȴ���Ϣ�Ĵ���
		 */
		virtual void onWaitMessageHandle(FCMessage *message);
		/**
		* ע�����ݼ���
		* @param  requestID ����ID
		* @param  callBack  �ص�����
		*/
		void registerListener(int requestID, ListenerMessageCallBack callBack, Object pInvoke);
		/**
		 * ע��ȴ�
		 */
		void registerWait(int requestID, FCMessage *message);
		/**
		 * ������Ϣ
		 */
		int send(FCMessage *message);
		/**
		 * ���͵�������
		 */
		void sendToListener(FCMessage *message);
		/**
		 * ȡ��ע�����ݼ���
		 */
		void unRegisterListener(int requestID);
		/**
		 * ȡ��ע�����
		 */
		void unRegisterListener(int requestID, ListenerMessageCallBack callBack);
		/**
		 * ȡ��ע��ȴ�
		 */
		void unRegisterWait(int requestID);
		/**
		 * �ȴ���Ϣ
		 */
		int waitMessage(int requestID, int timeout);
	};
}
#endif