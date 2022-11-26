/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTABCONTROL_H__
#define __FCTABCONTROL_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "..\\div\\FCDiv.h"
#include "FCTabPage.h"

namespace FaceCat{
    /**
	* ҳ�Ĳ���λ��
	*/
	enum TabPageLayout{
	    /**
		 * �·�
		 */
		TabPageLayout_Bottom,
		/**
		 * ���
		 */
		TabPageLayout_Left,
		/**
		 * �Ҳ�
		 */
		TabPageLayout_Right,
		/**
		 * ����
		 */
		TabPageLayout_Top
	};
	
	class FCTabPage;

	/*
	* ��ҳ�пؼ�
	*/
	class FCTabControl:public FCDiv{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
	protected:
	    /**
		 * ����״̬
		 */
		int m_animationState;
		/**
		 * ҳ�Ĳ���λ��
		 */
		TabPageLayout m_layout;
		/**
		 * ѡ�е�����
		 */
		int m_selectedIndex;
		/**
		 * �Ƿ�ʹ�ö���
		 */
		bool m_useAnimation;
		/**
		 * �����ƶ�
		 */
		void drawMoving();
		/*
		* ��ȡ����
		*/
		int getTabPageIndex(FCTabPage *tabPage);
	public:
	    /**
		 * ����ҳ
		 */
		ArrayList<FCTabPage*> m_tabPages;
		/* 
		* ������ҳ��
		*/
		FCTabControl();
		/*
		* ɾ����ҳ��
		*/
		virtual ~FCTabControl();
		/**
		 * ��ȡҳ�Ĳ���λ��
		 */
		virtual TabPageLayout getLayout();
		/**
		 * ����ҳ�Ĳ���λ��
		 */
		virtual void setLayout(TabPageLayout layout);
		/**
		 * ��ȡѡ�е�����
		 */
		virtual int getSelectedIndex();
		/**
		 * ����ѡ�е�����
		 */
		virtual void setSelectedIndex(int selectedIndex);
		/**
		 * ��ȡѡ�е�ҳ
		 */
		virtual FCTabPage* getSelectedTabPage();
		/**
		 * ����ѡ�е�ҳ
		 */
		virtual void setSelectedTabPage(FCTabPage *selectedTabPage);
		/**
		 * ��ȡ�Ƿ�ʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�ʹ�ö���
		 */
		virtual void setUseAnimation(bool useAnimation);
	public:
	    /**
		 * ��ӿؼ�����
		 */
		virtual void addControl(FCView *control);
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ����ؼ�
		 */
		virtual void clearControls();
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
		* ����ؼ�
		* @param  index  ����
		* @param  control  �ؼ�
		*/
		virtual void insertControl(int index, FCView *control);
		/**
		 * ��ʼ�϶�ҳͷ
		 */
        virtual void onDragTabHeaderBegin(FCTabPage *tabPage);
        /**
		 * �����϶�ҳͷ
		 */
        virtual void onDragTabHeaderEnd(FCTabPage *tabPage);
        /**
		 * ҳͷ�϶���
		 */
        virtual void onDraggingTabHeader(FCTabPage *tabPage);
        /**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ҳ�ı䷽��
		 */
		virtual void onSelectedTabPageChanged();
		/**
		 * �����
		 */
		virtual void onTimer(int timerID);
		/**
		 * �Ƴ��ؼ�
		 */
		virtual void removeControl(FCView *control);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���²���
		 */
		virtual void update();
	};
}

#endif