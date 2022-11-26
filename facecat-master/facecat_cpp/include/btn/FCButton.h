/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCBUTTON_H__
#define __FCBUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"

namespace FaceCat{
	/**
     * ��ť�ؼ�
     */
	class FCButton:public FCView{
	protected:
		/**
		* ������ʱ�ı���ͼƬ
		*/
		String m_disabledBackImage;
		/**
		* ������ͣʱ�ı���ͼƬ
		*/
		String m_hoveredBackImage;
		/**
		* ��������ʱ�ı���ͼƬ
		*/
		String m_pushedBackImage;
		/**
		* �������з�ʽ
		*/
		FCContentAlignment m_textAlign;
	protected:
	    /**
	     * ��ȡҪ���Ƶı���ɫ
	     */
		virtual Long getPaintingBackColor();
		/**
	     * ��ȡ���ڻ��Ƶı���ͼƬ
	     */
		virtual String getPaintingBackImage();
	public:
		/*
		* ���캯��
		*/
		FCButton();
		/*
		* ��������
		*/
		virtual ~FCButton();
		/**
	     * ��ȡ������ʱ�ı���ͼƬ
	     */
		virtual String getDisabledBackImage();
		/**
	     * ���ò�����ʱ�ı���ͼƬ
	     */
		virtual void setDisabledBackImage(const String& disabledBackImage);
		/**
	     * ��ȡ������ͣʱ�ı���ͼƬ
	     */
		virtual String getHoveredBackImage();
		/**
	     * ���ô�����ͣʱ�ı���ͼƬ
	     */
		virtual void setHoveredBackImage(const String& hoveredBackImage);
		/**
	     * ��ȡ��������ʱ�ı���ͼƬ
	     */
		virtual String getPushedBackImage();
		/**
	     * ���ô�������ʱ�ı���ͼƬ
	     */
		virtual void setPushedBackImage(const String& pushedBackImage);
		/**
	     * ��ȡ���ֵĲ��ַ�ʽ
	     */
		virtual FCContentAlignment getTextAlign();
		/**
	     * �������ֵĲ��ַ�ʽ
	     */
		virtual void setTextAlign(FCContentAlignment textAlign);
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
         * �������·���
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchDown(FCTouchInfo touchInfo);
	    /**
         * �������뷽��
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
	    /**
         * �����뿪����
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * ����̧�𷽷�
         * @param touchInfo ������Ϣ
         */
		virtual void onTouchUp(FCTouchInfo touchInfo);
	    /**
         * �ػ�ǰ������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
         */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * ��������
         * @param name  ��������
         * @param value ����ֵ
         */
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif