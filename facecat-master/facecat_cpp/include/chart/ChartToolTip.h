/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __CHARTTOOLTIP_H__
#define __CHARTTOOLTIP_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* ��ʾ��
	*/
	class ChartToolTip : public FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ��ʾ��ı���ɫ
	     */
		Long m_backColor;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_borderColor;
		/**
	     * ��ʾ�������
	     */
		FCFont *m_font;
		/**
	     * ��ʾ���������ɫ
	     */
		Long m_textColor;
	public:
		ChartToolTip();
		/*
		* ��������
		*/
		virtual ~ChartToolTip();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡ��ʾ��ı���ɫ
	     */
		virtual Long getBackColor();
		/**
	     * ������ʾ��ı���ɫ
	     */
		virtual void setBackColor(Long backColor);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		virtual Long getBorderColor();
		/**
	     * ���ñ��ߵ���ɫ
	     */
		virtual void setBorderColor(Long borderColor);
		/**
	     * ��ȡ��ʾ�������
	     */
		virtual FCFont* getFont();
		/**
	     * ������ʾ�������
	     */
		virtual void setFont(FCFont *font);
		/**
	     * ��ȡ��ʾ���������ɫ
	     */
		virtual Long getTextColor();
		/**
	     * ������ʾ���������ɫ
	     */
		virtual void setTextColor(Long textColor);
	public:
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
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param div    ͼ��
         * @param rect   ����
        */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
	    /**
         * ��������ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};
}
#endif