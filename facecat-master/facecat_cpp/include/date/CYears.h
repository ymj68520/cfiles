/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CYEARS_H__
#define __CYEARS_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "CYear.h"

namespace FaceCat{
	/*
	* ��ļ���
	*/
	class CYears{
	public:
	    /**
		 * ����
		 */
		CYears();
		virtual ~CYears();
		/**
		 * ��ļ���
		 */
		HashMap<int,CYear*> Years;
		/**
		* ��ȡ��
		* @param  year ���
		*/
		CYear* getYear(int year);
	};
}

#endif