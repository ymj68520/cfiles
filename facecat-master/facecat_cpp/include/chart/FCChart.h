/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCHART_H__
#define __FCCHART_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "FCDataTable.h"
#include "ChartDiv.h"
#include "FCPlot.h"
#include "BaseShape.h"
#include "VScale.h"

namespace FaceCat{
	class ChartDiv;
	class FCPlot;
	class BaseShape;
	class BarShape;
	class PointShape;
	class CandleShape;
	class PolylineShape;
	class TextShape;
	class FCView;
	class VScale;
	/*
	* ͼ��
	*/
	class FCChart:public FCView{
	private:
		/*
		* ���ID
		*/
		int m_timerID;
	protected:
	    /**
	     * �����Ƿ�
	     */
		bool m_autoFillHScale;
		/**
	     * �հ׿ռ�
	     */
		int m_blankSpace;
		/**
	     * �Ƿ�����϶�����
	     */
		bool m_canMoveShape;
		/**
	     * �Ƿ������ı��С
	     */
		bool m_canResizeV;
		/**
	     * �ǿɺ���ı��С
	     */
		bool m_canResizeH;
		/**
	     * �Ƿ����ִ�й�������
	     */
		bool m_canScroll;
		/**
	     * �Ƿ����ִ�����Ų���
	     */
		bool m_canZoom;
		CrossLineMoveMode m_crossLineMoveMode;
		/**
	     * ʮ���ߵ�ǰͣ���ļ�¼����
	     */
		int m_crossStopIndex;
		int m_cross_y;
		/**
	     * ����Դ
	     */
		FCDataTable *m_dataSource;
		/*
		* ����ͼ��
		*/
		ArrayList<ChartDiv*> m_divs;
		/**
	     * ���ȿɼ���¼��
	     */
		int m_firstVisibleIndex;
		/*
		* �����С������ʽ
		*/
		int m_hResizeType;
		/**
	     * �����ֶε���ʾ����
	     */
		String m_hScaleFieldText;
		/**
	     * ÿ��������X������ռ�Ŀռ�
	     */
		double m_hScalePixel;
		/**
	     * �����Ƿ������ƶ�
	     */
		bool m_isTouchMove;
		/**
	     * ����ʮ���߱�ʶ
	     */
		bool m_isScrollCross;
		/**
	     * �ϴ��ƶ��ĵ�λ
	     */
		FCPoint m_lastTouchMovePoint;
		/**
	     * �ϴε����λ��
	     */
		FCPoint m_lastTouchClickPoint;
		/**
	     * �������һ���ƶ����¼�
	     */
		double m_lastTouchMoveTime;
		/**
	     * ��ǰ���һ����¼�Ƿ�ɼ�
	     */
		bool m_lastRecordIsVisible;
		/*
		* ���ɼ�������
		*/
		int m_lastUnEmptyIndex;
		/**
	     * ���һ���ǿ�����
	     */
		double m_lastVisibleKey;
		/**
	     * ��ȡ���ɼ��ļ�¼��
	     */
		int m_lastVisibleIndex;
		/**
	     * ��ȡ���Y��Ŀ��
	     */
		int m_leftVScaleWidth;
		/**
	     * ��ȡ��ʾ����¼��
	     */
		int m_maxVisibleRecord;
		/*
		* ���ڱ��ƶ��Ļ���
		*/
		FCPlot *m_movingPlot;
		/**
	     * ��ȡ���ڱ��ƶ���ͼ��
	     */
		BaseShape *m_movingShape;
		/**
	     * ��ȡ�Ƿ�ת����
	     */
		bool m_reverseHScale;
		/**
	     * ��ȡ�Ҳ�Y��Ŀ��
	     */
		int m_rightVScaleWidth;
		/**
	     * ��ȡ�Ƿ����ü���Ч��
	     */
		bool m_scrollAddSpeed;
        /**
	     * ���������ķ���
	     */
		int m_scrollStep;
		/**
	     * �Ƿ���ʾʮ����
	     */
		bool m_showCrossLine;
		/**
	     * ��ʾѡ������
	     */
		bool m_showingSelectArea;
		/**
	     * �Ƿ�������ʾ��ʾ��
	     */
		bool m_showingToolTip;
		/**
	     * ��ʾ����ʾ�ӳ�tickֵ
	     */
		int m_tooltip_dely;
		/*
		* ���ڵ�����С��ͼ��
		*/
		ChartDiv *m_userResizeDiv;
		/*
		* ����������
		*/
		int m_workingAreaWidth;
	public:
	    /**
         * ��ϸ�ߣ�ֻ����ˮƽ�߻�ֱ��
         * @param paint ��ͼ����
         * @param color ��ɫ
         * @param width ���
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
        */
		virtual void drawThinLine(FCPaint *paint, Long dwPenColor, int width, int x1, int y1, int x2, int y2);
	    /**
         * ��������
         * @param paint ��ͼ����
         * @param text  ����
         * @param dwPenColor  ��ɫ
         * @param font  ����
         * @param point ����
        */
		virtual void drawText(FCPaint *paint, const wchar_t *strText, Long dwPenColor,FCFont *font, int left, int top);
	    /**
         * ��ȡ����Ŀ̶�
         * @param max   ���ֵ
         * @param min   ��Сֵ
         * @param vScale    ������
         *  @returns  �̶ȼ���
        */
		virtual ArrayList<double> getVScaleStep(double max, double min, ChartDiv *div, VScale *vScale);
	    /**
         * ���Ƴɽ���
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
         * @param bs    ��������
        */
		virtual void onPaintBar(FCPaint *paint, ChartDiv *div, BarShape *bs);
	    /**
         * ����K��
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
         * @param cs    K��
        */
		virtual void onPaintCandle(FCPaint *paint, ChartDiv *div, CandleShape *cs);
	    /**
         * ����K�ߵ���չ����
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
         * @param cs    K��
         * @param visibleMaxIndex   ���ֵ����
         * @param visibleMax    ���ֵ
         * @param visibleMinIndex   ��Сֵ����
         * @param visibleMin    ��Сֵ
        */
		virtual void onPaintCandleEx(FCPaint *paint, ChartDiv *div, CandleShape *cs, int visibleMaxIndex, double visibleMax, int visibleMinIndex, double visibleMin);
	    /**
         * ����ʮ����
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintCrossLine(FCPaint *paint, ChartDiv *div);
	    /**
         * ���Ʋ㱳��
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintDivBackGround(FCPaint *paint, ChartDiv *div);
	    /**
         * ���Ʋ�߿�
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintDivBorder(FCPaint *paint, ChartDiv *div);
	    /**
         * ���ƺ�������
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintHScale(FCPaint *paint, ChartDiv *div);
	    /**
         * ����ͼ�ε�ͼ��
         * @param paint ��ͼ����
        */
		virtual void onPaintIcon(FCPaint *paint);
	    /**
         * ���ƻ��߹���
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintPlots(FCPaint *paint, ChartDiv *div);
	    /**
         * ����������
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
         * @param ls    ��������
        */
		virtual void onPaintPolyline(FCPaint *paint, ChartDiv *div, PolylineShape *ls);
	    /**
         * ����������
         * @param paint ��ͼ����
         * @param div   ͼ��
         * @param lineColor �ߵ���ɫ
         * @param fillColor ���ɫ
         * @param ciClr ��ɫ�ֶ�
         * @param lineWidth �ߵĿ��
         * @param lineStyle �ߵ���ʽ
         * @param value ���ֵ
         * @param attachVScale  ����������
         * @param scaleX  ������
         * @param lY    ������
         * @param i     ����
         * @param points    �㼯��
         * @param x     ������
         * @param y     ������
        */
		virtual void onPaintPolyline(FCPaint *paint, ChartDiv *div, Long lineColor, Long fillColor, int ciClr,
				float lineWidth, PolylineStyle lineStyle, double value, AttachVScale attachVScale,
				int scaleX, int lY, int i, vector<FCPoint> *points, int *x, int *y);
	    /**
         * �����϶��ı���
         * @param paint ��ͼ����
        */
		virtual void onPaintResizeLine(FCPaint *paint);
	    /**
         * ����ѡ�п�
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintSelectArea(FCPaint *paint, ChartDiv *div);
	    /**
         * ����K�ߣ��ɽ����������ߵȵ�
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintShapes(FCPaint *paint, ChartDiv *div);
	    /**
         * ��������
         * @param paint ��ͼ����
         * @param div   ͼ��
         * @param ts    ����
        */
		virtual void onPaintText(FCPaint *paint, ChartDiv *div, TextShape *ts);
	    /**
         *  ���Ʊ���
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintTitle(FCPaint *paint, ChartDiv *div);
	    /**
         *  ������ʾ��
         * @param paint ��ͼ����
        */
		virtual void onPaintToolTip(FCPaint *paint);
	    /**
         *  ������������
         * @param paint ��ͼ����
         * @param div   Ҫ���ƵĲ�
        */
		virtual void onPaintVScale(FCPaint *paint, ChartDiv *div);
	protected:
	    /**
		 *  �����ɼ�����
		 * @param dataCount ��������
		 * @param first     ���ȿɼ�������
		 * @param last   ���ɼ�������
        */
		virtual void correctVisibleRecord(int dataCount, int *first, int *last);
	    /**
         *  ��ȡK�����ֵ����ʾλ��
         * @param scaleX    ������
         * @param scaleY    ������
         * @param stringWidth   ���ֵĿ��
         * @param stringHeight  ���ֵĸ߶�
         * @param actualWidth   ������
         * @param leftVScaleWidth  ���������
         * @param rightVScaleWidth  �Ҳ�������
         * @param x ���ֵ�ĺ�����
         * @param y ���ֵ��������
        */
		virtual void getCandleMaxStringPoint(float scaleX, float scaleY, float stringWidth, float stringHeight, int actualWidth,
		int leftVScaleWidth, int rightVScaleWidth, float *x, float *y);
	    /**
         * ��ȡK����Сֵ����ʾλ��
         * @param scaleX    ������
         * @param scaleY    ������
         * @param stringWidth   ���ֵĿ��
         * @param stringHeight  ���ֵĸ߶�
         * @param actualWidth   ������
         * @param leftVScaleWidth  ���������
         * @param rightVScaleWidth  �Ҳ�������
         * @param x ���ֵ�ĺ�����
         * @param y ���ֵ��������
        */
		virtual void getCandleMinStringPoint(float scaleX, float scaleY, float stringWidth, float stringHeight, int actualWidth,
		int leftVScaleWidth, int rightVScaleWidth, float *x, float *y);
	    /**
         * ��ȡĳ�����Ӧ������
         * @param x ������
         * @param leftVScaleWidth   �������ĸ߶�
         * @param hScalePixel   ���ݼ��
         * @param firstVisibleIndex ���ȿɼ�����
         * @returns  ����
        */
		virtual int getChartIndex(int x, int leftScaleWidth, double hScalePixel, int firstVisibleIndex);
	    /**
         * ��ȡ��K�ߵĸ߶�
         * @param close ���̼�
         * @param open  ���̼�
         * @param max   ��߼�
         * @param min   ��ͼ�
         * @param divPureV  ��߶�
         * @returns  �߶�
        */
		virtual float getUpCandleHeight(double close, double open, double max, double min, float divPureV);
	    /**
         * ��ȡ��K�ߵĸ߶�
         * @param close ���̼�
         * @param open  ���̼�
         * @param max   ��߼�
         * @param min   ��ͼ�
         * @param divPureV  ��߶�
         *  @returns  �߶�
        */
		virtual float getDownCandleHeight(double close, double open, double max, double min, float divPureV);
	    /**
         * ���
         * @param step  ����
         * @param dateCount ��������
         * @param hScalePixel   ���ݼ��
         * @param pureH ������
         * @param fIndex    ���ȿɼ�������
         * @param lIndex    ���ɼ�������
        */
		virtual void scrollLeft(int step, int dateCount, double hScalePixel, int pureH, int *fIndex, int *lIndex);
	    /**
        * �ҹ�
        * @param step  ����
        * @param dateCount ��������
        * @param hScalePixel   ���ݼ��
        * @param pureH ������
        * @param fIndex    ���ȿɼ�������
        * @param lIndex    ���ɼ�������
        */
		virtual void scrollRight(int step, int dataCount, double hScalePixel, int pureH, int *fIndex, int *lIndex);
	    /**
         *  ��ȡ����ĳ�����ֵ
         * @param y ������
         * @param max   ���ֵ
         * @param min   ��Сֵ
         * @param vHeight  ��߶�
         *  @returns  ��ֵ
        */
		virtual double getVScaleValue(int y, double max, double min, float vHeight);
	    /**
         *  ����ʮ��������
         * @param dataCount ��������
         * @param maxVisibleRecord  �����ʾ��¼��
         * @param crossStopIndex    ʮ��������
         * @param firstL            ���ȿɼ�������
         * @param lastL             ���ɼ�������
         * @returns  �������ʮ��������
        */
		virtual int resetCrossOverIndex(int dataCount, int maxVisibleRecord, int crossStopIndex, int firstL, int lastL);
	    /**
         * ��С
         * @param pureH ������
         * @param dataCount ��������
         * @param findex    ���ȿɼ�������
         * @param lindex    ���ɼ�������
         * @param hScalePixel   ���ݼ��
        */
		virtual void zoomIn(int pureH, int dataCount, int *findex, int *lindex, double *hScalePixel);
	    /**
		 * �Ŵ�
		 * @param pureH ������
		 * @param dataCount ��������
		 * @param findex    ���ȿɼ�������
		 * @param lindex    ���ɼ�������
		 * @param hScalePixel   ���ݼ��
        */
		virtual void zoomOut(int pureH,int dataCount, int *findex, int *lindex, double *hScalePixel);
	public:
		/*
		* ����ͼ��
		*/
		FCChart();
		/*
		* ��������
		*/
		virtual ~FCChart();
		/**
	     * ��ȡ�����Ƿ�
	     */
		virtual bool autoFillHScale();
		/**
	     * ���������Ƿ�
	     */
		virtual void setAutoFillHScale(bool autoFillHScale);
		/**
	     * ��ȡ�հ׿ռ�
	     */
		virtual int getBlankSpace();
		/**
	     * ���ÿհ׿ռ�
	     */
		virtual void setBlankSpace(int blankSpace);
		/**
	     *��ȡ�Ƿ�����϶�����
	     */
		virtual bool canMoveShape();
		/**
	     * �����Ƿ�����϶�����
	     */
		virtual void setCanMoveShape(bool canMoveShape);
		/**
	     * ��ȡ�Ƿ������ı��С
	     */
		virtual bool canResizeV();
		/**
	     * �����Ƿ������ı��С
	     */
		virtual void setCanResizeV(bool canResizeV);
		/**
	     * ��ȡ�ǿɺ���ı��С
	     */
		virtual bool canResizeH();
		/**
	     * �����ǿɺ���ı��С
	     */
		virtual void setCanResizeH(bool canResizeH);
		/**
	     * ��ȡ�Ƿ����ִ�й�������
	     */
		virtual bool canScroll();
		/**
	     * �����Ƿ����ִ�й�������
	     */
		virtual void setCanScroll(bool canScroll);
		/**
	     * ��ȡ�Ƿ����ִ�����Ų���
	     */
		virtual bool canZoom();
		/**
	     * �����Ƿ����ִ�����Ų���
	     */
		virtual void setCanZoom(bool canZoom);
		/**
	     * ��ȡʮ���ߵ��ƶ���ʽ
	     */
		virtual CrossLineMoveMode getCrossLineMoveMode();
		/**
	     * ����ʮ���ߵ��ƶ���ʽ
	     */
		virtual void setCrossLineMoveMode(CrossLineMoveMode crossLineMoveMode);
		/**
	     * ��ȡʮ���ߵ�ǰͣ���ļ�¼����
	     */
		virtual int getCrossStopIndex();
		/**
	     * ����ʮ���ߵ�ǰͣ���ļ�¼����
	     */
		virtual void setCrossStopIndex(int crossStopIndex);
		/**
	     * ��ȡ����Դ
	     */
		virtual FCDataTable* getDataSource();
		/**
	     * ��������Դ
	     */
		virtual void setDataSource(FCDataTable *dataSource);
		/**
	     * ��ȡ���ȿɼ���¼��
	     */
		virtual int getFirstVisibleIndex();
		/**
	     * �������ȿɼ���¼��
	     */
		virtual void setFirstVisibleIndex(int firstVisibleIndex);
		/**
	     * ��ȡ�����ֶε���ʾ����
	     */
		virtual String getHScaleFieldText();
		/**
	     * ���ú����ֶε���ʾ����
	     */
		virtual void setHScaleFieldText(const String& hScaleFieldText);
		/**
	     * ��ȡÿ��������X������ռ�Ŀռ�
	     */
		virtual double getHScalePixel();
		/**
	     * ����ÿ��������X������ռ�Ŀռ�
	     */
		virtual void setHScalePixel(double hScalePixel);
		/**
	     * ��ȡ���ɼ��ļ�¼��
	     */
		virtual int getLastVisibleIndex();
		/**
	     * �������ɼ��ļ�¼��
	     */
		virtual void setLastVisibleIndex(int lastVisibleIndex);
		/**
	     * ��ȡ���Y��Ŀ��
	     */
		virtual int getLeftVScaleWidth();
		/**
	     * �������Y��Ŀ��
	     */
		virtual void setLeftVScaleWidth(int leftVScaleWidth);
		/**
	     * ��ȡ��ʾ����¼��
	     */
		virtual int getMaxVisibleRecord();
		/**
	     * ������ʾ����¼��
	     */
		virtual void setMaxVisibleRecord(int maxVisibleRecord);
		/**
	     * ��ȡ�����ƶ��Ļ��߹���
	     */
		virtual FCPlot* getMovingPlot();
		/**
	     * ��ȡ���ڱ��ƶ���ͼ��
	     */
		virtual BaseShape* getMovingShape();
		/**
	     * ��ȡ�Ƿ�ת����
	     */
		virtual bool isReverseHScale();
		/**
	     * �����Ƿ�ת����
	     */
		virtual void setReverseHScale(bool reverseHScale);
		/**
	     * ��ȡ�Ҳ�Y��Ŀ��
	     */
		virtual int getRightVScaleWidth();
		/**
	     * �����Ҳ�Y��Ŀ��
	     */
		virtual void setRightVScaleWidth(int rightVScaleWidth);
		/**
	     * ��ȡ�Ƿ����ü���Ч��
	     */
		virtual bool isScrollAddSpeed();
		/**
	     * �����Ƿ����ü���Ч��
	     */
		virtual void setScrollAddSpeed(bool scrollAddSpeed);
		/**
	     * ��ȡ��ǰѡ�е�����
	     */
		virtual BaseShape* getSelectedShape();
		/**
	     * ���õ�ǰѡ�е�����
	     */
		virtual void setSelectedShape(BaseShape *baseShape);
		/**
	     * ��ȡ��ǰѡ�еĻ��߹���
	     */
		virtual FCPlot* getSelectedPlot();
		/**
	     * ���õ�ǰѡ�еĻ��߹���
	     */
		virtual void setSelectedPlot(FCPlot *selectedPlot);
		/**
	     * ��ȡ��ǰѡ�еĲ�
	     */
		virtual ChartDiv* getSelectedDiv();
		/**
	     * ���õ�ǰѡ�еĲ�
	     */
		virtual void setSelectedDiv(ChartDiv *selectedDiv);
		/**
	     * ��ȡ�Ƿ���ʾʮ����
	     */
		virtual bool isShowCrossLine();
		/**
	     * �����Ƿ���ʾʮ����
	     */
		virtual void setShowCrossLine(bool showCrossLine);
	    /**
         * ��ȡ��ȥ���������Ⱥ�ĺ�����
         *  @returns ���
        */
		virtual int getWorkingAreaWidth();
	public:
		/*
		* ��Ӳ�
		*/
		virtual ChartDiv* addDiv(int vPercent);
		/*
		* ��Ӳ�
		*/
		virtual ChartDiv* addDiv();
		/**
	     * �ɼ����ֵ����ֵ����Сֵ
	     */
		virtual void adjust();
		/**
	     * ��ָ�����ָ��λ����ӻ��߹���
	     */
		virtual void addPlot(FCPlot *bpl, const FCPoint& mp, ChartDiv *div);
		/**
	     * ���ͼ���ϵ����ݣ������ı�ͼ�νṹ
	     */
		virtual void clear();
		/**
	     * ��ͼ����в���
	     */
		virtual void changeChart(ScrollType scrollType, int limitStep);
		/**
	     * ������ɼ�����
	     */
		virtual void checkLastVisibleIndex();
		/**
	     * ��鲢������ʾ��
	     */
		virtual void checkToolTip();
		/**
	     * ȡ��ѡ������ͼ�Σ�����K�ߣ���״ͼ���ߵ�
	     */
		virtual void clearSelectedShape();
		/**
	     * ȡ��ѡ�����еĻ��߹���
	     */
		virtual void clearSelectedPlot();
		/**
	     * ȡ��ѡ�����еĲ�
	     */
		virtual void clearSelectedDiv();
		/**
	     * ����ѡ�п�
	     */
		virtual void closeSelectArea();
		/**
	     * ���ݼ�¼�Ż�ȡ�㼫ֵ
	     */
		virtual double divMaxOrMin(int index, ChartDiv *div, int flag);
		/**
	     * �������ȡ����󣬷���ͼ�����
	     */
		virtual ChartDiv* findDiv(const FCPoint& mp);
		/**
	     * ��ͼ�����ƻ�ȡ�������Ĳ㣬����ͼ�����
	     */
		virtual ChartDiv* findDiv(BaseShape *shape);
		/**
	     * ��ȡ�ؼ�����
	     */
		virtual String getControlType();
		/*
		* ��ȡ��������
		*/
		virtual int getDateType(DateType dateType);
		/*
		* ������������
		*/
		virtual DateType getDateType(int dateType);
		/**
	     * ��ȡͼ�㼯�ϵĿ���
	     */
		virtual ArrayList<ChartDiv*> getDivs();
		/**
	     * ��ȡ���������
	     */
		virtual void getHScaleDateString(double date, double lDate, DateType *dateType, wchar_t *str);
		/**
	     * ��������ȡ����Ӧ������
	     */
		virtual int getIndex(const FCPoint& mp);
		/**
	     * ��ȡ�����ʾ����
	     */
		virtual int getMaxVisibleCount(double hScalePixel, int pureH);
		/*
		* ��ȡ�����Ĳ�
		*/
		virtual ChartDiv* getTouchOverDiv();
		/**
	     * ��ȡ�������ں����¼����
	     */
		virtual int getTouchOverIndex();
		/**
	     * ��ȡ�������ֵ
	     */
		double getNumberValue(ChartDiv *div, const FCPoint& mp, AttachVScale attachVScale);
		/**
	     * ��ȡ����ֵ
	     */
		virtual void getProperty(const String& name, String *value, String *type);
		/**
	     * ��ȡ���������б�
	     */
		virtual ArrayList<String> getPropertyNames();
		/**
	     * ���ֶλ�ȡ���е�ͼ��
	     */
		virtual int getShapesCount(int field);
		/**
	     * ��ȡָ�������ĺ�����
	     */
		virtual float getX(int index);
		/**
	     * ��ȡĳһֵ��Ӧ��������
	     */
		virtual float getY(ChartDiv *div,double value,AttachVScale attach);
		/**
	     * ��ȡ����Ļ����ֶ�
	     */
		virtual int getVScaleBaseField(ChartDiv *div, VScale *vScale);
		/**
	     * ��ȡ����Ļ�׼ֵ
	     */
		virtual double getVScaleBaseValue(ChartDiv *div, VScale *vScale, int i);
		/*
		* ����������Ĳ���
		*/
		virtual int gridScale(double min, double max, int yLen, int maxSpan, int minSpan, int defCount, double *step, int *digit);
		/**
	     * �ж��Ƿ����ڲ���ͼ��
	     */
		virtual bool isOperating();
		/**
	     * ��λʮ����
	     */
		virtual void locateCrossLine();
		/**
	     * ��ͼ���ƶ�����һ������
	     */
		virtual void moveShape(ChartDiv *div, BaseShape *shape);
		/**
	     * ����ʮ���ߴ�Խ�ļ�¼��
	     */
		virtual void resetCrossOverIndex();
		/**
	     *  ����ͼ��ɾ�����е����ݣ��㣬ָ��ͻ��߹��ߵ�
	     */
		virtual void removeAll();
		/**
	     * �Ƴ�ͼ��
	     */
		virtual bool resizeDiv();
		/**
	     * �϶�ͼ��ı��С
	     */
		virtual void removeDiv(ChartDiv *div);
		/**
	     * ����
	     */
		virtual void reset();
		/**
	     * �Զ��������ȿɼ������ɼ��ļ�¼��
	     */
		virtual void resetVisibleRecord();
		/**
	     * �������
	     */
		virtual void scrollLeft(int step);
		/**
	     * ���������������ʾ��һ������Ϊֹ
	     */
		virtual void scrollLeftToBegin();
		/**
	     * �ҹ�����
	     */
		virtual void scrollRight(int step);
		/**
	     * �������ҹ�������ʾ���һ������Ϊֹ
	     */
		virtual void scrollRightToEnd();
		/**
	     * ���ʮ����
	     */
		virtual void scrollCrossLineLeft(int step);
		/**
	     * �ҹ�ʮ����
	     */
		virtual void scrollCrossLineRight(int step);
		/**
	     * ѡ�������ķ���
	     */
		virtual BaseShape* selectShape(int curIndex, int state);
		/**
	     * �ж��Ƿ�ѡ����״ͼ
	     */
		virtual bool selectBar(ChartDiv *div, float mpY, int fieldName, int fieldName2, int styleField, AttachVScale attachVScale, int curIndex);
		/**
	     * �ж��Ƿ�ѡ����״ͼ
	     */
		virtual bool selectCandle(ChartDiv *div, float mpY, int highField, int lowField, int styleField, AttachVScale attachVScale, int curIndex);
		/**
	     * �ж��Ƿ�ѡ����
	     */
		virtual bool selectPolyline(ChartDiv *div, const FCPoint& mp, int fieldName, float lineWidth, AttachVScale attachVScale, int curIndex);
		/**
	     * ��������
	     */
		virtual void setProperty(const String& name, const String& value);
		/**
	     * ����ͼ�����ȿɼ��������ź����ɼ���������
	     */
		virtual void setVisibleIndex(int firstVisibleIndex, int lastVisibleIndex);
		/**
	     * ���²���
	     */
		virtual void update();
		/**
	     * ��С
	     */
		virtual void zoomIn();
		/**
	     * �Ŵ�
	     */
		virtual void zoomOut();
	public:
		/*
		* ���̰��·���
		*/
		virtual void onKeyDown(char key);
		/**
	     * �ؼ���ӷ���
	     */
		virtual void onLoad();
		/**
	     * �����뿪�ķ���
	     */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
	     * ����̧��ķ���
	     */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
	     * �������µķ���
	     */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/*
		*  ������������
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/*
		* ����̧��ķ���
		*/
		virtual void onKeyUp(char key);
		/**
	     * �ػ�ǰ������
	     */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
	     * ���ص�����
	     */
		virtual void onTimer(int timerID);
	};
}
#endif