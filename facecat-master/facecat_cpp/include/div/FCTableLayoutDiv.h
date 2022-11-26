/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTABLELAYOUTDIV_H__
#define __FCTABLELAYOUTDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDiv.h"

namespace FaceCat{
    /**
	 * ������С������
	 */
	enum FCSizeType{
	    /**
		 * ���Դ�С
		 */
		FCSizeType_AbsoluteSize,
		/**
		 * �Զ����
		 */
		FCSizeType_AutoFill,
		/**
		 * �ٷֱȴ�С
		 */
		FCSizeType_PercentSize
	};

	/*
	* �е���ʽ
	*/
	class FCColumnStyle : public FCProperty{
	protected:
	    /**
		 * ������С������
		 */
		FCSizeType m_sizeType;
		/**
		 * ���
		 */
		float m_width;
	public:
		/*
		* ���캯��
		*/
		FCColumnStyle();
		/*
		* ���캯��
		*/
		FCColumnStyle(FCSizeType sizeType, float width);
		/*
		* ��������
		*/
		virtual ~FCColumnStyle();
		/**
		 * ��ȡ������С������
		 */
		virtual FCSizeType getSizeType();
		/**
		 * ���õ�����С������
		 */
		virtual void setSizeTypeA(FCSizeType  sizeType);
		/**
		 * ��ȡ���
		 */
		virtual float getWidth();
		/**
		 * ���ÿ��
		 */
		virtual void setWidth(float width);
	public:
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
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};

	/*
	* �е�����u
	*/
	class FCRowStyle : public FCProperty{
	protected:
	    /**
		 * ���
		 */
		float m_height;
		/**
		 * ������С������
		 */
		FCSizeType m_sizeType;
	public:
		/*
		* ���캯��
		*/
		FCRowStyle();
		/*
		* ���캯��
		*/
		FCRowStyle(FCSizeType sizeType, float height);
		/*
		* ��������
		*/
		virtual ~FCRowStyle();
		/**
		 * ��ȡ���
		 */
		virtual float getHeight();
		/**
		 * ���ÿ��
		 */
		virtual void setHeight(float height);
		/**
		 * ��ȡ������С������
		 */
		virtual FCSizeType getSizeType();
		/**
		 * ���õ�����С������
		 */
		virtual void setSizeTypeA(FCSizeType  sizeType);
	public:
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
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};

	/*
	* ����
	*/
	class FCTableLayoutDiv : public FCDiv{
	protected:
	    /**
		 * �еļ���
		 */
		ArrayList<int> m_columns;
		/**
		 * �е�����
		 */
		int m_columnsCount;
		/**
		 * �еļ���
		 */
		ArrayList<int> m_rows;
		/**
		 * �е�����
		 */
		int m_rowsCount;
		/**
		 * ���ؼ�
		 */
		ArrayList<FCView*> m_tableControls;
	public:
	    /**
		 * �е���ʽ
		 */
		ArrayList<FCColumnStyle> m_columnStyles;
		/**
		 * �е���ʽ
		 */
		ArrayList<FCRowStyle> m_rowStyles;
		/*
		* ���캯��
		*/
		FCTableLayoutDiv();
		/*
		* ��������
		*/
		virtual ~FCTableLayoutDiv();
		/**
		 * ��ȡ�е�����
		 */
		virtual int getColumnsCount();
		/**
		 * �����е�����
		 */
		virtual void setColumnsCount(int columnsCount);
		/**
		 * ��ȡ�е�����
		 */
		virtual int getRowsCount();
		/**
		 * �����е�����
		 */
		virtual void setRowsCount(int rowsCount);
	public:
		/**
		* ��ӿؼ�
		* @param  control   �ؼ�
		*/
		virtual void addControl(FCView *control);
		/**
		* ��ӿؼ�
		* @param  control   �ؼ�
		* @param  column   ��
		* @param  row   ��
		*/
		virtual void addControl(FCView *control, int column, int row);
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
		/**
		 * ���ò���
		 */
		virtual bool onResetLayout();
		/**
		* �Ƴ��ؼ�
		* @param  control   �ؼ�
		*/
		virtual void removeControl(FCView *control);
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���ָ��·���
		 */
		virtual void update();
	};
}

#endif