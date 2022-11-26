/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCCHECKBOX_H__
#define __FCCHECKBOX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "FCButton.h"

namespace FaceCat{
	/**
     * ��ѡ��ؼ�
     */
	class FCCheckBox : public FCButton{
	protected:
		/**
	     * ��ȡ���������ݵĺ���������ʽ
	     */
		FCHorizontalAlign m_buttonAlign;
		/**
	     * ��ȡ�����ð�ť�ı���ɫ
	     */
		Long m_buttonBackColor;
		/**
	     * ��ȡ�����ð�ť�ı�����ɫ
	     */
		Long m_buttonBorderColor;
		/**
	     * ��ȡ�����ð�ť�ĳߴ�
	     */
		FCSize m_buttonSize;
		/**
	     * ��ȡ�������Ƿ�ѡ��
	     */
		bool m_checked;
		/**
	     * ��ȡ������ѡ��ʱ�ı���ͼ
	     */
		String m_checkedBackImage;
		/**
	     * ��ȡ�����ô�����ͣ��ѡ��ʱ�ı���ͼƬ
	     */
		String m_checkHoveredBackImage;
		/**
	     * ��ȡ�����ô���������ѡ��ʱ�ı���ͼƬ
	     */
		String m_checkPushedBackImage;
		/**
	     * ��ȡ�����ò�����ʱ��ѡ�б���ͼƬ
	     */
		String m_disableCheckedBackImage;
	protected:
	    /**
	     * ��ȡ�����õı���ɫ
	     */
		virtual Long getPaintingBackColor();
		/**
	     * ��ȡҪ���Ƶİ�ť�ı���ɫ
	     */
		virtual Long getPaintingButtonBackColor();
		/**
	     * ��ȡҪ���Ƶİ�ť������ɫ
	     */
		virtual Long getPaintingButtonBorderColor();
		/**
	     * ��ȡ���ڻ��Ƶı���ͼƬ
	     */
		virtual String getPaintingBackImage();
	public:
		/*
		* ���캯��
		*/
		FCCheckBox();
		/*
		* ��������
		*/
		virtual ~FCCheckBox();
		/**
	     * ��ȡ���ݵĺ���������ʽ
	     */
		virtual FCHorizontalAlign getButtonAlign();
		/**
	     * �������ݵĺ���������ʽ
	     */
		virtual void setButtonAlign(FCHorizontalAlign buttonAlign);
		/**
	     * ��ȡ��ť�ı���ɫ
	     */
		virtual Long getButtonBackColor();
		/**
	     * ���ð�ť�ı���ɫ
	     */
		virtual void setButtonBackColor(Long buttonBackColor);
		/**
	     * ��ȡ��ť�ı�����ɫ
	     */
		virtual Long getButtonBorderColor();
		/**
	     * ���ð�ť�ı�����ɫ
	     */
		virtual void setButtonBorderColor(Long buttonBorderColor);
		/**
	     * ��ȡ��ť�ĳߴ�
	     */
		virtual FCSize getButtonSize();
		/**
	     * ���ð�ť�ĳߴ�
	     */
		virtual void setButtonSize(FCSize buttonSize);
		/**
	     * ��ȡ�Ƿ�ѡ��
	     */
		virtual bool isChecked();
		/**
	     * �����Ƿ�ѡ��
	     */
		virtual void setChecked(bool checked);
		/**
	     * ��ȡѡ��ʱ�ı���ͼ
	     */
		virtual String getCheckedBackImage();
		/**
	     * ����ѡ��ʱ�ı���ͼ
	     */
		virtual void setCheckedBackImage(const String& checkedBackImage);
		/**
	     * ��ȡ������ͣ��ѡ��ʱ�ı���ͼƬ
	     */
		virtual String getCheckHoveredBackImage();
		/**
	     * ���ô�����ͣ��ѡ��ʱ�ı���ͼƬ
	     */
		virtual void setCheckHoveredBackImage(const String& checkHoveredBackImage);
		/**
	     * ��ȡ����������ѡ��ʱ�ı���ͼƬ
	     */
		virtual String getCheckPushedBackImage();
		/**
	     * ���ô���������ѡ��ʱ�ı���ͼƬ
	     */
		virtual void setCheckPushedBackImage(const String& checkPushedBackImage);
		/**
	     * ��ȡ������ʱ��ѡ�б���ͼƬ
	     */
		virtual String getDisableCheckedBackImage();
		/**
	     * ���ò�����ʱ��ѡ�б���ͼƬ
	     */
		virtual void setDisableCheckedBackImage(const String& disableCheckedBackImage);
	public:
	    /**
	     * ��ȡ�ؼ�����
	     */
		virtual String getControlType();
        /**
          * ��ȡ����ֵ
          * @param name  ��������
          * @param value ��������ֵ
          * @param type  ������������
         */
		virtual void getProperty(const String& name, String *value, String *type);
		/**
	      * ��ȡ���������б�
	     */
		virtual ArrayList<String> getPropertyNames();
		/**
	      * ѡ�иı䷽��
	     */
		virtual void onCheckedChanged();
	    /**
         * �������
         * @param touchInfo ������Ϣ
        */
		virtual void onClick(FCTouchInfo touchInfo);
	    /**
         * �ػ汳������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ�ѡ�а�ť����
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintCheckButton(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ�ǰ������
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * ��������
         * @param name    ��������
         * @param value   ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif