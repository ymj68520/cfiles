/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __UISCRIPT_H__
#define __UISCRIPT_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"

namespace FaceCat{
	class FCUIEvent;
	class FCUIXml;

	/*
	* �ű��ӿ���
	*/
	class FCUIScript{
	private:
		/*
		* xml����
		*/
		FCUIXml* m_xml;
	public:
		/*
		* ���캯��
		*/
		FCUIScript(FCUIXml *xml);
		/*
		* ��������
		*/
		virtual ~FCUIScript();
		/**
		 * ��ȡXML����
		 */
		FCUIXml* getXml();
		/**
		 * ����XML����
		 */
		void setXml(FCUIXml *xml);
	public:
	    /**
		 * ���÷���
		 */
		virtual String callFunction(const String& function);
		/**
		 * ���ýű�
		 */
		virtual void setText(const String& text);
	};
}
#endif