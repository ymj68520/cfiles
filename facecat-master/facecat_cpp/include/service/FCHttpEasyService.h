/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCHTTPEASYSERVICE_H__
#define __FCHTTPEASYSERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"

using namespace std;

namespace FaceCat{
	class FCHttpData;

	/*
	* �򵥵�HTTP����
	*/
	class FCHttpEasyService{
	public:
	    /**
		 * HTTP��GET����
		 */
		FCHttpEasyService();
		/*
		* ɾ������
		*/
		virtual ~FCHttpEasyService();
	public:
		/**
		* ��������
		* @param  data  ��������
		*/
		virtual void onReceive(FCHttpData* data);
	};
}

#endif