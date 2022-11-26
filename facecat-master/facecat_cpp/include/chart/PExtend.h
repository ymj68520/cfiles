/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __PEXTEND_H__
#define __PEXTEND_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCPlot.h"
#include "FCPlot.h"

namespace FaceCat{
	class FCPlot;

	class AndrewSpitchfork:public FCPlot{
	public:
	    /**
	     * ����³˹�ɲݲ�
	     */
		AndrewSpitchfork();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class AngleLine:public FCPlot{
	public:
	    /**
	     * �����Ƕ���
	     */
		AngleLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class CircumCircle:public FCPlot{
	public:
	    /**
	     * ���Բ
	     */
		CircumCircle();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class ArrowSegment:public FCPlot{
	public:
	    /**
	     * ������ͷ�߶�
	     */
		ArrowSegment();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};
	class DownArrow:public FCPlot{
	protected:
		FCRect getDownArrowRect(float x, float y, float width);
	public:
	    /**
	     * �����µ���ͷ
	     */
		DownArrow();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};
	class DropLine:public FCPlot{
	protected:
	    /**
	     *��ȡ����
	     */
		float* getDropLineParams(HashMap<int, PlotMark*> *pList);
	public:
	    /**
	     * �����½�45����
	     */
		DropLine();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Ellipse:public FCPlot{
	public:
	    /**
	     * ��Բ
	     */
		Ellipse();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class FiboEllipse:public FCPlot{
	protected:
	    /**
	     * 쳲�Բ�Ĳ���
	     */
		float* fibonacciEllipseParam(HashMap<int, PlotMark*> *pList);
	public:
	    /**
	     * ����쳲�Բ
	     */
		FiboEllipse();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ��ͼ��
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class FiboFanline:public FCPlot{
	public:
	    /**
	     * 쳲�����
	     */
		FiboFanline();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class FiboTimeZone:public FCPlot{
	protected:
	    /**
	     * ��ȡ쳲������ߵĲ���
	     */
		ArrayList<int> getFibonacciTimeZonesParam(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * ����쳲�������
	     */
		FiboTimeZone();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class GannBox:public FCPlot{
	protected:
		FCPoint m_oppositePoint;
	public:
	    /**
	     * ������
	     */
		GannBox();
		/**
	     * ��ȡ��������
	     */
		virtual ActionType getAction();
		/**
	     * ��ȡѡ��״̬
	     */
		ActionType getClickStatus();
		/**
	     * ��ȡ���������Ҫ��
	     */
		FCPoint* getGannBoxPoints(float x1, float y1, float x2, float y2);
		/**
	     * ��ʼ������
	     */
		virtual bool onCreate(const FCPoint& mp);
		/**
	     * ��ʼ�ƶ����߹���
	     */
		virtual void onMoveStart();
		/**
	     * �ƶ�����
	     */
		virtual void onMoving();
		/**
	     * ����ͼ��Ĳ�Ӱ
	     */
		virtual void onPaintGhost(FCPaint *paint);
		/**
	     * ����ͼ��ķ���
	     */
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class GannLine:public FCPlot{
	public:
	    /**
	     * ����������
	     */
		GannLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class GoldenRatio:public FCPlot{
	public:
	    /**
	     * �ƽ�ָ���
	     */
		GoldenRatio();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class HLine:public FCPlot{
	public:
	    /**
	     * ����ˮƽ��
	     */
		HLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class LevelGrading:public FCPlot{
	protected:
	    /**
	     * ��ȡ�ߵ��Ƶ���ֱ�߲���
	     */
		float* levelGradingParams(double value1, double value2);
	public:
	    /**
	     * �����ߵ��Ƶ�
	     */
		LevelGrading();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Line:public FCPlot{
	public:
	    /**
	     * ����ֱ��
	     */
		Line();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class LrBand:public FCPlot{
	public:
	    /**
	     * �������Իع��
	     */
		LrBand();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class LrChannel:public FCPlot{
	public:
	    /**
	     * �����ع�ͨ��
	     */
		LrChannel();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class LrLine:public FCPlot{
	public:
	    /**
	     * �������Իع�
	     */
		LrLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class NullPoint:public FCPlot{
	protected:
	    /**
	     * ����������
	     */
		void nullPoint(float x1, float y1, float x2, float y2, float *nullX, float *nullY);
		/**
	     * ��ȡ������Ĳ���
	     */
		double* getNullPointParams(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * ����������
	     */
		NullPoint();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Parallel:public FCPlot{
	protected:
	    /**
	     * ��ȡƽ��ֱ�ߵĲ���
	     */
		float* getParallelParams(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * ����ƽ����
	     */
		Parallel();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Percent:public FCPlot{
	protected:
		float* getPercentParams(double value1, double value2);
	public:
	    /**
	     * �����ٷֱ���
	     */
		Percent();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Periodic:public FCPlot{
	protected:
		int m_period;
		int m_beginPeriod;
	public:
	    /**
	     * ����������
	     */
		Periodic();
		virtual ActionType getAction();
		ArrayList<double> getPLParams(HashMap<int,PlotMark*> *pList);
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Price:public FCPlot{
	protected:
		FCSize m_textSize;
	public:
	    /**
	     * �����۸�ǩ��
	     */
		Price();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class RangeRuler:public FCPlot{
	public:
	    /**
	     * �������ȳ�
	     */
		RangeRuler();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class RaseLine:public FCPlot{
	public:
	    /**
	     * ��������45����
	     */
		RaseLine();
		float* getRaseLineParams(HashMap<int,PlotMark*> *pList);
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Ray:public FCPlot{
	public:
	    /**
	     * ��������
	     */
		Ray();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class RectLine:public FCPlot{
	protected:
		FCPoint m_oppositePoint;
	public:
		RectLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Segment:public FCPlot{
	public:
	    /**
	     * �����߶�
	     */
		Segment();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Sine:public FCPlot{
	public:
	    /**
	     * ����������
	     */
		Sine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class SpeedResist:public FCPlot{
	public:
	    /**
	     * ����������
	     */
		SpeedResist();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class SeChannel:public FCPlot{
	protected:
		double getSEChannelSD(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * ������׼���ͨ��
	     */
		SeChannel();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class SymmetricLine:public FCPlot{
	public:
	    /**
	     * �����Գ���
	     */
		SymmetricLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class SymmetricTriangle:public FCPlot{
	protected:
		float* getSymmetricTriangleParams(HashMap<int,PlotMark*> *pList);
	public:
		SymmetricTriangle();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class TimeRuler:public FCPlot{
	protected:
		double* getTimeRulerParams(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * ����ʱ���
	     */
		TimeRuler();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart(); 
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Triangle:public FCPlot{
	public:
	    /**
	     * ����������
	     */
		Triangle();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};
	class UpArrow:public FCPlot{
	protected:
		FCRect getUpArrowRect(float x, float y, float width);
	public:
	    /**
	     * �������Ǽ�ͷ
	     */
		UpArrow();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class VLine:public FCPlot{
	public:
	    /**
	     * ������ֱ��
	     */
		VLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class WaveRuler:public FCPlot{
	protected:
		float* getWaveRulerParams(double value1, double value2);
	public:
	    /**
	     * �������˳�
	     */
		WaveRuler();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class TironeLevels:public FCPlot{
	protected:
		double* getTironelLevelsParams(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * ����̩��ˮƽ��
	     */
		TironeLevels();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class RaffChannel:public FCPlot{
	protected:
		double getRRCRange(HashMap<int,PlotMark*> *pList, float *param);
	public:
	    /**
	     * ���������ع�ͨ��
	     */
		RaffChannel();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class QuadrantLines:public Percent{
	public:
	    /**
	     * �����ĵȷ���
	     */
		QuadrantLines();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class BoxLine:public RectLine{
	protected:
		ActionType getAction(const FCPoint& mp);
	public:
	    /**
	     * ����������
	     */
		BoxLine();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class ParallelGram:public FCPlot{
	public:
		ParallelGram();
		virtual ActionType getAction();
		FCPoint* getPLPoints(HashMap<int,PlotMark*> *pList);
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaintGhost(FCPaint *paint);
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Circle:public FCPlot{
	public:
	    /**
	     * ����Բ
	     */
		Circle();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class PriceChannel:public Parallel{
	protected:
		void getLine3Params(HashMap<int,PlotMark*> *pList, float *k, float *d, float *x4);
		void paintEx(FCPaint *paint, HashMap<int,PlotMark*> *pList,Long lineColor);
	public:
	    /**
	     * �����۸�ͨ����
	     */
		PriceChannel();
		virtual ActionType getAction();
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint);
        virtual void onPaintGhost(FCPaint *paint);
	};

	class Gp:public FCPlot{
	public:
	    /**
	     * �����ƽ�ָ��λ��
	     */
		Gp();
		virtual ActionType getAction();
		virtual bool onCreate(const FCPoint& mp);
		virtual void onMoveStart();
		virtual void onMoving();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class Ga:public Triangle{
	protected:
		float* getGoldenRatioAimParams(HashMap<int,PlotMark*> *pList);
	public:
	    /**
	     * �����ƽ�ָ�Ŀ����
	     */
		Ga();
		virtual ActionType getAction();
		virtual void onMoveStart();
		virtual void onPaint(FCPaint *paint, HashMap<int,PlotMark*> *pList, Long lineColor);
	};

	class PFactory{
	public:
		/*
		* ��������
		*/
		static FCPlot* createPlot(const String& plotType);
	};
}
#endif