/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCLAYOUTDIV_H__
#define __FCLAYOUTDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCDiv.h"

namespace FaceCat{
	/**
	 * ���ֿؼ�
	 */
	class FCLayoutDiv : public FCDiv{
	protected:
	    /**
		 * �Ƿ��Զ�����
		 */
		bool m_autoWrap;
		/**
		 * ����ģʽ
		 */
		FCLayoutStyle m_layoutStyle;
	public:
		/*
		* ���캯��
		*/
		FCLayoutDiv();
		/*
		* ��������
		*/
		virtual ~FCLayoutDiv();
		/**
		 * ��ȡ�Ƿ��Զ�����
		 */
		virtual bool autoWrap();
		/**
		 * �����Ƿ��Զ�����
		 */
		virtual void setAutoWrap(bool autoWrap);
		/**
		 * ��ȡ����ģʽ
		 */
		virtual FCLayoutStyle getLayoutStyle();
		/**
		 * ��������ģʽ
		 */
		virtual void setLayoutStyle(FCLayoutStyle layoutStyle);
	public:
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
		* ��������
		* @param  name   ��������
		* @param  value   ��������ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ���ָ��·���
		 */
		virtual void update();
	};
}

#endif