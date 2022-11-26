/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCDATETIMEPICKER_H__
#define __FCDATETIMEPICKER_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"
#include "..\\date\\FCCalendar.h"

namespace FaceCat{
	/*
	* ����ѡ��ؼ�
	*/
	class FCDateTimePicker : public FCTextBox{
	protected:
	    /**
		 * ��ȡ����
		 */
		FCCalendar *m_calendar;
		/**
		 * ���ڸ�ʽ
		 */
		String m_customFormat;
		/**
		 * ������ť
		 */
		FCButton *m_dropDownButton;
		/**
		 * ������ť�������ָ��
		 */
		FCTouchEvent m_dropDownButtonTouchDownEvent;
		/**
		 * �����˵�
		 */
		FCMenu *m_dropDownMenu;
		/**
		 * ѡ�����ڸı亯��ָ��
		 */
		FCEvent m_selectedTimeChangedEvent;
		/**
		 * �Ƿ���ʾʱ��
		 */
		bool m_showTime;
		/**
		 * ������ť�������ָ��
		 */
		static void dropDownButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ѡ�����ڸı亯��ָ��
		 */
		static void selectedTimeChanged(Object sender, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCDateTimePicker();
		/*
		* ��������
		*/
		virtual ~FCDateTimePicker();
		/**
		 * ��ȡ����
		 */
		virtual FCCalendar* getCalendar();
		/**
		 * ��ȡ���ڸ�ʽ
		 */
		virtual String getCustomFormat();
		/**
		 * �������ڸ�ʽ
		 */
		virtual void setCustomFormat(const String& customFormat);
		/**
		 * ��ȡ������ť
		 */
		virtual FCButton* getDropDownButton();
		/**
		 * ��ȡ�����˵�
		 */
		virtual FCMenu* getDropDownMenu();
		/**
		 * ��ȡ�Ƿ���ʾʱ��
		 */
		virtual bool showTime();
		/**
		 * �����Ƿ���ʾʱ��
		 */
		virtual void setShowTime(bool showTime);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getPropertyNames();
		/**
		 * �����˵���ʾ����
		 */
		virtual void onDropDownOpening();
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ��ֵ�ı䷽��
		 */
		virtual void onSelectedTimeChanged();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}

#endif