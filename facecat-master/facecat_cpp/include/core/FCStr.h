/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCSTR_H__
#define __FCSTR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include <tchar.h>
#include "FCPaint.h"
#include "FCView.h"

namespace FaceCat{
	/*
	* �ַ���ת��
	*/
	class CodeConvert_Win{
	public:
		CodeConvert_Win(const char* input, unsigned int fromCodePage, unsigned int toCodePage);
		~CodeConvert_Win(){
			delete [] wcharBuf;        
			delete [] charBuf;    
			};    
			const char * toString(){    
				return charBuf;    
			};
	private:    
		  wchar_t * wcharBuf;    
		  char * charBuf;
	};

	/*
	* �ַ�������
	*/
	class FCStr{
	public:
		static double round(double x); 
	public:
		/*
		* ����ת��
		*/
		static void ANSCToUnicode(string& out, const char* inSrc);
		/*
		* �����ַ���
		*/
		static void contact(wchar_t *str, const wchar_t *str1, const wchar_t *str2, const wchar_t *str3);
	    /**
         * ê����Ϣת��Ϊ�ַ�
         * @param anchor  ê����Ϣ
         * @returns �ַ�
        */
		static String convertAnchorToStr(const FCAnchor& anchor);
	    /**
         * ��������ֵת��Ϊ�ַ�
         * @param value   ��ֵ
         * @returns �ַ�
        */
		static String convertBoolToStr(bool value);
	    /**
         * ��ɫת��Ϊ�ַ�
         * @param color  ��ɫ
         * @returns �ַ�
        */
		static String convertColorToStr(Long color);
	    /**
         * ���ݲ���ת�ַ���
         * @param contentAlignment  ���ݲ���
         * @returns �ַ���
        */
		static String convertContentAlignmentToStr(FCContentAlignment contentAlignment);
		/*
		* �����״תΪ�ַ���
		*/
		static String convertCursorToStr(FCCursors cursor);
	    /**
         * ˫���ȸ�������ֵת��Ϊ�ַ�
         * @param value  ��ֵ
         * @returns �ַ�
        */
		static String convertDoubleToStr(double value);
	    /**
         * ����Ϣת��Ϊ�ַ�
         * @param dock  ����Ϣ
         * @returns �ַ�
        */
		static String convertDockToStr(FCDockStyle dock);
	    /**
         * �����ȸ���������ֵת��Ϊ�ַ�
         * @param value  ��ֵ
         * @returns �ַ�
        */
		static String convertFloatToStr(float value);
	    /**
         * ����ת��Ϊ�ַ�
         * @param font  ����
         * @returns �ַ�
        */
		static String convertFontToStr(FCFont *font);
	    /**
         * �������з�ʽת��Ϊ�ַ�
         * @param horizontalAlign  �������з�ʽ
         * @returns �ַ�
        */
		static String convertHorizontalAlignToStr(FCHorizontalAlign horizontalAlign);
	    /**
         * ������ֵת��Ϊ�ַ�
         * @param value  ��ֵ
         * @returns �ַ�
        */
		static String convertIntToStr(int value);
	    /**
         * ������ʽת��Ϊ�ַ�
         * @param layoutStyle  ������ʽת
         * @returns ������ʽ
        */
		static String convertLayoutStyleToStr(FCLayoutStyle layoutStyle);
	    /**
         * ��������ֵת��Ϊ�ַ�
         * @param value   ��ֵ
         * @returns �ַ���
        */
		static String convertLongToStr(Long value);
	    /**
         * �߾�ת��Ϊ�ַ�
         * @param padding  �߾�
         * @returns �ַ�
        */
		static String convertPaddingToStr(const FCPadding& padding);
	    /**
         * ����ת��Ϊ�ַ�
         * @param point  ����
         * @returns �ַ�
        */
		static String convertPointToStr(const FCPoint& mp);
	    /**
         * ����ת��Ϊ�ַ�
         * @param rect  ����
         * @returns �ַ�
        */
		static String convertRectToStr(const FCRect& rect);
	    /**
         * ��Сת��Ϊ�ַ�
         * @param size  ��С
         * @returns �ַ�
        */
		static String convertSizeToStr(const FCSize& size);
	    /**
         * �ַ�ת��Ϊê����Ϣ
         * @param str  �ַ�
         * @returns ê����Ϣ
        */
		static FCAnchor convertStrToAnchor(const String& str);
	    /**
         * �ַ�ת��Ϊ������
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static bool convertStrToBool(const String& str);
	    /**
         * �ַ�ת��Ϊ��ɫ
         * @param str  �ַ�
         * @returns ��ɫ
        */
		static Long convertStrToColor(const String& str);
	    /**
         * �ַ���ת���ݲ���
         * @param str  �ַ�
         * @returns �ַ���
        */
		static FCContentAlignment convertStrToContentAlignment(const String& str);
		/*
		* �ַ���תΪ�����״
 		*/
		static FCCursors convertStrToCursor(const String& str);
	    /**
         * �ַ�ת��Ϊ����Ϣ
         * @param str  �ַ�
         * @returns ����Ϣ
        */
		static FCDockStyle convertStrToDock(const String& str);
	    /**
         * �ַ�ת��Ϊ˫���ȸ�������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static double convertStrToDouble(const String& str);
		/*
		* �ַ�ת��Ϊ˫���ȸ�������ֵ
		*/
		static double convertStrToDouble(const wchar_t *str);
	    /**
         * �ַ�ת��Ϊ�����ȸ�������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static float convertStrToFloat(const String& str);
	    /**
         * �ַ�ת��Ϊ����
         * @param str  �ַ�
         * @returns ����
        */
		static FCFont* convertStrToFont(const String& str);
	    /**
         * �ַ�ת��Ϊ�������з�ʽ
         * @param str  �ַ�
         * @returns �ַ�
        */
		static FCHorizontalAlign convertStrToHorizontalAlign(const String& str);
	    /**
         * �ַ�ת��Ϊ������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static int convertStrToInt(const String& str);
		/**
         * �ַ�ת��Ϊ������ֵ
         * @param str  �ַ�
         * @returns ��ֵ
        */
		static int convertStrToInt(const wchar_t *str);
	    /**
         * ������ʽת��Ϊ�ַ�
         * @param str  �ַ�
         * @returns ������ʽ
        */
		static FCLayoutStyle convertStrToLayoutStyle(const String& str);
	    /**
         * �ַ�ת��λ��������ֵ
         * @param str  �ַ���
         * @returns ������
        */
		static Long convertStrToLong(const String& str);
		/*
		* �ַ�ת��λ��������ֵ
		*/
		static Long convertStrToLong(const wchar_t *str);
	    /**
         * �ַ�ת��Ϊ�߾�
         * @param str  �ַ�
         * @returns �߾�
        */
		static FCPadding convertStrToPadding(const String& str);
	    /**
         * �ַ�ת��Ϊ����
         * @param str  �ַ�
         * @returns ����
        */
		static FCPoint convertStrToPoint(const String& str);
	    /**
         * �ַ�ת��Ϊ����
         * @param str  �ַ�
         * @returns ����
        */
		static FCRect convertStrToRect(const String& str);
	    /**
         * �ַ�ת��Ϊ��С
         * @param str  �ַ�
         * @returns ��С
        */
		static FCSize convertStrToSize(const String& str);
	    /**
         * �ַ�ת��Ϊ�������з�ʽ
         * @param str  �ַ�
         * @returns �ַ�
        */
		static FCVerticalAlign convertStrToVerticalAlign(const String& str);
	    /**
         * �������з�ʽת��Ϊ�ַ�
         * @param verticalAlign  �������з�ʽ
         * @returns �ַ�
        */
		static String convertVerticalAlignToStr(FCVerticalAlign verticalAlign);
		/*
		* ��ȡ����·��
		*/
		static string getAppPath();
		/*
		* ��ȡ���ڵ���ֵ
		*/
		static double getDateNum(int tm_year, int tm_mon, int tm_mday, int tm_hour, int tm_min, int tm_sec, int tm_msec);
		/*
		* ������ֵ��ȡ����
		*/
        static void getDateByNum(double num, int *tm_year, int *tm_mon, int *tm_mday, int *tm_hour, int *tm_min, int *tm_sec, int *tm_msec);
	    /**
         * ��ȡGuid
         * @returns  Guid
        */
		static string getGuid();
		/*
		* ��ȡ��ʽ���������
		*/
		static void getFormatDate(double date, wchar_t *str);
		/*
		* ��ȡ��ʽ���������
		*/
		static String getFormatDate(const String& format, int year, int month, int day, int hour, int minute, int second);
	    /**
         * ���ݱ���С����λ�ý�double��ת��ΪString��
         * @param value  ֵ
         * @param digit ����С����
         * @returns  ��ֵ�ַ�
        */
		static void getValueByDigit(double value, int digit, wchar_t *str);
		/*
		* ʮ������תʮ����
		*/
		static int hexToDec(const char *str);
		/*
		* �滻�ַ���
		*/
		static string replace(const string& str, const string& src, const string& dest);
		/*
		* �滻�ַ���
		*/
		static String replace(const String& str, const String& src, const String& dest);
	    /**
         * ��ȫ��DoubleתFloat
         * @param value  ֵ
         * @param digit ����С��λ��
         * @returns  Float
        */
		static float safeDoubleToFloat(double value, int digit);
		/*
		* �ָ��ַ���
		*/
		static ArrayList<String> split(const String& str, const String& pattern);
		/*
		* ���ַ���ת���ַ���
		*/
		static String stringTowstring(const string& strSrc);
		/*
		* תΪСд
		*/
		static String toLower(const String& str);
		/*
		* תΪ��д
		*/
		static String toUpper(const String& str);
		/*
		* �ַ��������ʽת��
		*/
		static void unicodeToANSC(string& out, const char* inSrc);
		/*
		* URL����
		*/
		static string urlEncode(const std::string& szToEncode);
		/*
		* URL����
		*/
		static string urlDecode(const std::string& szToDecode);
		/*
		* ���ַ���ת���ַ���
		*/
		static string wstringTostring(const String& strSrc);
	};
}
#endif