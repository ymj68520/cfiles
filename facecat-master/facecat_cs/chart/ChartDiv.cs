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
    /// ͼ�㣬�������������ᣬͼ�Σ����߹��ߣ�ָ������ݡ�
    /// </summary>
    [Serializable()]
    public class ChartDiv : FCProperty {
        /// <summary>
        /// ����ͼ��
        /// </summary>
        public ChartDiv() {
            //������������
            m_vGrid.Visible = false;
        }

        /// <summary>
        /// ��������
        /// </summary>
        ~ChartDiv() {
            delete();
        }

        protected bool m_allowUserPaint;

        /// <summary>
        /// ��ȡ�������Ƿ������û���ͼ
        /// </summary>
        public virtual bool AllowUserPaint {
            get { return m_allowUserPaint; }
            set { m_allowUserPaint = value; }
        }

        /// <summary>
        /// ���߹���
        /// </summary>
        protected ArrayList<FCPlot> m_plots = new ArrayList<FCPlot>();

        /// <summary>
        /// ͼ��
        /// </summary>
        protected ArrayList<BaseShape> m_shapes = new ArrayList<BaseShape>();

        private long m_backColor = FCColor.argb(0, 0, 0);

        /// <summary>
        /// ��ȡ�����ñ���ɫ
        /// </summary>
        public virtual long BackColor {
            get { return m_backColor; }
            set { m_backColor = value; }
        }

        protected long m_borderColor = FCColor.None;

        /// <summary>
        /// ��ȡ�����ñ��ߵ���ɫ
        /// </summary>
        public virtual long BorderColor {
            get { return m_borderColor; }
            set { m_borderColor = value; }
        }

        /// <summary>
        /// ��ȡ�����²��λ��
        /// </summary>
        public virtual int Bottom {
            get { return m_bounds.bottom; }
        }

        protected FCRect m_bounds = new FCRect();

        /// <summary>
        /// ��ȡ�����ò������
        /// </summary>
        public virtual FCRect Bounds {
            get { return m_bounds; }
            set { m_bounds = value; }
        }

        protected FCChart m_chart;

        /// <summary>
        /// ��ȡ���������ڲ���
        /// </summary>
        public virtual FCChart Chart {
            get { return m_chart; }
            set { m_chart = value; }
        }

        protected CrossLine m_crossLine = new CrossLine();

        /// <summary>
        /// ��ȡ������ʮ����
        /// </summary>
        public virtual CrossLine CrossLine {
            get { return m_crossLine; }
            set {
                if (m_crossLine != null) {
                    m_crossLine.delete();
                }
                m_crossLine = value;
            }
        }

        protected FCFont m_font = new FCFont();

        /// <summary>
        /// ��ȡ�����ò������
        /// </summary>
        public virtual FCFont Font {
            get { return m_font; }
            set { m_font = value; }
        }

        /// <summary>
        /// ��ȡ�߶�
        /// </summary>
        public virtual int Height {
            get { return m_bounds.bottom - m_bounds.top; }
        }

        protected ScaleGrid m_hGrid = new ScaleGrid();

        /// <summary>
        /// ��ȡ�����ú���������
        /// </summary>
        public virtual ScaleGrid HGrid {
            get { return m_hGrid; }
            set {
                if (m_hGrid != null) {
                    m_hGrid.delete();
                }
                m_hGrid = value;
            }
        }

        protected HScale m_hScale = new HScale();

        /// <summary>
        /// ��ȡ�����ú���
        /// </summary>
        public virtual HScale HScale {
            get { return m_hScale; }
            set {
                if (m_hScale != null) {
                    m_hScale.delete();
                }
                m_hScale = value;
            }
        }

        protected bool m_isDeleted;

        /// <summary>
        /// ��ȡ�������Ƿ��ѱ�����
        /// </summary>
        public virtual bool IsDeleted {
            get { return m_isDeleted; }
        }

        /// <summary>
        /// ��ȡ�����þ�������λ��
        /// </summary>
        public virtual int Left {
            get { return m_bounds.left; }
            set { m_bounds.left = value; }
        }

        protected VScale m_leftVScale = new VScale();

        /// <summary>
        /// ��ȡ������������
        /// </summary>
        public virtual VScale LeftVScale {
            get { return m_leftVScale; }
            set {
                if (m_leftVScale != null) {
                    m_leftVScale.delete();
                }
                m_leftVScale = value;
            }
        }

        /// <summary>
        /// ��ȡ�����Ҳ�ľ���
        /// </summary>
        public virtual int Right {
            get { return m_bounds.right; }
        }

        protected VScale m_rightVScale = new VScale();

        /// <summary>
        /// ��ȡ������������
        /// </summary>
        public virtual VScale RightVScale {
            get { return m_rightVScale; }
            set {
                if (m_rightVScale != null) {
                    m_rightVScale.delete();
                }
                m_rightVScale = value;
            }
        }

        protected SelectArea m_selectArea = new SelectArea();

        /// <summary>
        /// ��ȡ������ѡ�п�
        /// </summary>
        public virtual SelectArea SelectArea {
            get { return m_selectArea; }
            set {
                if (m_selectArea != null) {
                    m_selectArea.delete();
                }
                m_selectArea = value;
            }
        }

        protected bool m_selected;

        /// <summary>
        /// ��ȡ�������Ƿ�ѡ��
        /// </summary>
        public virtual bool Selected {
            get { return m_selected; }
            set { m_selected = value; }
        }

        protected bool m_showSelect = true;

        /// <summary>
        /// ��ȡ�������Ƿ����ѡ��
        /// </summary>
        public virtual bool ShowSelect {
            get { return m_showSelect; }
            set { m_showSelect = value; }
        }

        protected ChartTitleBar m_titleBar = new ChartTitleBar();

        /// <summary>
        /// ��ȡ�����ñ���
        /// </summary>
        public virtual ChartTitleBar TitleBar {
            get { return m_titleBar; }
            set {
                if (m_titleBar != null) {
                    m_titleBar.delete();
                }
                m_titleBar = value;
            }
        }

        protected ChartToolTip m_toolTip = new ChartToolTip();

        /// <summary>
        /// ��ȡ��������ʾ��
        /// </summary>
        public virtual ChartToolTip ToolTip {
            get { return m_toolTip; }
            set {
                if (m_toolTip != null) {
                    m_toolTip.delete();
                }
                m_toolTip = value;
            }
        }

        /// <summary>
        /// ��ȡ�����þ����ϲ��λ��
        /// </summary>
        public virtual int Top {
            get { return m_bounds.top; }
            set { m_bounds.top = value; }
        }

        protected float m_verticalPercent = 0;

        /// <summary>
        /// ��ȡ������������ռ����
        /// </summary>
        public virtual float VerticalPercent {
            get { return m_verticalPercent; }
            set { m_verticalPercent = value; }
        }

        protected ScaleGrid m_vGrid = new ScaleGrid();

        /// <summary>
        /// ��ȡ����������������
        /// </summary>
        public virtual ScaleGrid VGrid {
            get { return m_vGrid; }
            set {
                if (m_vGrid != null) {
                    m_vGrid.delete();
                }
                m_vGrid = value;
            }
        }

        /// <summary>
        /// ��ȡ���
        /// </summary>
        public virtual int Width {
            get { return m_bounds.right - m_bounds.left; }
        }

        protected int m_workingAreaHeight;

        /// <summary>
        /// ��ȡ�����ù�������ĸ߶�
        /// </summary>
        public virtual int WorkingAreaHeight {
            get { return m_workingAreaHeight; }
            set {
                if (value >= 0) {
                    m_workingAreaHeight = value;
                }
            }
        }

        /// <summary>
        /// ��ӻ��߹���
        /// </summary>
        /// <param name="plot">���߹���</param>
        public void addPlot(FCPlot plot) {
            m_plots.add(plot);
        }

        /// <summary>
        /// ���ͼ��
        /// </summary>
        /// <param name="shape">ͼ��</param>
        public void addShape(BaseShape shape) {
            m_shapes.add(shape);
        }

        /// <summary>
        /// �Ƿ����ͼ��
        /// </summary>
        /// <param name="shape">ͼ��</param>
        /// <returns>�Ƿ����</returns>
        public bool containsShape(BaseShape shape) {
            ArrayList<BaseShape> shapesCopy = getShapes(SortType.NONE);
            foreach (BaseShape bs in shapesCopy) {
                if (bs == shape) {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// ������Դ
        /// </summary>
        public void delete() {
            if (!m_isDeleted) {
                try {
                    if (m_shapes != null) {
                        foreach (BaseShape shape in m_shapes) {
                            shape.delete();
                        }
                        m_shapes.clear();
                    }
                    if (m_plots != null) {
                        foreach (FCPlot plot in m_plots) {
                            plot.delete();
                        }
                        m_plots.clear();
                    }
                    if (m_leftVScale != null) {
                        m_leftVScale.delete();
                    }
                    if (m_rightVScale != null) {
                        m_rightVScale.delete();
                    }
                    if (m_hScale != null) {
                        m_hScale.delete();
                    }
                    if (m_hGrid != null) {
                        m_hGrid.delete();
                    }
                    if (m_vGrid != null) {
                        m_vGrid.delete();
                    }
                    if (m_crossLine != null) {
                        m_crossLine.delete();
                    }
                    if (m_titleBar != null) {
                        m_titleBar.delete();
                    }
                    if (m_selectArea != null) {
                        m_selectArea.delete();
                    }
                    if (m_toolTip != null) {
                        m_toolTip.delete();
                    }
                }
                finally {
                    m_isDeleted = true;
                }
            }
        }

        /// <summary>
        /// ��ȡ���еĻ��߹���
        /// </summary>
        /// <returns>���л��߹���</returns>
        public ArrayList<FCPlot> getPlots(SortType sortType) {
            ArrayList<FCPlot> plist = new ArrayList<FCPlot>();
            plist.AddRange(m_plots.ToArray());
            if (sortType == SortType.ASC) {
                plist.Sort(new PlotZOrderCompareASC());
            }
            else if (sortType == SortType.DESC) {
                plist.Sort(new PlotZOrderCompareDESC());
            }
            return plist;
        }

        /// <summary>
        /// ��ȡ����ֵ
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">��������ֵ</param>
        /// <param name="type">������������</param>
        public virtual void getProperty(String name, ref String value, ref String type) {
            if (name == "allowuserpaint") {
                type = "bool";
                value = FCStr.convertBoolToStr(AllowUserPaint);
            }
            else if (name == "backcolor") {
                type = "color";
                value = FCStr.convertColorToStr(BackColor);
            }
            else if (name == "bordercolor") {
                type = "color";
                value = FCStr.convertColorToStr(BorderColor);
            }
            else if (name == "showselect") {
                type = "bool";
                value = FCStr.convertBoolToStr(ShowSelect);
            }
        }

        /// <summary>
        /// ��ȡ���������б�
        /// </summary>
        /// <returns></returns>
        public virtual ArrayList<String> getPropertyNames() {
            ArrayList<String> propertyNames = new ArrayList<String>();
            propertyNames.AddRange(new String[] { "AllowUserPaint", "BackColor", "BorderColor", "ShowSelect" });
            return propertyNames;
        }

        /// <summary>
        /// ��ȡ���е�ͼ��
        /// </summary>
        /// <param name="sortType">��������</param>
        /// <returns>ͼ�μ���</returns>
        public ArrayList<BaseShape> getShapes(SortType sortType) {
            ArrayList<BaseShape> slist = new ArrayList<BaseShape>();
            slist.AddRange(m_shapes.ToArray());
            if (sortType == SortType.ASC) {
                slist.Sort(new BaseShapeZOrderASC());
            }
            else if (sortType == SortType.DESC) {
                slist.Sort(new BaseShapeZOrderDESC());
            }
            return slist;
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="attachVScale">��������</param>
        /// <returns>������</returns>
        public VScale getVScale(AttachVScale attachVScale) {
            if (attachVScale == AttachVScale.Left) {
                return m_leftVScale;
            }
            else {
                return m_rightVScale;
            }
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="rect">����</param>
        public virtual void onPaint(FCPaint paint, FCRect rect) {

        }

        /// <summary>
        /// �Ƴ����߹���
        /// </summary>
        /// <param name="plot">���߹���</param>
        public void removePlot(FCPlot plot) {
            m_plots.remove(plot);
        }

        /// <summary>
        /// �Ƴ�ͼ��
        /// </summary>
        /// <param name="shape">ͼ��</param>
        public void removeShape(BaseShape shape) {
            if (m_shapes.Contains(shape)) {
                m_shapes.remove(shape);
            }
        }

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="name">��������</param>
        /// <param name="value">����ֵ</param>
        public virtual void setProperty(String name, String value) {
            if (name == "allowuserpaint") {
                AllowUserPaint = FCStr.convertStrToBool(value);
            }
            else if (name == "backcolor") {
                BackColor = FCStr.convertStrToColor(value);
            }
            else if (name == "bordercolor") {
                BorderColor = FCStr.convertStrToColor(value);
            }
            else if (name == "showselect") {
                ShowSelect = FCStr.convertStrToBool(value);
            }
        }
    }

    /// <summary>
    /// �Ƚ�������ε���(����)
    /// </summary>
    public class BaseShapeZOrderASC : IComparer<BaseShape> {
        /// <summary>
        /// �ȽϷ���
        /// </summary>
        /// <param name="x">����X</param>
        /// <param name="y">����Y</param>
        /// <returns>�Ƿ����</returns>
        public int Compare(BaseShape x, BaseShape y) {
            return x.ZOrder.CompareTo(y.ZOrder);
        }
    }

    /// <summary>
    /// �Ƚ�������ε���(����)
    /// </summary>
    public class BaseShapeZOrderDESC : IComparer<BaseShape> {
        /// <summary>
        /// �ȽϷ���
        /// </summary>
        /// <param name="x">����X</param>
        /// <param name="y">����Y</param>
        /// <returns>�Ƿ����</returns>
        public int Compare(BaseShape x, BaseShape y) {
            return y.ZOrder.CompareTo(x.ZOrder);
        }
    }

    /// <summary>
    /// �Ƚ�������ε���
    /// </summary>
    public class PlotZOrderCompareASC : IComparer<FCPlot> {
        /// <summary>
        /// �ȽϷ���
        /// </summary>
        /// <param name="x">���߹���X</param>
        /// <param name="y">���߹���Y</param>
        /// <returns>�Ƿ����</returns>
        public int Compare(FCPlot x, FCPlot y) {
            return x.ZOrder.CompareTo(y.ZOrder);
        }
    }

    /// <summary>
    /// �Ƚ�������ε���
    /// </summary>
    public class PlotZOrderCompareDESC : IComparer<FCPlot> {
        /// <summary>
        /// �ȽϷ���
        /// </summary>
        /// <param name="x">���߹���X</param>
        /// <param name="y">���߹���Y</param>
        /// <returns>�Ƿ����</returns>
        public int Compare(FCPlot x, FCPlot y) {
            return y.ZOrder.CompareTo(x.ZOrder);
        }
    }
}
