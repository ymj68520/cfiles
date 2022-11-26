/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSCROLLBAR_H__
#define __FCSCROLLBAR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"

namespace FaceCat{
	/*
	* ������
	*/
	class FCScrollBar:public FCView{
	private:
        /**
		 * ���ID
		 */
		int m_timerID;
		/**
		 * ������
		 */
		int m_tick;
	protected:
		FCButton *m_addButton;
		/**
		 * ��ǰ�ļ��ٶ�
		 */
		int m_addSpeed;
		/**
		 * ����������ť
		 */
		FCButton *m_backButton;
		/**
		 * ���ݳߴ�
		 */
		int m_contentSize;
		/**
		 * �Ƿ���������
		 */
		bool m_isAdding;
		/**
		 * �Ƿ����ڼ���
		 */
		bool m_isReducing;
		/**
		 * �������гߴ�
		 */
		int m_lineSize;
		/**
		 * ҳ�ĳߴ�
		 */
		int m_pageSize;
		/**
		 * ��������
		 */
		int m_pos;
		/**
		 * ������ť
		 */
		FCButton *m_reduceButton;
		/**
		 * ������ť
		 */
		FCButton *m_scrollButton;
	protected:
	    /**
		 * ������ť�İ����¼�
		 */
		FCTouchEvent m_addButtonTouchDownEvent;
		/**
		 * ������ť��̧���¼�
		 */
		FCTouchEvent m_addButtonTouchUpEvent;
		/**
		 * ������ť�İ����¼�
		 */
		FCTouchEvent m_reduceButtonTouchDownEvent;
		/**
		 * ������ť��̧���¼�
		 */
		FCTouchEvent m_reduceButtonTouchUpEvent;
		/**
		 * ������ť��ק�¼�
		 */
		FCEvent m_scrollButtonDraggingEvent;
		/**
		* ����������ť�����¼��ص��¼�
		* @params sender  ������
		* @params touchInfo  ������Ϣ
		*/
		static void addButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ����������ţ̌���¼��ص��¼�
		 */
		static void addButtonTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ����������ť�����¼��ص�����
		 */
		static void reduceButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ����������ţ̌���¼��ص�����
		 */
		static void reduceButtonTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ������ť���϶��¼��ص�����
		 */
		static void scrollButtonDragging(Object sender, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCScrollBar();
		/*
		* ��������
		*/
		virtual ~FCScrollBar();
		/**
		 * ������ť
		 */
		virtual FCButton* getAddButton();
		/**
		 * ��ȡ��ǰ�ļ��ٶ�
		 */
		virtual int getAddSpeed();
		/**
		 * ���õ�ǰ�ļ��ٶ�
		 */
		virtual void setAddSpeed(int addSpeed);
		/**
		 * ��ȡ����������ť
		 */
		virtual FCButton* getBackButton();
		/**
		 * ��ȡ���ݳߴ�
		 */
		virtual int getContentSize();
		/**
		 * �������ݳߴ�
		 */
		virtual void setContentSize(int contentWidth);
		/**
		 * ��ȡ�Ƿ���������
		 */
		virtual bool isAdding();
		/**
		 * �����Ƿ���������
		 */
		virtual void setIsAdding(bool isAdding);
		/**
		 * ��ȡ�Ƿ����ڼ���
		 */
		virtual bool isReducing();
		/**
		 * �����Ƿ����ڼ���
		 */
		virtual void setIsReducing(bool isReducing);
		/**
		 * ÿ�ι������гߴ�
		 */
		virtual int getLineSize();
		virtual void setLineSize(int lineSize);
		/**
		 * ��ȡҳ�ĳߴ�
		 */
		virtual int getPageSize();
		/**
		 * ����ҳ�ĳߴ�
		 */
		virtual void setPageSize(int pageSize);
		/**
		 * ��ȡ��������
		 */
		virtual int getPos();
		/**
		 * ���ù�������
		 */
		virtual void setPos(int pos);
		/**
		 * ������ť
		 */
		virtual FCButton* getReduceButton();
		/**
		 * ��ȡ������ť
		 */
		virtual FCButton* getScrollButton();
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * �б�󷽷�
		 */
		virtual void lineAdd();
		/**
		 * �б�С����
		 */
		virtual void lineReduce();
		/**
		* ����������ť�����¼�����
		* @params touchInfo  ������Ϣ
		*/
		void onAddButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * ����������ţ̌���¼�����
		 */
		void onAddButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * ���ٹ�������
		 */
		virtual void onAddSpeedScrollEnd();
		/**
		 * �Զ����ٹ�����ʼ
		 */
		virtual void onAddSpeedScrollStart(DWORD startTime, DWORD nowTime, int start, int end);
		/**
		 * �Զ����ٹ�����
		 */
		virtual int onAddSpeedScrolling();
		/**
		 * �϶���������
		 */
		virtual void onDragScroll();
		/**
		 * �ؼ���ӷ���
		 */
		virtual void onLoad();
		/**
		 * ����������ť�����¼�����
		 */
		void onReduceButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * ����������ţ̌���¼��ص�����
		 */
		void onReduceButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * ��������
		 */
		virtual void onScrolled();
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		 * ҳ��󷽷�
		 */
		virtual void pageAdd();
		/**
		 * ҳ��С����
		 */
		virtual void pageReduce();
		/**
		 * ��������ʼ
		 */
		virtual void scrollToBegin();
		/**
		 * ����������
		 */
		virtual void scrollToEnd();
		/**
		 * ���ص�����
		 */
		virtual void onTimer(int timerID);
	};
}

#endif