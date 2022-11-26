/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */
#ifndef __CFUNCTIONEX_H__
#define __CFUNCTIONEX_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* HTTP�Ŀ�
	*/
	class CFunctionEx : public CFunction{
	private:
	    /**
		 * ָ��
		 */
		FCScript *m_indicator;
		/**
		 * XML����
		 */
		FCNative *m_native;
	public:
		/**
		* ��������
		* @param  indicator  ָ��
		* @param  id  ID
		* @param  name  ����
		* @param  native  XML����
		*/
		CFunctionEx(FCScript *indicator, int cid, const String& name, FCNative *native);
		/*
		* ��������
		*/
		virtual ~CFunctionEx();
	public:
		static FCScript* createIndicator(const String& script, FCNative *native);
		/**
		* ����
		* @param  var  ����
		*/
		virtual double onCalculate(CVariable *var);
	};
}
#endif

