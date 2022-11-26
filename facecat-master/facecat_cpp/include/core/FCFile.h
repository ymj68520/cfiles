/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCFILE_H__
#define __FCFILE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "io.h"
#include <direct.h>
#include <fstream>
#include <sys/stat.h>

namespace FaceCat{
	/**
     * �ļ�������
     *
     */
	class FCFile{
	public:
		/**
		 * ׷������
		 */
		static bool append(const char *file, const char *content);
		/**
		 * ׷������-���ַ�
		 */
		static bool append(const String &file, const String &content);
		/**
		 * ����Ŀ¼
		 */
		static void createDirectory(const char *dir);
		/**
		 * ����Ŀ¼-���ַ�
		 */
		static void createDirectory(const String &dir);
		/**
		 * �ж�Ŀ¼�Ƿ����
		 */
		static bool isDirectoryExist(const char *dir);
		/**
		 * �ж�Ŀ¼�Ƿ����-���ַ�
		 */
		static bool isDirectoryExist(const String &dir);
		/**
		 * �ļ��Ƿ����
		 */
		static bool isFileExist(const char *file);
		/**
		 * �ļ��Ƿ����-���ַ�
		 */
		static bool isFileExist(const String &file);
		/**
		 * ��ȡĿ¼
		 */
		static bool getDirectories(const char *dir, ArrayList<string> *dirs);
		/**
		 * ��ȡĿ¼-���ַ�
		 */
		static bool getDirectories(const String &file, ArrayList<String> *dirs);
		/**
		 * ��ȡ�ļ�����
		 */
		static int getFileLength(const char *file);
		/**
		 * ��ȡ�ļ�����-���ַ�
		 */
		static int getFileLength(const String &file);
		/**
		 * ��ȡ�ļ�
		 */
		static bool getFiles(const char *dir, ArrayList<string> *files);
		/**
		 * ��ȡ�ļ�-���ַ�
		 */
		static bool getFiles(const String &dir, ArrayList<String> *files);
		/**
		 * ��ȡ�ļ�״̬
		 */
		static int getFileState(const char *file, struct stat *buf);
		/**
		 * ��ȡ�ļ�״̬-���ַ�
		 */
		static int getFileState(const String &file, struct stat *buf);
		/**
		 * ��ȡ�ļ�
		 */
		static bool read(const char *file, string *content);
		/**
		 * ��ȡ�ļ�-���ַ�
		 */
		static bool read(const String &file, String *content);
		/**
		 * �Ƴ��ļ�
		 */
		static void removeFile(const char *file);
		/**
		 * �Ƴ��ļ�-���ַ�
		 */
		static void removeFile(const String &file);
		/**
		 * д���ļ�
		 */
		static bool write(const char *file, const char *content);
		/**
		 * д���ļ�-���ַ�
		 */
		static bool write(const String &file, const String &content);
	};
}
#endif