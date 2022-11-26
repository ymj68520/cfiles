/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCBANDEDGRIDCOLUMN_H__
#define __FCBANDEDGRIDCOLUMN_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridEnums.h"
#include "FCBandedGrid.h"
#include "FCGridColumn.h"
#include "FCGridBand.h"

namespace FaceCat{
	class FCBandedGrid;
	class FCGridColumn;
	class FCGridBand;

	/*
	* ����ͷ�����
	*/
	class FCBandedGridColumn : public FCGridColumn{
	protected:
	    /**
		 * ����
		 */
		FCGridBand *m_band;
	public:
		/*
		* ���캯��
		*/
		FCBandedGridColumn();
		/*
		* ��������
		*/
		virtual ~FCBandedGridColumn();
		/**
		 * ��ȡ����
		 */
		virtual FCGridBand* getBand();
		/**
		 * ���ñ���
		 */
		virtual void setBand(FCGridBand *band);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * �϶���ʼ����
		 */
		virtual bool onDragBegin();
		/**
		* �������·���
         * @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
         * @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
	};
}

#endif