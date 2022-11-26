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

namespace FaceCat {
    /// <summary>
    /// ������
    /// </summary>
    public class FCDataRow {
        /// <summary>
        /// ������
        /// </summary>
        public FCDataRow() {
            m_values = new CList<double>();
        }

        /// <summary>
        /// ������
        /// <param name="capacity">����</param>
        /// <param name="step">����</param>
        /// </summary>
        public FCDataRow(int capacity, int step) {
            m_values = new CList<double>();
            m_values.set_capacity(capacity);
            m_values.set_step(capacity);
        }

        /// <summary>
        /// ������
        /// </summary>
        /// <param name="ary">����</param>
        /// <param name="size">����</param>
        public FCDataRow(double[] ary, int size) {
            m_values = new CList<double>();
            m_values.addranges(ary, size);
        }

        /// <summary>
        /// ��������
        /// </summary>
        ~FCDataRow() {
            delete();
        }

        /// <summary>
        /// ֵ����
        /// </summary>
        private CList<double> m_values;

        /// <summary>
        /// �������
        /// </summary>
        public void clear() {
            if (m_values != null) {
                m_values.clear();
            }
        }

        /// <summary>
        /// ���ٶ���
        /// </summary>
        public void delete() {
            if (m_values != null) {
                m_values.clear();
                m_values = null;
            }
        }

        /// <summary>
        /// ���ռ�
        /// </summary>
        /// <param name="columns">����</param>
        public void fillEmpty(int columns) {
            if (m_values != null) {
                int size = m_values.size();
                if (size >= 0) {
                    for (int i = size; i < columns; i++) {
                        m_values.insert(i, double.NaN);
                    }
                }
            }
        }

        /// <summary>
        /// ��ȡ��ֵ
        /// </summary>
        /// <param name="index">����</param>
        /// <returns>��ֵ</returns>
        public double get(int index) {
            if (index != -1) {
                return m_values.get(index);
            }
            return double.NaN;
        }

        /// <summary>
        /// �Ƴ�
        /// </summary>
        /// <param name="index">����</param>
        public void remove(int index) {
            if (index != -1 && m_values != null) {
                m_values.remove_at(index);
            }
        }

        /// <summary>
        /// ����ֵ
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="value">ֵ</param>
        public void set(int index, double value) {
            m_values.set(index, value);
        }
    }

    /// <summary>
    /// �Զ�������Դ
    /// </summary>
    public class FCDataTable {
        /// <summary>
        /// ��������
        /// </summary>
        ~FCDataTable() {
            delete();
        }

        public static int NULLFIELD = -1;

        /// <summary>
        /// �е�����
        /// </summary>
        private int m_colsCapacity = 4;

        /// <summary>
        /// �е���������
        /// </summary>
        private int m_colsStep = 4;

        /// <summary>
        /// ������
        /// </summary>
        private CList<int[]> m_columns = new CList<int[]>();

        /// <summary>
        /// ��ֵ��
        /// </summary>
        private CList<double> m_keys = new CList<double>();

        /// <summary>
        /// ������
        /// </summary>
        private CList<FCDataRow> m_rows = new CList<FCDataRow>();

        /// <summary>
        /// �Զ��ֶ�
        /// </summary>
        private static int m_autoField = 10000;

