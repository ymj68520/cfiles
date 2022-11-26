/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTREENODE_H__
#define __FCTREENODE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\grid\\FCGrid.h"
#include "..\\grid\\FCGridRow.h"
#include "..\\grid\\FCGridCell.h"
#include "..\\btn\\FCCheckBox.h"
#include "FCTree.h"

namespace FaceCat{
	class FCTree;

	/*
	* ���ڵ�
	*/
	class FCTreeNode : public FCGridControlCell{
	protected:
	    /**
		 * �Ƿ��������ڵ�
		 */
		bool m_allowDragIn;
		/**
		 * �Ƿ�����ϳ��ڵ�
		 */
		bool m_allowDragOut;
		/**
		 * ��ѡ���Ƿ�ѡ��
		 */
		bool m_checked;
		/**
		 * �ӽڵ�
		 */
		ArrayList<FCTreeNode*> m_nodes;
		/**
		 * �Ƿ�չ���ڵ�
		 */
		bool m_expended;
		/**
		 * ������������
		 */
		int m_indent;
		/**
		 * ���ڵ�
		 */
		FCTreeNode *m_parent;
		/**
		 * Ŀ����
		 */
		FCGridColumn *m_targetColumn;
		/**
		 * ����
		 */
		String m_text;
		/**
		 * ���ؼ�
		 */
		FCTree *m_tree;
		/**
		 * ֵ
		 */
		String m_value;
		/**
		 * ѡ�������ӽڵ�
		 */
		void checkChildNodes(ArrayList<FCTreeNode*> nodes, bool isChecked);
		/**
		 * �۵��ӽڵ�
		 */
		void collapseChildNodes(ArrayList<FCTreeNode*> nodes, bool collapseAll);
		/**
		 * չ�����еĽڵ�
		 */
		void expendChildNodes(ArrayList<FCTreeNode*> nodes, bool parentExpened, bool expendAll);
		/**
		 * ��ȡ���ڵ������
		 */
		FCTreeNode* getLastNode(ArrayList<FCTreeNode*> nodes);
	public:
		/*
		* ���캯��
		*/
		FCTreeNode();
		/*
		* ��������
		*/
		virtual ~FCTreeNode();
		/**
		 * ��ȡ�Ƿ��������ڵ�
		 */
		virtual bool allowDragIn();
		/**
		 * �����Ƿ��������ڵ�
		 */
		virtual void setAllowDragIn(bool allowDragIn);
		/**
		 * ��ȡ�Ƿ�����ϳ��ڵ�
		 */
		virtual bool allowDragOut();
		/**
		 * �����Ƿ�����ϳ��ڵ�
		 */
		virtual void setAllowDragOut(bool allowDragOut);
		/**
		 * ��ȡ��ѡ���Ƿ�ѡ��
		 */
		virtual bool isChecked();
		/**
		 * ���ø�ѡ���Ƿ�ѡ��
		 */
		virtual void setChecked(bool checked);
		/**
		 * ��ȡ�Ƿ�չ���ڵ�
		 */
		virtual bool isExpended();
		/**
		 * �����Ƿ�չ���ڵ�
		 */
		virtual void setExpended(bool expended);
		/**
		 * ��ȡ������������
		 */
		virtual int getIndent();
		/**
		 * ��ȡ���ڵ�
		 */
		virtual FCTreeNode* getParent();
		/**
		 * ���ø��ڵ�
		 */
		virtual void setParent(FCTreeNode *parent);
		/**
		 * ��ȡĿ����
		 */
		virtual FCGridColumn* getTargetColumn();
		/**
		 * ����Ŀ����
		 */
		virtual void setTargetColumn(FCGridColumn *targetColumn);
		/**
		 * ��ȡ���ؼ�
		 */
		virtual FCTree* getTree();
		/**
		 * �������ؼ�
		 */
		virtual void setTree(FCTree *tree);
		/**
		 * ��ȡֵ
		 */
		virtual String getValue();
		/**
		 * ����ֵ
		 */
		virtual void setValue(const String& value);
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
		 * ��ȡ�ڵ������
		 */
		int getNodeIndex(FCTreeNode *node);
		/**
		 * ��ȡҪ���Ƶ��ı�
		 */
		virtual String getPaintText();
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
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ����ڵ�
		 */
		void insertNode(int index, FCTreeNode *node);
		/**
		 * ���ڵ��Ƿ�ɼ�
		 */
		bool isNodeVisible(FCTreeNode *node);
		/**
		 * ��ӽڵ�
		 */
		virtual void onAddingNode(int index);
		/**
		 * ���Ƹ�ѡ��
		 */
		virtual void onPaintCheckBox(FCPaint *paint, const FCRect& rect);
		/**
		 * ���ƽڵ�
		 */
		virtual void onPaintNode(FCPaint *paint, const FCRect& rect);
		/**
		 * �ػ淽��
		 */
		virtual void onPaint(FCPaint *paint, const FCRect& rect, const FCRect& clipRect, bool isAlternate);
		/**
		 * �Ƴ��ڵ㷽��
		 */
		virtual void onRemovingNode();
		/**
		 * �Ƴ��ڵ�
		 */
		void removeNode(FCTreeNode *node);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * �����ַ�����ֵ
		 */
		virtual void setString(const String& value);
	};
}

#endif