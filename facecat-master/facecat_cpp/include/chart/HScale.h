/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __HSCALE_H__
#define __HSCALE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "CrossLineTip.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	class CrossLineTip;

	/*
	* ����
	*/
	class HScale : public FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ʮ���߱�ǩ
	     */
		CrossLineTip *m_crossLineTip;
		/**
	     * �������ֵ���ɫ
	     */
		HashMap<int, Long> m_dateColors;
		/**
	     * X�����ֵ�����
	     */
		FCFont *m_font;
		/**
	     * X��ĸ߶�
	     */
		int m_height;
		/**
	     * �������������
	     */
		HScaleType m_hScaleType;
		/**
	     * �������ּ��
	     */
		int m_interval;
		/**
	     * X���������ɫ
	     */
		Long m_scaleColor;
		/**
	     * �̶ȵ�
	     */
		ArrayList<double> m_scaleSteps;
		/**
	     * �ı���ɫ
	     */
		Long m_textColor;
		/**
	     * ��ʾX��
	     */
		bool m_visible;
	public:
		HScale();
		virtual ~HScale();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡʮ���߱�ǩ
	     */
		virtual CrossLineTip* getCrossLineTip();
		/**
	     *  ��ȡ�������ֵ���ɫ
	     */
		virtual Long getDateColor(DateType dateType);
		/**
	     * �����������ֵ���ɫ
	     */
		virtual void setDateColor(DateType dateType, Long color);
		/**
	     * ��ȡX�����ֵ�����
	     */
		virtual FCFont* getFont();
		/**
	     * ����X�����ֵ�����
	     */
		virtual void setFont(FCFont *font);
		/**
	     * ��ȡX��ĸ߶�
	     */
		virtual int getHeight();
		/**
	     * ����X��ĸ߶�
	     */
		virtual void setHeight(int height);
		/**
	     * ��ȡ�������������
	     */
		virtual HScaleType getHScaleType();
		/**
	     * ���ú������������
	     */
		virtual void setHScaleType(HScaleType hScaleType);
		/**
	     * ��ȡ�������ּ��
	     */
		virtual int getInterval();
		/**
	     * �����������ּ��
	     */
		virtual void setInterval(int interval);
		/**
	     * ��ȡX���������ɫ
	     */
		virtual Long getScaleColor();
		/**
	     * ����X���������ɫ
	     */
		virtual void setScaleColor(Long scaleColor);
		/**
	     * ��ȡ�ı���ɫ
	     */
		virtual Long getTextColor();
		/**
	     * �����ı���ɫ
	     */
		virtual void setTextColor(Long textColor);
		/**
	     * ��ȡ��ʾX��
	     */
		virtual bool isVisible();
		/**
	     * ������ʾX��
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
	     * ��ȡ�̶ȵ�
	     */
		ArrayList<double> getScaleSteps();
		/**
	     * �ػ淽��
	     */
		virtual void onPaint(FCPaint *paint, ChartDiv *div, const FCRect& rect);
		/**
	     * ��������
	     */
		virtual void setProperty(const String& name, const String& value);
		/**
	     * ���ÿ̶ȵ�
	     */
		void setScaleSteps(ArrayList<double> scaleSteps);
	};
}
#endif