/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __MONTHBUTTON_H__
#define __MONTHBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

	/*
	* �µİ�ť
	*/
	class MonthButton:public FCButton{
	protected:
	    /**
		 * ��ʾ����
		 */
		FCRect m_bounds;
		/**
		 * �����ؼ�
		 */
		FCCalendar *m_calendar;
		/**
		 * ��
		 */
		int m_month;
		/**
		 * �Ƿ�ɼ�
		 */
		bool m_visible;
		/**
		 * ��
		 */
		int m_year;
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
		MonthButton(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~MonthButton();
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ��ʾ����
		 */
		virtual FCRect getBounds();
		/**
		 * ������ʾ����
		 */
		virtual void setBounds(const FCRect& bounds);
		/**
		 * ��ȡ��
		 */
		virtual int getMonth();
		/**
		 * ������
		 */
		virtual void setMonth(int month);
		/**
		 * ��ȡ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * �����Ƿ�ɼ�
		 */
		virtual void setVisible(bool visible);
		/**
		 * ��ȡ��
		 */
		virtual int getYear();
		/**
		 * ������
		 */
		virtual void setYear(int year);
	public:
	    /**
		 * ��ȡ�µ�����
		 */
		virtual String getMonthStr();
		/**
		* �����������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* �ػ汳������
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBackGround(FCPaint *paint, const FCRect& clipRect);
		/**
		* �ػ���߷���
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
		/**
		* �ػ�ǰ������
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	};
}
#endif