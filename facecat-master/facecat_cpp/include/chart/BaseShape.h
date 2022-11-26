/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __BASESHAPE_H__
#define __BASESHAPE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "FCChart.h"
#include "ChartDiv.h"
#include "FCDataTable.h"

namespace FaceCat{
	class ChartDiv;
	class FCChart;
	/**
     * ���������ĸ���
     */
	class BaseShape : FCProperty{
	protected:
		/*
		*�Ƿ������û���ͼ
		*/
		bool m_allowUserPaint;
		/*
		*���������ỹ������
		*/
		AttachVScale m_attachVScale;
		/*
		*�Ƿ�ѡ��
		*/
		bool m_selected;
		/*
		*�Ƿ�ɼ�
		*/
		bool m_visible;
		/*
		*��ͼ˳��
		*/
		int m_zOrder;
	public:
		/*
		* ���캯��
		*/
		BaseShape();
		/*
		* ��������
		*/
		virtual ~BaseShape();
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
	     *  ��ȡ�Ƿ�ѡ��
	     */
		virtual bool isSelected();
		/**
	     *  �����Ƿ�ѡ��
	     */
		virtual void setSelected(bool selected);
		/**
	     * ��ȡͼ���Ƿ�ɼ�
	     */
		virtual bool isVisible();
		/**
	     * ����ͼ���Ƿ�ɼ�
	     */
		virtual void setVisible(bool visible);
		/**
	     * ��ȡ��ͼ˳��
	     */
		virtual int getZOrder();
		/**
	     * ���û�ͼ˳��
	     */
		virtual void setZOrder(int zOrder);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
	    /**
        * ���ֶ����ƻ�ȡ�ֶα���
        * @param fieldName  �ֶ�����
        * @returns �ֶα���
        */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
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
	     * ��ȡѡ�е����ɫ
	     */
		virtual Long getSelectedColor();
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

