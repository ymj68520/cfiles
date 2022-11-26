/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __FCRADIOBUTTON_H__
#define __FCRADIOBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "FCCheckBox.h"

namespace FaceCat{
    /**
     * ��ѡ��ؼ�
     */
	class FCRadioButton:public FCCheckBox{
	protected:
		/*
		* ������
		*/
		String m_groupName;
	public:
		/*
		* ���캯��
		*/
		FCRadioButton();
		/*
		* ��������
		*/
		virtual ~FCRadioButton();
		/**
	     * ��ȡ����
	     */
		virtual String getGroupName();
		/**
	     * ��������
	     */
		virtual void setGroupName(const String& groupName);
	public:
	    /**
	     * ��ȡ�ؼ�����
	     */
		virtual String getControlType();
	    /**
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ��������ֵ
         * @param type  ������������
        */
		virtual void getProperty(const String& name, String *value, String *type);
		/**
	     * ��ȡ���������б�
	     */
		virtual ArrayList<String> getPropertyNames();
		/**
	     * �������
	     */
		virtual void onClick(FCTouchInfo touchInfo);
	    /**
         * �ػ�ѡ�а�ť����
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintCheckButton(FCPaint *paint, const FCRect& clipRect);
	    /**
         * ��������
         * @param name    ��������
         * @param value   ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
		/**
	     * ���²��ַ���
	     */
		virtual void update();
	};
}

#endif