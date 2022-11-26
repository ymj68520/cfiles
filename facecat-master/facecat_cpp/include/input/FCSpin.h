/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSPIN_H__
#define __FCSPIN_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	/*
	* ��ֵѡ��
	*/
	class FCSpin : public FCTextBox{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
		/**
		 * TICKֵ
		 */
		int m_tick;
	protected:
	    /**
		 * �Ƿ��Զ���ʽ��
		 */
		bool m_autoFormat;
		/**
		 * ����С����λ��
		 */
		int m_digit;
		/**
		 * ���°�ť
		 */
		FCButton *m_downButton;
		/*
		* ������ť������������¼�
		*/
		FCTouchEvent m_downButtonTouchDownEvent;
		/*
		* ������ť�������̧���¼�
		*/
		FCTouchEvent m_downButtonTouchUpEvent;
		/**
		 * �Ƿ���������
		 */
		bool m_isAdding;
		/**
		 * �Ƿ����ڼ���
		 */
		bool m_isReducing;
		/**
		 * ���ֵ
		 */
		double m_maximum;
		/**
		 * ��Сֵ
		 */
		double m_minimum;
		/**
		 * �Ƿ���ʾǧ��λ
		 */
		bool m_showThousands;
		/**
		 * ��ֵ��������
		 */
		double m_step;
		/**
		 * ��ȡ���ϰ�ť
		 */
		FCButton *m_upButton;
		/**
		 * ���ϰ�ť�Ĵ������º���
		 */
		FCTouchEvent m_upButtonTouchDownEvent;
		/**
		 * ���ϰ�ť�Ĵ���̧����
		 */
		FCTouchEvent m_upButtonTouchUpEvent;
		/**
		 * ���°�ť�Ĵ��������¼�
		 */
		static void downButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ���°�ť�Ĵ���̧���¼�
		 */
		static void downButtonTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ���ϰ�ť�Ĵ��������¼�
		 */
		static void upButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ���ϰ�ť�Ĵ���̧���¼�
		 */
		static void upButtonTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCSpin();
		/*
		* ��������
		*/
		virtual ~FCSpin();
		/**
		 * ��ȡ�Ƿ��Զ���ʽ��
		 */
		virtual bool autoFormat();
		/**
		 * �����Ƿ��Զ���ʽ��
		 */
		virtual void setAutoFormat(bool autoFormat);
		/**
		 * ��ȡ����С����λ��
		 */
		virtual int getDigit();
		/**
		 * ���ñ���С����λ��
		 */
		virtual void setDigit(int digit);
		/**
		 * ��ȡ���°�ť
		 */
		virtual FCButton* getDownButton();
		/**
		 * ��ȡ�Ƿ���������
		 */
		virtual bool isAdding();
		/**
		 * �����Ƿ���������
		 */
		virtual void setIsAdding(bool isAdding);
		/**
		 * ��ȡ�Ƿ����ڼ���
		 */
		virtual bool isReducing();
		/**
		 * �����Ƿ����ڼ���
		 */
		virtual void setIsReducing(bool isReducing);
		/**
		 * ��ȡ���ֵ
		 */
		virtual double getMaximum();
		/**
		 * �������ֵ
		 */
		virtual void setMaximum(double maximum);
		/**
		 * ��ȡ��Сֵ
		 */
		virtual double getMinimum();
		/**
		 * ������Сֵ
		 */
		virtual void setMinimum(double minimum);
		/**
		 * ��ȡ�Ƿ���ʾǧ��λ
		 */
		virtual bool showThousands();
		/**
		 * �����Ƿ���ʾǧ��λ
		 */
		virtual void setShowThousands(bool showThousands);
		/**
		 * ��ȡ��ֵ��������
		 */
		virtual double getStep();
		/**
		 * ������ֵ��������
		 */
		virtual void setStep(double step);
		/**
		 * �����ı�
		 */
		virtual void setText(const String& text);
		/**
		 * ��ȡ���ϰ�ť
		 */
		virtual FCButton* getUpButton();
		/**
		 * ��ȡ������ֵ
		 */
		virtual double getValue();
		/**
		 * ���õ�����ֵ
		 */
		virtual void setValue(double value);
	public:
	    /**
		 *
		 * ����ָ�����ȵ���ֵ
		 */
		void add();
		/**
		 * ���ı�ת��Ϊǧ��λ��ʾ
		 */
		String formatNum(String inputText);
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
		 * ���ݱ���С����λ�ý�double��ת��ΪString��
		 */
		String getValueByDigit(double value, int digit);
		/**
		 * �������ַ���
		 */
		virtual void onChar(wchar_t ch);
		/**
		 * ���̰��·���
		 */
		virtual void onKeyDown(char key);
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ������������
		 */
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * ճ������
		 */
		virtual void onPaste();
		/**
		 * ����¼�
		 */
		virtual void onTimer(int timerID);
		/**
		 * ��ֵ�ı䷽��
		 */
		virtual void onValueChanged();
		/**
		 * ����ָ�����ȵ���ֵ
		 */
		void reduce();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ��������
		 */
		void setRegion();
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}

#endif