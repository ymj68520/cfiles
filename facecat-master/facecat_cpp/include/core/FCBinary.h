/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCBINARY_H__
#define __FCBINARY_H__
#include "..\\..\\stdafx.h"
#include "FCStr.h"
#pragma once
#define	DATA_LACK -1
#define PAGE_SIZE 1024 * 8
typedef unsigned char BYTE;
typedef BYTE *PBYTE;

namespace FaceCat
{
	/**
	 * ������
	 */
	class FCBinary
	{
	protected:
		PBYTE m_pBase;
		unsigned int m_nDataSize;
		unsigned int m_nSize;
		unsigned int m_nInitSize;
		bool m_bSustainSize;
		static unsigned int m_dwPageSize;
		unsigned int deAllocateBuffer(unsigned int nRequestedSize);
		unsigned int getMemSize();
	public:
	    /**
	     * ������
	     */
		FCBinary();
		/*
		* ��������
		*/
		virtual ~FCBinary();
		const FCBinary& operator+(FCBinary& buff);
		bool m_bSingleRead;
		unsigned int m_nReadPos;
	public:
		/*
		* ���
		*/
		void clearBytes();
		/*
		* ����
		*/
		void copy(FCBinary& buffer);	
		/*
		* �������
		*/
		unsigned int deleteBuffer(unsigned int nSize);
		/*
		* ���ĩβ
		*/
		unsigned int deleteEnd(unsigned int nSize);
		/*
		* ��ȡ�ļ�
		*/
		void fileRead(const String& strFileName);
		/*
		* д�ļ�
		*/
		void fileWrite(const String& strFileName);
		/*
		* ��ȡ���ļ�
		*/
		PBYTE getBytes(unsigned int nPos = 0);
		/*
		* ��ȡ���ĳ���
		*/
		unsigned int getBytesLen();
		/*
		* ��ʼ��
		*/
		void initialize(unsigned int nInitsize, bool bSustain);
		/*
		* ����
		*/
		unsigned int insert(const void *pData, unsigned int nSize);
		/*
		* ����
		*/
		unsigned int insert(String& strData);
		/*
		* ��ȡ
		*/
		unsigned int read(void *pData, unsigned int nSize);
		/**
	     * ��ȡChar����
	     */
		char readChar();
		/**
	     * ��ȡDouble����
	     */
		double readDouble();
		/**
	     * ��ȡFloat����
	     */
		float readFloat();
		/**
	     * ��ȡInt����
	     */
		int readInt();
		/**
	     * ��ȡLong����
	     */
		INT64 readLong();
		/**
	     * ��ȡShort����
	     */
		short readShort();
		/**
	     * ��ȡ�ַ�������
	     */
		String readString();
		/**
	     * ��ȡ�ַ�������
	     */
		string readString2();
		/*
		* ���¿����ڴ�
		*/
		unsigned int reAllocateBuffer(unsigned int nRequestedSize);
		/*
		* ��������
		*/
		unsigned int skipData(int nSize);
	    /**
         * д����
         * @param bytes  ��
         * @param len   ����
        */
		unsigned int write(const void *pData, unsigned int nSize);
		/*
		* д��String������
		*/
		unsigned int write(String& strData);
	    /**
         * д��Char������
         * @param val   Char������
        */
		void writeChar(char cValue);
	    /**
         * д��Double������
         * @param val   Double������
        */
		void writeDouble(double dValue);
	    /**
         * д��Float������
         * @param val   Float������
        */
		void writeFloat(float fValue);
	    /**
         * д��Int������
         * @param val   Int������
        */
		void writeInt(int nValue);
		/**
         * д��Long������
         * @param val   Long������
        */
		void writeLong(INT64 hValue);
	    /**
         * д��Short������
         * @param val   Short������
        */
		void writeShort(short sValue);
	    /**
         * д���ַ�������
         * @param val   �ַ�������
        */
		unsigned int writeString(const String& strData);
		/**
         * д���ַ�������
         * @param val   �ַ�������
        */
		unsigned int writeString(const string& strData);
	};
}

#endif