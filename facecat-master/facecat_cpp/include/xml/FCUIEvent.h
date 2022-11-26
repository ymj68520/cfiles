/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __UIEVENT_H__
#define __UIEVENT_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCUIScript.h"
#include "FCUIXml.h"
#include "..\\core\\FCLib.h"

namespace FaceCat{
	class FCUIScript;
	class FCUIXml;

	/*
	* �¼���Ϣ
	*/
	class FCEventInfo{
	private:
	    /**
		 * ����
		 */
		HashMap<int, String> m_functions;
	public:
		/*
		* ���캯��
		*/
		FCEventInfo();
		/*
		* ��������
		*/
		virtual ~FCEventInfo();
	public:
		/**
		* ����¼�
		* @params eventID  �¼�ID
		* @params function  ����
		*/
		void addEvent(int eventID, const String& function);
		/**
		 * ��ȡ����
		 */
		String getFunction(int eventID);
		/**
		 * �Ƴ��¼�
		 */
		void removeEvent(int eventID);
	};

	/*
	* �¼�
	*/
	class FCUIEvent{
	private:
	    /**
		 * �ű�
		 */
		FCUIScript *m_script;
		/**
		 * ������
		 */
		String m_sender;
		/**
		 * XML����
		 */
		FCUIXml *m_xml;
	public:
	    /**
		 * �¼�����
		 */
		map<FCView*, FCEventInfo*> m_events;
	public:
	    /**
		 * �����¼�
		 */
		FCUIEvent(FCUIXml *xml);
		/*
		* ��������
		*/
		virtual ~FCUIEvent();
		/**
		 * ��ȡ�ű�
		 */
		FCUIScript* getScript();
		/**
		 * ���ýű�
		 */
		void setScript(FCUIScript *script);
		/**
		 * ��ȡ������
		 */
		String getSender();
		/**
		 * ���õ�����
		 */
		void setSender(const String& sender);
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
		 * ��ӿؼ��¼�
		 */
        static void callAdd(Object sender, Object pInvoke);
        /**
		 * ��ӱ�����ɫ�ı��¼�
		 */
		static void callBackColorChanged(Object sender, Object pInvoke);
		/**
		 * ��ӱ���ͼƬ�ı�ʱ��
		 */
		static void callBackImageChanged(Object sender, Object pInvoke);
		/**
		 * �ַ������¼�
		 */
        static void callChar(Object sender, char ch, Object pInvoke);
        /**
		 * ѡ�иı��¼�
		 */
        static void callCheckedChanged(Object sender, Object pInvoke);
        /**
		 * ��������¼�
		 */
        static void callClick(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * �����¼�
		 */
        static void callCopy(Object sender, Object pInvoke);
        /**
		 * �����¼�
		 */
        static void callCut(Object sender, Object pInvoke);
        /**
		 * Dock�ı��¼�
		 */
        static void callDockChanged(Object sender, Object pInvoke);
        /**
		 * ˫���¼�
		 */
        static void callDoubleClick(Object sender, Object pInvoke);
        /**
		 * �϶���ʼ�¼�
		 */
        static void callDragBegin(Object sender, Object pInvoke);
        /**
		 * �϶������¼�
		 */
        static void callDragEnd(Object sender, Object pInvoke);
        /**
		 * �����϶��¼�
		 */
        static void callDragging(Object sender, Object pInvoke);
        /**
		 * ���øı��¼�
		 */
        static void callEnableChanged(Object sender, Object pInvoke);
		/*
		* ���÷���
		*/
        static String callFunction(Object sender, int eventID, Object pInvoke);
        /**
		 * ����ı��¼�
		 */
        static void callFontChanged(Object sender, Object pInvoke);
        /**
		 * ǰ��ɫ�ı��¼�
		 */
        static void callTextColorChanged(Object sender, Object pInvoke);
        /**
		 * ��ý����¼�
		 */
        static void callGotFocus(Object sender, Object pInvoke);
        /**
		 * ��Ԫ�����¼�
		 */
        static void callGridCellClick(Object sender, Object pInvoke);
        /**
		 * ��Ԫ��༭��ʼ�¼�
		 */
        static void callGridCellEditBegin(Object sender, Object pInvoke);
        /**
		 * ��Ԫ��༭�����¼�
		 */
        static void callGridCellEditEnd(Object sender, Object pInvoke);
        /**
		 * ��Ԫ���������¼�
		 */
        static void callGridCellTouchDown(Object sender, Object pInvoke);
        /**
		 * ��Ԫ�����ƶ��¼�
		 */
        static void callGridCellTouchMove(Object sender, Object pInvoke);
        /**
		 * ��Ԫ����̧���¼�
		 */
        static void callGridCellTouchUp(Object sender, Object pInvoke);
        /**
		 * �ڿؼ��߳��е����¼�
		 */
        static void callInvoke(Object sender, Object args, Object pInvoke);
        /**
		 * �ؼ������¼�
		 */
        static void callLoad(Object sender, Object pInvoke);
        /**
		 * λ�øı��¼�
		 */
        static void callLocationChanged(Object sender, Object pInvoke);
        /**
		 * ��ʧ�����¼�
		 */
        static void callLostFocus(Object sender, Object pInvoke);
        /**
		 * ��߽�ı��¼�
		 */
        static void callMarginChanged(Object sender, Object pInvoke);
        /**
		 * ���̰����¼�
		 */
        static void callKeyDown(Object sender, char key, Object pInvoke);
        /**
		 * ���̵����¼�
		 */
        static void callKeyUp(Object sender, char key, Object pInvoke);
        /**
		 * ��߽�ı��¼�
		 */
        static void callMenuItemClick(Object sender, FCMenuItem *item, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * ���������¼�
		 */
        static void callTouchDown(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * ���������¼�
		 */
        static void callTouchEnter(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * �����뿪�¼�
		 */
        static void callTouchLeave(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * �����ƶ��¼�
		 */
        static void callTouchMove(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * ����̧���¼�
		 */
        static void callTouchUp(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * ���������¼�
		 */
        static void callTouchWheel(Object sender, FCTouchInfo touchInfo, Object pInvoke);
        /**
		 * �ڱ߽�ı��¼�
		 */
        static void callPaddingChanged(Object sender, FCPaint *paint, const RECT& clipRect, Object pInvoke);
        /**
		 * �ػ��¼�
		 */
        static void callPaint(Object sender, FCPaint *paint, const FCRect& clipRect, Object pInvoke);
        /**
		 * �ػ�����¼�
		 */
        static void callPaintBorder(Object sender, FCPaint *paint, const FCRect& clipRect, Object pInvoke);
        /**
		 * ���ؼ������仯
		 */
        static void callParentChanged(Object sender, Object pInvoke);
        /**
		 * �����¼�
		 */
        static void callPaste(Object sender, Object pInvoke);
        /**
		 * �������仯�¼�
		 */
        static void callRegionChanged(Object sender, Object pInvoke);
        /**
		 * �Ƴ��ؼ��¼�
		 */
        static void callRemove(Object sender, Object pInvoke);
        /**
		 * ѡ�����ڸı��¼�
		 */
        static void callSelectedTimeChanged(Object sender, Object pInvoke);
        /**
		 * ѡ�������ı��¼�
		 */
        static void callSelectedIndexChanged(Object sender, Object pInvoke);
        /**
		 * ѡ��ҳ�ı��¼�
		 */
        static void callSelectedTabPageChanged(Object sender, Object pInvoke);
        /**
		 * �����¼�
		 */
        static void callScrolled(Object sender, Object pInvoke);
        /**
		 * �ߴ�ı��¼�
		 */
        static void callSizeChanged(Object sender, Object pInvoke);
        /**
		 * Tab�ı��¼�
		 */
        static void callTabIndexChanged(Object sender, Object pInvoke);
        /**
		 * Tabͣ���¼�
		 */
        static void callTabStop(Object sender, Object pInvoke);
        /**
		 * �ı��ı��¼�
		 */
        static void callTextChanged(Object sender, Object pInvoke);
        /**
		 * ���ص��¼�
		 */
        static void callTimer(Object sender, int timerID, Object pInvoke);
        /**
		 * ��ֵ�ı��¼�
		 */
        static void callVisibleChanged(Object sender, Object pInvoke);
        /**
		 * �ɼ�״̬�ı��¼�
		 */
        static void callValueChanged(Object sender, Object pInvoke);
        /**
		 * �����ѹر��¼�
		 */
        static void callWindowClosed(Object sender, Object pInvoke);
        /**
		 * ��ȡ�¼���ID
		 */
		virtual int getEventID(const String& eventName);
		/**
		 * ����¼�
		 */
		virtual void addEvent(FCView *control, const String& eventName, const String& function);
	};
}
#endif