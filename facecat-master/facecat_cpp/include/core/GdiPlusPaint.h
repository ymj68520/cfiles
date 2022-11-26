/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __GDIPLUSPAINT_H__
#define __GDIPLUSPAINT_H__
#pragma once
#include "..\\..\\stdafx.h"
#include <comdef.h>
#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;
#include "FCPaint.h"

namespace FaceCat{
	/*
	* GDI+��ͼ��
	*/
	class GdiPlusPaint : public FCPaint{
	protected:
	    /**
		 * λͼ
		 */
		Bitmap *m_bitmap;
		/**
		 * ��ˢ
		 */
		SolidBrush *m_brush;
		/**
		 * ��ˢ����ɫ
		 */
		Long m_brushColor;
		/**
		 * �յ��ַ�����ʽ
		 */
		StringFormat *m_emptyStringFormat;
		/**
		 * ֱ�߽�����ʽ
		 */
		int m_endLineCap;
		/**
		 * ����·��
		 */
		String m_exportPath;
		/**
		 * ��ͼ����
		 */
		Graphics *m_g;
		/**
		 * �ؼ���HDC
		 */
		HDC m_hDC;
		/**
		 * ͼ�񻺴�
		 */
		map<String, Bitmap*> m_images;
		/**
		 * ����ƫ��
		 */
		int m_offsetX;
		/**
		 * ����ƫ��
		 */
		int m_offsetY;
		/**
		 * ͸����
		 */
		float m_opacity;
		/**
		 * ��ͼ·��
		 */
		GraphicsPath *m_path;
		/**
		 * ����
		 */
		Pen *m_pen;
		/**
		 * ˢ������
		 */
		FCRect m_pRect;
		/**
		 *  ���ʵ���ɫ
		 */
		Long m_penColor;
		/**
		 * ���ʵĿ��
		 */
		float m_penWidth;
		/**
		 *  ���ʵ���ʽ
		 */
		int m_penStyle;
		/**
		 * ��Դ·��
		 */
		String m_resourcePath;
		/**
		 * ��ת�Ƕ�
		 */
		int m_rotateAngle;
		/**
		 * ������������
		 */
		double m_scaleFactorX;
		/**
		 * ������������
		 */
		double m_scaleFactorY;
		/**
		 * ƽ���̶�
		 */
		int m_smoothMode;
		/**
		 * ֱ�߿�ʼ��ʽ
		 */
		int m_startLineCap;
		/**
		 * ���ֵ�����
		 */
		int m_textQuality;
		/**
		 * ���ڴ�С
		 */
		FCRect m_wRect;
	protected:
	    /**
         * ����������Ч
         * @param gdiplusRect ����
        */
		void affectScaleFactor(Rect *gdiplusRect);
	    /**
         * ����������Ч
         * @param gdiplusRect ����
        */
		void affectScaleFactor(RectF *gdiplusRect);
	    /**
         * ��ȡ��ˢ
         * @param dwPenColor ��ɫ
        */
		SolidBrush* getBrush(Long dwPenColor);
	    /**
         * ��ȡ��ɫ
         * @param dwPenColor ������ɫ
        */
		Color getGdiPlusColor(Long dwPenColor);
		int getEncoderClsid(const WCHAR *format, CLSID *pClsid);
	    /**
         * ��ȡGdi����
         * @param font   Gdi����
        */
		Gdiplus::Font* getFont(FCFont *font);
	    /**
         * ��ȡ����
         * @param dwPenColor ������ɫ
         * @param width  ���
         * @param style  ��ʽ
        */
		Pen* getPen(Long dwPenColor, float width, int style);
	    /**
         * ��ȡ����Բ�ξ��ε�·��
         * @param gdiPlusRect ����
         * @param cornerRadius  �߽ǰ뾶
        */
		GraphicsPath* getRoundRectPath(Rect gdiPlusRect, int cornerRadius);
	public:
		/*
		* ���캯��
		*/
		GdiPlusPaint();
		/*
		* ��������
		*/
		virtual ~GdiPlusPaint();
	public:
	    /**
         * �������
         * @param rect ��������
         * @param startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle  �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ��ӱ���������
         * @param points  ����
        */
		virtual void addBezier(FCPoint *apt, int cpt);
	    /**
         * �������
         * @param points  ����
        */
		virtual void addCurve(FCPoint *apt, int cpt);
	    /**
         * �����Բ
         * @param rect  ����
        */
		virtual void addEllipse(const FCRect& rect);
	    /**
         * ���ֱ��
         * @param x1 ��һ����ĺ�����
         * @param y1 ��һ����������꣨�Զ�Ϊ��λ��
         * @param x2  �ڶ�����ĺ�����
         * @param y2  �ڶ������������
        */
		virtual void addLine(int x1, int y1, int x2, int y2);
	    /**
         * ��Ӿ���
         * @param rect  ����
        */
		virtual void addRect(const FCRect& rect);
	    /**
         * �������
         * @param rect ��������
         * @param startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle  �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * �������
         * @param text ����
         * @param font ����
         * @param rect ����
        */
		virtual void addText(const wchar_t *strText, FCFont *font, const FCRect& rect);
	    /**
         * ��ʼ����
         * @param exportPath  ·��
         * @param rect ����
        */
		virtual void beginExport(const String& exportPath, const FCRect& rect);
	    /**
         * ��ʼ��ͼ
         * @param hdc HDC
         * @param wRect ��������
         * @param pRect ˢ������
        */
		virtual void beginPaint(HDC hDC, const FCRect& wRect, const FCRect& pRect);
		/**
		 * ��ʼһ��·��
		 */
		virtual void beginPath();
		/**
		 * �ü�·��
		 */
		virtual void clipPath();
		/**
		 * �������
		 */
		virtual void clearCaches();
		/**
		 * �պ�·��
		 */
		virtual void closeFigure();
		/**
		 * ����һ��·��
		 */
		virtual void closePath();
	    /**
         * ���ƻ���
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param rect ��������
         * @param startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle  �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ���ñ���������
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param points  ������1
        */
		virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ��������
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param points  ������
        */
		virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƾ���
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param rect  ��������
        */
		virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
	    /**
         * ���ƾ���
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param left  �������
         * @param top �������
         * @param right  �Ҳ�����
         * @param bottom  �ײ�����
        */
		virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	    /**
         * ����ͼƬ
         * @param imagePath  ͼƬ·��
         * @param rect  ��������
        */
		virtual void drawImage(const wchar_t *imagePath, const FCRect& rect);
	    /**
         * ����ֱ��
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param x1  ��һ����ĺ�����
         * @param y1  ��һ�����������
         * @param x2  �ڶ�����ĺ�����
         * @param y2  �ڶ������������
        */
		virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
	    /**
         * ����ֱ��
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param x  ��һ���������
         * @param y  �ڶ����������
        */
		virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
	    /**
         * ����ֱ��
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
        */
		virtual void drawPath(Long dwPenColor, float width, int style);
	    /**
         * ��������
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param rect ��������
         * @param startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle  �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ���ƶ����
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param points  �������
        */
		virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƴ���ֱ��
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param points  �㼯
        */
		virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƾ���
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param rect   ��������
        */
		virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	    /**
         * ���ƾ���
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param left  �������
         * @param top �������
         * @param right  �Ҳ�����
         * @param bottom  �ײ�����
        */
		virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
	    /**
         * ����Բ�Ǿ���
         * @param dwPenColor ��ɫ
         * @param width  ���
         * @param style  ��ʽ
         * @param rect   ��������
         * @param cornerRadius   �߽ǰ뾶
        */
		virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
	    /**
         * ��������
         * @param text ����
         * @param dwPenColor  ��ɫ
         * @param font  ����
         * @param rect   ��������
        */
		virtual void drawText(const wchar_t *strText, Long dwPenColor, FCFont *font, const FCRect& rect);
	    /**
         * ��������
         * @param text ����
         * @param dwPenColor  ��ɫ
         * @param font  ����
         * @param rect   ��������
        */
		virtual void drawText(const wchar_t *strText, Long dwPenColor, FCFont *font, const FCRectF& rect);
	    /**
         * �����Զ�ʡ�Խ�β������
         * @param text ����
         * @param dwPenColor  ��ɫ
         * @param font  ����
         * @param rect   ��������
        */
		virtual void drawTextAutoEllipsis(const wchar_t *strText, Long dwPenColor, FCFont *font, const FCRect& rect);
		/**
		 * ��������
		 */
		virtual void endExport();
		/**
		 * ������ͼ
		 */
		virtual void endPaint();
		/**
		 * ���ü�·��
		 */
		virtual void excludeClipPath();
	    /**
         * �����Բ
         * @param dwPenColor  ��ɫ
         * @param rect   ��������
        */
		virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
	    /**
         * ���ƽ�����Բ
         * @param dwFirst ��ʼ��ɫ
         * @param dwSecond  ������ɫ
         * @param rect   ��������
         * @param angle   �Ƕ�
        */
		virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	    /**
         * ��佥��·��
         * @param dwFirst ��ʼ��ɫ
         * @param dwSecond  ��ʼ��ɫ
         * @param points   ��ļ���
         * @param angle   �Ƕ�
        */
		virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	    /**
         * ���ƽ���Ķ����
         * @param dwFirst ��ʼ��ɫ
         * @param dwSecond  ��ʼ��ɫ
         * @param points   ��ļ���
         * @param angle   �Ƕ�
        */
		virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
	    /**
         * ���ƽ������
         * @param dwFirst ��ʼ��ɫ
         * @param dwSecond  ��ʼ��ɫ
         * @param rect  ����
         * @param cornerRadius   �߽ǰ뾶
         * @param angle   �Ƕ�
        */
		virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
	    /**
         * ���·��
         * @param dwPenColor ��ɫ
        */
		virtual void fillPath(Long dwPenColor);
	    /**
         * ��������
         * @param dwPenColor ��ɫ
         * @param rect ��������
         * @param startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle  �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * �������
         * @param dwPenColor ��ɫ
         * @param points �������
        */
		virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
	    /**
         * ������
         * @param dwPenColor ��ɫ
         * @param rect ��������
        */
		virtual void fillRect(Long dwPenColor, const FCRect& rect);
	    /**
         * ������
         * @param dwPenColor ��ɫ
         * @param left  �������
         * @param top �������
         * @param right  �Ҳ�����
         * @param bottom  �ײ�����
        */
		virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
	    /**
         * ���Բ�Ǿ���
         * @param dwPenColor ��ɫ
         * @param rect  ��������
         * @param cornerRadius �߽ǰ뾶
        */
		virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
	    /**
         * ��ȡ��ɫ
         * @param dwPenColor ������ɫ
        */
		virtual Long getColor(Long dwPenColor);
	    /**
         * ��ȡҪ���Ƶ���ɫ
         * @param dwPenColor ������ɫ
        */
		virtual Long getPaintColor(Long dwPenColor);
		/**
		 * ��ȡƫ��
		 */
		virtual FCPoint getOffset();
	    /**
         * ��ת�Ƕ�
         * @param op Բ������
         * @param mp  �������
         * @param angle   �Ƕ�
        */
		virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
	    /**
         * ���òü�����
         * @param rect ����
        */
		virtual void setClip(const FCRect& rect);
	    /**
         * ����ֱ�����˵���ʽ
         * @param startLineCap ��ʼ����ʽ
         * @param endLineCap  ��������ʽ
        */
		virtual void setLineCap(int startLineCap, int endLineCap);
	    /**
         * ����ƫ��
         * @param mp  ƫ������
        */
		virtual void setOffset(const FCPoint& offset);
	    /**
         * ����͸����
         * @param opacity  ͸����
        */
		virtual void setOpacity(float opacity);
	    /**
         * ������Դ��·��
         * @param resourcePath  ��Դ��·��
        */
        virtual void setResourcePath(const String& resourcePath);
	    /**
         * ������ת�Ƕ�
         * @param rotateAngle  ��ת�Ƕ�
        */
		virtual void setRotateAngle(int rotateAngle);
	    /**
         * ������������
         * @param scaleFactorX ��������
         * @param scaleFactorY  ��������
        */
		virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
	    /**
         * ����ƽ��ģʽ
         * @param smoothMode  ƽ��ģʽ
        */
		virtual void setSmoothMode(int smoothMode);
	    /**
         * �������ֵ�����
         * @param textQuality  ��������
        */
		virtual void setTextQuality(int textQuality);
		/**
		 * �����Ƿ�֧��͸��ɫ
		 */
		virtual bool supportTransparent();
	    /**
         * ��ȡ���ִ�С
         * @param text ����
         * @param font  ����
        */
		virtual FCSize textSize(const wchar_t *strText, FCFont *font);
	    /**
         * ��ȡ���ִ�С
         * @param text ����
         * @param font  ����
        */
		virtual FCSizeF textSizeF(const wchar_t *strText, FCFont *font);
	};
}

#endif