	/*
	* K��
	*/
	class CandleShape:public BaseShape{
	protected:
		/**
	     * ���̼��ֶ�
	     */
		int m_closeField;
		/**
	     * ���̼۵���ʾ����
	     */
		String m_closeFieldText;
		/**
	     * ��ɫ���ֶ�
	     */
		int m_colorField;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_downColor;
		/**
	     * ��߼��ֶ�
	     */
		int m_highField;
		/**
	     * ��߼۵���ʾ����
	     */
		String m_highFieldText;
		/**
	     * ��ͼ��ֶ�
	     */
		int m_lowField;
		/**
	     * ��ͼ۵���ʾ����
	     */
		String m_lowFieldText;
		/**
	     * ���̼��ֶ�
	     */
		int m_openField;
		/**
	     * ���̼۵���ʾ����
	     */
		String m_openFieldText;
		/**
	     * �Ƿ���ʾ�����Сֵ
	     */
		bool m_showMaxMin;
		/*
		* ��ʽ
		*/
		CandleStyle m_style;
		/**
	     * ��ʽ�ֶ�
	     */
		int m_styleField;
		/**
	     * �����Сֵ��ǩ����ɫ
	     */
		Long m_tagColor;
		/**
	     * ������ɫ
	     */
		Long m_upColor;
	public:
		/*
		* ���캯��
		*/
		CandleShape();
		/**
	     *  ��ȡ��ɫ���ֶ�
	     */
		int getCloseField();
		/**
	     *  ������ɫ���ֶ�
	     */
		void setCloseField(int closeField);
		/**
	     * ��ȡ���̼۵���ʾ����
	     */
		String getCloseFieldText();
		/**
	     * �������̼۵���ʾ����
	     */
		void setCloseFieldText(const String& closeFieldText);
		/**
	     *  ��ȡ��ɫ���ֶ�
	     */
		int getColorField();
		/**
	     *  ������ɫ���ֶ�
	     */
		void setColorField(int colorField);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		Long getDownColor();
		/**
	     * �������ߵ���ɫ
	     */
		void setDownColor(Long downColor);
		/**
	     * ��ȡ��߼��ֶ�
	     */
		int getHighField();
		/**
	     * ������߼��ֶ�
	     */
		void setHighField(int highField);
		/**
	     * ��ȡ��߼۵���ʾ����
	     */
		String getHighFieldText();
		/**
	     * ������߼۵���ʾ����
	     */
		void setHighFieldText(const String& highFieldText);
		/**
	     * ��ȡ��ͼ��ֶ�
	     */
		int getLowField();
		/**
	     * ������ͼ��ֶ�
	     */
		void setLowField(int lowField);
		/**
	     * ��ȡ��ͼ۵���ʾ����
	     */
		String getLowFieldText();
		/**
	     * ������ͼ۵���ʾ����
	     */
		void setLowFieldText(const String& lowFieldText);
		/**
	     * ��ȡ���̼��ֶ�
	     */
		int getOpenField();
		/**
	     * ���ÿ��̼��ֶ�
	     */
		void setOpenField(int openField);
		/**
	     * ��ȡ���̼۵���ʾ����
	     */
		String getOpenFieldText();
		/**
	     * ���ÿ��̼۵���ʾ����
	     */
		void setOpenFieldText(const String& openFieldText);
		/**
	     * ��ȡ�Ƿ���ʾ�����Сֵ
	     */
		bool getShowMaxMin();
		/**
	     * �����Ƿ���ʾ�����Сֵ
	     */
		void setShowMaxMin(bool showMaxMin);
		/**
	     * ��ȡ����������
	     */
		CandleStyle getStyle();
		/**
	     * ��������������
	     */
		void setStyle(CandleStyle style);
		/**
	     * ��ȡ��ʽ�ֶ�
	     */
		int getStyleField();
		/**
	     * ������ʽ�ֶ�
	     */
		void setStyleField(int styleField);
		/**
	     * ��ȡ�����Сֵ��ǩ����ɫ
	     */
		Long getTagColor();
		/**
	     * ���������Сֵ��ǩ����ɫ
	     */
		void setTagColor(Long tagColor);
		/**
	     * ��ȡ������ɫ
	     */
		Long getUpColor();
		/**
	     * ����������ɫ
	     */
		void setUpColor(Long upColor);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
	    /**
         * ���ֶ����ƻ�ȡ�ֶα���
         * @param fieldName  �ֶ�����
         * @returns �ֶα���
        */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
	    /**
         * ��������ֵ
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
        *��ȡѡ�е����ɫ
        * @returns ��ɫ
        */
		virtual Long getSelectedColor();
	    /**
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};

	/*
	* ��״ͼ
	*/
	class BarShape:public BaseShape{
	protected:
	    /**
	     * ��ɫ���ֶ�
	     */
		int m_colorField;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_downColor;
		/**
	     * �ֶ�����
	     */
		int m_fieldName;
		/**
	     * �ֶ�����2
	     */
		int m_fieldName2;
		/**
	     * ��ʾ�ı�������
	     */
		String m_fieldText;
		/**
	     * ��ʾ�ı�������2
	     */
		String m_fieldText2;
		/**
	     * �ߵĿ��
	     */
		float m_lineWidth;
		/**
	     * ������ʽ
	     */
		BarStyle m_style;
		/**
	     * ��ʽ�ֶ�
	     */
		int m_styleField;
		/**
	     * ���ߵ���ɫ
	     */
		Long m_upColor;
	public:
		/*
		* ���캯��
		*/
		BarShape();
		/**
	     * ��ȡ��ɫ���ֶ�
	     */
		int getColorField();
		/**
	     * ������ɫ���ֶ�
	     */
		void setColorField(int colorField);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		Long getDownColor();
		/**
	     * �������ߵ���ɫ
	     */
		void setDownColor(Long downColor);
		/**
	     * ��ȡ�ֶ�����
	     */
		int getFieldName();
		/**
	     * �����ֶ�����
	     */
		void setFieldName(int fieldName);
		/**
	     * ��ȡ�ֶ�����2
	     */
		int getFieldName2();
		/**
	     * �����ֶ�����2
	     */
		void setFieldName2(int fieldName2);
		/**
	     *  ��ȡ��ʾ�ı�������
	     */
		String getFieldText();
		/**
	     *  ������ʾ�ı�������
	     */
		void setFieldText(const String& fieldText);
		/**
	     * ��ȡ��ʾ�ı�������2
	     */
		String getFieldText2();
		/**
	     * ������ʾ�ı�������2
	     */
		void setFieldText2(const String& fieldText2);
		/**
	     * ��ȡ�ߵĿ��
	     */
		float getLineWidth();
		/**
	     * �����ߵĿ��
	     */
		void setLineWidth(float lineWidth);
		/**
	     * ��ȡ��������ʽ
	     */
		BarStyle getStyle();
		/**
	     * ������������ʽ
	     */
		void setStyle(BarStyle style);
		/**
	     * ��ȡ��ʽ�ֶ�
	     */
		int getStyleField();
		/**
	     * ������ʽ�ֶ�
	     */
		void setStyleField(int styleField);
		/**
	     * ��ȡ���ߵ���ɫ
	     */
		Long getUpColor();
		/**
	     * �������ߵ���ɫ
	     */
		void setUpColor(Long upColor);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
	    /**
		 * ���ֶ����ƻ�ȡ�ֶα���
		 * @param fieldName  �ֶ�����
		 * @returns �ֶα���
        */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
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
        *��ȡѡ�е����ɫ
        * @returns ��ɫ
        */
		virtual Long getSelectedColor();
	    /**
		 * ��������ֵ
		 * @param name  ��������
		 * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};

	/*
	* ����
	*/
	class PolylineShape:public BaseShape{
	protected:
	    /**
	     * �ߵ���ɫ
	     */
		Long m_color;
		/**
	     * ��ɫ���ֶ�
	     */
		int m_colorField;
		/**
	     * �ֶ�����
	     */
		int m_fieldName;
		/**
	     * ��ʾ�ı�������
	     */
		String m_fieldText;
		/**
	     * ���ɫ
	     */
		Long m_fillColor;
		/**
	     * ��ʽ
	     */
		PolylineStyle m_style;
		/**
	     * �ߵĿ��
	     */
		float m_width;
	public:
		/*
		* ���캯��
		*/
		PolylineShape();
		/**
	     * ��ȡ�ߵ���ɫ
	     */
		Long getColor();
		/**
	     * �����ߵ���ɫ
	     */
		void setColor(Long color);
		/**
	     * ��ȡ��ɫ���ֶ�
	     */
		int getColorField();
		/**
	     * ������ɫ���ֶ�
	     */
		void setColorField(int colorField);
		/**
	     * ��ȡ�ֶ�����
	     */
		int getFieldName();
		/**
	     * �����ֶ�����
		 * @param fieldName �ֶ�����
	     */
		void setFieldName(int fieldName);
		/**
	     * ��ȡ��ʾ�ı�������
	     */
		String getFieldText();
		/**
	     * ������ʾ�ı�������
		 * @param fieldText ��������
	     */
		void setFieldText(const String& fieldText);
		/**
	     * ��ȡ���ɫ
	     */
		Long getFillColor();
		/**
	     * �������ɫ
	     */
		void setFillColor(Long fillColor);
		/**
	     * ��ȡ��ʽ
	     */
		PolylineStyle getStyle();
		/**
	     * ������ʽ
	     */
		void setStyle(PolylineStyle style);
		/**
	     * ��ȡ�ߵĿ��
	     */
		float getWidth();
		/**
	     * �����ߵĿ��
	     */
		void setWidth(float width);
	public:
	    /**
	     * ��ȡ�����ֶ�
	     */
		virtual int getBaseField();
		/**
	     * ���ֶ����ƻ�ȡ�ֶα���
	     */
		virtual String getFieldText(int fieldName);
		/**
	     * ��ȡ�����ֶ�
	     */
		virtual int* getFields(int *length);
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
	     * ��ȡѡ�е����ɫ
	     */
		virtual Long getSelectedColor();
		/**
	     * ��������
	     */
		virtual void setProperty(const String& name, const String& value);
	};

