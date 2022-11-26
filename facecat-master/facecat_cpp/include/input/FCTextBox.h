/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCTEXTBOX_H__
#define __FCTEXTBOX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\scroll\\FCHScrollBar.h"
#include "..\\scroll\\FCVScrollBar.h"
#include "..\\div\\FCDiv.h"
#include <stack>

namespace FaceCat{
	/*
	* ��
	*/
	struct WordLine{
	public:
	    /**
		 * ��������
		 */
		int m_end;
		/**
		 * ��ʼ����
		 */
		int m_start;
		WordLine(int start, int end){
			m_start = start;
			m_end = end;
		}
	};

	/*
	* �ı���
	*/
	class FCTextBox : public FCDiv{
	private:
		/*
		* TICKֵ
		*/
		int m_tick;
		/**
		 * ���ID
		 */
		int m_timerID;
	protected:
	    /**
		 * �����Ƿ���
		 */
		bool m_isKeyDown;
		/**
		 * �Ƿ�������
		 */
		bool m_isTouchDown;
		/**
		 * �и�
		 */
		int m_lineHeight;
		/**
		 * ����
		 */
		vector<WordLine> m_lines;
		/**
		 * �Ƿ������ʾ
		 */
		bool m_multiline;
		/**
		 * ����ƫ����
		 */
		int m_offsetX;
		/**
		 * �����ַ�
		 */
		wchar_t m_passwordChar;
		/**
		 * ���־��η�Χ
		 */
		vector<FCRectF> m_ranges;
		/**
		 * ����ջ
		 */
		stack<String> m_redoStack;
		/**
		 * �Ƿ�ֻ��
		 */
		bool m_readOnly;
		/**
		 * �Ƿ�����������
		 */
		bool m_rightToLeft;
		/**
		 * ѡ�еı���ɫ
		 */
		Long m_selectionBackColor;
		/**
		 * ѡ�е�ǰ��ɫ
		 */
		Long m_selectionTextColor;
		/**
		 * ѡ�г���
		 */
		int m_selectionLength;
		/**
		 * ѡ�п�ʼλ��
		 */
		int m_selectionStart;
		/**
		 * �Ƿ���ʾ���
		 */
		bool m_showCursor;
		/**
		 * ��ʼ�ƶ�������
		 */
		int m_startMovingIndex;
		/**
		 * �����ƶ�������
		 */
		int m_stopMovingIndex;
		/**
		 * ��ʱ����
		 */
		String m_tempText;
		/**
		 * ��ʱ���ֵ���ɫ
		 */
		Long m_tempTextColor;
		/**
		 * ���ݵĺ���������ʽ
		 */
		FCHorizontalAlign m_textAlign;
		/**
		 * �����Ƿ�ı�
		 */
		bool m_textChanged;
		/**
		 * �����˸Ƶ��
		 */
		int TICK;
		/**
		 * ����ջ
		 */
		stack<String> m_undoStack;
		/**
		 * ���ִ�С
		 */
		vector<FCSizeF> m_wordsSize;
		/**
		 * ���б༭�ؼ��Ƿ���������
		 */
		bool m_wordWrap;
		/**
		 * ��������ƶ�
		 */
		void cursorDown();
		/**
		 * ����ƶ������Ҷ�
		 */
		void cursorEnd();
		/**
		 * ����ƶ��������
		 */
		void cursorHome();
		/**
		 * ��������ƶ�
		 */
		void cursorLeft();
		/**
		 * ��������ƶ�
		 */
		void cursorRight();
		/**
		 * ��������ƶ�
		 */
		void cursorUp();
		/**
		 * ɾ���ַ�
		 */
		void deleteWord();
		/**
		 * �����ַ�
		 */
		void insertWord(const String& str);
		/**
		 * �ж��ַ������������Ƿ�ɼ�
		 */
		bool isLineVisible(int indexTop, int indexBottom, int cell, int floor, int lineHeight, double visiblePercent);
		/*
		* �ж��ַ������������Ƿ�ɼ�
		*/
		bool isLineVisible(int index, double visiblePercent);
		/**
		 * �����ƶ�����
		 */
		void setMovingIndex(int sIndex, int eIndex);
	public:
		/*
		* ���캯��
		*/
		FCTextBox();
		/*
		* ��������
		*/
		virtual ~FCTextBox();
		/**
		 * ��ȡ����
		 */
		virtual int getLinesCount();
		/**
		 * ��ȡ�и�
		 */
		virtual int getLineHeight();
		/**
		 * �����и�
		 */
		virtual void setLineHeight(int lineHeight);
		/**
		 * ��ȡ����
		 */
		virtual vector<WordLine> getLines();
		/**
		 * ��ȡ�Ƿ������ʾ
		 */
		virtual bool isMultiline();
		/**
		 * �����Ƿ������ʾ
		 */
		virtual void setMultiline(bool multiline);
		/**
		 * ��ȡ�����ַ�
		 */
		virtual wchar_t getPasswordChar();
		/**
		 * ���������ַ�
		 */
		virtual void setPasswordChar(wchar_t passwordChar);
		/**
		 * ��ȡ�Ƿ�ֻ��
		 */
		virtual bool isReadOnly();
		/**
		 * �����Ƿ�ֻ��
		 */
		virtual void setReadOnly(bool readOnly);
		/**
		 * ��ȡ�Ƿ�����������
		 */
		virtual bool isRightToLeft();
		/**
		 * �����Ƿ�����������
		 */
		virtual void setRightToLeft(bool rightToLeft);
		/**
		 * ��ȡѡ�еı���ɫ
		 */
		virtual Long getSelectionBackColor();
		/**
		 * ����ѡ�еı���ɫ
		 */
		virtual void setSelectionBackColor(Long selectionBackColor);
		/**
		 * ��ȡѡ�е�ǰ��ɫ
		 */
		virtual Long getSelectionTextColor();
		/**
		 * ����ѡ�е�ǰ��ɫ
		 */
		void setSelectionTextColor(Long selectionTextColor);
		/**
		 * ��ȡѡ�г���
		 */
		virtual int getSelectionLength();
		/**
		 * ����ѡ�г���
		 */
		virtual void setSelectionLength(int selectionLength);
		/**
		 * ��ȡѡ�п�ʼλ��
		 */
		virtual int getSelectionStart();
		/**
		 * ����ѡ�п�ʼλ��
		 */
		virtual void setSelectionStart(int selectionStart);
		/**
		 * ��ȡ��ʱ����
		 */
		virtual String getTempText();
		/**
		 * ������ʱ����
		 */
		virtual void setTempText(const String& tempText);
		/**
		 * ��ȡ��ʱ���ֵ���ɫ
		 */
		virtual Long getTempTextColor();
		/**
		 * ������ʱ���ֵ���ɫ
		 */
		virtual void setTempTextColor(Long tempTextColor);
		/**
		 * ��ȡ���ݵĺ���������ʽ
		 */
		virtual FCHorizontalAlign getTextAlign();
		/**
		 * �������ݵĺ���������ʽ
		 */
		virtual void setTextAlign(FCHorizontalAlign textAlign);
		/**
		 * ��ȡ���б༭�ؼ��Ƿ���������
		 */
		virtual bool isWordWrap();
		/**
		 * ���ö��б༭�ؼ��Ƿ���������
		 */
		virtual void setWordWrap(bool wordWrap);
	public:
	    /**
		 * �ж��Ƿ�����ظ�
		 */
		bool canRedo();
		/**
		 * �ж��Ƿ���Գ���
		 */
		bool canUndo();
		/**
		 * ����
		 */
		void clearRedoUndo();
		/**
		 * ��ȡ���ݵĸ߶�
		 */
		virtual int getContentHeight();
		/**
		 * ��ȡ���ݵĿ��
		 */
		virtual int getContentWidth();
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
		 * ��ȡѡ�е�����
		 */
		String getSelectionText();
		/**
		 * �ı����뷽��
		 */
		virtual void onChar(wchar_t ch);
		/**
		 * ��������
		 */
		virtual void onCopy();
		/**
		 * ����
		 */
		virtual void onCut();
		/**
		 * ��ȡ���㷽��
		 */
		virtual void onGotFocus();
		/**
		 * ���̷���
		 */
		virtual void onKeyDown(char key);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onKeyUp(char key);
		/**
		 * ��ʧ���㷽��
		 */
		virtual void onLostFocus();
		/**
		 * �������·���
		 */
		virtual void onTouchDown(FCTouchInfo touchInfo);
		/**
		 * �����ƶ�����
		 */
		virtual void onTouchMove(FCTouchInfo touchInfo);
		/**
		 * ����̧�𷽷�
		 */
		virtual void onTouchUp(FCTouchInfo touchInfo);
		/**
		 * �ػ�ǰ������
		 */
		virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
		/**
		 * ճ������
		 */
		virtual void onPaste();
		/**
		 * ���ֳߴ�ı��¼�
		 */
		virtual void onSizeChanged();
		/**
		 * ��ʹ��TAB�л�����
		 */
		virtual void onTabStop();
		/**
		 * ���ָı䷽��
		 */
		virtual void onTextChanged();
		/**
		 * ���ص�����
		 */
		virtual void onTimer(int timerID);
		/**
		 * �ظ�
		 */
		void redo();
		/**
		 * ȫѡ
		 */
		void selectAll();
		/**
		* ��������
		* @param  name  ��������
		* @param  value  ����ֵ
		*/
		virtual void setProperty(const String& name, const String& value);
		/**
		 * ����
		 */
		void undo();
		/**
		 * ���²��ַ���
		 */
		virtual void update();
	};
}

#endif