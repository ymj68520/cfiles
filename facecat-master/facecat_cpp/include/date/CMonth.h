/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CMONTH_H__
#define __CMONTH_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"

namespace FaceCat{
	/*
	* ��
	*/
	class CMonth{
	protected:
	    /**
		 * ������
		 */
		int m_month;
		/**
		 * ������
		 */
		int m_year;
		/*
		* ��������
		*/
		void createDays();
	public:
		/**
		* ������
		* @param  year   ��
		* @param  month  ��
		*/
		CMonth(int year, int month);
		/*
		* ��������
		*/
		virtual ~CMonth();
		/*
		* �յļ���
		*/
		HashMap<int, CDay*> m_days;
		/**
		 * ��ȡ�µ�����
		 */
		int getDaysInMonth();
		/**
		 * ��ȡ���µĵ�һ��
		 */
		CDay* getFirstDay();
		/**
		 * ��ȡ���µ����һ��
		 */
		CDay* getLastDay();
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