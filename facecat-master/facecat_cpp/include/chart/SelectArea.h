/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __SELECTAREA_H__
#define __SELECTAREA_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

    /**
     * ѡ������
     */
	class SelectArea : public FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ����ɫ
	     */
		Long m_backColor;
		/**
	     * ѡ�п������
	     */
		FCRect m_bounds;
		/**
	     * �Ƿ���Ըı�ѡ�п�Ĵ�С
	     */
		bool m_canResize;
		/**
	     * �Ƿ���Գ���ѡ�п�
	     */
		bool m_enabled;
		/**
	     * ѡ�п����ɫ
	     */
		Long m_lineColor;
		/**
	     * �Ƿ���ʾѡ�п�
	     */
		bool m_visible;
	public:
		/*
		* ���캯��
		*/
		SelectArea();
		/*
		* ��������
		*/
		virtual ~SelectArea();
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡ����ɫ
	     */
		virtual Long getBackColor();
		/**
	     * ���ñ���ɫ
	     */
		virtual void setBackColor(Long backColor);
		/**
	     * ��ȡѡ�п������
	     */
		virtual FCRect getBounds();
		/**
	     * ����ѡ�п������
	     */
		virtual void setBounds(FCRect bounds);
		/**
	     * ��ȡ�Ƿ���Ըı�ѡ�п�Ĵ�С
	     */
		virtual bool canResize();
		/**
	     * �����Ƿ���Ըı�ѡ�п�Ĵ�С
	     */
		virtual void setCanResize(bool canResize);
		/**
	     * ��ȡ�Ƿ���Գ���ѡ�п�
	     */
		virtual bool isEnabled();
		/**
	     * �����Ƿ���Գ���ѡ�п�
	     */
		virtual void setEnabled(bool enabled);
		/**
	     * ��ȡѡ�п����ɫ
	     */
		virtual Long getLineColor();
		/**
	     * ����ѡ�п����ɫ
	     */
		virtual void setLineColor(Long lineColor);
		/**
	     * ��ȡ�Ƿ���ʾѡ�п�
	     */
		virtual bool isVisible();
		/**
	     * �����Ƿ���ʾѡ�п�
	     */
		virtual void setVisible(bool visible);
	public:
	    /**
	     * �ر�
	     */
		void close();
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