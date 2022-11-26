/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCGRIDCOLUMN_H__
#define __FCGRIDCOLUMN_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCGrid.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	class FCGrid;

	/*
	* �����
	*/
	class FCGridColumn : public FCButton{
	protected:
	    /**
		 * �Ƿ��������
		 */
		bool m_allowSort;
		/**
		 * �Ƿ���Ե�����С
		 */
		bool m_allowResize;
		/**
		 * ���ݵĺ���������ʽ
		 */
		FCHorizontalAlign m_cellAlign;
		/**
		 * �е�����
		 */
		String m_columnType;
		/**
		 * �Ƿ񶳽�
		 */
		bool m_frozen;
		/**
		 * ���
		 */
		FCGrid *m_grid;
		/**
		 * ͷ���ľ���
		 */
		FCRect m_headerRect;
		/**
		 * ����
		 */
		int m_index;
		/**
		 * ����״̬
		 */
		FCGridColumnSortMode m_sortMode;
	protected:
	    /**
		 * ��ʼ���
		 */
		int m_beginWidth;
		/**
		 * ��������ʱ������
		 */
        FCPoint m_touchDownPoint;
        /**
		 * ������С״̬
		 */
		int m_resizeState;
	public:
		/*
		* ���캯��
		*/
		FCGridColumn();
		/*
		* ���캯��
		*/
		FCGridColumn(const String& text);
		/*
		* ��������
		*/
		virtual ~FCGridColumn();
		/**
		 * ��ȡ�Ƿ���Ե�����С
		 */
		virtual bool allowResize();
		/**
		 * �������Ƿ���Ե�����С
		 */
		virtual void setAllowResize(bool allowResize);
		/**
		 * ��ȡ�Ƿ��������
		 */
		virtual bool allowSort();
		/**
		 * �����Ƿ��������
		 */
		virtual void setAllowSort(bool allowSort);
		/**
		 * ��ȡ���ݵĺ���������ʽ
		 */
		virtual FCHorizontalAlign getCellAlign();
		/**
		 * �������ݵĺ���������ʽ
		 */
		virtual void setCellAlign(FCHorizontalAlign cellAlign);
		/**
		 * ��ȡ�е�����
		 */
		virtual String getColumnType();
		/**
		 * �����е�����
		 */
		virtual void setColumnType(String columnType);
		/**
		 * ��ȡ�Ƿ񶳽�
		 */
		virtual bool isFrozen();
		/**
		 * �����Ƿ񶳽�
		 */
		virtual void setFrozen(bool frozen);
		/**
		 * ��ȡ���
		 */
		virtual FCGrid* getGrid();
		/**
		 * ���ñ��
		 */
		virtual void setGrid(FCGrid *grid);
		/**
		 * ��ȡͷ���ľ���
		 */
		virtual FCRect getHeaderRect();
		/**
		 * ����ͷ���ľ���
		 */
		virtual void setHeaderRect(FCRect headerRect);
		/**
		 * ��ȡ����
		 */
		virtual int getIndex();
		/**
		 * ��������
		 */
		virtual void setIndex(int index);
		/**
		 * ��ȡ����״̬��0:������ 1:���� 2:����
		 */
		virtual FCGridColumnSortMode getSortMode();
		/**
		 * ��������״̬��0:������ 1:���� 2:����
		 */
		virtual void setSortMode(FCGridColumnSortMode sortMode);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
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
		 * �������
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * �϶���ʼ����
		 */
		virtual bool onDragBegin();
		/**
		 * �϶��з���
		 */
		virtual void onDragging();
		/**
		 * �������·���
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * �����ƶ�����
		 */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif