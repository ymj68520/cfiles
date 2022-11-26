/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTOOLTIP_H__
#define __FCTOOLTIP_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Label\\FCLabel.h"

namespace FaceCat{
	/*
	* ��ʾ��
	*/
	class FCToolTip : public FCLabel{
	private:
	    /**
		 * ���ID
		 */
		int m_timerID;
	protected:
	    /**
		 * ��ʾ��ʱ�䳤��
		 */
		int m_autoPopDelay;
		/**
		 * ������ֹʱ�ӳ���ʾ�ĺ�����
		 */
		int m_initialDelay;
		/**
		 * ��һ�δ�����λ��
		 */
		FCPoint m_lastTouchPoint;
		/**
		 * �Ƿ�������ʾ
		 */
		bool m_showAlways;
		/**
		 * �Ƿ�����ʾ����ʱʹ�ö���
		 */
		bool m_useAnimation;
	protected:
	    /**
		 * ʣ�ౣ����ʾ������
		 */
		int m_remainAutoPopDelay;
		/**
		 * ʣ���ӳ���ʾ������
		 */
		int m_remainInitialDelay;
	public:
		/*
		* ���캯��
		*/
		FCToolTip();
		/*
		* ��������
		*/
		virtual ~FCToolTip();
		/**
		 * ��ʾ��ʾ��ʱ�䳤��
		 */
		virtual int getAutoPopDelay();
		/**
		 * ������ʾ��ʱ�䳤��
		 */
		virtual void setAutoPopDelay(int autoPopDelay);
		/**
		 * ��ȡ������ֹʱ�ӳ���ʾ�ĺ�����
		 */
		virtual int getInitialDelay();
		/**
		 * ���ô�����ֹʱ�ӳ���ʾ�ĺ�����
		 */
		virtual void setInitialDelay(int initialDelay);
		/**
		 * ��ȡ�Ƿ�������ʾ
		 */
		virtual bool showAlways();
		/**
		 * �����Ƿ�������ʾ
		 */
		virtual void setShowAlways(bool showAlways);
		/**
		 * ��ȡ�Ƿ�����ʾ����ʱʹ�ö���
		 */
		virtual bool useAnimation();
		/**
		 * �����Ƿ�����ʾ����ʱʹ�ö���
		 */
		virtual void setUseAnimation(bool useAnimation);
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
		 * ���ؿؼ�
		 */
		virtual void hide();
		/**
		 * ��ӿؼ�����
		 */
		virtual void onLoad();
		/**
		* �����
		* @param  timerID   ���ID
		*/
		virtual void onTimer(int timerID);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		 * ��ʾ�ؼ�
		 */
		virtual void show();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}

#endif