        /// <summary>
        /// ��ȡ
        /// </summary>
        /// <returns></returns>
        public static int AutoField {
            get { return m_autoField++; }
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        public virtual int ColumnsCount {
            get { return m_columns.size(); }
        }

        private bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        public virtual int RowsCount {
            get {
                if (m_keys.size() != 0) return m_keys.size();
                return 0;
            }
        }

        /// <summary>
        /// �����
        /// </summary>
        /// <param name="colName">����</param>
        public virtual void addColumn(int colName) {
            int[] column = new int[] { colName, m_columns.size() };
            if (m_columns.size() == 0) {
                m_columns.push_back(column);
            }
            else {
                int begin = 0;
                int end = m_columns.size() - 1;
                int sub = end - begin;
                while (sub > 1) {
                    int half = begin + sub / 2;
                    int hf = m_columns.get(half)[0];
                    if (hf > colName) {
                        end = half;
                    }
                    else if (hf < colName) {
                        begin = half;
                    }
                    sub = end - begin;
                }
                if (colName < m_columns.get(begin)[0]) {
                    m_columns.insert(begin, column);
                    fillEmpty();
                    return;
                }
                else if (colName > m_columns.get(end)[0]) {
                    m_columns.insert(end + 1, column);
                    fillEmpty();
                    return;
                }
                else {
                    m_columns.insert(begin + 1, column);
                    fillEmpty();
                    return;
                }
            }
        }

        /// <summary>
        /// �����ֵ����
        /// </summary>
        /// <param name="num">��ֵ</param>
        /// <param name="newRow">������</param>
        private FCDataRow addKey(double num) {
            if (m_keys.size() == 0 || num > m_keys.get(m_keys.size() - 1)) {
                m_keys.push_back(num);
                FCDataRow newRow = new FCDataRow(m_colsCapacity, m_colsStep);
                m_rows.push_back(newRow);
                return newRow;
            }
            else {
                int begin = 0;
                int end = m_keys.size() - 1;
                int sub = end - begin;
                while (sub > 1) {
                    int half = begin + sub / 2;
                    double hf = m_keys.get(half);
                    if (hf > num) {
                        end = half;
                    }
                    else if (hf < num) {
                        begin = half;
                    }
                    sub = end - begin;
                }
                if (num < m_keys.get(begin)) {
                    m_keys.insert(begin, num);
                    FCDataRow newRow = new FCDataRow(m_colsCapacity, m_colsStep);
                    m_rows.insert(begin, newRow);
                    return newRow;
                }
                else if (num > m_keys.get(end)) {
                    m_keys.insert(end + 1, num);
                    FCDataRow newRow = new FCDataRow(m_colsCapacity, m_colsStep);
                    m_rows.insert(end + 1, newRow);
                    return newRow;
                }
                else {
                    m_keys.insert(begin + 1, num);
                    FCDataRow newRow = new FCDataRow(m_colsCapacity, m_colsStep);
                    m_rows.insert(begin + 1, newRow);
                    return newRow;
                }
            }
        }

        /// <summary>
        /// ֱ�Ӳ���������
        /// </summary>
        /// <param name="pk">����</param>
        /// <param name="ary">����</param>
        /// <param name="size">����</param>
        public virtual void AddRow(double pk, double[] ary, int size) {
            m_keys.push_back(pk);
            FCDataRow row = new FCDataRow(ary, size);
            m_rows.push_back(row);
        }

        /// <summary>
        /// �������
        /// </summary>
        public virtual void clear() {
            if (m_keys != null) {
                m_keys.clear();
            }
            if (m_rows != null) {
                for (int i = 0; i < m_rows.size(); i++) {
                    FCDataRow row = m_rows.get(i);
                    if (row != null) {
                        row.delete();
                    }
                }
                m_rows.clear();
            }
        }

        /// <summary>
        /// ������Դ�л�ȡ֮ǰ��һ�����ݵ�����
        /// </summary>
        /// <param name="field">�ֶ�</param>
        /// <param name="index">��������</param>
        /// <param name="n">����</param>
        /// <returns>��ֵ����</returns>
        public virtual double[] DATA_ARRAY(int field, int index, int n) {
            if (index >= 0) {
                //��ȡ���鳤��
                int arraylength = n;
                //����Ŀ�ʼλ��
                int start = 0;
                if (index < n - 1) {
                    arraylength = index + 1;
                }
                else {
                    start = index - n + 1;
                }
                if (arraylength == -1) {
                    return new double[0];
                }
                double[] array = new double[arraylength];
                //ƴװ����
                int columnIndex = getColumnIndex(field);
                for (int i = start; i <= index; i++) {
                    array[i - start] = get3(i, columnIndex);
                }
                return array;
            }
            else {
                return new double[0];
            }
        }

        /// <summary>
        /// ������Դ
        /// </summary>
        public virtual void delete() {
            if (!m_isDeleted) {
                clear();
                if (m_columns != null) {
                    m_columns.delete();
                    m_columns = null;
                }
                if (m_keys != null) {
                    m_keys.delete();
                    m_keys = null;
                }
                if (m_rows != null) {
                    m_rows.delete();
                    m_rows = null;
                }
                m_isDeleted = true;
            }
        }

        /// <summary>
        /// ���հ�
        /// </summary>
        private void fillEmpty() {
            int colSize = m_columns.size();
            for (int i = 0; i < m_rows.size(); i++) {
                m_rows.get(i).fillEmpty(colSize);
            }
        }

        /// <summary>
        /// ��ȡ�е�����
        /// </summary>
        /// <param name="colName">����</param>
        /// <returns>����</returns>
        public virtual int getColumnIndex(int colName) {
            if (colName == FCDataTable.NULLFIELD || m_columns == null) {
                return -1;
            }
            int low = 0;
            int high = m_columns.size() - 1;
            while (low <= high) {
                int middle = (low + high) / 2;
                int[] hf = m_columns.get(middle);
                if (colName == hf[0]) {
                    return middle;
                }
                else if (colName > hf[0]) {
                    low = middle + 1;
                }
                else if (colName < hf[0]) {
                    high = middle - 1;
                }
            }
            return -1;
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="key">��</param>
        /// <returns>����</returns>
        public virtual int getRowIndex(double key) {
            if (m_keys == null) {
                return -1;
            }
            int low = 0;
            int high = m_keys.size() - 1;
            while (low <= high) {
                int middle = (low + high) / 2;
                double hf = m_keys.get(middle);
                if (key == hf) {
                    return middle;
                }
                else if (key > hf) {
                    low = middle + 1;
                }
                else if (key < hf) {
                    high = middle - 1;
                }
            }
            return -1;
        }

        /// <summary>
        /// ��ȡX���ֵ
        /// </summary>
        /// <param name="index">����</param>
        /// <returns>X���ֵ</returns>
        public virtual double getXValue(int index) {
            try {
                return m_keys.get(index);
            }
            catch {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="pk">����</param>
        /// <param name="colName">����</param>
        public virtual double get(double pk, int colName) {
            try {
                int rowIndex = getRowIndex(pk);
                int colIndex = getColumnIndex(colName);
                return m_rows.get(rowIndex).get(colIndex);
            }
            catch {
                return double.NaN;
            }
        }

        /// <summary>
        /// ����������������ȡ����
        /// </summary>
        /// <param name="rowIndex">����</param>
        /// <param name="colName">����</param>
        /// <returns>����</returns>
        public virtual double get2(int rowIndex, int colName) {
            try {
                if (rowIndex >= 0 && rowIndex < m_rows.size()) {
                    int colIndex = getColumnIndex(colName);
                    return m_rows.get(rowIndex).get(colIndex);
                }
                else {
                    return double.NaN;
                }
            }
            catch {
                return double.NaN;
            }
        }

        /// <summary>
        /// ��������������������ȡ����
        /// </summary>
        /// <param name="rowIndex">������</param>
        /// <param name="colIndex">������</param>
        /// <returns>����</returns>
        public virtual double get3(int rowIndex, int colIndex) {
            try {
                if (rowIndex >= 0 && rowIndex < m_rows.size()) {
                    return m_rows.get(rowIndex).get(colIndex);
                }
                else {
                    return double.NaN;
                }
            }
            catch {
                return double.NaN;
            }
        }

        /// <summary>
        /// �Ƴ�����
        /// </summary>
        /// <param name="pk">����</param>
        public virtual void remove(double pk) {
            try {
                int index = getRowIndex(pk);
                m_keys.remove_at(index);
                FCDataRow row = m_rows.get(index);
                row.clear();
                m_rows.remove_at(index);
            }
            catch { }
        }

        /// <summary>
        /// �Ƴ�ָ������������
        /// </summary>
        /// <param name="rowIndex">������</param>
        public virtual void removeAt(int rowIndex) {
            try {
                m_keys.remove_at(rowIndex);
                FCDataRow row = m_rows.get(rowIndex);
                row.clear();
                m_rows.remove_at(rowIndex);
            }
            catch { }
        }

        /// <summary>
        /// �Ƴ���
        /// </summary>
        /// <param name="colName">����</param>
        public virtual void removeColumn(int colName) {
            int colIndex = getColumnIndex(colName);
            if (colIndex != -1) {
                int colSize = m_columns.size();
                int removeIndex = -1;
                for (int i = 0; i < colSize; i++) {
                    int[] col = m_columns.get(i);
                    int name = col[0];
                    int index = col[1];
                    if (col[0] == colName) {
                        removeIndex = i;
                    }
                    else {
                        if (index > colIndex) {
                            m_columns.set(i, new int[] { name, index - 1 });
                        }
                    }
                }
                m_columns.remove_at(removeIndex);
                for (int i = 0; i < m_rows.size(); i++) {
                    m_rows.get(i).remove(colIndex);
                    m_rows.get(i).fillEmpty(m_columns.size());
                }
            }
        }

        /// <summary>
        /// ������ݣ�����Ϊ����
        /// </summary>
        /// <param name="pk">����</param>
        /// <param name="colName">������</param>
        /// <param name="value">ֵ</param>
        public virtual void set(double pk, int colName, double value) {
            FCDataRow row = null;
            int index = getRowIndex(pk);
            if (index == -1) {
                row = addKey(pk);
                row.fillEmpty(m_columns.size());
            }
            else {
                row = m_rows.get(index);
            }
            int colIndex = getColumnIndex(colName);
            row.set(colIndex, value);
        }

        /// <summary>
        /// ���������������
        /// </summary>
        /// <param name="rowIndex">����</param>
        /// <param name="colName">������</param>
        /// <param name="value">ֵ</param>
        public virtual void set2(int rowIndex, int colName, double value) {
            int colIndex = getColumnIndex(colName);
            m_rows.get(rowIndex).set(colIndex, value);
        }

        /// <summary>
        /// ������������������������
        /// </summary>
        /// <param name="rowIndex">������</param>
        /// <param name="colIndex">������</param>
        /// <param name="value">ֵ</param>
        public virtual void set3(int rowIndex, int colIndex, double value) {
            m_rows.get(rowIndex).set(colIndex, value);
        }

        /// <summary>
        /// �����е�����
        /// </summary>
        /// <param name="capacity">����</param>
        public virtual void setColsCapacity(int capacity) {
            m_colsCapacity = capacity;
        }

        /// <summary>
        /// �����е���������
        /// </summary>
        /// <param name="step">����</param>
        public virtual void setColsGrowStep(int step) {
            m_colsStep = step;
        }

        /// <summary>
        /// �����е�����
        /// </summary>
        /// <param name="capacity">����</param>
        public virtual void setRowsCapacity(int capacity) {
            m_keys.set_capacity(capacity);
            m_rows.set_capacity(capacity);
        }

        /// <summary>
        /// �����е���������
        /// </summary>
        /// <param name="step">����</param>
        public virtual void setRowsGrowStep(int step) {
            m_keys.set_step(step);
            m_rows.set_step(step);
        }
    }
}
