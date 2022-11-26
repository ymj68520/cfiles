/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCMENUITEM_H__
#define __FCMENUITEM_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCMenu.h"

namespace FaceCat{
	class FCMenu;

	/*
	* �˵���
	*/
	class FCMenuItem : public FCButton{
	protected:
	    /**
		 * �Ƿ�ѡ��
		 */
		bool m_checked;
		/**
		 * �������
		 */
		FCMenu *m_dropDownMenu;
		/**
		 * ���˵���
		 */
		FCMenuItem *m_parentItem;
		/**
		 * ���ڲ˵�
		 */
		FCMenu *m_parentMenu;
		/**
		 * ֵ
		 */
		String m_value;
	public:
	    /**
		 * ���в˵���
		 */
		ArrayList<FCMenuItem*> m_items;
		/*
		* ���캯��
		*/
		FCMenuItem();
		/*
		* ���캯��
		*/
		FCMenuItem(const String& text);
		/*
		* ��������
		*/
		virtual ~FCMenuItem();
		/**
		 * ��ȡ�Ƿ�ѡ��
		 */
		bool isChecked();
		/**
		 * �����Ƿ�ѡ��
		 */
		void setChecked(bool checked);
		/**
		 * ��ȡ�������
		 */
		FCMenu* getDropDownMenu();
		/**
		 * �����������
		 */
		void setDropDownMenu(FCMenu *dropDownMenu);
		/**
		 * ��ȡ���˵���
		 */
		FCMenuItem* getParentItem();
		/**
		 * ���ø��˵���
		 */
		void setParentItem(FCMenuItem *parentItem);
		/**
		 * ��ȡ�����ڲ˵�
		 */
		FCMenu* getParentMenu();
		/**
		 * �������ڲ˵�
		 */
		void setParentMenu(FCMenu *parentMenu);
		/**
		 * ��ȡֵ
		 */
		String getValue();
		/**
		 * ����ֵ
		 */
		void setValue(const String& value);
	public:
		/**
		* ����Ӳ˵���
		* @param  item  �˵���
		*/
		void addItem(FCMenuItem *item);
		/**
		 * ������е���
		 */
		void clearItems();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ȡ���е���
		 */
		ArrayList<FCMenuItem*> getItems();
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
		* @param  item  �˵���
		*/
		void insertItem(int index, FCMenuItem *item);
		/**
		* �����
		* @param  index  ������
		*/
		virtual void onAddingItem(int index);
		/**
		* �������
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
		* @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* �ػ�ǰ������
		* @param  paint  ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * �Ƴ����
		 */
		virtual void onRemovingItem();
		/**
		* �Ƴ��Ӳ˵���
		* @param  item   �Ӳ˵���
		*/
		void removeItem(FCMenuItem *item);
		/**
		* ��������
		* @param  name   ������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif