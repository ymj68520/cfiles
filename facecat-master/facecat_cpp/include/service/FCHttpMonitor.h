/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __FCHTTPMONITOR_H__
#define __FCHTTPMONITOR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCBinary.h"
#include <string>
#include <map>
#pragma comment(lib, "ws2_32.lib")
#include "winsock2.h"
#include "FCHttpEasyService.h"
using namespace std;

namespace FaceCat
{
	class FCHttpEasyService;

    /**
	 * Http����
	 */
	class FCHttpData
	{
	public:
	    /**
		 * �ļ�Http����
		 */
		FCHttpData();
		/*
		* ��������
		*/
		~FCHttpData();
		SOCKADDR_IN m_addr;
		char *m_body;
        bool m_close;
		int m_contentLength;
        String m_contentType;
        String m_method;
		map<String, String> m_parameters;
		String m_remoteIP;
        int m_remotePort;
		char* m_resBytes;
		int m_resBytesLength;
		String m_resStr;
		SOCKET m_socket;
		int m_statusCode;	
        String m_url;
	};

	/*
	* HTTP����
	*/
	class FCHttpMonitor
	{
	public:
		SOCKADDR_IN m_addr;
		/**
		 * �ļ�����
		 */
		string m_fileName;
		/*
		* �׽���
		*/
		SOCKET m_hSocket;
		/**
		 * ���ݼ���
		 */
		map<int, FCHttpData*> m_httpDatas;
		/**
		 * �ű�����
		 */
		stack<FCScript*> m_indicators;
		/**
		 * ���ű�
		 */
		FCScript *m_indicator;
		/*
		* ȫ����
		*/
		FCLock m_lock;
		/*
		* HTTP��
		*/
		FCLock m_lockHttpData;
		/**
		 * XML����
		 */
		FCNative *m_native;
		/**
		 * �˿�
		 */
		int m_port;
		/**
		 * �ű�
		 */
		String m_script;
		/**
		 * ʹ�ýű�
		 */
		bool m_useScript;
	public:
		/*
		* ���캯��
		*/
		FCHttpMonitor(string fileName);
		/*
		* ��������
		*/
		virtual ~FCHttpMonitor();
		/*
		* ��ȡ�򵥷���
		*/
		static FCHttpEasyService* getEasyService(const String& name);
		/**
		 * ��ȡ���ű�
		 */
		FCScript* getIndicator();
		/**
		 * ��ȡ��������
		 */
		static FCHttpMonitor* getMainMonitor();
		/**
		 * ��ȡXML����
		 */
		FCNative* getNative();
		/**
		 * ��ȡ�˿�
		 */
		int getPort();
		/**
		 * ���ö˿�
		 */
		void setPort(int port);
		/**
		 * ��ȡ�ű�
		 */
		String getScript();
		/**
		 * ���ýű�
		 */
		void setScript(String script);
		/*
		* ��ȡ�׽���
		*/
		SOCKET getSocket();
		/**
		 * �Ƿ�ʹ�ýű�
		 */
		bool getUseScript();
		/*
		* ����HTTP����
		*/
		void setHttpData(int socketID, FCHttpData *data);
		/*
		* ����ָ��
		*/
		FCScript* popCIndicator();
	public:
	    /**
		 * ���ű�
		 */
		void checkScript();
		/*
		* �رշ���
		*/
		int close(int socketID);
		/**
		 * ��������
		 */
		int start(string fileName);
	};
}

#endif