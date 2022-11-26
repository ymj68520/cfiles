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
using System.Windows.Forms;

namespace FaceCat {
    /// <summary>
    /// �������
    /// </summary>
    public class FCNative {
        /// <summary>
        /// �����������
        /// </summary>
        public FCNative() {
            m_host.Native = this;
        }

        /// <summary>
        /// ��������
        /// </summary>
        ~FCNative() {
            delete();
        }

        /// <summary>
        /// �ؼ�
        /// </summary>
        private ArrayList<FCView> m_controls = new ArrayList<FCView>();

        /// <summary>
        /// �϶���ʼʱ�Ĵ���λ��
        /// </summary>
        private FCPoint m_dragBeginPoint;

        /// <summary>
        /// �϶���ʼʱ������
        /// </summary>
        private FCRect m_dragBeginRect;

        /// <summary>
        /// ���Կ�ʼ�϶���ƫ��������
        /// </summary>
        private FCPoint m_dragStartOffset;

        /// <summary>
        /// �����϶��Ŀؼ�
        /// </summary>
        private FCView m_draggingControl;

        /// <summary>
        /// ���������Ŀؼ�
        /// </summary>
        private FCView m_exportingControl;

        /// <summary>
        /// �����
        /// </summary>
        private HashMap<int, FCView> m_timers = new HashMap<int, FCView>();

        /// <summary>
        /// �����������µĿؼ�
        /// </summary>
        private FCView m_touchDownControl;

        /// <summary>
        /// ��������ʱ������
        /// </summary>
        private FCPoint m_touchDownPoint;

        /// <summary>
        /// �����������Ϸ��ƶ��Ŀؼ�
        /// </summary>
        private FCView m_touchMoveControl;

        private bool m_allowScaleSize = false;

        /// <summary>
        /// ��ȡ�������Ƿ�����ʹ�����ųߴ�
        /// </summary>
        public bool AllowScaleSize {
            get { return m_allowScaleSize; }
            set { m_allowScaleSize = value; }
        }

        /// <summary>
        /// ��ȡ�����ô�����״
        /// </summary>
        public FCCursors Cursor {
            get {
                if (m_host != null) {
                    return m_host.getCursor();
                }
                return FCCursors.Arrow;
            }
            set { m_host.setCursor(value); }
        }

        private FCSize m_displaySize;

        /// <summary>
        /// ��ȡ��������ʾ����
        /// </summary>
        public FCSize DisplaySize {
            get { return m_displaySize; }
            set { m_displaySize = value; }
        }

        private FCView m_focusedControl;

        /// <summary>
        /// ��ȡ������ѡ�еĿؼ�
        /// </summary>
        public FCView FocusedControl {
            get { return m_focusedControl; }
            set {
                if (m_focusedControl != value) {
                    if (m_focusedControl != null) {
                        FCView fControl = m_focusedControl;
                        m_focusedControl = null;
                        fControl.onLostFocus();
                    }
                    m_focusedControl = value;
                    if (m_focusedControl != null) {
                        m_focusedControl.onGotFocus();
                    }
                }
            }
        }

        private FCHost m_host = new WinHost();

        /// <summary>
        /// ��ȡ�����ÿؼ�������
        /// </summary>
        public FCHost Host {
            get { return m_host; }
            set { m_host = value; }
        }

        /// <summary>
        /// ��ȡ������ͣ�Ŀؼ�
        /// </summary>
        public FCView HoveredControl {
            get { return m_touchMoveControl; }
        }

        private bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public bool IsDeleted {
            get { return m_isDeleted; }
        }

        private FCMirrorMode m_mirrorMode = FCMirrorMode.None;

        /// <summary>
        /// ��ȡ�����þ���ģʽ
        /// </summary>
        public FCMirrorMode MirrorMode {
            get { return m_mirrorMode; }
            set { m_mirrorMode = value; }
        }

        private ArrayList<FCNative> m_mirrors = new ArrayList<FCNative>();

        /// <summary>
        /// ��ȡ�����þ��񼯺�
        /// </summary>
        public ArrayList<FCNative> Mirrors {
            get { return m_mirrors; }
            set { m_mirrors = value; }
        }

        private FCNative m_mirrorHost;

        /// <summary>
        /// ��ȡ������
        /// </summary>
        public FCNative MirrorHost {
            get { return m_mirrorHost; }
        }

        private float m_opacity = 1;

        /// <summary>
        /// ��ȡ������͸����
        /// </summary>
        public float Opacity {
            get { return m_opacity; }
            set { m_opacity = value; }
        }

        private FCPaint m_paint = new GdiPlusPaint();

        /// <summary>
        /// ��ȡ��ͼ��
        /// </summary>
        public FCPaint Paint {
            get { return m_paint; }
            set { m_paint = value; }
        }

        /// <summary>
        /// ��ȡ������ס�Ŀؼ�
        /// </summary>
        public FCView PushedControl {
            get { return m_touchDownControl; }
        }

        private String m_resourcePath;

        /// <summary>
        /// ��ȡ��������Դ�ļ���·��
        /// </summary>
        public String ResourcePath {
            get { return m_resourcePath; }
            set { m_resourcePath = value; }
        }

        private int m_rotateAngle;

        /// <summary>
        /// ��ȡ��������ת�Ƕ�
        /// </summary>
        public int RotateAngle {
            get { return m_rotateAngle; }
            set { m_rotateAngle = value; }
        }

        private FCSize m_scaleSize;

        /// <summary>
        /// ��ȡ������ʹ�����ųߴ�
        /// </summary>
        public FCSize ScaleSize {
            get { return m_scaleSize; }
            set { m_scaleSize = value; }
        }

        /// <summary>
        /// ��ȡ������ʵ��λ��
        /// </summary>
        public FCPoint TouchPoint {
            get {
                if (m_host != null) {
                    return m_host.getTouchPoint();
                }
                return new FCPoint(0, 0);
            }
        }

