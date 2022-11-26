/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */


#ifndef __FCSCRIPT_H__
#define __FCSCRIPT_H__
#pragma once
#define FUNCTIONID_CHUNK 40
#define FUNCTIONID_FUNCVAR 10
#define FUNCTIONID_FUNCTION 9
#define FUNCTIONID_VAR 10

#include "..\\..\\stdafx.h"
#include "..\\core\\FCStr.h"
#include "Enums.h"
#include "FCDataTable.h"
#include "ChartDiv.h"
#include "BaseShape.h"

namespace FaceCat{
	class FCScript;
	class CMathElement;

	/*
	* ��������
	*/
	struct LPDATA
	{
	public:
		LPDATA()
		{
		};
		/*
		* ���һ��ֵ
		*/
		double lastvalue;
		/*
		* ��һ��ֵ
		*/
		double first_value;
		/*
		* ģʽ
		*/
		int mode;
		/*
		* ��
		*/
		double sum;
	};

	/*
	* ����
	*/
	class CVariable{
	public:
	    /**
         * ����
         */
		CVariable();
		/*
		* ���캯��
		*/
		virtual ~CVariable();
		/**
	     * ��״ͼ
	     */
		BarShape *m_barShape;
		/**
	     * K��
	     */
		CandleShape *m_candleShape;
		/**
	     * ���ʽ
	     */
		String m_expression;
		/**
	     * �ֶ�
	     */
		int m_field;
		/**
	     * �ֶε�����
	     */
		int m_fieldIndex;
		/**
	     * ��ʾ�ֶ�
	     */
		String m_fieldText;
		/**
	     * �����ı��
	     */
		int m_functionID;
		/**
	     * ��������
	     */
		String m_funcName;
		/**
	     * ָ��
	     */
		FCScript *m_indicator;
		/**
	     * ����
	     */
		int m_line;
		PointShape *m_pointShape;
		/**
	     * ����ͼ
	     */
		PolylineShape *m_polylineShape;
		/**
	     * ��ֵ
	     */
		String m_name;
		/**
	     * ����
	     */
		CVariable **m_parameters;
		/*
		* ��������
		*/
		int m_parametersLength;
		/**
	     * �ָ��ı��ʽ
	     */
		CMathElement **m_splitExpression;
		/*
		* ���ʽ����
		*/
		int m_splitExpressionLength;
		/**
	     * ��ʱ�ֶ�
	     */
		int *m_tempFields;
		/*
		* ��ʱ�ֶγ���
		*/ 
		int m_tempFieldsLength;
		/**
	     * ����ʱ�ֶε�����
	     */
		int *m_tempFieldsIndex;
		/*
		* ����ʱ�ֶεĳ���
		*/
		int m_tempFieldsIndexLength;
		/**
	     * ����
	     */
		TextShape *m_textShape;
		/**
	     * ����
	     */
		int m_type;
		/**
	     * ������ֵ
	     */
		double m_value;
		/**
	     * �����յ��ֶ�
	     */
		void createTempFields(int count);
	};

	/*
	* ������Ԫ
	*/
	class CMathElement{
	public:
	    /*
         * ���캯��
         */
		CMathElement();
	    /*
         * ���캯��
         */
		CMathElement(int type, double value);
	    /*
         * ��������
         */
		virtual ~CMathElement();
		/**
	     * ����
	     */
		int m_type;
		/**
	     * ������ֵ
	     */
		double m_value;
		/**
	     * ����
	     */
		CVariable *m_var;
	};

	/*
	* ������Ԫ��չ
	*/
	class CMathElementEx : public CMathElement{
	public:
		/*
		* �¸���Ԫ
		*/
		CMathElementEx *m_next;
		/*
		* ���캯��
		*/
		CMathElementEx(int type, double value):CMathElement(type, value){
			m_next = 0;
		}
		/*
		* ��������
		*/
		virtual ~CMathElementEx(){
			if(m_next){
				delete m_next;
				m_next = 0;
			}
		}
	};

