/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu);
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

using System;
using System.Collections.Generic;
using System.Drawing;

namespace FaceCat {
    /// <summary>
    /// ����
    /// </summary>
    public class CVariable {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        public CVariable(FCScript indicator) {
            m_indicator = indicator;
        }

        /// <summary>
        /// ��״ͼ
        /// </summary>
        public BarShape m_barShape;

        /// <summary>
        /// K��
        /// </summary>
        public CandleShape m_candleShape;

        /// <summary>
        /// ���ʽ
        /// </summary>
        public String m_expression;

        /// <summary>
        /// �ֶ�
        /// </summary>
        public int m_field = FCDataTable.NULLFIELD;

        /// <summary>
        /// �ֶε�����
        /// </summary>
        public int m_fieldIndex = -1;

        /// <summary>
        /// ��ʾ�ֶ�
        /// </summary>
        public String m_fieldText;

        /// <summary>
        /// ��������
        /// </summary>
        public String m_funcName;

        /// <summary>
        /// �����ı��
        /// </summary>
        public int m_functionID = -1;

        /// <summary>
        /// ����
        /// </summary>
        public int m_line = -1;

        /// <summary>
        /// ָ��
        /// </summary>
        private FCScript m_indicator;

        /// <summary>
        /// ����ͼ
        /// </summary>
        public PolylineShape m_polylineShape;

        /// <summary>
        /// ��ֵ
        /// </summary>
        public String m_name;

        /// <summary>
        /// ����
        /// </summary>
        public CVariable[] m_parameters;

        /// <summary>
        /// �ָ��ı��ʽ
        /// </summary>
        public CMathElement[] m_splitExpression;

        /// <summary>
        /// ��ʱ�ֶ�
        /// </summary>
        public int[] m_tempFields;

        /// <summary>
        /// ����ʱ�ֶε�����
        /// </summary>
        public int[] m_tempFieldsIndex;

        /// <summary>
        /// ����
        /// </summary>
        public TextShape m_textShape;

        /// <summary>
        /// ����
        /// ����� 0:ʹ�ñ�ı����ֶ� 1:ʹ���Լ����ֶ�
        /// ������ 0:���� 1:ֱ�Ӽ��� 2:ֱ��ȡֵ 3:�̶�ֵ 4:��ʱ����
        /// </summary>
        public int m_type = 0;

        /// <summary>
        /// ������ֵ
        /// </summary>
        public double m_value;

        /// <summary>
        /// �����յ��ֶ�
        /// </summary>
        /// <param name="count">����</param>
        public void createTempFields(int count) {
            m_tempFields = new int[count];
            m_tempFieldsIndex = new int[count];
            for (int i = 0; i < count; i++) {
                int field = FCDataTable.AutoField;
                m_tempFields[i] = field;
                m_indicator.DataSource.addColumn(field);
                m_tempFieldsIndex[i] = m_indicator.DataSource.getColumnIndex(field);
            }
        }
    }

    /// <summary>
    /// ������Ԫ
    /// </summary>
    public class CMathElement {
        /// <summary>
        /// ����
        /// 0:�������� 1:������ֵ 2:���� 3:#
        /// </summary>
        public int m_type;

        /// <summary>
        /// ������ֵ
        /// </summary>
        public double m_value;

        /// <summary>
        /// ����
        /// </summary>
        public CVariable m_var;
    }

    /// <summary>
    /// ָ�귽��
    /// </summary>
    public class CFunction {
        /// <summary>
        /// ��������
        /// </summary>
        public CFunction() {
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="id">ID</param>
        /// <param name="name">����</param>
        public CFunction(int id, String name) {
            m_ID = id;
            m_name = name;
        }

        /// <summary>
        /// ����ID
        /// </summary>
        public int m_ID;

        /// <summary>
        /// ��������
        /// </summary>
        public String m_name;

        /// <summary>
        /// ���Ƿ���в���
        /// </summary>
        public int m_type;

        /// <summary>
        /// ���㷽��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        public virtual double onCalculate(CVariable var) {
            return 0;
        }
    }

    /// <summary>
    /// ��ʱ����
    /// </summary>
    public class CVar {
        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="type">����</param>
        public CVar() {

        }

        /// <summary>
        /// ��������
        /// </summary>
        ~CVar() {
            delete();
        }

        /// <summary>
        /// �б�
        /// </summary>
        public ArrayList<String> m_list;

        /// <summary>
        /// ��ϣ��
        /// </summary>
        public HashMap<String, String> m_map;

        /// <summary>
        /// ��ֵ
        /// </summary>
        public double m_num;

        /// <summary>
        /// �ַ���
        /// </summary>
        public String m_str;

        /// <summary>
        /// ����
        /// </summary>
        public int m_type;

        /// <summary>
        /// �ϼ�����
        /// </summary>
        public CVar m_parent;

