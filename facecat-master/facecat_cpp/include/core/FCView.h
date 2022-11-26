/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCVIEW_H__
#define __FCVIEW_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCNative.h"
#include "FCPaint.h"
#include "FCStr.h"
#include "FCProperty.h"
#include "FCHost.h"

namespace FaceCat{
	static int timerID = 0;
	class FCNative;
	class FCView;

	typedef void (*FCEvent)(Object, Object);
	typedef void (*FCInvokeEvent)(Object, Object, Object);
	typedef void (*FCKeyEvent)(Object, char, Object);
	typedef void (*FCTouchEvent)(Object, FCTouchInfo, Object);
	typedef void (*FCPaintEvent)(Object, FCPaint*, const FCRect&, Object);
	typedef bool (*FCPreviewsKeyEvent)(Object, int, char, Object);
	typedef bool (*FCPreviewsTouchEvent)(Object, int, FCTouchInfo, Object);
	typedef void (*FCTimerEvent)(Object, int, Object);

    /**
	* �¼����
	*/
	class FCEventID{
	public:
        static const int ADD = 0;
        static const int AUTOSIZECHANGED = 1;
        static const int BACKCOLORCHANGED = 2;
        static const int BACKIMAGECHANGED = 3;
        static const int CHAR = 4;
        static const int CLICK = 5;
        static const int COPY = 6;
        static const int CUT = 7;
        static const int DOCKCHANGED = 8;
        static const int DOUBLECLICK = 9;
        static const int DRAGBEGIN = 10;
        static const int DRAGEND = 11;
        static const int DRAGGING = 12;
        static const int ENABLECHANGED = 13;
        static const int FONTCHANGED = 14;
        static const int TEXTCOLORCHANGED = 15;
        static const int GOTFOCUS = 16;
        static const int INVOKE = 17;
        static const int KEYDOWN = 18;
        static const int KEYUP = 19;
        static const int LOAD = 20;
        static const int LOCATIONCHANGED = 21;
        static const int LOSTFOCUS = 22;
        static const int MARGINCHANGED = 23;
        static const int TOUCHDOWN = 24;
        static const int TOUCHENTER = 25;
        static const int TOUCHLEAVE = 26;
        static const int TOUCHMOVE = 27;
        static const int TOUCHUP = 28;
        static const int TOUCHWHEEL = 29;
        static const int PADDINGCHANGED = 30;
        static const int PARENTCHANGED = 31;
        static const int PAINT = 32;
        static const int PAINTBORDER = 33;
        static const int PASTE = 34;
        static const int REGIONCHANGED = 36;
        static const int REMOVE = 37;
        static const int SIZECHANGED = 38;
        static const int TABINDEXCHANGED = 39;
		static const int TABSTOP = 40;
        static const int TABSTOPCHANGED = 41;
        static const int TEXTCHANGED = 42;
        static const int TIMER = 43;
        static const int VISIBLECHANGED = 44;
        static const int CHECKEDCHANGED = 45;
        static const int SELECTEDTIMECHANGED = 46;
        static const int GRIDCELLCLICK = 47;
        static const int GRIDCELLEDITBEGIN = 48;
        static const int GRIDCELLEDITEND = 49;
        static const int GRIDCELLTOUCHDOWN = 50;
        static const int GRIDCELLTOUCHENTER = 51;
        static const int GRIDCELLTOUCHLEAVE = 52;
        static const int GRIDCELLTOUCHMOVE = 53;
        static const int GRIDCELLTOUCHUP = 54;
        static const int GRIDSELECTEDCELLSCHANGED = 55;
        static const int GRIDSELECTEDCOLUMNSSCHANGED = 56;
        static const int GRIDSELECTEDROWSCHANGED = 57;
        static const int MENUITEMCLICK = 58;
        static const int SELECTEDINDEXCHANGED = 59;
        static const int SELECTEDTABPAGECHANGED = 60;
        static const int SCROLLED = 61;
        static const int VALUECHANGED = 62;
        static const int WINDOWCLOSED = 63;
        static const int WINDOWCLOSING = 64;
		static const int PREVIEWSKEYEVENT = 65;
        static const int PREVIEWSTOUCHEVENT = 66;
        static const int USER = 100000;
	};

	/*
	* �ؼ��Ļ���
	*/
	class FCView : public FCProperty{
	protected:
	    /**
		 * �������з�ʽ
		 */
		FCHorizontalAlign m_align;
		/**
		 * �Ƿ�����϶�λ��
		 */
		bool m_allowDrag;
		/**
		 * �Ƿ�����Ԥ�����¼�
		 */
		bool m_allowPreviewsEvent;
		/**
		 * ê����Ϣ
		 */
		FCAnchor m_anchor;
		/**
		 * �Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		bool m_autoEllipsis;
		/**
		 * �Ƿ��Զ������ߴ�
		 */
		bool m_autoSize;
		/**
		 * ����ɫ
		 */
		Long m_backColor;
		/**
		 * ����ͼƬ
		 */
		String m_backImage;
		/**
		 * ���ߵ���ɫ
		 */
		Long m_borderColor;
		/**
		 * �Ƿ�������ý���
		 */
		bool m_canFocus;
		/**
		 * �Ƿ���Դ����¼�
		 */
		bool m_canRaiseEvents;
		/**
		 * Բ�ǽǶ�
		 */
		int m_cornerRadius;
		/*
		* �����״
		*/
		FCCursors m_cursor;
		/**
		 * �Ƿ�����ƫ����ʾ
		 */
		bool m_displayOffset;
		/**
		 * �󶨱�Ե����
		 */
		FCDockStyle m_dock;
		/**
		 * �ؼ��Ƿ����
		 */
		bool m_enabled;
		/**
		 * ����
		 */
		FCFont *m_font;
		/**
		 * �Ƿ����Ҽ��˵�
		 */
		bool m_hasPopupMenu;
		/**
		 * �������Ƿ������϶�
		 */
		bool m_isDragging;
		/**
		 * �Ƿ�Ϊ����
		 */
		bool m_isWindow;
		/**
		 * �ؼ���λ��
		 */
		FCPoint m_location;
		/**
		 * ��߾�
		 */
		FCPadding m_margin;
		/**
		 * �ؼ������ߴ�
		 */
		FCSize m_maximumSize;
		/**
		 * �ؼ�����С�ߴ�
		 */
		FCSize m_minimumSize;
		/**
		 * �ؼ���Ψһ��ʶ����
		 */
		String m_name;
		/**
		 * ��ť���ڵ�ͼ�νӿ�
		 */
		FCNative *m_native;
		/**
		 * �ϴ�����
		 */
		FCPoint m_oldLocation;
		/**
		 * �ϴγߴ�
		 */
		FCSize m_oldSize;
		/**
		 * ͸����
		 */
		float m_opacity;
		/**
		 * �ڱ߾�
		 */
		FCPadding m_padding;
		/**
		 * ���ؼ�
		 */
		FCView *m_parent;
		/**
		 * �ٷֱ�λ��
		 */
		FCPointF *m_percentLocation;
		/**
		 * �ٷֱȳߴ�
		 */
		FCSizeF *m_percentSize;
		/*
		* ����
		*/
		FCRect m_region;
		/**
		 * ��Դ·��
		 */
		String m_resourcePath;
		/**
		 * �ߴ�
		 */
		FCSize m_size;
		/*
		* Tab����
		*/
		int m_tabIndex;
		/*
		* �Ƿ�֧��Tab
		*/
		bool m_tabStop;
		/**
		 * TAGֵ
		 */
		Object m_tag;
		/**
		 * ����
		 */
		String m_text;
		/**
		 * ǰ��ɫ
		 */
		Long m_textColor;
		/**
		 * �Ƿ��ö���ʾ
		 */
		bool m_topMost;
		/**
		 * �Ƿ����òü�
		 */
		bool m_useRegion;
		/**
		 * �������з�ʽ
		 */
		FCVerticalAlign m_verticalAlign;
		/**
		 * �ؼ��Ƿ�ɼ�
		 */
		bool m_visible;
	protected:
	    /**
		 * �¼�����
		 */
		map<int, vector<Object>*> m_events;
		/*
		* �����߼���
		*/
		map<int, vector<Object>*> m_invokes;
	    /**
         * �����¼�
         * @param eventID  �¼�ID
        */
		void callEvents(int eventID);
	    /**
         * ���ÿؼ��̷߳����¼�
         * @param eventID  �¼�ID
         * @param args     ����
        */
		void callInvokeEvents(int eventID, Object args);
		void callKeyEvents(int eventID, char key);
	    /**
         * ���ü����¼�
         * @param eventID  �¼�ID
         * @param key      ����
        */
		void callTouchEvents(int eventID, FCTouchInfo touchInfo);
	    /**
         * �����ػ��¼�
         * @param eventID  �¼�ID
         * @param paint    ��ͼ����
         * @param clipRect �ü�����
        */
		void callPaintEvents(int eventID, FCPaint *paint, const FCRect& clipRect);
		/*
		* ����Ԥ�����¼�
		*/
		bool callPreviewsKeyEvent(int eventID, int tEventID, char key);
	    /**
         * �����ػ��¼�
         * @param eventID  �¼�ID
         * @param tEventID �¼�ID2
         * @param touchInfo   ������Ϣ
        */
		bool callPreviewsTouchEvent(int eventID, int tEventID, FCTouchInfo touchInfo);
	    /**
         * ��������¼�
         * @param eventID  �¼�ID
         * @param timerID  �����
        */
		void callTimerEvents(int eventID, int timerID);
	    /**
         * ��ȡ�����õı���ɫ
         * @returns ����ɫ
        */
        virtual Long getPaintingBackColor();
        /**
         * ��ȡҪ���Ƶı���ͼƬ
         * @returns ����ͼƬ
        */
        virtual String getPaintingBackImage();
        /**
         * ��ȡҪ���Ƶı�����ɫ
         * @returns ������ɫ
        */
        virtual Long getPaintingBorderColor();
        /**
         * ��ȡҪ���Ƶ�ǰ��ɫ
         * @returns ǰ��ɫ
        */
        virtual Long getPaintingTextColor();
	public:
		/*
		* ���пؼ�
		*/
		ArrayList<FCView*> m_controls;
		/*
		* ���캯��
		*/
		FCView();
		/*
		* ��������
		*/
		virtual ~FCView();
		/**
		 * ��ȡ�������з�ʽ
		 */
		virtual FCHorizontalAlign getAlign();
		/**
		 * ���ú������з�ʽ
		 */
		virtual void setAlign(FCHorizontalAlign align);
		/**
		 * ��ȡ�Ƿ�����϶�λ��
		 */
		virtual bool allowDrag();
		/**
		 * �����Ƿ�����϶�λ��
		 */
		virtual void setAllowDrag(bool allowDrag);
		/**
		 * ��ȡ�Ƿ�����Ԥ�����¼�
		 */
		virtual bool allowPreviewsEvent();
		/**
		 * �����Ƿ�����Ԥ�����¼�
		 */
		virtual void setAllowPreviewsEvent(bool allowPreviewsEvent);
		/**
		 * ��ȡê����Ϣ
		 */
		virtual FCAnchor getAnchor();
		/**
		 * ����ê����Ϣ
		 */
		virtual void setAnchor(const FCAnchor& anchor);
		/**
		 * ��ȡ�Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual bool autoEllipsis();
		/**
		 * �����Ƿ������ֳ�����Χʱ�ڽ�β��ʾʡ�Ժ�
		 */
		virtual void setAutoEllipsis(bool autoEllipsis);
		/**
		 * ��ȡ�Ƿ��Զ������ߴ�
		 */
		virtual bool autoSize();
		/**
		 * �����Ƿ��Զ������ߴ�
		 */
		virtual void setAutoSize(bool autoSize);
		/**
		 * ��ȡ����ɫ
		 */
		virtual Long getBackColor();
		/**
		 * ���ñ���ɫ
		 */
		virtual void setBackColor(Long backColor);
		/**
		 * ��ȡ����ͼƬ
		 */
		virtual String getBackImage();
		/**
		 * ���ñ���ͼƬ
		 */
		virtual void setBackImage(const String& backImage);
		/**
		 * ��ȡ���ߵ���ɫ
		 */
		virtual Long getBorderColor();
		/**
		 * ���ñ��ߵ���ɫ
		 */
		virtual void setBorderColor(Long borderColor);
		/**
		 * ��ȡ�����²��λ��
		 */
		virtual int getBottom();
		/**
		 * ��ȡ�ؼ�����������
		 */
		virtual FCRect getBounds();
		/**
		 * ���ÿؼ�����������
		 */
		virtual void setBounds(const FCRect& rect);
		/**
		 * ��ȡ�Ƿ�������ý���
		 */
		virtual bool canFocus();
		/**
		 * �����Ƿ�������ý���
		 */
		virtual void setCanFocus(bool canFocus);
		/**
		 * ��ȡ�Ƿ���Դ����¼�
		 */
		virtual bool canRaiseEvents();
		/**
		 * �����Ƿ���Դ����¼�
		 */
		virtual void setCanRaiseEvents(bool canRaiseEvents);
		/**
		 * ��ȡ�Ƿ񱻴�������
		 */
		virtual bool isCapture();
		/**
		 * ��ȡԲ�ǽǶ�
		 */
		virtual int getCornerRadius();
		/**
		 * ����Բ�ǽǶ�
		 */
		virtual void setCornerRadius(int cornerRadius);
		/*
		* ��ȡ�����״
		*/
		virtual FCCursors getCursor();
		/*
		* ���������״
		*/
		virtual void setCursor(FCCursors cursor);
		/**
		 * ��ȡ�Ƿ�����ƫ����ʾ
		 */
		virtual bool displayOffset();
		/**
		 * �����Ƿ�����ƫ����ʾ
		 */
		virtual void setDisplayOffset(bool displayOffset);
		/**
		 * ��ȡ������ʾ������
		 */
		virtual FCRect getDisplayRect();
		/**
		 * ��ȡ�󶨱�Ե����
		 */
		virtual FCDockStyle getDock();
		/**
		 * ���ð󶨱�Ե����
		 */
		virtual void setDock(FCDockStyle dock);
		/**
		 * ��ȡ�ؼ��Ƿ����
		 */
		virtual bool isEnabled();
		/**
		 * ���ÿؼ��Ƿ����
		 */
		virtual void setEnabled(bool enabled);
		/**
		 * ��ȡ�Ƿ���н���
		 */
		virtual bool isFocused();
		/**
		 * �����Ƿ���н���
		 */
		virtual void setFocused(bool focused);
		/**
		 * ��ȡ����
		 */
		virtual FCFont* getFont();
		/**
		 * ��������
		 */
		virtual void setFont(FCFont *font);
		/**
		 * ��ȡ�Ƿ����Ҽ��˵�
		 */
		virtual bool hasPopupMenu();
		/**
		 * �����Ƿ����Ҽ��˵�
		 */
		virtual void setHasPopupMenu(bool hasPopupMenu);
		/**
		 * ��ȡ�ؼ��ĸ߶�
		 */
		virtual int getHeight();
		/**
		 * ���ÿؼ��ĸ߶�
		 */
		virtual void setHeight(int height);
		/**
		 * ��ȡ�������Ƿ������϶�
		 */
		virtual bool isDragging();
		/**
		 * ��ȡ�Ƿ�Ϊ����
		 */
		virtual bool isWindow();
		/**
		 * �����Ƿ�Ϊ����
		 */
		virtual void setWindow(bool isWindow);
		/**
		 * ��ȡ��������λ��
		 */
		virtual int getLeft();
		/**
		 * ���þ�������λ��
		 */
		virtual void setLeft(int left);
		/**
		 * ��ȡ�ؼ���λ��
		 */
		virtual FCPoint getLocation();
		/**
		 * ���ÿؼ���λ��
		 */
		virtual void setLocation(const FCPoint& location);
		/**
		 * ��ȡ��߾�
		 */
		virtual FCPadding getMargin();
		/**
		 * ������߾�
		 */
		virtual void setMargin(const FCPadding& margin);
		/**
		 * ��ȡ�ؼ������ߴ�
		 */
		virtual FCSize getMaximumSize();
		/**
		 * ���ÿؼ������ߴ�
		 */
		virtual void setMaximumSize(FCSize maxinumSize);
		/**
		 * ��ȡ�ؼ�����С�ߴ�
		 */
		virtual FCSize getMinimumSize();
		/**
		 * ���ÿؼ�����С�ߴ�
		 */
		virtual void setMinimumSize(FCSize minimumSize);
		/*
		* ��ȡ�����ĵ�
		*/
		virtual FCPoint getTouchPoint();
		/*
		* ��ȡ����
		*/
		virtual String getName();
		/*
		* ��������
		*/
		virtual void setName(const String& name);
		/**
		 * ��ȡ������
		 */
		virtual FCNative* getNative();
		/*
		* ���ÿ�����
		*/
		void setNative(FCNative *native);
		/**
		 * ��ȡ͸����
		 */
		virtual float getOpacity();
		/**
		 * ����͸����
		 */
		virtual void setOpacity(float opacity);
		/**
		 * ��ȡ�ڱ߾�
		 */
		virtual FCPadding getPadding();
		/**
		 * �����ڱ߾�
		 */
		virtual void setPadding(const FCPadding& padding);
		/**
		 * ��ȡ���ؼ�
		 */
		virtual FCView* getParent();
		/**
		 * ���ø��ؼ�
		 */
		virtual void setParent(FCView *control);
		/**
		 * ��ȡ�ü�����
		 */
		virtual FCRect getRegion();
		/**
		 * ���òü�����
		 */
		virtual void setRegion(const FCRect& region);
		/**
		 * ��ȡ��Դ·��
		 */
		virtual String getResourcePath();
		/**
		 * ������Դ·��
		 */
		virtual void setResourcePath(const String& resourcePath);
		/**
		 * ��ȡ�����Ҳ�ľ���
		 */
		virtual int getRight();
		/**
		 * ��ȡ�ߴ�
		 */
		virtual FCSize getSize();
		/**
		 * ���óߴ�
		 */
		virtual void setSize(const FCSize& size);
		/*
		* ��ȡTab����
		*/
		virtual int getTabIndex();
		/*
		* ����Tab����
		*/
		virtual void setTabIndex(int tabIndex);
		/*
		* �Ƿ�֧��Tab��
		*/
		virtual bool isTabStop();
		/*
		* �����Ƿ�֧��Tab��
		*/
		virtual void setTabStop(bool tabStop);
		/**
		 * ��ȡTAGֵ
		 */
		virtual Object getTag();
		/**
		 * ����TAGֵ
		 */
		virtual void setTag(Object tag);
		/**
		 * ��ȡ����
		 */
		virtual String getText();
		/**
		 * ��������
		 */
		virtual void setText(const String& text);
		/**
		 * ��ȡǰ��ɫ
		 */
		virtual Long getTextColor();
		/**
		 * ����ǰ��ɫ
		 */
		virtual void setTextColor(Long textColor);
		/**
		 * ��ȡ�����ϲ��λ��
		 */
		virtual int getTop();
		/**
		 * ���þ����ϲ��λ��
		 */
		virtual void setTop(int top);
		/**
		 * ��ȡ�Ƿ��ö���ʾ
		 */
		virtual bool isTopMost();
		/**
		 * ��ȡ�Ƿ��ö���ʾ
		 */
		virtual void setTopMost(bool topMost);
		/**
		 * ��ȡ�������Ƿ����òü�
		 */
		virtual bool useRegion();
		/**
		 * ��ȡ�������з�ʽ
		 */
		virtual FCVerticalAlign getVerticalAlign();
		/**
		 * �����������з�ʽ
		 */
		virtual void setVerticalAlign(FCVerticalAlign verticalAlign);
		/**
		 * ��ȡ�ؼ��Ƿ�ɼ�
		 */
		virtual bool isVisible();
		/**
		 * ���ÿؼ��Ƿ�ɼ�
		 */
		virtual void setVisible(bool visible);
		/**
		 * ��ȡ�ؼ��Ŀ��
		 */
		virtual int getWidth();
		/**
		 * ���ÿؼ��Ŀ��
		 */
		virtual void setWidth(int width);
	public:
	    /**
         * ��ӿؼ�
         * @param control  �ؼ�
        */
		virtual void addControl(FCView *control);
	    /**
         * �ڿؼ��߳��е��÷���
         * @param args  ����
        */
		virtual void addEvent(Object func, int eventID, Object pInvoke);
	    /**
         * �ڿؼ��߳��е��÷���
         * @param args  ����
        */
		virtual void beginInvoke(Object args);
	    /**
         * ���ӿؼ�������ǰ
         * @param childControl  �ӿؼ�
        */
		virtual void bringChildToFront(FCView *childControl);
		/**
		 * ���ؼ��ŵ���ǰ��ʾ
		 */
		virtual void bringToFront();
		/**
		 * ������пؼ�
		 */
		virtual void clearControls();
	    /**
         * �Ƿ�����ؼ�
         * @param control   �ؼ�
         * @returns  �Ƿ����
        */
		virtual bool containsControl(FCView *control);
	    /**
         * �Ƿ�����ؼ�
         * @param point   ����
         * @returns  �Ƿ����
        */
		virtual bool containsPoint(const FCPoint& mp);
		/**
		 * ���ý���
		 */
		virtual void focus();
	    /**
         * ��ȡ�ؼ����ϵĿ���
         * @returns �ؼ�����
        */
		virtual ArrayList<FCView*> getControls();
	    /**
         * ��ȡ�ؼ�����
         * @returns �ؼ�����
        */
		virtual String getControlType();
	    /**
         * ��ȡ��ʾƫ������
         * @returns ����
        */
		virtual FCPoint getDisplayOffset();
	    /**
         * ��ȡ�µ������
         * @returns �±��
        */
		static int getNewTimerID();
	    /**
         * ��ȡ�����˵�������
         * @param control  ��ǰ�ؼ�
         * @returns �ؼ�
        */
		virtual FCView* getPopupMenuContext(FCView *control);
	    /**
         * ��ȡ����ֵ
         * @param name  ��������
         * @param value ��������ֵ
         * @param type  ������������
        */
		virtual void getProperty(const String& name, String *value, String *type);
		/**
		 * ��ȡ���������б�
		 */
		virtual ArrayList<String> getPropertyNames();
	    /**
         * �ж��Ƿ�����ӿؼ�
         * @returns  �Ƿ�����ӿؼ�
        */
		virtual bool hasChildren();
		/**
		 * ���ؿؼ�
		 */
		virtual void hide();
	    /**
         * ����ؼ�
         * @param index  ����
         * @param control  �ؼ�
        */
		virtual void insertControl(int index, FCView *control);
		/**
		 * ��������
		 */
		virtual void invalidate();
	    /**
         * �ڿؼ��߳��е��÷���
         * @param args  ����
        */
		virtual void invoke(Object args);
	    /**
         * �ж��Ƿ���ƿ���״̬
         * @param control   �ؼ�
         * @returns  �Ƿ���ƿ���״̬
        */
		bool isPaintEnabled(FCView *control);
	    /**
         * �ж��Ƿ��ͼʱ�ɼ�
         * @param control   �ؼ�
         * @returns  �Ƿ�ɼ�
        */
		bool isPaintVisible(FCView *control);
		/**
		 * ��ӿؼ�����
		 */
		virtual void onAdd();
		/**
		 * �Զ����óߴ����Ըı䷽��
		 */
		virtual void onAutoSizeChanged();
		/*
		* ����ɫ�仯����
		*/
		virtual void onBackColorChanged();
		/**
		 * ����ɫ�ı䷽��
		 */
		virtual void onBackImageChanged();
		/*
		* ���뷽��
		*/
		virtual void onChar(wchar_t ch);
		/**
		 * �ַ�����
		 */
		virtual void onClick(FCTouchInfo touchInfo);
		/**
		 * ����
		 */
		virtual void onCopy();
		/**
		 * ����
		 */
		virtual void onCut();
		/**
		 * ��ͣ�ı䷽��
		 */
		virtual void onDockChanged();
	    /**
         * ����˫������
         * @param touchInfo  ������Ϣ
        */
		virtual void onDoubleClick(FCTouchInfo touchInfo);
	    /**
         *  �϶���ʼ����
         * @returns  �Ƿ��϶�
        */
		virtual bool onDragBegin();
		/**
		 * �϶���������
		 */
		virtual void onDragEnd();
		/**
		 * �����϶�����
		 */
		virtual void onDragging();
	    /**
         * �϶�׼������
         * @param startOffset  �����϶���ƫ��������
        */
		virtual void onDragReady(FCPoint *startOffset);
		/**
		 * ���øı䷽��
		 */
		virtual void onEnableChanged();
		/**
		 * ����ı䷽��
		 */
		virtual void onFontChanged();
		/**
		 * ��ý��㷽��
		 */
		virtual void onGotFocus();
	    /**
         * �ڿؼ��߳��е��÷���
         * @param args  ����
        */
		virtual void onInvoke(Object args);
		/**
		 * �ؼ����ط���
		 */
		virtual void onLoad();
		/**
		 * λ�øı䷽��
		 */
		virtual void onLocationChanged();
		/**
		 * ��ʧ���㷽��
		 */
		virtual void onLostFocus();
		/*
		* ���̰��·���
		*/
		virtual void onKeyDown(char key);
		/*
		* ����̧�𷽷�
		*/
		virtual void onKeyUp(char key);
		/**
		 * ��߾�ı䷽��
		 */
		virtual void onMarginChanged();
	    /**
         * �������·���
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchDown(FCTouchInfo touchInfo);
	    /**
         * �������뷽��
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchEnter(FCTouchInfo touchInfo);
	    /**
         * �����뿪����
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchLeave(FCTouchInfo touchInfo);
	    /**
         * �����ƶ����÷���
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchMove(FCTouchInfo touchInfo);
	    /**
         * ����̧�𷽷�
         * @param touchInfo  ������Ϣ
        */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/*
		* ������������
		*/
		virtual void onTouchWheel(FCTouchInfo touchInfo);
		/**
		 * �ڱ߾�ı䷽��
		 */
		virtual void onPaddingChanged();
	    /**
         * �ػ淽��
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ汳������
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ���߷���
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
	    /**
         * �ػ�ǰ������
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * �������ı䷽��
		 */
		virtual void onParentChanged();
		/**
		 * ����
		 */
		virtual void onPaste();
	    /**
         * Ԥ��ͼ����
         * @param paint  ��ͼ����
         * @param clipRect   �ü�����
        */
		virtual void onPrePaint(FCPaint *paint, const FCRect& clipRect);
		/*
		* ����Ԥ�����¼�
		*/
		virtual bool onPreviewsKeyEvent(int eventID, char key);
	    /**
         * �����°�����
         * @param eventID  �¼�ID
         * @param key      ����
         * @returns     ״̬
        */
		virtual bool onPreviewsTouchEvent(int eventID, FCTouchInfo touchInfo);
		/**
		 * �ü�����ı䷽��
		 */
		virtual void onRegionChanged();
		/**
		 * �Ƴ��ؼ�����
		 */
		virtual void onRemove();
		/**
		 * �ߴ�ı䷽��
		 */
		virtual void onSizeChanged();
		/**
		 * TAB�����ı䷽��
		 */
		virtual void onTabIndexChanged();
		/**
		 * ��ʹ��TAB�л�����
		 */
		virtual void onTabStop();
		/**
		 * �Ƿ���TAB�л��ı䷽��
		 */
		virtual void onTabStopChanged();
		/**
		 * �ı��ı䷽��
		 */
		virtual void onTextChanged();
		/**
		 * ǰ��ɫ�ı䷽��
		 */
		virtual void onTextColorChanged();
	    /**
         * ���ص�����
         * @param timerID  ���
        */
		virtual void onTimer(int timerID);
		/**
		 * �ɼ�״̬�ı䷽��
		 */
		virtual void onVisibleChanged();
		/*
		 * תΪ�������
		 */
		virtual FCPoint pointToControl(const FCPoint& mp);
	    /**
         * ��ȡ����ڿؼ����������
         * @param point  ����
         * @returns  �������
        */
		virtual FCPoint pointToNative(const FCPoint& mp);
	    /**
         * �Ƴ��ؼ�
         * @param control �ؼ�
        */
		virtual void removeControl(FCView *control);
	    /**
         * ȡ��ע���¼�
         * @param func  ����ָ��
         * @param eventID  �¼�ID
        */
		virtual void removeEvent(Object func, int eventID);
	    /**
         * ��������
         * @param name  ��������
         * @param value ����ֵ
        */
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ��ʾ�ؼ�
		 */
		virtual void show();
	    /**
         * ��ʼ���
         * @param timerID  ���
         * @param interval ���
        */
		virtual void startTimer(int timerID, int interval);
	    /**
         * ֹͣ���
         * @param timerID  ���
        */
		virtual void stopTimer(int timerID);
	    /**
         * ���ؼ��������
         * @param childControl  �ӿؼ�
        */
		virtual void sendChildToBack(FCView *childControl);
		/**
		 * ���ؼ��ŵ���������ʾ
		 */
		virtual void sendToBack();
		/**
		 * ���½���
		 */
		virtual void update();
	};
}
#endif