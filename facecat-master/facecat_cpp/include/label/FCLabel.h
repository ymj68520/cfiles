/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCLABEL_H__
#define __FCLABEL_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ��ǩ
	*/
	class FCLabel : public FCView{
	protected:
		FCContentAlignment m_textAlign;
	public:
		/*
		* ���캯��
		*/ 
		FCLabel();
		/*
		* ��������
		*/
		virtual ~FCLabel();
		/**
		 * ��ȡ���ֵĲ��ַ�ʽ
		 */
		virtual FCContentAlignment getTextAlign();
		/**
		 * �������ֵĲ��ַ�ʽ
		 */
		virtual void setTextAlign(FCContentAlignment textAlign);
	public:
	    /**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
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
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/*
		* Ԥ��ͼ����
		*/
		virtual void onPrePaint(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}
#endif