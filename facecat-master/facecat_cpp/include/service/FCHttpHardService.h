/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __FCHTTPHARDSERVICE_H__
#define __FCHTTPHARDSERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include <string>
#include <map>
#include "FCServerService.h"

#define SERVICEID_HTTPHARD 20
#define FUNCTIONID_HTTPHARD_TEST 0

namespace FaceCat{
    /**
	 * HTTP����
	 */
	class FCHttpHardService:FCServerService{
	private:
	public:
	    /**
		 * ����HTTP����
		 */
		FCHttpHardService();
		/*
		* ��������
		*/
		virtual ~FCHttpHardService();
	public:
		/**
		* ��������
		* @param  message  ��Ϣ
		*/
		virtual void onReceive(FCMessage *message);
		/**
		* ������Ϣ
		* @param  message  ��Ϣ
		*/
		int send(FCMessage *message);
	};
}

#endif