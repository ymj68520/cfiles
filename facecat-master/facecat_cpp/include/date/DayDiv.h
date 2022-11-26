/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __DAYDIV_H__
#define __DAYDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "DayButton.h"
#include "CYears.h"
#include "CMonth.h"
#include "CDay.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
	class DayButton;
	class HeadDiv;
	class FCCalendar;
	class TimeDiv;
	/**
	 * �������ڲ�
	 */
	class DayDiv{
	protected:
	    /**
		 * ���ʱ�����µ���
		 */
		int m_am_ClickRowFrom;
		/**
		 * ���ʱ�ĵ��µ���
		 */
		int m_am_ClickRowTo;
		/**
		 * �����ķ���
		 */
		int m_am_Direction;
		/**
		 * ������ǰ֡��
		 */
		int m_am_Tick;
		/**
		 * ������֡��
		 */
		int m_am_TotalTick;
		/**
		 * �����ؼ�
		 */
		FCCalendar *m_calendar;
	public:
	    /**
		 * ���ڲ�ļ���
		 */
		ArrayList<DayButton*> m_dayButtons;
		/**
		 * �������ڲ�ļ���
		 */
		ArrayList<DayButton*> m_dayButtons_am;
	public:
		/*
		* ���캯��
		*/
		DayDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~DayDiv();
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
	public:
	    /**
		 * ����
		 */
		void hide();
		/**
		* ��������¼�
		* @param  touchInfo   ������Ϣ
		*/
		void onClick(FCTouchInfo touchInfo);
		/**
		 * ��ӿؼ�����
		 */
		void onLoad();
		/**
		* �ػ淽��
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		void onPaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������ͼ��
		* @param  state  ״̬
		*/
		void onResetDiv(int state);
		/**
		 * ���������
		 */
		void onTimer();
		/**
		* ѡ������
		* @param  selectedDay  ����
		*/
		void selectDay(CDay *selectedDay);
		/**
		 * ��ʾ
		 */
		void show();
		/**
		 * ���²��ַ���
		 */
		void update();
	};
}
#endif