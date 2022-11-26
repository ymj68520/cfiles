/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCGRIDROW_H__
#define __FCGRIDROW_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCProperty.h"
#include "FCGridCell.h"
#include "FCGrid.h"
#include "FCGridColumn.h"

namespace FaceCat{
	class FCGridCell;
	class FCGrid;
	class FCGridColumn;

	/*
	* ����е�����
	*/
	class FCGridRowStyle{
	protected:
	    /**
		 * ����е���ʽ
		 */
		Long m_backColor;
		/**
		 * ����
		 */
		FCFont *m_font;
		/**
		 * ������ͣ�еı���ɫ
		 */
		Long m_hoveredBackColor;
		/**
		 * ������ͣ�е�ǰ��ɫ
		 */
		Long m_hoveredTextColor;
		/**
		 * ѡ���еı���ɫ
		 */
		Long m_selectedBackColor;
		/**
		 * ѡ���е�ǰ��ɫ
		 */
		Long m_selectedTextColor;
		/**
		 * ǰ��ɫ
		 */
		Long m_textColor;
	public:
		/*
		* ���캯��
		*/
		FCGridRowStyle();
		/*
		* ��������
		*/
		virtual ~FCGridRowStyle();
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
		/**
		 * ��ȡ������ͣ�еı���ɫ
		 */
		virtual Long getHoveredBackColor();
		/**
		 * ���ô�����ͣ�еı���ɫ
		 */
		virtual void setHoveredBackColor(Long hoveredBackColor);
		/**
		 * ��ȡ������ͣ�е�ǰ��ɫ
		 */
		virtual Long getHoveredTextColor();
		/**
		 * ���ô�����ͣ�е�ǰ��ɫ
		 */
		virtual void setHoveredTextColor(Long hoveredTextColor);
		/**
		 * ��ȡѡ���еı���ɫ
		 */
		virtual Long getSelectedBackColor();
		/**
		 * ����ѡ���еı���ɫ
		 */
		virtual void setSelectedBackColor(Long selectedBackColor);
		/**
		 * ��ȡѡ���е�ǰ��ɫ
		 */
		virtual Long getSelectedTextColor();
		/**
		 * ����ѡ���е�ǰ��ɫ
		 */
		virtual void setSelectedTextColor(Long selectedTextColor);
	public:
		void copy(FCGridRowStyle *style);
	};

	/*
	* �����
	*/
	class FCGridRow : public FCProperty{
	protected:
	    /**
		 * �Ƿ�����༭
		 */
		bool m_allowEdit;
		/**
		 * ��ʾ����
		 */
		FCRect m_bounds;
		/**
		 * �༭��ť
		 */
		FCView *m_editButton;
		/**
		 * ���ڱ��
		 */
		FCGrid *m_grid;
		int m_height;
		/**
		 * �����������
		 */
		int m_horizontalOffset;
		/**
		 * ����
		 */
		int m_index;
		/**
		 * TAGֵ
		 */
		Object m_tag;
		/**
		 * �Ƿ�ɼ�
		 */
		bool m_visible;
		/**
		 * �ɼ�����
		 */
		int m_visibleIndex;
	public:
		/*
		* ��Ԫ��
		*/
		ArrayList<FCGridCell*> m_cells;
		/*
		* �༭״̬
		*/
		int m_editState;
		/*
		* ���캯��
		*/
		FCGridRow();
		/*
		* ��������
		*/
		virtual ~FCGridRow();
		/**
		 * ��ȡ�Ƿ�����༭
		 */
		virtual bool allowEdit();
		/**
		 * �����Ƿ�����༭
		 */
		virtual void setAllowEdit(bool allowEdit);
		/**
		 * ��ȡ��ʾ����
		 */
		virtual FCRect getBounds();
		/**
		 * ������ʾ����
		 */
		virtual void setBounds(FCRect bounds);
		/**
		 * ��ȡ�༭��ť
		 */
		virtual FCView* getEditButton();
		/**
		 * ���ñ༭��ť
		 */
		virtual void setEditButton(FCView *editButton);
		/**
		 * ��ȡ���ڱ��
		 */
		virtual FCGrid* getGrid();
		/**
		 * �������ڱ��
		 */
		virtual void setGrid(FCGrid *grid);
		/**
		 * ��ȡ�и�
		 */
		virtual int getHeight();
		/**
		 * �����и�
		 */
		virtual void setHeight(int height);
		/**
		 * ��ȡ�����������
		 */
		virtual int getHorizontalOffset();
		/**
		 * ���ú����������
		 */
		virtual void setHorizontalOffset(int horizontalOffset);
		/**
		 * ��ȡ����
		 */
		virtual int getIndex();
		/**
		 * ��������
		 */
		virtual void setIndex(int index);
		/**
		 * ��ȡTAGֵ
		 */
		virtual Object getTag();
		/**
		 * ����TAGֵ
		 */
		virtual void setTag(Object tag);
		/**
		 * ��ȡ�Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * �����Ƿ�ɼ�
		 */
		virtual void setVisible(bool visible);
		/**
		 * ��ȡ�ɼ�����
		 */
		virtual int getVisibleIndex();
		/**
		 * ���ÿɼ�����
		 */
		virtual void setVisibleIndex(int visibleIndex);
	public:
	    /**
		 * ��ӵ�Ԫ��
		 */
		void addCell(FCGridColumn *column, FCGridCell *cell);
		/**
		 * ��ӵ�Ԫ��
		 */
		void addCell(int columnIndex, FCGridCell *cell);
		/**
		 * ��ӵ�Ԫ��
		 */
		void addCell(const String& columnName, FCGridCell *cell);
		/**
		 * �����Ԫ��
		 */
		void clearCells();
		/**
		 * ��ȡ���е�Ԫ��
		 */
		ArrayList<FCGridCell*> getCells();
		/**
		 * �����е����ƻ�ȡ��Ԫ��
		 */
		FCGridCell* getCell(FCGridColumn *column);
		/**
		 * �����е�������ȡ��Ԫ��
		 */
		FCGridCell* getCell(int columnIndex);
		/**
		 * �����е����ƻ�ȡ��Ԫ��
		 */
		FCGridCell* getCell(const String& columnName);
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
		 * ����з���
		 */
		virtual void onAdd();
		/**
		 * �ػ淽��
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/**
		 * �ػ���߷���
		 */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect, bool isAlternate);
		/**
		 * �Ƴ��з���
		 */
		virtual void onRemove();
		/**
		 * �Ƴ���Ԫ��
		 */
		void removeCell(FCGridColumn *column);
		/**
		 * �Ƴ���Ԫ��
		 */
		void removeCell(int columnIndex);
		/**
		 * �Ƴ���Ԫ��
		 */
		void removeCell(const String& columnName);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif