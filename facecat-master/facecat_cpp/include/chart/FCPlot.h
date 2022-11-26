/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCPLOT_H__
#define __FCPLOT_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "..\\core\\FCNative.h"
#include "..\\core\\FCPaint.h"
#include "ChartDiv.h"
#include "FCChart.h"
#include "FCDataTable.h"
#include "FCPlot.h"

namespace FaceCat{
	class ChartDiv;
	class FCDataTable;
	class FCChart;
	class FCNative;
	class FCPlot;

	/*
	* ����ֵ�ļ���
	*/
	class PlotMark{
	public:
		/*
		* ����һ����ֵ
		*/
		PlotMark(int index, double key, double value){
			Index = index;
			Key = key;
			Value = value;
		}
		/*
		* ����
		*/
		int Index;
		/*
		* ��
		*/
		double Key;
		/*
		* ֵ
		*/
		double Value;
		/*
		* ����
		*/
		PlotMark* copy(){
			PlotMark *plotMark = new PlotMark(Index, Key, Value);
			return plotMark;
		}
	};

	/*
	* ���߹��ߵĻ���
	*/
	class FCPlot{
	protected:
	    /**
	     * �ƶ�����
	     */
		ActionType m_action;
		AttachVScale m_attachVScale;
		/**
	     * �ߵ���ɫ
	     */
		Long m_color;
		/**
	     * ����Դ
	     */
		FCDataTable *m_dataSource;
		/**
	     * ����ͼ��
	     */
		ChartDiv *m_div;
		/**
	     * �Ƿ��ƶ���Ӱ
	     */
		bool m_drawGhost;
		/**
	     * �Ƿ����ѡ�л��Ϸ�
	     */
		bool m_enabled;
		/**
	     * ����
	     */
		FCFont *m_font;
		/**
	     * �Ƿ����ڻ�����Ӱ
	     */
		bool m_isPaintingGhost;
		/**
	     * �ߵ���ʽ��nullΪʵ��
	     */
		int m_lineStyle;
		/**
	     * �ߵĿ��
	     */
		int m_lineWidth;
		/**
	     * �ؼ���
	     */
		HashMap<int,PlotMark*> m_marks;
		/**
	     * �ƶ�����
	     */
		int m_moveTimes;
		/**
	     * ����������
	     */
		String m_plotType;
		/**
	     * Դ�ֶ�
	     */
		HashMap<String,int> m_sourceFields;
		/**
	     * ��ʼ�ƶ�ʱ��ֵ
	     */
		HashMap<int,PlotMark*> m_startMarks;
		/**
	     * �Ƿ�ѡ��
	     */
		bool m_selected;
		/**
	     * ѡ��ɫ
	     */
		Long m_selectedColor;
		/**
	     * ѡ�е����ʽ
	     */
		SelectPoint m_selectedPoint;
		/**
	     * ��ʼ�ƶ��ĵ�
	     */
		FCPoint m_startPoint;
		/**
	     * ��ʾ������
	     */
		String m_text;
		/**
	     * �ɼ���
	     */
		bool m_visible;
		/**
	     * ͼ��˳��
	     */
		int m_zOrder;
	protected:
	    /**
         * ����Բ
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param width ���
         * @param style ��ʽ
         * @param left  ������
         * @param top   ������
         * @param right �Ҳ������
         * @param bottom   �Ҳ�������
        */
		void drawEllipse(FCPaint *paint, Long dwPenColor, int width, int style, const FCRect& rect);
		void drawEllipse(FCPaint *paint, Long dwPenColor, int width, int style, int left, int top, int right, int bottom);
		void drawEllipse(FCPaint *paint, Long dwPenColor, int width, int style, float left, float top, float right, float bottom);
	    /**
         * ���߷���
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param width ���
         * @param style ��ʽ
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
        */
		void drawLine(FCPaint *paint, Long dwPenColor, int width, int style, const FCPoint& x, const FCPoint& y);
		void drawLine(FCPaint *paint, Long dwPenColor, int width, int style, int x1, int y1, int x2, int y2);
		void drawLine(FCPaint *paint, Long dwPenColor, int width, int style, float x1, float y1, float x2, float y2);
		void drawPolygon(FCPaint *paint, Long dwPenColor, int width, int style, FCPoint *apt, int cpt);
	    /**
         * ������
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param width ���
         * @param style ��ʽ
         * @param points    ��ļ���
        */
		void drawPolyline(FCPaint *paint, Long dwPenColor, int width, int style, FCPoint *apt, int cpt);
	    /**
         * ������
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param width ���
         * @param style ��ʽ
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
         * @param k     ֱ�߲���k
         * @param b     ֱ�߲���b
        */
		void drawRay(FCPaint *paint, Long dwPenColor, int width, int style, float x1, float y1, float x2, float y2, float k, float b);
	    /**
         * ������
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param width ���
         * @param style ��ʽ
         * @param left  ������
         * @param top   ������
         * @param right �Ҳ������
         * @param bottom    �Ҳ�������
        */
		void drawRect(FCPaint *paint, Long dwPenColor, int width, int style, int left, int top, int right, int bottom);
	    /**
         * ������
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param width ���
         * @param style ��ʽ
         * @param left  ������
         * @param top   ������
         * @param right �Ҳ������
         * @param bottom    �Ҳ�������
        */
		void drawRect(FCPaint *paint, Long dwPenColor, int width, int style, const FCRect& rect);
	    /**
         * ����ѡ�е�
         * @param paint ��ͼ����
         * @param dwPenColor    ��ɫ
         * @param x     ������
         * @param y     ������
        */
		void drawSelect(FCPaint *paint, Long dwPenColor, int x, int y);
		void drawSelect(FCPaint *paint, Long dwPenColor, float x, float y);
	    /**
         * ������
         * @param paint ��ͼ����
         * @param text  ����
         * @param dwPenColor    ��ɫ
         * @param font  ����
         * @param x     ������
         * @param y     ������
        */
		void drawText(FCPaint *paint, const wchar_t *strText, Long dwPenColor, FCFont *font, int left, int top);
		void fillEllipse(FCPaint *paint, Long dwPenColor, const FCRect& rect);
	    /**
         * �������
         * @param paint ��ͼ����
         * @param color ��ɫ
         * @param points   ��ļ���
        */
		void fillPolygon(FCPaint *paint, Long dwPenColor, FCPoint *apt, int cpt);
		void fillRect(FCPaint *paint, Long dwPenColor, const FCRect& rect);
	    /**
         * ��ȡ���ֵĴ�С
         * @param paint ��ͼ����
         * @param text  ����
         * @param font  ����
         *  @returns  ��С
        */
		FCSize textSize(FCPaint *paint, const wchar_t *strText, FCFont *font);
	protected:
	    /**
         * �ƶ�����
         * @param touchY    ������
         * @param startY    ��ʼ������
         * @param startIndex  ��ʼ����
         * @param touchBeginIndex   ������ʼ����
         * @param touchEndIndex     ������������
         * @param pureV �������
         * @param max   ���ֵ
         * @param min   ��Сֵ
         * @param dataCount ��������
         * @param yAddValue ����仯ֵ
         * @param newIndex  �µ�����
        */
		void movePlot(float touchY, float startY, int startIndex, int touchBeginIndex, int touchEndIndex, float pureV,
		double max, double min, int dataCount, double *yAddValue, int *newIndex);
	protected:
		void clearMarks(HashMap<int,PlotMark*> *marks);
		FCNative* getNative();
	    /**
         * ��ʼ��һ�������͵�ͨ�÷���
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		bool createPoint(const FCPoint& mp);
	    /**
         * ��ʼ�����������͵�ͨ�÷���
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		bool create2PointsA(const FCPoint& mp);
	    /**
         * ��ʼ�����������͵�ͨ�÷���
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		bool create2PointsB(const FCPoint& mp);
	    /**
         * ��ʼ����K�ߵ�ķ���
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		bool create2CandlePoints(const FCPoint& mp);
	    /**
         * ��ʼ�����������͵�ͨ�÷���
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		bool create3Points(const FCPoint& mp);
	    /**
         * ��ʼ����ӦK���ϵĵ�
         * @param pos   λ��
         * @param index ����
         * @param close ���̼��ֶ�
        */
		void createCandlePoint(int pos, int index, int close);
	    /**
         * ��ʼ�ĸ�K�ߵ�ķ���
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		bool create4CandlePoints(const FCPoint& mp);
	    /**
         * ��ȡK����������߼ۺ���ͼ�
         * @param pList ���󼯺�
         *  @returns  ���ȳߵĲ���
        */
		double* getCandleRange(HashMap<int,PlotMark*> *pList);
		FCPoint getTouchOverPoint();
	    /**
         * ���������ȡ����
         * @param mp    ����
         *  @returns  ����
        */
		int getIndex(const FCPoint& mp);
	    /**
         * ��ȡֱ�ߵĲ���
         * @param markA ��һ����
         * @param markB �ڶ�����
         *  @returns  ֱ�ߵĲ���
        */
		float* getLineParams(PlotMark *markA, PlotMark *markB);
	    /**
         * ��ȡ���Իع���ĸߵ͵�ƫ��ֵ
         * @param pList ���󼯺�
         * @param param ֱ�߲���
         *  @returns  �ߵ͵�ƫ��ֵ
        */
		double* getLRBandRange(HashMap<int,PlotMark*> *marks, float *param);
	    /**
         * ��ȡ���Իع�Ĳ���
         * @param marks ���󼯺�
         *  @returns  ��������
        */
		float* getLRParams(HashMap<int,PlotMark*> *marks);
	    /**
	     * ��ȡ�ƶ�����
		 */
		FCPoint getMovingPoint();
	    /**
         * ���������ȡ��ֵ
         * @param mp    ����
         *  @returns  ��ֵ
        */
		double getNumberValue(const FCPoint& mp);
	    /**
         * ��ȡƫ�ƺ�����
         *  @returns  ƫ�ƺ�����
        */
		int getPx();
	    /**
         * ��ȡƫ��������
         *  @returns  ƫ��������
        */
		int getPy();
	    /**
         * ���������ȡ����
         * @param markA ��һ����
         * @param markB �ڶ�����
         *  @returns  ���ζ���
        */
		FCRect getRectangle(PlotMark *markA, PlotMark *markB);
	    /**
         * ��ȡ�ƽ�ָ��ߵ�ֱ�߲���
         * @param value1  ֵ1
         * @param value2    ֵ2
         *  @returns  �ƽ�ָ��ߵ�ֱ�߲���
        */
		float* goldenRatioParams(double value1, double value2);
	    /**
         * �������ߵ�ѡ�з���
         * @param param ����
         * @param length    ����
         *  @returns  �Ƿ�ѡ��
        */
		bool hLinesSelect(float *param, int length);
	    /**
         * �ƶ�����
         * @param mp    ����
        */
		void move(const FCPoint& mp);
	    /**
         * ��ͼ����
         * @param paint ��ͼ����
        */
		virtual void onPaint(FCPaint *paint);
		/**
	     * ����ͼ��Ĳ�Ӱ
		 */
		virtual void onPaintGhost(FCPaint *paint);
	    /**
         * ����ͼ��ķ���
         * @param paint ��ͼ����
         * @param pList ����ֵ����
         * @param lineColor ��ɫ
        */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	    /**
         * ��ȡ���ƺ�����
         * @param index ����
         *  @returns  ������
        */
		float pX(int index);
	    /**
         * ��ȡ����������
         * @param value ֵ
         *  @returns  ������
        */
		float pY(double value);
	    /**
         * ���ݺ������ȡ���߹����ڲ�������
         * @param x ������
         *  @returns  �ڲ�������
        */
		float pX(float x);
	    /**
         * ���ݺ������ȡ���߹����ڲ�������
         * @param y     ������
         *  @returns  �ڲ�������
        */
		float pY(float y);
	    /**
         * ������С
         * @param index ����
        */
		void resize(int index);
	    /**
         * ���µ�����С
         * @param mp    ����
         * @param oppositePoint ��λ��
        */
		void resize(const FCPoint& mp, FCPoint oppositePoint);
	    /**
         * �ж��Ƿ�ѡ����ָ���ĵ�
         * @param mp    ����
         * @param x     ��ĺ�����
         * @param y     ���������
         *  @returns      �Ƿ�ѡ��
        */
		bool selectPoint(const FCPoint& mp, float x, float y);
	    /**
         * �ж��Ƿ�ѡ����
         * @param mp    ���λ��
         * @param x     ������
         * @param k     ֱ�߲���k
         * @param b     ֱ�߲���b
         *  @returns      �Ƿ�ѡ����
        */
		bool selectLine(const FCPoint& mp, float x, float k, float b);
	    /**
         * �ж��Ƿ�ѡ����
         * @param mp    ���λ��
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
        */
		bool selectLine(const FCPoint& mp, float x1, float y1, float x2, float y2);
	    /**
         * �ж��Ƿ�ѡ������
         * @param mp    ���λ��
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
         * @param k     ֱ�߲���k
         * @param b     ֱ�߲���b
         *  @returns      �Ƿ�ѡ������
        */
		bool selectRay(const FCPoint& mp, float x1, float y1, float x2, float y2, float *pk, float *pb);
	    /**
         * �ж��Ƿ�ѡ������
         * @param mp    ���λ��
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
         *  @returns      �Ƿ�ѡ������
        */
		bool selectRay(const FCPoint& mp, float x1, float y1, float x2, float y2);
	    /**
         * ��ȡѡ��״̬
         * @param mp    ���λ��
         * @param markA ��A
         * @param markB ��B
         *  @returns      ѡ��״̬
        */
		ActionType selectRect(const FCPoint& mp, PlotMark *markA, PlotMark *markB);
	    /**
         * �ж��Ƿ�ѡ���߶�
         * @param mp    ���λ��
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
         *  @returns      �Ƿ�ѡ���߶�
        */
		bool selectSegment(const FCPoint& mp, float x1, float y1, float x2, float y2);
	    /**
         * �ж��Ƿ�ѡ��������
         * @param mp    ���λ��
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
         *  @returns      �Ƿ�ѡ��������
        */
		bool selectSine(const FCPoint& mp,float x1, float y1, float x2, float y2);
	    /**
         * �ж��Ƿ�ѡ��������
         * @param mp    ���λ��
         * @param x1    ��һ����ĺ�����
         * @param y1    ��һ�����������
         * @param x2    �ڶ�����ĺ�����
         * @param y2    �ڶ������������
         * @param x3    ��������ĺ�����
         * @param y3    ���������������
         *  @returns      �Ƿ�ѡ��������
        */
		bool selectTriangle(const FCPoint& mp, float x1, float y1, float x2, float y2, float x3, float y3);
		/*
		* ���ù��
		* @param cursor ���
		*/
		void setCursor(FCCursors cursor);
	public:
		/*
		* ��������
		*/
		FCPlot();
		/*
		* ���ٻ���
		*/
		virtual ~FCPlot();
		/**
	     * ��ȡ���������ỹ������
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * �ø��������ỹ������
	     */
		virtual void setAttachVScale(AttachVScale attachVScale);
		/**
	     * ��ȡ�ߵ���ɫ
	     */
		virtual Long getColor();
		/**
	     * �����ߵ���ɫ
	     */
		virtual void setColor(Long color);
		/**
	     * ��ȡ����ͼ��
	     */
		virtual ChartDiv* getDiv();
		/**
	     * ��������ͼ��
	     */
		virtual void setDiv(ChartDiv *div);
		/**
	     * ��ȡ�Ƿ��ƶ���Ӱ
	     */
		virtual bool drawGhost();
		/**
	     * �����Ƿ��ƶ���Ӱ
	     */
		virtual void setDrawGhost(bool drawGhost);
		/**
	     * ��ȡ�Ƿ����ѡ�л��Ϸ�
	     */
		virtual bool isEnabled();
		/**
	     * �����Ƿ����ѡ�л��Ϸ�
	     */
		virtual void setEnabled(bool enabled);
		/**
	     * ��ȡ����
	     */
		virtual FCFont* getFont();
		/**
	     * ��������
	     */
		virtual void setFont(FCFont *font);
		/**
	     * �����Ƿ��ѱ�����
	     */
		virtual FCChart* getChart();
		/**
	     * ��ȡ�ߵ���ʽ��nullΪʵ��
	     */
		virtual int getLineStyle();
		/**
	     * �����ߵ���ʽ��nullΪʵ��
	     */
		virtual void setLineStyle(int lineStyle);
		/**
	     * ��ȡ�ߵĿ��
	     */
		virtual int getLineWidth();
		/**
	     * �����ߵĿ��
	     */
		virtual void setLineWidth(int lineWidth);
		/**
	     * ��ȡ����������
	     */
		virtual String getPlotType();
		/**
	     * ��������������
	     */
		virtual void setPlotType(const String& plotType);
		/**
	     * ��ȡ�Ƿ�ѡ��
	     */
		virtual bool isSelected();
		/**
	     * �����Ƿ�ѡ��
	     */
		virtual void setSelected(bool selected);
		/**
	     * ��ȡѡ��ɫ
	     */
		virtual Long getSelectedColor();
		/**
	     * ����ѡ��ɫ
	     */
		virtual void setSelectedColor(Long selectedColor);
		/**
	     * ��ȡѡ�е����ʽ
	     */
		virtual enum SelectPoint getSelectedPoint();
		/**
	     * ����ѡ�е����ʽ
	     */
		virtual void setSelectedPoint(enum SelectPoint selectedPoint);
		/**
	     * ��ȡ��ʾ������
	     */
		virtual String getText();
		/**
	     * ��ȡ��ʾ������
	     */
		virtual void setText(const String& text);
		/**
	     * ��ȡ�ɼ���
	     */
		virtual bool isVisible();
		/**
	     * ���ÿɼ���
	     */
		virtual void setVisible(bool visible);
	    /**
         * ��ȡ������
         *  @returns  ���
        */
		virtual int getWorkingAreaWidth();
	    /**
         * ��ȡ����߶�
         *  @returns  �߶�
        */
		virtual int getWorkingAreaHeight();
		/**
	     * ��ȡͼ��˳��
	     */
		virtual int getZOrder();
		/**
	     * ����ͼ��˳��
	     */
		virtual void setZOrder(int zOrder);
	public:
	    /**
         * ��ȡ����
         *  @returns ��������
        */
		virtual ActionType getAction();
	    /**
         * ��ʼ������
         * @param mp    ����
         *  @returns  �Ƿ��ʼ���ɹ�
        */
		virtual bool onCreate(const FCPoint& mp);
		/*
		* �ƶ���ʼ
		*/
		virtual void onMoveBegin();
		/**
	     * �ƶ�����
	     */
		virtual void onMoveEnd();
		/**
	     * �ƶ���ʼ
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�
	     */
		virtual void onMoving();
	    /**
         * �ж�ѡ��
         *  @returns  �Ƿ�ѡ��
        */
		virtual bool onSelect();
	    /**
         * ���Ƶ�ͼ����
         * @param paint ��ͼ����
        */
		virtual void render(FCPaint *paint);
	public:
		/*
		* ������Բ�Ĳ���
		*/
		static void ellipseAB(float width,  float height,  float *a,  float *b);
		/*
		* �жϵ��Ƿ��ڡ���Բ��
		*/
        static bool ellipseHasPoint(float x, float y, float oX, float oY, float a, float b);
		/*
		* ������������Բ��
		*/
        static void ellipseOR(float x1, float y1, float x2, float y2, float x3, float y3, float *oX, float *oY, float *r);
		/*
		* ��ȡֱ�ߵ�б��
		*/
        static double lineSlope(float x1,  float y1,  float x2,  float y2,  float oX,  float oY);
		/*
		* ��ȡֱ�ߵĲ���
		*/
        static void lineXY(float x1,  float y1,  float x2,  float y2,  float oX,  float oY,  float *k,  float *b);
		/*
		* ����ƽ���ı��ε��ĸ���
		*/
        static void parallelogram(float x1, float y1, float x2, float y2, float x3, float y3, float *x4, float *y4);
		/*
		* ����������������
		*/
        static void rectangleXYWH(int x1, int y1, int x2, int y2, int *x, int *y, int *w, int *h);
	};
}
#endif