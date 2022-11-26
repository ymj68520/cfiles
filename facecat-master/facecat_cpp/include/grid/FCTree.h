/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTREE_H__
#define __FCTREE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\grid\\FCGrid.h"
#include "..\\grid\\FCGridColumn.h"
#include "..\\grid\\FCGridRow.h"
#include "..\\grid\\FCGridCell.h"
#include "..\\grid\\FCGridCellExtends.h"
#include "FCTreeNode.h"

namespace FaceCat{
	class FCTreeNode;

	/*
	* ���ؼ�
	*/
	class FCTree:public FCGrid{
	protected:
	    /**
		 * �Ƿ��ڽڵ�����ʾ��ѡ��
		 */
		bool m_checkBoxes;
		/**
		 * ��ѡ��Ĵ�С
		 */
		FCSize m_checkBoxSize;
		/**
		 * ѡ��ѡ��ʱ��ͼƬ
		 */
		String m_checkedImage;
		/**
		 * �۵��ڵ��ͼƬ
		 */
		String m_collapsedNodeImage;
		/**
		 * չ���ڵ��ͼƬ
		 */
		String m_expendedNodeImage;
		/**
		 * �����ƶ��Ľڵ�
		 */
		FCTreeNode *m_movingNode;
		/**
		 * �ڵ�Ĵ�С
		 */
		FCSize m_nodeSize;
		/**
		 * ��ѡ��δѡ��ʱ��ͼƬ
		 */
		String m_unCheckedImage;
	public:
		/*
		* �ڵ�
		*/
		ArrayList<FCTreeNode*> m_nodes;
		/*
		* ���캯��
		*/
		FCTree();
		/*
		* ��������
		*/
		virtual ~FCTree();
		/**
		 * ��ȡ�Ƿ��ڽڵ�����ʾ��ѡ��
		 */
		virtual bool hasCheckBoxes();
		/**
		 * �����Ƿ��ڽڵ�����ʾ��ѡ��
		 */
		virtual void setCheckBoxes(bool checkBoxes);
		/**
		 * ��ȡ��ѡ��Ĵ�С
		 */
		virtual FCSize getCheckBoxSize();
		/**
		 * ���ø�ѡ��Ĵ�С
		 */
		virtual void setCheckBoxSize(FCSize checkBoxSize);
		/**
		 * ��ȡ��ѡ��ѡ��ʱ��ͼƬ
		 */
		virtual String getCheckedImage();
		/**
		 * ���ø�ѡ��ѡ��ʱ��ͼƬ
		 */
		virtual void setCheckedImage(const String& checkedImage);
		/**
		 * ��ȡ�۵��ڵ��ͼƬ
		 */
		virtual String getCollapsedNodeImage();
		/**
		 * �����۵��ڵ��ͼƬ
		 */
		virtual void setCollapsedNodeImage(const String& collapsedNodeImage);
		/**
		 * ��ȡչ���ڵ��ͼƬ
		 */
		virtual String getExpendedNodeImage();
		/**
		 * ����չ���ڵ��ͼƬ
		 */
		virtual void setExpendedNodeImage(const String& expendedNodeImage);
		/**
		 * ��ȡ�ڵ�Ĵ�С
		 */
		virtual FCSize getNodeSize();
		/**
		 * ���ýڵ�Ĵ�С
		 */
		virtual void setNodeSize(FCSize nodeSize);
		/**
		 * ��ȡѡ�еĽڵ�
		 */
		virtual ArrayList<FCTreeNode*> getSelectedNodes();
		/**
		 * ����ѡ�еĽڵ�
		 */
		virtual void setSelectedNodes(ArrayList<FCTreeNode*> selectedNodes);
		/**
		 * ��ȡ��ѡ��δѡ��ʱ��ͼƬ
		 */
		virtual String getUnCheckedImage();
		/**
		 * ���ø�ѡ��δѡ��ʱ��ͼƬ
		 */
		virtual void setUnCheckedImage(const String& unCheckedImage);
	public:
	    /**
		 * ��ӽڵ�
		 */
		void appendNode(FCTreeNode *node);
		/**
		 * ������нڵ�
		 */
		void clearNodes();
		/**
		 * �۵��ڵ�
		 */
		void collapse();
		/**
		 * �۵����нڵ�
		 */
		void collapseAll();
		/**
		 * չ���ڵ�
		 */
		void expend();
		/**
		 * չ�����нڵ�
		 */
		void expendAll();
		/**
		 * ��ȡ�ӽڵ�
		 */
		ArrayList<FCTreeNode*> getChildNodes();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ȡ�ڵ������
		 */
		int getNodeIndex(FCTreeNode *node);
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
		 * ����ڵ�
		 */
		void insertNode(int index, FCTreeNode *node);
		/**
		 * ��Ԫ�������·���
		 */
		virtual void onCellTouchDown(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * ��Ԫ�����ƶ�����
		 */
		virtual void onCellTouchMove(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * ��Ԫ����̧�𷽷�
		 */
		virtual void onCellTouchUp(FCGridCell *cell, FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * ���Ʊ༭�ı���
		 */
		virtual void onPaintEditTextBox(FCGridCell *cell, FCPaint *paint, const FCRect& rect, const FCRect& clipRect);
		/**
		 * �Ƴ��ڵ�
		 */
		void removeNode(FCTreeNode *node);
		/**
		 * ��������
		 */
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif