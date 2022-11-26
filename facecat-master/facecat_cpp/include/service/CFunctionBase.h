/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CFUNCTIONBASE_H__
#define __CFUNCTIONBASE_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	/*
	* ����������
	*/
	class CFunctionBase : public CFunction{
	private:
	    /**
		 * ָ��
		 */
		FCScript *m_indicator;
	public:
		/**
		* ��������
		* @param  indicator  ָ��
		* @param  id  ID
		* @param  name  ����
		*/
		CFunctionBase(FCScript *indicator, int cid, const String& name);
		/*
		* ��������
		*/
		virtual ~CFunctionBase();
	public:
		/**
		* ��ӷ���
		* @param  indicator  ������
		*/
		static void addFunctions(FCScript *indicator);
		/**
		* ����
		* @param  var  ����
		*/
		virtual double onCalculate(CVariable *var);
	public:
		/**
		* ���뺯��
		* @param  var  ����
		*/
		double INPUT(CVariable *var);
		/**
		* �������
		* @param  var  ����
		*/
		double OUTPUT(CVariable *var);
		/**
		* ˯��
		* @param  var  ����
		*/
		double SLEEP(CVariable *var);
	};
}

#endif

