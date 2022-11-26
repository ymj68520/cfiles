/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CHARTTITLEBAR_H__
#define __CHARTTITLEBAR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "FCDataTable.h"
#include "Enums.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

	/*
	* ������
	*/
	class ChartTitle : public FCProperty{
	protected:
	    /**
	     * ����С����λ��
	     */
		int m_digit;
		/**
	     * �ֶ�����
	     */
		int m_fieldName;
		/**
	     * �ֶ�����
	     */
		String m_fieldText;
		/**
	     * ������ʾģʽ
	     */
		TextMode m_fieldTextMode;
		/**
	     * ����ķָ���
	     */
		String m_fieldTextSeparator;
		/**
	     * ���ֵ���ɫ
	     */
		Long m_textColor;
		/**
	     * �Ƿ�ɼ�
	     */
		bool m_visible;
	public:
	     /**
          * ��������
          * @param  fieldName  �ֶ�����
          * @param  fieldText  �ֶ�����
          * @param  textColor  ������ɫ
          * @param  digit      ����С��λ��
          * @param  visible    �Ƿ�ɼ�
         */
		ChartTitle(int fieldName, const String& fieldText, Long color, int digit, bool visible);
		/**
	     * ��ȡ����С����λ��
	     */
		virtual int getDigit();
		/**
	     * ���ñ���С����λ��
	     */
		virtual void setDigit(int digit);
		/**
	     * ��ȡ�ֶ�����
	     */
		virtual int getFieldName();
		/**
	     * �����ֶ�����
	     */
		virtual void setFieldName(int fieldName);
		/**
	     * ��ȡ�ֶ�����
	     */
		virtual String getFieldText();
		/**
	     * �����ֶ�����
	     */
		virtual void setFieldText(const String& fieldText);
		/**
	     * ��ȡ������ʾģʽ
	     */
		virtual TextMode getFieldTextMode();
		/**
	     * ���ñ�����ʾģʽ
	     */
		virtual void setFieldTextMode(TextMode fieldTextMode);
		/**
	     * ��ȡ����ķָ���
	     */
		virtual String getFieldTextSeparator();
		/**
	     * ���ñ���ķָ���
	     */
		virtual void setFieldTextSeparator(const String& fieldTextSeparator);
		/**
	     * ��ȡ���ֵ���ɫ
	     */
		virtual Long getTextColor();
		/**
	     * �������ֵ���ɫ
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
		virtual void getProperty(const String& name, String *value, String *type);
		/**
	     * ��ȡ���������б�
	     */
		virtual ArrayList<String> getPropertyNames();
	    /**
		  * ��������ֵ
		  * @param name  ��������
		  * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};

	/*
	* ������
	*/
	class ChartTitleBar : public FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ����
	     */
		FCFont *m_font;
		/*
		* ������ɫ
		*/
		Long m_textColor;
		/**
	     * ����߶�
	     */
		int m_height;
		/**
	     * ����������
	     */
		int m_maxLine;
		/**
	     * �Ƿ���ʾ�����������
	     */
		bool m_showUnderLine;
		/**
	     * ��ı���
	     */
		String m_text;
		/**
	     * �Ƿ���ʾ����������ߵ���ɫ
	     */
		Long m_underLineColor;
		/**
	     * �Ƿ���ʾ����
	     */
		bool m_visible;
	public:
	    /**
         * ͼ�������
         */
		ChartTitleBar();
		/*
		* ��������
		*/
		virtual ~ChartTitleBar();
		/*
		* ���б���
		*/
		ArrayList<ChartTitle*> Titles;
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡ����
	     */
		virtual FCFont* getFont();
		/**
	     * ��������
	     */
		virtual void setFont(FCFont *font);
		/**
	     * ��ȡ����߶�
	     */
		virtual int getHeight();
		/**
	     * ���ñ���߶�
	     */
		virtual void setHeight(int height);
		/**
	     * ��ȡ����������
	     */
		virtual int getMaxLine();
		/**
	     * ��������������
	     */
		virtual void setMaxLine(int maxLine);
		/**
	     * ��ȡ�Ƿ���ʾ�����������
	     */
		virtual bool showUnderLine();
		/**
	     * �����Ƿ���ʾ�����������
	     */
		virtual void setShowUnderLine(bool showUnderLine);
		/**
	     * ��ȡ��ı���
	     */
		virtual String getText();
		/**
	     * ���ò�ı���
	     */
		virtual void setText(const String& text);
		/**
	     * ��ȡ�����������ɫ
	     */
		virtual Long getTextColor();
		/**
	     * ���ñ����������ɫ
	     */
		virtual void setTextColor(Long textColor);
		/**
	     * ��ȡ�Ƿ���ʾ����������ߵ���ɫ
	     */
		virtual Long getUnderLineColor();
		/**
	     * �����Ƿ���ʾ����������ߵ���ɫ
	     */
		virtual void setUnderLineColor(Long underLineColor);
		/**
	     * ��ȡ�Ƿ���ʾ����
	     */
		virtual bool isVisible();
		/**
	     * �����Ƿ���ʾ����
	     */
		virtual void setVisible(bool visible);
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