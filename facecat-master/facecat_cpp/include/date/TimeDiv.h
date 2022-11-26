/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __TIMEDIV_H__
#define __TIMEDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCCalendar.h"
#include "..\\input\\FCSpin.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* ʱ���
	*/
	class TimeDiv{
	protected:
		/*
		* ѡ��ʱ��ı��¼�
		*/
		static void selectedTimeChanged(Object sender, Object pInvoke);
	protected:
	    /**
		 * �����ؼ�
		 */
		FCCalendar *m_calendar;
		/**
		 * �߶�
		 */
		int m_height;
		/**
		 * Сʱ
		 */
		FCSpin *m_spinHour;
		/**
		 * ����
		 */
		FCSpin *m_spinMinute;
		/**
		 * ��
		 */
		FCSpin *m_spinSecond;
	protected:
	    /**
		 * ��ȡ���Ƶı���ɫ
		 */
		virtual Long getPaintingBackColor();
		/**
		 * ��ȡ���Ƶı�����ɫ
		 */
		virtual Long getPaintingBorderColor();
		/**
		 * ��ȡҪ���Ƶ�ǰ��ɫ
		 */
		virtual Long getPaintingTextColor();
	public:
		/*
		* ���캯��
		*/
		TimeDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~TimeDiv();
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ�����ø߶�
		 */
		virtual int getHeight();
		/**
		 * ��ȡ�����ø߶�
		 */
		virtual void setHeight(int height);
		/**
		 * ��ȡ������Сʱ
		 */
		virtual int getHour();
		/**
		 * ��ȡ������Сʱ
		 */
		virtual void setHour(int hour);
		/**
		 * ��ȡ�����÷���
		 */
		virtual int getMinute();
		/**
		 * ��ȡ�����÷���
		 */
		virtual void setMinute(int minute);
		/**
		 *��ȡ��
		 */
		virtual int getSecond();
		/**
		 * ������
		 */
		virtual void setSecond(int second);
	public:
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
		 * ��ֵ�޸��¼�
		 */
		void onSelectedTimeChanged();
		/**
		 * ���������
		 */
		void onTimer();
		/**
		 * ���²��ַ���
		 */
		void update();
	};
}
#endif