	/*
	* ����
	*/
	class TextShape:public BaseShape{
	protected:
	    /**
	     * ��ɫ�ֶ�
	     */
		int m_colorField;
		/**
	     * �ֶ�
	     */
		int m_fieldName;
		/**
	     * ����
	     */
		FCFont *m_font;
		/**
	     * ��ʽ�ֶ�
	     */
		int m_styleField;
		/**
	     * ���Ƶ�����
	     */
		String m_text;
		/**
	     * ���Ƶ�����
	     */
		Long m_textColor;
	public:
		/*
		* ���캯��
		*/
		TextShape();
		/**
	     * ��������
	     */
		virtual ~TextShape();
		/**
	     * ��ȡ��ɫ�ֶ�
	     */
		int getColorField();
		/**
	     * ������ɫ�ֶ�
	     */
		void setColorField(int colorField);
		/**
	     * ��ȡ�ֶ�
	     */
		int getFieldName();
		/**
	     * �����ֶ�
	     */
		void setFieldName(int fieldName);
		/**
	     * ��ȡ����
	     */
		FCFont* getFont();
		/**
	     * ��������
	     */
		void setFont(FCFont *font);
		/**
	     * ��ȡ��ʽ�ֶ�
	     */
		int getStyleField();
		/**
	     * ������ʽ�ֶ�
	     */
		void setStyleField(int styleField);
		/**
	     * ��ȡ���Ƶ�����
	     */
		String getText();
		/**
	     * ���û��Ƶ�����
	     */
		void setText(const String& text);
		/**
	     * ��ȡǰ��ɫ
	     */
		Long getTextColor();
		/**
	     * ����ǰ��ɫ
	     */
		void setTextColor(Long textColor);
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
}
#endif