/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */
#ifndef __FCLOCK__H__
#define __FCLOCK__H__
#pragma once

namespace FaceCat
{
	/*
	* ͬ����
	*/
	class FCLock
	{
	public:
		/*
		* ���캯��
		*/
		FCLock();
		/*
		* ��������
		*/
		~FCLock();
		/*
		* ��
		*/
		void lock();
		/*
		* ����
		*/
		void unLock();
	private:
		CRITICAL_SECTION m_cs;
	};
}

#endif