	/*
	* ����
	*/
	class CFunction{
	public:
		/*
		* ���캯��
		*/
		CFunction();
		/*
		* ��������
		*/
		virtual ~CFunction();
		/*
		* ID
		*/
		int m_ID;
		/*
		* ����
		*/
		String m_name;
		/*
		* ����
		*/ 
		int m_type;
	public:
		/*
		* �����
		*/
		virtual double onCalculate(CVariable *var);
	};

    /*
     * ��ʱ����
     */
	class CVar{
	public:
	    /**
	     * �б�
	     */
        ArrayList<String> *m_list;
        /**
	     * ��ϣ��
	     */
        HashMap<String, String> *m_map;
        /**
	     * ��ֵ
	     */
        double m_num;
        /**
	     * �ַ���
	     */
        String m_str;
        /**
	     * ����
	     */
        int m_type;
        /**
	     * �ϼ�����
	     */
        CVar *m_parent;
	public:
		/*
		* ���캯��
		*/
        CVar(){
			m_list = 0;
			m_map = 0;
			m_parent = 0;
        }
		/*
		* ��������
		*/
        virtual ~CVar(){
			if (m_list){
                delete m_list;
				m_list = 0;
            }
            if (m_map){
                delete m_map;
				m_map = 0;
            }
            m_parent = 0;
        }
	public:
	    /**
         * ��ȡ����
         * @param indicator   ָ��
         * @param name        ����
         * @returns ��ֵ
        */
        virtual String getText(FCScript *indicator, CVariable *name);
        /**
         * ��ȡֵ
         * @param indicator   ָ��
         * @param name        ����
         * @returns ��ֵ
        */
		virtual double getValue(FCScript *indicator, CVariable *name);
	    /**
         * ��������
         * @param indicator   ָ��
         * @param name        ����
         * @param value       ֵ
        */
		virtual double onCreate(FCScript *indicator, CVariable *name, CVariable *value);
	    /**
         * ����ֵ
         * @param indicator   ָ��
         * @param name        ����
         * @param value       ֵ
        */
		virtual void setValue(FCScript *indicator, CVariable *name, CVariable *value);
    };

    /*
     * ��ʱ��������
     */
	class CVarFactory{
	public:
	    /**
         * ��������
         * @returns ����
        */
		virtual CVar* createVar(){
			return new CVar;
		}
	};

