/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __FCDIV_H__
#define __FCDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCView.h"
#include "..\\scroll\\FCScrollBar.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"

namespace FaceCat{
	class FCHScrollBar;
	class FCVScrollBar;

	/*
	* ͼ��
	*/
	class FCDiv : public FCView{
	protected:
	    /**
		 * �Ƿ������϶�����
		 */
		bool m_allowDragScroll;
		/**
		 * ���������
		 */
		FCHScrollBar *m_hScrollBar;
		/**
		 * �Ƿ����ڱ��϶�
		 */
		bool m_isDragScrolling;
		/**
		 * �Ƿ����ڹ���2
		 */
		bool m_isDragScrolling2;
		/**
		 * �Ƿ�׼���϶�����
		 */
		bool m_readyToDragScroll;
		/**
		 * ������ť�����¼������¼�
		 */
		FCKeyEvent m_scrollButtonKeyDownEvent;
		/**
		 * ������ť���������¼�
		 */
		FCTouchEvent m_scrollButtonTouchWheelEvent;
		/**
		 * �Ƿ���ʾ���������
		 */
		bool m_showHScrollBar;
		/**
		 * �Ƿ���ʾ���������
		 */
		bool m_showVScrollBar;
		/**
		 * ��ʼ�ƶ���λ��
		 */
		FCPoint m_startMovePoint;
		/**
		 * ��ʼ�ƶ��ĺ���λ��
		 */
		int m_startMovePosX;
		/**
		 * ��ʼ�ƶ�������λ��
		 */
		int m_startMovePosY;
		/**
		 * ��ʼ�ƶ�ʱ��
		 */
		DWORD m_startMoveTime;
		/**
		 * ���������
		 */
		FCVScrollBar *m_vScrollBar;
		/*
		* ����������¼�
		*/
		FCEvent m_vScrollBarScrolledEvent;
		/**
		 * ������ť�����¼������¼�
		 */
		static void scrollButtonKeyDown(Object sender, char key, Object pInvoke);
		/**
		 * ������ť���������¼�
		 */
		static void scrollButtonTouchWheel(Object sender, FCTouchInfo touchInfo, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCDiv();
		/*
		* ��������
		*/
		virtual ~FCDiv();
		/**
		 * ��ȡ�Ƿ������϶�����
		 */
		virtual bool allowDragScroll();
		/**
		 * �����Ƿ������϶�����
		 */
		virtual void setAllowDragScroll(bool allowDragScroll);
		/**
		 * ��ȡ���������
		 */
		FCHScrollBar* getHScrollBar();
		/**
		 * ��ȡ�Ƿ���ʾ���������
		 */
		virtual bool showHScrollBar();
		/**
		 * �����Ƿ���ʾ���������
		 */
		virtual void setShowHScrollBar(bool showHScrollBar);
		/**
		 * ��ȡ�Ƿ����ڱ��϶�
		 */
		virtual bool isDragScrolling();
		/**
		 * ��ȡ�Ƿ���ʾ���������
		 */
		virtual bool showVScrollBar();
		/**
		 * �����Ƿ���ʾ���������
		 */
		virtual void setShowVScrollBar(bool showVScrollBar);
		/**
		 * ��ȡ���������
		 */
		virtual FCVScrollBar* getVScrollBar();
	public:
	    /**
		 * ��ȡ���ݵĸ߶�
		 */
		virtual int getContentHeight();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ȡ��ʾƫ������
		 */
		virtual FCPoint getDisplayOffset();
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getPropertyNames();
		/**
		 * ���¹���һ��
		 */
		virtual void lineDown();
		/**
		 * �������һ��
		 */
		virtual void lineLeft();
		/**
		 * ���ҹ���һ��
		 */
		virtual void lineRight();
		/**
		 * ���Ϲ���һ��
		 */
		virtual void lineUp();
		/**
		* �϶�׼������
		* @param  startOffset  �����϶���ƫ��������
		*/
		virtual void onDragReady(FCPoint *startOffset);
		/**
		 * �϶���������
		 */
		virtual void onDragScrollEnd();
		/**
		 * �϶�������
		 */
		virtual void onDragScrolling();
		/**
		 * �϶�������ɼ��
		 */
		virtual bool onDragScrollPermit();
		/**
		 * �϶�������ʼ
		 */
		virtual void onDragScrollStart();
		/**
		* ���̰��·���
		* @param  key  ����
		*/
		virtual void onKeyDown(char key);
		/**
		* �����������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* ������������
		* @param  touchInfo   ������Ϣ
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		* Ԥ�������¼�
		* @param  eventID   �¼�ID
		* @param  touchInfo   ������Ϣ
		*/
		virtual bool onPreviewsTouchEvent(int eventID, FCTouchInfo touchInfo);
		/**
		 * ���·�һҳ
		 */
		virtual void pageDown();
		/**
		 * ����һҳ
		 */
		virtual void pageLeft();
		/**
		 * ���ҷ�һҳ
		 */
		virtual void pageRight();
		/**
		 * ���Ϸ�һҳ
		 */
		virtual void pageUp();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���²��ַ���
		 */
		virtual void update();
		/**
		 * ���¹������Ĳ���
		 */
		virtual void updateScrollBar();
	};
}

#endif