/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __DATETITLE_H__
#define __DATETITLE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* ����������
	*/
	class DateTitle : public FCButton{
	protected:
		FCCalendar *m_calendar;
	public:
		/**
		 * ���ڱ���
		 */
		DateTitle(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~DateTitle();
		/**
		 * ��ȡ����
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ��������
		 */
		virtual void setCalendar(FCCalendar *calendar);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		* �����������
		* @param  mp   ����
		* @param  button   ������ť
		* @param  clicks   �������
		* @param  delta   ����ֵ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* �ػ�ǰ������
		* @param  paint ��ͼ����
		* @param  clipRect  	�ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}
#endif