        /// <summary>
        /// ������Դ
        /// </summary>
        public virtual void delete() {
            if (m_list != null) {
                m_list.clear();
            }
            if (m_map != null) {
                m_map.clear();
            }
            m_parent = null;
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="name">����</param>
        /// <returns>��ֵ</returns>
        public virtual String getText(FCScript indicator, CVariable name) {
            if (m_type == 1) {
                if (m_str.Length > 0 && m_str[0] == '\'') {
                    return m_str.Substring(1, m_str.Length - 2);
                }
                else {
                    return m_str;
                }
            }
            else {
                return FCStr.convertDoubleToStr(m_num);
            }
        }

        /// <summary>
        /// ��ȡֵ
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="name">����</param>
        /// <returns>��ֵ</returns>
        public virtual double getValue(FCScript indicator, CVariable name) {
            if (m_type == 1) {
                return FCStr.convertStrToDouble(m_str.Replace("\'", ""));
            }
            else {
                return m_num;
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="name">����</param>
        /// <param name="value">ֵ</param>
        public virtual double onCreate(FCScript indicator, CVariable name, CVariable value) {
            double result = 0;
            int id = name.m_field;
            if (value.m_expression.Length > 0 && value.m_expression[0] == '\'') {
                m_type = 1;
                m_str = value.m_expression.Substring(1, value.m_expression.Length - 2);
            }
            else {
                if (value.m_expression == "LIST") {
                    m_type = 2;
                    m_list = new ArrayList<string>();
                }
                else if (value.m_expression == "MAP") {
                    m_type = 3;
                    m_map = new HashMap<string, string>();
                }
                else if (indicator.m_tempVars.containsKey(value.m_field)) {
                    CVar otherCVar = indicator.m_tempVars.get(value.m_field);
                    if (otherCVar.m_type == 1) {
                        m_type = 1;
                        m_str = otherCVar.m_str;
                    }
                    else {
                        m_type = 0;
                        m_num = otherCVar.m_num;
                    }
                }
                else {
                    m_type = 0;
                    result = indicator.getValue(value);
                    m_num = result;
                }
            }
            return result;
        }

        /// <summary>
        /// ����ֵ
        /// </summary>
        /// <param name="indicator">ָ��</param>
        /// <param name="name">����</param>
        /// <param name="value">ֵ</param>
        public virtual void setValue(FCScript indicator, CVariable name, CVariable value) {
            if (m_type == 1) {
                m_str = indicator.getText(value);
            }
            else {
                m_num = indicator.getValue(value);
            }
        }
    }

    /// <summary>
    /// ��ʱ��������
    /// </summary>
    public class CVarFactory {
        /// <summary>
        /// ��������
        /// </summary>
        /// <returns>����</returns>
        public virtual CVar createVar() {
            return new CVar();
        }
    }

    /// <summary>
    /// ָ�깫ʽ��չ
    /// </summary>
    public class FCScript {
        /// <summary>
        /// ����ָ��
        /// </summary>
        public FCScript() {
            m_mainVariables = new HashMap<String, int>();
            m_variables = new ArrayList<CVariable>();
            m_defineParams = new HashMap<String, double>();
            m_lines = new ArrayList<CVariable>();
            String[] functions = FUNCTIONS.Split(',');
            String[] fieldFunctions = FUNCTIONS_FIELD.Split(',');
            int iSize = functions.Length;
            int jSize = fieldFunctions.Length;
            for (int i = 0; i < iSize; i++) {
                int cType = 0;
                for (int j = 0; j < jSize; j++) {
                    if (functions[i] == fieldFunctions[j]) {
                        cType = 1;
                        break;
                    }
                }
                CFunction function = new CFunction(i, functions[i]);
                function.m_type = cType;
                m_functions.put(function.m_name, function);
            }
            m_systemColors.add(FCColor.argb(255, 255, 255));
            m_systemColors.add(FCColor.argb(255, 255, 0));
            m_systemColors.add(FCColor.argb(255, 0, 255));
            m_systemColors.add(FCColor.argb(0, 255, 0));
            m_systemColors.add(FCColor.argb(82, 255, 255));
            m_systemColors.add(FCColor.argb(255, 82, 82));
        }

        /// <summary>
        /// ������ʶ
        /// </summary>
        private int m_break;

        /// <summary>
        /// ��������
        /// </summary>
        ~FCScript() {
            delete();
        }

        /// <summary>
        /// �����б�
        /// </summary>
        private HashMap<String, double> m_defineParams;

        /// <summary>
        /// ���з���
        /// </summary>
        private static String FUNCTIONS =
                "CURRBARSCOUNT,BARSCOUNT,DRAWKLINE,STICKLINE,VALUEWHEN,BARSLAST,DOWNNDAY,DRAWICON,DRAWNULL,FUNCTION,FUNCVAR"
                + ",DRAWTEXT,POLYLINE,BETWEEN,CEILING,EXPMEMA,HHVBARS,INTPART,LLVBARS,DOTIMES,DOWHILE,CONTINUE"
                + ",RETURN,REVERSE,AVEDEV,MINUTE,SQUARE,UPNDAY,DELETE"
                + ",COUNT,CROSS,EVERY,EXIST,EXPMA,FLOOR,MONTH,ROUND,TIME2,WHILE,BREAK,CHUNK"
                + ",ACOS,ASIN,ATAN,DATE,HOUR,LAST,MEMA,NDAY,RAND,SIGN,SQRT,TIME,YEAR"
                + ",ABS,AMA,COS,DAY,DMA,EMA,EXP,HHV,IFF,IFN,LLV,LOG,MAX,MIN"
                + ",MOD,NOT,POW,SIN,SMA,STD,SUM,TAN,REF,SAR,FOR,GET,SET"
                + ",TMA,VAR,WMA,ZIG,IF,MA"
                + ",STR.CONTACT,STR.EQUALS,STR.FIND,STR.FINDLAST,STR.LENGTH,STR.SUBSTR,STR.REPLACE,STR.SPLIT,STR.TOLOWER,STR.TOUPPER,LIST.ADD,LIST.CLEAR,LIST.GET,LIST.INSERT,LIST.REMOVE,LIST.SIZE,MAP.CLEAR,MAP.CONTAINSKEY,MAP.GET,MAP.GETKEYS,MAP.REMOVE,MAP.SET,MAP.SIZE";


        /// <summary>
        /// ���ֶη���
        /// </summary>
        private static String FUNCTIONS_FIELD = "EXPMEMA,EXPMA,MEMA,AMA,DMA,EMA,SMA,SUM,SAR,TMA,WMA,MA";

        /// <summary>
        /// ����ͬ��������ID
        /// </summary>
        private static int FUNCTIONID_FUNCVAR = 10;

        /// <summary>
        /// ���巽����ID
        /// </summary>
        private static int FUNCTIONID_FUNCTION = 9;

        /// <summary>
        /// ���������ID
        /// </summary>
        private static int FUNCTIONID_VAR = 82;

        /// <summary>
        /// �����б�
        /// </summary>
        private HashMap<string, CFunction> m_functions = new HashMap<string, CFunction>();

        /// <summary>
        /// �����Ĺ�ϣ��
        /// </summary>
        private HashMap<int, CFunction> m_functionsMap = new HashMap<int, CFunction>();

        /// <summary>
        /// ��伯��
        /// </summary>
        private ArrayList<CVariable> m_lines;

        /// <summary>
        /// ��
        /// </summary>
        private object m_lock = new object();

        /// <summary>
        /// �Ӻ�
        /// </summary>
        private const int OP_ADD = 0;

        /// <summary>
        /// ���
        /// </summary>
        private const int OP_AND = 1;

        /// <summary>
        /// ����
        /// </summary>
        private const int OP_DIVIDE = 2;

        /// <summary>
        /// �Ⱥ�
        /// </summary>
        private const int OP_E = 3;

        /// <summary>
        /// ���ں�
        /// </summary>
        private const int OP_GT = 4;

        /// <summary>
        /// ���ڵ���
        /// </summary>
        private const int OP_GTE = 5;

        /// <summary>
        /// ������
        /// </summary>
        private const int OP_LB = 6;

        /// <summary>
        /// С�ں�
        /// </summary>
        private const int OP_LT = 7;

        /// <summary>
        /// С�ڵ���
        /// </summary>
        private const int OP_LTE = 8;

        /// <summary>
        /// �˺�
        /// </summary>
        private const int OP_MULTIPLY = 9;

        /// <summary>
        /// ������
        /// </summary>
        private const int OP_NE = 10;

        /// <summary>
        /// ��Ч
        /// </summary>
        private const int OP_NULL = -1;

        /// <summary>
        /// ���
        /// </summary>
        private const int OP_OR = 11;

        /// <summary>
        /// ������
        /// </summary>
        private const int OP_RB = 12;

        /// <summary>
        /// ����
        /// </summary>
        private const int OP_SUB = 13;

        /// <summary>
        /// ȡģ
        /// </summary>
        private const int OP_MOD = 14;

        /// <summary>
        /// �����
        /// </summary>
        private Random m_random = new Random();

        /// <summary>
        /// ���
        /// </summary>
        private double m_result;

        /// <summary>
        /// ���Ͻ��
        /// </summary>
        private CVar m_resultVar;

        /// <summary>
        /// ����������
        /// </summary>
        private HashMap<String, CVariable> m_tempFunctions = new HashMap<String, CVariable>();

        /// <summary>
        /// ������
        /// </summary>
        private HashMap<String, CVariable> m_tempVariables = new HashMap<String, CVariable>();

        /// <summary>
        /// ��ʱ����
        /// </summary>
        public HashMap<int, CVar> m_tempVars = new HashMap<int, CVar>();

        /// <summary>
        /// ������ʶ�ַ���
        /// </summary>
        private const String VARIABLE = "~";

        /// <summary>
        /// ��ʶ�ַ���2
        /// </summary>
        private const String VARIABLE2 = "��";

        /// <summary>
        /// ��ʶ�ַ���3
        /// </summary>
        private const String VARIABLE3 = "?";

        /// <summary>
        /// ��������
        /// </summary>
        private ArrayList<CVariable> m_variables;

        private AttachVScale m_attachVScale = AttachVScale.Left;

        /// <summary>
        /// ��ȡ�����������������
        /// </summary>
        public virtual AttachVScale AttachVScale {
            get { return m_attachVScale; }
            set {
                m_attachVScale = value;
                foreach (CVariable var in m_variables) {
                    if (var.m_polylineShape != null) {
                        var.m_barShape.AttachVScale = value;
                        var.m_candleShape.AttachVScale = value;
                        var.m_polylineShape.AttachVScale = value;
                        var.m_textShape.AttachVScale = value;
                    }
                }
            }
        }

        private FCDataTable m_dataSource;

        /// <summary>
        /// ��ȡ����������Դ
        /// </summary>
        public virtual FCDataTable DataSource {
            get { return m_dataSource; }
            set { m_dataSource = value; }
        }

        private ChartDiv m_div;

        /// <summary>
        /// ��ȡ������ͼ��
        /// </summary>
        public virtual ChartDiv Div {
            get { return m_div; }
            set {
                m_div = value;
                m_dataSource = m_div.Chart.DataSource;
            }
        }

        private bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        /// <summary>
        /// ��ǰ����������
        /// </summary>
        private int m_index = -1;

        /// <summary>
        /// ��ȡ��ǰ���ڼ��������
        /// </summary>
        public virtual int Index {
            get { return m_index; }
        }

        private HashMap<String, int> m_mainVariables;

        /// <summary>
        /// ��ȡ��������Ҫ����
        /// </summary>
        public virtual HashMap<String, int> MainVariables {
            get { return m_mainVariables; }
        }

        private String m_name;

        /// <summary>
        /// ��ȡ����������
        /// </virtual>
        public virtual String Name {
            get { return m_name; }
            set { m_name = value; }
        }

        /// <summary>
        /// ��ȡ�����ýű�
        /// </summary>
        public virtual String Script {
            set {
                lock (m_lock) {
                    //�������
                    m_lines.clear();
                    m_defineParams.clear();
                    ArrayList<String> lines = new ArrayList<String>();
                    getMiddleScript(value, lines);
                    int linesCount = lines.size();
                    for (int i = 0; i < linesCount; i++) {
                        String strLine = lines[i];
                        if (strLine.IndexOf("FUNCTION ") == 0) {
                            String funcName = strLine.Substring(9, strLine.IndexOf('(') - 9).ToUpper();
                            addFunction(new CFunction(FUNCTIONID_FUNCTION, funcName));
                        }
                        else if (strLine.IndexOf("CONST ") == 0) {
                            String[] consts = strLine.Substring(6).Split(new String[] { ":" }, StringSplitOptions.RemoveEmptyEntries);
                            m_defineParams.put(consts[0], FCStr.convertStrToDouble(consts[1]));
                            lines.removeAt(i);
                            i--;
                            linesCount--;
                        }
                    }
                    linesCount = lines.size();
                    for (int i = 0; i < linesCount; i++) {
                        analysisScriptLine(lines[i]);
                    }
                    lines.clear();
                }
            }
        }

        private ArrayList<long> m_systemColors = new ArrayList<long>();

        /// <summary>
        /// ��ȡ������ϵͳ��ɫ
        /// </summary>
        public virtual ArrayList<long> SystemColors {
            get { return m_systemColors; }
            set { m_systemColors = value; }
        }

        protected object m_tag = null;

        /// <summary>
        /// ��ȡ������TAGֵ
        /// </summary>
        public virtual object Tag {
            get { return m_tag; }
            set { m_tag = value; }
        }

        protected CVarFactory m_varFactory = new CVarFactory();

        /// <summary>
        /// ��ȡ��������ʱ��������
        /// </summary>
        public virtual CVarFactory VarFactory {
            get { return m_varFactory; }
            set { m_varFactory = value; }
        }

        /// <summary>
        /// ��ӷ���
        /// </summary>
        /// <param name="function">����</param>
        public virtual void addFunction(CFunction function) {
            m_functions.put(function.m_name, function);
            m_functionsMap.put(function.m_ID, function);
        }

        /// <summary>
        /// ��������а����ķ����ͱ���
        /// </summary>
        private void analysisVariables(ref String sentence, int line, String funcName, String fieldText, bool isFunction) {
            ArrayList<string> wordsList = new ArrayList<string>();
            string[] splitWords = splitExpression2(sentence);
            int splitWordsSize = splitWords.Length;
            for (int s = 0; s < splitWordsSize; s++) {
                string wStr = splitWords[s];
                string[] subWStr = wStr.Split(new string[] { VARIABLE2, ":" }, StringSplitOptions.RemoveEmptyEntries);
                int subWStrSize = subWStr.Length;
                for (int u = 0; u < subWStrSize; u++) {
                    if (m_functions.containsKey(subWStr[u])) {
                        wordsList.add(subWStr[u]);
                    }
                }
            }
            int wordsListSize = wordsList.size();
            for (int f = 0; f < wordsListSize; f++) {
                string word = wordsList[f];
                CFunction func = m_functions.get(word);
                //ϵͳָ����
                String fName = func.m_name;
                int funcID = func.m_ID;
                int funcType = func.m_type;
                String function = fName + "(";
                //��һ�����ŵ�����
                int bIndex = sentence.IndexOf(function);
                while (bIndex != -1) {
                    //����������
                    int rightBracket = 0;
                    //�ַ�����
                    int idx = 0;
                    //����
                    int count = 0;
                    //ƥ��Գ�����
                    foreach (char ch in sentence) {
                        if (idx >= bIndex) {
                            if (ch == '(') {
                                count++;
                            }
                            else if (ch == ')') {
                                count--;
                                if (count == 0) {
                                    rightBracket = idx;
                                    break;
                                }
                            }
                        }
                        idx++;
                    }
                    if (rightBracket == 0) {
                        break;
                    }
                    //������
                    String body = sentence.Substring(bIndex, rightBracket - bIndex + 1);
                    //��������
                    CVariable var = new CVariable(this);
                    body = body.Substring(0, body.IndexOf('('));
                    var.m_name = VARIABLE + m_variables.size().ToString();
                    var.m_expression = body;
                    var.m_type = 0;
                    var.m_functionID = funcID;
                    var.m_fieldText = body;
                    //�����ֶ�
                    if (funcType == 1) {
                        int field = FCDataTable.AutoField;
                        var.m_field = field;
                        m_dataSource.addColumn(field);
                    }
                    m_variables.add(var);
                    if (bIndex == 0) {
                        if (isFunction) {
                            var.m_funcName = funcName;
                            var.m_line = line;
                            var.m_fieldText = fieldText;
                            m_lines.add(var);
                            m_tempFunctions.put(funcName, var);
                            isFunction = false;
                        }
                    }
                    var.m_splitExpression = splitExpression(var.m_expression);
                    //��ȡ�����
                    int startIndex = bIndex + function.Length;
                    String subSentence = sentence.Substring(startIndex, rightBracket - startIndex);
                    if (funcID == FUNCTIONID_FUNCTION) {
                        if (m_tempFunctions.containsKey(fName)) {
                            if (m_tempFunctions.get(fName).m_fieldText != null) {
                                String[] fieldTexts = m_tempFunctions.get(fName).m_fieldText.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                                String[] transferParams = subSentence.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                                subSentence = "";
                                int transferParamsLen = transferParams.Length;
                                for (int i = 0; i < transferParamsLen; i++) {
                                    if (i == 0) {
                                        subSentence = "FUNCVAR(";
                                    }
                                    subSentence += fieldTexts[i] + VARIABLE2 + transferParams[i];
                                    if (i != transferParamsLen - 1) {
                                        subSentence += VARIABLE2;
                                    }
                                    else {
                                        subSentence += ")";
                                    }
                                }
                            }
                        }
                    }
                    //�ݹ����
                    analysisVariables(ref subSentence, 0, "", "", false);
                    String[] parameters = subSentence.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                    //���������
                    if (parameters != null && parameters.Length > 0) {
                        var.m_parameters = new CVariable[parameters.Length];
                        for (int j = 0; j < parameters.Length; j++) {
                            String parameter = parameters[j];
                            //�滻����
                            parameter = replace(parameter);
                            CVariable pVar = new CVariable(this);
                            pVar.m_expression = parameter;
                            pVar.m_name = VARIABLE + m_variables.size().ToString();
                            pVar.m_type = 1;
                            var.m_parameters[j] = pVar;
                            //�������ͺ��ֶ�
                            foreach (CVariable variable in m_variables) {
                                //�滻�ֶ�
                                if (variable.m_type == 2 && variable.m_expression == parameters[j] && variable.m_field != FCDataTable.NULLFIELD) {
                                    pVar.m_type = 2;
                                    pVar.m_field = variable.m_field;
                                    pVar.m_fieldText = parameters[j];
                                    break;
                                }
                            }
                            if (pVar.m_type == 1) {
                                string varKey = parameter;
                                if (varKey.IndexOf("[REF]") == 0) {
                                    varKey = varKey.Substring(5);
                                }
                                if (m_tempVariables.containsKey(varKey)) {
                                    pVar.m_field = m_tempVariables.get(varKey).m_field;
                                }
                                else {
                                    pVar.m_field = -(m_variables.size() + 1);
                                    m_tempVariables.put(varKey, pVar);
                                }
                            }
                            m_variables.add(pVar);
                            pVar.m_splitExpression = splitExpression(parameter);
                            if (pVar.m_splitExpression != null && pVar.m_splitExpression.Length == 2) {
                                if (pVar.m_splitExpression[0].m_var == pVar) {
                                    pVar.m_splitExpression = null;
                                }
                            }
                        }
                    }
                    //�滻�ַ���
                    sentence = sentence.Substring(0, bIndex) + var.m_name + sentence.Substring(rightBracket + 1);
                    bIndex = sentence.IndexOf(function, sentence.IndexOf(var.m_name));
                }
            }
            wordsList.clear();
        }

        /// <summary>
        /// ���ؽű���
        /// </summary>
        /// <param name="line">�ű���</param>
        private void analysisScriptLine(String line) {
            CVariable script = new CVariable(this);
            bool isFunction = false;
            String strLine = line;
            String funcName = null;
            String fieldText = null;
            if (line.IndexOf("FUNCTION ") == 0) {
                int cindex = strLine.IndexOf('(');
                funcName = strLine.Substring(9, cindex - 9);
                int rindex = strLine.IndexOf(')');
                if (rindex - cindex > 1) {
                    fieldText = strLine.Substring(cindex + 1, rindex - cindex - 1);
                    String[] pList = fieldText.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                    int pListSize = pList.Length;
                    for (int i = 0; i < pListSize; i++) {
                        string str = pList[i];
                        if (str.IndexOf("[REF]") != -1) {
                            str = str.Substring(5);
                        }
                        String pCmd = "VAR(" + str + VARIABLE2 + "0)";
                        analysisVariables(ref pCmd, 0, "", "", false);
                    }
                }
                strLine = strLine.Substring(rindex + 1);
                strLine = "CHUNK" + strLine.Substring(0, strLine.Length - 1) + ")";
                isFunction = true;
            }
            analysisVariables(ref strLine, m_lines.size(), funcName, fieldText, isFunction);
            script.m_line = m_lines.size();
            if (isFunction) {
                return;
            }
            //�������
            String variable = null;
            String sentence = null;
            String followParameters = "";
            String op = "";
            foreach (char ch in strLine) {
                if (ch != ':' && ch != '=') {
                    if (op.Length > 0) {
                        break;
                    }
                }
                else {
                    op += ch.ToString();
                }
            }
            //�����߱���
            if (op == ":=") {
                variable = strLine.Substring(0, strLine.IndexOf(":="));
                sentence = strLine.Substring(strLine.IndexOf(":=") + 2);
            }
            //���߱���
            else if (op == ":") {
                variable = strLine.Substring(0, strLine.IndexOf(":"));
                sentence = strLine.Substring(strLine.IndexOf(":") + 1);
                followParameters = "COLORAUTO";
                //�������
                if (sentence.IndexOf(VARIABLE2) != -1) {
                    followParameters = sentence.Substring(sentence.IndexOf(VARIABLE2) + 1);
                    sentence = sentence.Substring(0, sentence.IndexOf(VARIABLE2));
                }
            }
            //��ͼ����
            else {
                sentence = strLine;
                String[] strs = sentence.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                if (strs != null && strs.Length > 1) {
                    String strVar = strs[0];
                    sentence = strVar;
                    int idx = FCStr.convertStrToInt(strVar.Substring(1));
                    if (idx < m_variables.size()) {
                        CVariable var = m_variables[idx];
                        //�޸Ĳ���
                        int startIndex = 0;
                        if (var.m_parameters == null) {
                            var.m_parameters = new CVariable[strs.Length - 1];
                            startIndex = 0;
                        }
                        else {
                            CVariable[] newParameters = new CVariable[var.m_parameters.Length + strs.Length - 1];
                            for (int i = 0; i < var.m_parameters.Length; i++) {
                                newParameters[i] = var.m_parameters[i];
                            }
                            startIndex = var.m_parameters.Length;
                            var.m_parameters = newParameters;
                        }
                        for (int i = 1; i < strs.Length; i++) {
                            CVariable newVar = new CVariable(this);
                            newVar.m_type = 1;
                            newVar.m_expression = strs[i];
                            var.m_parameters[startIndex + i - 1] = newVar;

                        }
                    }
                }
            }
            script.m_expression = replace(sentence);
            m_variables.add(script);
            m_lines.add(script);
            //��������䴦��
            if (variable != null) {
                script.m_type = 1;
                //��������
                CVariable pfunc = new CVariable(this);
                pfunc.m_type = 2;
                pfunc.m_name = VARIABLE + m_variables.size().ToString();
                //�ж�����Ƿ񴿱���
                int field = FCDataTable.NULLFIELD;
                if (sentence.IndexOf(VARIABLE) == 0) {
                    int num = 0;
                    bool isNum = int.TryParse(sentence.Replace(VARIABLE, ""), out num);
                    if (isNum) {
                        foreach (CVariable var in m_variables) {
                            if (var.m_name == sentence && var.m_field != FCDataTable.NULLFIELD) {
                                field = var.m_field;
                                break;
                            }
                        }
                    }
                }
                if (field == FCDataTable.NULLFIELD) {
                    field = FCDataTable.AutoField;
                    m_dataSource.addColumn(field);
                }
                else {
                    script.m_type = 0;
                }
                pfunc.m_field = field;
                pfunc.m_expression = variable;
                pfunc.m_splitExpression = splitExpression(variable);
                m_variables.add(pfunc);
                m_mainVariables.put(variable, field);
                script.m_field = field;
            }
            //׷�ӻ������
            if (followParameters != null && followParameters.Length > 0) {
                String newLine = null;
                if (followParameters.IndexOf("COLORSTICK") != -1) {
                    newLine = "STICKLINE(1" + VARIABLE2 + variable + VARIABLE2 + "0" + VARIABLE2 + "1" + VARIABLE2 + "2" + VARIABLE2 + "DRAWTITLE)";
                }
                else if (followParameters.IndexOf("CIRCLEDOT") != -1) {
                    newLine = "DRAWICON(1" + VARIABLE2 + variable + VARIABLE2 + "CIRCLEDOT" + VARIABLE2 + "DRAWTITLE)";
                }
                else if (followParameters.IndexOf("POINTDOT") != -1) {
                    newLine = "DRAWICON(1" + VARIABLE2 + variable + VARIABLE2 + "POINTDOT" + VARIABLE2 + "DRAWTITLE)";
                }
                else {
                    newLine = "POLYLINE(1" + VARIABLE2 + variable + VARIABLE2 + followParameters + VARIABLE2 + "DRAWTITLE)";
                }
                analysisScriptLine(newLine);
            }
            script.m_splitExpression = splitExpression(script.m_expression);
        }

        /// <summary>
        /// �Ա��ʽ������ֵ����ֵ֮ǰ���Ƚ����﷨У��
        /// </summary>
        /// <param name="expr">Ҫ��ֵ�ı��ʽ</param>
        /// <returns>��ֵ���</returns>
        private double calculate(CMathElement[] expr) {
            int exprLength = expr.Length; //��
            CMathElement[] optr = new CMathElement[exprLength];
            int optrLength = 1;
            CMathElement exp = new CMathElement();
            exp.m_type = 3;
            optr[0] = exp;
            CMathElement[] opnd = new CMathElement[exprLength];
            //ɾ
            int opndLength = 0;
            int idx = 0;
            CMathElement right = null;
            while (idx < exprLength && (expr[idx].m_type != 3 || optr[optrLength - 1].m_type != 3)) {
                CMathElement Q2 = expr[idx];
                if (Q2.m_type != 0 && Q2.m_type != 3) {
                    opnd[opndLength] = Q2;
                    opndLength++;
                    idx++;
                }
                else {
                    CMathElement Q1 = optr[optrLength - 1];
                    int precede = OP_NULL;
                    if (Q2.m_type == 3) {
                        if (Q1.m_type == 3) {
                            precede = OP_E;
                        }
                        else {
                            precede = OP_GT;
                        }
                    }
                    else {
                        int q1Value = (int)Q1.m_value;
                        int q2Value = (int)Q2.m_value;
                        switch (q2Value) {
                            case OP_E:
                            case OP_ADD:
                            case OP_SUB:
                            case OP_GT:
                            case OP_LT:
                            case OP_AND:
                            case OP_OR:
                            case OP_GTE:
                            case OP_LTE:
                            case OP_NE:
                            case OP_MOD:
                                if (Q1.m_type == 3 || (Q1.m_type == 0 && q1Value == OP_LB)) {
                                    precede = OP_LT;
                                }
                                else {
                                    precede = OP_GT;
                                }
                                break;
                            case OP_MULTIPLY:
                            case OP_DIVIDE:
                                if (Q1.m_type == 0 && (q1Value == OP_MULTIPLY || q1Value == OP_DIVIDE || q1Value == OP_RB)) {
                                    precede = OP_GT;
                                }
                                else {
                                    precede = OP_LT;
                                }
                                break;
                            case OP_LB:
                                precede = OP_LT;
                                break;
                            case OP_RB:
                                if (Q1.m_type == 0 && q1Value == OP_LB) {
                                    precede = OP_E;
                                }
                                else {
                                    precede = OP_GT;
                                }
                                break;
                        }
                    }
                    switch (precede) {
                        case OP_LT:         //ջ��Ԫ������Ȩ��
                            optr[optrLength] = Q2;
                            optrLength++;
                            idx++;
                            break;
                        case OP_E:       //�����Ų�������һ���ַ�
                            optrLength--;
                            idx++;
                            break;
                        case OP_GT:    //��ջ������������ջ
                            if (opndLength == 0) return 0;
                            int op = (int)Q1.m_value;
                            optrLength--;
                            double opnd1 = 0, opnd2 = 0;
                            CMathElement left = opnd[opndLength - 1];
                            if (left.m_type == 2) {
                                opnd2 = getValue(left.m_var);
                            }
                            else {
                                opnd2 = left.m_value;
                            }
                            if (opndLength > 1) {
                                right = opnd[opndLength - 2];
                                if (right.m_type == 2) {
                                    opnd1 = getValue(right.m_var);
                                }
                                else {
                                    opnd1 = right.m_value;
                                }
                                opndLength -= 2;
                            }
                            else {
                                opndLength--;
                            }
                            //��ȡ�������ߵ�ֵ
                            double result = 0;
                            switch (op) {
                                case OP_ADD: result = opnd1 + opnd2; break;
                                case OP_SUB: result = opnd1 - opnd2; break;
                                case OP_MULTIPLY: result = opnd1 * opnd2; break;
                                case OP_DIVIDE: {
                                        if (opnd2 == 0) {
                                            result = 0;
                                        }
                                        else {
                                            result = opnd1 / opnd2;
                                        }
                                        break;
                                    }
                                case OP_MOD: {
                                        if (opnd2 == 0) {
                                            result = 0;
                                        }
                                        else {
                                            result = opnd1 % opnd2;
                                        }
                                        break;
                                    }
                                case OP_GTE: result = (opnd1 >= opnd2 ? 1 : 0); break;
                                case OP_LTE: result = (opnd1 <= opnd2 ? 1 : 0); break;
                                case OP_NE: {
                                        if ((left.m_var != null && left.m_var.m_functionID == -2) || (right != null && right.m_var != null && right.m_var.m_functionID == -2)) {
                                            if (right != null && left.m_var != null && right.m_var != null) {
                                                if (getText(left.m_var) != getText(right.m_var)) {
                                                    result = 1;
                                                }
                                            }
                                        }
                                        else {
                                            result = (opnd1 != opnd2 ? 1 : 0);
                                        }
                                        break;
                                    }
                                case OP_E: {
                                        if ((left.m_var != null && left.m_var.m_functionID == -2) || (right != null && right.m_var != null && right.m_var.m_functionID == -2)) {
                                            if (right != null && left.m_var != null && right.m_var != null) {
                                                if (getText(left.m_var) != getText(right.m_var)) {
                                                    result = 1;
                                                }
                                            }
                                        }
                                        else {
                                            result = (opnd1 == opnd2 ? 1 : 0);
                                        }
                                        break;
                                    }
                                case OP_GT: result = (opnd1 > opnd2 ? 1 : 0); break;
                                case OP_LT: result = (opnd1 < opnd2 ? 1 : 0); break;
                                case OP_AND:
                                    if (opnd1 == 1 && opnd2 == 1) result = 1;
                                    else result = 0;
                                    break;
                                case OP_OR:
                                    if (opnd1 == 1 || opnd2 == 1) result = 1;
                                    else result = 0;
                                    break;
                                default: result = 0; break;
                            }
                            if (m_break > 0) {
                                return result;
                            }
                            else {
                                CMathElement expression = new CMathElement();
                                expression.m_type = 1;
                                expression.m_value = result;
                                opnd[opndLength] = expression;
                                opndLength++;
                            }
                            break;
                    }
                }
            }
            //��ȡ���
            if (opndLength > 0) {
                CMathElement rlast = opnd[opndLength - 1];
                if (rlast.m_type == 2) {
                    return getValue(rlast.m_var);
                }
                else {
                    return rlast.m_value;
                }
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ���÷���
        /// </summary>
        /// <param name="funcName">��������</param>
        /// <returns>����ֵ</returns>
        public virtual double callFunction(String funcName) {
            double result = 0;
            lock (m_lock) {
                ArrayList<String> lines = new ArrayList<String>();
                getMiddleScript(funcName, lines);
                int linesSize = lines.size();
                m_result = 0;
                for (int i = 0; i < linesSize; i++) {
                    String str = lines[i];
                    int cindex = str.IndexOf('(');
                    String upperName = str.Substring(0, cindex).ToUpper();
                    if (m_tempFunctions.containsKey(upperName)) {
                        CVariable function = m_tempFunctions.get(upperName);
                        int rindex = str.LastIndexOf(')');
                        CVariable topVar = new CVariable(this);
                        if (rindex - cindex > 1) {
                            String pStr = str.Substring(cindex + 1, rindex - cindex - 1);
                            String[] pList = pStr.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                            String[] fieldTexts = function.m_fieldText.Split(new String[] { VARIABLE2 }, StringSplitOptions.RemoveEmptyEntries);
                            int pListLen = pList.Length;
                            topVar.m_parameters = new CVariable[pListLen * 2];
                            for (int j = 0; j < pListLen; j++) {
                                String pName = fieldTexts[j];
                                String pValue = pList[j];
                                CVariable varName = null;
                                if (m_tempVariables.containsKey(pName)) {
                                    varName = m_tempVariables.get(pName);
                                }
                                CVariable varValue = new CVariable(this);
                                varValue.m_expression = pValue;
                                if (pValue[0] == '\'') {
                                    varValue.m_type = 1;
                                }
                                else {
                                    varValue.m_type = 3;
                                    varValue.m_value = FCStr.convertStrToDouble(pValue);
                                }
                                topVar.m_parameters[j * 2] = varName;
                                topVar.m_parameters[j * 2 + 1] = varValue;
                            }
                            FUNCVAR(topVar);
                        }
                        getValue(m_tempFunctions.get(upperName));
                        if (topVar.m_parameters != null) {
                            int variablesSize = topVar.m_parameters.Length;
                            for (int j = 0; j < variablesSize; j++) {
                                if (j % 2 == 0) {
                                    int id = topVar.m_parameters[j].m_field;
                                    if (m_tempVars.containsKey(id)) {
                                        CVar cVar = m_tempVars.get(id);
                                        if (cVar.m_parent != null) {
                                            m_tempVars.put(id, cVar.m_parent);
                                        }
                                        else {
                                            m_tempVars.remove(id);
                                        }
                                        cVar.delete();
                                    }
                                }
                            }
                        }
                    }
                }
                lines.clear();
                result = m_result;
                m_result = 0;
                m_break = 0;
            }
            return result;
        }

        /// <summary>
        /// ���÷���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private double callFunction(CVariable var) {
            switch (var.m_functionID) {
                case 0: return CURRBARSCOUNT(var);
                case 1: return BARSCOUNT(var);
                case 2: return DRAWKLINE(var);
                case 3: return STICKLINE(var);
                case 4: return VALUEWHEN(var);
                case 5: return BARSLAST(var);
                case 6: return DOWNNDAY(var);
                case 7: return DRAWICON(var);
                case 8: return DRAWNULL(var);
                case 9: return FUNCTION(var);
                case 10: return FUNCVAR(var);
                case 11: return DRAWTEXT(var);
                case 12: return POLYLINE(var);
                case 13: return BETWEEN(var);
                case 14: return CEILING(var);
                case 15: return EXPMEMA(var);
                case 16: return HHVBARS(var);
                case 17: return INTPART(var);
                case 18: return LLVBARS(var);
                case 19: return DOTIMES(var);
                case 20: return DOWHILE(var);
                case 21: return CONTINUE(var);
                case 22: return RETURN(var);
                case 23: return REVERSE(var);
                case 24: return AVEDEV(var);
                case 25: return MINUTE(var);
                case 26: return SQUARE(var);
                case 27: return UPNDAY(var);
                case 28: return DELETE(var);
                case 29: return COUNT(var);
                case 30: return CROSS(var);
                case 31: return EVERY(var);
                case 32: return EXIST(var);
                case 33: return EMA(var);
                case 34: return FLOOR(var);
                case 35: return MONTH(var);
                case 36: return ROUND(var);
                case 37: return TIME2(var);
                case 38: return WHILE(var);
                case 39: return BREAK(var);
                case 40: return CHUNK(var);
                case 41: return ACOS(var);
                case 42: return ASIN(var);
                case 43: return ATAN(var);
                case 44: return DATE(var);
                case 45: return HOUR(var);
                case 46: return LAST(var);
                case 47: return MEMA(var);
                case 48: return NDAY(var);
                case 49: return RAND(var);
                case 50: return SIGN(var);
                case 51: return SQRT(var);
                case 52: return TIME(var);
                case 53: return YEAR(var);
                case 54: return ABS(var);
                case 55: return AMA(var);
                case 56: return COS(var);
                case 57: return DAY(var);
                case 58: return DMA(var);
                case 59: return EMA(var);
                case 60: return EXP(var);
                case 61: return HHV(var);
                case 62: return IF(var);
                case 63: return IFN(var);
                case 64: return LLV(var);
                case 65: return LOG(var);
                case 66: return MAX(var);
                case 67: return MIN(var);
                case 68: return MOD(var);
                case 69: return NOT(var);
                case 70: return POW(var);
                case 71: return SIN(var);
                case 72: return SMA(var);
                case 73: return STD(var);
                case 74: return SUM(var);
                case 75: return TAN(var);
                case 76: return REF(var);
                case 77: return SAR(var);
                case 78: return FOR(var);
                case 79: return GET(var);
                case 80: return SET(var);
                case 81: return TMA(var);
                case 82: return VAR(var);
                case 83: return WMA(var);
                case 84: return ZIG(var);
                case 85: return IF(var);
                case 86: return MA(var);
                case 87: return STR_CONTACT(var);
                case 88: return STR_EQUALS(var);
                case 89: return STR_FIND(var);
                case 90: return STR_FINDLAST(var);
                case 91: return STR_LENGTH(var);
                case 92: return STR_SUBSTR(var);
                case 93: return STR_REPLACE(var);
                case 94: return STR_SPLIT(var);
                case 95: return STR_TOLOWER(var);
                case 96: return STR_TOUPPER(var);
                case 97: return LIST_ADD(var);
                case 98: return LIST_CLEAR(var);
                case 99: return LIST_GET(var);
                case 100: return LIST_INSERT(var);
                case 101: return LIST_REMOVE(var);
                case 102: return LIST_SIZE(var);
                case 103: return MAP_CLEAR(var);
                case 104: return MAP_CONTAINSKEY(var);
                case 105: return MAP_GET(var);
                case 106: return MAP_GETKEYS(var);
                case 107: return MAP_REMOVE(var);
                case 108: return MAP_SET(var);
                case 109: return MAP_SIZE(var);
                default:
                    if (m_functionsMap.containsKey(var.m_functionID)) {
                        return m_functionsMap.get(var.m_functionID).onCalculate(var);
                    }
                    return 0;
            }
        }

        /// <summary>
        /// ���Ԫ��
        /// </summary>
        public virtual void clear() {
            lock (m_lock) {
                //���ͼ��
                if (m_div != null) {
                    ArrayList<BaseShape> shapes = getShapes();
                    foreach (BaseShape shape in shapes) {
                        m_div.removeShape(shape);
                        m_div.TitleBar.Titles.clear();
                        shape.delete();
                    }
                    if (shapes != null) {
                        shapes.clear();
                    }
                }
                //�������
                foreach (CVariable var in m_variables) {
                    if (var.m_field >= 10000) {
                        m_dataSource.removeColumn(var.m_field);
                    }
                    if (var.m_tempFields != null) {
                        for (int i = 0; i < var.m_tempFields.Length; i++) {
                            if (var.m_tempFields[i] >= 10000) {
                                m_dataSource.removeColumn(var.m_tempFields[i]);
                            }
                        }
                    }
                }
                m_lines.clear();
                m_variables.clear();
                m_mainVariables.clear();
                m_defineParams.clear();
                m_tempFunctions.clear();
                deleteTempVars();
                m_tempVariables.clear();
            }
        }

        /// <summary>
        /// ������ʱ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�µı���</returns>
        public CVar copyTempVar(CVar var) {
            CVar newVar = new CVar();
            newVar.m_type = var.m_type;
            newVar.m_str = var.m_str;
            newVar.m_num = var.m_num;
            return newVar;
        }

        /// <summary>
        /// ����ָ��
        /// </summary>
        /// <returns>ָ��</returns>
        public static FCScript createIndicator() {
            FCScript indicator = new FCScript();
            return indicator;
        }

        /// <summary>
        /// ɾ����ʱ����
        /// </summary>
        /// <param name="var">����</param>
        private void deleteTempVars() {
            while (m_tempVars.size() > 0) {
                ArrayList<int> removeIDs = new ArrayList<int>();
                foreach (int key in m_tempVars.Keys) {
                    removeIDs.add(key);
                }
                int removeIDsSize = removeIDs.size();
                for (int i = 0; i < removeIDsSize; i++) {
                    int removeID = removeIDs[i];
                    if (m_tempVars.containsKey(removeID)) {
                        CVar cVar = m_tempVars.get(removeID);
                        if (cVar.m_parent != null) {
                            m_tempVars.put(removeID, cVar.m_parent);
                        }
                        else {
                            m_tempVars.remove(removeID);
                        }
                        cVar.delete();
                    }
                }
                removeIDs.clear();
            }
        }

        /// <summary>
        /// ɾ����ʱ����
        /// </summary>
        /// <param name="var">����</param>
        private void deleteTempVars(CVariable var) {
            if (var.m_parameters != null) {
                int pLen = var.m_parameters.Length;
                if (pLen > 0) {
                    for (int i = 0; i < pLen; i++) {
                        CVariable parameter = var.m_parameters[i];
                        if (parameter.m_splitExpression != null && parameter.m_splitExpression.Length > 0) {
                            CVariable subVar = parameter.m_splitExpression[0].m_var;
                            if (subVar != null && (subVar.m_functionID == FUNCTIONID_FUNCVAR || subVar.m_functionID == FUNCTIONID_VAR)) {
                                int sunLen = subVar.m_parameters.Length;
                                for (int j = 0; j < sunLen; j++) {
                                    if (j % 2 == 0) {
                                        CVariable sunVar = subVar.m_parameters[j];
                                        int id = sunVar.m_field;
                                        if (sunVar.m_expression.IndexOf("[REF]") == 0) {
                                            string pName = sunVar.m_expression.Substring(5);
                                            int variablesSize = m_variables.size();
                                            for (int k = 0; k < variablesSize; k++) {
                                                CVariable variable = m_variables[k];
                                                if (variable.m_expression == pName) {
                                                    variable.m_field = id;
                                                }
                                            }
                                        }
                                        else {
                                            if (m_tempVars.containsKey(id)) {
                                                CVar cVar = m_tempVars.get(id);
                                                if (cVar.m_parent != null) {
                                                    m_tempVars.put(id, cVar.m_parent);
                                                }
                                                else {
                                                    m_tempVars.remove(id);
                                                }
                                                cVar.delete();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public virtual void delete() {
            if (!m_isDeleted) {
                clear();
                m_functionsMap.clear();
                m_functions.clear();
                m_isDeleted = true;
            }
        }

        /// <summary>
        /// �����ַ�����ȡ��ɫ
        /// </summary>
        /// <param name="strColor">�ַ���</param>
        /// <returns>��ɫ</returns>
        private long getColor(String strColor) {
            switch (strColor) {
                case "COLORRED": return FCColor.argb(255, 0, 0);
                case "COLORGREEN": return FCColor.argb(0, 255, 0);
                case "COLORBLUE": return FCColor.argb(0, 0, 255);
                case "COLORMAGENTA": return FCColor.argb(255, 0, 255);
                case "COLORYELLOW": return FCColor.argb(255, 255, 0);
                case "COLORLIGHTGREY": return FCColor.argb(211, 211, 211);
                case "COLORLIGHTRED": return FCColor.argb(255, 82, 82);
                case "COLORLIGHTGREEN": return FCColor.argb(144, 238, 144);
                case "COLORLIGHTBLUE": return FCColor.argb(173, 216, 230);
                case "COLORBLACK": return FCColor.argb(0, 0, 0);
                case "COLORWHITE": return FCColor.argb(255, 255, 255);
                case "COLORCYAN": return FCColor.argb(0, 255, 255);
                case "COLORAUTO":
                    int lineCount = 0;
                    long lineColor = FCColor.None;
                    foreach (BaseShape shape in getShapes()) {
                        if (shape is PolylineShape) {
                            lineCount++;
                        }
                    }
                    int systemColorsSize = m_systemColors.size();
                    if (systemColorsSize > 0) {
                        lineColor = m_systemColors[(lineCount) % systemColorsSize];
                    }
                    return lineColor;
                default: {
                        strColor = strColor.Substring(5);
                        Color color = ColorTranslator.FromHtml("#" + strColor);
                        int r = color.R;
                        int g = color.G;
                        int b = color.B;
                        return FCColor.argb(r, g, b);
                    }
            }
        }

        /// <summary>
        /// ������Դ�л�ȡ����ָ����Ҫ��MATH_STRUCT�ṹ
        /// </summary>
        /// <param name="fieldIndex">�ֶ�</param>
        /// <param name="mafieldIndex">����MAֵ�ֶ�</param>
        /// <param name="index">��������</param>
        /// <param name="n">����</param>
        /// <returns>MATH_STRUCT�ṹ</returns>
        private LPDATA getDatas(int fieldIndex, int mafieldIndex, int index, int n) {
            LPDATA math_struct = new LPDATA();
            //����ģʽΪ1��Ч�ʽϸ�
            math_struct.mode = 1;
            if (index >= 0) {
                //��ȡ��ǰ��ֵ
                double value = m_dataSource.get3(index, mafieldIndex);
                if (!double.IsNaN(value)) {
                    math_struct.lastvalue = value;
                    //��ȡMA��Ҫ��ȡ�ĵ�һ��ֵ
                    if (index >= n - 1) {
                        double nValue = m_dataSource.get3(index + 1 - n, fieldIndex);
                        if (!double.IsNaN(nValue)) {
                            math_struct.first_value = nValue;
                        }
                    }
                }
                else {
                    //����ģʽΪ2��Ч�ʽϵ�
                    math_struct.mode = 0;
                    ArrayList<double> list = new ArrayList<double>();
                    int start = index - n + 2;
                    if (start < 0) start = 0;
                    for (int i = start; i <= index; i++) {
                        double lValue = m_dataSource.get3(i, fieldIndex);
                        if (!double.IsNaN(lValue)) {
                            math_struct.sum += lValue;
                        }
                    }
                }
            }
            return math_struct;
        }

        /// <summary>
        /// ��ȡ���еķ���
        /// </summary>
        /// <returns>�����б�</returns>
        public virtual ArrayList<CFunction> getFunctions() {
            ArrayList<CFunction> functions = new ArrayList<CFunction>();
            foreach (CFunction func in m_functions.Values) {
                functions.add(func);
            }
            return functions;
        }

        /// <summary>
        /// ��ȡ�ߵĿ��
        /// </summary>
        /// <param name="strLine">�ߵ�����</param>
        /// <returns>�߿�</returns>
        private float getLineWidth(String strLine) {
            float lineWidth = 1;
            if (strLine.Length > 9) {
                lineWidth = FCStr.convertStrToFloat(strLine.Substring(9));
            }
            return lineWidth;
        }

        /// <summary>
        /// ��ȡ�м�ű�
        /// </summary>
        /// <param name="script">�ű�</param>
        /// <param name="lines">��</param>
        /// <returns></returns>
        private int getMiddleScript(String script, ArrayList<String> lines) {
            script = script.Replace(" AND ", "&").Replace(" OR ", "|");
            String line = "";
            bool isstr = false;
            char lh = '0';
            bool isComment = false;
            bool functionBegin = false;
            int kh = 0;
            bool isReturn = false, isVar = false, isNewParam = false, isSet = false;
            foreach (char ch in script) {
                if (ch == '\'') {
                    isstr = !isstr;
                }
                if (!isstr) {
                    if (ch == '{') {
                        int lineLength = line.Length;
                        if (lineLength == 0) {
                            isComment = true;
                        }
                        else {
                            if (!isComment) {
                                kh++;
                                if (functionBegin && kh == 1) {
                                    line += "(";
                                }
                                else {
                                    if (line.LastIndexOf(")") == lineLength - 1) {
                                        line = line.Substring(0, lineLength - 1) + VARIABLE2 + "CHUNK(";
                                    }
                                    else if (line.LastIndexOf("))" + VARIABLE2 + "ELSE") == lineLength - 7) {
                                        line = line.Substring(0, lineLength - 6) + VARIABLE2 + "CHUNK(";
                                    }
                                }
                            }
                        }
                    }
                    else if (ch == '}') {
                        if (isComment) {
                            isComment = false;
                        }
                        else {
                            kh--;
                            if (functionBegin && kh == 0) {
                                int lineLength = line.Length;
                                if (lineLength > 0) {
                                    if (line[lineLength - 1].ToString() == VARIABLE2) {
                                        line = line.Substring(0, lineLength - 1);
                                    }
                                }
                                line += ")";
                                lines.add(line);
                                functionBegin = false;
                                line = "";
                            }
                            else {
                                if (kh == 0) {
                                    line += "))";
                                    lines.add(line);
                                    line = "";
                                }
                                else {
                                    line += "))" + VARIABLE2;
                                }
                            }
                        }
                    }
                    else if (ch == ' ') {
                        int lineLength = line.Length;
                        if (line == "CONST") {
                            line = "CONST ";
                        }
                        else if (line == "FUNCTION") {
                            line = "FUNCTION ";
                            functionBegin = true;
                        }
                        else if (!isReturn && (line.LastIndexOf("RETURN") == lineLength - 6)) {
                            if (line.Length == 6 || (line.LastIndexOf(")RETURN") == lineLength - 7
                            || line.LastIndexOf("(RETURN") == lineLength - 7
                            || line.LastIndexOf(VARIABLE2 + "RETURN") == lineLength - 7)) {
                                line += "(";
                                isReturn = true;
                            }
                        }
                        else if (!isVar && line.LastIndexOf("VAR") == lineLength - 3) {
                            if (line.Length == 3 || (line.LastIndexOf(")VAR") == lineLength - 4
                             || line.LastIndexOf("(VAR") == lineLength - 4
                             || line.LastIndexOf(VARIABLE2 + "VAR") == lineLength - 4)) {
                                line += "(";
                                isVar = true;
                                isNewParam = true;
                            }
                        }
                        else if (!isSet && line.LastIndexOf("SET") == lineLength - 3) {
                            if (line.Length == 3 || (line.LastIndexOf(")SET") == lineLength - 4
                            || line.LastIndexOf("(SET") == lineLength - 4
                            || line.LastIndexOf(VARIABLE2 + "SET") == lineLength - 4)) {
                                line = line.Substring(0, lineLength - 3) + "SET(";
                                isSet = true;
                                isNewParam = true;
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    else if (ch != '\t' && ch != '\r' && ch != '\n') {
                        if (!isComment) {
                            if (ch == '&') {
                                if (lh != '&') {
                                    line += ch.ToString();
                                }
                            }
                            else if (ch == '|') {
                                if (lh != '|') {
                                    line += ch.ToString();
                                }
                            }
                            else if (ch == '=') {
                                if (isVar && isNewParam) {
                                    isNewParam = false;
                                    line += VARIABLE2;
                                }
                                else if (isSet && isNewParam) {
                                    isNewParam = false;
                                    line += VARIABLE2;
                                }
                                else {
                                    if (lh != '=' && lh != '!') {
                                        line += ch.ToString();
                                    }
                                }
                            }
                            else if (ch == '-') {
                                if (lh != VARIABLE2[0] && getOperator(lh.ToString()) != OP_NULL && lh != ')') {
                                    line += ch.ToString();
                                }
                                else {
                                    line += VARIABLE3;
                                    lh = VARIABLE3[0];
                                    continue;
                                }
                            }
                            else if (ch == ',') {
                                isNewParam = true;
                                line += VARIABLE2;
                            }
                            else if (ch == ';') {
                                if (isReturn) {
                                    line += ")";
                                    isReturn = false;
                                }
                                else if (isVar) {
                                    line += ")";
                                    isVar = false;
                                }
                                else if (isSet) {
                                    line += ")";
                                    isSet = false;
                                }
                                else {
                                    int lineLength = line.Length;
                                    if (line.LastIndexOf("BREAK") == lineLength - 5) {
                                        if (line.LastIndexOf(")BREAK") == lineLength - 6
                                       || line.LastIndexOf("(BREAK") == lineLength - 6
                                       || line.LastIndexOf(VARIABLE2 + "BREAK") == lineLength - 6) {
                                            line += "()";
                                        }
                                    }
                                    else if (line.LastIndexOf("CONTINUE") == lineLength - 8) {
                                        if (line.LastIndexOf(")CONTINUE") == lineLength - 9
                                        || line.LastIndexOf("(CONTINUE") == lineLength - 9
                                        || line.LastIndexOf(VARIABLE2 + "CONTINUE") == lineLength - 9) {
                                            line += "()";
                                        }
                                    }
                                }
                                if (kh > 0) {
                                    line += VARIABLE2;
                                }
                                else {
                                    lines.add(line);
                                    line = "";
                                }
                            }
                            else if (ch == '(') {
                                int lineLength = line.Length;
                                if (kh > 0 && line.LastIndexOf("))" + VARIABLE2 + "ELSEIF") == lineLength - 9) {
                                    line = line.Substring(0, lineLength - 9) + ")" + VARIABLE2;
                                }
                                else {
                                    line += "(";
                                }
                            }
                            else {
                                line += ch.ToString().ToUpper();
                            }
                        }
                    }
                }
                else {
                    line += ch.ToString();
                }
                lh = ch;
            }
            return 0;
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <param name="op">�ַ���</param>
        /// <returns>��������</returns>
        private int getOperator(String op) {
            switch (op) {
                case ">=":
                    return OP_GTE;
                case "<=":
                    return OP_LTE;
                case "<>":
                case "!":
                    return OP_NE;
                case "+":
                    return OP_ADD;
                case VARIABLE3:
                    return OP_SUB;
                case "*":
                    return OP_MULTIPLY;
                case "/":
                    return OP_DIVIDE;
                case "(":
                    return OP_LB;
                case ")":
                    return OP_RB;
                case "=":
                    return OP_E;
                case ">":
                    return OP_GT;
                case "<":
                    return OP_LT;
                case "&":
                    return OP_AND;
                case "|":
                    return OP_OR;
                case "%":
                    return OP_MOD;
            }
            return OP_NULL;
        }

        /// <summary>
        /// ��ȡ���е�ͼ��
        /// </summary>
        /// <returns>��ȡ���е�ͼ��</returns>
        public virtual ArrayList<BaseShape> getShapes() {
            ArrayList<BaseShape> shapes = new ArrayList<BaseShape>();
            foreach (CVariable var in m_variables) {
                if (var.m_barShape != null) {
                    shapes.add(var.m_barShape);
                }
                if (var.m_candleShape != null) {
                    shapes.add(var.m_candleShape);
                }
                if (var.m_polylineShape != null) {
                    shapes.add(var.m_polylineShape);
                }
                if (var.m_textShape != null) {
                    shapes.add(var.m_textShape);
                }
            }
            return shapes;
        }

        /// <summary>
        /// ��ȡ�ı�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�ı�</returns>
        public virtual String getText(CVariable var) {
            if (var.m_expression.Length > 0 && var.m_expression[0] == '\'') {
                return var.m_expression.Substring(1, var.m_expression.Length - 2);
            }
            else {
                if (m_tempVars.containsKey(var.m_field)) {
                    CVar cVar = m_tempVars.get(var.m_field);
                    return cVar.getText(this, var);
                }
                else {
                    return FCStr.convertDoubleToStr(getValue(var));
                }
            }
        }

        /// <summary>
        /// ��ȡ��ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������</returns>
        public virtual double getValue(CVariable var) {
            switch (var.m_type) {
                case 0:
                    return callFunction(var);
                case 1:
                    if (m_tempVars.size() > 0) {
                        if (m_tempVars.containsKey(var.m_field)) {
                            return m_tempVars.get(var.m_field).getValue(this, var);
                        }
                    }
                    if (var.m_expression != null && var.m_expression[0] == '\'') {
                        return FCStr.convertStrToDouble(var.m_expression.Substring(1, var.m_expression.Length - 2));
                    }
                    else {
                        if (var.m_splitExpression != null) {
                            return calculate(var.m_splitExpression);
                        }
                        else {
                            return 0;
                        }
                    }
                case 2:
                    return m_dataSource.get3(m_index, var.m_fieldIndex);
                case 3:
                    return var.m_value;
                default:
                    return 0;
            }
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="name">����</param>
        /// <returns>����</returns>
        public virtual CVariable getVariable(String name) {
            if (m_tempVariables.containsKey(name)) {
                return m_tempVariables.get(name);
            }
            else {
                return null;
            }
        }

        /// <summary>
        /// ����ָ��
        /// </summary>
        /// <param name="index">����</param>
        /// <returns>�Ƿ����ɹ�</returns>
        public virtual void onCalculate(int index) {
            lock (m_lock) {
                if (m_lines != null && m_lines.size() > 0) {
                    //��ȡ�е�����
                    foreach (CVariable sentence in m_lines) {
                        if (sentence.m_field != FCDataTable.NULLFIELD) {
                            sentence.m_fieldIndex = m_dataSource.getColumnIndex(sentence.m_field);
                        }
                    }
                    foreach (CVariable var in m_variables) {
                        if (var.m_field != FCDataTable.NULLFIELD) {
                            var.m_fieldIndex = m_dataSource.getColumnIndex(var.m_field);
                        }
                        if (var.m_tempFields != null) {
                            for (int i = 0; i < var.m_tempFields.Length; i++) {
                                var.m_tempFieldsIndex[i] = m_dataSource.getColumnIndex(var.m_tempFields[i]);
                            }
                        }
                    }
                    for (int i = index; i < m_dataSource.RowsCount; i++) {
                        m_break = 0;
                        m_index = i;
                        int lineSize = m_lines.size();
                        for (int j = 0; j < lineSize; j++) {
                            CVariable sentence = m_lines[j];
                            if (sentence.m_funcName == null || (sentence.m_funcName != null && sentence.m_line != j)) {
                                //����ָ��
                                double value = calculate(sentence.m_splitExpression);
                                if (sentence.m_type == 1 && sentence.m_field != FCDataTable.NULLFIELD) {
                                    m_dataSource.set3(i, sentence.m_fieldIndex, value);
                                }
                            }
                            if (m_break == 1) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        /// <summary>
        /// �Ƴ�����
        /// </summary>
        /// <param name="function">����</param>
        public virtual void removeFunction(CFunction function) {
            m_functions.remove(function.m_name);
            m_functionsMap.remove(function.m_ID);
        }

        /// <summary>
        /// �滻�����ͱ���
        /// </summary>
        /// <param name="parameter">����</param>
        /// <returns>�滻�����</returns>
        private String replace(String parameter) {
            //�滻����
            String[] splitParameters = splitExpression2(parameter);
            for (int p = 0; p < splitParameters.Length; p++) {
                String str = splitParameters[p];
                if (m_defineParams.containsKey(str)) {
                    splitParameters[p] = m_defineParams.get(str).ToString();
                }
                else {
                    foreach (CVariable varaible in m_variables) {
                        if (varaible.m_type == 2 && varaible.m_expression == str) {
                            splitParameters[p] = varaible.m_name;
                            break;
                        }
                    }
                }
            }
            String newParameter = "";
            for (int p = 0; p < splitParameters.Length - 1; p++) {
                newParameter += splitParameters[p];
            }
            return newParameter;
        }

        /// <summary>
        /// ��������Դ�ֶ�
        /// </summary>
        /// <param name="key">��</param>
        /// <param name="value">ֵ</param>
        public virtual void setSourceField(String key, int value) {
            CVariable pfunc = new CVariable(this);
            pfunc.m_type = 2;
            pfunc.m_name = VARIABLE + m_variables.size().ToString();
            pfunc.m_expression = key;
            pfunc.m_splitExpression = splitExpression(key);
            pfunc.m_field = value;
            int columnIndex = m_dataSource.getColumnIndex(value);
            if (columnIndex == -1) {
                m_dataSource.addColumn(value);
            }
            m_variables.add(pfunc);
        }

        /// <summary>
        /// ��������Դֵ
        /// </summary>
        /// <param name="key">��</param>
        /// <param name="value">ֵ</param>
        public virtual void setSourceValue(int index, String key, double value) {
            CVariable pfunc = null;
            foreach (CVariable var in m_variables) {
                if (var.m_type == 2 && var.m_expression == key) {
                    pfunc = var;
                    break;
                }
            }
            if (pfunc != null) {
                m_dataSource.set2(index, pfunc.m_field, value);
            }
        }

        /// <summary>
        /// ���ñ�����ֵ
        /// </summary>
        /// <param name="variable">����</param>
        /// <param name="parameter">ֵ</param>
        /// <returns>���</returns>
        public virtual void setVariable(CVariable variable, CVariable parameter) {
            int type = variable.m_type;
            int id = variable.m_field;
            switch (type) {
                case 2:
                    double value = getValue(parameter);
                    m_dataSource.set3(m_index, variable.m_fieldIndex, value);
                    break;
                default:
                    if (m_tempVars.containsKey(id)) {
                        CVar cVar = m_tempVars.get(id);
                        cVar.setValue(this, variable, parameter);
                        if (m_resultVar != null) {
                            cVar.m_str = m_resultVar.m_str;
                            m_resultVar = null;
                        }
                    }
                    else {
                        variable.m_value = getValue(parameter);
                    }
                    break;
            }
        }

        /// <summary>
        /// �ѱ��ʽ��ֳ��ַ������飬���ں���ļ�����ֵ
        /// </summary>
        /// <param name="expression">���ʽ</param>
        /// <returns>�����ҷ��ش��±�0��ʼ���ַ�������</returns>
        private CMathElement[] splitExpression(String expression) {
            CMathElement[] exprs = null;
            ArrayList<String> lstItem = new ArrayList<String>();
            int length = expression.Length;
            String item = String.Empty;
            String ch = String.Empty;
            bool isstr = false;
            while (length != 0) {
                ch = expression.Substring(expression.Length - length, 1);
                if (ch == "\'") {
                    isstr = !isstr;
                }
                if (isstr || getOperator(ch) == OP_NULL) item += ch;
                else {
                    if (item != String.Empty) {
                        lstItem.add(item);
                    }
                    item = String.Empty;
                    int nextIndex = expression.Length - length + 1;
                    String chNext = String.Empty;
                    if (nextIndex < expression.Length - 1) {
                        chNext = expression.Substring(nextIndex, 1);
                    }
                    String unionText = ch + chNext;
                    //˫�ֽڷ��Ŵ���
                    if (unionText == ">=" || unionText == "<=" || unionText == "<>") {
                        lstItem.add(unionText);
                        length--;
                    }
                    else {
                        lstItem.add(ch);
                    }
                }
                length--;
            }
            if (item != String.Empty) {
                lstItem.add(item);
            }
            exprs = new CMathElement[lstItem.size() + 1];
            int lstSize = lstItem.size();
            for (int i = 0; i < lstSize; i++) {
                CMathElement expr = new CMathElement();
                String strExpr = lstItem[i];
                int op = getOperator(strExpr);
                if (op != OP_NULL) {
                    expr.m_type = 0;
                    expr.m_value = op;
                }
                else {
                    double value = 0;
                    bool success = double.TryParse(strExpr, out value);
                    if (success) {
                        expr.m_type = 1;
                        expr.m_value = value;
                    }
                    else {
                        foreach (CVariable var in m_variables) {
                            if (var.m_name == strExpr || var.m_expression == strExpr) {
                                expr.m_type = 2;
                                expr.m_var = var;
                                break;
                            }
                        }
                    }
                }
                exprs[i] = expr;
            }
            CMathElement lExpr = new CMathElement();
            lExpr.m_type = 3;
            exprs[lstItem.size()] = lExpr;
            return exprs;
        }

        /// <summary>
        /// �ѱ��ʽ��ֳ��ַ������飬���ں���ļ�����ֵ
        /// </summary>
        /// <param name="expression">���ʽ</param>
        /// <returns>�����ҷ��ش��±�0��ʼ���ַ�������</returns>
        private String[] splitExpression2(String expression) {
            String[] exprs = null;
            ArrayList<String> lstItem = new ArrayList<String>();
            int length = expression.Length;
            String item = String.Empty;
            String ch = String.Empty;
            bool isstr = false;
            while (length != 0) {
                ch = expression.Substring(expression.Length - length, 1);
                if (ch == "\'") {
                    isstr = !isstr;
                }
                if (isstr || getOperator(ch) == OP_NULL) item += ch;
                else {
                    if (item != String.Empty) {
                        lstItem.add(item);
                    }
                    item = String.Empty;
                    int nextIndex = expression.Length - length + 1;
                    String chNext = String.Empty;
                    if (nextIndex < expression.Length - 1) {
                        chNext = expression.Substring(nextIndex, 1);
                    }
                    String unionText = ch + chNext;
                    //˫�ֽڷ��Ŵ���
                    if (unionText == ">=" || unionText == "<=" || unionText == "<>") {
                        lstItem.add(unionText);
                        length--;
                    }
                    else {
                        lstItem.add(ch);
                    }
                }
                length--;
            }
            if (item != String.Empty) {
                lstItem.add(item);
            }
            exprs = new String[lstItem.size() + 1];
            for (int i = 0; i < lstItem.size(); i++) exprs[i] = lstItem[i];
            exprs[lstItem.size()] = "#";
            return exprs;
        }

        /// <summary>
        /// �������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        private double ABS(CVariable var) {
            return Math.Abs(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ��������Ӧ����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����Ӧ����ֵ</returns>
        private double AMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            double lastAma = 0;
            if (m_index > 0) {
                lastAma = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            //��ȡ������Ҫ�Ĳ���
            double n = getValue(var.m_parameters[1]);
            double ama = lastAma + n * (close - lastAma);
            m_dataSource.set3(m_index, var.m_fieldIndex, ama);
            return ama;
        }

        /// <summary>
        /// ���㷴����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������ֵ</returns>
        private double ACOS(CVariable var) {
            return Math.Acos(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ���㷴����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������ֵ</returns>
        private double ASIN(CVariable var) {
            return Math.Asin(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ���㷴����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������ֵ</returns>
        private double ATAN(CVariable var) {
            return Math.Atan(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ����ƽ������ƫ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ƽ������ƫ��</returns>
        private double AVEDEV(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int p = (int)getValue(var.m_parameters[1]);
            CVariable cParam = var.m_parameters[0];
            int closeFieldIndex = cParam.m_fieldIndex;
            //��ȡ������Ҫ��ֵ
            double close = getValue(cParam);
            int closeField = cParam.m_field;
            if (closeFieldIndex == -1) {
                if (var.m_tempFields == null) {
                    var.createTempFields(1);
                }
                closeFieldIndex = var.m_tempFieldsIndex[0];
                closeField = var.m_tempFields[0];
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            double[] list = m_dataSource.DATA_ARRAY(closeField, m_index, p);
            double avg = 0;
            if (list != null && list.Length > 0) {
                double sum = 0;
                for (int i = 0; i < list.Length; i++) {
                    sum += list[i];
                }
                avg = sum / list.Length;
            }
            return avedev(close, list, list.Length, avg);
        }

        /// <summary>
        /// ����������Ŀ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������Ŀ</returns>
        private int BARSCOUNT(CVariable var) {
            return m_dataSource.RowsCount;
        }

        /// <summary>
        /// ������һ��������������ǰ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������</returns>
        private int BARSLAST(CVariable var) {
            int result = 0;
            int tempIndex = m_index;
            for (int i = m_index; i >= 0; i--) {
                m_index = i;
                double value = getValue(var.m_parameters[0]);
                if (value == 1) {
                    break;
                }
                else {
                    if (i == 0) {
                        result = 0;
                    }
                    else {
                        result++;
                    }
                }
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// �жϱ��ʽ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int BETWEEN(CVariable var) {
            double value = getValue(var.m_parameters[0]);
            double min = getValue(var.m_parameters[1]);
            double max = getValue(var.m_parameters[2]);
            int result = 0;
            if (value >= min && value <= max) {
                result = 1;
            }
            return result;
        }

        /// <summary>
        /// ����ѭ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int BREAK(CVariable var) {
            m_break = 2;
            return 0;
        }

        /// <summary>
        /// �������Ͻӽ�������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���Ͻӽ�������</returns>
        private double CEILING(CVariable var) {
            return Math.Ceiling(getValue(var.m_parameters[0]));
        }

        /// ִ�д����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        private double CHUNK(CVariable var) {
            int pLen = var.m_parameters.Length;
            if (pLen > 0) {
                for (int i = 0; m_break == 0 && i < pLen; i++) {
                    getValue(var.m_parameters[i]);
                }
            }
            deleteTempVars(var);
            return 0;
        }

        /// <summary>
        /// ����ѭ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int CONTINUE(CVariable var) {
            m_break = 3;
            return 0;
        }

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        private double COS(CVariable var) {
            return Math.Cos(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ͳ������������������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������</returns>
        private int COUNT(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 0;
            for (int i = 0; i < n; i++) {
                if (getValue(var.m_parameters[0]) > 0) {
                    result++;
                }
                m_index--;
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// �ж��Ƿ�Խ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��Խ:1 ����Խ:0</returns>
        private int CROSS(CVariable var) {
            double x = getValue(var.m_parameters[0]);
            double y = getValue(var.m_parameters[1]);
            int result = 0;
            int tempIndex = m_index;
            m_index -= 1;
            if (m_index < 0) {
                m_index = 0;
            }
            double lastX = getValue(var.m_parameters[0]);
            double lastY = getValue(var.m_parameters[1]);
            m_index = tempIndex;
            if (x >= y && lastX < lastY) {
                result = 1;
            }
            return result;
        }

        /// <summary>
        /// ��ȡ��ǰ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��������</returns>
        private int CURRBARSCOUNT(CVariable var) {
            return m_index + 1;
        }

        /// <summary>
        /// ȡ�ø����ڴ�1900�����ĵ�������.
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������</returns>
        private int DATE(CVariable var) {
            int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, ms = 0;
            FCStr.getDateByNum(m_dataSource.getXValue(m_index), ref year, ref month, ref day, ref hour, ref minute, ref second, ref ms);
            return year * 10000 + month * 100 + day;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����</returns>
        private int DAY(CVariable var) {
            return FCStr.convertNumToDate(m_dataSource.getXValue(m_index)).Day;
        }

        /// <summary>
        /// ɾ������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int DELETE(CVariable var) {
            int pLen = var.m_parameters.Length;
            for (int i = 0; i < pLen; i++) {
                CVariable name = var.m_parameters[i];
                int id = name.m_field;
                if (m_tempVars.containsKey(id)) {
                    CVar cVar = m_tempVars.get(id);
                    if (cVar.m_parent != null) {
                        m_tempVars.put(id, cVar.m_parent);
                    }
                    else {
                        m_tempVars.remove(id);
                    }
                    cVar.delete();
                }
            }
            return 0;
        }

        /// <summary>
        /// ���㶯̬�ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��̬�ƶ�ƽ��</returns>
        private double DMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            double lastDma = 0;
            if (m_index > 0) {
                lastDma = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            //��ȡ������Ҫ�Ĳ���
            double n = getValue(var.m_parameters[1]);
            //����ָ��
            double result = n * close + (1 - n) * lastDma;
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// ѭ��ִ��һ������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private int DOTIMES(CVariable var) {
            int n = (int)getValue(var.m_parameters[0]);
            int pLen = var.m_parameters.Length;
            if (pLen > 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 1; m_break == 0 && j < pLen; j++) {
                        getValue(var.m_parameters[j]);
                    }
                    if (m_break > 0) {
                        if (m_break == 3) {
                            m_break = 0;
                            deleteTempVars(var);
                            continue;
                        }
                        else {
                            m_break = 0;
                            deleteTempVars(var);
                            break;
                        }
                    }
                    else {
                        deleteTempVars(var);
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// ִ��DOWHILEѭ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private int DOWHILE(CVariable var) {
            int pLen = var.m_parameters.Length;
            if (pLen > 1) {
                while (true) {
                    for (int i = 0; m_break == 0 && i < pLen - 1; i++) {
                        getValue(var.m_parameters[i]);
                    }
                    if (m_break > 0) {
                        if (m_break == 3) {
                            m_break = 0;
                            deleteTempVars(var);
                            continue;
                        }
                        else {
                            m_break = 0;
                            deleteTempVars(var);
                            break;
                        }
                    }
                    double inLoop = getValue(var.m_parameters[pLen - 1]);
                    deleteTempVars(var);
                    if (inLoop <= 0) {
                        break;
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// �����Ƿ�����������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�Ƿ�����������</returns>
        private int DOWNNDAY(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[0]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 1;
            for (int i = 0; i < n; i++) {
                double right = getValue(var.m_parameters[0]);
                m_index--;
                double left = m_index >= 0 ? getValue(var.m_parameters[0]) : 0;
                if (right >= left) {
                    result = 0;
                    break;
                }
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// ���Ƶ�ͼ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>0</returns>
        private double DRAWICON(CVariable var) {
            if (m_div != null) {
                CVariable cond = var.m_parameters[0];
                CVariable price = var.m_parameters[1];
                PolylineShape polylineShape = null;
                if (var.m_polylineShape == null) {
                    String strColor = "COLORAUTO";
                    String strStyle = "CIRCLEDOT";
                    for (int i = 2; i < var.m_parameters.Length; i++) {
                        String strParam = var.m_parameters[i].m_expression;
                        if (strParam.IndexOf("COLOR") == 0) {
                            strColor = strParam;
                            break;
                        }
                        else if (strParam == "CIRCLEDOT") {
                            strStyle = strParam;
                            break;
                        }
                        else if (strParam == "POINTDOT") {
                            strStyle = strParam;
                            break;
                        }
                    }
                    if (var.m_expression == "DRAWICON") {
                        strStyle = var.m_expression;
                    }
                    polylineShape = new PolylineShape();
                    m_div.addShape(polylineShape);
                    long lineColor = getColor(strColor);
                    //��������
                    polylineShape.AttachVScale = m_attachVScale;
                    polylineShape.FieldText = price.m_fieldText;
                    polylineShape.Color = lineColor;
                    polylineShape.Style = PolylineStyle.Cycle;
                    var.createTempFields(1);
                    var.m_polylineShape = polylineShape;
                }
                else {
                    polylineShape = var.m_polylineShape;
                }
                //��Ӽ۸��ֶ�
                if (price.m_expression != null && price.m_expression.Length > 0) {
                    if (polylineShape.FieldName == FCDataTable.NULLFIELD) {
                        if (price.m_field != FCDataTable.NULLFIELD) {
                            polylineShape.FieldName = price.m_field;
                        }
                        else {
                            price.createTempFields(1);
                            polylineShape.FieldName = price.m_tempFields[0];
                        }
                        for (int i = 2; i < var.m_parameters.Length; i++) {
                            String strParam = var.m_parameters[i].m_expression;
                            if (strParam == "DRAWTITLE") {
                                if (polylineShape.FieldText != null) {
                                    m_div.TitleBar.Titles.add(new CTitle(polylineShape.FieldName, polylineShape.FieldText, polylineShape.Color, 2, true));
                                }
                            }
                        }
                    }
                    if (price.m_tempFields != null) {
                        double value = getValue(price);
                        m_dataSource.set3(m_index, price.m_tempFieldsIndex[0], value);
                    }
                }
                //��������
                double dCond = 1;
                if (cond.m_expression != null && cond.m_expression.Length > 0 && cond.m_expression != "1") {
                    dCond = getValue(cond);
                    if (dCond != 1) {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], -10000);
                    }
                    else {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], 1);
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// ����K��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>0</returns>
        private double DRAWKLINE(CVariable var) {
            if (m_div != null) {
                CVariable high = var.m_parameters[0];
                CVariable open = var.m_parameters[1];
                CVariable low = var.m_parameters[2];
                CVariable close = var.m_parameters[3];
                CandleShape candleShape = null;
                if (var.m_candleShape == null) {
                    candleShape = new CandleShape();
                    candleShape.HighFieldText = high.m_fieldText;
                    candleShape.OpenFieldText = open.m_fieldText;
                    candleShape.LowFieldText = low.m_fieldText;
                    candleShape.CloseFieldText = close.m_fieldText;
                    candleShape.AttachVScale = m_attachVScale;
                    candleShape.Style = CandleStyle.Rect;
                    m_div.addShape(candleShape);
                    var.m_candleShape = candleShape;
                }
                else {
                    candleShape = var.m_candleShape;
                }
                //������߼��ֶ�
                if (high.m_expression != null && high.m_expression.Length > 0) {
                    if (candleShape.HighField == FCDataTable.NULLFIELD) {
                        if (high.m_field != FCDataTable.NULLFIELD) {
                            candleShape.HighField = high.m_field;
                        }
                        else {
                            high.createTempFields(1);
                            candleShape.HighField = high.m_tempFields[0];
                        }
                    }
                    if (high.m_tempFields != null) {
                        double value = getValue(high);
                        m_dataSource.set3(m_index, high.m_tempFieldsIndex[0], value);
                    }
                }
                //���ÿ��̼��ֶ�
                if (open.m_expression != null && open.m_expression.Length > 0) {
                    if (open.m_field != FCDataTable.NULLFIELD) {
                        candleShape.OpenField = open.m_field;
                    }
                    else {
                        open.createTempFields(1);
                        candleShape.OpenField = open.m_tempFields[0];
                    }
                    if (open.m_tempFields != null) {
                        double value = getValue(open);
                        m_dataSource.set3(m_index, open.m_tempFieldsIndex[0], value);
                    }
                }
                //������ͼ��ֶ�
                if (low.m_expression != null && low.m_expression.Length > 0) {
                    if (low.m_field != FCDataTable.NULLFIELD) {
                        candleShape.LowField = low.m_field;
                    }
                    else {
                        low.createTempFields(1);
                        candleShape.LowField = low.m_tempFields[0];
                    }
                    if (low.m_tempFields != null) {
                        double value = getValue(low);
                        m_dataSource.set3(m_index, low.m_tempFieldsIndex[0], value);
                    }
                }
                //�������̼��ֶ�
                if (close.m_expression != null && close.m_expression.Length > 0) {
                    if (close.m_field != FCDataTable.NULLFIELD) {
                        candleShape.CloseField = close.m_field;
                    }
                    else {
                        close.createTempFields(1);
                        candleShape.CloseField = close.m_tempFields[0];
                    }
                    if (close.m_tempFields != null) {
                        double value = getValue(close);
                        m_dataSource.set3(m_index, close.m_tempFieldsIndex[0], value);
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// ������Ч��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��Ч��</returns>
        private double DRAWNULL(CVariable var) {
            return double.NaN;
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>0</returns>
        private double DRAWTEXT(CVariable var) {
            if (m_div != null) {
                //��ȡ����
                CVariable cond = var.m_parameters[0];
                CVariable price = var.m_parameters[1];
                CVariable text = var.m_parameters[2];
                TextShape textShape = null;
                if (var.m_textShape == null) {
                    textShape = new TextShape();
                    textShape.AttachVScale = m_attachVScale;
                    textShape.Text = getText(text);
                    var.createTempFields(1);
                    textShape.StyleField = var.m_tempFields[0];
                    String strColor = "COLORAUTO";
                    for (int i = 3; i < var.m_parameters.Length; i++) {
                        String strParam = var.m_parameters[i].m_expression;
                        if (strParam.IndexOf("COLOR") == 0) {
                            strColor = strParam;
                            break;
                        }
                    }
                    if (strColor != "COLORAUTO") {
                        textShape.TextColor = getColor(strColor);
                    }
                    m_div.addShape(textShape);
                    var.m_textShape = textShape;
                }
                else {
                    textShape = var.m_textShape;
                }
                //��Ӽ۸��ֶ�
                if (price.m_expression != null && price.m_expression.Length > 0) {
                    if (textShape.FieldName == FCDataTable.NULLFIELD) {
                        if (price.m_field != FCDataTable.NULLFIELD) {
                            textShape.FieldName = price.m_field;
                        }
                        else {
                            price.createTempFields(1);
                            textShape.FieldName = price.m_tempFields[0];
                        }
                    }
                    if (price.m_tempFields != null) {
                        double value = getValue(price);
                        m_dataSource.set3(m_index, price.m_tempFieldsIndex[0], value);
                    }
                }
                //��������
                double dCond = 1;
                if (cond.m_expression != null && cond.m_expression.Length > 0 && cond.m_expression != "1") {
                    dCond = getValue(cond);
                    if (dCond != 1) {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], -10000);
                    }
                    else {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], 0);
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// �ж��Ƿ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�Ƿ����</returns>
        private int EXIST(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 0;
            for (int i = 0; i < n; i++) {
                if (getValue(var.m_parameters[0]) > 0) {
                    result = 1;
                    break;
                }
                m_index--;
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// ����ָ���ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ָ���ƶ�ƽ��</returns>
        private double EMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            double lastEma = 0;
            if (m_index > 0) {
                lastEma = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            //����ָ��
            double result = FCScript.exponentialMovingAverage(n, close, lastEma);
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// �ж��Ƿ�һֱ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�Ƿ�һֱ����</returns>
        private int EVERY(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 1;
            for (int i = 0; i < n; i++) {
                if (getValue(var.m_parameters[0]) <= 0) {
                    result = 0;
                    break;
                }
                m_index--;
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// ����ָ��ƽ���ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ָ��ƽ���ƶ�ƽ��</returns>
        private double EXPMEMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            CVariable cParam = var.m_parameters[0];
            double close = getValue(cParam);
            int closeFieldIndex = cParam.m_fieldIndex;
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            if (var.m_tempFields == null) {
                if (closeFieldIndex == -1) {
                    var.createTempFields(2);
                }
                else {
                    var.createTempFields(1);
                }
            }
            if (var.m_tempFields.Length == 2) {
                closeFieldIndex = var.m_tempFieldsIndex[1];
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //����ָ��
            int maFieldIndex = var.m_tempFieldsIndex[0];
            double ma = movingAverage(m_index, n, close, getDatas(closeFieldIndex, maFieldIndex, m_index - 1, n));
            m_dataSource.set3(m_index, maFieldIndex, ma);
            double lastEma = 0;
            if (m_index > 0) {
                lastEma = m_dataSource.get3(m_index, var.m_fieldIndex);
            }
            //����ָ��
            double result = exponentialMovingAverage(n, ma, lastEma);
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// ����e��X����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>e��X����</returns>
        private double EXP(CVariable var) {
            return Math.Exp(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// �������½ӽ�������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���½ӽ�������</returns>
        private double FLOOR(CVariable var) {
            return Math.Floor(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ִ��FORѭ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private int FOR(CVariable var) {
            int pLen = var.m_parameters.Length;
            if (pLen > 3) {
                int start = (int)getValue(var.m_parameters[0]);
                int end = (int)getValue(var.m_parameters[1]);
                int step = (int)getValue(var.m_parameters[2]);
                if (step > 0) {
                    for (int i = start; i < end; i += step) {
                        for (int j = 3; j < pLen; j++) {
                            getValue(var.m_parameters[j]);
                            if (m_break != 0) {
                                break;
                            }
                        }
                        if (m_break > 0) {
                            if (m_break == 3) {
                                m_break = 0;
                                deleteTempVars(var);
                                continue;
                            }
                            else {
                                m_break = 0;
                                deleteTempVars(var);
                                break;
                            }
                        }
                        else {
                            deleteTempVars(var);
                        }
                    }
                }
                else if (step < 0) {
                    for (int i = start; i > end; i += step) {
                        for (int j = 3; j < pLen; j++) {
                            if (m_break != 0) {
                                break;
                            }
                        }
                        if (m_break > 0) {
                            if (m_break == 3) {
                                m_break = 0;
                                deleteTempVars(var);
                                continue;
                            }
                            else {
                                m_break = 0;
                                deleteTempVars(var);
                                break;
                            }
                        }
                        else {
                            deleteTempVars(var);
                        }
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// ִ�з���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        private double FUNCTION(CVariable var) {
            m_result = 0;
            if (var.m_parameters != null) {
                int pLen = var.m_parameters.Length;
                if (pLen > 0) {
                    for (int i = 0; i < pLen; i++) {
                        getValue(var.m_parameters[i]);
                    }
                }
            }
            String name = var.m_expression;
            if (m_tempFunctions.containsKey(name)) {
                getValue(m_tempFunctions.get(name));
            }
            if (m_break == 1) {
                m_break = 0;
            }
            double result = m_result;
            m_result = 0;
            deleteTempVars(var);
            return result;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ֵ</returns>
        private double FUNCVAR(CVariable var) {
            double result = 0;
            int pLen = var.m_parameters.Length;
            HashMap<CVar, int> cVars = new HashMap<CVar, int>();
            for (int i = 0; i < pLen; i++) {
                if (i % 2 == 0) {
                    CVariable name = var.m_parameters[i];
                    CVariable value = var.m_parameters[i + 1];
                    int id = name.m_field;
                    if (name.m_expression.IndexOf("[REF]") == 0) {
                        int variablesSize = m_variables.size();
                        for (int j = 0; j < variablesSize; j++) {
                            CVariable variable = m_variables[j];
                            if (variable != name) {
                                if (variable.m_field == id) {
                                    variable.m_field = value.m_field;
                                }
                            }
                        }
                        continue;
                    }
                    CVar newCVar = m_varFactory.createVar();
                    result = newCVar.onCreate(this, name, value);
                    if (newCVar.m_type == 1) {
                        name.m_functionID = -2;
                    }
                    cVars.put(newCVar, id);
                }
            }
            foreach (CVar newCVar in cVars.Keys) {
                int id = cVars[newCVar];
                if (m_tempVars.containsKey(id)) {
                    CVar cVar = m_tempVars.get(id);
                    newCVar.m_parent = cVar;
                }
                m_tempVars.put(id, newCVar);
            }
            cVars.clear();
            return result;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ֵ</returns>
        private double GET(CVariable var) {
            return getValue(var.m_parameters[0]);
        }

        /// <summary>
        /// ����ָ���ֶ�һ�������ڵ����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���ֵ</returns>
        private double HHV(CVariable var) {
            //��ȡ����
            int n = (int)getValue(var.m_parameters[1]);
            CVariable cParam = var.m_parameters[0];
            int closeFieldIndex = cParam.m_fieldIndex;
            int closeField = cParam.m_field;
            if (closeFieldIndex == -1) {
                if (cParam.m_tempFields == null) {
                    cParam.createTempFields(0);
                }
                closeFieldIndex = cParam.m_tempFieldsIndex[0];
                closeField = cParam.m_tempFields[0];
                double close = getValue(cParam);
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            double[] higharray = m_dataSource.DATA_ARRAY(closeField, m_index, n);
            return FCScript.maxValue(higharray, higharray.Length);
        }

        /// <summary>
        /// ����ָ���ֶ�һ�������ڵ����ֵ����������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����</returns>
        private double HHVBARS(CVariable var) {
            //��ȡ����
            int n = (int)getValue(var.m_parameters[1]);
            CVariable cParam = var.m_parameters[0];
            int closeField = cParam.m_field;
            int closeFieldIndex = cParam.m_fieldIndex;
            if (closeFieldIndex == -1) {
                if (cParam.m_tempFields == null) {
                    cParam.createTempFields(0);
                }
                closeField = cParam.m_tempFields[0];
                closeFieldIndex = cParam.m_tempFieldsIndex[0];
                double close = getValue(cParam);
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //��������
            double[] higharray = m_dataSource.DATA_ARRAY(closeField, m_index, n);
            double result = 0;
            if (higharray.Length > 0) {
                int mIndex = 0;
                double close = 0;
                for (int i = 0; i < higharray.Length; i++) {
                    if (i == 0) {
                        close = higharray[i];
                        mIndex = 0;
                    }
                    else {
                        if (higharray[i] > close) {
                            close = higharray[i];
                            mIndex = i;
                        }
                    }
                }
                result = higharray.Length - mIndex - 1;
            }
            return result;
        }

        /// <summary>
        /// ����Сʱ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>Сʱ</returns>
        private int HOUR(CVariable var) {
            return FCStr.convertNumToDate(m_dataSource.getXValue(m_index)).Hour;
        }

        /// <summary>
        /// ѡ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private double IF(CVariable var) {
            double result = 0;
            int pLen = var.m_parameters.Length;
            for (int i = 0; i < pLen; i++) {
                result = getValue(var.m_parameters[i]);
                if (i % 2 == 0) {
                    if (result == 0) {
                        i++;
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            deleteTempVars(var);
            return result;
        }

        /// <summary>
        /// ��ѡ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ѡ����</returns>
        private double IFN(CVariable var) {
            double result = 0;
            int pLen = var.m_parameters.Length;
            for (int i = 0; i < pLen; i++) {
                result = getValue(var.m_parameters[i]);
                if (i % 2 == 0) {
                    if (result != 0) {
                        i++;
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            deleteTempVars(var);
            return result;
        }

        /// <summary>
        /// ������X����ֵ��С������ӽ�������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ӽ�������</returns>
        private double INTPART(CVariable var) {
            double result = getValue(var.m_parameters[0]);
            if (result != 0) {
                int intResult = (int)result;
                double sub = Math.Abs(result - intResult);
                if (sub >= 0.5) {
                    if (result > 0) {
                        result = intResult - 1;
                    }
                    else {
                        result = intResult + 1;
                    }
                }
                else {
                    result = intResult;
                }
            }
            return result;
        }

        /// <summary>
        /// �ж��Ƿ��������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�Ƿ��������</returns>
        private int LAST(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            int m = (int)getValue(var.m_parameters[2]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            if (m < 0) {
                m = m_dataSource.RowsCount;
            }
            else if (m > m_index + 1) {
                m = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 1;
            for (int i = m; i < n; i++) {
                m_index = tempIndex - m;
                if (getValue(var.m_parameters[0]) <= 0) {
                    result = 0;
                    break;
                }
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// ����ָ���ֶ�һ�������ڵ���Сֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��Сֵ</returns>
        private double LLV(CVariable var) {
            //��ȡ����
            int n = (int)getValue(var.m_parameters[1]);
            CVariable cParam = var.m_parameters[0];
            int closeField = cParam.m_field;
            int closeFieldIndex = cParam.m_fieldIndex;
            if (closeField == FCDataTable.NULLFIELD) {
                if (cParam.m_tempFields == null) {
                    cParam.createTempFields(0);
                }
                closeField = cParam.m_tempFields[0];
                closeFieldIndex = cParam.m_tempFieldsIndex[0];
                double close = getValue(cParam);
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            double[] lowarray = m_dataSource.DATA_ARRAY(closeField, m_index, n);
            return FCScript.minValue(lowarray, lowarray.Length);
        }

        /// <summary>
        /// ����ָ���ֶ�һ�������ڵ���Сֵ������������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����</returns>
        private double LLVBARS(CVariable var) {
            //��ȡ����
            int n = (int)getValue(var.m_parameters[1]);
            CVariable cParam = var.m_parameters[0];
            int closeField = cParam.m_field;
            int closeFieldIndex = cParam.m_fieldIndex;
            if (closeField == FCDataTable.NULLFIELD) {
                if (cParam.m_tempFields == null) {
                    cParam.createTempFields(0);
                }
                closeField = cParam.m_tempFields[0];
                closeFieldIndex = cParam.m_tempFieldsIndex[0];
                double close = getValue(cParam);
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //��������
            double[] lowarray = m_dataSource.DATA_ARRAY(closeField, m_index, n);
            double result = 0;
            if (lowarray.Length > 0) {
                int mIndex = 0;
                double close = 0;
                for (int i = 0; i < lowarray.Length; i++) {
                    if (i == 0) {
                        close = lowarray[i];
                        mIndex = 0;
                    }
                    else {
                        if (lowarray[i] < close) {
                            close = lowarray[i];
                            mIndex = i;
                        }
                    }
                }
                result = lowarray.Length - mIndex - 1;
            }
            return result;
        }

        /// <summary>
        /// ���㳣�ö���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���ö���</returns>
        private double LOG(CVariable var) {
            return Math.Log10(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ������ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���ƶ�ƽ��</returns>
        private double MA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            CVariable cParam = var.m_parameters[0];
            double close = getValue(cParam);
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            int closeFieldIndex = cParam.m_fieldIndex;
            if (closeFieldIndex == -1) {
                if (var.m_tempFields == null) {
                    var.createTempFields(1);
                }
                closeFieldIndex = var.m_tempFieldsIndex[0];
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //����ָ��
            double result = movingAverage(m_index, n, close, getDatas(closeFieldIndex, var.m_fieldIndex, m_index - 1, n));
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// �������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���ֵ</returns>
        private double MAX(CVariable var) {
            //��ȡ����ֵ
            double left = getValue(var.m_parameters[0]);
            //��ȡ�Ҳ��ֵ
            double right = getValue(var.m_parameters[1]);
            if (left >= right) {
                return left;
            }
            else {
                return right;
            }
        }

        /// <summary>
        /// ����ָ���ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ָ���ƶ�ƽ��</returns>
        private double MEMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            double lastMema = 0;
            if (m_index > 0) {
                lastMema = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            //����ָ��
            double result = simpleMovingAverage(close, lastMema, n, 1);
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// ������Сֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��С�ٻ�ֵ</returns>
        private double MIN(CVariable var) {
            //��ȡ����ֵ
            double left = getValue(var.m_parameters[0]);
            //��ȡ�Ҳ��ֵ
            double right = getValue(var.m_parameters[1]);
            if (left <= right) {
                return left;
            }
            else {
                return right;
            }
        }

        /// <summary>
        /// ���ط���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����</returns>
        private int MINUTE(CVariable var) {
            return FCStr.convertNumToDate(m_dataSource.getXValue(m_index)).Minute;
        }

        /// <summary>
        /// ����ģ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ģ</returns>
        private double MOD(CVariable var) {
            //��ȡ����ֵ
            double left = getValue(var.m_parameters[0]);
            //��ȡ�Ҳ��ֵ
            double right = getValue(var.m_parameters[1]);
            if (right != 0) {
                return left % right;
            }
            return 0;
        }

        /// <summary>
        /// �����·�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�·�</returns>
        private int MONTH(CVariable var) {
            return FCStr.convertNumToDate(m_dataSource.getXValue(m_index)).Month;
        }

        /// <summary>
        /// �����Ƿ��������X>Y
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�Ƿ����</returns>
        private int NDAY(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[2]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 1;
            for (int i = 0; i < n; i++) {
                if (getValue(var.m_parameters[0]) <= getValue(var.m_parameters[1])) {
                    result = 0;
                    break;
                }
                m_index--;
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// ��ֵΪ0ʱ����1,���򷵻�0
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>1��0</returns>
        private int NOT(CVariable var) {
            double value = getValue(var.m_parameters[0]);
            if (value == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>0</returns>
        private double POLYLINE(CVariable var) {
            if (m_div != null) {
                CVariable cond = var.m_parameters[0];
                CVariable price = var.m_parameters[1];
                PolylineShape polylineShape = null;
                if (var.m_polylineShape == null) {
                    //��ȡ��ɫ�Ϳ��
                    String strColor = "COLORAUTO";
                    String strLineWidth = "LINETHICK";
                    bool dotLine = false;
                    for (int i = 2; i < var.m_parameters.Length; i++) {
                        String strParam = var.m_parameters[i].m_expression;
                        if (strParam.IndexOf("COLOR") == 0) {
                            strColor = strParam;
                        }
                        else if (strParam.IndexOf("LINETHICK") == 0) {
                            strLineWidth = strParam;
                        }
                        else if (strParam.IndexOf("DOTLINE") == 0) {
                            dotLine = true;
                        }
                    }
                    polylineShape = new PolylineShape();
                    m_div.addShape(polylineShape);
                    //��������
                    polylineShape.AttachVScale = m_attachVScale;
                    polylineShape.Color = getColor(strColor);
                    polylineShape.Width = getLineWidth(strLineWidth);
                    var.createTempFields(1);
                    polylineShape.ColorField = var.m_tempFields[0];
                    polylineShape.FieldText = price.m_fieldText;
                    if (dotLine) {
                        polylineShape.Style = PolylineStyle.DotLine;
                    }
                    var.m_polylineShape = polylineShape;
                }
                else {
                    polylineShape = var.m_polylineShape;
                }
                //��Ӽ۸��ֶ�
                if (price.m_expression != null && price.m_expression.Length > 0) {
                    if (polylineShape.FieldName == FCDataTable.NULLFIELD) {
                        if (price.m_field != FCDataTable.NULLFIELD) {
                            polylineShape.FieldName = price.m_field;
                        }
                        else {
                            price.createTempFields(1);
                            polylineShape.FieldName = price.m_tempFields[0];
                        }
                        for (int i = 2; i < var.m_parameters.Length; i++) {
                            String strParam = var.m_parameters[i].m_expression;
                            if (strParam == "DRAWTITLE") {
                                if (polylineShape.FieldText != null) {
                                    m_div.TitleBar.Titles.add(new CTitle(polylineShape.FieldName, polylineShape.FieldText, polylineShape.Color, 2, true));
                                }
                            }
                        }
                    }
                    if (price.m_tempFieldsIndex != null) {
                        double value = getValue(price);
                        m_dataSource.set3(m_index, price.m_tempFieldsIndex[0], value);
                    }
                }
                //��������
                double dCond = 1;
                if (cond.m_expression != null && cond.m_expression.Length > 0 && cond.m_expression != "1") {
                    dCond = getValue(cond);
                    if (dCond != 1) {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], -10000);
                    }
                    else {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], 1);
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����</returns>
        private double POW(CVariable var) {
            //��ȡ����ֵ
            double left = getValue(var.m_parameters[0]);
            //��ȡ�Ҳ��ֵ
            double right = getValue(var.m_parameters[1]);
            return Math.Pow(left, right);
        }

        /// <summary>
        /// ��ȡ�����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�����</returns>
        private int RAND(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[0]);
            return m_random.Next(0, n + 1);
        }

        /// <summary>
        /// ��ȡǰ��������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ǰ��������ֵ</returns>
        private double REF(CVariable var) {
            //��ȡ����
            int param = (int)getValue(var.m_parameters[1]);
            param = m_index - param;
            double result = 0;
            if (param >= 0) {
                int tempIndex = m_index;
                m_index = param;
                result = getValue(var.m_parameters[0]);
                m_index = tempIndex;
            }
            return result;
        }

        /// <summary>
        /// ����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ֵ</returns>
        private double RETURN(CVariable var) {
            m_resultVar = null;
            m_result = getValue(var.m_parameters[0]);
            if (m_tempVars.containsKey(var.m_parameters[0].m_field)) {
                m_resultVar = copyTempVar(m_tempVars.get(var.m_parameters[0].m_field));
            }
            else {
                if (var.m_parameters[0].m_expression.IndexOf('\'') == 0) {
                    m_resultVar = new CVar();
                    m_resultVar.m_type = 1;
                    m_resultVar.m_str = var.m_parameters[0].m_expression;
                }
            }
            m_break = 1;
            return m_result;
        }

        /// <summary>
        /// ȡ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ֵ</returns>
        private double REVERSE(CVariable var) {
            return -getValue(var.m_parameters[0]);
        }

        /// <summary>
        /// ������������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��������ֵ</returns>
        private double ROUND(CVariable var) {
            return Math.Round(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ����������ָ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>������ָ��</returns>
        private double SAR(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[2]);
            double s = getValue(var.m_parameters[3]) / 100;
            double m = getValue(var.m_parameters[4]) / 100;
            //��ȡ������Ҫ��ֵ
            double high = 0, low = 0;
            CVariable hParam = var.m_parameters[0];
            CVariable lParam = var.m_parameters[1];
            high = getValue(hParam);
            low = getValue(lParam);
            //������ʱ����
            if (var.m_tempFields == null) {
                if (hParam.m_field == FCDataTable.NULLFIELD || lParam.m_field == FCDataTable.NULLFIELD) {
                    var.createTempFields(4);
                }
                else {
                    var.createTempFields(2);
                }
            }
            int highField = hParam.m_field;
            int highFieldIndex = hParam.m_fieldIndex;
            if (highField == FCDataTable.NULLFIELD) {
                highField = var.m_tempFields[2];
                highFieldIndex = var.m_tempFieldsIndex[2];
                m_dataSource.set3(m_index, highFieldIndex, high);
            }
            int lowField = lParam.m_field;
            int lowFieldIndex = lParam.m_fieldIndex;
            if (lowField == FCDataTable.NULLFIELD) {
                lowField = var.m_tempFields[3];
                lowFieldIndex = var.m_tempFieldsIndex[3];
                m_dataSource.set3(m_index, lowFieldIndex, low);
            }
            double[] high_list = m_dataSource.DATA_ARRAY(highField, m_index - 1, n);
            double[] low_list = m_dataSource.DATA_ARRAY(lowField, m_index - 1, n);
            double hhv = FCScript.maxValue(high_list, high_list.Length);
            double llv = FCScript.minValue(low_list, low_list.Length);
            int lastState = 0;
            double lastSar = 0;
            double lastAf = 0;
            if (m_index > 0) {
                lastState = (int)m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[0]);
                lastSar = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
                lastAf = m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[1]);
            }
            int state = 0;
            double af = 0, sar = 0;
            //����ָ��
            stopAndReverse(m_index, n, s, m, high, low, hhv, llv, lastState, lastSar, lastAf, ref state, ref af, ref sar);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[1], af);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], state);
            m_dataSource.set3(m_index, var.m_fieldIndex, sar);
            return sar;
        }

        /// <summary>
        /// ���ñ�����ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private double SET(CVariable var) {
            int pLen = var.m_parameters.Length;
            for (int i = 0; i < pLen; i++) {
                if (i % 2 == 0) {
                    CVariable variable = var.m_parameters[i];
                    CVariable parameter = var.m_parameters[i + 1];
                    setVariable(variable, parameter);
                }
            }
            return 0;
        }

        /// <summary>
        /// �������0�򷵻�1,���С��0�򷵻أ�1�����򷵻�0
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>1,0,-1</returns>
        private int SIGN(CVariable var) {
            double value = getValue(var.m_parameters[0]);
            if (value > 0) {
                return 1;
            }
            else if (value < 0) {
                return -1;
            }
            return 0;
        }

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        private double SIN(CVariable var) {
            return Math.Sin(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// �����ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�ƶ�ƽ��</returns>
        private double SMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            int m = (int)getValue(var.m_parameters[2]);
            double lastSma = 0;
            if (m_index > 0) {
                lastSma = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            //����ָ��
            double result = simpleMovingAverage(close, lastSma, n, m);
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// ����ƽ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ƽ����</returns>
        private double SQRT(CVariable var) {
            return Math.Sqrt(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ����ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ƽ��</returns>
        private double SQUARE(CVariable var) {
            double result = getValue(var.m_parameters[0]);
            result = result * result;
            return result;
        }

        /// <summary>
        /// �����׼��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��׼��</returns>
        private double STD(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int p = (int)getValue(var.m_parameters[1]);
            CVariable cParam = var.m_parameters[0];
            double close = getValue(cParam);
            int closeField = cParam.m_field;
            int closeFieldIndex = cParam.m_fieldIndex;
            if (closeField == FCDataTable.NULLFIELD) {
                if (var.m_tempFields == null) {
                    var.createTempFields(1);
                }
                closeField = var.m_tempFields[0];
                closeFieldIndex = var.m_tempFieldsIndex[0];
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //��ȡ������Ҫ��ֵ
            double[] list = m_dataSource.DATA_ARRAY(closeField, m_index, p);
            double avg = 0;
            double sum = 0;
            if (list != null && list.Length > 0) {
                for (int i = 0; i < list.Length; i++) {
                    sum += list[i];
                }
                avg = sum / list.Length;
            }
            double result = standardDeviation(list, list.Length, avg, 1);
            return result;
        }

        /// <summary>
        /// �����״ͼ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>0</returns>
        private double STICKLINE(CVariable var) {
            if (m_div != null) {
                //��ȡ����
                CVariable cond = var.m_parameters[0];
                CVariable price1 = var.m_parameters[1];
                CVariable price2 = var.m_parameters[2];
                CVariable width = var.m_parameters[3];
                CVariable empty = var.m_parameters[4];
                BarShape barShape = null;
                if (var.m_barShape == null) {
                    barShape = new BarShape();
                    m_div.addShape(barShape);
                    //��������
                    barShape.AttachVScale = m_attachVScale;
                    barShape.FieldText = price1.m_fieldText;
                    barShape.FieldText2 = price2.m_fieldText;
                    CVariable color = null;
                    for (int i = 5; i < var.m_parameters.Length; i++) {
                        String strParam = var.m_parameters[i].m_expression;
                        if (strParam.IndexOf("COLOR") == 0) {
                            color = var.m_parameters[i];
                            break;
                        }
                    }
                    if (color != null) {
                        barShape.UpColor = getColor(color.m_expression);
                        barShape.DownColor = getColor(color.m_expression);
                    }
                    else {
                        barShape.UpColor = FCColor.argb(255, 82, 82);
                        barShape.DownColor = FCColor.argb(82, 255, 255);
                    }
                    barShape.Style = BarStyle.Line;
                    var.createTempFields(1);
                    barShape.StyleField = var.m_tempFields[0];
                    barShape.LineWidth = (int)Math.Round(FCStr.convertStrToDouble(width.m_expression));
                    var.m_barShape = barShape;
                }
                else {
                    barShape = var.m_barShape;
                }
                //��Ӽ۸�һ�ֶ�
                if (price1.m_expression != null && price1.m_expression.Length > 0) {
                    if (barShape.FieldName == FCDataTable.NULLFIELD) {
                        if (price1.m_field != FCDataTable.NULLFIELD) {
                            barShape.FieldName = price1.m_field;
                        }
                        else {
                            price1.createTempFields(1);
                            barShape.FieldName = price1.m_tempFields[0];
                        }
                        for (int i = 5; i < var.m_parameters.Length; i++) {
                            String strParam = var.m_parameters[i].m_expression;
                            if (strParam == "DRAWTITLE") {
                                if (barShape.FieldText != null) {
                                    m_div.TitleBar.Titles.add(new CTitle(barShape.FieldName, barShape.FieldText, barShape.DownColor, 2, true));
                                }
                                break;
                            }
                        }
                    }
                    if (price1.m_tempFieldsIndex != null) {
                        double value = getValue(price1);
                        m_dataSource.set3(m_index, price1.m_tempFieldsIndex[0], value);
                    }
                }
                //��Ӽ۸���ֶ�
                if (price2.m_expression != null && price2.m_expression.Length > 0 && price2.m_expression != "0") {
                    if (price2.m_field != FCDataTable.NULLFIELD) {
                        barShape.FieldName2 = price2.m_field;
                    }
                    else {
                        price2.createTempFields(1);
                        barShape.FieldName2 = price2.m_tempFields[0];
                    }
                    if (price2.m_tempFieldsIndex != null) {
                        double value = getValue(price2);
                        m_dataSource.set3(m_index, price2.m_tempFieldsIndex[0], value);
                    }
                }
                //��������
                double dCond = 1;
                if (cond.m_expression != null && cond.m_expression.Length > 0 && cond.m_expression != "1") {
                    dCond = getValue(cond);
                    if (dCond != 1) {
                        m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], -10000);
                    }
                    else {
                        int dEmpty = 2;
                        if (empty.m_expression != null && empty.m_expression.Length > 0) {
                            dEmpty = (int)getValue(empty);
                            m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], dEmpty);
                        }
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��</returns>
        private double SUM(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            int closeFieldIndex = var.m_parameters[0].m_fieldIndex;
            if (closeFieldIndex == -1) {
                if (var.m_tempFields == null) {
                    var.createTempFields(1);
                }
                closeFieldIndex = var.m_tempFieldsIndex[0];
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            if (n == 0) {
                n = m_index + 1;
            }
            //����ָ��
            double result = sumilationValue(m_index, n, close, getDatas(closeFieldIndex, var.m_fieldIndex, m_index - 1, n));
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// ��������ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����ֵ</returns>
        private double TAN(CVariable var) {
            return Math.Tan(getValue(var.m_parameters[0]));
        }

        /// <summary>
        /// ȡ�ø����ڵ�ʱ��,������������������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ʱ��</returns>
        private double TIME(CVariable var) {
            int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, ms = 0;
            FCStr.getDateByNum(m_dataSource.getXValue(m_index), ref year, ref month, ref day, ref hour, ref minute, ref second, ref ms);
            return hour * 100 + minute;
        }

        /// <summary>
        /// ȡ�ø����ڵ�ʱ����,������������������.
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>ʱ����</returns>
        private double TIME2(CVariable var) {
            int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, ms = 0;
            FCStr.getDateByNum(m_dataSource.getXValue(m_index), ref year, ref month, ref day, ref hour, ref minute, ref second, ref ms);
            return hour * 10000 + minute * 100 + second;
        }

        /// <summary>
        /// ����ݹ��ƶ�ƽ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�ݹ��ƶ�ƽ��</returns>
        private double TMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            int m = (int)getValue(var.m_parameters[2]);
            //����ָ��
            double lastTma = 0;
            if (m_index > 0) {
                lastTma = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            double result = n * lastTma + m * close;
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// �����Ƿ�����������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>�Ƿ�����������</returns>
        private int UPNDAY(CVariable var) {
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[0]);
            if (n < 0) {
                n = m_dataSource.RowsCount;
            }
            else if (n > m_index + 1) {
                n = m_index + 1;
            }
            int tempIndex = m_index;
            int result = 1;
            for (int i = 0; i < n; i++) {
                double right = getValue(var.m_parameters[0]);
                m_index--;
                double left = m_index >= 0 ? getValue(var.m_parameters[0]) : 0;
                if (right <= left) {
                    result = 0;
                    break;
                }
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// ����������ʱ,ȡ��ǰֵ,����ȡ�ϸ�ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ֵ</returns>
        private double VALUEWHEN(CVariable var) {
            int n = m_dataSource.RowsCount;
            int tempIndex = m_index;
            double result = 0;
            for (int i = 0; i < n; i++) {
                double value = getValue(var.m_parameters[0]);
                if (value == 1) {
                    result = getValue(var.m_parameters[1]);
                    break;
                }
                m_index--;
            }
            m_index = tempIndex;
            return result;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��ֵ</returns>
        private double VAR(CVariable var) {
            double result = 0;
            int pLen = var.m_parameters.Length;
            for (int i = 0; i < pLen; i++) {
                if (i % 2 == 0) {
                    CVariable name = var.m_parameters[i];
                    CVariable value = var.m_parameters[i + 1];
                    int id = name.m_field;
                    CVar newCVar = m_varFactory.createVar();
                    result = newCVar.onCreate(this, name, value);
                    if (newCVar.m_type == 1) {
                        name.m_functionID = -2;
                    }
                    if (m_tempVars.containsKey(id)) {
                        CVar cVar = m_tempVars.get(id);
                        newCVar.m_parent = cVar;
                    }
                    m_tempVars.put(id, newCVar);
                }
            }
            return result;
        }

        /// <summary>
        /// ִ��WHILEѭ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>״̬</returns>
        private int WHILE(CVariable var) {
            int pLen = var.m_parameters.Length;
            if (pLen > 1) {
                while (true) {
                    if (getValue(var.m_parameters[0]) <= 0) {
                        break;
                    }
                    for (int i = 1; m_break == 0 && i < pLen; i++) {
                        getValue(var.m_parameters[i]);
                    }
                    if (m_break > 0) {
                        if (m_break == 3) {
                            m_break = 0;
                            deleteTempVars(var);
                            continue;
                        }
                        else {
                            m_break = 0;
                            deleteTempVars(var);
                            break;
                        }
                    }
                    else {
                        deleteTempVars(var);
                    }
                }
            }
            return 0;
        }

        /// <summary>
        /// �����Ȩ�ƶ�ƽ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>��Ȩ�ƶ�ƽ��</returns>
        private double WMA(CVariable var) {
            //��ȡ������Ҫ��ֵ
            double close = getValue(var.m_parameters[0]);
            //��ȡ������Ҫ�Ĳ���
            int n = (int)getValue(var.m_parameters[1]);
            int m = (int)getValue(var.m_parameters[2]);
            //����ָ��
            double lastWma = 0;
            if (m_index > 0) {
                lastWma = m_dataSource.get3(m_index - 1, var.m_fieldIndex);
            }
            double result = weightMovingAverage(n, m, close, lastWma);
            m_dataSource.set3(m_index, var.m_fieldIndex, result);
            return result;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int YEAR(CVariable var) {
            return FCStr.convertNumToDate(m_dataSource.getXValue(m_index)).Year;
        }

        /// <summary>
        /// ����֮�ַ�ת
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>֮�ַ�ת</returns>
        private double ZIG(CVariable var) {
            double sxp = 0, exp = 0;
            int state = 0, sxi = 0, exi = 0;
            //��ȡ������Ҫ�Ĳ���
            double p = getValue(var.m_parameters[1]);
            //��ȡ������Ҫ��ֵ
            CVariable cParam = var.m_parameters[0];
            double close = getValue(cParam);
            int closeFieldIndex = cParam.m_fieldIndex;
            //�����ֶ�
            if (var.m_tempFields == null) {
                if (closeFieldIndex == -1) {
                    var.createTempFields(6);
                }
                else {
                    var.createTempFields(5);
                }
            }
            if (closeFieldIndex == -1) {
                closeFieldIndex = var.m_tempFieldsIndex[5];
                m_dataSource.set3(m_index, closeFieldIndex, close);
            }
            //��ȡ��һ��¼��ֵ
            if (m_index > 0) {
                state = (int)m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[0]);
                exp = m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[1]);
                sxp = m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[2]);
                sxi = (int)m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[3]);
                exi = (int)m_dataSource.get3(m_index - 1, var.m_tempFieldsIndex[4]);
            }
            int cStart = -1, cEnd = -1;
            double k = 0, b = 0;
            zigZag(m_index, close, p, ref sxp, ref sxi, ref exp, ref exi, ref state, ref cStart, ref cEnd, ref k, ref b);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[0], state);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[1], exp);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[2], sxp);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[3], sxi);
            m_dataSource.set3(m_index, var.m_tempFieldsIndex[4], exi);
            if (cStart != -1 && cEnd != -1) {
                return 1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// �����ַ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int STR_CONTACT(CVariable var) {
            int pLen = var.m_parameters.Length;
            String text = "'";
            for (int i = 0; i < pLen; i++) {
                text += getText(var.m_parameters[i]);
            }
            text += "'";
            m_resultVar = new CVar();
            m_resultVar.m_type = 1;
            m_resultVar.m_str = text;
            return text.Length;
        }

        /// <summary>
        /// �����ַ����г������ֵ�λ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>λ��</returns>
        private int STR_FIND(CVariable var) {
            return getText(var.m_parameters[0]).IndexOf(getText(var.m_parameters[1]));
        }

        /// <summary>
        /// �Ƚ��ַ����Ƿ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>λ��</returns>
        private int STR_EQUALS(CVariable var) {
            int result = 0;
            if (getText(var.m_parameters[0]) == getText(var.m_parameters[1])) {
                result = 1;
            }
            return result;
        }

        /// <summary>
        /// �����ַ��������������ֵ�λ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>λ��</returns>
        private int STR_FINDLAST(CVariable var) {
            return getText(var.m_parameters[0]).LastIndexOf(getText(var.m_parameters[1]));
        }

        /// <summary>
        /// ��ȡ�ַ����ĳ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>����</returns>
        private int STR_LENGTH(CVariable var) {
            return getText(var.m_parameters[0]).Length;
        }

        /// <summary>
        /// ��ȡ�ַ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int STR_SUBSTR(CVariable var) {
            int pLen = var.m_parameters.Length;
            if (pLen == 2) {
                m_resultVar = new CVar();
                m_resultVar.m_type = 1;
                m_resultVar.m_str = "'" + getText(var.m_parameters[0]).Substring((int)getValue(var.m_parameters[1])) + "'";
            }
            else if (pLen >= 3) {
                m_resultVar = new CVar();
                m_resultVar.m_type = 1;
                m_resultVar.m_str = "'" + getText(var.m_parameters[0]).Substring((int)getValue(var.m_parameters[1]), (int)getValue(var.m_parameters[2])) + "'";
            }
            return 0;
        }

        /// <summary>
        /// �滻�ַ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int STR_REPLACE(CVariable var) {
            m_resultVar = new CVar();
            m_resultVar.m_type = 1;
            m_resultVar.m_str = "'" + getText(var.m_parameters[0]).Replace(getText(var.m_parameters[1]), getText(var.m_parameters[2])) + "'";
            return 0;
        }

        /// <summary>
        /// �и��ַ���
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int STR_SPLIT(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int id = pName.m_field;
            if (m_tempVars.containsKey(id)) {
                ArrayList<String> list = m_tempVars.get(id).m_list;
                list.clear();
                String[] strs = getText(var.m_parameters[1]).Split(new String[] { getText(var.m_parameters[2]) }, StringSplitOptions.RemoveEmptyEntries);
                int strsSize = strs.Length;
                for (int i = 0; i < strsSize; i++) {
                    list.add(strs[i]);
                }
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// �ַ���ת��ΪСд
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int STR_TOLOWER(CVariable var) {
            m_resultVar = new CVar();
            m_resultVar.m_type = 1;
            m_resultVar.m_str = getText(var.m_parameters[0]).ToLower();
            return 0;
        }

        /// <summary>
        /// �ַ���ת��Ϊ��д
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int STR_TOUPPER(CVariable var) {
            m_resultVar = new CVar();
            m_resultVar.m_type = 1;
            m_resultVar.m_str = getText(var.m_parameters[0]).ToUpper();
            return 0;
        }

        /// <summary>
        /// ������ݵ�����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int LIST_ADD(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int listName = pName.m_field;
            if (m_tempVars.containsKey(listName)) {
                ArrayList<String> list = m_tempVars.get(listName).m_list;
                int pLen = var.m_parameters.Length;
                for (int i = 1; i < pLen; i++) {
                    list.add(getText(var.m_parameters[i]));
                }
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int LIST_CLEAR(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int listName = pName.m_field;
            if (m_tempVars.containsKey(listName)) {
                m_tempVars[listName].m_list.clear();
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// �Ӽ����л�ȡ����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int LIST_GET(CVariable var) {
            CVariable pName = var.m_parameters[1];
            int listName = pName.m_field;
            if (m_tempVars.containsKey(listName)) {
                ArrayList<String> list = m_tempVars.get(listName).m_list;
                int index = (int)getValue(var.m_parameters[2]);
                if (index < list.size()) {
                    String strValue = list[index];
                    CVariable variable = var.m_parameters[0];
                    int id = variable.m_field;
                    int type = variable.m_type;
                    switch (type) {
                        case 2:
                            double value = FCStr.convertStrToDouble(strValue);
                            m_dataSource.set3(m_index, variable.m_fieldIndex, value);
                            break;
                        default:
                            if (m_tempVars.containsKey(id)) {
                                CVar otherCVar = m_tempVars.get(id);
                                CVariable newVar = new CVariable(this);
                                newVar.m_expression = "'" + strValue + "'";
                                newVar.m_type = 1;
                                otherCVar.setValue(this, variable, newVar);
                            }
                            break;
                    }
                }
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// �򼯺��в�������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int LIST_INSERT(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int listName = pName.m_field;
            if (m_tempVars.containsKey(listName)) {
                m_tempVars.get(listName).m_list.Insert((int)getValue(var.m_parameters[1]), getText(var.m_parameters[2]));
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// �Ӽ������Ƴ�����
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int LIST_REMOVE(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int listName = pName.m_field;
            if (m_tempVars.containsKey(listName)) {
                m_tempVars.get(listName).m_list.removeAt((int)getValue(var.m_parameters[1]));
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// ��ȡ���ϵĴ�С
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int LIST_SIZE(CVariable var) {
            int size = 0;
            CVariable pName = var.m_parameters[0];
            int listName = pName.m_field;
            if (m_tempVars.containsKey(listName)) {
                size = m_tempVars.get(listName).m_list.size();
            }
            return size;
        }

        /// <summary>
        /// �����ϣ��
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_CLEAR(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                m_tempVars.get(mapName).m_map.clear();
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// ��ϣ���Ƿ������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_CONTAINSKEY(CVariable var) {
            int result = 0;
            CVariable pName = var.m_parameters[0];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                if (m_tempVars.get(mapName).m_map.containsKey(getText(var.m_parameters[1]))) {
                    result = 1;
                }
            }
            return result;
        }

        /// <summary>
        /// ��ȡ��ϣ���ֵ
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_GET(CVariable var) {
            CVariable pName = var.m_parameters[1];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                HashMap<String, String> map = m_tempVars.get(mapName).m_map;
                String key = getText(var.m_parameters[2]);
                if (map.containsKey(key)) {
                    String strValue = map.get(key);
                    CVariable variable = var.m_parameters[0];
                    int id = variable.m_field;
                    int type = variable.m_type;
                    switch (type) {
                        case 2:
                            double value = FCStr.convertStrToDouble(strValue);
                            m_dataSource.set3(m_index, variable.m_fieldIndex, value);
                            break;
                        default:
                            if (m_tempVars.containsKey(id)) {
                                CVar otherCVar = m_tempVars.get(id);
                                CVariable newVar = new CVariable(this);
                                newVar.m_type = 1;
                                newVar.m_expression = "'" + strValue + "'";
                                otherCVar.setValue(this, variable, newVar);
                            }
                            break;
                    }
                }
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// ��ȡ��ϣ��ļ�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_GETKEYS(CVariable var) {
            CVariable pName = var.m_parameters[1];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                int listName = var.m_parameters[0].m_field;
                if (m_tempVars.containsKey(listName)) {
                    HashMap<String, String> map = m_tempVars.get(mapName).m_map;
                    ArrayList<String> list = m_tempVars.get(listName).m_list;
                    list.clear();
                    foreach (String key in map.Keys) {
                        list.add(key);
                    }
                    return 1;
                }
            }
            return 0;
        }

        /// <summary>
        /// �ӹ�ϣ�����Ƴ�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_REMOVE(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                m_tempVars[mapName].m_map.remove(getText(var.m_parameters[1]));
                return 1;
            }
            return 0;
        }

        /// <summary>
        /// ���ϣ�����������
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_SET(CVariable var) {
            CVariable pName = var.m_parameters[0];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                m_tempVars.get(mapName).m_map.put(getText(var.m_parameters[1]), getText(var.m_parameters[2]));
            }
            return 0;
        }

        /// <summary>
        /// ��ȡ��ϣ��ĳߴ�
        /// </summary>
        /// <param name="var">����</param>
        /// <returns>���</returns>
        private int MAP_SIZE(CVariable var) {
            int size = 0;
            CVariable pName = var.m_parameters[0];
            int mapName = pName.m_field;
            if (m_tempVars.containsKey(mapName)) {
                size = m_tempVars.get(mapName).m_map.size();
            }
            return size;
        }

        public static double avgValue(double[] list, int length) {
            int i = 0;
            double sum = 0;
            if (length > 0) {
                for (i = 0; i < length; i++) {
                    sum += list[i];
                }
                return sum / length;
            }
            return 0;
        }

        public static double avedev(double value, double[] listForAvedev, int listForAvedev_length, double avg) {
            int i = 0; ;
            if (listForAvedev_length > 0) {
                double sum = Math.Abs(value - avg);
                for (i = 0; i < listForAvedev_length; i++) {
                    sum += Math.Abs(listForAvedev[i] - avg);
                }
                return sum / listForAvedev_length;
            }
            else {
                return 0;
            }
        }

        public static double exponentialMovingAverage(int n, double value, double lastEMA) {
            return (value * 2 + lastEMA * (n - 1)) / (n + 1);
        }

        public static int fibonacciValue(int index) {
            if (index < 1) {
                return 0;
            }
            else {
                int[] vList = new int[index];
                int i = 0, result = 0;
                for (i = 0; i <= index - 1; i++) {
                    if (i == 0 || i == 1) {
                        vList[i] = 1;
                    }
                    else {
                        vList[i] = vList[i - 1] + vList[i - 2];
                    }
                }
                result = vList[index - 1];
                return result;
            }
        }

        public static void linearRegressionEquation(double[] list, int length, ref float k, ref float b) {
            int i = 0;
            double sumX = 0;
            double sumY = 0;
            double sumUp = 0;
            double sumDown = 0;
            double xAvg = 0;
            double yAvg = 0;
            k = 0;
            b = 0;
            if (length > 1) {
                for (i = 0; i < length; i++) {
                    sumX += i + 1;
                    sumY += list[i];
                }
                xAvg = sumX / length;
                yAvg = sumY / length;
                for (i = 0; i < length; i++) {
                    sumUp += (i + 1 - xAvg) * (list[i] - yAvg);
                    sumDown += (i + 1 - xAvg) * (i + 1 - xAvg);
                }
                k = (float)(sumUp / sumDown);
                b = (float)(yAvg - k * xAvg);
            }
        }

        public static double maxValue(double[] list, int length) {
            double max = 0;
            int i = 0;
            for (i = 0; i < length; i++) {
                if (i == 0) {
                    max = list[i];
                }
                else {
                    if (max < list[i]) {
                        max = list[i];
                    }
                }
            }
            return max;
        }

        public static double minValue(double[] list, int length) {
            double min = 0;
            int i = 0;
            for (i = 0; i < length; i++) {
                if (i == 0) {
                    min = list[i];
                }
                else {
                    if (min > list[i]) {
                        min = list[i];
                    }
                }
            }
            return min;
        }

        public static double movingAverage(int index, int n, double value, LPDATA last_MA) {
            double sum = 0;
            if (last_MA.mode == 0) {
                sum = last_MA.sum + value;
            }
            else {
                if (index > n - 1) {
                    sum = last_MA.lastvalue * n;
                    sum -= last_MA.first_value;
                }
                else {
                    sum = last_MA.lastvalue * index;
                    n = index + 1;
                }
                sum += value;
            }
            return sum / n;
        }

        public static double simpleMovingAverage(double close, double lastSma, int n, int m) {
            return (close * m + lastSma * (n - m)) / n;
        }

        public static double standardDeviation(double[] list, int length, double avg, double standardDeviation) {
            int i = 0;
            if (length > 0) {
                double sum = 0;
                for (i = 0; i < length; i++) {
                    sum += (list[i] - avg) * (list[i] - avg);
                }
                return standardDeviation * Math.Sqrt(sum / length);
            }
            else {
                return 0;
            }
        }

        public static double sumilationValue(int index, int n, double value, LPDATA last_SUM) {
            double sum = 0;
            if (last_SUM.mode == 0) {
                sum = last_SUM.sum + value;
            }
            else {
                sum = last_SUM.lastvalue;
                if (index > n - 1) {
                    sum -= last_SUM.first_value;
                }
                sum += value;
            }
            return sum;
        }

        public static double sumValue(double[] list, int length) {
            double sum = 0;
            int i = 0;
            for (i = 0; i < length; i++) {
                sum += list[i];
            }
            return sum;
        }

        public static void stopAndReverse(int index, int n, double s, double m, double high, double low, double hhv, double llv, int last_state,
       double last_sar, double last_af, ref int state, ref double af, ref double sar) {
            if (index >= n) {
                if (index == n) {
                    af = s;
                    if (llv < low) {
                        sar = llv;
                        state = 1;
                    }
                    if (hhv > high) {
                        sar = hhv;
                        state = 2;
                    }
                }
                else {
                    state = last_state;
                    af = last_af;
                    if (state == 1) {
                        if (high > hhv) {
                            af += s;
                            if (af > m) {
                                af = m;
                            }
                        }
                        sar = last_sar + af * (hhv - last_sar);
                        if (sar < low) {
                            state = 1;
                        }
                        else {
                            state = 3;
                        }
                    }
                    else if (state == 2) {
                        if (low < llv) {
                            af += s;
                            if (af > m) af = m;
                        }
                        sar = last_sar + af * (llv - last_sar);
                        if (sar > high) {
                            state = 2;
                        }
                        else {
                            state = 4;
                        }
                    }
                    else if (state == 3) {
                        sar = hhv;
                        if (sar > high) {
                            state = 2;
                        }
                        else {
                            state = 4;
                        }
                        af = s;
                    }
                    else if (state == 4) {
                        sar = llv;
                        if (sar < low) {
                            state = 1;
                        }
                        else {
                            state = 3;
                        }
                        af = s;
                    }
                }
            }
        }

        public static double weightMovingAverage(int n, int weight, double value, double lastWMA) {
            return (value * weight + (n - weight) * lastWMA) / n;
        }

        public static void zigZag(int index, double close, double p, ref double sxp, ref int sxi, ref double exp, ref int exi, ref int state,
                                     ref int cStart, ref int cEnd, ref double k, ref double b) {
            bool reverse = false;
            bool ex = false;
            if (index == 0) {
                sxp = close;
                exp = close;
            }
            else if (index == 1) {
                if (close >= exp) {
                    state = 0;
                }
                else {
                    state = 1;
                }
                exp = close;
                exi = 1;
            }
            else {
                if (state == 0) {
                    if (100 * (exp - close) / (exp) > p) {
                        reverse = true;
                    }
                    else if (close >= exp) {
                        ex = true;
                    }
                }
                else {
                    if (100 * (close - exp) / (exp) > p) {
                        reverse = true;
                    }
                    else if (close <= exp) {
                        ex = true;
                    }
                }
                if (reverse == true) {
                    if (state == 1) {
                        state = 0;
                    }
                    else {
                        state = 1;
                    }
                    k = (exp - sxp) / (exi - sxi);
                    b = exp - k * exi;
                    cStart = sxi;
                    cEnd = exi;
                    sxi = exi;
                    sxp = exp;
                    exi = index;
                    exp = close;
                }
                else if (ex == true) {
                    exp = close;
                    exi = index;
                    k = (exp - sxp) / (exi - sxi);
                    b = exp - k * exi;
                    cStart = sxi;
                    cEnd = exi;
                }
                else {
                    k = (close - exp) / (index - exi);
                    b = close - k * index;
                    cStart = exi;
                    cEnd = index;
                }
            }
        }
    }

    /// <summary>
    /// ��ѧ�������ݴ���ṹ
    /// </summary>
    public struct LPDATA {
        /// <summary>
        /// ����ֵ
        /// </summary>
        public double lastvalue;
        /// <summary>
        /// ��һ��ֵ
        /// </summary>
        public double first_value;
        /// <summary>
        /// ģʽ
        /// </summary>
        public int mode;
        /// <summary>
        /// ��
        /// </summary>
        public double sum;
    }
}
