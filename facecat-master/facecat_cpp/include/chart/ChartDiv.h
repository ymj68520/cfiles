/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __CHARTDIV_H__
#define __CHARTDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCPaint.h"
#include "Enums.h"
#include "CrossLine.h"
#include "ScaleGrid.h"
#include "FCChart.h"
#include "VScale.h"
#include "SelectArea.h"
#include "ChartToolTip.h"
#include "ChartTitleBar.h"
#include "HScale.h"
#include "FCPlot.h"
#include "BaseShape.h"

namespace FaceCat{
	class FCChart;
	class CrossLine;
	class ChartToolTip;
	class FCPlot;
	class BaseShape;
	class HScale;
	class VScale;
	class FCNative;
	class ChartTitleBar;
	class SelectArea;
	class ScaleGrid;
	/*
	* ͼ�㣬�������������ᣬͼ�Σ����߹��ߣ�ָ������ݡ�
	*/
	class ChartDiv : public FCProperty{
	protected:
		/*
		* �Ƿ������û���ͼ
		*/
		bool m_allowUserPaint;
		/*
		* ����ɫ
		*/
		Long m_backColor;
		/*
		* ����ɫ
		*/
		Long m_borderColor;
		/*
		* K��ͼ
		*/
		FCChart *m_chart;
		/*
		* ʮ����
		*/
		CrossLine *m_crossLine;
		/*
		* ����
		*/
		FCFont *m_font;
		/*
		* ����������
		*/
		ScaleGrid *m_hGrid;
		/*
		* ����
		*/
		HScale *m_hScale;
		/*
		* ��������
		*/
		VScale *m_leftVScale;
		/*
		* λ��
		*/
		FCPoint m_location;
		/*
		* ���߹���
		*/
		ArrayList<FCPlot*> m_plots;
		/*
		* �Ҳ������
		*/
		VScale *m_rightVScale;
		/*
		* ѡ������
		*/
		SelectArea *m_selectArea;
		/*
		* �Ƿ�ѡ��
		*/
		bool m_selected;
		/*
		* ͼ��
		*/
		ArrayList<BaseShape*> m_shapes;
		/*
		* ��ʾѡ��
		*/
		bool m_showSelect;
		/*
		* ��С
		*/
		FCSize m_size;
		/*
		* ������
		*/
		ChartTitleBar *m_title;
		/*
		* ��ʾ��ǩ
		*/
		ChartToolTip *m_toolTip;
		/*
		* ����ٷֱ�
		*/
		int m_verticalPercent;
		/*
		* ����������
		*/
		ScaleGrid *m_vGrid;
		/*
		* �������ĸ߶�
		*/
		int m_workingAreaHeight;
	public:
		/*
		* ͼ������
		*/
		static bool shapesAsc(BaseShape *x, BaseShape *y);
		/*
		* ͼ�ν���
		*/
		static bool shapesDesc(BaseShape *x, BaseShape *y);
		/*
		* ���߹�������
		*/
		static bool plotsAsc(FCPlot *x, FCPlot *y);
		/*
		* ���߹��߽���
		*/
		static bool plotsDesc(FCPlot *x, FCPlot *y);
	public:
		/*
		* ����ͼ��
		*/
		ChartDiv();
		/*
		* ��������
		*/
		virtual ~ChartDiv();
		/*
		* ��ȡ�Ƿ������û���ͼ
		*/
		virtual bool allowUserPaint();
		/*
		* �����Ƿ������û���ͼ
		*/
		virtual void setAllowUserPaint(bool allowUserPaint);
		/*
		* ��ȡ����ɫ
		*/
		virtual Long getBackColor();
		/*
		* ���ñ���ɫ
		*/
		virtual void setBackColor(Long backColor);
		/*
		* ��ȡ����ɫ
		*/
		virtual Long getBorderColor();
		/*
		* ���ñ���ɫ
		*/
		virtual void setBorderColor(Long borderColor);
		/*
		* ��ȡ�����²��λ��
		*/
		virtual int getBottom();
		/*
		* ��ȡ�������
		*/
		virtual FCRect getBounds();
		/*
		* ���ò������
		*/
		virtual void setBounds(FCRect bounds);
		/*
		* ��ȡʮ����
		*/
		virtual CrossLine* getCrossLine();
		/*
		* ����ʮ����
		*/
		virtual void setCrossLine(CrossLine *crossLine);
		/*
		* ��ȡ����
		*/
		virtual FCFont* getFont();
		/*
		* ��������
		*/
		virtual void setFont(FCFont *font);
		/*
		* ��ȡ�߶�
		*/
		virtual int getHeight();
		/*
		* ��ȡ����������
		*/
		virtual ScaleGrid* getHGrid();
		/*
		* ���ú���������
		*/
		virtual void setHGrid(ScaleGrid *hGrid);
		/*
		* ��ȡ����
		*/
		virtual HScale* getHScale();
		/*
		* ���ú���
		*/
		virtual void setHScale(HScale *hScale);
		/*
		* ��ȡK��ͼ
		*/
		virtual FCChart* getChart();
		/*
		* ����K��ͼ
		*/
		virtual void setChart(FCChart *chart);
		/*
		* ��ȡ���ľ���
		*/
		virtual int getLeft();
		/*
		* ��ȡ��������
		*/
		virtual VScale* getLeftVScale();
		/*
		* ������������
		*/
		virtual void setLeftVScale(VScale *leftVScale);
		/*
		* ��ȡλ��
		*/
		virtual FCPoint getLocation();
		/*
		* ��ȡ�����Ҳ�ľ���
		*/
		virtual int getRight();
		/*
		* ��ȡ�Ҳ������
		*/
		virtual VScale* getRightVScale();
		/*
		* �����Ҳ������
		*/
		virtual void setRightVScale(VScale *rightVScale);
		/*
		* ��ȡѡ������
		*/
		virtual SelectArea* getSelectArea();
		/*
		* ����ѡ������
		*/
		virtual void setSelectArea(SelectArea *selectArea);
		/*
		* ��ȡ�Ƿ�ѡ��
		*/
		virtual bool isSelected();
		/*
		* �����Ƿ�ѡ��
		*/
		virtual void setSelected(bool selected);
		/*
		* ��ȡ�Ƿ�Ҫ��ʾѡ��
		*/
		virtual bool isShowSelect();
		/*
		* �����Ƿ�Ҫ��ʾѡ��
		*/
		virtual void setShowSelect(bool showSelect);
		/*
		* ��ȡ������
		*/
		virtual ChartTitleBar* getTitleBar();
		/*
		* ���ñ�����
		*/
		virtual void setTitleBar(ChartTitleBar *title);
		/*
		* ��ȡ��ʾ��ǩ
		*/
		virtual ChartToolTip* getToolTip();
		/*
		* ������ʾ��ǩ
		*/
		virtual void setToolTip(ChartToolTip *toolTip);
		/*
		* ��ȡ���붥���ľ���
		*/
		virtual int getTop();
		/*
		* ��ȡ����ٷֱ�
		*/
		virtual int getVerticalPercent();
		/*
		* ��������ٷֱ�
		*/
		virtual void setVerticalPercent(int verticalPercent);
		/*
		* ��ȡ����������
		*/
		virtual ScaleGrid* getVGrid();
		/*
		* ��������������
		*/
		virtual void setVGrid(ScaleGrid *vGrid);
		/*
		* ��ȡ���
		*/
		virtual int getWidth();
		/*
		* ��ȡ�������ĸ߶�
		*/
		virtual int getWorkingAreaHeight();
		/*
		* ���ù������ĸ߶�
		*/
		virtual void setWorkingAreaHeight(int workingAreaHeight);
	public:
		/**
         * ��ӻ���
         * @param plot ����
        */
		void addPlot(FCPlot *plot);
		/**
         * ���ͼ��
         * @param shape ͼ��
        */
		void addShape(BaseShape *shape);
		/**
         * �Ƿ����ͼ��
         * @param shape ͼ��
        */
		bool containsShape(BaseShape *shape);
		/**
         * ��ȡ���ߵļ���
         * @param sortType ��������
        */
		ArrayList<FCPlot*> getPlots(SortType sortType);
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
         * ��ȡͼ�εļ���
         * @param sortType ��������
        */
		ArrayList<BaseShape*> getShapes(SortType sortType);
		/**
         * ��ȡ����
         * @param attachVScale �����Ҳ�
        */
		VScale* getVScale(AttachVScale attachVScale);
		/**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param rect ����
        */
		virtual void onPaint(FCPaint *paint, const FCRect& rect);
		/**
		 * �Ƴ�����
		 * @param plot ����
        */
		void removePlot(FCPlot *plot);
		/**
         * �Ƴ�ͼ��
         * @param shape ͼ��
        */
		void removeShape(BaseShape *shape);
		/**
         * ��������
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};
}
#endif