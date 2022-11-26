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
    /// ��ѡ��ؼ�
    /// </summary>
    public class FCRadioButton : FCCheckBox {
        /// <summary>
        /// ������ѡ��
        /// </summary>
        public FCRadioButton() {
        }

        protected String groupName;

        /// <summary>
        /// ��ȡ����������
        /// </summary>
        public virtual String GroupName {
            get { return groupName; }
            set { groupName = value; }
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "RadioButton";
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public override void getProperty(String name, ref String value, ref String type) {
            if (name == "groupname") {
                type = "text";
                value = GroupName;
            }
            else {
                base.getProperty(name, ref value, ref type);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns>���������б�</returns>
        public override ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = base.getPropertyNames();
            propertyNames.AddRange(new String[] { "GroupName" });
            return propertyNames;
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public override void onClick(FCTouchInfo touchInfo) {
            if (!Checked) {
                Checked = !Checked;
            }
            callTouchEvents(FCEventID.CLICK, touchInfo);
            invalidate();
        }

        /// <summary>
        /// �ػ�ѡ�а�ť����
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public override void onPaintCheckButton(FCPaint paint, FCRect clipRect) {
            //���Ʊ���ͼ
            String bkImage = getPaintingBackImage();
            if (bkImage != null && bkImage.Length > 0) {
                paint.drawImage(bkImage, clipRect);
            }
            else {
                if (Checked) {
                    FCRect innerRect = new FCRect(clipRect.left + 2, clipRect.top + 2, clipRect.right - 3, clipRect.bottom - 3);
                    if (clipRect.right - clipRect.left < 4 || clipRect.bottom - clipRect.top < 4) {
                        innerRect = clipRect;
                    }
                    paint.fillEllipse(getPaintingButtonBackColor(), innerRect);
                }
                paint.drawEllipse(getPaintingButtonBorderColor(), 1, 0, clipRect);
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public override void setProperty(String name, String value) {
            if (name == "groupname") {
                GroupName = value;
            }
            else {
                base.setProperty(name, value);
            }
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public override void update() {
            if (Checked) {
                ArrayList<FCView> controls = null;
                if (Parent != null) {
                    controls = Parent.getControls();
                }
                else {
                    controls = Native.getControls();
                }
                //��ѡ�����ͬ����
                int controlSize = controls.size();
                for (int i = 0; i < controlSize; i++) {
                    FCRadioButton radioButton = controls.get(i) as FCRadioButton;
                    if (radioButton != null && radioButton != this) {
                        if (radioButton.GroupName == GroupName && radioButton.Checked == true) {
                            radioButton.Checked = false;
                            radioButton.invalidate();
                        }
                    }
                }
            }
        }
    }
}
