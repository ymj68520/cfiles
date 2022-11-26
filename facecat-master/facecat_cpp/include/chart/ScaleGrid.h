/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __SCALEGRID_H__
#define __SCALEGRID_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;

    /**
     * ������
     */
	class ScaleGrid : public FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * ����
	     */
		int m_distance;
		/**
	     * �����ߵ���ɫ
	     */
		Long m_gridColor;
		/**
	     * ��ȡ�����ú��������ߵ���ʽ
	     */
		int m_lineStyle;
		/**
	     * �Ƿ�ɼ�
	     */
		bool m_visible;
	public:
		/*
		* ���캯��
		*/
		ScaleGrid();
		/*
		* ��������
		*/
		virtual ~ScaleGrid();
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
		virtual int getDistance();
		/**
	     * ���þ���
	     */
		virtual void setDistance(int distance);
		/**
	     * ��ȡ�����ߵ���ɫ
	     */
		virtual Long getGridColor();
		/**
	     * ���������ߵ���ɫ
	     */
		virtual void setGridColor(Long gridColor);
		/**
	     * ��ȡ���������ߵ���ʽ
	     */
		virtual int getLineStyle();
		/**
	     * ���ú��������ߵ���ʽ
	     */
		virtual void setLineStyle(int lineStyle);
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