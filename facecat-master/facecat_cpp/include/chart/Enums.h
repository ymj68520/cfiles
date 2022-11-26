/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __ENUMS_H__
#define __ENUMS_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ��������
	*/
	enum ActionType{
		ActionType_AT1 = 1, //��һ����Ķ���
		ActionType_AT2 = 2, //�ڶ�����Ķ���
		ActionType_AT3 = 3, //��������Ķ���
		ActionType_AT4 = 4, //���ĸ���Ķ���
		ActionType_MOVE = 0, //�ƶ�
		ActionType_NO = -1 //���ƶ�
	};

	/*
	* ���������
	*/
	enum AttachVScale{
		AttachVScale_Left, //����
		AttachVScale_Right //����
	};

	/*
	* ��״ͼ��ʽ
	*/
	enum BarStyle{
		BarStyle_Line, //����
		BarStyle_Rect //����
	};

	/*
	* �ߵ���ʽ
	*/
	enum CandleStyle{
		CandleStyle_American, //������
		CandleStyle_CloseLine, //������
		CandleStyle_Rect, //����
		CandleStyle_Tower //������
	};

	/*
	* ʮ���ߵ��ƶ���ʽ
	*/
	enum CrossLineMoveMode{
		CrossLineMoveMode_AfterClick, //����������ƶ�
		CrossLineMoveMode_FollowTouch //���津��
	};

	/*
	* ���ڵ�����
	*/
	enum DateType{
		DateType_Day = 2, //��
		DateType_Hour = 3, //Сʱ
		DateType_Millisecond = 6, //����
		DateType_Minute = 4, //����
		DateType_Month = 1, //��
		DateType_Second = 5, //��
		DateType_Year = 0 //��
	};

	/*
	* X�������
	*/
	enum HScaleType{
		HScaleType_Date, //����
		HScaleType_Number //����
	};

	/*
	* ���ֵ���ʽ
	*/
	enum NumberStyle{
		NumberStyle_Standard, //��׼
		NumberStyle_Underline //���»�������
	};

	/*
	* ���ߵ���ʽ
	*/
	enum PolylineStyle{
		PolylineStyle_Cycle, //ԲȦ
		PolylineStyle_DashLine, //����
		PolylineStyle_DotLine, //ϸ��ͼ
		PolylineStyle_SolidLine //ʵ��
	};

	/*
	* ��������
	*/
	enum ScrollType{
		ScrollType_None, //��
		ScrollType_Left, //����
		ScrollType_Right, //����
		ScrollType_ZoomIn, //��С
		ScrollType_ZoomOut //�Ŵ�
	};

	/*
	* ѡ�е���ʽ
	*/
	enum SelectPoint{
		SelectPoint_Ellipse, //Բ
		SelectPoint_Rect //����
	};

	/*
	* ͼ�α����ģʽ
	*/
	enum TextMode{
		TextMode_Field, //��ʾ�ֶ�
		TextMode_Full, //��ʾ����
		TextMode_None, //����ʾ
		TextMode_Value //��ʾֵ
	};

	/*
	* ��������ϵ
	*/
	enum VScaleSystem{
		VScaleSystem_Logarithmic, //��������
		VScaleSystem_Standard //��׼
	};

	/*
	* ������������
	*/
	enum VScaleType{
		VScaleType_Divide, //�ȷ�
		VScaleType_EqualDiff, //�Ȳ�
		VScaleType_EqualRatio, //�ȱ�
		VScaleType_GoldenRatio, //�ƽ�ָ�
		VScaleType_Percent //�ƽ�ָ�
	};
}
#endif