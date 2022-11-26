/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCLINKLABEL_H__
#define __FCLINKLABEL_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCLabel.h"

namespace FaceCat{
    /**
	 * �����ӿؼ���Ϊ
	 */
	enum FCLinkBehavior{
	    /**
		 * ������ʾ�»���
		 */
		LinkBehaviorA_AlwaysUnderLine,
		/**
		 * ������ͣʱ��ʾ�»���
		 */
		LinkBehaviorA_HoverUnderLine,
		/**
		 * ���ǲ���ʾ�»���
		 */
		LinkBehaviorA_NeverUnderLine
	};

	class FCLabel;

	/*
	* ���ӱ�ǩ
	*/
	class FCLinkLabel : public FCLabel{
	protected:
	    /**
		 * ����������ʱ����ɫ
		 */
		Long m_activeLinkColor;
		/**
		 * �����ӱ�����ʱ����ɫ
		 */
		Long m_disabledLinkColor;
		/**
		 * �»��ߵ���ʾ��ʽ
		 */
		FCLinkBehavior m_linkBehavior;
		/**
		 * �����Ӵ���Ĭ��ʱ����ɫ
		 */
		Long m_linkColor;
		/**
		 * �Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
		 */
		bool m_linkVisited;
		/**
		 * �Ƿ��ѷ���
		 */
		bool m_visited;
		/**
		 * �ѷ��ʵĳ����ӵ���ɫ
		 */
		Long m_visitedLinkColor;
	protected:
	    /**
		 * ��ȡҪ���Ƶĳ�������ɫ
		 */
		virtual Long getPaintingLinkColor();
	public:
		/*
		* ���캯��
		*/
		FCLinkLabel();
		/*
		* ��������
		*/
		virtual ~FCLinkLabel();
		/**
		 * ��ȡ����������ʱ����ɫ
		 */
		virtual Long getActiveLinkColor();
		/**
		 * ���õ���������ʱ����ɫ
		 */
		virtual void setActiveLinkColor(Long activeLinkColor);
		/**
		 * ��ȡ�����ӱ�����ʱ����ɫ
		 */
		virtual Long getDisabledLinkColor();
		/**
		 * ���ó����ӱ�����ʱ����ɫ
		 */
		virtual void setDisabledLinkColor(Long disabledLinkColor);
		/**
		 * ��ȡ�»��ߵ���ʾ��ʽ
		 */
		virtual FCLinkBehavior getLinkBehavior();
		/**
		 * �����»��ߵ���ʾ��ʽ
		 */
		virtual void setLinkBehavior(FCLinkBehavior linkBehavior);
		/**
		 * ��ȡ�����Ӵ���Ĭ��ʱ����ɫ
		 */
		virtual Long getLinkColor();
		/**
		 * ���ó����Ӵ���Ĭ��ʱ����ɫ
		 */
		virtual void setLinkColor(Long linkColor);
		/**
		 * ��ȡ�Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
		 */
		virtual bool isLinkVisited();
		/**
		 * �����Ƿ����ѷ��ʵ���ʽ��ʾ��������ɫ
		 */
		virtual void setLinkVisited(bool linkVisited);
		/**
		 * ��ȡ�ĳ����ӵ���ɫ
		 */
		virtual Long getVisitedLinkColor();
		/**
		 * ���ʵĳ����ӵ���ɫ
		 */
		virtual void setVisitedLinkColor(Long visitedLinkColor);
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
		 * �����������
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * �������·���
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * �������뷽��
		 */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
		/**
		 * �����뿪����
		 */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
	};
}
#endif