/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCHSCROLLBAR_H__
#define __FCHSCROLLBAR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCScrollBar.h"

/*
* ���������
*/
namespace FaceCat{
	class FCHScrollBar:public FCScrollBar{
	protected:
	    /**
		 * ������ť�Ĵ��������¼�
		 */
        FCTouchEvent m_backButtonTouchDownEvent;
        /**
		 * ������ť�Ĵ���̧���¼�
		 */
		FCTouchEvent m_backButtonTouchUpEvent;
		/**
		* ������������ť�������»ص��¼�
		* @params sender  ������
		* @params touchInfo  ������Ϣ
		*/
		static void backButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * ������������ť����̧��ص��¼�
		 */
		static void backButtonTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCHScrollBar();
		/*
		* ��������
		*/
		virtual ~FCHScrollBar();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ������������ť�������»ص�����
		 */
		void onBackButtonTouchDown(FCTouchInfo touchInfo);
		/**
		 * ������������ť����̧�𷽷�
		 */
		void onBackButtonTouchUp(FCTouchInfo touchInfo);
		/**
		 * �϶���������
		 */
		virtual void onDragScroll();
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}

#endif