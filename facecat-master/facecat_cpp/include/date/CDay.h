/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CDAY_H__
#define __CDAY_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/**
		* ������
		* @param  year   ��
		* @param  month   ��
		* @param  day   ��
	*/
	class CDay{
	protected:
		int m_day;
		int m_month;
		int m_year;
	public:
		/*
		* ���캯��
		*/
		CDay(int year, int month, int day);
		/*
		* ��������
		*/
		virtual ~CDay();
		/**
		 * ��ȡ��
		 */
		int getDay();
		/**
		 * ��ȡ��
		 */
		int getMonth();
		/**
		 * ��ȡ��
		 */
		int getYear();
	};
}
#endif