/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTABPAGE_H__
#define __FCTABPAGE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\div\\FCDiv.h"
#include "..\\btn\\FCButton.h"
#include "FCTabControl.h"

namespace FaceCat{
	class FCTabControl;
    /**
	 * ��ҳ�пؼ�
	 */
	class FCTabPage:public FCDiv{
	protected:
	    /**
		 * ��ʼ�϶�ҳͷ��ť�¼�
		 */
        FCEvent m_dragHeaderBeginEvent;
        /**
		 * �����϶�ҳͷ��ť�¼�
		 */
        FCEvent m_dragHeaderEndEvent;
        /**
		 * ҳͷ��ť�϶����¼�
		 */
        FCEvent m_draggingHeaderEvent;
        /**
		 * ��ȡ������ҳͷ��ť
		 */
		FCButton *m_headerButton;
		/**
		 * ��ȡ������ͷ����λ��
		 */
		FCPoint m_headerLocation;
		/**
		 * ҳͷ�Ĵ��������¼�
		 */
		FCTouchEvent m_headerTouchDownEvent;
		/**
		 * ��ҳ�пؼ�
		 */
		FCTabControl *m_tabControl;
		/**
		* ��ʼ�϶�ҳͷ��ť����
		* @param  sender   ������
		*/
        static void dragHeaderBegin(Object sender, Object pInvoke);
        /**
		 * �����϶�ҳͷ��ť����
		 */
        static void dragHeaderEnd(Object sender, Object pInvoke);
        /**
		 * ҳͷ��ť�϶��з���
		 */
        static void draggingHeader(Object sender, Object pInvoke);
		/**
		* ҳͷ�������·���
		* @param  touchInfo   ������Ϣ
		*/
		static void headerTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
	public:
		/*
		* ����ҳ
		*/
		FCTabPage();
		/*
		* ɾ��ҳ
		*/
		virtual ~FCTabPage();
		/**
		 * ��ȡҳͷ��ť
		 */
		virtual FCButton* getHeaderButton();
		/**
		 * ����ҳͷ��ť
		 */
		virtual void setHeaderButton(FCButton *headerButton);
		/**
		 * ��ȡͷ����λ��
		 */
		virtual FCPoint getHeaderLocation();
		/**
		 * ����ͷ����λ��
		 */
		virtual void setHeaderLocation(FCPoint headerLocation);
		/**
		 * ��ȡͷ���Ƿ�ɼ�
		 */
		virtual bool isHeaderVisible();
		/**
		 * ����ͷ���Ƿ�ɼ�
		 */
		virtual void setHeaderVisible(bool visible);
		/**
		 * ��ȡ��ҳ�пؼ�
		 */
		virtual FCTabControl* getTabControl();
		/**
		 * ���ö�ҳ�пؼ�
		 */
		virtual void setTabControl(FCTabControl *tabControl);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		* ��ȡ����ֵ
		* @param  name  ��������
		* @param  value  ��������ֵ
		* @param  type  ������������
		*/
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getPropertyNames();
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ���ָı䷽��
		 */
		virtual void onTextChanged();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif