/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __YEARDIV_H__
#define __YEARDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "YearButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
	class FCCalendar;
	class HeadDiv;
	class YearButton;
	class TimeDiv;

	/*
	* ��Ĳ�
	*/
	class YearDiv{
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
		 * ��ʼ���
		 */
		int m_startYear;
	public:
	    /**
		 * �µİ�ť
		 */
		ArrayList<YearButton*> m_yearButtons;
		/**
		 * �µĶ�����ť
		 */
		ArrayList<YearButton*> m_yearButtons_am;
	public:
		/*
		* ���캯��
		*/
		YearDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~YearDiv();
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ��ʼ���
		 */
		virtual int getStartYear();
	public:
	    /**
		 * ����
		 */
		void hide();
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
		* ѡ��ʼ���
		* @param  startYear  ��ʼ���
		*/
		void selectStartYear(int startYear);
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