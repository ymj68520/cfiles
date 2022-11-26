/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __HEADDIV_H__
#define __HEADDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "FCCalendar.h"
#include "DateTitle.h"

namespace FaceCat{
	class ArrowButton;
	class DateTitle;

	/*
	* ͷ����
	*/
	class HeadDiv:public FCView{
	protected:
	    /**
		 * ����
		 */
		FCCalendar *m_calendar;
		/**
		 * ���ڱ���
		 */
		DateTitle *m_dateTitle;
		/**
		 * �ϸ����ڵİ�ť
		 */
		ArrowButton *m_lastBtn;
		/**
		 * �¸����ڵİ�ť
		 */
		ArrowButton *m_nextBtn;
		/*
		* ��������
		*/
		String m_weekStrings[7];
	public:
		/*
		* ���캯��
		*/
		HeadDiv(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~HeadDiv();
		/**
		 * ��ȡ����
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ��������
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ���ڱ���
		 */
		virtual DateTitle* getDateTitle();
		/**
		 * �������ڱ���
		 */
		virtual void setDateTitle(DateTitle *dateTitle);
		/**
		 * ��ȡ���ϸ����ڵİ�ť
		 */
		virtual ArrowButton* getLastBtn();
		/**
		 * ���õ��ϸ����ڵİ�ť
		 */
		virtual void setLastBtn(ArrowButton *lastBtn);
		/**
		 * ��ȡ���¸����ڵİ�ť
		 */
		virtual ArrowButton* getNextBtn();
		/**
		 * ���õ��¸����ڵİ�ť
		 */
		virtual void setNextBtn(ArrowButton *nextBtn);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		* �ػ汳������
		* @param  paint   ��ͼ����
		* @param  clipRect   �ü�����
		*/
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
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
		/**
		 * ���ָ��·���
		 */
		virtual void update();
	};
}

#endif