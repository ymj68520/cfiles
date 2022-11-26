/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCGRIDCELL_H__
#define __FCGRIDCELL_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCProperty.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCGridColumn;
	class FCGridRow;
	class FCGrid;

	/*
	* ��Ԫ����ʽ
	*/
	class FCGridCellStyle{
	protected:
		FCHorizontalAlign m_align;
		/**
		 * �Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		bool m_autoEllipsis;
		/**
		 * ��ȡ
		 */
		Long m_backColor;
		/**
		 * ����
		 */
		FCFont *m_font;
		/**
		 * ǰ��ɫ
		 */
		Long m_textColor;
	public:
		/*
		* ���캯��
		*/
		FCGridCellStyle();
		/*
		* ��������
		*/
		virtual ~FCGridCellStyle();
		/**
		 * ��ȡ���ݵĺ���������ʽ
		 */
		virtual FCHorizontalAlign getAlign();
		/**
		 * �������ݵĺ���������ʽ
		 */
		virtual void setAlign(FCHorizontalAlign align);
		/**
		 * ��ȡ�Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual bool autoEllipsis();
		/**
		 * �����Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual void setAutoEllipsis(bool autoEllipsis);
		/*
		* ��ȡ����ɫ
		*/
		virtual Long getBackColor();
		/*
		* ���ñ���ɫ
		*/
		virtual void setBackColor(Long backColor);
		/**
		 * ��ȡ����
		 */
		virtual FCFont* getFont();
		/**
		 * ��������
		 */
		virtual void setFont(FCFont *font);
		/**
		 * ��ȡǰ��ɫ
		 */
		virtual Long getTextColor();
		/**
		 * ����ǰ��ɫ
		 */
		virtual void setTextColor(Long textColor);
	public:
		/*
		* ����
		*/
		void copy(FCGridCellStyle *style);
	};

	/*
	* ��Ԫ��
	*/
	class FCGridCell : public FCProperty{
	protected:
	    /**
		 * �Ƿ�ɱ༭
		 */
		bool m_allowEdit;
		/*
		* �еĿ��
		*/
		int m_colSpan;
		/**
		 * ������
		 */
		FCGridColumn *m_column;
		/**
		 * ���
		 */
		FCGrid *m_grid;
		/**
		 * ����
		 */
		String m_name;
		/**
		 * ������
		 */
		FCGridRow *m_row;
		/*
		* �еĿ��
		*/
		int m_rowSpan;
		/**
		 * ��ʽ
		 */
		FCGridCellStyle *m_style;
		/**
		 * TAGֵ
		 */
		Object m_tag;
	public:
		/*
		* ���캯��
		*/
		FCGridCell();
		/*
		* ��������
		*/
		virtual ~FCGridCell();
		/**
		 * ��ȡ�Ƿ�ɱ༭
		 */
		virtual bool allowEdit();
		/**
		 * �����Ƿ�ɱ༭
		 */
		virtual void setAllowEdit(bool allowEdit);
		/**
		 * ��ȡ��Խ������
		 */
		virtual int getColSpan();
		/**
		 *���ÿ�Խ������
		 */
		virtual void setColSpan(int colSpan);
		/**
		 * ��ȡ������
		 */
		virtual FCGridColumn* getColumn();
		/**
		 * ����������
		 */
		virtual void setColumn(FCGridColumn *column);
		/**
		 * ��ȡ���
		 */
		virtual FCGrid* getGrid();
		/**
		 * ���ñ��
		 */
		virtual void setGrid(FCGrid *grid);
		/**
		 * ��ȡ����
		 */
		virtual String getName();
		/**
		 * ��������
		 */
		virtual void setName(const String& name);
		/**
		 * ��ȡ������
		 */
		virtual FCGridRow* getRow();
		/**
		 * ����������
		 */
		virtual void setRow(FCGridRow *row);
		/**
		 * ��ȡ��Խ������
		 */
		virtual int getRowSpan();
		/**
		 * ���ÿ�Խ������
		 */
		virtual void setRowSpan(int rowSpan);
		/**
		 * ��ȡ��ʽ
		 */
		virtual FCGridCellStyle* getStyle();
		/**
		 * ������ʽ
		 */
		virtual void setStyle(FCGridCellStyle *style);
		/**
		 * ��ȡTAGֵ
		 */
		virtual Object getTag();
		/**
		 * ����TAGֵ
		 */
		virtual void setTag(Object tag);
		/**
		 * ��ȡ����
		 */
		virtual String getText();
		/**
		 * ��������
		 */
		virtual void setText(const String& text);
	public:
	    /**
		 * ��Ԫ���С�Ƚϣ���������
		 */
		virtual int compareTo(FCGridCell *cell);
		/**
		 * ��ȡ��������ֵ
		 */
		virtual bool getBool();
		/**
		 * ��ȡ˫���ȸ���ֵ
		 */
		virtual double getDouble();
		/**
		 * ��ȡ�����ȸ���ֵ
		 */
		virtual float getFloat();
		/**
		 * ��ȡ������ֵ
		 */
		virtual int getInt();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual Long getLong();
		/**
		 * ��ȡҪ���Ƶ�����
		 */
		virtual String getPaintText();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getPropertyNames();
		/**
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ��ӵ�Ԫ�񷽷�
		 */
		virtual void onAdd();
		/**
		* �ػ淽��
		* @param  paint  ��ͼ����
		* @param  rect  ����
		* @param  clipRect  �ü�����
		* @param  isAlternate  �Ƿ�����
		*/
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/**
		 * �Ƴ���Ԫ�񷽷�
		 */
		virtual void onRemove();
		/**
		 * ���ò�������ֵ
		 */
        virtual void setBool(bool value);
        /**
		 * ����˫���ȸ���ֵ
		 */
        virtual void setDouble(double value);
        /**
		 * ���õ����ȸ���ֵ
		 */
        virtual void setFloat(float value);
        /**
		 * ����������ֵ
		 */
        virtual void setInt(int value);
        /**
		 * ���ó�������ֵ
		 */
        virtual void setLong(Long value);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * �����ַ�����ֵ
		 */
        virtual void setString(const String& value);
	};

	/*
	* �ؼ��͵�Ԫ��
	*/
	class FCGridControlCell : public FCGridCell{
	protected:
		FCView *m_control;
		/**
		 * ���������¼�
		 */
		FCTouchEvent m_touchDownEvent;
		/**
		 * �����ƶ��¼�
		 */
		FCTouchEvent m_touchMoveEvent;
		/**
		 * ����̧���¼�
		 */
		FCTouchEvent m_touchUpEvent;
		/**
		 * ���������¼�
		 */
		FCTouchEvent m_touchWheelEvent;
	protected:
		/**
		* �ؼ����������¼�
		* @param  sender  ������
         * @param  touchInfo    ������Ϣ
		*/
		static void controlTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		* �ؼ������ƶ��¼�
		* @param  sender  ������
		*/
		static void controlTouchMove(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		* �ؼ�����̧���¼�
		* @param  sender  ������
		*/
		static void controlTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		* �ؼ��������ֹ����¼�
		* @param  sender  ������
		* @param  touchInfo   ������Ϣ
		*/
		static void controlTouchWheel(Object sender, FCTouchInfo touchInfo, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCGridControlCell();
		/*
		* ��������
		*/
		virtual ~FCGridControlCell();
		/**
		 * ��ȡ�ؼ�
		 */
		FCView* getControl();
		/**
		 * ���ÿؼ�
		 */
		void setControl(FCView *control);
		/**
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ��ȡҪ���Ƶ�����
		 */
		virtual String getPaintText();
		/**
		 * ��ӵ�Ԫ�񷽷�
		 */
		virtual void onAdd();
		/**
		 * �ؼ��������·���
		 */
		virtual void onControlTouchDown(FCTouchInfo touchInfo);
		/**
		 * �ؼ������ƶ��¼�
		 */
		virtual void onControlTouchMove(FCTouchInfo touchInfo);
		/**
		 * �ؼ�����̧���¼�
		 */
		virtual void onControlTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ؼ��������ֹ����¼�
		 */
		virtual void onControlTouchWheel(FCTouchInfo touchInfo);
		/**
		 * �ػ淽��
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/*
		* �ػ�ؼ�
		*/
		virtual void onPaintControl(FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		 * �Ƴ���Ԫ�񷽷�
		 */
		virtual void onRemove();
		/**
		 * �����ַ�����ֵs
		 */
		virtual void setString(const String& value);
	};
}

#endif