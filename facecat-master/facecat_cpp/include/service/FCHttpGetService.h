/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCHTTPGETSERVICE_H__
#define __FCHTTPGETSERVICE_H__
#pragma once
#include "..\\..\\stdafx.h"
namespace FaceCat{
    /**
	 * HTTP��GET����
	 */
    class FCHttpGetService{
    public:
		/**
		* ��ȡ��ҳ����
		* @param  url  ��ַ
		*/
        static string get(const string url);
    };
}
#endif
