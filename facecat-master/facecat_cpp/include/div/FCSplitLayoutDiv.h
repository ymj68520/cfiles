/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSPLITLAYOUTDIV_H__
#define __FCSPLITLAYOUTDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCDiv.h"
#include "FCLayoutDiv.h"
#include "FCTableLayoutDiv.h"

namespace FaceCat{
	/*
	* �ָ��
	*/
	class FCSplitLayoutDiv : public FCLayoutDiv{
	protected:
	    /**
		 * ��һ���ؼ�
		 */
		FCView *m_firstControl;
		/**
		 * �ڶ����ؼ�
		 */
		FCView *m_secondControl;
		/**
		 * �ָ�ģʽ
		 */
		FCSizeType m_splitMode;
		/**
		 * �ָ�ٷֱ�
		 */
		float m_splitPercent;
		/**
		 * �ָť
		 */
		FCButton *m_splitter;
		/*
		* �϶��¼�
		*/
		FCEvent m_splitterDraggingEvent;
		/*
		* �϶��¼��ص�
		*/
		static void splitterDragging(Object sender, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCSplitLayoutDiv();
		/*
		* ��������
		*/
		virtual ~FCSplitLayoutDiv();
		/**
		 * ��ȡ��һ���ؼ�
		 */
		virtual FCView* getFirstControl();
		/**
		 * ���õ�һ���ؼ�
		 */
		virtual void setFirstControl(FCView *firstControl);
		/**
		 * ��ȡ�ڶ����ؼ�
		 */
		virtual FCView* getSecondControl();
		/**
		 * ���õڶ����ؼ�
		 */
		virtual void setSecondControl(FCView *secondControl);
		/**
		 * ��ȡ�ָ�ģʽ
		 */
		virtual FCSizeType getSplitMode();
		/**
		 * ���÷ָ�ģʽ
		 */
		virtual void setSplitMode(FCSizeType splitMode);
		/**
		 * ��ȡ�ָť
		 */
		virtual FCButton* getSplitter();
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
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
		/*
		* �϶�����
		*/
		void onSplitterDragging();
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ���ò���
		 */
		virtual bool onResetLayout();
		/**
		 * ���ָ��·���
		 */
		virtual void update();
		/**
		* ��������
		* @param  name   ��������
		* @param  value   ��������ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif