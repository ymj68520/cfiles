/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCMENU_H__
#define __FCMENU_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\div\\FCLayoutDiv.h"
#include "FCMenuItem.h"

namespace FaceCat{
	class FCMenuItem;
	/**
	* ����˵��¼�
    */
	typedef void (*FCMenuItemTouchEvent)(Object, FCMenuItem*, FCTouchInfo, Object);

	/*
	* �˵�
	*/
	class FCMenu : public FCLayoutDiv{
	private:
	    /**
		 * �����
		 */
		int m_timerID;
	protected:
	    /**
		 * �Ƿ��Զ�����
		 */
		bool m_autoHide;
		/**
		 * ���˵���
		 */
		FCMenuItem *m_parentItem;
		/**
		 * �Ƿ񵯳�
		 */
		bool m_popup;
		/**
		* �Զ���Ӧλ�úʹ�С
		* @param  menu  �˵�
		*/
		virtual void adjust(FCMenu *menu);
		/**
		* ���ͼ���Ƿ���н���
		* @param  items  �ؼ�����
		*/
		virtual bool checkDivFocused(ArrayList<FCMenuItem*> items);
		/**
		* ��齹��
		* @param  control  �ؼ�
		*/
		virtual bool checkFocused(FCView *control);
		/**
		* �ر�����ؼ�
		* @param  items  �˵�����
		*/
		virtual bool closeMenus(ArrayList<FCMenuItem*> items);
	protected:
		/**
		* ���ò˵��Ĵ����¼�
		* @param  eventID   �¼�ID
		* @param  item   �˵���
         * @param  touchInfo   ������Ϣ
        */
		void callMenuItemTouchEvent(int eventID, FCMenuItem *item, FCTouchInfo touchInfo);
	public:
	    /**
		 * �˵���
		 */
		ArrayList<FCMenuItem*> m_items;
		/*
		* ���캯��
		*/
		FCMenu();
		/*
		* ��������
		*/
		virtual ~FCMenu();
		/**
		 * ��ȡ�Ƿ��Զ�����
		 */
		virtual bool autoHide();
		/**
		 * �����Ƿ��Զ�����
		 */
		virtual void setAutoHide(bool autoHide);
		/**
		 * ��ȡ���˵���
		 */
		virtual FCMenuItem* getParentItem();
		/**
		 * ���ø��˵���
		 */
		virtual void setParentItem(FCMenuItem *parentItem);
		/**
		 * ��ȡ�Ƿ񵯳�
		 */
		virtual bool isPopup();
		/**
		 * �����Ƿ񵯳�
		 */
		virtual void setPopup(bool popup);
	public:
		/**
		* �����
		* @param  item  �˵���
		*/
		virtual void addItem(FCMenuItem *item);
		/**
		 * ������е���
		 */
		virtual void clearItems();
		/**
		 * �����˵�
		 */
		virtual FCMenu* createDropDownMenu();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ȡ���еĲ˵���
		 */
		virtual ArrayList<FCMenuItem*> getItems();
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
		* ������
		* @param  index  ����
		* @param  item   �˵���
		*/
		virtual void insertItem(int index, FCMenuItem *item);
		/**
		 * �Ƿ񲻴����Զ�����
		 */
		virtual bool onAutoHide();
		/*
		* ���ط���
		*/
		virtual void onLoad();
		/**
		* �˵��������
		* @param  item   �˵���
         * @param  touchInfo   ������Ϣ
        */
		virtual void onMenuItemClick(FCMenuItem *item, FCTouchInfo touchInfo);
		/**
		* �˵������ƶ�����
		* @param  item   �˵���
         * @param  touchInfo   ������Ϣ
        */
		virtual void onMenuItemTouchMove(FCMenuItem *item, FCTouchInfo touchInfo);
		/**
        * �����������
        * @param  touchInfo   ������Ϣ
        */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����
		* @param  timerID   ���ID
        */
		virtual void onTimer(int timerID);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		* �Ƴ��˵���
		* @param  item   �˵���
        */
		virtual void removeItem(FCMenuItem *item);
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif