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
    public class FCHScrollBar : FCScrollBar {
        /// <summary>
        /// �����ؼ�
        /// </summary>
        public FCHScrollBar() {
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
            return "HScrollBar";
        }

        /// <summary>
        /// �϶���������
        /// </summary>
        public override void onDragScroll() {
            bool floatRight = false;
            FCButton backButton = BackButton;
            FCButton scrollButton = ScrollButton;
            int backButtonWidth = backButton.Width;
            int contentSize = ContentSize;
            if (scrollButton.Right > backButtonWidth) {
                floatRight = true;
            }
            base.onDragScroll();
            if (floatRight) {
                Pos = contentSize;
            }
            else {
                Pos = (int)((long)contentSize * (long)scrollButton.Left / backButtonWidth);
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
            if (mp.x < scrollButton.Left) {
                pageReduce();
                IsReducing = true;
            }
            else if (mp.x > scrollButton.Right) {
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
                int abWidth = addButton.Visible ? addButton.Width : 0;
                addButton.Size = new FCSize(abWidth, height);
                addButton.Location = new FCPoint(width - abWidth, 0);
                int rbWidth = reduceButton.Visible ? reduceButton.Width : 0;
                reduceButton.Size = new FCSize(rbWidth, height);
                reduceButton.Location = new FCPoint(0, 0);
                int backWidth = width - abWidth - rbWidth;
                backButton.Size = new FCSize(backWidth, height);
                backButton.Location = new FCPoint(rbWidth, 0);
                //��ȡ��������Ⱥ�����
                int scrollWidth = backWidth * pageSize / contentSize;
                int scrollPos = backWidth * pos / contentSize;
                if (scrollWidth < 10) {
                    scrollWidth = 10;
                    if (scrollPos + scrollWidth > backWidth) {
                        scrollPos = backWidth - scrollWidth;
                    }
                }

                scrollButton.Size = new FCSize(scrollWidth, height);
                scrollButton.Location = new FCPoint(scrollPos, 0);
            }
        }
    }
}
