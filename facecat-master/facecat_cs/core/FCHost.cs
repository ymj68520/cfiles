/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu);
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

using System;

namespace FaceCat {
    /// <summary>
    /// �ؼ�����
    /// </summary>
    public abstract class FCHost {
        /// <summary>
        /// ��ȡ�������Ƿ��������
        /// </summary>
        public abstract bool AllowOperate {
            get;
            set;
        }

        /// <summary>
        /// ��ȡ�������Ƿ�����ֲ���ͼ
        /// </summary>
        public abstract bool AllowPartialPaint {
            get;
            set;
        }

        public abstract bool IsDeleted {
            get;
        }

        /// <summary>
        /// ��ȡ�����÷�����
        /// </summary>
        public abstract FCNative Native {
            get;
            set;
        }

        /// <summary>
        /// �����
        /// </summary>
        public abstract void activeMirror();

        /// <summary>
        /// �ڿؼ����߳��е��÷���
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <param name="args">����</param>
        public abstract void beginInvoke(FCView control, object args);

        /// <summary>
        /// �����ı�
        /// </summary>
        /// <param name="text">�ı�</param>
        public abstract void copy(String text);

        /// <summary>
        /// ������Դ
        /// </summary>
        public abstract void delete();

        /// <summary>
        /// �����ڲ��ؼ�
        /// </summary>
        /// <param name="parent">���ؼ�</param>
        /// <param name="clsid">����ID</param>
        /// <returns>�ؼ�</returns>
        public abstract FCView createInternalControl(FCView parent, String clsid);

        /// <summary>
        /// ��ȡ���
        /// </summary>
        /// <returns>���</returns>
        public abstract FCCursors getCursor();

        /// <summary>
        /// ��ȡ�����ཻ��
        /// </summary>
        /// <param name="lpDestRect">�ཻ����</param>
        /// <param name="lpSrc1Rect">����1</param>
        /// <param name="lpSrc2Rect">����2</param>
        /// <returns>�Ƿ��ཻ</returns>
        public abstract int getIntersectRect(ref FCRect lpDestRect, ref FCRect lpSrc1Rect, ref FCRect lpSrc2Rect);

        /// <summary>
        /// ��ȡ�ߴ�
        /// </summary>
        /// <returns>��С</returns>
        public abstract FCSize getSize();

        /// <summary>
        /// ��ȡ����λ��
        /// </summary>
        /// <returns>����</returns>
        public abstract FCPoint getTouchPoint();

        /// <summary>
        /// ��ȡ���β�����
        /// </summary>
        /// <param name="lpDestRect">��������</param>
        /// <param name="lpSrc1Rect">����1</param>
        /// <param name="lpSrc2Rect">����2</param>
        /// <returns>�Ƿ��ཻ</returns>
        public abstract int getUnionRect(ref FCRect lpDestRect, ref FCRect lpSrc1Rect, ref FCRect lpSrc2Rect);

        /// <summary>
        /// ˢ�»�ͼ
        /// </summary>
        /// <param name="rect">����</param>
        public abstract void invalidate(FCRect rect);

        /// <summary>
        /// ˢ�»�ͼ
        /// </summary>
        public abstract void invalidate();

        /// <summary>
        /// �ڿؼ����߳��е��÷���
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <param name="args">����</param>
        public abstract void invoke(FCView control, object args);

        /// <summary>
        /// ��ȡ������״̬
        /// </summary>
        /// <param name="key">����</param>
        /// <returns>״̬</returns>
        public abstract bool isKeyPress(int key);

        /// <summary>
        /// ��ȡճ���ı�
        /// </summary>
        /// <returns>�ı�</returns>
        public abstract String paste();

        /// <summary>
        /// ���ù��
        /// </summary>
        /// <param name="cursor">���</param>
        public abstract void setCursor(FCCursors cursor);

        /// <summary>
        /// ��ʾ��ʾ��
        /// </summary>
        /// <param name="text">����</param>
        /// <param name="mp">λ��</param>
        public abstract void showToolTip(String text, FCPoint mp);

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="timerID">���ID</param>
        /// <param name="interval">���</param>
        public abstract void startTimer(int timerID, int interval);

        /// <summary>
        /// ֹͣ���
        /// </summary>
        /// <param name="timerID">���ID</param>
        public abstract void stopTimer(int timerID);
    }
}