        /// <summary>
        /// ��ӿؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void addControl(FCView control) {
            control.Native = this;
            m_controls.add(control);
            control.onAdd();
        }

        /// <summary>
        /// ��Ӿ���
        /// </summary>
        /// <param name="mirrorHost">����</param>
        /// <param name="control">�ؼ�</param>
        public void addMirror(FCNative mirrorHost, FCView control) {
            m_mirrorHost = mirrorHost;
            m_mirrorHost.Mirrors.add(this);
            control.Native = this;
            m_controls.add(control);
        }

        /// <summary>
        /// ���ؼ��ŵ���ǰ��ʾ
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void bringToFront(FCView control) {
            FCView parent = control.Parent;
            if (parent != null) {
                parent.bringChildToFront(control);
            }
            else {
                if (m_controls != null && m_controls.size() > 0) {
                    m_controls.remove(control);
                    m_controls.add(control);
                }
            }
        }

        /// <summary>
        /// �˳��϶�
        /// </summary>
        public void cancelDragging() {
            if (m_draggingControl != null) {
                m_draggingControl.Bounds = m_dragBeginRect;
                FCView draggingControl = m_draggingControl;
                m_draggingControl = null;
                draggingControl.onDragEnd();
                FCView parent = draggingControl.Parent;
                if (parent != null) {
                    parent.invalidate();
                }
                else {
                    invalidate();
                }
            }
        }

        /// <summary>
        /// ������еĿؼ�
        /// </summary>
        public void clearControls() {
            ArrayList<FCView> controls = new ArrayList<FCView>();
            foreach (FCView control in m_controls) {
                controls.add(control);
            }
            foreach (FCView control in controls) {
                control.onRemove();
                control.delete();
            }
            m_controls.clear();
        }

