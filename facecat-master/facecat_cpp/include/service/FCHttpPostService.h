/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCHTTPPOSTSERVICE_H__
#define __FCHTTPPOSTSERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCClientService.h"

namespace FaceCat{
	/*
	* Post����
	*/
	class FCHttpPostService : public FCClientService{
	private:
	    /**
		 * �Ƿ�ͬ������
		 */
		bool m_isSyncSend;
		/*
		* ��
		*/
        FCLock m_lock;
        /**
		 * ��ַ
		 */
		string m_url;
		/**
		 * Timeoutʱ��
		 */
		int m_timeout;
	public:
		ArrayList<FCMessage*> m_messages;
		/**
		 * ����HTTP����
		 */
		FCHttpPostService();
		/*
		* ��������
		*/
		virtual ~FCHttpPostService();
		/**
		 * ��ȡ�Ƿ�ͬ������
		 */
		bool isSyncSend();
		/**
		 * �����Ƿ�ͬ������
		 */
        void setIsSyncSend(bool isSyncSend);
		/*
		* ��ȡ��
		*/
        FCLock getLock();
        /**
		 * ��ȡTimeoutʱ��
		 */
		int getTimeout();
		/**
		 * ����Timeoutʱ��
		 */
		void setTimeout(int timeout);
		/**
		 * ��ȡ��ַ
		 */
		string getUrl();
		/**
		 * ���õ�ַ
		 */
		void setUrl(string url);
	public:
	    /**
		 * �첽��������
		 */
		static DWORD WINAPI asynSend(LPVOID lpParam);
	public:
		/**
		* ��������
		* @param  message  ��Ϣ
		*/
		virtual void onReceive(FCMessage *message);
		/**
		* ����POST����
		* @param  url  ��ַ
		* @param  data  ����
		*/
		String post(const String& url);
		/*
		* ����POST����
		*/
		string post(const String& url, char *sendDatas, int sendSize);
		/*
		* ����POST����
		*/
		String post(const String& url, const String &data);
		/*
		* ��������
		*/
		int send(FCMessage *message);
		/**
		* ����POST����
		* @param  message  ��Ϣ
		*/
		int sendRequest(FCMessage *message);
	};
}
#endif