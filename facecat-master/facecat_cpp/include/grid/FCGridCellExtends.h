/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCGRIDCELLEXTENDS_H__
#define __FCGRIDCELLEXTENDS_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCGridCell.h"
#include "FCGridColumn.h"
#include "FCGridRow.h"
#include "FCGrid.h"

namespace FaceCat{
	class FCGridCell;
	class FCGridColumn;
	class FCGridRow;
	class FCGrid;
	class FCButton;
	class FCCheckBox;
	class FCComboBox;
	class FCDateTimePicker;
	class FCLabel;
	class FCSpin;
	class FCRadioButton;
	class FCTextBox;

	/*
	* �����͵�Ԫ��
	*/
	class FCGridBoolCell : public FCGridCell{
	protected:
	    /**
		 * ��ֵ
		 */
		bool m_value;
	public:
		FCGridBoolCell();
		FCGridBoolCell(bool value);
		virtual ~FCGridBoolCell();
	public:
	    /**
		 * ��Ԫ���С�Ƚϣ���������
		 */
		virtual int compareTo(FCGridCell *cell);
		/**
		 * ��ȡ��������ֵ
		 */
		virtual bool getBool();
		/**
		 * ��ȡ˫���ȸ���ֵ
		 */
		virtual double getDouble();
		/**
		 * ��ȡ�����ȸ���ֵ
		 */
		virtual float getFloat();
		/**
		 * ��ȡ������ֵ
		 */
		virtual int getInt();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual Long getLong();
		/**
		 * ��ȡ�ַ�����ֵ
		 */
		virtual String getString();
		/**
		 * ���ò�������ֵ
		 */
	    virtual void setBool(bool value);
	    /**
		 * ����˫���ȸ���ֵ
		 */
        virtual void setDouble(double value);
        /**
		 * ���õ����ȸ���ֵ
		 */
        virtual void setFloat(float value);
        /**
		 * ����������ֵ
		 */
        virtual void setInt(int value);
        /**
		 * ���ó�������ֵ
		 */
        virtual void setLong(Long value);
        /**
		 * �����ַ�����ֵ
		 */
        virtual void setString(const String& value);
	};

	/*
	* ��ť�͵�Ԫ��
	*/
	class FCGridButtonCell: public FCGridControlCell{
	public:
		FCGridButtonCell();
		virtual ~FCGridButtonCell();
		FCButton* getButton();
	};

	/*
	* ��ѡ���͵�Ԫ��
	*/
	class FCGridCheckBoxCell : public FCGridControlCell{
	protected:
	public:
		FCGridCheckBoxCell();
		virtual ~FCGridCheckBoxCell();
		FCCheckBox* getCheckBox();
	public:
	    /**
		 * ��ȡ��������ֵ
		 */
		virtual bool getBool();
		/**
		 * ��ȡ˫���ȸ���ֵ
		 */
		virtual double getDouble();
		/**
		 * ��ȡ�����ȸ���ֵ
		 */
		virtual float getFloat();
		/**
		 * ��ȡ������ֵ
		 */
		virtual int getInt();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual Long getLong();
		/**
		 * ��ȡ��������ֵ
		 */
		virtual String getString();
		/**
		 * ���ò�������ֵ
		 */
		virtual void setBool(bool value);
		/**
		 * ����˫���ȸ���ֵ
		 */
		virtual void setDouble(double value);
		/**
		 * ���õ����ȸ���ֵ
		 */
        virtual void setFloat(float value);
        /**
		 * ����������ֵ
		 */
        virtual void setInt(int value);
        /**
		 * ���ó�������ֵ
		 */
        virtual void setLong(Long value);
        /**
		 * �����ַ�����ֵ
		 */
        virtual void setString(const String& value);
	};

	/*
	* �����б�Ԫ��
	*/
	class FCGridComboBoxCell : public FCGridControlCell{
	public:
		FCGridComboBoxCell();
		virtual ~FCGridComboBoxCell();
		FCComboBox* getComboBox();
	public:
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
		virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ����ʱ��ѡ��Ԫ��
	*/
	class FCGridDateTimePickerCell : public FCGridControlCell{
	public:
		FCGridDateTimePickerCell();
		virtual ~FCGridDateTimePickerCell();
		FCDateTimePicker* getDatePicker();
	};

	/*
	* ͼ�㵥Ԫ��
	*/
	class FCGridDivCell : public FCGridControlCell{
	public:
		FCGridDivCell();
		virtual ~FCGridDivCell();
		FCDiv* getDiv();
	};

	/*
	* ˫���ȵ�Ԫ��
	*/
	class FCGridDoubleCell : public FCGridCell{
	protected:
		double m_value;
	public:
		FCGridDoubleCell();
		FCGridDoubleCell(double value);
		virtual ~FCGridDoubleCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* �����ȵ�Ԫ��
	*/
	class FCGridFloatCell : public FCGridCell{
	protected:
		float m_value;
	public:
		FCGridFloatCell();
		FCGridFloatCell(float value);
		virtual ~FCGridFloatCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ���͵�Ԫ��
	*/
	class FCGridIntCell : public FCGridCell{
	protected:
		int m_value;
	public:
		FCGridIntCell();
		FCGridIntCell(int value);
		virtual ~FCGridIntCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ��ǩ��Ԫ��
	*/
	class FCGridLabelCell : public FCGridControlCell{
	public:
		FCGridLabelCell();
		virtual ~FCGridLabelCell();
		FCLabel* getLabel();
	};

	/*
	* �����͵�Ԫ��
	*/
	class FCGridLongCell : public FCGridCell{
	protected:
		Long m_value;
	public:
		FCGridLongCell();
		FCGridLongCell(Long value);
		virtual ~FCGridLongCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
        virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ��ѡ��Ԫ��
	*/
	class FCGridRadioButtonCell : public FCGridControlCell{
	public:
		FCGridRadioButtonCell();
		virtual ~FCGridRadioButtonCell();
		FCRadioButton* getRadioButton();
	public:
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setBool(bool value);
		virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
        virtual void setString(const String& value);
	};

	/*
	* ��ֵ�ı���Ԫ��
	*/
	class FCGridSpinCell : public FCGridControlCell{
	public:
		FCGridSpinCell();
		virtual ~FCGridSpinCell();
		FCSpin* getSpin();
	public:
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual void setBool(bool value);
		virtual void setDouble(double value);
        virtual void setFloat(float value);
        virtual void setInt(int value);
        virtual void setLong(Long value);
	};

	/*
	* �ַ�����Ԫ��
	*/
	class FCGridStringCell : public FCGridCell{
	protected:
		String m_value;
	public:
		FCGridStringCell();
		FCGridStringCell(const String& value);
		virtual ~FCGridStringCell();
	public:
		virtual int compareTo(FCGridCell *cell);
		virtual bool getBool();
		virtual double getDouble();
		virtual float getFloat();
		virtual int getInt();
		virtual Long getLong();
		virtual String getString();
		virtual void setString(const String& value);
	};

	/*
	* ���뵥Ԫ��
	*/
	class FCGridPasswordCell : public FCGridStringCell{
	public:
		FCGridPasswordCell();
		virtual ~FCGridPasswordCell();
	public:
		virtual String getPaintText();
	};

	/*
	* �ı���Ԫ��
	*/
	class FCGridTextBoxCell: public FCGridControlCell{
	public:
		FCGridTextBoxCell();
		virtual ~FCGridTextBoxCell();
		FCTextBox* getTextBox();
	};
}
#endif