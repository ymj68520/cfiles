/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CROSSLINETIP_H__
#define __CROSSLINETIP_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* ʮ������ʾ��
	*/
	class CrossLineTip{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * X����ʾ�򱳾�ɫ
	     */
		Long m_backColor;
		/**
	     * X����ʾ�����ֵ�����
	     */
		FCFont *m_font;
		/**
	     * X����ʾ������ɫ
	     */
		Long m_textColor;
		/**
	     * �Ƿ�ɼ�
	     */
		bool m_visible;
	public:
		CrossLineTip();
		virtual ~CrossLineTip();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡX����ʾ�򱳾�ɫ
	     */
		virtual Long getBackColor();
		/**
	     * ����X����ʾ�򱳾�ɫ
	     */
		virtual void setBackColor(Long backColor);
		/**
	     * ��ȡX����ʾ�����ֵ�����
	     */
		virtual FCFont* getFont();
		/**
	     * ����X����ʾ�����ֵ�����
	     */
		virtual void setFont(FCFont *font);
		/**
	     * ��ȡX����ʾ������ɫ
	     */
		virtual Long getTextColor();
		/**
	     * ����X����ʾ������ɫ
	     */
		virtual void setTextColor(Long textColor);
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
          * ��ȡ����ֵ
          * @param name  ��������
          * @param value ��������ֵ
          * @param type  ������������
         */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/**
	     * ��ȡ���������б�
	     */
		virtual void getProperty(const String& name, String *value, String *type);
	    /**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param div    ͼ��
         * @param rect   ����
        */
		virtual ArrayList<String> getPropertyNames();
	    /**
         * ��������ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};
}
#endif