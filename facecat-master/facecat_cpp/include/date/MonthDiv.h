/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __MONTHDIV_H__
#define __MONTHDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "MonthButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"
#include "FCCalendar.h"

namespace FaceCat{
	class MonthButton;
	class HeadDiv;
	class FCCalendar;
	class TimeDiv;

	/*
	* �µĲ�
	*/
	class MonthDiv{
	protected:
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
		/**
		 * ���
		 */
		int m_year;
	public:
	    /**
		 * �µİ�ť
		 */
		ArrayList<MonthButton*> m_monthButtons;
		/**
		 * �µĶ�����ť
		 */
		ArrayList<MonthButton*> m_monthButtons_am;
	public:
		/*
		* ���캯��
		*/
		MonthDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~MonthDiv();
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ���
		 */
		virtual int getYear();
	public:
	    /**
		 * ����
		 */
		virtual void hide();
		/**
		* �����������
		* @param  mp   ����
		* @param  button   ��ť
		* @param  clicks   �������
		* @param  delta   ������
		*/
		void onClick(FCTouchInfo touchInfo);
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		* �ػ淽��
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		void onPaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������ͼ��
		* @param  state   ״̬
		*/
		void onResetDiv(int state);
		/**
		 * ���������
		 */
		virtual void onTimer();
		/**
		* ѡ�����
		* @param  year   ���
		*/
		virtual void selectYear(int year);
		/**
		 * ��ʾ
		 */
		virtual void show();
		/**
		 * ���²��ַ���
		 */
		void update();
	};
}
#endif