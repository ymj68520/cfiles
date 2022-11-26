/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCALENDAR_H__
#define __FCCALENDAR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "CYears.h"
#include "CMonth.h"
#include "ArrowButton.h"
#include "DateTitle.h"
#include "DayButton.h"
#include "DayDiv.h"
#include "HeadDiv.h"
#include "MonthButton.h"
#include "MonthDiv.h"
#include "TimeDiv.h"
#include "YearButton.h"
#include "YearDiv.h"

namespace FaceCat{
	class ArrowButton;
	class DateTitle;
	class DayButton;
	class DayDiv;
	class HeadDiv;
	class MonthButton;
	class MonthDiv;
	class TimeDiv;
	class YearButton;
	class YearDiv;

	/*
	* ����ģʽ
	*/
	enum FCCalendarMode{
		FCCalendarMode_Day, //ѡ����
		FCCalendarMode_Month, //ѡ����
		FCCalendarMode_Year //ѡ����
	};

	/*
	* �����ؼ�
	*/
	class FCCalendar : public FCView{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;;
	protected:
	    /**
		 * ���ڲ�
		 */
		DayDiv *m_dayDiv;
		/**
		 * ͷ����
		 */
		HeadDiv *m_headDiv;
		/**
		 * ������ģʽ
		 */
		FCCalendarMode m_mode;
		/**
		 * ��ǰ���·�
		 */
		int m_month;
		/**
		 * �·ݲ�
		 */
		MonthDiv *m_monthDiv;
		/**
		 * ѡ������
		 */
		CDay *m_selectedDay;
		/**
		 * ʱ���
		 */
		TimeDiv *m_timeDiv;
		/**
		 * �Ƿ�ʹ�ö���
		 */
		bool m_useAnimation;
		/**
		 * ���
		 */
		int m_year;
		/**
		 * ��ݲ�
		 */
		YearDiv *m_yearDiv;
		/**
		 * ����
		 */
		CYears *m_years;
	public:
		/*
		* ���캯��
		*/
		FCCalendar();
		/*
		* ��������
		*/
		virtual ~FCCalendar();
		/**
		 * ��ȡ���ڲ�
		 */
		virtual DayDiv* getDayDiv();
		/**
		 * �������ڲ�
		 */
		virtual void setDayDiv(DayDiv *dayDiv);
		/**
		 * ��ȡͷ����
		 */
		virtual HeadDiv* getHeadDiv();
		/**
		 * ����ͷ����
		 */
		virtual void setHeadDiv(HeadDiv *headDiv);
		/**
		 * ��ȡ������ģʽ
		 */
		virtual FCCalendarMode getMode();
		/**
		 * ����������ģʽ
		 */
		virtual void setMode(FCCalendarMode mode);
		/**
		 * ��ȡ�·�
		 */
		virtual CMonth* getMonth();
		/**
		 * �����·�
		 */
		virtual void setMonth(CMonth *month);
		/**
		 * ��ȡ�·ݲ�
		 */
		virtual MonthDiv* getMonthDiv();
		/**
		 * �����·ݲ�
		 */
		virtual void setMonthDiv(MonthDiv *monthDiv);
		/**
		 * ��ȡѡ������
		 */
		virtual CDay* getSelectedDay();
		/**
		 * ����ѡ������
		 */
		virtual void setSelectedDay(CDay *day);
		/**
		 * ��ȡʱ���
		 */
		virtual TimeDiv* getTimeDiv();
		/**
		 * ����ʱ���
		 */
		virtual void setTimeDiv(TimeDiv *timeDiv);
		/**
		 * ��ȡ�Ƿ�ʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�ʹ�ö���
		 */
		virtual void setUseAnimation(bool useAnimation);
		/**
		 * ��ȡ��ݲ�
		 */
		virtual YearDiv* getYearDiv();
		/**
		 * ������ݲ�
		 */
		virtual void setYearDiv(YearDiv *yearDiv);
		/**
		 * ��ȡ����
		 */
		virtual CYears* getYears();
		/**
		 * ��������
		 */
		virtual void setYears(CYears *years);
	public:
		/*
		* ��ȡ����
		*/
		int dayOfWeek(int y, int m, int d);
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		* �������»�ȡ�ϸ���
		* @param  year   ��
		* @param  month   ��
		*/
		CMonth* getLastMonth(int year, int month);
		/**
		* ��ȡ�¸���
		* @param  year   ��
		* @param  month   ��
		*/
		CMonth* getNextMonth(int year, int month);
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value  ����ֵ
		* @param  type   ����
		*/
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getPropertyNames();
		/**
		 * �ص��ϸ���
		 */
		void goLastMonth();
		/**
		 * ǰ���¸���
		 */
		void goNextMonth();
		/**
		* �����������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * �ؼ�������¼�
		 */
		virtual void onLoad();
		/**
		* ���̷���
		* @param  key  ����
		*/
		virtual void onKeyDown(char key);
		/**
		* �ػ汳������
		* @param  paint  ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * ѡ�����ڸ��ķ���
		 */
		virtual void onSelectedTimeChanged();
		/**
		* ����¼�
		* @param  timerID  �����
		*/
		virtual void onTimer(int timerID);
		/**
		* ��������ֵ
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���²���
		 */
		virtual void update();
	};
}
#endif