        /// <summary>
        /// ��ȡ�ؼ��ľ��Ժ�����
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>����</returns>
        public int clientX(FCView control) {
            if (control != null) {
                FCView parent = control.Parent;
                int cLeft = control.Left;
                if (control == m_exportingControl) {
                    cLeft = 0;
                }
                if (parent != null) {
                    if (m_mirrorMode != FCMirrorMode.None) {
                        int controlsSize = m_controls.size();
                        for (int i = 0; i < controlsSize; i++) {
                            if (m_controls.get(i) == control) {
                                return cLeft;
                            }
                        }
                    }
                    return cLeft - (control.DisplayOffset ? parent.getDisplayOffset().x : 0) + clientX(parent);
                }
                else {
                    return cLeft;
                }
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// ��ȡ�ؼ��ľ���������
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>����</returns>
        public int clientY(FCView control) {
            if (control != null) {
                FCView parent = control.Parent;
                int cTop = control.Top;
                if (control == m_exportingControl) {
                    cTop = 0;
                }
                if (parent != null) {
                    if (m_mirrorMode != FCMirrorMode.None) {
                        int controlsSize = m_controls.size();
                        for (int i = 0; i < controlsSize; i++) {
                            if (m_controls.get(i) == control) {
                                return cTop;
                            }
                        }
                    }
                    return cTop - (control.DisplayOffset ? parent.getDisplayOffset().y : 0) + clientY(parent);
                }
                else {
                    return cTop;
                }
            }
            else {
                return 0;
            }
        }

        /// <summary>
        /// �Ƿ�����ؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>�Ƿ����</returns>
        public bool containsControl(FCView control) {
            foreach (FCView subControl in m_controls) {
                if (subControl == control) {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// ����̧���¼�
        /// </summary>
        /// <param name="sender">������</param>
        /// <param name="e">����</param>
        private void container_KeyUp(object sender, KeyEventArgs e) {
            onKeyUp((char)e.KeyData);
        }

        /// <summary>
        /// ������Դ
        /// </summary>
        public virtual void delete() {
            if (!m_isDeleted) {
                m_mirrors.clear();
                m_mirrorHost = null;
                m_timers.clear();
                clearControls();
                if (m_host != null) {
                    m_host.delete();
                }
                if (m_paint != null) {
                    m_paint.delete();
                }
                m_isDeleted = true;
            }
        }

        /// <summary>
        /// ������ͼƬ
        /// </summary>
        /// <param name="exportPath">����·��</param>
        public void exportToImage(String exportPath) {
            exportToImage(exportPath, null);
        }

        /// <summary>
        /// �����ؼ���ͼƬ
        /// </summary>
        /// <param name="exportPath">����·��</param>
        /// <param name="control">�ؼ�</param>
        public void exportToImage(String exportPath, FCView control) {
            m_exportingControl = control;
            if (control != null) {
                ArrayList<FCView> controls = new ArrayList<FCView>();
                controls.add(control);
                FCRect rect = new FCRect(0, 0, control.Width, control.Height);
                m_paint.beginExport(exportPath, rect);
                renderControls(rect, controls, getPaintingResourcePath(control), GetPaintingOpacity(control));
                m_paint.endExport();
            }
            else {
                FCRect rect = new FCRect(0, 0, m_displaySize.cx, m_displaySize.cy);
                m_paint.beginExport(exportPath, rect);
                ArrayList<FCView> subControls = new ArrayList<FCView>();
                getSortedControls(null, subControls);
                renderControls(rect, subControls, m_resourcePath, m_opacity);
                subControls.clear();
                m_paint.endExport();
            }
            m_exportingControl = null;
        }

        /// <summary>
        /// ���ݴ���λ�û�ȡ�ؼ�
        /// </summary>
        /// <param name="mp">����</param>
        /// <param name="controls">�ؼ�����</param>
        /// <returns>�ؼ�����</returns>
        private FCView findControl(FCPoint mp, ArrayList<FCView> controls) {
            int size = controls.size();
            for (int i = size - 1; i >= 0; i--) {
                FCView control = controls.get(i);
                if (control.Visible) {
                    if (control.containsPoint(mp)) {
                        ArrayList<FCView> subControls = new ArrayList<FCView>();
                        getSortedControls(control, subControls);
                        FCView subControl = findControl(mp, subControls);
                        subControls.clear();
                        if (subControl != null) {
                            return subControl;
                        }
                        return control;
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// �������Ʋ��ҿؼ�
        /// </summary>
        /// <param name="name">����</param>
        /// <param name="controls">�ؼ�����</param>
        /// <returns>�ؼ�</returns>
        private FCView findControl(String name, ArrayList<FCView> controls) {
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                if (control.Name == name) {
                    return control;
                }
                else {
                    ArrayList<FCView> subControls = control.getControls();
                    if (subControls != null && subControls.size() > 0) {
                        FCView fControl = findControl(name, subControls);
                        if (fControl != null) {
                            return fControl;
                        }
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// ����������ҿؼ�
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�ؼ�</returns>
        public FCView findControl(FCPoint mp) {
            ArrayList<FCView> subControls = new ArrayList<FCView>();
            getSortedControls(null, subControls);
            FCView control = findControl(mp, subControls);
            subControls.clear();
            return control;
        }

        /// <summary>
        /// ���������ڿؼ��в��ҿؼ�
        /// </summary>
        /// <param name="mp">����</param>
        /// <param name="parent">���ؼ�</param>
        /// <returns>�ؼ�</returns>
        public FCView findControl(FCPoint mp, FCView parent) {
            ArrayList<FCView> subControls = new ArrayList<FCView>();
            getSortedControls(parent, subControls);
            FCView control = findControl(mp, subControls);
            subControls.clear();
            return control;
        }

        /// <summary>
        /// �������Ʋ��ҿؼ�
        /// </summary>
        /// <param name="name">����</param>
        /// <returns>�ؼ�</returns>
        public FCView findControl(String name) {
            return findControl(name, m_controls);
        }

        /// <summary>
        /// ���ݿؼ�����Ԥ�����¼��Ŀؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>�ؼ�</returns>
        private FCView findPreviewsControl(FCView control) {
            if (control.AllowPreviewsEvent) {
                return control;
            }
            else {
                FCView parent = control.Parent;
                if (parent != null) {
                    return findPreviewsControl(parent);
                }
                else {
                    return control;
                }
            }
        }

        /// <summary>
        /// ���ݿؼ����Ҵ���
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>����</returns>
        private FCView findWindow(FCView control) {
            if (control.IsWindow) {
                return control;
            }
            else {
                FCView parent = control.Parent;
                if (parent != null) {
                    return findWindow(parent);
                }
                else {
                    return control;
                }
            }
        }

        /// <summary>
        /// ��ȡ�ؼ����ϵĿ���
        /// </summary>
        /// <returns>�ؼ�����</returns>
        public ArrayList<FCView> getControls() {
            return m_controls;
        }

        /// <summary>
        /// ��ȡ����ؼ�
        /// </summary>
        /// <param name="controls">�ؼ�����</param>
        /// <returns>����ؼ�</returns>
        private FCView getFocusedControl(ArrayList<FCView> controls) {
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                if (control.Focused) {
                    return control;
                }
                else {
                    //�����ӿؼ�
                    ArrayList<FCView> subControls = control.getControls();
                    if (subControls != null && subControls.size() > 0) {
                        FCView focusedControl = getFocusedControl(subControls);
                        if (focusedControl != null) {
                            return focusedControl;
                        }
                    }
                }
            }
            return null;
        }

        /// <summary>
        /// ��ȡ���Ƶ�͸����
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>͸����</returns>
        private float GetPaintingOpacity(FCView control) {
            float opacity = control.Opacity;
            FCView parent = control.Parent;
            if (parent != null) {
                opacity *= GetPaintingOpacity(parent);
            }
            else {
                opacity *= m_opacity;
            }
            return opacity;
        }

        /// <summary>
        /// ��ȡ���Ƶ���Դ·��
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>·��</returns>
        private String getPaintingResourcePath(FCView control) {
            String resourcePath = control.ResourcePath;
            if (resourcePath != null && resourcePath.Length > 0) {
                return resourcePath;
            }
            else {
                FCView parent = control.Parent;
                if (parent != null) {
                    return getPaintingResourcePath(parent);
                }
                else {
                    return m_resourcePath;
                }
            }
        }

        /// <summary>
        /// ��ȡ�����Ŀؼ�����
        /// </summary>
        /// <param name="parent">���ؼ�</param>
        /// <param name="sortedControls">�����Ŀؼ�</param>
        /// <returns>״̬</returns>
        private bool getSortedControls(FCView parent, ArrayList<FCView> sortedControls) {
            ArrayList<FCView> controls = null;
            if (parent != null) {
                controls = parent.getControls();
            }
            else {
                controls = m_controls;
            }
            int controlSize = controls.size();
            int index = 0;
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                if (control.Visible) {
                    if (control.TopMost) {
                        sortedControls.add(control);
                    }
                    else {
                        sortedControls.Insert(index, control);
                        index++;
                    }
                }
            }
            return sortedControls.size() > 0;
        }

        /// <summary>
        /// ��ȡTabStop����ΪTRUE�Ŀؼ�
        /// </summary>
        /// <param name="control"></param>
        private void getTabStopControls(FCView control, ArrayList<FCView> tabStopControls) {
            ArrayList<FCView> controls = control.getControls();
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView subControl = controls.get(i);
                if (!subControl.IsWindow) {
                    if (subControl.Enabled && subControl.TabStop) {
                        tabStopControls.add(subControl);
                    }
                    getTabStopControls(subControl, tabStopControls);
                }
            }
        }

        /// <summary>
        /// �ж��Ƿ���ƿ���״̬
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <returns>�Ƿ���ƿ���״̬</returns>
        private bool isPaintEnabled(FCView control) {
            if (control.Enabled) {
                FCView parent = control.Parent;
                if (parent != null) {
                    return isPaintEnabled(parent);
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        }

        /// <summary>
        /// ����ؼ�
        /// </summary>
        /// <param name="index">����</param>
        /// <param name="control">�ؼ�</param>
        public void insertControl(int index, FCView control) {
            m_controls.Insert(index, control);
        }

        /// <summary>
        /// ʹ�û������ͼ�󣬲����¼����ͼ�ṹ
        /// </summary>
        public virtual void invalidate() {
            if (m_host != null) {
                m_host.invalidate();
            }
        }

        /// <summary>
        /// �ֲ���ͼ
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void invalidate(FCView control) {
            if (m_host != null) {
                int clX = clientX(control);
                int clY = clientY(control);
                m_host.invalidate(new FCRect(clX, clY, clX + control.Width, clY + control.Height));
                ArrayList<FCNative> mirrors = null;
                if (m_mirrorMode == FCMirrorMode.Shadow) {
                    clX = m_mirrorHost.clientX(control);
                    clY = m_mirrorHost.clientY(control);
                    m_mirrorHost.Host.invalidate(new FCRect(clX, clY, clX + control.Width, clY + control.Height));
                    mirrors = m_mirrorHost.Mirrors;
                }
                else {
                    mirrors = m_mirrors;
                }
                int mirrorsSize = mirrors.size();
                for (int i = 0; i < mirrorsSize; i++) {
                    if (mirrors.get(i) != this && mirrors.get(i).MirrorMode != FCMirrorMode.BugHole) {
                        clX = mirrors.get(i).clientX(control);
                        clY = mirrors.get(i).clientY(control);
                        mirrors.get(i).Host.invalidate(new FCRect(clX, clY, clX + control.Width, clY + control.Height));
                    }
                }
            }
        }

        /// <summary>
        /// �ֲ���ͼ
        /// </summary>
        /// <param name="rect"> ����</param>
        public void invalidate(FCRect rect) {
            if (m_host != null) {
                m_host.invalidate(rect);
            }
        }

        /// <summary>
        /// �������뷽��
        /// </summary>
        /// <param name="key">����</param>
        /// <returns>�Ƿ���</returns>
        public bool onChar(char key) {
            FCView focusedControl = FocusedControl;
            if (focusedControl != null && isPaintEnabled(focusedControl)) {
                if (focusedControl.TabStop) {
                    FCView window = findWindow(focusedControl);
                    if (window != null) {
                        if (!(m_host.isKeyPress(0x10) || m_host.isKeyPress(0x11)) && key == 9) {
                            ArrayList<FCView> tabStopControls = new ArrayList<FCView>();
                            getTabStopControls(window, tabStopControls);
                            int size = tabStopControls.size();
                            if (size > 0) {
                                //����
                                for (int i = 0; i < size - 1; i++) {
                                    for (int j = 0; j < size - 1 - i; j++) {
                                        FCView controlLeft = tabStopControls.get(j);
                                        FCView controlRight = tabStopControls.get(j + 1);
                                        if (controlLeft.TabIndex > controlRight.TabIndex) {
                                            FCView temp = tabStopControls.get(j + 1);
                                            tabStopControls.set(j + 1, tabStopControls.get(j));
                                            tabStopControls.set(j, temp);
                                        }
                                    }
                                }
                                //�ҵ���һ���ؼ�
                                bool change = false;
                                FCView newFocusedControl = null;
                                for (int i = 0; i < size; i++) {
                                    FCView control = tabStopControls.get(i);
                                    if (focusedControl == control) {
                                        if (i < size - 1) {
                                            newFocusedControl = tabStopControls.get(i + 1);
                                        }
                                        else {
                                            newFocusedControl = tabStopControls.get(0);
                                        }
                                        change = true;
                                        break;
                                    }
                                }
                                if (!change) {
                                    newFocusedControl = tabStopControls.get(0);
                                }
                                //ת�ƽ���
                                if (newFocusedControl != focusedControl) {
                                    newFocusedControl.Focused = true;
                                    focusedControl = newFocusedControl;
                                    focusedControl.onTabStop();
                                    window.invalidate();
                                    return true;
                                }
                            }
                        }
                    }
                }
                focusedControl.onChar(key);
            }
            return false;
        }

        /// <summary>
        /// ����˫��
        /// </summary>
        /// <param name="button">��ť</param>
        /// <param name="clicks">�������</param>
        /// <param name="delta">����ֵ</param>
        public void onDoubleClick(FCTouchInfo touchInfo) {
            FCView focusedControl = FocusedControl;
            if (focusedControl != null && isPaintEnabled(focusedControl)) {
                FCPoint mp = TouchPoint;
                int clx = clientX(focusedControl);
                int cly = clientY(focusedControl);
                FCPoint cmp = new FCPoint(mp.x - clx, mp.y - cly);
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = cmp;
                newTouchInfo.m_secondPoint = cmp;
                focusedControl.onDoubleClick(newTouchInfo);
            }
        }

        /// <summary>
        /// ������̰���
        /// </summary>
        /// <param name="key">����</param>
        public void onKeyDown(char key) {
            FCView focusedControl = FocusedControl;
            if (focusedControl != null && isPaintEnabled(focusedControl)) {
                focusedControl.onKeyDown(key);
            }
        }

        /// <summary>
        /// �������̧��
        /// </summary>
        /// <param name="key">����</param>
        public void onKeyUp(char key) {
            FCView focusedControl = FocusedControl;
            if (focusedControl != null && isPaintEnabled(focusedControl)) {
                focusedControl.onKeyUp(key);
            }
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onMouseDown(FCTouchInfo touchInfo) {
            m_draggingControl = null;
            m_touchDownControl = null;
            FCPoint mp = TouchPoint;
            m_touchDownPoint = mp;
            ArrayList<FCView> subControls = new ArrayList<FCView>();
            getSortedControls(null, subControls);
            FCView control = findControl(mp, subControls);
            subControls.clear();
            if (control != null) {
                //�������ö�
                FCView window = findWindow(control);
                if (window != null && window.IsWindow) {
                    window.bringToFront();
                }
                if (isPaintEnabled(control)) {
                    int clx = clientX(control);
                    int cly = clientY(control);
                    FCPoint cmp = new FCPoint(mp.x - clx, mp.y - cly);
                    FCView focusedControl = FocusedControl;
                    //�����¼�
                    m_touchDownControl = control;
                    if (focusedControl == FocusedControl) {
                        if (control.CanFocus) {
                            if (touchInfo.m_firstTouch) {
                                //ѡ�пؼ�
                                FocusedControl = control;
                            }
                        }
                    }
                    if (onPreviewTouchEvent(FCEventID.TOUCHDOWN, m_touchDownControl, touchInfo)) {
                        return;
                    }
                    FCTouchInfo newTouchInfo = touchInfo.clone();
                    newTouchInfo.m_firstPoint = cmp;
                    newTouchInfo.m_secondPoint = cmp;
                    m_touchDownControl.onTouchDown(newTouchInfo);
                    if (m_touchDownControl != null) {
                        m_touchDownControl.onDragReady(ref m_dragStartOffset);
                    }
                }
            }
        }

        /// <summary>
        /// �����뿪�¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onMouseLeave(FCTouchInfo touchInfo) {
            //���ô����뿪�¼�
            if (m_touchMoveControl != null && isPaintEnabled(m_touchMoveControl)) {
                FCPoint mp = TouchPoint;
                FCPoint cmp = new FCPoint(mp.x - clientX(m_touchMoveControl), mp.y - clientY(m_touchMoveControl));
                FCView touchMoveControl = m_touchMoveControl;
                m_touchMoveControl = null;
                if (onPreviewTouchEvent(FCEventID.TOUCHLEAVE, m_touchDownControl, touchInfo)) {
                    return;
                }
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = cmp;
                newTouchInfo.m_secondPoint = cmp;
                touchMoveControl.onTouchLeave(newTouchInfo);
            }
        }

        /// <summary>
        /// �����ƶ��¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onMouseMove(FCTouchInfo touchInfo) {
            FCPoint mp = TouchPoint;
            //���¿ؼ�ʱ
            if (m_touchDownControl != null) {
                if (onPreviewTouchEvent(FCEventID.TOUCHMOVE, m_touchDownControl, touchInfo)) {
                    return;
                }
                FCPoint cmp = new FCPoint(mp.x - clientX(m_touchDownControl), mp.y - clientY(m_touchDownControl));
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = cmp;
                newTouchInfo.m_secondPoint = cmp;
                m_touchDownControl.onTouchMove(newTouchInfo);
                setCursor(m_touchDownControl);
                //�϶�
                if (m_touchDownControl.AllowDrag && newTouchInfo.m_firstTouch && newTouchInfo.m_clicks == 1) {
                    if (Math.Abs(mp.x - m_touchDownPoint.x) > m_dragStartOffset.x
                        || Math.Abs(mp.y - m_touchDownPoint.y) > m_dragStartOffset.y) {
                        //�����¼�
                        if (m_touchDownControl.onDragBegin()) {
                            m_dragBeginRect = m_touchDownControl.Bounds;
                            m_dragBeginPoint = m_touchDownPoint;
                            m_draggingControl = m_touchDownControl;
                            m_touchDownControl = null;
                            FCView parent = m_draggingControl.Parent;
                            if (parent != null) {
                                parent.invalidate();
                            }
                            else {
                                invalidate();
                            }
                        }
                    }
                }
            }
            //�϶�ʱ
            else if (m_draggingControl != null) {
                FCView draggingControl = m_draggingControl;
                int offsetX = mp.x - m_dragBeginPoint.x;
                int offsetY = mp.y - m_dragBeginPoint.y;
                FCRect newBounds = m_dragBeginRect;
                newBounds.left += offsetX;
                newBounds.top += offsetY;
                newBounds.right += offsetX;
                newBounds.bottom += offsetY;
                draggingControl.Bounds = newBounds;
                //���������϶��¼�
                draggingControl.onDragging();
                FCView parent = draggingControl.Parent;
                if (parent != null) {
                    parent.invalidate();
                }
                else {
                    invalidate();
                }
            }
            else {
                ArrayList<FCView> subControls = new ArrayList<FCView>();
                getSortedControls(null, subControls);
                FCView control = findControl(mp, subControls);
                if (control != null) {
                    if (onPreviewTouchEvent(FCEventID.TOUCHMOVE, control, touchInfo)) {
                        return;
                    }
                }
                subControls.clear();
                if (m_touchMoveControl != control) {
                    //���ô����뿪�¼�
                    if (m_touchMoveControl != null && isPaintEnabled(m_touchMoveControl)) {
                        if (m_touchDownControl == null) {
                            FCPoint cmp = new FCPoint(mp.x - clientX(m_touchMoveControl), mp.y - clientY(m_touchMoveControl));
                            FCView touchMoveControl = m_touchMoveControl;
                            m_touchMoveControl = control;
                            FCTouchInfo newTouchInfo = touchInfo.clone();
                            newTouchInfo.m_firstPoint = cmp;
                            newTouchInfo.m_secondPoint = cmp;
                            touchMoveControl.onTouchLeave(newTouchInfo);
                        }
                    }
                    if (control != null && isPaintEnabled(control)) {
                        if (m_touchDownControl == null) {
                            FCPoint cmp = new FCPoint(mp.x - clientX(control), mp.y - clientY(control));
                            m_touchMoveControl = control;
                            //���ô��������¼�
                            FCTouchInfo newTouchInfo = touchInfo.clone();
                            newTouchInfo.m_firstPoint = cmp;
                            newTouchInfo.m_secondPoint = cmp;
                            control.onTouchEnter(newTouchInfo);
                            control.onTouchMove(newTouchInfo);
                            setCursor(control);
                        }
                    }
                }
                else {
                    //���ô����ƶ��¼�
                    if (control != null && isPaintEnabled(control)) {
                        FCPoint cmp = new FCPoint(mp.x - clientX(control), mp.y - clientY(control));
                        m_touchMoveControl = control;
                        FCTouchInfo newTouchInfo = touchInfo.clone();
                        newTouchInfo.m_firstPoint = cmp;
                        newTouchInfo.m_secondPoint = cmp;
                        control.onTouchMove(newTouchInfo);
                        setCursor(control);
                    }
                }
            }
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onMouseUp(FCTouchInfo touchInfo) {
            FCPoint mp = TouchPoint;
            ArrayList<FCView> subControls = new ArrayList<FCView>();
            getSortedControls(null, subControls);
            //��ȡ�������µĿؼ�
            if (m_touchDownControl != null) {
                FCView touchDownControl = m_touchDownControl;
                if (onPreviewTouchEvent(FCEventID.TOUCHUP, touchDownControl, touchInfo)) {
                    m_touchDownControl = null;
                    return;
                }
                if (m_touchDownControl != null) {
                    FCView control = findControl(mp, subControls);
                    FCPoint cmp = new FCPoint(mp.x - clientX(m_touchDownControl), mp.y - clientY(m_touchDownControl));
                    if (control != null && control == m_touchDownControl) {
                        FCTouchInfo newTouchInfo = touchInfo.clone();
                        newTouchInfo.m_firstPoint = cmp;
                        newTouchInfo.m_secondPoint = cmp;
                        m_touchDownControl.onClick(newTouchInfo);
                    }
                    else {
                        m_touchMoveControl = null;
                    }
                    //����������˫���¼�
                    if (m_touchDownControl != null) {
                        touchDownControl = m_touchDownControl;
                        m_touchDownControl = null;
                        FCTouchInfo newTouchInfo = touchInfo.clone();
                        newTouchInfo.m_firstPoint = cmp;
                        newTouchInfo.m_secondPoint = cmp;
                        touchDownControl.onTouchUp(newTouchInfo);
                    }
                }
            }
            else if (m_draggingControl != null) {
                FCPoint cmp = new FCPoint(mp.x - clientX(m_touchDownControl), mp.y - clientY(m_touchDownControl));
                FCView draggingControl = m_draggingControl;
                m_draggingControl = null;
                if (onPreviewTouchEvent(FCEventID.TOUCHUP, draggingControl, touchInfo)) {
                    return;
                }
                //����������˫���¼�
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = cmp;
                newTouchInfo.m_secondPoint = cmp;
                draggingControl.onTouchUp(newTouchInfo);
                //�����϶������¼�
                draggingControl.onDragEnd();
                FCView parent = draggingControl.Parent;
                if (parent != null) {
                    parent.invalidate();
                }
                else {
                    invalidate();
                }
            }
            subControls.clear();
        }

        /// <summary>
        /// ���������¼�
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onMouseWheel(FCTouchInfo touchInfo) {
            FCView focusedControl = FocusedControl;
            if (focusedControl != null && isPaintEnabled(focusedControl)) {
                FCPoint mp = TouchPoint;
                if (onPreviewTouchEvent(FCEventID.TOUCHWHEEL, focusedControl, touchInfo)) {
                    return;
                }
                mp.x -= clientX(focusedControl);
                mp.y -= clientY(focusedControl);
                touchInfo.m_firstPoint = mp;
                touchInfo.m_secondPoint = mp;
                focusedControl.onTouchWheel(touchInfo);
            }
        }

        /// <summary>
        /// ��ͼ����
        /// </summary>
        /// <param name="clipRect">��������</param>
        public void onPaint(FCRect clipRect) {
            ArrayList<FCView> subCotrols = new ArrayList<FCView>();
            getSortedControls(null, subCotrols);
            renderControls(clipRect, subCotrols, m_resourcePath, m_opacity);
            subCotrols.clear();
        }

        /// <summary>
        /// Ԥ��������¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <param name="key">����</param>
        /// <returns>״̬</returns>
        public bool onPreviewKeyEvent(int eventID, char key) {
            FCView focusedControl = FocusedControl;
            if (focusedControl != null && isPaintEnabled(focusedControl)) {
                FCView window = findWindow(focusedControl);
                if (window != null) {
                    return window.onPreviewsKeyEvent(eventID, key);
                }
            }
            return false;
        }

        /// <summary>
        /// Ԥ�������¼�
        /// </summary>
        /// <param name="eventID">�¼�ID</param>
        /// <param name="control">�ؼ�</param>
        /// <param name="touchInfo">������Ϣ</param>
        /// <returns></returns>
        public bool onPreviewTouchEvent(int eventID, FCView control, FCTouchInfo touchInfo) {
            FCView previewsControl = findPreviewsControl(control);
            if (previewsControl != null) {
                FCPoint mp = touchInfo.m_firstPoint;
                int clx = clientX(previewsControl);
                int cly = clientY(previewsControl);
                FCPoint wcmp = new FCPoint(mp.x - clx, mp.y - cly);
                FCTouchInfo newTouchInfo = touchInfo.clone();
                newTouchInfo.m_firstPoint = wcmp;
                newTouchInfo.m_secondPoint = wcmp;
                if (previewsControl.onPreviewsTouchEvent(eventID, newTouchInfo)) {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// ����ߴ�ı�
        /// </summary>
        public void onResize() {
            update();
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="timerID">���ID</param>
        public void onTimer(int timerID) {
            if (m_timers.containsKey(timerID)) {
                m_timers.get(timerID).onTimer(timerID);
            }
            int mirrorsSize = m_mirrors.size();
            if (mirrorsSize > 0) {
                for (int i = 0; i < mirrorsSize; i++) {
                    m_mirrors.get(i).onTimer(timerID);
                }
            }
        }

        /// <summary>
        /// ���ƿؼ�
        /// </summary>
        /// <param name="rect">����</param>
        /// <param name="controls">�ؼ�����</param>
        /// <param name="resourcePath">��Դ·��</param>
        /// <param name="opacity">͸����</param>
        private void renderControls(FCRect rect, ArrayList<FCView> controls, String resourcePath, float opacity) {
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                control.onPrePaint(m_paint, control.DisplayRect);
                FCRect destRect = new FCRect();
                int clx = clientX(control);
                int cly = clientY(control);
                FCRect bounds = new FCRect(clx, cly, clx + control.Width, cly + control.Height);
                //��ȡ�Զ���ü�����
                if (control.UseRegion) {
                    FCRect clipRect = control.Region;
                    bounds.left += clipRect.left;
                    bounds.top += clipRect.top;
                    bounds.right = bounds.left + clipRect.right - clipRect.left;
                    bounds.bottom = bounds.top + clipRect.bottom - clipRect.top;
                }
                if (control.Visible && m_host.getIntersectRect(ref destRect, ref rect, ref bounds) > 0) {
                    //���òü�
                    FCRect clipRect = new FCRect(destRect.left - clx, destRect.top - cly,
                        destRect.right - clx, destRect.bottom - cly);
                    //������Դ·��
                    String newResourcePath = control.ResourcePath;
                    if (newResourcePath == null || newResourcePath.Length == 0) {
                        newResourcePath = resourcePath;
                    }
                    //����͸����
                    float newOpacity = control.Opacity * opacity;
                    setPaint(clx, cly, clipRect, newResourcePath, newOpacity);
                    control.onPaint(m_paint, clipRect);
                    //�����ӿؼ�
                    ArrayList<FCView> subControls = new ArrayList<FCView>();
                    getSortedControls(control, subControls);
                    if (subControls != null && subControls.size() > 0) {
                        renderControls(destRect, subControls, newResourcePath, newOpacity);
                        subControls.clear();
                    }
                    setPaint(clx, cly, clipRect, newResourcePath, newOpacity);
                    control.onPaintBorder(m_paint, clipRect);
                }
            }
        }

        /// <summary>
        /// �Ƴ��ؼ�
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void removeControl(FCView control) {
            if (control == m_draggingControl) {
                m_draggingControl = null;
            }
            if (control == m_focusedControl) {
                m_focusedControl = null;
            }
            if (control == m_touchDownControl) {
                m_touchDownControl = null;
            }
            if (control == m_touchMoveControl) {
                m_touchMoveControl = null;
            }
            ArrayList<int> removeTimers = new ArrayList<int>();
            foreach (int timerID in m_timers.Keys) {
                if (m_timers.get(timerID) == control) {
                    removeTimers.add(timerID);
                }
            }
            foreach (int timerID in removeTimers) {
                stopTimer(timerID);
            }
            if (control.Parent == null) {
                m_controls.remove(control);
                control.onRemove();
            }
        }

        /// <summary>
        /// �Ƴ�����
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void removeMirror(FCView control) {
            m_mirrorHost.Mirrors.remove(this);
            m_controls.remove(control);
            control.Native = m_mirrorHost;
        }

        /// <summary>
        /// ���ؼ��ŵ���������ʾ
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void sendToBack(FCView control) {
            FCView parent = control.Parent;
            if (parent != null) {
                parent.sendChildToBack(control);
            }
            else {
                if (m_controls != null && m_controls.size() > 0) {
                    m_controls.remove(control);
                    m_controls.Insert(0, control);
                }
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="controls">�ؼ�����</param>
        public void setAlign(ArrayList<FCView> controls) {
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                if (control.DisplayOffset) {
                    FCSize parentSize = m_displaySize;
                    FCView parent = control.Parent;
                    if (parent != null) {
                        if (!(m_mirrorMode == FCMirrorMode.BugHole && controls == m_controls)) {
                            parentSize = parent.Size;
                        }
                    }
                    FCSize size = control.Size;
                    FCPadding margin = control.Margin;
                    FCPadding padding = new FCPadding();
                    if (parent != null) {
                        padding = parent.Padding;
                    }
                    if (control.Align == FCHorizontalAlign.Center) {
                        control.Left = (parentSize.cx - size.cx) / 2;
                    }
                    else if (control.Align == FCHorizontalAlign.Right) {
                        control.Left = parentSize.cx - size.cx - margin.right - padding.right;
                    }
                    if (control.VerticalAlign == FCVerticalAlign.Bottom) {
                        control.Top = parentSize.cy - size.cy - margin.bottom - padding.bottom;
                    }
                    else if (control.VerticalAlign == FCVerticalAlign.Middle) {
                        control.Top = (parentSize.cy - size.cy) / 2;
                    }
                }
            }
        }

        /// <summary>
        /// ����ê����Ϣ
        /// </summary>
        /// <param name="controls">�ؼ�����</param>
        /// <param name="oldSize">ԭ�ߴ�</param>
        public void setAnchor(ArrayList<FCView> controls, FCSize oldSize) {
            if (oldSize.cx != 0 && oldSize.cy != 0) {
                int controlSize = controls.size();
                for (int i = 0; i < controlSize; i++) {
                    FCView control = controls.get(i);
                    FCSize parentSize = m_displaySize;
                    FCView parent = control.Parent;
                    if (parent != null) {
                        if (!(m_mirrorMode == FCMirrorMode.BugHole && controls == m_controls)) {
                            parentSize = parent.Size;
                        }
                    }
                    FCAnchor anchor = control.Anchor;
                    FCRect bounds = control.Bounds;
                    setAnchor(ref bounds, ref parentSize, ref oldSize, anchor.left, anchor.top, anchor.right, anchor.bottom);
                    control.Bounds = bounds;
                }
            }
        }

        public static void setAnchor(ref FCRect bounds, ref FCSize parentSize, ref FCSize oldSize, bool anchorLeft, bool anchorTop, bool anchorRight, bool anchorBottom) {
            if (anchorRight && !anchorLeft) {
                bounds.left = bounds.left + parentSize.cx - oldSize.cx;
            }
            if (anchorBottom && !anchorTop) {
                bounds.top = bounds.top + parentSize.cy - oldSize.cy;
            }
            if (anchorRight) {
                bounds.right = bounds.right + parentSize.cx - oldSize.cx;
            }
            if (anchorBottom) {
                bounds.bottom = bounds.bottom + parentSize.cy - oldSize.cy;
            }
        }

        /// <summary>
        /// ���ù��
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void setCursor(FCView control) {
            FCCursors cursor = control.Cursor;
            if (!isPaintEnabled(control)) {
                cursor = FCCursors.Arrow;
            }
            if (this.Cursor != cursor) {
                this.Cursor = cursor;
            }
        }

        /// <summary>
        /// ���ð󶨱�Ե
        /// </summary>
        /// <param name="control">�ؼ�</param>
        public void setDock(ArrayList<FCView> controls) {
            int controlSize = controls.size();
            for (int i = 0; i < controlSize; i++) {
                FCView control = controls.get(i);
                FCSize parentSize = m_displaySize;
                FCView parent = control.Parent;
                if (parent != null) {
                    if (!(m_mirrorMode == FCMirrorMode.BugHole && controls == m_controls)) {
                        parentSize = parent.Size;
                    }
                }
                FCDockStyle dock = control.Dock;
                if (dock != FCDockStyle.None) {
                    FCPadding padding = new FCPadding();
                    if (parent != null) {
                        padding = parent.Padding;
                    }
                    FCPadding margin = control.Margin;
                    FCSize cSize = control.Size;
                    FCRect spaceRect = new FCRect();
                    spaceRect.left = padding.left + margin.left;
                    spaceRect.top = padding.top + margin.top;
                    spaceRect.right = parentSize.cx - padding.right - margin.right;
                    spaceRect.bottom = parentSize.cy - padding.bottom - margin.bottom;
                    FCRect bounds = new FCRect();
                    int dockStyle = -1;
                    if (dock == FCDockStyle.Bottom) {
                        dockStyle = 4;
                    }
                    else if (dock == FCDockStyle.Fill) {
                        dockStyle = 0;
                    }
                    else if (dock == FCDockStyle.Left) {
                        dockStyle = 1;
                    }
                    else if (dock == FCDockStyle.Right) {
                        dockStyle = 3;
                    }
                    else if (dock == FCDockStyle.Top) {
                        dockStyle = 2;
                    }
                    setDock(ref bounds, ref spaceRect, ref cSize, dockStyle);
                    control.Bounds = bounds;
                }
            }
        }

        public static void setDock(ref FCRect bounds, ref FCRect spaceRect, ref FCSize cSize, int dock) {
            if (dock == 0) {
                bounds.left = spaceRect.left;
                bounds.top = spaceRect.top;
                bounds.right = spaceRect.right;
                bounds.bottom = spaceRect.bottom;
            }
            else if (dock == 1) {
                bounds.left = spaceRect.left;
                bounds.top = spaceRect.top;
                bounds.right = bounds.left + cSize.cx;
                bounds.bottom = spaceRect.bottom;
            }
            else if (dock == 2) {
                bounds.left = spaceRect.left;
                bounds.top = spaceRect.top;
                bounds.right = spaceRect.right;
                bounds.bottom = bounds.top + cSize.cy;
            }
            else if (dock == 3) {
                bounds.left = spaceRect.right - cSize.cx;
                bounds.top = spaceRect.top;
                bounds.right = spaceRect.right;
                bounds.bottom = spaceRect.bottom;
            }
            else if (dock == 4) {
                bounds.left = spaceRect.left;
                bounds.top = spaceRect.bottom - cSize.cy;
                bounds.right = spaceRect.right;
                bounds.bottom = spaceRect.bottom;
            }
        }

        /// <summary>
        /// ���û�ͼ����
        /// </summary>
        /// <param name="offsetX">����ƫ��</param>
        /// <param name="offsetY">����ƫ��</param>
        /// <param name="clipRect">�ü�����</param>
        /// <param name="resourcePath">��Դ·��</param>
        /// <param name="opacity">͸����</param>
        private void setPaint(int offsetX, int offsetY, FCRect clipRect, String resourcePath, float opacity) {
            m_paint.setOffset(new FCPoint(offsetX, offsetY));
            m_paint.setClip(clipRect);
            m_paint.setResourcePath(resourcePath);
            m_paint.setOpacity(opacity);
        }

        /// <summary>
        /// �������
        /// </summary>
        /// <param name="control">�ؼ�</param>
        /// <param name="timerID">�����</param>
        /// <param name="interval">���</param>
        public void startTimer(FCView control, int timerID, int interval) {
            m_timers.put(timerID, control);
            if (m_host != null) {
                m_host.startTimer(timerID, interval);
            }
        }

        /// <summary>
        /// ֹͣ���
        /// </summary>
        /// <param name="timerID">�����</param>
        public void stopTimer(int timerID) {
            if (m_timers.containsKey(timerID)) {
                if (m_host != null) {
                    m_host.stopTimer(timerID);
                }
                m_timers.remove(timerID);
            }
        }

        /// <summary>
        /// ���²���
        /// </summary>
        public void update() {
            if (m_host != null) {
                FCSize oldSize = m_displaySize;
                m_displaySize = m_host.getSize();
                if (m_displaySize.cx != 0 && m_displaySize.cy != 0) {
                    setAlign(m_controls);
                    setAnchor(m_controls, oldSize);
                    setDock(m_controls);
                    int controlsSize = m_controls.size();
                    for (int i = 0; i < controlsSize; i++) {
                        m_controls.get(i).update();
                    }
                }
            }
        }
    }
}
