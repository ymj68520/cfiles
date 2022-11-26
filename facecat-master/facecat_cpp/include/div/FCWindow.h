/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCWINDOW_H__
#define __FCWINDOW_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\btn\\FCButton.h"
#include "FCWindowFrame.h"

namespace FaceCat{
	class FCWindowFrame;

	typedef void (*FCWindowClosingEvent)(Object, bool*, Object);

	/*
	* ����
	*/
	class FCWindow : public FCView{
	protected:
		int m_borderWidth;
		/**
		 * �Ƿ���Ե����ߴ�
		 */
		bool m_canResize;
		/**
		 * �������ĸ߶�
		 */
		int m_captionHeight;
		/**
		 * �����
		 */
		FCWindowFrame *m_frame;
		/**
		 * �Ƿ�Ự����
		 */
		bool m_isDialog;
		/**
		 * �����ߴ�ĵ�
		 */
		int m_resizePoint;
		/**
		 * ��Ӱ����ɫ
		 */
		Long m_shadowColor;
		/**
		 * ��Ӱ�Ĵ�С
		 */
		int m_shadowSize;
		/**
		 * �ƶ���ʼ��
		 */
		FCPoint m_startTouchPoint;
		/**
		 * �ƶ���ʼʱ�Ŀؼ�����
		 */
		FCRect m_startRect;
	protected:
		/**
		* �����¼�
		* @param  eventID  �¼�ID
		* @param  cancel   �Ƿ��˳�
		*/
		void callWindowClosingEvents(int eventID, bool *cancel);
		/**
		* ��ȡ����״̬
		* @param  state  ״ֵ̬
		*/
		FCCursors getResizeCursor(int state);
		/**
		 * ��ȡ�����ߴ�ĵ�
		 */
		ArrayList<FCRect> getResizePoints();
		/**
		 * ��ȡ�����ߴ��״̬
		 */
		int getResizeState();
	public:
		FCWindow();
		virtual ~FCWindow();
		/**
		 * ��ȡ�߿�Ŀ��
		 */
		virtual int getBorderWidth();
		/**
		 * ���ñ߿�Ŀ��
		 */
		virtual void setBorderWidth(int borderWidth);
		/**
		 * ��ȡ�������ĸ߶�
		 */
		virtual int getCaptionHeight();
		/**
		 * ���ñ������ĸ߶�
		 */
		virtual void setCaptionHeight(int captionHeight);
		/**
		 * ��ȡ�Ƿ���Ե����ߴ�
		 */
		virtual bool canResize();
		/**
		 * �����Ƿ���Ե����ߴ�
		 */
		virtual void setCanResize(bool canResize);
		/**
		 * ��ȡ�����
		 */
		virtual FCWindowFrame* getFrame();
		/**
		 * ���ô����
		 */
		virtual void setFrame(FCWindowFrame *frame);
		/**
		 * ��ȡ�Ƿ�Ự����
		 */
		virtual bool isDialog();
		/**
		 * ��ȡ��Ӱ����ɫ
		 */
		virtual Long getShadowColor();
		/**
		 * ������Ӱ����ɫ
		 */
		virtual void setShadowColor(Long shadowColor);
		/**
		 * ��ȡ��Ӱ�Ĵ�С
		 */
		virtual int getShadowSize();
		/**
		 * ������Ӱ�Ĵ�С
		 */
		virtual void setShadowSize(int shadowSize);
	public:
	    /**
		 * ���ؼ��ŵ���ǰ��ʾ
		 */
		virtual void bringToFront();
		/**
		 * �رմ���
		 */
		virtual void close();
		/**
		 * ��ȡ�ؼ�����
		 */
		virtual String getControlType();
		/**
		 * ��ȡ��̬��ͼ����
		 */
		FCRect getDynamicPaintRect();
		/**
		* ��ȡ����ֵ
		* @param  name   ��������
		* @param  value   ��������ֵ
		* @param  type   ������������
		*/
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ�����б�
		 */
		virtual ArrayList<String> getPropertyNames();
		/**
		 * ������ʼ����
		 */
		virtual bool onDragBegin();
		/**
		* �϶�׼������
		* @param  startOffset  �����϶���ƫ��������
		*/
		virtual void onDragReady(FCPoint *startOffset);
		/**
		* �������·���
         * @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		* �����ƶ�����
         * @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		* ����̧�𷽷�
         * @param  touchInfo  ������Ϣ
		*/
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		* ����ǰ������
		* @param  paint   ��ͼ����
		* @param  clipRect  �ü�����
		*/
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/**
		* �������ڹرշ���
		* @param  cancel  �Ƿ��˳�
		*/
		virtual void onWindowClosing(bool *cancel);
		/**
		 * ����رշ���
		 */
		virtual void onWindowClosed();
		/**
		 * ���ؼ��ŵ���������ʾ
		 */
		virtual void sendToBack();
		/**
		* ��������ֵ
		* @param  name   ��������
		* @param  value   ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * �ԻỰ��ʽ��ʾ
		 */
		virtual void showDialog();
	};
}
#endif