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
    /// �����͵�Ԫ��
    /// </summary>
    public class FCGridBoolCell : FCGridCell {
        /// <summary>
        /// ���������͵�Ԫ��
        /// </summary>
        public FCGridBoolCell() {
        }

        /// <summary>
        /// ���������͵�Ԫ��
        /// </summary>
        /// <param name="value">��ֵ</param>
        public FCGridBoolCell(bool value) {
            m_value = value;
        }

        /// <summary>
        /// ��ֵ
        /// </summary>
        protected bool m_value;

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public override int compareTo(FCGridCell cell) {
            bool value = getBool();
            bool target = cell.getBool();
            if (value && !target) {
                return 1;
            }
            else if (!value && target) {
                return -1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            return m_value ? 1 : 0;
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            return m_value ? 1 : 0;
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            return m_value ? 1 : 0;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            return m_value ? 1 : 0;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_value ? "true" : "false";
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            m_value = value;
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            m_value = value > 0 ? true : false;
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            m_value = value > 0 ? true : false;
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            m_value = value > 0 ? true : false;
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            m_value = value > 0 ? true : false;
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_value = value == "true" ? true : false;
        }
    }

    /// <summary>
    /// ��ť�ؼ���Ԫ��
    /// </summary>
    public class FCGridButtonCell : FCGridControlCell {
        /// <summary>
        /// ������ť�ؼ���Ԫ��
        /// </summary>
        public FCGridButtonCell() {
            FCButton button = new FCButton();
            button.BorderColor = FCColor.None;
            button.DisplayOffset = false;
            Control = button;
        }

        /// <summary>
        /// ��ȡ��ť
        /// </summary>
        public FCButton Button {
            get {
                if (Control != null) {
                    return Control as FCButton;
                }
                else {
                    return null;
                }
            }
        }
    }

    /// <summary>
    /// ��ѡ��ؼ���Ԫ��
    /// </summary>
    public class FCGridCheckBoxCell : FCGridControlCell {
        /// <summary>
        /// ������ѡ��ؼ���Ԫ��
        /// </summary>
        public FCGridCheckBoxCell() {
            FCCheckBox checkBox = new FCCheckBox();
            checkBox.DisplayOffset = false;
            checkBox.ButtonAlign = FCHorizontalAlign.Center;
            Control = checkBox;
        }

        /// <summary>
        /// ��ȡ��ѡ��ؼ�
        /// </summary>
        public FCCheckBox CheckBox {
            get {
                if (Control != null) {
                    return Control as FCCheckBox;
                }
                else {
                    return null;
                }
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                return checkBox.Checked;
            }
            else {
                return false;
            }
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                return checkBox.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                return checkBox.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                return checkBox.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                return checkBox.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns></returns>
        public override String getString() {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                return checkBox.Checked ? "true" : "false";
            }
            else {
                return "false";
            }
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                checkBox.Checked = value;
            }
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                checkBox.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                checkBox.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                checkBox.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                checkBox.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value"></param>
        public override void setString(String value) {
            FCCheckBox checkBox = CheckBox;
            if (checkBox != null) {
                checkBox.Checked = value == "true";
            }
        }
    }

    /// <summary>
    /// ��ť�ؼ���Ԫ��
    /// </summary>
    public class FCGridComboBoxCell : FCGridControlCell {
        /// <summary>
        /// ������ť�ؼ���Ԫ��
        /// </summary>
        public FCGridComboBoxCell() {
            FCComboBox comboBox = new FCComboBox();
            comboBox.BorderColor = FCColor.None;
            comboBox.DisplayOffset = false;
            Control = comboBox;
        }

        /// <summary>
        /// ��ȡ��ť�ؼ�
        /// </summary>
        public FCComboBox ComboBox {
            get {
                if (Control != null) {
                    return Control as FCComboBox;
                }
                else {
                    return null;
                }
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                return comboBox.SelectedIndex > 0;
            }
            else {
                return false;
            }
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                return (double)comboBox.SelectedIndex;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                return (float)comboBox.SelectedIndex;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                return comboBox.SelectedIndex;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                return (long)comboBox.SelectedIndex;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>�ַ���</returns>
        public override String getString() {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                return comboBox.SelectedValue;
            }
            else {
                return "";
            }
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                comboBox.SelectedIndex = value ? 1 : 0;
            }
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                comboBox.SelectedIndex = (int)value;
            }
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                comboBox.SelectedIndex = (int)value;
            }
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                comboBox.SelectedIndex = value;
            }
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                comboBox.SelectedIndex = (int)value;
            }
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            FCComboBox comboBox = ComboBox;
            if (comboBox != null) {
                comboBox.SelectedValue = value;
            }
        }
    }

    /// <summary>
    /// ���ڿؼ���Ԫ��
    /// </summary>
    public class FCGridDateTimePickerCell : FCGridControlCell {
        /// <summary>
        /// �������ڿؼ���Ԫ��
        /// </summary>
        public FCGridDateTimePickerCell() {
            FCDateTimePicker datePicker = new FCDateTimePicker();
            datePicker.BorderColor = FCColor.None;
            datePicker.DisplayOffset = false;
            Control = datePicker;
        }

        /// <summary>
        /// ��ȡ��ť�ؼ�
        /// </summary>
        public FCDateTimePicker DatePicker {
            get {
                if (Control != null) {
                    return Control as FCDateTimePicker;
                }
                else {
                    return null;
                }
            }
        }
    }

    /// <summary>
    /// ��ؼ���Ԫ��
    /// </summary>
    public class GridDivCell : FCGridControlCell {
        /// <summary>
        /// ������ؼ���Ԫ��
        /// </summary>
        public GridDivCell() {
            FCDiv div = new FCDiv();
            div.BorderColor = FCColor.None;
            div.DisplayOffset = false;
            Control = div;
        }

        /// <summary>
        /// ��ȡ��ؼ�
        /// </summary>
        public FCDiv Div {
            get {
                if (Control != null) {
                    return Control as FCDiv;
                }
                else {
                    return null;
                }
            }
        }
    }

    /// <summary>
    /// ˫���ȸ����͵�Ԫ��
    /// </summary>
    public class FCGridDoubleCell : FCGridCell {
        /// <summary>
        /// ����˫���ȸ����͵�Ԫ��
        /// </summary>
        public FCGridDoubleCell() {
        }

        /// <summary>
        /// ����˫���ȸ����͵�Ԫ��
        /// </summary>
        /// <param name="value">��ֵ</param>
        public FCGridDoubleCell(double value) {
            m_value = value;
        }

        /// <summary>
        /// ��ֵ
        /// </summary>
        protected double m_value;

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public override int compareTo(FCGridCell cell) {
            double value = getDouble();
            double target = cell.getDouble();
            if (value > target) {
                return 1;
            }
            else if (value < target) {
                return -1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            return m_value == 0 ? false : true;
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            return (float)m_value;
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            return (int)m_value;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            return (long)m_value;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_value.ToString();
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            m_value = value ? 1 : 0;
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            m_value = value;
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            m_value = value;
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            m_value = value;
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            m_value = (double)value;
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_value = FCStr.convertStrToDouble(value);
        }
    }

    /// <summary>
    /// �����ȸ����͵�Ԫ��
    /// </summary>
    public class FCGridFloatCell : FCGridCell {
        /// <summary>
        /// ���������ȸ����͵�Ԫ��
        /// </summary>
        public FCGridFloatCell() {
        }

        /// <summary>
        /// ���������ȸ����͵�Ԫ��
        /// </summary>
        /// <param name="value">��ֵ</param>
        public FCGridFloatCell(float value) {
            m_value = value;
        }

        /// <summary>
        /// ��ֵ
        /// </summary>
        protected float m_value;

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public override int compareTo(FCGridCell cell) {
            float value = getFloat();
            float target = cell.getFloat();
            if (value > target) {
                return 1;
            }
            else if (value < target) {
                return -1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            return m_value == 0 ? false : true;
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            return (int)m_value;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            return (long)m_value;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_value.ToString();
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            m_value = value ? 1 : 0;
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            m_value = (float)value;
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            m_value = value;
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            m_value = value;
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            m_value = (float)value;
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_value = (float)FCStr.convertStrToDouble(value);
        }
    }

    /// <summary>
    /// ���͵�Ԫ��
    /// </summary>
    public class FCGridIntCell : FCGridCell {
        /// <summary>
        /// �������͵�Ԫ��
        /// </summary>
        public FCGridIntCell() {
        }

        /// <summary>
        /// �������͵�Ԫ��
        /// </summary>
        /// <param name="value">��ֵ</param>
        public FCGridIntCell(int value) {
            m_value = value;
        }

        /// <summary>
        /// ��ֵ
        /// </summary>
        protected int m_value;

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public override int compareTo(FCGridCell cell) {
            int value = getInt();
            int target = cell.getInt();
            if (value > target) {
                return 1;
            }
            else if (value < target) {
                return -1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            return m_value == 0 ? false : true;
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_value.ToString();
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            m_value = value ? 1 : 0;
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            m_value = (int)value;
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            m_value = (int)value;
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            m_value = value;
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            m_value = (int)value;
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_value = FCStr.convertStrToInt(value);
        }
    }

    /// <summary>
    /// ��ǩ�͵�Ԫ��
    /// </summary>
    public class FCGridLabelCell : FCGridControlCell {
        /// <summary>
        /// ������ǩ��Ԫ��
        /// </summary>
        public FCGridLabelCell() {
            FCLabel label = new FCLabel();
            label.BorderColor = FCColor.None;
            label.DisplayOffset = false;
            Control = label;
        }

        /// <summary>
        /// ��ȡ��ǩ�ؼ�
        /// </summary>
        public FCLabel Label {
            get {
                if (Control != null) {
                    return Control as FCLabel;
                }
                else {
                    return null;
                }
            }
        }
    }

    /// <summary>
    /// �����͵�Ԫ��
    /// </summary>
    public class FCGridLongCell : FCGridCell {
        /// <summary>
        /// ���������͵�Ԫ��
        /// </summary>
        public FCGridLongCell() {
        }

        /// <summary>
        /// ���������͵�Ԫ��
        /// </summary>
        /// <param name="value">��ֵ</param>
        public FCGridLongCell(long value) {
            m_value = value;
        }

        /// <summary>
        /// ��ֵ
        /// </summary>
        protected long m_value;

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public override int compareTo(FCGridCell cell) {
            long value = getLong();
            long target = cell.getLong();
            if (value > target) {
                return 1;
            }
            else if (value < target) {
                return -1;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            return m_value == 0 ? false : true;
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            return (int)m_value;
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            return m_value;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_value.ToString();
        }


        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            m_value = value ? 1 : 0;
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            m_value = (long)value;
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            m_value = (long)value;
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            m_value = value;
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            m_value = value;
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_value = (long)FCStr.convertStrToInt(value);
        }
    }

    /// <summary>
    /// �����͵�Ԫ��
    /// </summary>
    public class FCGridPasswordCell : FCGridStringCell {
        /// <summary>
        /// ��ȡҪ���Ƶ��ı�
        /// </summary>
        /// <returns>�ı�</returns>
        public override string getPaintText() {
            return "******";
        }
    }

    /// <summary>
    /// ��ѡ��ť��Ԫ��
    /// </summary>
    public class GridRadioButtonCell : FCGridControlCell {
        /// <summary>
        /// ������ѡ��ť��Ԫ��
        /// </summary>
        public GridRadioButtonCell() {
            FCRadioButton radioButton = new FCRadioButton();
            radioButton.BorderColor = FCColor.None;
            radioButton.DisplayOffset = false;
            Control = radioButton;
        }

        /// <summary>
        /// ��ȡ��ť�ؼ�
        /// </summary>
        public FCRadioButton RadioButton {
            get {
                if (Control != null) {
                    return Control as FCRadioButton;
                }
                else {
                    return null;
                }
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                return radioButton.Checked;
            }
            else {
                return false;
            }
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                return radioButton.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                return radioButton.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                return radioButton.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                return radioButton.Checked ? 1 : 0;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns></returns>
        public override String getString() {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                return radioButton.Checked ? "true" : "false";
            }
            else {
                return "false";
            }
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                radioButton.Checked = value;
            }
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                radioButton.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                radioButton.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                radioButton.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                radioButton.Checked = value > 0 ? true : false;
            }
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value"></param>
        public override void setString(String value) {
            FCRadioButton radioButton = RadioButton;
            if (radioButton != null) {
                radioButton.Checked = value == "true";
            }
        }
    }

    /// <summary>
    /// ��ֵ��Ԫ��
    /// </summary>
    public class FCGridSpinCell : FCGridControlCell {
        /// <summary>
        /// ���������Ԫ��
        /// </summary>
        public FCGridSpinCell() {
            FCSpin spin = new FCSpin();
            spin.BorderColor = FCColor.None;
            spin.DisplayOffset = false;
            Control = spin;
        }

        /// <summary>
        /// ��ȡ�����ؼ�
        /// </summary>
        public FCSpin Spin {
            get {
                if (Control != null) {
                    return Control as FCSpin;
                }
                else {
                    return null;
                }
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override bool getBool() {
            FCSpin spin = Spin;
            if (spin != null) {
                return spin.Value > 0;
            }
            else {
                return false;
            }
        }

        /// <summary>
        /// ��ȡ˫���ȸ���ֵ
        /// </summary>
        /// <returns>˫���ȸ���ֵ</returns>
        public override double getDouble() {
            FCSpin spin = Spin;
            if (spin != null) {
                return spin.Value;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ�����ȸ���ֵ
        /// </summary>
        /// <returns>�����ȸ���ֵ</returns>
        public override float getFloat() {
            FCSpin spin = Spin;
            if (spin != null) {
                return (float)spin.Value;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ������ֵ
        /// </summary>
        /// <returns>������ֵ</returns>
        public override int getInt() {
            FCSpin spin = Spin;
            if (spin != null) {
                return (int)spin.Value;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ��������ֵ
        /// </summary>
        /// <returns>��������ֵ</returns>
        public override long getLong() {
            FCSpin spin = Spin;
            if (spin != null) {
                return (long)spin.Value;
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ���ò�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setBool(bool value) {
            FCSpin spin = Spin;
            if (spin != null) {
                spin.Value = value ? 1 : 0;
            }
        }

        /// <summary>
        /// ����˫���ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setDouble(double value) {
            FCSpin spin = Spin;
            if (spin != null) {
                spin.Value = value;
            }
        }

        /// <summary>
        /// ���õ����ȸ���ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setFloat(float value) {
            FCSpin spin = Spin;
            if (spin != null) {
                spin.Value = (double)value;
            }
        }

        /// <summary>
        /// ����������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setInt(int value) {
            FCSpin spin = Spin;
            if (spin != null) {
                spin.Value = (double)value;
            }
        }

        /// <summary>
        /// ���ó�������ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setLong(long value) {
            FCSpin spin = Spin;
            if (spin != null) {
                spin.Value = (double)value;
            }
        }
    }

    /// <summary>
    /// �ַ��͵�Ԫ��
    /// </summary>
    public class FCGridStringCell : FCGridCell {
        /// <summary>
        /// �����ַ��͵�Ԫ��
        /// </summary>
        public FCGridStringCell() {
        }

        /// <summary>
        /// �����ַ��͵�Ԫ��
        /// </summary>
        /// <param name="value">��ֵ</param>
        public FCGridStringCell(String value) {
            m_value = value;
        }

        /// <summary>
        /// �ַ�
        /// </summary>
        protected String m_value;

        /// <summary>
        /// ��Ԫ���С�Ƚϣ���������
        /// </summary>
        /// <param name="cell">�Ƚϵ�Ԫ��</param>
        /// <returns>1:�ϴ� 0:��� -1:��С</returns>
        public override int compareTo(FCGridCell cell) {
            String target = cell.getString();
            String value = getString();
            if (value != null) {
                return value.CompareTo(target);
            }
            return -1;
        }

        /// <summary>
        /// ��ȡ�ַ�����ֵ
        /// </summary>
        /// <returns>�ַ�����ֵ</returns>
        public override String getString() {
            return m_value;
        }

        /// <summary>
        /// �����ַ�����ֵ
        /// </summary>
        /// <param name="value">��ֵ</param>
        public override void setString(String value) {
            m_value = value;
        }
    }

    /// <summary>
    /// �����Ԫ��
    /// </summary>
    public class FCGridTextBoxCell : FCGridControlCell {
        /// <summary>
        /// ���������Ԫ��
        /// </summary>
        public FCGridTextBoxCell() {
            FCTextBox textBox = new FCTextBox();
            textBox.BorderColor = FCColor.None;
            textBox.DisplayOffset = false;
            Control = textBox;
        }

        /// <summary>
        /// ��ȡ��ť�ؼ�
        /// </summary>
        public FCTextBox TextBox {
            get {
                if (Control != null) {
                    return Control as FCTextBox;
                }
                else {
                    return null;
                }
            }
        }
    }
}
