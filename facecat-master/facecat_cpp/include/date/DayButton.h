/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __DAYBUTTON_H__
#define __DAYBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "CDay.h"
#include "FCCalendar.h"

namespace FaceCat{
	class FCCalendar;

    /**
	* ���ڰ�ť
	*/
	class DayButton{
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
		 * ���������
		 */
		CDay *m_day;
		/**
		 * �Ƿ��ڱ���
		 */
		bool m_inThisMonth;
		/**
		 * �Ƿ�ѡ��
		 */
		bool m_selected;
		/**
		 * �Ƿ�ɼ�
		 */
		bool m_visible;
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
		DayButton(FCCalendar *calendar);
		/*
		* ��������
		*/
		virtual ~DayButton();
		/**
		 * ��ȡ��ʾ����
		 */
		virtual FCRect getBounds();
		/**
		 * ������ʾ����
		 */
		virtual void setBounds(const FCRect& bounds);
		/**
		 * ��ȡ�����ؼ�
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ���������ؼ�
		 */
		virtual void setCalendar(FCCalendar *calendar);
		/**
		 * ��ȡ���������
		 */
		virtual CDay* getDay();
		/**
		 * ���ñ��������
		 */
		virtual void setDay(CDay *day);
		/**
		 * ��ȡ�Ƿ��ڱ���
		 */
		virtual bool inThisMonth();
		/**
		 * �����Ƿ��ڱ���
		 */
		virtual void setThisMonth(bool inThisMonth);
		/**
		 * ��ȡ�Ƿ�ѡ��
		 */
		virtual bool isSelected();
		/**
		 * �����Ƿ�ѡ��
		 */
		virtual void setSelected(bool selected);
		/**
		 * ��ȡ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * �����Ƿ�ɼ�
		 */
		virtual void setVisible(bool visible);
	public:
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