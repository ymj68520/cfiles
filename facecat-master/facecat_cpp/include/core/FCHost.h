/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCHOST_H__
#define __FCHOST_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCStr.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCNative.h"

namespace FaceCat{
	class FCView;
	class FCNative;

    /**
     * �ؼ�����
     */
	class FCHost{
	public:
		/*
		* ���캯��
		*/
		FCHost();
		/*
		* ��������
		*/
		virtual ~FCHost();
		/**
		 * ��ȡ������
		 */
		virtual FCNative* getNative();
		/**
		 * ���÷�����
		 */
		virtual void setNative(FCNative *native);
	public:
		/*
		* �����
		*/
		virtual void activeMirror();
		/**
		 * �Ƿ��������
		 */
		virtual bool allowOperate();
		/**
		 * �Ƿ�����ֲ���ͼ
		 */
		virtual bool allowPartialPaint();
		/**
		 * �ڿؼ����߳��е��÷���
		 */
		virtual void beginInvoke(FCView *control, Object args);
		/**
		 * �����ı�
		 */
		virtual void copy(string text);
		/**
		 * �����ڲ��ؼ�
		 */
		virtual FCView* createInternalControl(FCView *parent, const String& clsid);
		/*
		* ��ȡ�����״
		*/
        virtual FCCursors getCursor();
        /**
         * ��ȡ�����ཻ��
         *
         * @param lpDestRect    �ཻ����
         * @param lpSrc1Rect    ����1
         * @param lpSrc2Rect    ����2
         * @returns �Ƿ��ཻ
         */
		virtual int getIntersectRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
        /**
		 * ��ȡ����λ��
		 */
        virtual FCPoint getTouchPoint();
        /**
		 * ��ȡ�ߴ�
		 */
        virtual FCSize getSize();
		/*
		* ��ȡ����������
		*/
		virtual int getUnionRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
		/**
		 * ˢ�»�ͼ
		 */
		virtual void invalidate();
	    /**
         *  ˢ�»�ͼ
         * @param rect ����
         */
        virtual void invalidate(const FCRect& rect);
        /**
         *  �ڿؼ����߳��е��÷���
         * @param control �ؼ�
         * @param args  ����
         */
		virtual void invoke(FCView *control, Object args);
		/*
		* �����Ƿ񱻰���
		*/
		virtual bool isKeyPress(char key);
		/**
		 * ��ȡճ���ı�
		 */
		virtual string paste();
		/**
		 * �����Ƿ��������
		 */
		virtual void setAllowOperate(bool allowOperate);
		/**
		 * �����Ƿ�����ֲ���ͼ
		 */
		virtual void setAllowPartialPaint(bool allowPartialPaint);
		/*
		* ���������״
		*/
        virtual void setCursor(FCCursors cursor);
        /**
         *  ��ʾ��ʾ��
         * @param text  ����
         * @param mp    λ��
         */
		virtual void showToolTip(const String& text, const FCPoint& mp);
	    /**
         *  �������
         * @param timerID   ���ID
         * @param interval  ���
         */
        virtual void startTimer(int timerID, int interval);
        /**
         *  ֹͣ���
         * @param timerID   ���ID
         */
        virtual void stopTimer(int timerID);
	};
}
#endif