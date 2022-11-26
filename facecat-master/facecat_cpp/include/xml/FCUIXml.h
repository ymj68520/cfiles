/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __UIXML_H__
#define __UIXML_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"
#include <atlstr.h>  
#import <msxml3.dll>
#include "..\\core\\FCLib.h"

namespace FaceCat{
	#define HRCALL(a, errmsg) \
	do { \
		hr = (a); \
		if (FAILED(hr)) { \
			dprintf( "%s:%d  HRCALL Failed: %s\n  0x%.8x = %s\n", \
					__FILE__, __LINE__, errmsg, hr, #a ); \
			goto clean; \
		} \
	} while (0)

	class FCUIEvent;
	class FCUIScript;

	/*
	* XML����
	*/
	class FCUIXml{
	protected:
	    /**
		 * �ؼ��б�
		 */
		ArrayList<FCView*> m_controls;
		/**
		 * �¼�
		 */
		FCUIEvent *m_event;
		/**
		 * ������
		 */
		FCNative *m_native;
		/**
		 * �ű�
		 */
		FCUIScript *m_script;
		/**
		 * CSS��ʽ
		 */
		HashMap<String, String> m_styles;
		/*
		* ����FCGridBand
		*/
		void createBandedGridBands(IXMLDOMNode *node, FCView *control);
		/*
		 * ���������
		 */
		void createBandedGridColumns(IXMLDOMNode *node, FCView *control);
		/*
		 * ����ͼ�ε������� 
		 */
		void createChartSubProperty(IXMLDOMNode *node, FCChart *chart);
		/**
		 * �����˵���
		 */
		void createMenuItem(IXMLDOMNode *node, FCMenu *menu, FCMenuItem *parentItem);
		/*
		 * ���������
		 */
		void createGridColumns(IXMLDOMNode *node, FCView *control);
		/*
		 * ���������
		 */
		void createGridRow(IXMLDOMNode *node, FCView *control);
		/*
		 * ���������
		 */
		void createGridRows(IXMLDOMNode *node, FCView *control);
		/**
		 * �����ָ�ֿؼ�
		 */
		void createSplitLayoutSubProperty(IXMLDOMNode *node, FCSplitLayoutDiv *splitLayoutDiv);
		/**
		 * �����ؼ�
		 */
		void createTableLayoutSubProperty(IXMLDOMNode *node, FCTableLayoutDiv *tableLayoutDiv);
		/**
		 * ������ҳ�е�ҳ
		 */
		void createTabPage(IXMLDOMNode *node, FCView *control);
		/**
		 * �������Ľڵ�
		 */
		void createTreeNode(IXMLDOMNode *node, FCView *control, FCTreeNode *treeNode);
		/**
		 * �������Ľڵ�
		 */
		void createTreeNodes(IXMLDOMNode *node, FCView *control);
		/**
		 * �����û��ؼ�
		 */
		FCView* createUserControl(IXMLDOMNode *node);
		static void dprintf(char *format, ...);
		static IXMLDOMDocument* domFromCOM();	
	public:
		/*
		* ���캯��
		*/
		FCUIXml();
		/*
		* ��������
		*/
		virtual ~FCUIXml();
		/**
		 * ��ȡ�¼�
		 */
		FCUIEvent* getEvent();
		/**
		 * �����¼�
		 */
		void setEvent(FCUIEvent *uiEvent);
		/**
		 * ��ȡ������
		 */
		FCNative* getNative();
		/**
		 * ���÷�����
		 */
		void setNative(FCNative *native);
		/**
		 * ��ȡ�ű�
		 */
		FCUIScript* getScript();
		/**
		 * ���ýű�
		 */
		void setScript(FCUIScript *script);
		/*
		 * ��ȡXML��·��
		 */
		String getXmlPath();
	public:
		/**
		* ��ȡ��ť
		* @params name   �ؼ�����
		*/
		FCButton* getButton(const String& name);
		/**
		 * ��ȡͼ�οؼ�
		 */
		FCChart* getChart(const String& name);
		/**
		 * ��ȡ��ѡ��
		 */
		FCCheckBox* getCheckBox(const String& name);
		/**
		 * ��ȡ�����ؼ�
		 */
		FCComboBox* getComboBox(const String& name);
		/*
		 * ��ȡ����ʱ��ؼ�
		 */
		FCDateTimePicker* getDateTimePicker(const String& name);
		/**
		 * ��ȡͼ��
		 */
		FCDiv* getDiv(const String& name);
		/**
		 * ��ȡ���
		 */
		FCGrid* getGrid(const String& name);
		/**
		 * ��ȡ��ؼ�
		 */
		FCGroupBox* getGroupBox(const String& name);
		/**
		 * ��ȡ��ǩ
		 */
		FCLabel* getLabel(const String& name);
		/**
		 * ��ȡ���ֲ�
		 */
		FCLayoutDiv* getLayoutDiv(const String& name);
		/**
		 * ��ȡ�������ƿؼ�
		 */
		ArrayList<FCView*> getLikeControls(const String& name);
		/**
		 * ��ȡ�˵��ؼ�
		 */
		FCMenu* getMenu(const String& name);
		/**
		 * ��ȡ�˵���ؼ�
		 */
		FCMenuItem* getMenuItem(const String& name);
		/**
		 * ��ȡ��ѡ��ť
		 */
		FCRadioButton* getRadioButton(const String& name);
		/**
		 * ��ȡ��ֵ�ؼ�
		 */
		FCSpin* getSpin(const String& name);
		/**
		 * ��ȡ�ָ��
		 */
		FCSplitLayoutDiv* getSplitLayoutDiv(const String& name);
		/**
		 * ��ȡ��ҳ�пؼ�
		 */
		FCTabControl* getTabControl(const String& name);
		/**
		 * ��ȡ����
		 */
		FCTableLayoutDiv* getTableLayoutDiv(const String& name);
		/**
		 * ��ȡ�пؼ�
		 */
		FCTabPage* getTabPage(const String& name);
		/**
		 * ��ȡ�ı���
		 */
		FCTextBox* getTextBox(const String& name);
		/**
		 * ��ȡ���ؼ�
		 */
		FCTree* getTree(const String& name);
		/**
		 * ��ȡ����
		 */
		FCWindow* getWindow(const String& name);
	public:
		/**
		* �Ƿ�����ؼ�
		* @params control  �ؼ�
		* @params node  �ڵ�
		*/
		virtual bool containsControl(FCView *control);
		/**
		 * �����ؼ�
		 */
		virtual FCView* createControl(IXMLDOMNode *node, const String& type);
		/**
		 * �����ؼ����
		 */
		void createNative();
		/**
		 * ����������
		 */
		virtual void createSubProperty(IXMLDOMNode *node, FCView *control);
		/**
		 * ���ҿؼ�
		 */
		virtual FCView* findControl(const String& name);
		/**
		 * ��ȡ����
		 */
		HashMap<String, String> getAttributes(IXMLDOMNode *node);
		/**
		 * ��ȡ���еĿؼ�
		 */
		ArrayList<FCView*> getControls();
		/**
		 * �ж��Ƿ����������
		 */
		virtual bool isAfterSetingAttribute(const String& name);
		/**
		 * ��ȡ�ļ������ص��ؼ���
		 */
		virtual void loadFile(const String& fileName, FCView *control);
		/**
		 * ��ӿؼ�
		 */
		virtual void onAddControl(FCView *control, IXMLDOMNode *node);
		/**
		 * ��ȡ�ļ���
		 */
		virtual void readBody(IXMLDOMNode *node, FCView *control);
		/**
		 * ��ȡ�ӽڵ�
		 */
		virtual void readChildNodes(IXMLDOMNode *node, FCView *control);
		/**
		 * ��ȡͷ��
		 */
		virtual void readHead(IXMLDOMNode *node, FCView *control);
		/**
		 * ��ȡXML
		 */
		virtual FCView* readNode(IXMLDOMNode *node, FCView* parent);
		/**
		 * ��ȡ��ʽ
		 */
		virtual void readStyle(IXMLDOMNode *node, FCView *control);
		/**
		 * ����������
		 */
		virtual void setAttributesAfter(IXMLDOMNode *node, FCProperty *control);
		/**
		 * ǰ��������
		 */
		virtual void setAttributesBefore(IXMLDOMNode *node, FCProperty *control);
		/**
		 * �����¼�
		 */
		virtual void setEvents(IXMLDOMNode *node, FCProperty *control);
		/**
		 * ����CSS��ʽ
		 */
		virtual void setStyle(const String& style, FCProperty *control);
	};
}
#endif