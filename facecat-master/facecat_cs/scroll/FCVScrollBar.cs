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
    /// ����������ؼ�
    /// </summary>
    public class FCVScrollBar : FCScrollBar {
        /// <summary>
        /// �����ؼ�
        /// </summary>
        public FCVScrollBar() {
            m_backButtonTouchDownEvent = new FCTouchEvent(backButtonTouchDown);
            m_backButtonTouchUpEvent = new FCTouchEvent(backButtonTouchUp);
        }

        /// <summary>
        /// ������ť�Ĵ��������¼�
        /// </summary>
        private FCTouchEvent m_backButtonTouchDownEvent;

        /// <summary>
        /// ������ť�Ĵ���̧���¼�
        /// </summary>
        private FCTouchEvent m_backButtonTouchUpEvent;

        /// <summary>
        /// ������������ť�������»ص��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void backButtonTouchDown(object sender, FCTouchInfo touchInfo) {
            onBackButtonTouchDown(touchInfo);
        }

        /// <summary>
        /// ������������ť����̧��ص��¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="touchInfo">������Ϣ</param>
        private void backButtonTouchUp(object sender, FCTouchInfo touchInfo) {
            onBackButtonTouchUp(touchInfo);
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public override void delete() {
            if (!IsDeleted) {
                FCButton backButton = BackButton;
                if (backButton != null) {
                    if (m_backButtonTouchDownEvent != null) {
                        backButton.removeEvent(m_backButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                        m_backButtonTouchDownEvent = null;
                    }
                    if (m_backButtonTouchUpEvent != null) {
                        backButton.removeEvent(m_backButtonTouchUpEvent, FCEventID.TOUCHUP);
                        m_backButtonTouchUpEvent = null;
                    }
                }
            }
            base.delete();
        }

        /// <summary>
        /// ��ȡ�ؼ�����
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public override String getControlType() {
            return "VScrollBar";
        }

        /// <summary>
        /// �϶���������
        /// </summary>
        public override void onDragScroll() {
            bool floatRight = false;
            FCButton backButton = BackButton;
            FCButton scrollButton = ScrollButton;
            int backButtonHeight = backButton.Height;
            int contentSize = ContentSize;
            if (scrollButton.Bottom > backButtonHeight) {
                floatRight = true;
            }
            base.onDragScroll();
            if (floatRight) {
                Pos = contentSize;
            }
            else {
                Pos = (int)(((long)contentSize * (long)scrollButton.Top) / backButton.Height);
            }
            onScrolled();
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public override void onLoad() {
            bool isAdd = false;
            FCButton backButton = BackButton;
            if (backButton != null) {
                isAdd = true;
            }
            base.onLoad();
            if (!isAdd) {
                backButton = BackButton;
                backButton.addEvent(m_backButtonTouchDownEvent, FCEventID.TOUCHDOWN);
                backButton.addEvent(m_backButtonTouchUpEvent, FCEventID.TOUCHUP);
            }
        }

        /// <summary>
        /// ������������ť�������»ص�����
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onBackButtonTouchDown(FCTouchInfo touchInfo) {
            FCButton scrollButton = ScrollButton;
            FCPoint mp = touchInfo.m_firstPoint;
            if (mp.y < scrollButton.Top) {
                pageReduce();
                IsReducing = true;
            }
            else if (mp.y > scrollButton.Bottom) {
                pageAdd();
                IsAdding = true;
            }
        }

        /// <summary>
        /// ������������ť����̧�𷽷�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onBackButtonTouchUp(FCTouchInfo touchInfo) {
            IsAdding = false;
            IsReducing = false;
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public override void update() {
            if (Native == null) {
                return;
            }
            FCButton addButton = AddButton;
            FCButton backButton = BackButton;
            FCButton reduceButton = ReduceButton;
            FCButton scrollButton = ScrollButton;
            int width = Width, height = Height;
            int contentSize = ContentSize;
            //���ð�ť��λ��
            if (contentSize > 0 && addButton != null && backButton != null && reduceButton != null && scrollButton != null) {
                int pos = Pos;
                int pageSize = PageSize;
                if (pos > contentSize - pageSize) {
                    pos = contentSize - pageSize;
                }
                if (pos < 0) {
                    pos = 0;
                }
                int abHeight = addButton.Visible ? addButton.Height : 0;
                addButton.Size = new FCSize(width, abHeight);
                addButton.Location = new FCPoint(0, height - abHeight);
                int rbHeight = reduceButton.Visible ? reduceButton.Height : 0;
                reduceButton.Size = new FCSize(width, rbHeight);
                reduceButton.Location = new FCPoint(0, 0);
                int backHeight = height - abHeight - rbHeight;
                backButton.Size = new FCSize(width, backHeight);
                backButton.Location = new FCPoint(0, rbHeight);
                //��ȡ��������Ⱥ�����
                int scrollHeight = backHeight * pageSize / contentSize;
                int scrollPos = (int)((long)backHeight * (long)pos / contentSize);
                if (scrollHeight < 10) {
                    scrollHeight = 10;
                    if (scrollPos + scrollHeight > backHeight) {
                        scrollPos = backHeight - scrollHeight;
                    }
                }
                scrollButton.Size = new FCSize(width, scrollHeight);
                scrollButton.Location = new FCPoint(0, scrollPos);
            }
        }
    }
}
