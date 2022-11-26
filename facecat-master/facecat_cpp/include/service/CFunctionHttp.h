/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __CFUNCTIONHTTP_H__
#define __CFUNCTIONHTTP_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCHttpMonitor.h"
#include "FCHttpEasyService.h"

namespace FaceCat{
	/*
	* HTTP��
	*/
	class CFunctionHttp : public CFunction{
	private:
	    /**
		 * HTTP����
		 */
		FCHttpData *m_data;
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
		CFunctionHttp(FCScript *indicator, int cid, const String& name);
		/*
		* ��������
		*/
		virtual ~CFunctionHttp();
		/**
		 * ��ȡHTTP����
		 */
		FCHttpData* getHttpData();
		/**
		 * ����HTTP����
		 */
		void setHttpData(FCHttpData *data);
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
		 * ���ǰ׺
		 */
		double HTTP_ADDPORT(CVariable *var);
		/**
		 * ���ű�
		 */
		double HTTP_CHECKSCRIPT(CVariable *var);
		/**
		 * HTTP�ر�
		 */
		double HTTP_CLOSE(CVariable *var);
		/**
		 * ����GET����
		 */
		double HTTP_EASYREQUEST(CVariable *var);
		/**
		 * ��ȡ�������ͷ���
		 */
		double HTTP_GETCONTENTTYPE(CVariable *var);
		/**
		 * ��ȡIP
		 */
		double HTTP_GETREMOTEIP(CVariable *var);
		/**
		 * ��ȡPort
		 */
		double HTTP_GETREMOTEPORT(CVariable *var);
		/**
		 * ��ȡ���󷽷�
		 */
		double HTTP_GETREQUESTMETHOD(CVariable *var);
		/**
		 * ��ȡ����URL
		 */
		double HTTP_GETREQUESTURL(CVariable *var);
		/**
		 * ��ȡ��������
		 */
		double HTTP_GETSERVICENAME(CVariable *var);
		/**
		 * ����������
		 */
		double HTTP_HARDREQUEST(CVariable *var);
		/**
		 * ����������
		 */
		double HTTP_POSTREQUEST(CVariable *var);
		/**
		 * HTTP��ȡPOST����Ĳ���
		 */
		double HTTP_POSTSTRING(CVariable *var);
		/**
		 * HTTP��ȡGET����Ĳ���
		 */
		double HTTP_QUERYSTRING(CVariable *var);
		/**
		 * ������Ӧ״̬��
		 */
		double HTTP_SETSTATUSCODE(CVariable *var);
		/**
		 * HTTP��Ӧд��
		 */
		double HTTP_WRITE(CVariable *var);
	};
}
#endif

