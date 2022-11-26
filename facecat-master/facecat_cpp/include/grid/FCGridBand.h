/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCGRIDBAND_H__
#define __FCGRIDBAND_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGrid.h"
#include "FCBandedGridColumn.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	class FCBandedGrid;
	class FCBandedGridColumn;

	/*
	* ����
	*/
	class FCGridBand : public FCButton{
	protected:
	    /**
		 * �Ƿ���Ե�����С
		 */
		bool m_allowResize;
		/**
		 * ���
		 */
		FCBandedGrid *m_grid;
		/**
		 * ����
		 */
		int m_index;
		/**
		 * ������
		 */
		FCGridBand *m_parentBand;
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
		 * ������С״̬��1:��� 2:�Ҳ�
		 */
		int m_resizeState;
	public:
	    /**
		 * �ӱ���
		 */
		ArrayList<FCGridBand*> m_bands;
		/**
		 * �ӱ����
		 */
		ArrayList<FCBandedGridColumn*> m_columns;
		/*
		* ���캯��
		*/
		FCGridBand();
		/*
		* ��������
		*/
		virtual ~FCGridBand();
		/**
		 * ��ȡ�Ƿ���Ե�����С
		 */
		virtual bool allowResize();
		/**
		 * �����Ƿ���Ե�����С
		 */
		virtual void setAllowResize(bool allowResize);
		/**
		 * ��ȡ���
		 */
		virtual FCBandedGrid* getGrid();
		/**
		 * ���ñ��
		 */
		virtual void setGrid(FCBandedGrid *grid);
		/**
		 * ��ȡ����
		 */
		virtual int getIndex();
		/**
		 * ��������
		 */
		virtual void setIndex(int index);
		/**
		 * ��ȡ������
		 */
		virtual FCGridBand* getParentBand();
		/**
		 * ���ø�����
		 */
		virtual void setParentBand(FCGridBand *parentBand);
	public:
	    /**
		 * ��ӱ���
		 */
		void addBand(FCGridBand *band);
		/**
		 * ��ӱ����
		 */
		void addColumn(FCBandedGridColumn *column);
		/**
		 * �������
		 */
		void clearBands();
		/**
		 * �����
		 */
		void clearColumns();
		/**
		 * ��ȡ���е��ӱ����
		 */
		ArrayList<FCBandedGridColumn*> getAllChildColumns();
		/**
		 * ��ȡ�����б�
		 */
		ArrayList<FCGridBand*> getBands();
		/**
		 * ��ȡ��ͷ
		 */
		ArrayList<FCBandedGridColumn*> getColumns();
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
		* @param  index   ����
		* @param  band   ����
		*/
		void insertBand(int index, FCGridBand *band);
		/**
		* ��������
		* @param  index   ����
		* @param  band   ����
		*/
		void insertColumn(int index, FCBandedGridColumn *column);
		/**
		* �������·���
         * @param  touchInfo    ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
         * @param  touchInfo    ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
         * @param  touchInfo    ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �Ƴ�����
		 */
		void removeBand(FCGridBand *band);
		/**
		 * �Ƴ������
		 */
		void removeColumn(FCBandedGridColumn *column);
		/**
		 * ������ͷ����
		 */
		virtual void resetHeaderLayout();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif