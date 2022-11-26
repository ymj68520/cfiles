/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __FCDATATABLE_H__
#define __FCDATATABLE_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	class FCDataTable;

    /**
     *  ������
     */
	class FCDataRow{
	protected:
		FCDataTable *m_table;
		/**
	     * ֵ����
	     */
		ArrayList<double> m_values;
	public:
	    /**
	     * ������
	     */
		FCDataRow(FCDataTable *table);
	    /**
         * ������
         * @param capacity  ����
         * @param step  ����
        */
		FCDataRow(FCDataTable *table, int capacity, int step);
	    /**
         * ������
         * @param ary     ����
         * @param size    ����
        */
		FCDataRow(FCDataTable *table, double *ary, int size);
		virtual ~FCDataRow();
	    /**
         * ���ռ�
         * @param columns   ����
        */
		void fillEmpty(int columns);
	    /**
         *  ��ȡ��ֵ
         * @param index   ����
         *  @returns ��ֵ
        */
		double get(int index);
	    /**
          * �Ƴ�
          * @param index   ����
        */
		void remove(int index);
	    /**
		 * ����ֵ
		 * @param index   ����
		 * @param value   ֵ
        */
		void set(int index, double value);
	};

    /**
     * �Զ�������Դ
     */
	class FCDataTable{
	protected:
	    /**
	     * �Զ��ֶ�
	     */
		int m_autoField;
		/**
	     * �е�����
	     */
		int m_colsCapacity;
		/**
	     * �е���������
	     */
		int m_colsStep;
		/**
	     * ������
	     */
		ArrayList<int*> m_columns;
		/**
	     * ��ֵ��
	     */
		ArrayList<double> m_keys;
		/**
	     * ������
	     */
		ArrayList<FCDataRow*> m_rows;
		/**
	     * �����ֵ����
	     */
		FCDataRow* addKey(double num);
		/**
	     * ���հ�
	     */
		void fillEmpty();
	public:
		/*
		* ��ֵ
		*/
		double NaN;
		/*
		* ��������Դ
		*/
		FCDataTable();
		/*
		* ��������Դ
		*/
		virtual ~FCDataTable();
		/*
		* ��ȡ�Զ��ֶ�
		*/
		int AUTOFIELD();
		/*
		* ���ֶ�
		*/
		static inline int NULLFIELD(){
			return -1;
		}
		/**
	     * �����
	     */
		void addColumn(int colName);
		/**
	     * ֱ�Ӳ���������
	     */
		void addRow(double pk, double *ary, int size);
		/**
	     * ����
	     */
		int columnsCount();
		/**
	     * �������
	     */
		void clear();
		/**
	     * ��ȡ�е�����
	     */
		int getColumnIndex(int colName);
		/**
	     * ��ȡ����
	     */
		int getRowIndex(double key);
		/**
	     * ��ȡX���ֵ
	     */
		double getXValue(int rowIndex);
		/**
	     * ��ȡ����
	     */
		double get(double pk, int colName);
		/**
	     * ����������������ȡ����
	     */
		double get2(int rowIndex, int colName);
		/**
	     * ��������������������ȡ����
	     */
		double get3(int rowIndex, int colIndex);
		/*
		* �Ƿ��ֵ
		*/
		static inline bool isNaN(double value){
			return ((*(((long long*) &value)) & 0x7fffffffffffffffL) > 0x7ff0000000000000L);
		}
		/**
	     * �Ƴ�ָ������������
	     */
		void removeAt(int rowIndex);
		/**
	     * �Ƴ���
	     */
		void removeColumn(int name);
		/**
	     * ��ȡ����
	     */
		int rowsCount();
		/**
	     * ������ݣ�����Ϊ����
	     */
		void set(double pk, int colName, double value);
		/**
	     * ���������������
	     */
		void set2(int rowIndex, int colName, double value);
		/**
	     * ������������������������
	     */
		void set3(int rowIndex, int colIndex, double value);
		/**
	     * �����е�����
	     */
		void setColsCapacity(int capacity);
		/**
	     * �����е���������
	     */
		void setColsGrowStep(int step);
		/**
	     * �����е�����
	     */
		void setRowsCapacity(int capacity);
		/**
	     * �����е���������
	     */
		void setRowsGrowStep(int step);
		/**
	     * ������Դ�л�ȡ֮ǰ��һ�����ݵ�����
	     */
		double* DATA_ARRAY(int colName, int rowIndex, int n, int *length);
	};
}
#endif