	/*
	* �ű�
	*/
	class FCScript{
	protected:
		CRITICAL_SECTION _csLock;
		/**
	     * �����б�
	     */
		HashMap<String,double> m_defineParams;
		/**
	     * �����б�
	     */
		HashMap<String,CFunction*> m_functions;
		/**
	     * �����Ĺ�ϣ��
	     */
		HashMap<int, CFunction*> m_functionsMap;
		/**
	     * ��ǰ���ڼ��������
	     */
		int m_index;
		/**
	     * ��伯��
	     */
		ArrayList<CVariable*> m_lines;
		/**
	     * ϵͳ��ɫ
	     */
		ArrayList<Long> m_systemColors;
		/**
	     * TAGֵ
	     */
		Object m_tag;
		/**
	     * ����������
	     */
		HashMap<String, CVariable*> m_tempFunctions;
		/**
	     * ������
	     */
        HashMap<String, CVariable*> m_tempVariables;
        /**
	     * ��������
	     */
		ArrayList<CVariable*> m_variables;
		/**
	     * ��ʱ��������
	     */
		CVarFactory *m_varFactory;
		/**
	     * ������ʶ�ַ���
	     */
		String VARIABLE;
		/**
	     * ��ʶ�ַ���2
	     */
		String VARIABLE2;
		/**
	     * ��ʶ�ַ���3
	     */
		String VARIABLE3;
		/**
	     * ���з���
	     */
		String FUNCTIONS;
		/*
		* �������ķ���
		*/
		String FUNCTIONS_FIELD;
	protected:
	    /**
	     * �����������
	     */
		AttachVScale m_attachVScale;
		/**
	     * ������ʶ
	     */
		int m_break;
		/**
	     * ����Դ
	     */
		FCDataTable *m_dataSource;
		/**
	     * ͼ��
	     */
		ChartDiv *m_div;
		/**
	     * ����
	     */
		String m_name;
		/**
	     * �ű�
	     */
		double m_result;
		/**
	     * ���Ͻ��
	     */
		CVar m_resultVar;
	protected:
	    /**
	     * ��������а����ķ����ͱ���
	     */
		void FCScript::analysisVariables(String *sentence, int line, String funcName, String fieldText, bool isFunction);
	    /**
         * ���ؽű���
         * @param line  �ű���
        */
		void analysisScriptLine(String line);
	    /**
         * �Ա��ʽ������ֵ����ֵ֮ǰ���Ƚ����﷨У��
         * @param expr      Ҫ��ֵ�ı��ʽ
         * @returns ��ֵ���
        */
		double calculate(CMathElement **expr, int exprLength);
	    /**
         * ���÷���
         * @param var   ����
         * @returns ���
        */
		double callFunction(CVariable *var);
	    /**
         * ɾ����ʱ����
         * @param var  ����
        */
		void deleteTempVars();
	    /**
         * ɾ����ʱ����
         * @param var  ����
        */
		void deleteTempVars(CVariable *var);
	    /**
         * �����ַ�����ȡ��ɫ
         * @param strColor  �ַ���
         * @returns ��ɫ
        */
		Long getColor(const String& strColor);
	    /**
         * ������Դ�л�ȡ����ָ����Ҫ��MATH_STRUCT�ṹ
         * @param   fieldIndex   �ֶ�
         * @param   mafieldIndex  ����MAֵ�ֶ�
         * @param   index    ��������
         * @param   n        ����
         * @returns MATH_STRUCT�ṹ
        */
		LPDATA getDatas(int fieldIndex, int mafieldIndex, int index, int n);
	    /**
         * ��ȡ�ߵĿ��
         * @param strLine  �ߵ�����
         * @returns �߿�
        */
		float getLineWidth(const String& strLine);
	    /**
         * ��ȡ�м�ű�
         * @param script   �ű�
         * @param lines    ��
        */
		int getMiddleScript(const String& script, ArrayList<String> *lines);
	    /**
         * ��ȡ��������
         * @param   op    �ַ���
         * @returns ��������
        */
		int getOperator(const String& op);
		/*
		* �Ƿ�����
		*/
		bool isNumeric(const String& str);
	    /**
         * �滻�����ͱ���
         * @param  parameter  ����
         * @returns �滻�����
        */
		String replace(const String& parameter);
	    /**
         * �ѱ��ʽ��ֳ��ַ������飬���ں���ļ�����ֵ
         * @param expression  ���ʽ
         * @returns  �����ҷ��ش��±�0��ʼ���ַ�������
        */
		CMathElement** splitExpression(const String& expression, int *sLength);
	    /**
         * �ѱ��ʽ��ֳ��ַ������飬���ں���ļ�����ֵ
         * @param expression  ���ʽ
         * @returns  �����ҷ��ش��±�0��ʼ���ַ�������
        */
		String* splitExpression2(const String& expression, int *sLength);
	public:
		/*
		* ���캯��
		*/
		FCScript();
		/*
		* ��������
		*/
		virtual ~FCScript();
		/**
	     * ��Ҫ����
	     */
		HashMap<String ,int> m_mainVariables;
		/**
	     * ��ʱ����
	     */
		HashMap<int, CVar*> m_tempVars;
		/**
	     * ��ȡ�����������
	     */
		virtual AttachVScale getAttachVScale();
		/**
	     * ���������������
	     */
		virtual void setAttachVScale(AttachVScale attachVScale);
		/**
	     * ��ȡ����Դ
	     */
		virtual FCDataTable* getDataSource();
		/**
	     * ��������Դ
	     */
		virtual void setDataSource(FCDataTable *dataSource);
		/**
	     * ��ȡͼ��
	     */
		virtual ChartDiv* getDiv();
		/**
	     * ����ͼ��
	     */
		virtual void setDiv(ChartDiv *div);
		/**
	     * ��ȡ��ǰ���ڼ��������
	     */
		virtual int getIndex();
		/**
	     * ��ȡ����
	     */
		virtual String getName();
		/**
	     * ��������
	     */
		virtual void setName(const String& name);
		/**
	     * ��ȡ�ű�
	     */
		virtual double getResult();
		/**
	     * ���ýű�
	     */
		virtual void setScript(const String& script);
		/**
	     * ��ȡϵͳ��ɫ
	     */
		virtual ArrayList<Long> getSystemColors();
		/**
	     * ����ϵͳ��ɫ
	     */
		virtual void setSystemColors(ArrayList<Long> systemColors);
		/**
	     * ��ȡTAGֵ
	     */
		virtual Object getTag();
		/**
	     * ����TAGֵ
	     */
		virtual void setTag(Object tag);
		/**
	     * ��ȡ��ʱ��������
	     */
		virtual CVarFactory* getVarFactory();
		/**
	     * ������ʱ��������
	     */
		virtual void setVarFactory(CVarFactory *varFactory);
	public:
	    /**
         * ��ӷ���
         * @param function  ����
        */
		void addFunction(CFunction *function);
	    /**
         * ���÷���
         * @param fieldName  ��������
         * @returns ����ֵ
        */
		double callFunction(String funcName);
		/*
		* �������
		*/
		void clear();
		/**
	     * ��ȡ���еķ���
	     */
		ArrayList<CFunction*> getFunctions();
		/**
	     * ��ȡ���е�ͼ��
	     */
		ArrayList<BaseShape*> getShapes();
	    /**
         * ��ȡ�ı�
         * @param   var   ����
         * @returns �ı�
        */
		String getText(CVariable *var);
	    /**
         * ��ȡ��ֵ
         * @param   var   ����
         * @returns  ������
        */
		double getValue(CVariable *var);
	    /**
         * ��ȡ����
         * @param  name  ����
         * @returns ����
        */
		CVariable* getVariable(const String& name);
		/*
		* ��
		*/
		void lock();
	    /**
         * ����ָ��
         * @param  index   ����
         * @returns  �Ƿ����ɹ�
        */
		void onCalculate(int index);
	    /**
         * �Ƴ�����
         * @param function  ����
        */
		void removeFunction(CFunction *function);
	    /**
         * ��������Դ�ֶ�
         * @param key   ��
         * @param value  ֵ
        */
		void setSourceField(const String& key, int value);
	    /**
         * ��������Դֵ
         * @param key   ��
         * @param value  ֵ
        */
		void setSourceValue(int index, const String& key, double value);
	    /**
         * ���ñ�����ֵ
         * @param variable  ����
         * @param parameter  ֵ
         * @returns  ���
        */
		void setVariable(CVariable *variable, CVariable *parameter);
		 /*
         * ����
         */
		void unLock();
	protected:
	    /**
         * �������ֵ
         * @param var   ����
         * @returns  ����ֵ
        */
		double ABS2(CVariable *var);
	    /**
         * ��������Ӧ����ֵ
         * @param var   ����
         * @returns  ����Ӧ����ֵ
        */
		double AMA(CVariable *var);
	    /**
         * ���㷴����ֵ
         * @param var   ����
         * @returns  ������ֵ
        */
		double ACOS(CVariable *var);
	    /**
         * ���㷴����ֵ
         * @param var   ����
         * @returns  ������ֵ
        */
		double ASIN(CVariable *var);
	    /**
         * ���㷴����ֵ
         * @param var   ����
         * @returns  ������ֵ
        */
		double ATAN(CVariable *var);
	    /**
         * ����ƽ������ƫ��
         * @param var   ����
         * @returns  ƽ������ƫ��
        */
		double AVEDEV(CVariable *var);
	    /**
         * ����������Ŀ
         * @param var   ����
         * @returns  ������Ŀ
        */
		int BARSCOUNT(CVariable *var);
	    /**
         * ������һ��������������ǰ��������
         * @param var   ����
         * @returns  ������
        */
		int BARSLAST(CVariable *var);
	    /**
         * �жϱ��ʽ
         * @param var   ����
         * @returns  ���
        */
		int BETWEEN(CVariable *var);
	    /**
         * ����ѭ��
         * @param var   ����
         * @returns  ���
        */
		int BREAK(CVariable *var);
	    /**
         * �������Ͻӽ�������
         * @param var   ����
         * @returns  ���Ͻӽ�������
        */
		double CEILING(CVariable *var);
	    /**
         * ִ�д����
         * @param var   ����
         * @returns  ����ֵ
        */
		double CHUNK(CVariable *var);
	    /**
         * ����ѭ��
         * @param var   ����
         * @returns  ���
        */
		int CONTINUE(CVariable *var);
	    /**
         * ��������ֵ
         * @param var   ����
         * @returns  ����ֵ
        */
		double COS(CVariable *var);
	    /**
         * ͳ������������������
         * @param var   ����
         * @returns  ������
        */
		int COUNT(CVariable *var);
	    /**
         * �ж��Ƿ�Խ
         * @param var   ����
         * @returns  ��Խ:1 ����Խ:0
        */
		int CROSS(CVariable *var);
	    /**
         * ��ȡ��ǰ��������
         * @param var   ����
         * @returns  ��������
        */
		int CURRBARSCOUNT(CVariable *var);
	    /**
         * ȡ�ø����ڴ�1900�����ĵ�������.
         * @param var   ����
         * @returns  ������
        */
		int DATE(CVariable *var);
	    /**
         * ��������
         * @param var   ����
         * @returns  ����
        */
		int DAY(CVariable *var);
	    /**
         * ɾ������
         * @param var   ����
         * @returns  ���
        */
		int DELETE2(CVariable *var);
	    /**
         * ���㶯̬�ƶ�ƽ��
         * @param var   ����
         * @returns  ��̬�ƶ�ƽ��
        */
		double DMA(CVariable *var);
	    /**
         * ѭ��ִ��һ������
         * @param var   ����
         * @returns  ״̬
        */
		int DOTIMES(CVariable *var);
	    /**
         * ִ��DOWHILEѭ��
         * @param var   ����
         * @returns  ״̬
        */
		int DOWHILE(CVariable *var);
	    /**
         * �����Ƿ�����������
         * @param var   ����
         * @returns  �Ƿ�����������
        */
		int DOWNNDAY(CVariable *var);
	    /**
         * ���Ƶ�ͼ
         * @param var   ����
         * @returns  0
        */
		double DRAWICON(CVariable *var);
	    /**
         * ����K��
         * @param var   ����
         * @returns  0
        */
		double DRAWKLINE(CVariable *var);
	    /**
         * ������Ч��
         * @param var   ����
         * @returns  ��Ч��
        */
		double DRAWNULL(CVariable *var);
	    /**
         * ��������
         * @param var   ����
         * @returns  0
        */
		double DRAWTEXT(CVariable *var);
	    /**
         * �ж��Ƿ����
         * @param var   �Ƿ����
         * @returns  0
        */
		int EXIST(CVariable *var);
	    /**
         * ����ָ���ƶ�ƽ��
         * @param var   �Ƿ����
         * @returns  ָ���ƶ�ƽ��
        */
		double EMA(CVariable *var);
	    /**
         * �ж��Ƿ�һֱ����
         * @param var   �Ƿ����
         * @returns  �Ƿ�һֱ����
        */
		int EVERY(CVariable *var);
	    /**
         * ����ָ��ƽ���ƶ�ƽ��
         * @param var   �Ƿ����
         * @returns  ָ��ƽ���ƶ�ƽ��
        */
		double EXPMEMA(CVariable *var);
	    /**
         * ����e��X����
         * @param fieldName  �ֶ�����
         * @returns e��X����
        */
		double EXP(CVariable *var);
	    /**
         * �������½ӽ�������
         * @param var  ����
         * @returns ���½ӽ�������
        */
		double FLOOR(CVariable *var);
	    /**
         * ִ��FORѭ��
         * @param fieldName  �ֶ�����
         * @returns ״̬
        */
		int FOR(CVariable *var);
	    /**
         * ִ�з���
         * @param var  ����
         * @returns ����ֵ
        */
		double FUNCTION(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ��ֵ
        */
		double FUNCVAR(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ����ֵ
         * @param var  ����
         * @returns ��ֵ
        */
		double GET(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ����ֵ
         * @param var  ����
         * @returns ���ֵ
        */
		double HHV(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ����ֵ����������
         * @param var  ����
         * @returns ����
        */
		double HHVBARS(CVariable *var);
	    /**
         * ����Сʱ
         * @param var  ����
         * @returns Сʱ
        */
		int HOUR(CVariable *var);
	    /**
         * ѡ����
         * @param var  ����
         * @returns ���
        */
		double IF(CVariable *var);
	    /**
         * ��ѡ����
         * @param var  ����
         * @returns ��ѡ����
        */
		double IFN(CVariable *var);
	    /**
         * ������X����ֵ��С������ӽ�������
         * @param var  ����
         * @returns ��ӽ�������
        */
		double INTPART(CVariable *var);
	    /**
         * �ж��Ƿ��������
         * @param var  ����
         * @returns �Ƿ��������
        */
		int LAST(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ���Сֵ
         * @param var  ����
         * @returns ��Сֵ
        */
		double LLV(CVariable *var);
	    /**
         * ����ָ���ֶ�һ�������ڵ���Сֵ������������
         * @param var  ����
         * @returns ����
        */
		double LLVBARS(CVariable *var);
	    /**
         * ���㳣�ö���
         * @param var  ����
         * @returns ���ö���
        */
		double LOG(CVariable *var);
	    /**
         * ������ƶ�ƽ��
         * @param var  ����
         * @returns ���ƶ�ƽ��
        */
		double MA(CVariable *var);
	    /**
         * �������ֵ
         * @param var  ����
         * @returns ���ֵ
        */
		double MAX2(CVariable *var);
	    /**
         * ����ָ���ƶ�ƽ��
         * @param var  ����
         * @returns ָ���ƶ�ƽ��
        */
		double MEMA(CVariable *var);
	    /**
         * ������Сֵ
         * @param var  ����
         * @returns ��С�ٻ�ֵ
        */
		double MIN2(CVariable *var);
	    /**
         * ���ط���
         * @param var  ����
         * @returns ����
        */
		int MINUTE(CVariable *var);
	    /**
         * ����ģ
         * @param var  ����
         * @returns ģ
        */
		double MOD(CVariable *var);
	    /**
         * �����·�
         * @param var  ����
         * @returns �·�
        */
		int MONTH(CVariable *var);
	    /**
         * �����Ƿ��������X>Y
         * @param var  ����
         * @returns �Ƿ����
        */
		int NDAY(CVariable *var);
	    /**
         * ��ֵΪ0ʱ����1,���򷵻�0
         * @param var  ����
         * @returns 1��0
        */
		int NOT(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns 0
        */
		double POLYLINE(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ����
        */
		double POW(CVariable *var);
	    /**
         * ��ȡ�����
         * @param var  ����
         * @returns �����
        */
		int RAND(CVariable *var);
	    /**
         * ��ȡǰ��������ֵ
         * @param var  ����
         * @returns ǰ��������ֵ
        */
		double REF(CVariable *var);
	    /**
         * ����ֵ
         * @param var  ����
         * @returns ֵ
        */
		double RETURN(CVariable *var);
	    /**
         * ȡ��
         * @param var  ����
         * @returns ��ֵ
        */
		double REVERSE(CVariable *var);
	    /**
         * ������������
         * @param var  ����
         * @returns ��������ֵ
        */
		double ROUND(CVariable *var);
	    /**
         * ����������ָ��
         * @param var  ����
         * @returns ������ָ��
        */
		double SAR(CVariable *var);
	    /**
         * ���ñ�����ֵ
         * @param var  ����
         * @returns ״̬
        */
		double SET(CVariable *var);
	    /**
         * �������0�򷵻�1,���С��0�򷵻أ�1�����򷵻�0
         * @param var  ����
         * @returns 1,0,-1
        */
		int SIGN(CVariable *var);
	    /**
         * ��������ֵ
         * @param var  ����
         * @returns ����ֵ
        */
		double SIN(CVariable *var);
	    /**
         * �����ƶ�ƽ��
         * @param var  ����
         * @returns �ƶ�ƽ��
        */
		double SMA(CVariable *var);
	    /**
         * ����ƽ����
         * @param var  ����
         * @returns ƽ����
        */
		double SQRT(CVariable *var);
	    /**
         * ����ƽ��
         * @param var  ����
         * @returns ƽ��
        */
		double SQUARE(CVariable *var);
	    /**
         * �����׼��
         * @param var  ����
         * @returns ��׼��
        */
		double STD(CVariable *var);
	    /**
         * �����״ͼ
         * @param var  ����
         * @returns 0
        */
		double STICKLINE(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ��
        */
		double SUM(CVariable *var);
	    /**
         * ��������ֵ
         * @param var  ����
         * @returns ����ֵ
        */
		double TAN(CVariable *var);
	    /**
         * ȡ�ø����ڵ�ʱ��,������������������
         * @param var  ����
         * @returns ʱ��
        */
		int TIME(CVariable *var);
	    /**
         * ȡ�ø����ڵ�ʱ��,������������������
         * @param var  ����
         * @returns ʱ����
        */
		int TIME2(CVariable *var);
	    /**
         * ����ݹ��ƶ�ƽ��
         * @param var  ����
         * @returns �ݹ��ƶ�ƽ��
        */
		double TMA(CVariable *var);
	    /**
         * �����Ƿ�����������
         * @param var  ����
         * @returns �Ƿ�����������
        */
		int UPNDAY(CVariable *var);
	    /**
         * ����������ʱ,ȡ��ǰֵ,����ȡ�ϸ�ֵ
         * @param var  ����
         * @returns ��ֵ
        */
		double VALUEWHEN(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ��ֵ
        */
		double VAR(CVariable *var);
	    /**
         * ִ��WHILEѭ��
         * @param var  ����
         * @returns ״̬
        */
		int WHILE(CVariable *var);
	    /**
         * �����Ȩ�ƶ�ƽ����
         * @param var  ����
         * @returns ��Ȩ�ƶ�ƽ��
        */
		double WMA(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ���
        */
		int YEAR(CVariable *var);
	    /**
         * ����֮�ַ�ת
         * @param var  ����
         * @returns ֮�ַ�ת
        */
		double ZIG(CVariable *var);
	public:
	    /**
         * �����ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_CONTACT(CVariable *var);
	    /**
         * �Ƚ��ַ����Ƿ����
         * @param var  ����
         * @returns λ��
        */
		int STR_EQUALS(CVariable *var);
	    /**
         * �����ַ����г������ֵ�λ��
         * @param var  ����
         * @returns λ��
        */
		int STR_FIND(CVariable *var);
	    /**
         * �����ַ��������������ֵ�λ��
         * @param var  ����
         * @returns λ��
        */
		int STR_FINDLAST(CVariable *var);
	    /**
         * ��ȡ�ַ����ĳ���
         * @param var  ����
         * @returns ����
        */
		int STR_LENGTH(CVariable *var);
	    /**
         * ��ȡ�ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_SUBSTR(CVariable *var);
	    /**
         * �滻�ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_REPLACE(CVariable *var);
	    /**
         * �и��ַ���
         * @param var  ����
         * @returns ���
        */
		int STR_SPLIT(CVariable *var);
	    /**
         * �ַ���ת��ΪСд
         * @param var  ����
         * @returns ���
        */
		int STR_TOLOWER(CVariable *var);
	    /**
         * �ַ���ת��Ϊ��д
         * @param var  ����
         * @returns ���
        */
		int STR_TOUPPER(CVariable *var);
	    /**
         * ������ݵ�����
         * @param var  ����
         * @returns ���
        */
		int LIST_ADD(CVariable *var);
	    /**
         * �������
         * @param var  ����
         * @returns ���
        */
		int LIST_CLEAR(CVariable *var);
	    /**
         * �Ӽ����л�ȡ����
         * @param var  ����
         * @returns ���
        */
		int LIST_GET(CVariable *var);
	    /**
         * �򼯺��в�������
         * @param var  ����
         * @returns ���
        */
		int LIST_INSERT(CVariable *var);
	    /**
         * �Ӽ������Ƴ�����
         * @param var  ����
         * @returns ���
        */
		int LIST_REMOVE(CVariable *var);
	    /**
         * ��ȡ���ϵĴ�С
         * @param var  ����
         * @returns ���
        */
		int LIST_SIZE(CVariable *var);
	    /**
         * �����ϣ��
         * @param var  ����
         * @returns ���
        */
		int MAP_CLEAR(CVariable *var);
	    /**
         * ��ϣ���Ƿ������
         * @param var  ����
         * @returns ���
        */
		int MAP_CONTAINSKEY(CVariable *var);
	    /**
         * ��ȡ��ϣ���ֵ
         * @param var  ����
         * @returns ���
        */
		int MAP_GET(CVariable *var);
	    /**
         * ��ȡ��ϣ��ļ�
         * @param var  ����
         * @returns ���
        */
		int MAP_GETKEYS(CVariable *var);
	    /**
         * �ӹ�ϣ�����Ƴ�
         * @param var  ����
         * @returns ���
        */
		int MAP_REMOVE(CVariable *var);
	    /**
         * ���ϣ�����������
         * @param var  ����
         * @returns ���
        */
		int MAP_SET(CVariable *var);
	    /**
         * ��ȡ��ϣ��ĳߴ�
         * @param var  ����
         * @returns ���
        */
		int MAP_SIZE(CVariable *var);
	public:
		/*
		* Avedev
		*/
		static double avedev(double value, double *listForAvedev, int listForAvedev_length, double avg);
		/*
		* ƽ��ֵ
		*/
        static double avgValue(double *list, int length);
		/*
		* ָ���ƶ�ƽ��ƽ��
		*/
        static double exponentialMovingAverage(int n, double value, double lastEMA);
		/*
		* 쳲�����
		*/
        static int fibonacciValue(int index);
		/*
		* ���Իع�
		*/
        static void linearRegressionEquation(double *list, int length, float *k, float *b);
		/*
		* ���ֵ
		*/
        static double maxValue(double *list, int length);
		/*
		* ��Сֵ
		*/
        static double minValue(double *list, int length);
		/*
		* ƽ��ֵ
		*/
        static double movingAverage(int index, int n, double value, struct LPDATA last_MA);
		/*
		* ��׼��
		*/
        static double standardDeviation(double *list, int length, double avg,  double standardDeviation);
		/*
		* ���ƶ�ƽ��
		*/
        static double simpleMovingAverage(double close, double lastSma, int n, int m);
		/*
		* ���
		*/
        static double sumilationValue(int index, int n, double value, struct LPDATA last_SUM);
		/*
		* ���
		*/
        static double sumValue(double *list, int length);
		/*
		* �����߷�ת
		*/
        static void stopAndReverse(int index, int n, double s, double m, double high, double low, double hhv, double llv, int last_state, double last_sar, double last_af, int* state, double* af, double* sar);
        /*
		* ��Ȩ�ƶ�ƽ��
		*/
		static double weightMovingAverage(int n, int weight, double value, double lastWMA);
		/*
		* ZigZag
		*/
        static void zigZag(int index, double close, double p, double *sxp, int *sxi, double *exp, int *exi, int *state,
                           int *cStart, int *cEnd, double *k, double *b);
	};
}
#endif