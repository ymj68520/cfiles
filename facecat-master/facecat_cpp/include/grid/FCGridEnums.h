/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCGRIDENUMS_H__
#define __FCGRIDENUMS_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
    /**
	 * ���������ʽ
	 */
	enum FCGridColumnSortMode{
		/**
		 * ����
		 */
		FCGridColumnSortMode_Asc,
		/**
		 * ����
		 */
		FCGridColumnSortMode_Desc,
		/**
		 * ������
		 */
		FCGridColumnSortMode_None
	};

    /**
	 * ���ѡ��ģʽ
	 */
	enum FCGridSelectionMode{
	    /**
		 * ѡ�е�Ԫ��
		 */
		FCGridSelectionMode_SelectCell,
		/**
		 * ѡ������
		 */
		FCGridSelectionMode_SelectFullColumn,
		/**
		 * ѡ������
		 */
		FCGridSelectionMode_SelectFullRow,
		/**
		 * ��ѡ��
		 */
		FCGridSelectionMode_SelectNone
	};

    /**
	 * ��Ԫ��༭ģʽ
	 */
	enum FCGridCellEditMode{
	    /**
		 * ˫��
		 */
        FCGridCellEditMode_DoubleClick,
        /**
		 * ��Ч
		 */
        FCGridCellEditMode_None,
        /**
		 * ����
		 */
        FCGridCellEditMode_SingleClick
	};
}

#endif