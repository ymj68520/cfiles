/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __ARROWBUTTON_H__
#define __ARROWBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"
#include "YearDiv.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* ��ͷ��ť
	*/
	class ArrowButton:public FCButton{
	protected:
	    /**
		 * �����ؼ�
		 */
		FCCalendar *m_calendar;
		/**
		 * �Ƿ�ǰ���ϸ���
		 */
		bool m_toLast;
	public:
		/*
		* ���캯��
		*/
		ArrowButton(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~ArrowButton();
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ�Ƿ�ǰ���ϸ���
		 */
		virtual bool isToLast();
		/**
		 * �����Ƿ�ǰ���ϸ���
		 */
		virtual void setToLast(bool toLast);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
    	/**
    		* ��������¼�
    		* @param  touchInfo   ������Ϣ
    	*/
		virtual void onClick(FCTouchInfo touchInfo);
    	/**
    		* �ػ汳������
    		* @param  paint   ��ͼ����
    		* @param  clipRect   �ü�����
    	*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}
#endif