/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCNATIVE_H__
#define __FCNATIVE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCView.h"
#include "FCStr.h"
#include "FCPaint.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "FCHost.h"
#include "WinHost.h"

namespace FaceCat{
	enum SortType{
		SortType_NONE,
		SortType_ASC,
		SortType_DESC
	};

	class FCView;
	class FCHost;
	class WinHost;
	/*
	* ������
	*/
	class FCNative{
	protected:
	    /**
		 * �Ƿ�����ʹ�����ųߴ�
		 */
		bool m_allowScaleSize;
		/**
		 * ��ʾ����
		 */
		FCSize m_displaySize;
		/*
		* ��ʼ��ͼ�ĵ�
		*/
		FCPoint m_drawBeginPoint;
		/**
		 * �϶���ʼʱ������
		 */
		FCRect m_dragBeginRect;
		/**
		 * ���Կ�ʼ�϶���ƫ��������
		 */
		FCPoint m_dragStartOffset;
		/*
		* Ҫ����ͼƬ�Ŀؼ�
		*/
		FCView *m_exportingControl;
		/**
		 * �ؼ�������
		 */
		FCHost *m_host;
		/*
		* ��������
		*/
		FCNative *m_mirrorHost;
		/*
		* ����ģʽ
		*/
		FCMirrorMode m_mirrorMode;
		/**
		 * ͸����
		 */
		float m_opacity;
		/**
		 * ��ͼ��
		 */
		FCPaint *m_paint;
		/**
		 * ��������ʱ������
		 */
		FCPoint m_touchDownPoint;
		/**
		 * ��Դ�ļ���·��
		 */
		String m_resourcePath;
		/**
		 * ��ת�Ƕ�
		 */
		int m_rotateAngle;
		/**
		 * ʹ�����ųߴ�
		 */
		FCSize m_scaleSize;
		/*
		* ���
		*/
		map<int, FCView*> m_timers;
	    /**
         * ���ݴ���λ�û�ȡ�ؼ�
         * @param mp    ����
         * @param control �ؼ�
         * @returns �ؼ�����
        */
		FCView* findControl(const FCPoint& mp, ArrayList<FCView*> *controls);
	    /**
         * �������Ʋ��ҿؼ�
         * @param name  ����
         * @param controls  �ؼ�����
         * @returns �ؼ�
        */
		FCView* findControl(const String& name, ArrayList<FCView*> *controls);
	    /**
         * ���ݿؼ�����Ԥ�����¼��Ŀؼ�
         * @param control   �ؼ�
         * @returns �ؼ�
        */
		FCView* findPreviewsControl(FCView *control);
	    /**
         * ���ݿؼ����Ҵ���
         * @param control   �ؼ�
         * @returns ����
        */
		FCView* findWindow(FCView *control);
	    /**
         * ��ȡ���Ƶ�͸����
         * @param control   �ؼ�
         * @returns ͸����
        */
		float getPaintingOpacity(FCView *control);
	    /**
         * ��ȡ���Ƶ���Դ·��
         * @param control   �ؼ�
         * @returns ·��
        */
		String getPaintingResourcePath(FCView *control);
	    /**
         * ��ȡ�����Ŀؼ�����
         * @param parent    ���ؼ�
         * @param sortedControls   �����Ŀؼ�
         * @returns ״̬
        */
		bool getSortedControls(FCView *parent, ArrayList<FCView*> *sortedControls);
		/*
		* ��ȡ����Tab���Ŀؼ�
		*/
		void getTabStopControls(FCView *control, ArrayList<FCView*> *tabStopControls);
	    /**
         * �ж��Ƿ���ƿ���״̬
         * @param control   �ؼ�
         * @returns �Ƿ���ƿ���״̬
        */
		bool isPaintEnabled(FCView *control);
	    /**
         * ���ƿؼ�
         * @param   rect ����
         * @param   controls �ؼ�����
         * @param   resourcePath ��Դ·��
         * @param   opacity ͸����
        */
		void renderControls(const FCRect& rect, ArrayList<FCView*> *controls, String resourcePath, float opacity);
		void setCursor(FCView *control);
	    /**
         * ���û�ͼ����
         * @param offsetX  ����ƫ��
         * @param offsetY  ����ƫ��
         * @param clipRect  �ü�����
         * @param resourcePath  ��Դ·��
         * @param opacity  ͸����
        */
		void setPaint(int offsetX, int offsetY, const FCRect& clipRect, String resourcePath, float opacity);
	public:
	    /**
		 * �����϶��Ŀؼ�
		 */
		FCView *m_draggingControl;
		/*
		* ��������Ŀؼ�
		*/
		FCView *m_focusedControl;
		/**
		 * �����������µĿؼ�
		 */
		FCView *m_touchDownControl;
		/**
		 * �����������Ϸ��ƶ��Ŀؼ�
		 */
		FCView *m_touchMoveControl;
	public:
	    /**
		 * �ؼ�
		 */
		ArrayList<FCView*> m_controls;
		/*
		* ����
		*/
		vector<FCNative*> m_mirrors;
		/*
		* ���캯��
		*/
		FCNative();
		/*
		* ��������
		*/
		virtual ~FCNative();
		/**
		 * ��ȡ�Ƿ�����ʹ�����ųߴ�
		 */
		bool allowScaleSize();
		/**
		 * �����Ƿ�����ʹ�����ųߴ�
		 */
		void setAllowScaleSize(bool allowScaleSize);
		/*
		* ��ȡ������״
		*/
		FCCursors getCursor();
		/*
		* ����������״
		*/
		void setCursor(FCCursors cursor);
		/**
		 * ��ȡ��ʾ����
		 */
		FCSize getDisplaySize();
		/**
		 * ������ʾ����
		 */
		void setDisplaySize(FCSize displaySize);
		/**
		 * ��ȡѡ�еĿؼ�
		 */
		FCView* getFocusedControl();
		/**
		 * ����ѡ�еĿؼ�
		 */
		void setFocusedControl(FCView *focusedControl);
		/**
		 * ��ȡ�ؼ�������
		 */
		FCHost* getHost();
		/**
		 * ���ÿؼ�������
		 */
		void setHost(FCHost *host);
		/**
		 * ��ȡ������ͣ�Ŀؼ�
		 */
		FCView* getHoveredControl();
		/*
		* ��ȡ��������
		*/
		FCNative* getMirrorHost();
		/*
		* ��ȡ����ģʽ
		*/
		FCMirrorMode getMirrorMode();
		/*
		* ���þ���ģʽ
		*/
		void setMirrorMode(FCMirrorMode mirrorMode);
		/**
		 * ��ȡ������ʵ��λ��
		 */
		FCPoint getTouchPoint();
		/**
		 * ��ȡ͸����
		 */
		float getOpacity();
		/**
		 * ����͸����
		 */
		void setOpacity(float opacity);
		/**
		 * ���ͼ��
		 */
		FCPaint* getPaint();
		/**
		 * ȡ��ͼ��
		 */
		void setPaint(FCPaint *paint);
		/**
		 * ��ȡ������ס�Ŀؼ�
		 */
		FCView* getPushedControl();
		/**
		 * ��ȡ��Դ�ļ���·��
		 */
		String getResourcePath();
		/**
		 * ������Դ�ļ���·��
		 */
		void setResourcePath(const String& resourcePath);
		/**
		 * ��ȡ��ת�Ƕ�
		 */
		int getRotateAngle();
		/**
		 * ������ת�Ƕ�
		 */
		void setRotateAngle(int rotateAngle);
		/**
		 * ��ȡʹ�����ųߴ�
		 */
		FCSize getScaleSize();
		/**
		 * ����ʹ�����ųߴ�
		 */
		void setScaleSize(FCSize scaleSize);
	public:
	    /**
         * ��ӿؼ�
         * @param control �ؼ�
        */
		void addControl(FCView *control);
		/*
		* ��Ӿ���
		*/
		void addMirror(FCNative *mirrorHost, FCView *control);
	    /**
         * ���ؼ��ŵ���ǰ��ʾ
         * @param control �ؼ�
        */
		void bringToFront(FCView *control);
		/**
		 * �˳��϶�
		 */
		void cancelDragging();
		/**
		 * ������еĿؼ�
		 */
		void clearControls();
	    /**
         * ��ȡ�ؼ��ľ��Ժ�����
         * @param control �ؼ�
        */
		int clientX(FCView *control);
	    /**
         * ��ȡ�ؼ��ľ���������
         * @param control �ؼ�
         * @returns ����
        */
		int clientY(FCView *control);
	    /**
         * �Ƿ�����ؼ�
         * @param control �ؼ�
         * @returns �Ƿ����
        */
		bool containsControl(FCView *control);
		/*
		* ����ΪͼƬ
		*/
        void exportToImage(const String& exportPath);
		/*
		* ����ΪͼƬ
		*/
        void exportToImage(const String& exportPath, FCView *control);
        /**
         * ���ݴ���λ�û�ȡ�ؼ�
         * @param mp    ����
        */
		FCView* findControl(const FCPoint& mp);
	    /**
         * ���������ڿؼ��в��ҿؼ�
         * @param mp    ����
         * @param parent    ���ؼ�
         * @returns �ؼ�
        */
		FCView* findControl(const FCPoint& mp, FCView *parent);
	    /**
         * �������Ʋ��ҿؼ�
         * @param name  ����
         * @returns �ؼ�
        */
		FCView* findControl(const String& name);
		/**
		 * ��ȡ�ؼ����ϵĿ���
		 */
		ArrayList<FCView*> getControls();
	    /**
         * ����ؼ�
         * @param index ����
         * @param control   �ؼ�
         */
		void insertControl(int index, FCView *control);
		/**
		 * ʹ�û������ͼ�󣬲����¼����ͼ�ṹ
		 */
		void invalidate();
	    /**
         * �ֲ���ͼ
         * @param control   �ؼ�
         */
		void invalidate(FCView *control);
	    /**
         * �ֲ���ͼ
         * @param rect  ����
         */
		void invalidate(const FCRect& rect);
		/**
         * ��������
         */
		bool onChar(wchar_t key);
	    /**
         * ˫��
         */
		void onDoubleClick(FCTouchInfo touchInfo);
		/**
         * ���̰���
         */
		void onKeyDown(char key);
		/**
         * ����̧��
         */
		void onKeyUp(char key);
		/**
         * ��������
         */
		void onTouchDown(FCTouchInfo touchInfo);
		/**
         * �����뿪
         */
		void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * �����ƶ��¼�
         * @param   ouchInfo    ������Ϣ
        */
		void onTouchMove(FCTouchInfo touchInfo);
		/**
         * ����̧��
         */
		void onTouchUp(FCTouchInfo touchInfo);
		/**
         * ��������
         */
		void onTouchWheel(FCTouchInfo touchInfo);
	    /**
         * ��ͼ����
         * @param clipRect  ��������
        */
		void onPaint(const FCRect& rect);
		/*
		* ����Ԥ����
		*/
		bool onPreviewsKeyEvent(int eventID, char key);
		/*
		* ����Ԥ����
		*/
		bool onPreviewsTouchEvent(int eventID, FCView *control, FCTouchInfo touchInfo);
		/**
		 * ����ߴ�ı�
		 */
		void onResize();
	    /**
         * �������
         * @param   timerID ���ID
        */
		void onTimer(int timerID);
		/**
		 * �Ƴ��ؼ�
		 */
		void removeControl(FCView *control);
		/*
		* �Ƴ�����
		*/
		void removeMirror(FCView *control);
		/**
		 * ���ؼ��ŵ���������ʾ
		 */
		void sendToBack(FCView *control);
		/**
		 * ��������
		 */
		void setAlign(ArrayList<FCView*> *controls);
	    /**
         * ����ê����Ϣ
         * @param controls  �ؼ�����
         * @param oldSize   ԭ�ߴ�
        */
		void setAnchor(FCRect *bounds, FCSize *parentSize, FCSize *oldSize, bool anchorLeft, bool anchorTop, bool anchorRight, bool anchorBottom);
		/*
		* ����ê����Ϣ
		*/
		void setAnchor(ArrayList<FCView*> *controls, FCSize oldSize);
	    /**
         * ���ð󶨱�Ե
         * @param control   �ؼ�
        */
		void setDock(FCRect *bounds, FCRect *spaceRect, FCSize *cSize, int dock);
		/*
		* ���ð󶨱�Ե
		*/
		void setDock(ArrayList<FCView*> *controls);
	    /**
         * �������
         * @param control  �ؼ�
         * @param timerID  �����
         * @param interval ���
        */
		void startTimer(FCView *control, int timerID, int interval);
		/**
		 * ֹͣ���
		 */
		void stopTimer(int timerID);
		/**
		 * ���²���
		 */
		void update();
	};
}
#endif