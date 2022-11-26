/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __WINHOST_H__
#define __WINHOST_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCStr.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCNative.h"
#include "FCHost.h"

namespace FaceCat{
	class FCView;
	class FCNative;

	/*
	* Windows�豸��
	*/
	class WinHost : public FCHost{
	protected:
		CRITICAL_SECTION _csLock;
		/**
		 * �Ƿ���Բ���
		 */
		bool m_allowOperate;
		/**
		 * �Ƿ�֧�־ֲ���ͼ
		 */
		bool m_allowPartialPaint;
		/*
		* ���뷨���
		*/
		HIMC m_hImc;
		/**
		 * ͼ�οؼ�
		 */
		HWND m_hWnd;
		/**
		 * ���ÿؼ��̷߳�������ˮ��
		 */
		int m_invokeSerialID;
		/**
		 * ���ÿؼ��̷߳����Ĳ���
		 */
		map<int, Object> m_invokeArgs;
		/**
		 * ���ÿؼ��̷߳����Ŀؼ�
		 */
		map<int, FCView*> m_invokeControls;
		/**
		 * ������
		 */
		FCNative *m_native;
		/**
		 * �����̷߳�������ϢID
		 */
		int m_pInvokeMsgID;
		/**
		 * ��ʾ��
		 */
		FCView *m_toolTip;
	protected:
	    /**
		 * ��ȡ�ͻ��˵Ĵ�С
		 */
		FCSize getClientSize();
	public:
	    /**
		 * ����ؼ�����
		 */
		WinHost();
		virtual ~WinHost();
		/**
		 * ��ȡ����ؼ�����
		 */
		HWND getHWnd();
		/**
		 * ���ô���ؼ�����
		 */
		void setHWnd(HWND hWnd);
		/*
		* ��ȡ������
		*/
		virtual FCNative* getNative();
		/*
		* ���ÿ�����
		*/
		virtual void setNative(FCNative *native);
		/*
		* ��ȡInvoke����Ϣ��
		*/
		int getPInvokeMsgID();
		/*
		* ����Invoke����Ϣ��
		*/
		void setPInvokeMsgID(int pInvokeMsgID);
		/*
		* ��ȡ��ʾ��
		*/
		FCView* getToolTip();
		/*
		* ������ʾ��
		*/
		void setToolTip(FCView *toolTip);
	public:
	    /**
		 * �����
		 */
		virtual void activeMirror();
		/**
		 * ��ȡ�������Ƿ��������
		 */
		virtual bool allowOperate();
		/**
		 * ��ȡ�������Ƿ�����ֲ���ͼ
		 */
		virtual bool allowPartialPaint();
		/**
		*�ڿؼ����߳��е��÷���
		* @param control �ؼ�
		* @param args ����
		*/
		virtual void beginInvoke(FCView *control, Object args);
		/**
		 * �����ı�
		 */
		virtual void copy(string text);
		/**
		*�����ڲ��ؼ�
		* @param parent ���ؼ�
		* @param clsid ����ID
		*/
		virtual FCView* createInternalControl(FCView *parent, const String& clsid);
		/**
		 * ��ȡ�����·��
		 */
		static string getAppPath();
		/**
		 * ȡ����
		 */
		virtual FCCursors getCursor();
		/**
		*��ȡ�����ཻ��
		* @param lpDestRect �ཻ����
		* @param lpSrc1Rect ����1
		* @param lpSrc2Rect ����2
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
		/**
		*��ȡ���β�����
		* @param lpDestRect ��������
		* @param lpSrc1Rect ����1
		* @param lpSrc2Rect ����2
		*/
		virtual int getUnionRect(LPRECT lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
		/*
		* ��
		*/
		void lock();
		/**
		 * ˢ�»�ͼ
		 */
		virtual void invalidate();
		/**
		* ˢ�»�ͼ
		* @param rect  ����
		*/
        virtual void invalidate(const FCRect& rect);
		/**
		* �ڿؼ����߳��е��÷���
		* @param control   �ؼ�
		* @param args      ����
		*/
		virtual void invoke(FCView *control, Object args);
		/**
		* ��ȡ������״̬
		* @param key   ����
		*/
		virtual bool isKeyPress(char key);
		/**
		* ���ÿؼ��̵߳ķ���
		* @param invokeSerialID   ��ϢID
		*/
		void onInvoke(int invokeSerialID);
		/**
		* ��Ϣ����
		* @param m  ��Ϣ
		*/
		int onMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		/**
		* �ػ淽��
		* @param clipRect  �ü�����
		*/
		void onPaint(HDC hDC, const FCRect& rect);
		/**
		 * ��ȡճ���ı�
		 */
		virtual string paste();
		/*
		* �����Ƿ��������
		*/
		virtual void setAllowOperate(bool allowOperate);
		/*
		* �����Ƿ�����ֲ���ͼ
		*/
		virtual void setAllowPartialPaint(bool allowPartialPaint);
		/**
		* ���ù��
		* @param cursor  ���
		*/
        virtual void setCursor(FCCursors cursor);
		/**
		* ��ʾ��ʾ��
		* @param text  ����
		* @param mp  λ��
		*/
		virtual void showToolTip(const String& text, const FCPoint& mp);
		/**
		* �������
		* @param timerID  ���ID
		* @param interval  ���
		*/
        virtual void startTimer(int timerID, int interval);
		/**
		* ֹͣ���
		* @param timerID  ���ID
		*/
        virtual void stopTimer(int timerID);
		/*
		* ����
		*/
		void unLock();
	};
}
#endif