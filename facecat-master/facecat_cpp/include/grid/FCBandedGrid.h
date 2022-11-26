/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCBANDEDGRID_H__
#define __FCBANDEDGRID_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGridColumn.h"
#include "FCGridBand.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCBandedGridColumn;
	class FCGridBand;

	/*
	* ��״���
	*/
	class FCBandedGrid : public FCGrid{
	protected:
	    /**
		 * ��ȡ���пɼ����Ŀ��
		 */
		int getAllVisibleBandsWidth();
	public:
	    /**
		 * ����
		 */
		ArrayList<FCGridBand*> m_bands;
		/*
		* ���캯��
		*/
		FCBandedGrid();
		/*
		* ��������
		*/
		virtual ~FCBandedGrid();
	public:
		/**
		* ��ӱ���
		* @param  band  ����
		*/
		void addBand(FCGridBand *band);
		/**
		* �����
		* @param  column  ��
		*/
		virtual void addColumn(FCGridColumn *column);
		/**
		 * �������
		 */
		void clearBands();
		/**
		 * ������е���
		 */
		virtual void clearColumns();
        /**
		 * ��ȡ�����б�
		 */
		ArrayList<FCGridBand*> getBands();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		* �������
		* @param  index  ����
		* @param  band  ����
		*/
		void insertBand(int index, FCGridBand *band);
		/**
		 * ���ÿؼ����ɼ�����
		 */
		virtual void onSetEmptyClipRegion();
		/**
		* �Ƴ�����
		* @param  band  ����
		*/
		void removeBand(FCGridBand *band);
		/**
		* �Ƴ���ͷ
		* @param  column  ��ͷ
		*/
		virtual void removeColumn(FCGridColumn *column);
		/**
		 * ������ͷ����
		 */
		virtual void resetHeaderLayout();
		/**
		 * ���²���
		 */
		virtual void update();
	};
}

#endif