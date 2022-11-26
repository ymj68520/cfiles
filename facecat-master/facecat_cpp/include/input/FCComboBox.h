/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCOMBOBOX_H__
#define __FCCOMBOBOX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCTextBox.h"
#include "..\\btn\\FCButton.h"
#include "..\\div\\FCMenu.h"
#include "..\\div\\FCMenuItem.h"

namespace FaceCat{
	class FCComboBox;

	/*
	* �����б�Ĳ˵�
	*/
	class FCComboBoxMenu : public FCMenu{
	protected:
	    /**
		 * �б�ؼ�
		 */
		FCComboBox *m_comboBox;
	public:
		/*
		* ���캯��
		*/
		FCComboBoxMenu();
		/*
		* ��������
		*/
		virtual ~FCComboBoxMenu();
		/**
		 * ��ȡ�б�ؼ�
		 */
		FCComboBox* getComboBox();
		/**
		 * �����б�ؼ�
		 */
		void setComboBox(FCComboBox *comboBox);
		/**
		 * �Ƿ��Զ�����
		 */
		virtual bool onAutoHide();
	};

	/*
	* �����б�
	*/
	class FCComboBox : public FCTextBox{
	protected:
		/*
		* ������ť
		*/
		FCButton* m_dropDownButton;
		/**
		 * ������ť�ĵ������
		 */
		FCTouchEvent m_dropDownButtonTouchDownEvent;
		/**
		 * �����˵��ĵ������
		 */
		FCMenuItemTouchEvent m_menuItemClickEvent;
		/**
		 * �����˵��İ�������
		 */
		FCKeyEvent m_menuKeyDownEvent;
		/*
		* �����˵�
		*/
		FCComboBoxMenu* m_dropDownMenu;
		/**
		 * ������ť�ĵ������
		 */
		static void dropDownButtonTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * �˵���ĵ������
		 */
		static void menuItemClick(Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object pInvoke);
		/**
		 * �����˵��İ�������
		 */
		static void menuKeyDown(Object sender, char key, Object pInvoke);
	public:
		/*
		* ���캯��
		*/
		FCComboBox();
		/*
		* ��������
		*/
		virtual ~FCComboBox();
		/**
		 * ��ȡ������ť
		 */
		virtual FCButton* getDropDownButton();
		/**
		 * ��ȡ�����˵�
		 */
		virtual FCComboBoxMenu* getDropDownMenu();
		/**
		 * ��ȡѡ�е�����
		 */
		virtual int getSelectedIndex();
		/**
		 * ����ѡ�е�����
		 */
		virtual void setSelectedIndex(int selectedIndex);
		/**
		 * ��ȡѡ�е�����
		 */
		virtual String getSelectedText();
		/**
		 * ����ѡ�е�����
		 */
		virtual void setSelectedText(const String& selectedText);
		/**
		 * ��ȡѡ�е�ֵ
		 */
		virtual String getSelectedValue();
		/**
		 * ����ѡ�е�ֵ
		 */
		virtual void setSelectedValue(const String& selectedValue);
	public:
	    /**
		 * ��Ӳ˵���
		 */
		void addItem(FCMenuItem *item);
		/**
		 * ������в˵���
		 */
		void clearItems();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ȡ�˵���
		 */
		ArrayList<FCMenuItem*> getItems();
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
		 * ����˵���
		 */
		void insertItem(int index, FCMenuItem *item);
		/**
		 * �˵���������
		 */
		virtual void onDropDownOpening();
		/**
		 * ���̰��·���
		 */
		virtual void onKeyDown(char key);
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		 * ѡ�������ı䷽��
		 */
		virtual void onSelectedIndexChanged();
		/**
		 * �������ַ���
		 */
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * �Ƴ��˵���
		 */
		void removeItem(FCMenuItem *item);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}

#endif