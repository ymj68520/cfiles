/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __VSCALE_H__
#define __VSCALE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "FCDataTable.h"
#include "CrossLineTip.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	class CrossLineTip;

    /**
     * Y��
     */
	class VScale : public FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ���ֵ����Сֵ�Ƿ��Զ�����
	     */
		bool m_autoMaxMin;
		/**
	     * �����ֶ�
	     */
		int m_baseField;
		/**
	     * ʮ���߱�ǩ
	     */
		CrossLineTip *m_crossLineTip;
		/**
	     * �����ʾ��ֵ����С����λ��
	     */
		int m_digit;
		/**
	     * ���Y�����ֵ�����
	     */
		FCFont *m_font;
		/**
	     * ����
	     */
		int m_magnitude;
		/**
	     * �����������м�ֵ
	     */
		double m_midValue;
		/**
	     * ��������
	     */
		NumberStyle m_numberStyle;
		/**
	     * ��Сֵ�Ϸ��ļ�϶����
	     */
		int m_paddingBottom;
		/**
	     * ���ֵ�Ϸ��ļ�϶����
	     */
		int m_paddingTop;
		/**
	     * �Ƿ�ת
	     */
		bool m_reverse;
		/**
	     * ������Ļ���
	     */
		Long m_scaleColor;
		/*
		* ����̶�
		*/
		ArrayList<double> m_scaleSteps;
		/**
	     * ����ϵ������
	     */
		VScaleSystem m_system;
		/**
	     * Y�����ֵ���ɫ
	     */
	    Long m_textColor;
		/**
	     * Y�����ֵ���ɫ2
	     */
		Long m_textColor2;
		/**
	     * �����������
	     */
		VScaleType m_type;
		/**
	     * ����ֵ�ɼ����ֵ����ֵ
	     */
		double m_visibleMax;
		/**
	     * ����ֵ�ɼ����ֵ���Сֵ
	     */
		double m_visibleMin;
	public:
		/*
		* ���캯��
		*/
		VScale();
		/*
		* ��������
		*/
		virtual ~VScale();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡ���ֵ����Сֵ�Ƿ��Զ�����
	     */
		virtual bool autoMaxMin();
		/**
	     * �������ֵ����Сֵ�Ƿ��Զ�����
	     */
		virtual void setAutoMaxMin(bool autoMaxMin);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
		/**
	     * ���û����ֶ�
	     */
		virtual void setBaseField(int baseField);
		/**
	     * ��ȡʮ���߱�ǩ
	     */
		virtual CrossLineTip* getCrossLineTip();
		/**
	     * ��ȡ�����ʾ��ֵ����С����λ��
	     */
		virtual int getDigit();
		/**
	     * ���������ʾ��ֵ����С����λ��
	     */
		virtual void setDigit(int digit);
		/**
	     * ��ȡ���Y�����ֵ�����
	     */
		virtual FCFont* getFont();
		/**
	     * ��ȡ���Y�����ֵ�����
	     */
		virtual void setFont(FCFont *font);
		/**
	     * ��ȡ����
	     */
		virtual int getMagnitude();
		/**
	     * ��������
	     */
		virtual void setMagnitude(int magnitude);
		/**
	     * ��ȡ�����������м�ֵ
	     */
		virtual double getMidValue();
		/**
	     * ���������������м�ֵ
	     */
		virtual void setMidValue(double midValue);
		/**
	     * ��ȡ��������
	     */
		virtual NumberStyle getNumberStyle();
		/**
	     * ������������
	     */
		virtual void setNumberStyle(NumberStyle numberStyle);
		/**
	     * ��ȡ��Сֵ�Ϸ��ļ�϶����
	     */
		virtual int getPaddingBottom();
		/**
	     * ������Сֵ�Ϸ��ļ�϶����
	     */
		virtual void setPaddingBottom(int paddingBottom);
		/**
	     * ��ȡ���ֵ�Ϸ��ļ�϶����
	     */
		virtual int getPaddingTop();
		/**
	     * �������ֵ�Ϸ��ļ�϶����
	     */
		virtual void setPaddingTop(int paddingTop);
		/**
	     * ��ȡ�Ƿ�ת
	     */
		virtual bool isReverse();
		/**
	     * �����Ƿ�ת
	     */
		virtual void setReverse(bool reverse);
		/**
	     * ��ȡ������Ļ���
	     */
		virtual Long getScaleColor();
		/**
	     * ����������Ļ���
	     */
		virtual void setScaleColor(Long scaleColor);
		/**
	     * ��ȡ����ϵ������
	     */
		virtual VScaleSystem getSystem();
		/**
	     * ��������ϵ������
	     */
		virtual void setSystem(VScaleSystem system);
		/**
	     * ��ȡY�����ֵ���ɫ
	     */
	    virtual Long getTextColor();
	    /**
	     * ����Y�����ֵ���ɫ
	     */
		virtual void setTextColor(Long textColor);
		/**
	     * ��ȡY�����ֵ���ɫ2
	     */
		virtual Long getTextColor2();
		/**
	     * ����Y�����ֵ���ɫ2
	     */
		virtual void setTextColor2(Long textColor2);
		/**
	     * ��ȡ�����������
	     */
		virtual VScaleType getType();
		/**
	     * ���������������
	     */
		virtual void setType(VScaleType type);
		/**
	     * ��ȡ����ֵ�ɼ����ֵ����ֵ
	     */
		virtual double getVisibleMax();
		/**
	     * ��������ֵ�ɼ����ֵ����ֵ
	     */
		virtual void setVisibleMax(double visibleMax);
		/**
	     * ��ȡ����ֵ�ɼ����ֵ���Сֵ
	     */
		virtual double getVisibleMin();
		/**
	     * ��������ֵ�ɼ����ֵ���Сֵ
	     */
		virtual void setVisibleMin(double visibleMin);
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
	     * ��ȡ���������б�
	     */
		ArrayList<double> getScaleSteps();
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
		/**
	     * ���ÿ̶ȵ�
	     */
		void setScaleSteps(ArrayList<double> scaleSteps);
	};
}
#endif