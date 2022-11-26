/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __CROSSLINE_H__
#define __CROSSLINE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "Enums.h"
#include "ChartDiv.h"

namespace FaceCat{
	class ChartDiv;
	/**
     * ʮ����
     */
	class CrossLine : FCProperty{
	protected:
	    /**
	     * �Ƿ������û���ͼ
	     */
		bool m_allowUserPaint;
		/**
	     * �Ƿ�����˫������
	     */
		bool m_allowDoubleClick;
		/**
	     * ���������ỹ������
	     */
		AttachVScale m_attachVScale;
		/**
	     * ʮ���ߵ���ɫ
	     */
		Long m_lineColor;
	public:
		/*
		* ���캯��
		*/
		CrossLine();
		/*
		* ��������
		*/
		virtual ~CrossLine();
		/**
	     * ��ȡ�Ƿ�����˫������
	     */
		virtual bool allowDoubleClick();
		/**
	     * �����Ƿ�����˫������
	     */
		virtual void setAllowDoubleClick(bool allowDoubleClick);
		/**
	     * ��ȡ�Ƿ������û���ͼ
	     */
		virtual bool allowUserPaint();
		/**
	     * �����Ƿ������û���ͼ
	     */
		virtual void setAllowUserPaint(bool allowUserPaint);
		/**
	     * ��ȡ���������ỹ������
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * �������������ỹ������
	     */
		virtual void setAttachVScale(AttachVScale attachVScale);
		/**
	     * ��ȡʮ���ߵ���ɫ
	     */
		virtual Long getLineColor();
		/**
	     * ����ʮ���ߵ���ɫ
	     */
		virtual void setLineColor(Long lineColor);
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