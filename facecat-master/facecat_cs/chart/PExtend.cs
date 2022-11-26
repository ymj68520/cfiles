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

namespace FaceCat
{
    /// <summary>
    /// ����³˹�ɲݲ�
    /// </summary>
    public sealed class AndrewsPitchfork : FCPlot
    {
        /// <summary>
        /// ��������³˹�ɲݲ�
        /// </summary>
        public AndrewsPitchfork()
        {
            PlotType = "ANDREWSPITCHFORK";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            if (m_sourceFields == null || !m_sourceFields.containsKey("CLOSE"))
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //ȡ����
            int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            int cIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            int dIndex = m_dataSource.getRowIndex(m_marks.get(3).Key);
            float x1 = px(aIndex);
            float x2 = px(bIndex);
            float x3 = px(cIndex);
            float x4 = px(dIndex);
            float y1 = py(m_dataSource.get2(aIndex, m_sourceFields.get("CLOSE")));
            float y2 = py(m_marks.get(1).Value);
            float y3 = py(m_dataSource.get2(cIndex, m_sourceFields.get("CLOSE")));
            float y4 = py(m_dataSource.get2(dIndex, m_sourceFields.get("CLOSE")));
            //�ж��Ƿ�ѡ�е�
            bool selected = selectPoint(mp, x1, y1);
            if (selected)
            {
                action = ActionType.AT1;
                return action;
            }
            selected = selectPoint(mp, x2, y2);
            if (selected)
            {
                action = ActionType.AT2;
                return action;
            }
            selected = selectPoint(mp, x3, y3);
            if (selected)
            {
                action = ActionType.AT3;
                return action;
            }
            selected = selectPoint(mp, x4, y4);
            if (selected)
            {
                action = ActionType.AT4;
                return action;
            }
            //�ж��Ƿ�ѡ������
            float k = 0, b = 0;
            selected = selectRay(mp, x1, y1, x2, y2, ref k, ref b);
            if (selected)
            {
                action = ActionType.MOVE;
                return action;
            }
            int wWidth = WorkingAreaWidth;
            //�Ǵ�ֱʱ
            if (k != 0 || b != 0)
            {
                float x3_newx = wWidth;
                if (bIndex < aIndex)
                {
                    x3_newx = 0;
                }
                b = y3 - x3 * k;
                float x3_newy = k * x3_newx + b;
                selected = selectRay(mp, x3, y3, x3_newx, x3_newy);
                if (selected)
                {
                    action = ActionType.MOVE;
                    return action;
                }
                float x4_newx = wWidth;
                if (bIndex < aIndex)
                {
                    x4_newx = 0;
                }
                b = y4 - x4 * k;
                float x4_newy = k * x4_newx + b;
                selected = selectRay(mp, x4, y4, x4_newx, x4_newy);
                if (selected)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //��ֱʱ
            else
            {
                if (y1 >= y2)
                {
                    selected = selectRay(mp, x3, y3, x3, 0);
                    if (selected)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    selected = selectRay(mp, x4, y4, x4, 0);
                    if (selected)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
                else
                {
                    int wHeight = WorkingAreaHeight;
                    selected = selectRay(mp, x3, y3, x3, wHeight);
                    if (selected)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    selected = selectRay(mp, x4, y4, x4, wHeight);
                    if (selected)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>��ʼ���Ƿ�ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            bool create = create4CandlePoints(mp);
            if (create)
            {
                m_marks.put(1, new PlotMark(m_marks.get(1).Index, m_marks.get(1).Key, getNumberValue(mp)));
            }
            return create;
        }



        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
                m_startMarks.put(3, m_marks.get(3));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            if (m_sourceFields == null || !m_sourceFields.containsKey("CLOSE"))
            {
                return;
            }
            //ȡ����
            int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            int cIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            int dIndex = m_dataSource.getRowIndex(m_marks.get(3).Key);
            float x1 = px(aIndex);
            float x2 = px(bIndex);
            float x3 = px(cIndex);
            float x4 = px(dIndex);
            //ȡY
            float y1 = py(m_dataSource.get2(aIndex, m_sourceFields.get("CLOSE")));
            float y2 = py(m_marks.get(1).Value);
            float y3 = py(m_dataSource.get2(cIndex, m_sourceFields.get("CLOSE")));
            float y4 = py(m_dataSource.get2(dIndex, m_sourceFields.get("CLOSE")));
            float k = 0, b = 0;
            lineXY(x1, y1, x2, y2, 0, 0, ref k, ref b);
            drawRay(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2, k, b);
            //��б��
            if (k != 0 || b != 0)
            {
                float x3_newx = WorkingAreaWidth;
                if (bIndex < aIndex)
                {
                    x3_newx = 0;
                }
                b = y3 - x3 * k;
                float x3_newy = k * x3_newx + b;
                drawRay(paint, lineColor, m_lineWidth, m_lineStyle, x3, y3, x3_newx, x3_newy, k, b);
                float x4_newx = WorkingAreaWidth;
                if (bIndex < aIndex)
                {
                    x4_newx = 0;
                }
                b = y4 - x4 * k;
                float x4_newy = k * x4_newx + b;
                drawRay(paint, lineColor, m_lineWidth, m_lineStyle, x4, y4, x4_newx, x4_newy, k, b);
            }
            //����ֱ��
            else
            {
                if (y1 >= y2)
                {
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x3, y3, x3, 0);
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x4, y4, x4, 0);
                }
                else
                {
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x3, y3, x3, WorkingAreaHeight);
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x4, y4, x4, WorkingAreaHeight);
                }
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
                drawSelect(paint, lineColor, x3, y3);
                drawSelect(paint, lineColor, x4, y4);
            }
        }
    }

    /// <summary>
    /// �Ƕ���
    /// </summary>
    public sealed class Angleline : FCPlot
    {
        /// <summary>
        /// �����Ƕ���
        /// </summary>
        public Angleline()
        {
            PlotType = "ANGLELINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            ArrayList<PlotMark[]> mList = new ArrayList<PlotMark[]>();
            mList.add(new PlotMark[] { m_marks.get(0), m_marks.get(1) });
            mList.add(new PlotMark[] { m_marks.get(0), m_marks.get(2) });
            int listSize = mList.size();
            for (int i = 0; i < listSize; i++)
            {
                PlotMark markA = mList.get(i)[0];
                PlotMark markB = mList.get(i)[1];
                int bIndex = m_dataSource.getRowIndex(markA.Key);
                int eIndex = m_dataSource.getRowIndex(markB.Key);
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                float y1 = py(markA.Value);
                float y2 = py(markB.Value);
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    if (i == 0)
                    {
                        action = ActionType.AT2;
                        return action;
                    }
                    else
                    {
                        action = ActionType.AT3;
                        return action;
                    }
                }
                float k = 0;
                float b = 0;
                //��ȡֱ�߲���
                lineXY(x1, y1, x2, y2, 0, 0, ref k, ref b);
                if (!(k == 0 && b == 0))
                {
                    if (mp.y / (mp.x * k + b) >= 0.9 && mp.y / (mp.x * k + b) <= 1.1)
                    {
                        if (x1 >= x2)
                        {
                            if (mp.x > x1 + 5)
                            {
                                action = ActionType.NO;
                                return action;
                            }
                        }
                        else if (x1 < x2)
                        {
                            if (mp.x < x1 - 5)
                            {
                                action = ActionType.NO;
                                return action;
                            }
                        }
                        action = ActionType.MOVE;
                        return action;
                    }
                }
                else
                {
                    if (mp.x >= x1 - m_lineWidth * 5 && mp.x <= x1 + m_lineWidth * 5)
                    {
                        if (y1 >= y2)
                        {
                            if (mp.y <= y1 - 5)
                            {
                                action = ActionType.MOVE;
                                return action;
                            }
                        }
                        else
                        {
                            if (mp.y >= y1 - 5)
                            {
                                action = ActionType.MOVE;
                                return action;
                            }
                        }
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create3Points(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            ArrayList<PlotMark[]> marks = new ArrayList<PlotMark[]>();
            marks.add(new PlotMark[] { pList.get(0), pList.get(1) });
            marks.add(new PlotMark[] { pList.get(0), pList.get(2) });
            int markSize = marks.size();
            for (int i = 0; i < markSize; i++)
            {
                PlotMark markA = marks.get(i)[0];
                PlotMark markB = marks.get(i)[1];
                float y1 = py(markA.Value);
                float y2 = py(markB.Value);
                int bIndex = m_dataSource.getRowIndex(markA.Key);
                int eIndex = m_dataSource.getRowIndex(markB.Key);
                //��ȡ����
                float[] param = getLineParams(markA, markB);
                float a = 0;
                float b = 0;
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                //�Ǵ�ֱʱ
                if (param != null)
                {
                    a = param[0];
                    b = param[1];
                    float leftX = 0;
                    float leftY = leftX * a + b;
                    float rightX = WorkingAreaWidth;
                    float rightY = rightX * a + b;
                    if (x1 >= x2)
                    {
                        drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, x2, y2);
                    }
                    else
                    {
                        drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, rightX, rightY);
                    }
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                }
                //��ֱʱ
                else
                {
                    if (y1 >= y2)
                    {
                        drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, 0);
                    }
                    else
                    {
                        drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, WorkingAreaHeight);
                    }
                }
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// ��ͷ�߶�
    /// </summary>
    public sealed class ArrowSegment : FCPlot
    {
        /// <summary>
        /// ������ͷ�߶�
        /// </summary>
        public ArrowSegment()
        {
            PlotType = "ARROWSEGMENT";
        }

        private const int ARROW_SIZE = 10;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLineParams(m_marks.get(0), m_marks.get(1));
            //������������
            if (param != null)
            {
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            else
            {
                if (mp.y >= y1 - m_lineWidth * 5 && mp.y <= y1 + m_lineWidth * 5)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 5 && mp.y <= y2 + m_lineWidth * 5)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            if (selectSegment(mp, x1, y1, x2, y2))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��  
            int y1 = (int)py(pList.get(0).Value);
            int y2 = (int)py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int x1 = (int)px(bIndex);
            int x2 = (int)px(eIndex);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
            double slopy = 0, cosy = 0, siny = 0;
            slopy = Math.Atan2((double)(y1 - y2), (double)(x1 - x2));
            cosy = Math.Cos(slopy);
            siny = Math.Sin(slopy);
            FCPoint pt1 = new FCPoint(x2, y2);
            FCPoint pt2 = new FCPoint(pt1.x + (int)(ARROW_SIZE * cosy - (ARROW_SIZE / 2.0 * siny) + 0.5),
                pt1.y + (int)(ARROW_SIZE * siny + (ARROW_SIZE / 2.0 * cosy) + 0.5));
            FCPoint pt3 = new FCPoint(pt1.x + (int)(ARROW_SIZE * cosy + ARROW_SIZE / 2.0 * siny + 0.5),
                pt1.y - (int)(ARROW_SIZE / 2.0 * cosy - ARROW_SIZE * siny + 0.5));
            FCPoint[] points = new FCPoint[3] { pt1, pt2, pt3 };
            fillPolygon(paint, lineColor, points);
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class BoxLine : Rect
    {
        /// <summary>
        /// ����������
        /// </summary>
        public BoxLine()
        {
            PlotType = "BOXLINE";
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="mp">���λ��</param>
        /// <returns>��������</returns>
        private ActionType getAction(FCPoint mp)
        {
            //��ȡ����
            double[] param = getCandleRange(m_marks);
            double nHigh = param[0];
            double nLow = param[1];
            if (param != null)
            {
                ActionType m_action = selectRect(mp, new PlotMark(0, m_marks.get(0).Key, nHigh), new PlotMark(1, m_marks.get(1).Key, nLow));
                return m_action;
            }
            return ActionType.NO;
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            action = getAction(mp);
            if (action == ActionType.AT4)
            {
                action = ActionType.AT2;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            //��ȡ����
            double[] param = getCandleRange(pList);
            double nHigh = param[0];
            double nLow = param[1];
            if (param != null)
            {
                FCRect rect = getRectangle(new PlotMark(0, pList.get(0).Key, nHigh), new PlotMark(1, pList.get(1).Key, nLow));
                int x1 = rect.left;
                int y1 = rect.top;
                int x2 = rect.right;
                int y2 = rect.bottom;
                //������
                if (rect.right-rect.left > 0 && rect.bottom-rect.top > 0)
                {
                    int rwidth = rect.right - rect.left;
                    int rheight = rect.bottom - rect.top;
                    drawRect(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x1 + rwidth, y1 + rheight);
                    //����������
                    int count = Math.Abs(bIndex - eIndex) + 1;
                    drawText(paint, "COUNT:" + count.ToString(), lineColor, m_font, x1 + 2, y1 + 2);
                    double diff = nLow - nHigh;
                    double range = 0;
                    if (nHigh != 0)
                    {
                        range = diff / nHigh;
                    }
                    String diffString = diff.ToString("0.00");
                    String rangeString = range.ToString("0.00%");
                    FCSize rangeSize = textSize(paint, rangeString, m_font);
                    drawText(paint, diffString, lineColor, m_font, x1 + rwidth + 2, y1 + 2);
                    drawText(paint, rangeString, lineColor, m_font, x1 + rwidth + 2, y1 + rheight - rangeSize.cy - 2);
                    //��ƽ��ֵ
                    if (m_sourceFields != null && m_sourceFields.containsKey("CLOSE"))
                    {
                        double[] array = m_dataSource.DATA_ARRAY(m_sourceFields.get("CLOSE"), eIndex, eIndex - bIndex + 1);
                        double avg = FCScript.avgValue(array, array.Length);
                        float yAvg = py(avg);
                        drawLine(paint, lineColor, m_lineWidth, 1, x1, yAvg, x2, yAvg);
                        String avgString = "AVG:" + avg.ToString("0.00");
                        FCSize avgSize = textSize(paint, avgString, m_font);
                        drawText(paint, avgString, lineColor, m_font, x1 + 2, yAvg - avgSize.cy - 2);
                    }
                }
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// Բ
    /// </summary>
    public class Circle : FCPlot
    {
        /// <summary>
        /// ����Բ
        /// </summary>
        public Circle()
        {
            PlotType = "CIRCLE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
            }
            else
            {
                float r = (float)(Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
                FCPoint p = new FCPoint(mp.x - x1, mp.y - y1);
                float round = p.x * p.x + p.y * p.y;
                if (round / (r * r) >= 0.9 && round / (r * r) <= 1.1)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsA(mp);
        }
        
        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float r = (float)Math.Sqrt(Math.Abs((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x1 - r, y1 - r, x1 + r, y1 + r);
            //��ѡ�е�
            if (Selected)
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ���Բ
    /// </summary>
    public sealed class CircumCircle : FCPlot
    {
        /// <summary>
        /// �������Բ
        /// </summary>
        public CircumCircle()
        {
            PlotType = "CIRCUMCIRCLE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            float y3 = py(m_marks.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            float Ox = 0, Oy = 0, r = 0;
            //��ȡԲ�Ĳ���
            FCPlot.ellipseOR(x1, y1, x2, y2, x3, y3, ref Ox, ref Oy, ref r);
            float clickX = mp.x - Ox;
            float clickY = mp.y - Oy;
            double ellipseValue = clickX * clickX + clickY * clickY;
            //ģ��ѡ��
            if (ellipseValue >= r * r * 0.8 && ellipseValue <= r * r * 1.2)
            {
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                }
                else if (selectPoint(mp, x3, y3))
                {
                    action = ActionType.AT3;
                }
                else
                {
                    action = ActionType.MOVE;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create3Points(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            float Ox = 0, Oy = 0, r = 0;
            //��ȡԲ�Ĳ���
            FCPlot.ellipseOR(x1, y1, x2, y2, x3, y3, ref Ox, ref Oy, ref r);
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, Ox - r, Oy - r, Ox + r, Oy + r);
            //��ѡ�е�
            if (Selected)
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, y2, x3, y3);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x3, y3, x1, y1);
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
                drawSelect(paint, lineColor, x3, y3);
            }
        }
    }

    /// <summary>
    /// �µ���ͷ
    /// </summary>
    public sealed class DownArrow : FCPlot
    {
        /// <summary>
        /// �����µ���ͷ
        /// </summary>
        public DownArrow()
        {
            PlotType = "DOWNARROW";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡֵ������
            double fValue = m_marks.get(0).Value;
            int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            //��ȡ�������������
            float x1 = px(aIndex);
            float y1 = py(fValue);
            //��ȡ�������
            int width = 10;
            FCRect rect = new FCRect(x1 - width / 2, y1 - width * 3 / 2, x1 + width / 2, y1);
            FCPoint mp = getTouchOverPoint();
            //�ж��Ƿ�ѡ��
            if (mp.x >= rect.left && mp.x <= rect.right && mp.y >= rect.top && mp.y <= rect.bottom)
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            double fValue = pList.get(0).Value;
            //��ȡλ�ú�����
            int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            //��ȡ�ڲ��������������
            int x1 = (int)px(aIndex);
            int y1 = (int)py(fValue);
            int width = 10;
            FCPoint point1 = new FCPoint(x1, y1);
            FCPoint point2 = new FCPoint(x1 + width / 2, y1 - width);
            FCPoint point3 = new FCPoint(x1 + width / 4, y1 - width);
            FCPoint point4 = new FCPoint(x1 + width / 4, y1 - width * 3 / 2);
            FCPoint point5 = new FCPoint(x1 - width / 4, y1 - width * 3 / 2);
            FCPoint point6 = new FCPoint(x1 - width / 4, y1 - width);
            FCPoint point7 = new FCPoint(x1 - width / 2, y1 - width);
            FCPoint[] points = new FCPoint[7] { point1, point2, point3, point4, point5, point6, point7 };
            fillPolygon(paint, lineColor, points);
            if (Selected)
            {
                drawSelect(paint, lineColor, x1 - width / 2, y1 - width * 3 / 2);
            }
        }
    }

    /// <summary>
    /// �½�45����
    /// </summary>
    public sealed class Dropline : FCPlot
    {
        /// <summary>
        /// �����½�45����
        /// </summary>
        public Dropline()
        {
            PlotType = "DROPLINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            float[] param = getDropLineParams(m_marks);
            //�ж�ѡ��
            if (param != null)
            {
                if (mp.y - param[0] * mp.x - param[1] >= m_lineWidth * -5 && mp.y - param[0] * mp.x - param[1] <= m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡֱ�ߵĲ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns></returns>
        private float[] getDropLineParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            float y1 = py(pList.get(0).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            float a = 1;
            float b = y1 - x1;
            return new float[] { a, b };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ����
            float[] param = getDropLineParams(pList);
            float a = param[0];
            float b = param[1];
            float leftX = 0;
            float leftY = leftX * a + b;
            float rightX = WorkingAreaWidth;
            float rightY = rightX * a + b;
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
        }
    }

    /// <summary>
    /// ��Բ
    /// </summary>
    public sealed class Ellipse : FCPlot
    {
        /// <summary>
        /// ������Բ
        /// </summary>
        public Ellipse()
        {
            PlotType = "ELLIPSE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ�����ĵ�������
            double fValue = m_marks.get(0).Value;
            double eValue = m_marks.get(1).Value;
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //��ȡ����
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(fValue);
            float y2 = py(eValue);
            float x = 0;
            float y = 0;
            if (x1 >= x2)
            {
                x = x2;
            }
            else
            {
                x = x2 - (x2 - x1) * 2;
            }
            if (y1 >= y2)
            {
                y = y1 - (y1 - y2) * 2;
            }
            else
            {
                y = y1;
            }
            //��������
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
                return action;
            }
            //��������
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            //��ȡ��Բ�ļ�������
            float width = Math.Abs((x1 - x2) * 2);
            float height = Math.Abs((y1 - y2) * 2);
            float oX = x + width / 2;
            float oY = y + height / 2;
            float a = 0;
            float b = 0;
            //�������
            FCPlot.ellipseAB(width, height, ref a, ref b);
            //����Բ��һ�����ʱ��
            if (a != 0 && b != 0)
            {
                float clickX = mp.x - oX;
                float clickY = mp.y - oY;
                double ellipseValue = clickX * clickX / (a * a) + clickY * clickY / (b * b);
                //ģ��ѡ��
                if (ellipseValue >= 0.8 && ellipseValue <= 1.2)
                {
                    action = ActionType.MOVE;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.AT1)
                {
                    Cursor = FCCursors.SizeNS;
                }
                else if (m_action == ActionType.AT2)
                {
                    Cursor = FCCursors.SizeWE;
                }
                else
                {
                    Cursor = FCCursors.Hand;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ�����ֵ������
            double fValue = pList.get(0).Value;
            double eValue = pList.get(1).Value;
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            //��ȡ�ڲ�λ��
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(fValue);
            float y2 = py(eValue);
            float x = x1 - (x1 - x2);
            float y = 0;
            float width = (x1 - x2) * 2;
            float height = 0;
            if (y1 >= y2)
                height = (y1 - y2) * 2;
            else
                height = (y2 - y1) * 2;
            y = y2 - height / 2;
            if (width == 0)
                width = 1;
            if (height == 0)
                height = 1;
            if (width == 1 && height == 1)
            {
                drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x - 2, y - 2, x + 2, y + 2);
            }
            else
            {
                drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x, y, x + width, y + height);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// 쳲�Բ
    /// </summary>
    public sealed class FiboEllipse : FCPlot
    {
        /// <summary>
        /// ����쳲�Բ
        /// </summary>
        public FiboEllipse()
        {
            PlotType = "FIBOELLIPSE";
        }

        /// <summary>
        /// 쳲�Բ�Ĳ���
        /// </summary>
        /// <param name="pList">������������</param>
        /// <returns>쳲�Բ�Ĳ���</returns>
        private float[] fibonacciEllipseParam(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float r1 = (float)(Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            float r2 = r1 * 0.236f;
            float r3 = r1 * 0.382f;
            float r4 = r1 * 0.5f;
            float r5 = r1 * 0.618f;
            return new float[] { x1, y1, x2, y2, r1, r2, r3, r4, r5 };
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ�������
            FCPoint mp = getTouchOverPoint();
            float[] param = fibonacciEllipseParam(m_marks);
            float x1 = param[0];
            float y1 = param[1];
            float x2 = param[2];
            float y2 = param[3];
            //����
            if (selectPoint(mp, x1, y1) || m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            //�ڲ��
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            if (selectSegment(mp, x1, y1, x2, y2))
            {
                action = ActionType.MOVE;
                return action;
            }
            //�ж��Ƿ����ƶ��ĸ���Բ
            FCPoint p = new FCPoint(mp.x - x1, mp.y - y1);
            float round = p.x * p.x + p.y * p.y;
            for (int i = 4; i < 9; i++)
            {
                float r = param[i];
                if (round / (r * r) >= 0.9 && round / (r * r) <= 1.1)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ��ͼ��
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ�����ֵ��������Ȼ���ȡ�ڲ�λ�á�
            float[] param = fibonacciEllipseParam(pList);
            float x1 = param[0];
            float y1 = param[1];
            float x2 = param[2];
            float y2 = param[3];
            drawLine(paint, lineColor, m_lineWidth, 1, x1, y1, x2, y2);
            float r1 = param[4] >= 4 ? param[4] : 4;
            float r2 = param[5] >= 4 ? param[5] : 4;
            float r3 = param[6] >= 4 ? param[6] : 4;
            float r4 = param[7] >= 4 ? param[7] : 4;
            float r5 = param[8] >= 4 ? param[8] : 4;
            //����Բ
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x1 - r1, y1 - r1, x1 + r1, y1 + r1);
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x1 - r2, y1 - r2, x1 + r2, y1 + r2);
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x1 - r3, y1 - r3, x1 + r3, y1 + r3);
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x1 - r4, y1 - r4, x1 + r4, y1 + r4);
            drawEllipse(paint, lineColor, m_lineWidth, m_lineStyle, x1 - r5, y1 - r5, x1 + r5, y1 + r5);
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
            if (r5 > 20)
            {
                //��������
                FCSize sizeF = textSize(paint, "23.6%", m_font);
                drawText(paint, "23.6%", lineColor, m_font, x1 - sizeF.cx / 2, y1 - r1 - sizeF.cy);
                sizeF = textSize(paint, "38.2%", m_font);
                drawText(paint, "38.2%", lineColor, m_font, x1 - sizeF.cx / 2, y1 - r2 - sizeF.cy);
                sizeF = textSize(paint, "50.0%", m_font);
                drawText(paint, "50.0%", lineColor, m_font, x1 - sizeF.cx / 2, y1 - r3 - sizeF.cy);
                sizeF = textSize(paint, "61.8%", m_font);
                drawText(paint, "61.8%", lineColor, m_font, x1 - sizeF.cx / 2, y1 - r4 - sizeF.cy);
                sizeF = textSize(paint, "100%", m_font);
                drawText(paint, "100%", lineColor, m_font, x1 - sizeF.cx / 2, y1 - r5 - sizeF.cy);
            }
        }
    }

    /// <summary>
    /// 쳲�����
    /// </summary>
    public sealed class FiboFanline : FCPlot
    {
        /// <summary>
        /// ����쳲�����
        /// </summary>
        public FiboFanline()
        {
            PlotType = "FIBOFANLINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ�������
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //����
            if (selectPoint(mp, x1, y1) || m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            //����
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            //�ж�ѡ�е�
            FCPointF firstP = new FCPointF(x2, y2 - (y2 - y1) * 0.382f);
            FCPointF secondP = new FCPointF(x2, y2 - (y2 - y1) * 0.5f);
            FCPointF thirdP = new FCPointF(x2, y2 - (y2 - y1) * 0.618f);
            FCPointF startP = new FCPointF(x1, y1);
            //��ȡֱ�߲���
            bool selected = selectSegment(mp, x1, y1, x2, y2);
            if (selected)
            {
                action = ActionType.MOVE;
                return action;
            }
            if ((x2 > x1 && mp.x >= x1 - 2) || (mp.x <= x1 + 2 && x2 < x1))
            {
                if (selectRay(mp, startP.x, startP.y, firstP.x, firstP.y)
                    || selectRay(mp, startP.x, startP.y, secondP.x, secondP.y)
                    || selectRay(mp, startP.x, startP.y, thirdP.x, thirdP.y))
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ�����ֵ��������Ȼ���ȡ�ڲ�λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            drawLine(paint, lineColor, m_lineWidth, 1, x1, y1, x2, y2);
            //��ѡ��
            if (Selected || (x1 == x2))
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
            if (x1 != x2 && y1 != y2)
            {
                FCPointF firstP = new FCPointF(x2, y2 - (y2 - y1) * 0.382f);
                FCPointF secondP = new FCPointF(x2, y2 - (y2 - y1) * 0.5f);
                FCPointF thirdP = new FCPointF(x2, y2 - (y2 - y1) * 0.618f);
                FCPointF startP = new FCPointF(x1, y1);
                ArrayList<FCPointF> listP = new ArrayList<FCPointF>();
                listP.AddRange(new FCPointF[] { firstP, secondP, thirdP });
                int listSize = listP.size();
                for (int i = 0; i < listSize; i++)
                {
                    //��ȡֱ�߲���
                    float k = 0;
                    float b = 0;
                    lineXY(startP.x, startP.y, listP[i].x, listP[i].y, 0, 0, ref k, ref b);
                    float newX = 0;
                    float newY = 0;
                    if (x2 > x1)
                    {
                        newY = k * WorkingAreaWidth + b;
                        newX = WorkingAreaWidth;
                    }
                    else
                    {
                        newY = b;
                        newX = 0;
                    }
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, startP.x, startP.y, newX, newY);
                }
            }
        }
    }

    /// <summary>
    /// 쳲�������
    /// </summary>
    public sealed class FiboTimezone : FCPlot
    {
        /// <summary>
        /// ����쳲�������
        /// </summary>
        public FiboTimezone()
        {
            PlotType = "FIBOTIMEZONE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            int[] param = getFibonacciTimeZonesParam(m_marks);
            for (int i = 0; i < param.Length; i++)
            {
                //�ж�ѡ��
                int rI = (int)param[i];
                FCChart chart = Chart;
                if (rI >= chart.FirstVisibleIndex && rI <= chart.LastVisibleIndex)
                {
                    float x1 = px(rI);
                    if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ쳲������ߵĲ���
        /// </summary>
        /// <param name="pList">��������</param>
        /// <returns>쳲������ߵĲ���</returns>
        private int[] getFibonacciTimeZonesParam(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            double fValue = pList.get(0).Value;
            int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int pos = 1;
            int fibonacciValue = 1;
            ArrayList<int> fValueList = new ArrayList<int>();
            fValueList.add(aIndex);
            FCChart chart = Chart;
            while (aIndex + fibonacciValue <= chart.LastVisibleIndex)
            {
                fibonacciValue = FCScript.fibonacciValue(pos);
                fValueList.add(aIndex + fibonacciValue);
                pos++;
            }
            return fValueList.ToArray();
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ�����ֵ��������Ȼ���ȡ�ڲ�λ��
            int[] param = getFibonacciTimeZonesParam(pList);
            FCChart chart = Chart;
            for (int i = 0; i < param.Length; i++)
            {
                int rI = (int)param[i];
                if (rI >= chart.FirstVisibleIndex && rI <= chart.LastVisibleIndex)
                {
                    float x1 = px(rI);
                    //����
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
                    //��ѡ��
                    if (i == 0 && Selected)
                    {
                        drawSelect(paint, lineColor, x1, WorkingAreaHeight / 2);
                    }
                    int fValue = FCScript.fibonacciValue(i);
                    //������
                    drawText(paint, fValue.ToString(), lineColor, m_font, x1, 0);
                }
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class GannBox : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public GannBox()
        {
            PlotType = "GANNBOX";
        }

        /// <summary>
        /// ����������
        /// </summary>
        private FCPoint oppositePoint = new FCPoint();

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ��������
            return getClickStatus();
        }

        /// <summary>
        /// ��ȡѡ��״̬
        /// </summary>
        /// <returns></returns>
        private ActionType getClickStatus()
        {
            FCPoint mp = getTouchOverPoint();
            //��ȡ�������λ��
            FCRect rect = getRectangle(m_marks.get(0), m_marks.get(1));
            int x1 = rect.left;
            int y1 = rect.top;
            int x2 = rect.right;
            int y2 = rect.top;
            int x3 = rect.left;
            int y3 = rect.bottom;
            int x4 = rect.right;
            int y4 = rect.bottom;
            //�ж��Ƿ�ѡ�е�
            if (selectPoint(mp, x1, y1))
            {
                return ActionType.AT1;
            }
            else if (selectPoint(mp, x2, y2))
            {
                return ActionType.AT2;
            }
            else if (selectPoint(mp, x3, y3))
            {
                return ActionType.AT3;
            }
            else if (selectPoint(mp, x4, y4))
            {
                return ActionType.AT4;
            }
            else
            {
                int sub = (int)(m_lineWidth * 2.5);
                //�ж��Ƿ��ƶ�
                FCRect bigRect = new FCRect(rect.left - sub, rect.top - sub, rect.right + sub, rect.bottom + sub);
                if (mp.x >= bigRect.left && mp.x <= bigRect.right && mp.y >= bigRect.top && mp.y <= bigRect.bottom)
                {
                    if (rect.right - rect.left <= 4 || rect.bottom - rect.top <= 4)
                    {
                        return ActionType.MOVE;
                    }
                    else
                    {
                        FCRect smallRect = new FCRect(rect.left + sub, rect.top + sub, rect.right - sub, rect.bottom - sub);
                        if (!(mp.x >= smallRect.left && mp.x <= smallRect.right && mp.y >= smallRect.top && mp.y <= smallRect.bottom))
                        {
                            return ActionType.MOVE;
                        }
                    }
                    x1 = rect.left;
                    y1 = rect.bottom;
                    x2 = rect.right;
                    y2 = rect.top;
                    FCPoint startP = new FCPoint(x1, y1);
                    FCPoint[] listP = getGannBoxPoints(x1, y1, x2, y2);
                    bool selected;
                    for (int i = 0; i < listP.Length; i++)
                    {
                        selected = selectLine(mp, startP.x, startP.y, listP[i].x, listP[i].y);
                        if (selected) return ActionType.MOVE;
                    }
                    selected = selectLine(mp, startP.x, startP.y, x2, y2);
                    if (selected) return ActionType.MOVE;
                    x1 = rect.left;
                    y1 = rect.top;
                    x2 = rect.right;
                    y2 = rect.bottom;
                    listP = getGannBoxPoints(x1, y1, x2, y2);
                    for (int i = 0; i < listP.Length; i++)
                    {
                        selected = selectLine(mp, startP.x, startP.y, listP[i].x, listP[i].y);
                        if (selected) return ActionType.MOVE;
                    }
                    startP = new FCPoint(x1, y1);
                    selected = selectLine(mp, startP.x, startP.y, x2, y2);
                    if (selected) return ActionType.MOVE;
                }
            }
            return ActionType.NO;
        }

        /// <summary>
        /// ��ȡ���������Ҫ��
        /// </summary>
        /// <param name="x1">��һ�����X</param>
        /// <param name="y1">��һ�����Y</param>
        /// <param name="x2">�ڶ������X</param>
        /// <param name="y2">�ڶ������Y</param>
        /// <returns>���������Ҫ��</returns>
        private FCPoint[] getGannBoxPoints(float x1, float y1, float x2, float y2)
        {
            FCPoint firstP = new FCPoint(x2, y2 - (y2 - y1) * 0.875f);
            FCPoint secondP = new FCPoint(x2, y2 - (y2 - y1) * 0.75f);
            FCPoint thirdP = new FCPoint(x2, y2 - (y2 - y1) * 0.67f);
            FCPoint forthP = new FCPoint(x2, y2 - (y2 - y1) * 0.5f);
            FCPoint fifthP = new FCPoint(x2 - (x2 - x1) * 0.875f, y2);
            FCPoint sixthP = new FCPoint(x2 - (x2 - x1) * 0.75f, y2);
            FCPoint seventhP = new FCPoint(x2 - (x2 - x1) * 0.67f, y2);
            FCPoint eighthP = new FCPoint(x2 - (x2 - x1) * 0.5f, y2);
            return new FCPoint[] { firstP, secondP, thirdP, forthP, fifthP, sixthP, seventhP, eighthP };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            FCRect rect = getRectangle(m_marks.get(0), m_marks.get(1));
            int x1 = rect.left;
            int y1 = rect.top;
            int x2 = rect.right;
            int y2 = rect.top;
            int x3 = rect.left;
            int y3 = rect.bottom;
            int x4 = rect.right;
            int y4 = rect.bottom;
            //���ݲ�ͬ���ͳ�ʼ��������Ϣ
            switch (m_action)
            {
                case ActionType.AT1:
                    oppositePoint = new FCPoint(x4, y4);
                    break;
                case ActionType.AT2:
                    oppositePoint = new FCPoint(x3, y3);
                    break;
                case ActionType.AT3:
                    oppositePoint = new FCPoint(x2, y2);
                    break;
                case ActionType.AT4:
                    oppositePoint = new FCPoint(x1, y1);
                    break;
            }
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                case ActionType.AT2:
                case ActionType.AT3:
                case ActionType.AT4:
                    resize(mp, oppositePoint);
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            FCRect rect = getRectangle(pList.get(0), pList.get(1));
            int leftVScaleWidth = Chart.LeftVScaleWidth;
            int titleHeight = Div.TitleBar.Height;
            paint.setClip(new FCRect(rect.left + leftVScaleWidth, rect.top + titleHeight, rect.right + leftVScaleWidth, rect.bottom + titleHeight));
            //������
            if (rect.right - rect.left > 0 && rect.bottom - rect.top > 0)
            {
                drawRect(paint, lineColor, m_lineWidth, m_lineStyle, rect.left, rect.top, rect.right, rect.bottom);
            }
            FCPoint oP = new FCPoint(rect.left, rect.top);
            int x1 = rect.left;
            int y1 = rect.bottom;
            int x2 = rect.right;
            int y2 = rect.top;
            if (x1 != x2 && y1 != y2)
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                FCPoint startP = new FCPoint(x1, y1);
                FCPoint[] listP = getGannBoxPoints(x1, y1, x2, y2);
                float k = 0;
                float b = 0;
                for (int i = 0; i < listP.Length; i++)
                {
                    //��ȡֱ�߲���
                    lineXY(startP.x, startP.y, listP[i].x, listP[i].y, 0, 0, ref k, ref b);
                    float newX = 0;
                    float newY = 0;
                    if (x2 > x1)
                    {
                        newY = k * x2 + b;
                        newX = x2;
                    }
                    else
                    {
                        newY = b;
                        newX = x1;
                    }
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, startP.x, startP.y, newX, newY);
                }
                x1 = rect.left;
                y1 = rect.top;
                x2 = rect.right;
                y2 = rect.bottom;
                //��ȡ��Ҫ��
                listP = getGannBoxPoints(x1, y1, x2, y2);
                startP = new FCPoint(x1, y1);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                for (int i = 0; i < listP.Length; i++)
                {
                    //��ȡֱ�߲���
                    lineXY(startP.x, startP.y, listP[i].x, listP[i].y, 0, 0, ref k, ref b);
                    float newX = 0;
                    float newY = 0;
                    if (x2 > x1)
                    {
                        newY = k * x2 + b;
                        newX = x2;
                    }
                    else
                    {
                        newY = b;
                        newX = x1;
                    }
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, startP.x, startP.y, newX, newY);
                }
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, rect.left, rect.top);
                drawSelect(paint, lineColor, rect.right, rect.top);
                drawSelect(paint, lineColor, rect.left, rect.bottom);
                drawSelect(paint, lineColor, rect.right, rect.bottom);
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class GannLine : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public GannLine()
        {
            PlotType = "GANNLINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
                return action;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            //�ж��Ƿ�ѡ�е�
            bool selected = selectSegment(mp, x1, y1, x2, y2);
            if (selected)
            {
                action = ActionType.MOVE;
                return action;
            }
            FCPointF firstP = new FCPointF(x2, y2 - (y2 - y1) * 0.875f);
            FCPointF secondP = new FCPointF(x2, y2 - (y2 - y1) * 0.75f);
            FCPointF thirdP = new FCPointF(x2, y2 - (y2 - y1) * 0.67f);
            FCPointF forthP = new FCPointF(x2, y2 - (y2 - y1) * 0.5f);
            FCPointF fifthP = new FCPointF(x2 - (x2 - x1) * 0.875f, y2);
            FCPointF sixthP = new FCPointF(x2 - (x2 - x1) * 0.75f, y2);
            FCPointF seventhP = new FCPointF(x2 - (x2 - x1) * 0.67f, y2);
            FCPointF eighthP = new FCPointF(x2 - (x2 - x1) * 0.5f, y2);
            FCPointF startP = new FCPointF(x1, y1);
            ArrayList<FCPointF> listP = new ArrayList<FCPointF>();
            listP.AddRange(new FCPointF[] { firstP, secondP, thirdP, forthP, fifthP, sixthP, seventhP, eighthP });
            if ((x2 > x1 && mp.x >= x1 - 2) || (mp.x <= x1 + 2 && x2 < x1))
            {
                int listSize = listP.size();
                for (int i = 0; i < listSize; i++)
                {
                    selected = selectLine(mp, startP.x, startP.y, listP[i].x, listP[i].y);
                    if (selected)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
		/// ��ʼ�ƶ����߹���
		/// </summary>
		public override void onMoveStart()
		{
            m_moveTimes++;
			m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.AT1)
                {
                    Cursor = FCCursors.SizeNS;
                }
                else if (m_action == ActionType.AT2)
                {
                    Cursor = FCCursors.SizeNS;
                }
                else
                {
                    Cursor = FCCursors.Hand;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
		}

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            drawLine(paint, lineColor, m_lineWidth, 1, x1, y1, x2, y2);
            //��ѡ�е�
            if (Selected || (x1 == x2))
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
            //����
            if (x1 != x2 && y1 != y2)
            {
                FCPointF firstP = new FCPointF(x2, y2 - (y2 - y1) * 0.875f);
                FCPointF secondP = new FCPointF(x2, y2 - (y2 - y1) * 0.75f);
                FCPointF thirdP = new FCPointF(x2, y2 - (y2 - y1) * 0.67f);
                FCPointF forthP = new FCPointF(x2, y2 - (y2 - y1) * 0.5f);
                FCPointF fifthP = new FCPointF(x2 - (x2 - x1) * 0.875f, y2);
                FCPointF sixthP = new FCPointF(x2 - (x2 - x1) * 0.75f, y2);
                FCPointF seventhP = new FCPointF(x2 - (x2 - x1) * 0.67f, y2);
                FCPointF eighthP = new FCPointF(x2 - (x2 - x1) * 0.5f, y2);
                FCPointF startP = new FCPointF(x1, y1);
                ArrayList<FCPointF> listP = new ArrayList<FCPointF>();
                listP.AddRange(new FCPointF[] { firstP, secondP, thirdP, forthP, fifthP, sixthP, seventhP, eighthP });
                int listSize = listP.size();
                for (int i = 0; i < listSize; i++)
                {
                    float k = 0;
                    float b = 0;
                    //��ȡֱ�߲���
                    lineXY(startP.x, startP.y, listP[i].x, listP[i].y, 0, 0, ref k, ref b);
                    float newX = 0;
                    float newY = 0;
                    if (x2 > x1)
                    {
                        newY = k * WorkingAreaWidth + b;
                        newX = WorkingAreaWidth;
                    }
                    else
                    {
                        newY = b;
                        newX = 0;
                    }
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, startP.x, startP.y, newX, newY);
                }
            }
        }
    }

    /// <summary>
    /// �ƽ�ָ���
    /// </summary>
    public class GoldenRatio : FCPlot
    {
        /// <summary>
        /// �����ƽ�ָ���
        /// </summary>
        public GoldenRatio()
        {
            PlotType = "GOLDENRATIO";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ�����λ��
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            float x1 = px(bIndex);
            if (m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
            {
                if (mp.y >= y1 - m_lineWidth * 2.5f && mp.y <= y1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 2.5f && mp.y <= y2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            if (hLinesSelect(GoldenRatioParams(m_marks.get(0).Value, m_marks.get(1).Value), 6))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            switch (m_action)
            {
                case ActionType.AT1:
                    resize(0);
                    break;
                case ActionType.AT2:
                    resize(1);
                    break;
                case ActionType.MOVE:
                    double subY = mp.y - m_startPoint.y;
                    double maxValue = m_div.getVScale(m_attachVScale).VisibleMax;
                    double minValue = m_div.getVScale(m_attachVScale).VisibleMin;
                    double yAddValue = subY / WorkingAreaHeight * (minValue - maxValue);
                    m_marks.put(0, new PlotMark(0, m_startMarks.get(0).Key, m_startMarks.get(0).Value + yAddValue));
                    m_marks.put(1, new PlotMark(1, m_startMarks.get(1).Key, m_startMarks.get(1).Value + yAddValue));
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            //��ȡֱ�߲���
            float[] lineParam = GoldenRatioParams(pList.get(0).Value, pList.get(1).Value);
            String[] str = new String[] { "0.00%", "23.60%", "38.20%", "50.00%", "61.80%", "100.00%" };
            //�����ֺ���
            for (int i = 0; i < lineParam.Length; i++)
            {
                FCSize sizeF = textSize(paint, str[i], m_font);
                float yP = lineParam[i];
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, 0, yP, WorkingAreaWidth, yP);
                drawText(paint, str[i], lineColor, m_font, WorkingAreaWidth - sizeF.cx, yP - sizeF.cy);
            }
            //��ѡ��
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x1, y2);
            }
        }
    }

    /// <summary>
    /// �ƽ�ָ�Ŀ����
    /// </summary>
    public class Ga : Triangle
    {
        /// <summary>
        /// �����ƽ�ָ�Ŀ����
        /// </summary>
        public Ga()
        {
            PlotType = "GA";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = base.getAction();
            if (action != ActionType.NO)
            {
                return action;
            }
            else
            {
                //ѡ�к���
                if (hLinesSelect(getGoldenRatioAimParams(m_marks), 6))
                {
                    action = ActionType.MOVE;
                }
                return action;
            }
        }

        /// <summary>
        /// ��ȡ�ƽ�ָ��ֱ�߲���
        /// </summary>
        /// <returns></returns>
        private float[] getGoldenRatioAimParams(HashMap<int, PlotMark> pList)
        {
            //��ȡ���λ��
            double baseValue = pList.get(0).Value;
            if (pList.get(1).Value >= pList.get(2).Value)
            {
                return GoldenRatioParams(baseValue, baseValue + pList.get(1).Value - pList.get(2).Value);
            }
            else
            {
                return GoldenRatioParams(baseValue + pList.get(1).Value - pList.get(2).Value, baseValue);
            }
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            Cursor = FCCursors.Hand;
            m_startMarks.put(0, m_marks.get(0));
            m_startMarks.put(1, m_marks.get(1));
            m_startMarks.put(2, m_marks.get(2));
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int bIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int cIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            float x1 = px(aIndex);
            float x2 = px(bIndex);
            float x3 = px(cIndex);
            //����
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, y2, x3, y3);
            //��ȡֱ�߲���
            float[] lineParam = getGoldenRatioAimParams(pList);
            String[] str = new String[] { "0.00%", "23.60%", "38.20%", "50.00%", "61.80%", "100.00%" };
            //�����ֺ���
            for (int i = 0; i < lineParam.Length; i++)
            {
                FCSize sizeF = textSize(paint, str[i], m_font);
                float yP = lineParam[i];
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, 0, yP, WorkingAreaWidth, yP);
                drawText(paint, str[i], lineColor, m_font, WorkingAreaWidth - sizeF.cx, yP - sizeF.cy);
            }
            //��ѡ�е�
            if (Selected || (x1 == x2 && x2 == x3 && y1 == y2 && y2 == y3))
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
                drawSelect(paint, lineColor, x3, y3);
            }
        }
    }

    /// <summary>
    /// �ƽ�ָ��λ��
    /// </summary>
    public class Gp : FCPlot
    {
        /// <summary>
        /// �����ƽ�ָ��λ��
        /// </summary>
        public Gp()
        {
            PlotType = "GP";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ�����λ��
            float y1 = py(m_marks.get(0).Value);
            if (mp.y >= y1 - m_lineWidth * 2.5f && mp.y <= y1 + m_lineWidth * 2.5f)
            {
                action = ActionType.MOVE;
            }
            else
            {
                //�ƽ�ָ�λ
                double[] list = new double[] { 0.236, 0.382, 0.5, 0.618, 0.819, 1.191, 1.382, 1.6180, 2, 2.382, 2.618 };
                for (int i = 0; i < list.Length; i++)
                {
                    //��ȡ����
                    float yP = py(list[i] * m_marks.get(0).Value);
                    if (mp.y >= yP - m_lineWidth * 2.5f && mp.y <= yP + m_lineWidth * 2.5f)
                    {
                        action = ActionType.MOVE;
                        break;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            //����
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, 0, y1, WorkingAreaWidth, y1);
            //�ƽ�ָ�λ
            double[] list = new double[] { 0.236, 0.382, 0.5, 0.618, 0.819, 1.191, 1.382, 1.6180, 2, 2.382, 2.618 };
            for (int i = 0; i < list.Length; i++)
            {
                //��ȡ����
                float yP = py(list[i] * pList.get(0).Value);
                String str = (list[i] * 100).ToString() + "%";
                FCSize sizeF = textSize(paint, str, m_font);
                drawLine(paint, lineColor, m_lineWidth, 1, 0, yP, WorkingAreaWidth, yP);
                drawText(paint, str, lineColor, m_font, WorkingAreaWidth - sizeF.cx, yP - sizeF.cy);
            }
            //��ѡ��
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
            }
        }
    }

    /// <summary>
    /// ˮƽ��
    /// </summary>
    public sealed class HLine : FCPlot
    {
        /// <summary>
        /// ����ˮƽ��
        /// </summary>
        public HLine()
        {
            PlotType = "HLINE";
        }

        /// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            if (mp.y >= y1 - m_lineWidth * 2.5f && mp.y <= y1 + m_lineWidth * 2.5f)
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            int rIndex = m_dataSource.RowsCount;
            if (rIndex > 0)
            {
                m_marks.clear();
                double y = getNumberValue(mp);
                m_marks.put(0, new PlotMark(0, 0, y));
                return true;
            }
            return false;
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// �ƶ�
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            m_marks.put(0, new PlotMark(0, 0, getNumberValue(mp)));
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡֱ��λ��
            float y1 = py(pList.get(0).Value);
            //��ֱ��
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, 0, y1, WorkingAreaWidth, y1);
        }
    }

    /// <summary>
    /// �ߵ��Ƶ�
    /// </summary>
    public sealed class LevelGrading : FCPlot
    {
        /// <summary>
        /// �����ߵ��Ƶ�
        /// </summary>
        public LevelGrading()
        {
            PlotType = "LEVELGRADING";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ�����λ��
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            float x1 = px(bIndex);
            if (m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
            {
                if (mp.y >= y1 - m_lineWidth * 2.5f && mp.y <= y1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 2.5f && mp.y <= y2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            if (hLinesSelect(levelGradingParams(m_marks.get(0).Value, m_marks.get(1).Value), 5))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ȡ�ߵ��Ƶ���ֱ�߲���
        /// </summary>
        /// <param name="value1">ֵ1</param>
        /// <param name="value2">ֵ2</param>
        /// <returns>�ߵ��Ƶ���ֱ�߲���</returns>
        private float[] levelGradingParams(double value1, double value2)
        {
            float y1 = py(value1);
            float y2 = py(value2);
            float yA = 0, yB = 0, yC = 0, yD = 0, yE = 0;
            yA = y1;
            yB = y2;
            yC = y1 <= y2 ? y2 + (y2 - y1) * 0.382f : y2 - (y1 - y2) * 0.382f;
            yD = y1 <= y2 ? y2 + (y2 - y1) * 0.618f : y2 - (y1 - y2) * 0.618f;
            yE = y1 <= y2 ? y2 + (y2 - y1) : y2 - (y1 - y2);
            return new float[] { yA, yB, yC, yD, yE };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            switch (m_action)
            {
                case ActionType.AT1:
                    resize(0);
                    break;
                case ActionType.AT2:
                    resize(1);
                    break;
                case ActionType.MOVE:
                    double subY = mp.y - m_startPoint.y;
                    double maxValue = m_div.getVScale(m_attachVScale).VisibleMax;
                    double minValue = m_div.getVScale(m_attachVScale).VisibleMin;
                    double yAddValue = subY / WorkingAreaHeight * (minValue - maxValue);
                    m_marks.put(0, new PlotMark(0, m_startMarks.get(0).Key, m_startMarks.get(0).Value + yAddValue));
                    m_marks.put(1, new PlotMark(1, m_startMarks.get(1).Key, m_startMarks.get(1).Value + yAddValue));
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            //��ȡֱ�߲���
            float[] lineParam = levelGradingParams(pList.get(0).Value, pList.get(1).Value);
            String[] str = null;
            if (y1 >= y2)
            {
                str = new String[] { "-100%", "0.00%", "38.20%", "61.80%", "100%" };
            }
            else
            {
                str = new String[] { "100%", "0.00%", "-38.20%", "-61.80%", "-100%" };
            }
            //�����ֺ���
            for (int i = 0; i < lineParam.Length; i++)
            {
                FCSize sizeF = textSize(paint, str[i], m_font);
                float yP = lineParam[i];
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, 0, yP, WorkingAreaWidth, yP);
                drawText(paint, str[i], lineColor, m_font, WorkingAreaWidth - sizeF.cx, yP - sizeF.cy);
            }
            //��ѡ��
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x1, y2);
            }
        }
    }

    /// <summary>
    /// ֱ��
    /// </summary>
    public sealed class Line : FCPlot
    {
        /// <summary>
        /// ����ֱ��
        /// </summary>
        public Line()
        {
            PlotType = "LINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
            }
            else if (selectLine(mp, x1, y1, x2, y2))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsA(mp);
        }

        /// <summary>
		/// ��ʼ�ƶ����߹���
		/// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            //��ȡ����
            float[] param = getLineParams(pList.get(0), pList.get(1));
            float a = 0;
            float b = 0;
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            if (param != null)
            {
                a = param[0];
                b = param[1];
                float leftX = 0;
                float leftY = leftX * a + b;
                float rightX = WorkingAreaWidth;
                float rightY = rightX * a + b;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
            }
            else
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ���Իع��
    /// </summary>
    public sealed class LrBand : FCPlot
    {
        /// <summary>
        /// �������Իع��
        /// </summary>
        public LrBand()
        {
            PlotType = "LRBAND";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLRParams(m_marks);
            if (param != null)
            {
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                //�жϲ�ͬ�Ķ�������
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                //�ж�ѡ��
                if (touchIndex >= bIndex && touchIndex <= eIndex)
                {
                    double yValue = a * ((touchIndex - bIndex) + 1) + b;
                    float y = py(yValue);
                    float x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    double[] parallel = getLRBandRange(m_marks, param);
                    yValue = a * ((touchIndex - bIndex) + 1) + b + parallel[0];
                    y = py(yValue);
                    x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    yValue = a * ((touchIndex - bIndex) + 1) + b - parallel[1];
                    y = py(yValue);
                    x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡֱ�߲���
            float[] param = getLRParams(pList);
            if (param != null)
            {
                //��ȡ���λ��
                int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                //��ȡ���y
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                double[] parallel = getLRBandRange(pList, param);
                double leftTop = leftValue + parallel[0];
                double rightTop = rightValue + parallel[0];
                double leftBottom = leftValue - parallel[1];
                double rightBottom = rightValue - parallel[1];
                float leftTopY = py(leftTop);
                float rightTopY = py(rightTop);
                float leftBottomY = py(leftBottom);
                float rightBottomY = py(rightBottom);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, leftTopY, x2, rightTopY);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, leftBottomY, x2, rightBottomY);
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// �ع�ͨ��
    /// </summary>
    public sealed class LrChannel : FCPlot
    {
        /// <summary>
        /// �����ع�ͨ��
        /// </summary>
        public LrChannel()
        {
            PlotType = "LRCHANNEL";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLRParams(m_marks);
            if (param != null)
            {
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                if (touchIndex >= bIndex && touchIndex <= chart.LastVisibleIndex)
                {
                    //�ж�ѡ��
                    double yValue = a * ((touchIndex - bIndex) + 1) + b;
                    float y = py(yValue);
                    float x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    double[] parallel = getLRBandRange(m_marks, param);
                    yValue = a * ((touchIndex - bIndex) + 1) + b + parallel[0];
                    y = py(yValue);
                    x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    yValue = a * ((touchIndex - bIndex) + 1) + b - parallel[1];
                    y = py(yValue);
                    x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡֱ�߲���
            float[] param = getLRParams(pList);
            if (param != null)
            {
                //��ȡ���λ��
                int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                //��������ѡ�е�
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                double[] parallel = getLRBandRange(pList, param);
                double leftTop = leftValue + parallel[0];
                double rightTop = rightValue + parallel[0];
                double leftBottom = leftValue - parallel[1];
                double rightBottom = rightValue - parallel[1];
                float leftTopY = py(leftTop);
                float rightTopY = py(rightTop);
                float leftBottomY = py(leftBottom);
                float rightBottomY = py(rightBottom);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, leftTopY, x2, rightTopY);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, leftBottomY, x2, rightBottomY);
                FCChart chart = Chart;
                rightValue = (chart.LastVisibleIndex + 1 - bIndex) * a + b;
                float x3 = (float)((chart.LastVisibleIndex - chart.FirstVisibleIndex + 1) * chart.HScalePixel + chart.HScalePixel / 2);
                double dashTop = rightValue + parallel[0];
                double dashBottom = rightValue - parallel[1];
                float mValueY = py(rightValue);
                float dashTopY = py(dashTop);
                float dashBottomY = py(dashBottom);
                drawLine(paint, lineColor, m_lineWidth, 1, x2, rightTopY, x3, dashTopY);
                drawLine(paint, lineColor, m_lineWidth, 1, x2, rightBottomY, x3, dashBottomY);
                drawLine(paint, lineColor, m_lineWidth, 1, x2, y2, x3, mValueY);
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// ���Իع�
    /// </summary>
    public sealed class LrLine : FCPlot
    {
        /// <summary>
        /// �������Իع�
        /// </summary>
        public LrLine()
        {
            PlotType = "LRLINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ���λ��
            FCPoint mp = getTouchOverPoint();
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLRParams(m_marks);
            if (param != null)
            {
                //�ж�ѡ��
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                if (touchIndex >= bIndex && touchIndex <= eIndex)
                {
                    double yValue = a * ((touchIndex - bIndex) + 1) + b;
                    float y = py(yValue);
                    float x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡֱ�߲���
            float[] param = getLRParams(pList);
            if (param != null)
            {
                int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                //��������ѡ�е�
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }

    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class NullPoint : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public NullPoint()
        {
            PlotType = "NULLPOINT";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            double[] closeParam = getNullPointParams(m_marks);
            double leftClose = closeParam[1];
            double rightClose = closeParam[0];
            float y1 = py(leftClose);
            float y2 = py(rightClose);
            float x1 = px(bIndex >= eIndex ? bIndex : eIndex);
            float x2 = px(bIndex >= eIndex ? eIndex : bIndex);
            //��ȡ����
            float[] param = getLineParams(m_marks.get(0), m_marks.get(1));
            //������������
            if (param != null)
            {
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            else
            {
                if (mp.y >= y1 - m_lineWidth * 5 && mp.y <= y1 + m_lineWidth * 5)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 5 && mp.y <= y2 + m_lineWidth * 5)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            float x3 = 0, y3 = 0;
            if (y1 != y2)
            {
                //��һ���߶�
                nullPoint(x1, y1, x2, y2, ref x3, ref y3);
            }
            if (selectTriangle(mp, x1, y1, x2, y2, x3, y3))
            {
                action = ActionType.MOVE;
                return action;
            }
            return action;
        }

        /// <summary>
        /// ��ȡ������Ĳ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns>������Ĳ���</returns>
        private double[] getNullPointParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0 || m_sourceFields == null || m_sourceFields.size() == 0 || !m_sourceFields.containsKey("CLOSE"))
            {
                return null;
            }
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            double leftClose = 0, rightClose = 0;
            double close1 = m_dataSource.get2(bIndex, m_sourceFields.get("CLOSE"));
            double close2 = m_dataSource.get2(eIndex, m_sourceFields.get("CLOSE"));
            if (eIndex >= bIndex)
            {
                leftClose = m_dataSource.get2(bIndex, m_sourceFields.get("CLOSE"));
                rightClose = m_dataSource.get2(eIndex, m_sourceFields.get("CLOSE"));
            }
            else
            {
                leftClose = m_dataSource.get2(eIndex, m_sourceFields.get("CLOSE"));
                rightClose = m_dataSource.get2(bIndex, m_sourceFields.get("CLOSE"));
            }
            return new double[] { leftClose, rightClose };
        }

        /// <summary>
        /// ������������
        /// </summary>
        /// <param name="x1">��һ����ĺ�����</param>
        /// <param name="y1">��һ�����������</param>
        /// <param name="x2">�ڶ�����ĺ�����</param>
        /// <param name="y2">�ڶ������������</param>
        /// <param name="nullX">������ĺ�����</param>
        /// <param name="nullY">�������������</param>
        private void nullPoint(float x1, float y1, float x2, float y2, ref float nullX, ref float nullY)
        {
            float k1 = 0, k2 = 0, b1 = 0, b2 = 0;
            if (y1 >= y2)
            {
                k1 = -(float)Math.Tan(45);
                k2 = -(float)Math.Tan(60);
                b1 = y1 - k1 * x1;
                b2 = y2 - k2 * x2;
            }
            else
            {
                k1 = (float)Math.Tan(45);
                k2 = (float)Math.Tan(60);
                b1 = y1 - k1 * x1;
                b2 = y2 - k2 * x2;
            }
            nullX = (b2 - b1) / (k1 - k2);
            nullY = nullX * k1 + b1;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ�� 
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int aIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            double[] closeParam = getNullPointParams(pList);
            double leftClose = closeParam[1];
            double rightClose = closeParam[0];
            float y1 = py(leftClose);
            float y2 = py(rightClose);
            float x1 = px(bIndex >= aIndex ? bIndex : aIndex);
            float x2 = px(bIndex >= aIndex ? aIndex : bIndex);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
            float nullX = 0, nullY = 0;
            if (y1 != y2)
            {
                nullPoint(x1, y1, x2, y2, ref nullX, ref nullY);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, nullX, nullY);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, y2, nullX, nullY);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ƽ����
    /// </summary>
    public class Parallel : FCPlot
    {
        /// <summary>
        /// ����ƽ����
        /// </summary>
        public Parallel()
        {
            PlotType = "PARALLEL";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            float y3 = py(m_marks.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            //��ȡֱ�߲���
            float[] param = getParallelParams(m_marks);
            //�Ǵ�ֱ
            if (param != null)
            {
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                else if (selectPoint(mp, x3, y3))
                {
                    action = ActionType.AT3;
                    return action;
                }
                //��ֱ��
                if (mp.y - param[0] * mp.x - param[1] >= m_lineWidth * -5 && mp.y - param[0] * mp.x - param[1] <= m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
                //ƽ����
                if (mp.y - param[0] * mp.x - param[2] >= m_lineWidth * -5 && mp.y - param[0] * mp.x - param[2] <= m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //��ֱ
            else
            {
                if (mp.y >= y1 - m_lineWidth * 5 && mp.y <= y1 + m_lineWidth * 5)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 5 && mp.y <= y2 + m_lineWidth * 5)
                {
                    action = ActionType.AT2;
                    return action;
                }
                else if (mp.y >= y3 - m_lineWidth * 5 && mp.y <= y3 + m_lineWidth * 5)
                {
                    action = ActionType.AT3;
                    return action;
                }
                if (mp.x >= x1 - m_lineWidth * 5 && mp.x <= x1 + m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
                if (mp.x >= x3 - m_lineWidth * 5 && mp.x <= x3 + m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡƽ��ֱ�ߵĲ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns>ƽ��ֱ�ߵĲ���</returns>
        protected float[] getParallelParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            float a = 0;
            if (x2 - x1 != 0)
            {
                a = (y2 - y1) / (x2 - x1);
                float b = y1 - a * x1;
                float c = y3 - a * x3;
                return new float[] { a, b, c };
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create3Points(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            //��ȡ����
            float[] param = getParallelParams(pList);
            float a = 0;
            float b = 0;
            float c = 0;
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            //�Ǵ�ֱ
            if (param != null)
            {
                a = param[0];
                b = param[1];
                c = param[2];
                float leftX = 0;
                float leftY = leftX * a + b;
                float rightX = WorkingAreaWidth;
                float rightY = rightX * a + b;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
                leftY = leftX * a + c;
                rightY = rightX * a + c;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
            }
            //��ֱ
            else
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x3, 0, x3, WorkingAreaHeight);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
                drawSelect(paint, lineColor, x3, y3);
            }
        }
    }

    /// <summary>
    /// ƽ���ı���
    /// </summary>
    public class ParalleGram : FCPlot
    {
        /// <summary>
        /// ����ƽ���ı���
        /// </summary>
        public ParalleGram()
        {
            PlotType = "PARALLELOGRAM";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            if (m_moveTimes == 1)
            {
                action = ActionType.AT3;
                return action;
            }
            else
            {
                //��ȡ���λ��
                float y1 = py(m_marks.get(0).Value);
                float y2 = py(m_marks.get(1).Value);
                float y3 = py(m_marks.get(2).Value);
                int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
                int bIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
                int cIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
                float x1 = px(aIndex);
                float x2 = px(bIndex);
                float x3 = px(cIndex);
                if (selectPoint(mp, x1, y1) || m_moveTimes == 1)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                else if (selectPoint(mp, x3, y3))
                {
                    action = ActionType.AT3;
                    return action;
                }
            }
            FCPoint[] points = getPLPoints(m_marks);
            for (int i = 0; i < points.Length; i++)
            {
                int start = i;
                int end = i + 1;
                if (start == 3)
                {
                    end = 0;
                }
                if (selectRay(mp, points[start].x, points[start].y, points[end].x, points[end].y))
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ����
        /// </summary>
        /// <param name="marks">��ļ���</param>
        /// <returns>��������</returns>
        private FCPoint[] getPLPoints(HashMap<int, PlotMark> marks)
        {
            FCPoint point1 = new FCPoint(px(m_dataSource.getRowIndex(marks.get(0).Key)), py(marks.get(0).Value));
            FCPoint point2 = new FCPoint(px(m_dataSource.getRowIndex(marks.get(1).Key)), py(marks.get(1).Value));
            FCPoint point3 = new FCPoint(px(m_dataSource.getRowIndex(marks.get(2).Key)), py(marks.get(2).Value));
            float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
            x1 = point1.x;
            y1 = point1.y;
            x2 = point2.x;
            y2 = point2.y;
            x3 = point3.x;
            y3 = point3.y;
            parallelogram(x1, y1, x2, y2, x3, y3, ref x4, ref y4);
            FCPoint point4 = new FCPoint(x4, y4);
            return new FCPoint[] { point1, point2, point3, point4 };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            int rIndex = m_dataSource.RowsCount;
            if (rIndex > 0)
            {
                int currentIndex = getIndex(mp);
                double y = getNumberValue(mp);
                double date = m_dataSource.getXValue(currentIndex);
                m_marks.clear();
                m_marks.put(0, new PlotMark(0, date, y));
                int si = currentIndex + 10;
                FCChart chart = Chart;
                if (si > chart.LastVisibleIndex)
                {
                    si = chart.LastVisibleIndex;
                }
                m_marks.put(1, new PlotMark(1, m_dataSource.getXValue(si), y));
                m_marks.put(2, new PlotMark(2, date, y));
                return true;
            }
            return false;
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            FCPoint[] points = getPLPoints(pList);
            //����
            for (int i = 0; i < points.Length; i++)
            {
                int start = i;
                int end = i + 1;
                if (start == 3)
                {
                    end = 0;
                }
                float x1 = points[start].x;
                float y1 = points[start].y;
                float x2 = points[end].x;
                float y2 = points[end].y;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                //��ѡ�е�
                if (Selected && i < 3)
                {
                    drawSelect(paint, lineColor, x1, y1);
                }
            }
        }
    }

    /// <summary>
    /// �ٷֱ���
    /// </summary>
    public class Percent : FCPlot
    {
        /// <summary>
        /// �����ٷֱ���
        /// </summary>
        public Percent()
        {
            PlotType = "PERCENT";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            float x1 = px(bIndex);
            if (m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
            {
                if (mp.y >= y1 - m_lineWidth * 2.5f && mp.y <= y1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 2.5f && mp.y <= y2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            if (hLinesSelect(getPercentParams(m_marks.get(0).Value, m_marks.get(1).Value), 5))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ȡ�ٷֱ��ߵĲ���
        /// </summary>
        /// <param name="value1">ֵ1</param>
        /// <param name="value2">ֵ2</param>
        /// <returns>�ٷֱ��ߵĲ���</returns>
        protected float[] getPercentParams(double value1, double value2)
        {
            float y1 = py(value1);
            float y2 = py(value2);
            float y0 = 0, y25 = 0, y50 = 0, y75 = 0, y100 = 0;
            y0 = y1;
            y25 = y1 <= y2 ? y1 + (y2 - y1) / 4 : y2 + (y1 - y2) * 3 / 4;
            y50 = y1 <= y2 ? y1 + (y2 - y1) / 2 : y2 + (y1 - y2) / 2;
            y75 = y1 <= y2 ? y1 + (y2 - y1) * 3 / 4 : y2 + (y1 - y2) / 4;
            y100 = y2;
            return new float[] { y0, y25, y50, y75, y100 };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }


        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.AT1:
                    resize(0);
                    break;
                case ActionType.AT2:
                    resize(1);
                    break;
                case ActionType.MOVE:
                    double subY = mp.y - m_startPoint.y;
                    double maxValue = m_div.getVScale(m_attachVScale).VisibleMax;
                    double minValue = m_div.getVScale(m_attachVScale).VisibleMin;
                    double yAddValue = subY / WorkingAreaHeight * (minValue - maxValue);
                    m_marks.put(0, new PlotMark(0, m_startMarks.get(0).Key, m_startMarks.get(0).Value + yAddValue));
                    m_marks.put(1, new PlotMark(1, m_startMarks.get(1).Key, m_startMarks.get(1).Value + yAddValue));
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            //��ȡ����
            float[] lineParam = getPercentParams(pList.get(0).Value, pList.get(1).Value);
            String[] str = new String[] { "0.00%", "25.00%", "50.00%", "75.00%", "100.00%" };
            //���ߺ�����
            for (int i = 0; i < lineParam.Length; i++)
            {
                FCSize sizeF = textSize(paint, str[i], m_font);
                float yP = lineParam[i];
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, 0, yP, WorkingAreaWidth, yP);
                drawText(paint, str[i], lineColor, m_font, WorkingAreaWidth - sizeF.cx, yP - sizeF.cy);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x1, y2);
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class Periodic : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public Periodic()
        {
            PlotType = "PERIODIC";
        }

        /// <summary>
        /// ����
        /// </summary>
        private int m_period = 5;

        /// <summary>
        /// ��ʼ�ƶ�����
        /// </summary>
        private int m_beginPeriod = 1;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ���λ��
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            double[] param = getPLParams(m_marks);
            float y = WorkingAreaHeight / 2;
            for (int i = 0; i < param.Length; i++)
            {
                //�ж�ѡ��
                int rI = (int)param[i];
                float x1 = px(rI);
                if (selectPoint(mp, x1, y))
                {
                    action = ActionType.AT1;
                    m_marks.put(0, new PlotMark(0, m_dataSource.getXValue(rI), 0));
                    m_beginPeriod = m_period;
                    return action;
                }
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <param name="pList">����ļ���</param>
        /// <returns>�������������</returns>
        private double[] getPLParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            double fValue = pList.get(0).Value;
            int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            ArrayList<double> fValueList = new ArrayList<double>();
            FCChart chart = Chart;
            for (int i = chart.FirstVisibleIndex; i < chart.LastVisibleIndex; i++)
            {
                if (Math.Abs(i - aIndex) % m_period == 0)
                {
                    fValueList.add(i);
                }
            }
            return fValueList.ToArray();
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����λ��</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            int rIndex = m_dataSource.RowsCount;
            if (rIndex > 0)
            {
                int currentIndex = getIndex(mp);
                double y = getNumberValue(mp);
                double date = m_dataSource.getXValue(currentIndex);
                m_marks.clear();
                m_marks.put(0, new PlotMark(0, date, y));
                FCChart chart = Chart;
                m_period = chart.MaxVisibleRecord / 10;
                if (m_period < 1)
                {
                    m_period = 1;
                }
                return true;
            }
            return false;
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.AT1)
                {
                    Cursor = FCCursors.SizeNS;
                }
                else
                {
                    Cursor = FCCursors.Hand;
                }
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bI = getIndex(m_startPoint);
            int eI = getIndex(mp);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    m_period = m_beginPeriod + (eI - bI);
                    if (m_period < 1)
                    {
                        m_period = 1;
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ����
            double[] param = getPLParams(pList);
            for (int i = 0; i < param.Length; i++)
            {
                int rI = (int)param[i];
                float x1 = px(rI);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, WorkingAreaHeight / 2);
                }
            }
        }
    }

    /// <summary>
    /// �۸�ǩ��
    /// </summary>
    public sealed class Price : FCPlot
    {
        /// <summary>
        /// �����۸�ǩ��
        /// </summary>
        public Price()
        {
            PlotType = "PRICE";
        }

        private FCSize m_textSize;

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ���λ��
            FCPoint mp = getTouchOverPoint();
            double fValue = m_marks.get(0).Value;
            int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            float x1 = px(aIndex);
            float y1 = py(fValue);
            FCRect rect = new FCRect(x1, y1, x1 + m_textSize.cx, y1 + m_textSize.cy);
            if (mp.x >= rect.left && mp.x <= rect.right && mp.y >= rect.top && mp.y <= rect.bottom)
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            int wX = WorkingAreaWidth;
            int wY = WorkingAreaHeight;
            if (wX > 0 && wY > 0)
            {
                //��ȡ���λ��
                double fValue = pList.get(0).Value;
                int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                float x1 = px(aIndex);
                float y1 = py(fValue);
                FCChart chart = Chart;
                String word = FCStr.getValueByDigit(fValue, chart.LeftVScaleWidth > 0 ? m_div.LeftVScale.Digit : m_div.RightVScale.Digit);
                //������
                drawText(paint, word, lineColor, m_font, x1, y1);
                m_textSize = textSize(paint, word, m_font);
                if (Selected)
                {
                    if (m_textSize.cx > 0 && m_textSize.cy > 0)
                    {
                        drawRect(paint, lineColor, m_lineWidth, m_lineStyle, (int)x1, (int)y1, (int)x1 + m_textSize.cx, (int)y1 + m_textSize.cy);
                    }
                }
            }
        }
    }

    /// <summary>
    /// �۸�ͨ����
    /// </summary>
    public class PriceChannel : Parallel
    {
        /// <summary>
        /// �����۸�ͨ����
        /// </summary>
        public PriceChannel()
        {
            PlotType = "PRICECHANNEL";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = base.getAction();
            if (action != ActionType.NO)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            float k = 0, d = 0, x4 = 0;
            getLine3Params(m_marks, ref k, ref d, ref x4);
            if (k == 0 && d == 0)
            {
                if (mp.x >= x4 - m_lineWidth * 5 && mp.x <= x4 + m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                }
            }
            else
            {
                if (selectLine(mp, px(mp.x), k, d))
                {
                    action = ActionType.MOVE;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ�������ߵĲ���
        /// </summary>
        /// <param name="marks">���󼯺�</param>
        /// <param name="k">ֱ�߲���k</param>
        /// <param name="d">ֱ�߲���d</param>
        /// <param name="x4">���ĸ���ĺ�����</param>
        private void getLine3Params(HashMap<int, PlotMark> marks, ref float k, ref float d, ref float x4)
        {
            //��ȡ����
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int pIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            float x1 = px(bIndex);
            float x3 = px(pIndex);
            float[] param = getParallelParams(m_marks);
            if (param != null)
            {
                k = param[0];
                float b = param[1];
                float c = param[2];
                d = b >= c ? b + (b - c) : b - (c - b);
            }
            else
            {
                x4 = 0;
                if (x3 > x1)
                {
                    x4 = x1 - (x3 - x1);
                }
                else
                {
                    x4 = x1 + (x1 - x3);
                }
            }
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaint(FCPaint paint)
        {
            paintEx(paint, m_marks, Color);
            base.onPaint(paint);
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            paintEx(paint, m_startMarks, SelectedColor);
            base.onPaintGhost(paint);
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        private void paintEx(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            float k = 0, d = 0, x4 = 0;
            getLine3Params(m_marks, ref k, ref d, ref x4);
            if (k == 0 && d == 0)
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x4, 0, x4, WorkingAreaHeight);

            }
            else
            {
                float leftX = 0;
                float leftY = leftX * k + d;
                float rightX = WorkingAreaWidth;
                float rightY = rightX * k + d;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
            }
        }
    }

    /// <summary>
    /// �ĵȷ���
    /// </summary>
    public sealed class QuadrantLines : Percent
    {
        /// <summary>
        /// �����ĵȷ���
        /// </summary>
        public QuadrantLines()
        {
            PlotType = "QUADRANTLINES";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLRParams(m_marks);
            if (param != null)
            {
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                if (touchIndex >= bIndex && touchIndex <= eIndex)
                {
                    //�ع����ж�
                    double yValue = a * ((touchIndex - bIndex) + 1) + b;
                    float y = py(yValue);
                    float x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    //�ȷ����ж�
                    double[] candleRegion = getCandleRange(m_marks);
                    if (candleRegion != null)
                    {
                        float[] percents = getPercentParams(candleRegion[0], candleRegion[1]);
                        for (int i = 0; i < percents.Length; i++)
                        {
                            if (selectRay(mp, x1, percents[i], x2, percents[i]))
                            {
                                action = ActionType.MOVE;
                                return action;
                            }
                        }
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡֱ�߲���
            float[] param = getLRParams(pList);
            if (param != null)
            {
                int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                //��������ѡ�е�
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                //�ȷ����ж�
                double[] candleRegion = getCandleRange(pList);
                if (candleRegion != null)
                {
                    float[] percents = getPercentParams(candleRegion[0], candleRegion[1]);
                    for (int i = 0; i < percents.Length; i++)
                    {
                        float yp = percents[i];
                        if (i == 2)
                        {
                            drawLine(paint, lineColor, m_lineWidth, 1, x1, yp, x2, yp);
                        }
                        else
                        {
                            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, yp, x2, yp);
                        }
                    }
                }
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// �����ع�ͨ��
    /// </summary>
    public sealed class RaffChannel : FCPlot
    {
        /// <summary>
        /// ���������ع�ͨ��
        /// </summary>
        public RaffChannel()
        {
            PlotType = "RAFFCHANNEL";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLRParams(m_marks);
            if (param != null)
            {
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                if (touchIndex >= chart.FirstVisibleIndex && touchIndex <= chart.LastVisibleIndex)
                {
                    double yValue = a * ((touchIndex - bIndex) + 1) + b;
                    float y = py(yValue);
                    float x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    double parallel = getRRCRange(m_marks, param);
                    yValue = a * ((touchIndex - bIndex) + 1) + b + parallel;
                    y = py(yValue);
                    x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    yValue = a * ((touchIndex - bIndex) + 1) + b - parallel;
                    y = py(yValue);
                    x = px(touchIndex);
                    if (mp.x >= x - 5 && mp.x <= x + 5 && mp.y >= y - 5 && mp.y <= y + 5)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ�������Իع�ĸߵ͵�ֵ
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <param name="param">ֱ�߲���</param>
        /// <returns>�������Իع�ĸߵ͵�ֵ</returns>
        private double getRRCRange(HashMap<int, PlotMark> pList, float[] param)
        {
            if (param == null || m_sourceFields == null || m_sourceFields.size() == 0 || !m_sourceFields.containsKey("HIGH")
            || !m_sourceFields.containsKey("LOW"))
            {
                return 0;
            }
            float a = param[0];
            float b = param[1];
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            double upSubValue = 0;
            double downSubValue = 0;
            int pos = 0;
            for (int i = bIndex; i <= eIndex; i++)
            {
                double high = m_dataSource.get2(i, m_sourceFields.get("HIGH"));
                double low = m_dataSource.get2(i, m_sourceFields.get("LOW"));
                if (!double.IsNaN(high) && !double.IsNaN(low))
                {
                    double midValue = (i - bIndex + 1) * a + b;
                    if (pos == 0)
                    {
                        upSubValue = high - midValue;
                        downSubValue = midValue - low;
                    }
                    else
                    {
                        if (high - midValue > upSubValue)
                        {
                            upSubValue = high - midValue;
                        }
                        if (midValue - low > downSubValue)
                        {
                            downSubValue = midValue - low;
                        }
                    }
                    pos++;
                }
            }
            if (upSubValue >= downSubValue)
            {
                return upSubValue;
            }
            else
            {
                return downSubValue;
            }
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡֱ�߲���
            float[] param = getLRParams(pList);
            if (param != null)
            {
                //��������ѡ�е�
                float a = param[0];
                float b = param[1];
                int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
                float x1 = px(bIndex);
                float x2 = px(eIndex);
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                float[] param2 = getLineParams(new PlotMark(0, pList.get(0).Key, leftValue), new PlotMark(1, pList.get(1).Key, rightValue));
                if (param2 != null)
                {
                    //���ع���
                    a = param2[0];
                    b = param2[1];
                    float leftX = 0;
                    float leftY = leftX * a + b;
                    float rightX = WorkingAreaWidth;
                    float rightY = rightX * a + b;
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
                    //��ȡ��������
                    double parallel = getRRCRange(pList, param);
                    //������
                    double leftTop = leftValue + parallel;
                    double rightTop = rightValue + parallel;
                    param2 = getLineParams(new PlotMark(0, pList.get(0).Key, leftTop), new PlotMark(1, pList.get(1).Key, rightTop));
                    if (param2 != null)
                    {
                        a = param2[0];
                        b = param2[1];
                        leftX = 0;
                        leftY = leftX * a + b;
                        rightX = WorkingAreaWidth;
                        rightY = rightX * a + b;
                        drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
                    }
                    //������
                    double leftBottom = leftValue - parallel;
                    double rightBottom = rightValue - parallel;
                    param2 = getLineParams(new PlotMark(0, pList.get(0).Key, leftBottom), new PlotMark(1, pList.get(1).Key, rightBottom));
                    if (param2 != null)
                    {
                        a = param2[0];
                        b = param2[1];
                        leftX = 0;
                        leftY = leftX * a + b;
                        rightX = WorkingAreaWidth;
                        rightY = rightX * a + b;
                        drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
                    }
                }
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// ���ȳ�
    /// </summary>
    public sealed class RangeRuler : FCPlot
    {
        /// <summary>
        /// �������ȳ�
        /// </summary>
        public RangeRuler()
        {
            PlotType = "RANGERULER";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ��λ��
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            double[] param = getCandleRange(m_marks);
            double nHigh = param[0];
            double nLow = param[1];
            float highY = py(nHigh);
            float lowY = py(nLow);
            //��ȡ�ϴ��X�ͽ�С��X
            float smallX = x1 > x2 ? x2 : x1;
            float bigX = x1 > x2 ? x1 : x2;
            if ((mp.y >= highY - m_lineWidth * 2.5f && mp.y <= highY + m_lineWidth * 2.5f)
                || (mp.y >= lowY - m_lineWidth * 2.5f && mp.y <= lowY + m_lineWidth * 2.5f))
            {
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            //ѡ���������
            if (mp.y >= highY - m_lineWidth * 2.5f && mp.y <= highY + m_lineWidth * 2.5f)
            {
                if (mp.x >= smallX - m_lineWidth * 2.5f && mp.x <= bigX + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //ѡ���������
            else if (mp.y >= lowY - m_lineWidth * 2.5f && mp.y <= lowY + m_lineWidth * 2.5f)
            {
                if (mp.x >= smallX - m_lineWidth * 2.5f && mp.x <= bigX + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //ѡ������
            float mid = x1 >= x2 ? (x2 + (x1 - x2) / 2) : (x1 + (x2 - x1) / 2);
            if (mp.x >= mid - m_lineWidth * 2.5f && mp.x <= mid + m_lineWidth * 2.5f)
            {
                if (mp.y >= highY - m_lineWidth * 2.5f && mp.y <= lowY + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float smallX = x1 > x2 ? x2 : x1;
            float bigX = x1 > x2 ? x1 : x2;
            //��ȡ����
            double[] param = getCandleRange(pList);
            double nHigh = param[0];
            double nLow = param[1];
            float highY = py(nHigh);
            float lowY = py(nLow);
            float mid = x1 >= x2 ? (x2 + (x1 - x2) / 2) : (x1 + (x2 - x1) / 2);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, highY, x2, highY);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, lowY, x2, lowY);
            drawLine(paint, lineColor, m_lineWidth, 1, mid, lowY, mid, highY);
            if (nHigh != nLow)
            {
                //������
                double diff = Math.Abs(nLow - nHigh);
                double range = 0;
                if (nHigh != 0)
                {
                    range = diff / nHigh;
                }
                FCChart chart = Chart;
                String diffString = FCStr.getValueByDigit(diff, m_div.getVScale(m_attachVScale).Digit);
                String rangeString = range.ToString("0.00%");
                FCSize diffSize = textSize(paint, diffString, m_font);
                FCSize rangeSize = textSize(paint, rangeString, m_font);
                drawText(paint, diffString, lineColor, m_font, bigX - diffSize.cx, highY + 2);
                drawText(paint, rangeString, lineColor, m_font, bigX - rangeSize.cx, lowY - rangeSize.cy);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, smallX, highY);
                drawSelect(paint, lineColor, smallX, lowY);
                drawSelect(paint, lineColor, bigX, highY);
                drawSelect(paint, lineColor, bigX, lowY);
            }
        }
    }

    /// <summary>
    /// ����45����
    /// </summary>
    public sealed class RaseLine : FCPlot
    {
        /// <summary>
        /// ��������45����
        /// </summary>
        public RaseLine()
        {
            PlotType = "RASELINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ����
            float[] param = getRaseLineParams(m_marks);
            //�ж�ѡ��
            if (param != null)
            {
                if (mp.y - param[0] * mp.x - param[1] >= m_lineWidth * -5 && mp.y - param[0] * mp.x - param[1] <= m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡֱ�ߵĲ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns></returns>
        private float[] getRaseLineParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            float y1 = py(pList.get(0).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            float a = -1;
            float b = y1 + x1;
            return new float[] { a, b };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ����
            float[] param = getRaseLineParams(pList);
            float a = param[0];
            float b = param[1];
            float leftX = 0;
            float leftY = leftX * a + b;
            float rightX = WorkingAreaWidth;
            float rightY = rightX * a + b;
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public sealed class Ray : FCPlot
    {
        /// <summary>
        /// ��������
        /// </summary>
        public Ray()
        {
            PlotType = "RAY";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //�ж�ѡ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            //��ȡֱ�߲���
            float[] param = getLineParams(m_marks.get(0), m_marks.get(1));
            if (param != null)
            {
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            else
            {
                if (mp.y >= y1 - m_lineWidth * 5 && mp.y <= y1 + m_lineWidth * 5)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 5 && mp.y <= y2 + m_lineWidth * 5)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            if (selectRay(mp, x1, y1, x2, y2))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsA(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float k = 0;
            float b = 0;
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            lineXY(x1, y1, x2, y2, 0, 0, ref k, ref b);
            drawRay(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2, k, b);
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ����
    /// </summary>
    public class Rect : FCPlot
    {
        /// <summary>
        /// ��������
        /// </summary>
        public Rect()
        {
            PlotType = "FCRect";
        }

        /// <summary>
        /// ����������
        /// </summary>
        private FCPoint oppositePoint = new FCPoint();

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            action = selectRect(mp, m_marks.get(0), m_marks.get(1));
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>��ʼ���Ƿ�ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            if (m_action != ActionType.MOVE && m_action != ActionType.NO)
            {
                //��ȡ�ĸ����λ��
                FCRect rect = getRectangle(m_marks.get(0), m_marks.get(1));
                int x1 = rect.left;
                int y1 = rect.top;
                int x2 = rect.right;
                int y2 = rect.top;
                int x3 = rect.left;
                int y3 = rect.bottom;
                int x4 = rect.right;
                int y4 = rect.bottom;
                //���ݶ����������ñ���
                switch (m_action)
                {
                    case ActionType.AT1:
                        oppositePoint = new FCPoint(x4, y4);
                        break;
                    case ActionType.AT2:
                        oppositePoint = new FCPoint(x3, y3);
                        break;
                    case ActionType.AT3:
                        oppositePoint = new FCPoint(x2, y2);
                        break;
                    case ActionType.AT4:
                        oppositePoint = new FCPoint(x1, y1);
                        break;
                }
            }
            m_moveTimes++;
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                case ActionType.AT2:
                case ActionType.AT3:
                case ActionType.AT4:
                    resize(mp, oppositePoint);
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            FCRect rect = getRectangle(pList.get(0), pList.get(1));
            //������
            if (rect.right - rect.left > 0 && rect.bottom - rect.top > 0)
            {
                drawRect(paint, lineColor, m_lineWidth, m_lineStyle, rect.left, rect.top, rect.right, rect.bottom);
            }
            //��ѡ�еĵ�
            if (Selected)
            {
                drawSelect(paint, lineColor, rect.left, rect.top);
                drawSelect(paint, lineColor, rect.right, rect.top);
                drawSelect(paint, lineColor, rect.left, rect.bottom);
                drawSelect(paint, lineColor, rect.right, rect.bottom);
            }
        }
    }

    /// <summary>
    /// �߶�
    /// </summary>
    public sealed class Segment : FCPlot
    {
        /// <summary>
        /// �����߶�
        /// </summary>
        public Segment()
        {
            PlotType = "SEGMENT";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLineParams(m_marks.get(0), m_marks.get(1));
            //������������
            if (param != null)
            {
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            else
            {
                if (mp.y >= y1 - m_lineWidth * 5 && mp.y <= y1 + m_lineWidth * 5)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 5 && mp.y <= y2 + m_lineWidth * 5)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            if (selectSegment(mp, x1, y1, x2, y2))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��  
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class Sine : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public Sine()
        {
            PlotType = "SINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡѡ�е�
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //�ж�ѡ��
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
                return action;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            if (selectSine(mp, x1, y1, x2, y2))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            int rIndex = m_dataSource.RowsCount;
            if (rIndex > 0)
            {
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                if (touchIndex >= 0 && touchIndex <= chart.LastVisibleIndex)
                {
                    int eIndex = touchIndex;
                    int bIndex = eIndex - chart.MaxVisibleRecord / 10;
                    if (bIndex >= 0 && eIndex != bIndex)
                    {
                        double fDate = m_dataSource.getXValue(bIndex);
                        double sDate = m_dataSource.getXValue(eIndex);
                        m_marks.clear();
                        double y = getNumberValue(mp);
                        m_marks.put(0, new PlotMark(0, fDate, y + (m_div.getVScale(m_attachVScale).VisibleMax - m_div.getVScale(m_attachVScale).VisibleMin) / 4));
                        m_marks.put(1, new PlotMark(1, sDate, y));
                        return true;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.AT1)
                {
                    Cursor = FCCursors.SizeNS;
                }
                else if (m_action == ActionType.AT2)
                {
                    Cursor = FCCursors.SizeWE;
                }
                else
                {
                    Cursor = FCCursors.Hand;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            double fValue = pList.get(0).Value;
            double eValue = pList.get(1).Value;
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int x1 = (int)px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(fValue);
            float y2 = py(eValue);
            //����
            double f = 2.0 * Math.PI / ((x2 - x1) * 4);
            if (x1 != x2)
            {
                int len = WorkingAreaWidth;
                if (len > 0)
                {
                    FCPoint[] pf = new FCPoint[len];
                    for (int i = 0; i < len; i++)
                    {
                        int x = -x1 + i;
                        float y = (float)(0.5 * (y2 - y1) * Math.Sin(x * f) * 2);
                        FCPoint pt = new FCPoint((int)(x + x1), (int)(y + y1));
                        pf[i] = pt;
                    }
                    drawPolyline(paint, lineColor, m_lineWidth, m_lineStyle, pf);
                }
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public sealed class SpeedResist : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public SpeedResist()
        {
            PlotType = "SPEEDRESIST";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ���λ��
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            if (selectPoint(mp, x1, y1) || m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            FCPointF firstP = new FCPointF(x2, y2 - (y2 - y1) / 3);
            FCPointF secondP = new FCPointF(x2, y2 - (y2 - y1) * 2 / 3);
            FCPointF startP = new FCPointF(x1, y1);
            float oK = 0, oB = 0, fK = 0, fB = 0, sK = 0, sB = 0;
            //��ȡֱ�߲���
            lineXY(x1, y1, x2, y2, 0, 0, ref oK, ref oB);
            lineXY(startP.x, startP.y, firstP.x, firstP.y, 0, 0, ref fK, ref fB);
            lineXY(startP.x, startP.y, secondP.x, secondP.y, 0, 0, ref sK, ref sB);
            float smallX = x1 <= x2 ? x1 : x2;
            float smallY = y1 <= y2 ? y1 : y2;
            float bigX = x1 > x2 ? x1 : x2;
            float bigY = y1 > y2 ? y1 : y2;
            if (mp.x >= smallX - 2 && mp.x <= bigX + 2 && mp.y >= smallY - 2 && mp.y <= bigY + 2)
            {
                if (!(oK == 0 && oB == 0))
                {
                    if (mp.y / (mp.x * oK + oB) >= 0.9 && mp.y / (mp.x * oK + oB) <= 1.1)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
                else
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            if ((x2 > x1 && mp.x >= x1 - 2) || (mp.x <= x1 + 2 && x2 < x1))
            {
                if (!(fK == 0 && fB == 0))
                {
                    if (mp.y / (mp.x * fK + fB) >= 0.9 && mp.y / (mp.x * fK + fB) <= 1.1)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
                if (!(sK == 0 && sB == 0))
                {
                    if (mp.y / (mp.x * sK + sB) >= 0.9 && mp.y / (mp.x * sK + sB) <= 1.1)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsA(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            drawLine(paint, lineColor, m_lineWidth, 1, x1, y1, x2, y2);
            //��ѡ�е�
            if (Selected || (x1 == x2))
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
            if (x1 != x2 && y1 != y2)
            {
                FCPoint firstP = new FCPoint(x2, y2 - (y2 - y1) / 3);
                FCPoint secondP = new FCPoint(x2, y2 - (y2 - y1) * 2 / 3);
                FCPoint startP = new FCPoint(x1, y1);
                float fK = 0, fB = 0, sK = 0, sB = 0;
                //��ȡֱ�߲���
                lineXY(startP.x, startP.y, firstP.x, firstP.y, 0, 0, ref fK, ref fB);
                lineXY(startP.x, startP.y, secondP.x, secondP.y, 0, 0, ref sK, ref sB);
                float newYF = 0, newYS = 0;
                float newX = 0;
                if (x2 > x1)
                {
                    newYF = fK * WorkingAreaWidth + fB;
                    newYS = sK * WorkingAreaWidth + sB;
                    newX = WorkingAreaWidth;
                }
                else
                {
                    newYF = fB;
                    newYS = sB;
                    newX = 0;
                }
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, startP.x, startP.y, newX, newYF);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, startP.x, startP.y, newX, newYS);
            }
        }
    }

    /// <summary>
    /// ��׼���ͨ��
    /// </summary>
    public class SeChannel : FCPlot
    {
        /// <summary>
        /// ������׼���ͨ��
        /// </summary>
        public SeChannel()
        {
            PlotType = "SECHANNEL";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            float[] param = getLRParams(m_marks);
            if (param != null)
            {
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                FCChart chart = Chart;
                int touchIndex = chart.getTouchOverIndex();
                if (touchIndex >= bIndex && touchIndex <= chart.LastVisibleIndex)
                {
                    //�ж�ѡ��
                    double yValue = a * ((touchIndex - bIndex) + 1) + b;
                    float y = py(yValue);
                    float x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    double sd = getSEChannelSD(m_marks);
                    yValue = a * ((touchIndex - bIndex) + 1) + b + sd;
                    y = py(yValue);
                    x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                    yValue = a * ((touchIndex - bIndex) + 1) + b - sd;
                    y = py(yValue);
                    x = px(touchIndex);
                    if (selectPoint(mp, x, y))
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ��׼���ͨ���ı�׼��ֵ
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns>��׼���ͨ���Ĳ���</returns>
        private double getSEChannelSD(HashMap<int, PlotMark> pList)
        {
            if (m_sourceFields != null && m_sourceFields.containsKey("CLOSE"))
            {
                int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
                int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
                int len = eIndex - bIndex + 1;
                if (len > 0)
                {
                    double[] ary = new double[len];
                    for (int i = 0; i < len; i++)
                    {
                        double close = m_dataSource.get2(i + bIndex, m_sourceFields.get("CLOSE"));
                        if (!double.IsNaN(close))
                        {
                            ary[i] = close;
                        }
                    }
                    double avg = FCScript.avgValue(ary, len);
                    //���׼��
                    double sd = FCScript.standardDeviation(ary, len, avg, 2);
                    return sd;
                }
            }
            return 0;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    if (touchIndex < eIndex)
                    {
                        resize(0);
                    }
                    break;
                case ActionType.AT2:
                    if (touchIndex > bIndex)
                    {
                        resize(1);
                    }
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            FCChart chart = Chart;
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key); 
            float x1 = px(chart.getX(bIndex));
            float x2 = px(chart.getX(eIndex));
            //��ȡֱ�߲���
            float[] param = getLRParams(pList);
            if (param != null)
            {
                //��������ѡ�е�
                float a = param[0];
                float b = param[1];
                double leftValue = a + b;
                double rightValue = (eIndex - bIndex + 1) * a + b;
                float y1 = py(leftValue);
                float y2 = py(rightValue);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
                double sd = getSEChannelSD(pList);
                double leftTop = leftValue + sd;
                double rightTop = rightValue + sd;
                double leftBottom = leftValue - sd;
                double rightBottom = rightValue - sd;
                float leftTopY = py(leftTop);
                float rightTopY = py(rightTop);
                float leftBottomY = py(leftBottom);
                float rightBottomY = py(rightBottom);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, leftTopY, x2, rightTopY);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, leftBottomY, x2, rightBottomY);
                rightValue = (chart.LastVisibleIndex + 1 - bIndex) * a + b;
                float x3 = (float)((chart.LastVisibleIndex - chart.FirstVisibleIndex) * chart.HScalePixel + chart.HScalePixel / 2);
                double dashTop = rightValue + sd;
                double dashBottom = rightValue - sd;
                float mValueY = py(rightValue);
                float dashTopY = py(dashTop);
                float dashBottomY = py(dashBottom);
                drawLine(paint, lineColor, m_lineWidth, 1, x2, rightTopY, x3, dashTopY);
                drawLine(paint, lineColor, m_lineWidth, 1, x2, rightBottomY, x3, dashBottomY);
                drawLine(paint, lineColor, m_lineWidth, 1, x2, y2, x3, mValueY);
                //��ѡ�е�
                if (Selected)
                {
                    drawSelect(paint, lineColor, x1, y1);
                    drawSelect(paint, lineColor, x2, y2);
                }
            }
        }
    }

    /// <summary>
    /// �Գ���
    /// </summary>
    public sealed class SymmetricLine : FCPlot
    {
        /// <summary>
        /// �����Գ���
        /// </summary>
        public SymmetricLine()
        {
            PlotType = "SYMMETRICLINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
                return action;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            //��ȡ�Գ�����
            int cIndex = 0;
            if (x2 >= x1)
            {
                cIndex = bIndex - (eIndex - bIndex);
            }
            else
            {
                cIndex = bIndex + (bIndex - eIndex);
            }
            if (cIndex > m_dataSource.RowsCount - 1)
            {
                cIndex = m_dataSource.RowsCount - 1;
            }
            else if (cIndex < 0)
            {
                cIndex = 0;
            }
            float x3 = px(cIndex);
            if ((mp.x >= x1 - m_lineWidth * 5 && mp.x <= x1 + m_lineWidth * 5)
            || (mp.x >= x2 - m_lineWidth * 5 && mp.x <= x2 + m_lineWidth * 5)
            || (mp.x >= x3 - m_lineWidth * 5 && mp.x <= x3 + m_lineWidth * 5))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsA(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            //��ȡ�Գ�����
            int cIndex = -1;
            if (x2 >= x1)
            {
                cIndex = bIndex - (eIndex - bIndex);
            }
            else
            {
                cIndex = bIndex + (bIndex - eIndex);
            }
            if (cIndex > m_dataSource.RowsCount - 1)
            {
                cIndex = m_dataSource.RowsCount - 1;
            }
            else if (cIndex < 0)
            {
                cIndex = 0;
            }
            float x3 = px(cIndex);
            //����
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, 0, x2, WorkingAreaHeight);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x3, 0, x3, WorkingAreaHeight);
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// �Գ�������
    /// </summary>
    public class SymemetrictriAngle : FCPlot
    {
        /// <summary>
        /// �����Գ�������
        /// </summary>
        public SymemetrictriAngle()
        {
            PlotType = "SYMMETRICTRIANGLE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            float y3 = py(m_marks.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            //��ȡ����
            float[] param = getSymmetricTriangleParams(m_marks);
            //�Ǵ�ֱ
            if (param != null)
            {
                if (selectPoint(mp, x1, y1))
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                else if (selectPoint(mp, x3, y3))
                {
                    action = ActionType.AT3;
                    return action;
                }
                //��ֱ��
                if (mp.y - param[0] * mp.x - param[1] >= m_lineWidth * -5 && mp.y - param[0] * mp.x - param[1] <= m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
                //�Գ�������
                if (mp.y - param[2] * mp.x - param[3] >= m_lineWidth * -5 && mp.y - param[2] * mp.x - param[3] <= m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //��ֱ
            else
            {
                if (mp.y >= y1 - m_lineWidth * 5 && mp.y <= y1 + m_lineWidth * 5)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.y >= y2 - m_lineWidth * 5 && mp.y <= y2 + m_lineWidth * 5)
                {
                    action = ActionType.AT2;
                    return action;
                }
                else if (mp.y >= y3 - m_lineWidth * 5 && mp.y <= y3 + m_lineWidth * 5)
                {
                    action = ActionType.AT3;
                    return action;
                }
                if (mp.x >= x1 - m_lineWidth * 5 && mp.x <= x1 + m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
                if (mp.x >= x3 - m_lineWidth * 5 && mp.x <= x3 + m_lineWidth * 5)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ�Գ�������ֱ�ߵĲ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns>�Գ�������ֱ�ߵĲ���</returns>
        private float[] getSymmetricTriangleParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            float a = 0;
            if (x2 - x1 != 0)
            {
                a = (y2 - y1) / (x2 - x1);
                float b = y1 - a * x1;
                float c = -a;
                float d = y3 - c * x3;
                return new float[] { a, b, c, d };
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create3Points(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int pIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            //��ȡ����
            float[] param = getSymmetricTriangleParams(pList);
            float a = 0;
            float b = 0;
            float c = 0;
            float d = 0;
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float x3 = px(pIndex);
            //�Ǵ�ֱ
            if (param != null)
            {
                a = param[0];
                b = param[1];
                c = param[2];
                d = param[3];
                float leftX = 0;
                float leftY = leftX * a + b;
                float rightX = WorkingAreaWidth;
                float rightY = rightX * a + b;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
                leftY = leftX * c + d;
                rightY = rightX * c + d;
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, leftX, leftY, rightX, rightY);
            }
            //��ֱ
            else
            {
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x3, 0, x3, WorkingAreaHeight);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
                drawSelect(paint, lineColor, x3, y3);
            }
        }
    }

    /// <summary>
    /// ʱ���
    /// </summary>
    public sealed class TimeRuler : FCPlot
    {
        /// <summary>
        /// ����ʱ���
        /// </summary>
        public TimeRuler()
        {
            PlotType = "TIMERULER";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ��λ��
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            if (selectPoint(mp, x1, y1))
            {
                action = ActionType.AT1;
                return action;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            //��ȡ����
            double[] param = getTimeRulerParams(m_marks);
            float yBHigh = py(param[0]);
            float yBLow = py(param[1]);
            float yEHigh = py(param[2]);
            float yELow = py(param[3]);
            //�ж�ѡ��
            if (y1 < yBHigh)
            {
                yBHigh = y1;
            }
            if (y1 > yBLow)
            {
                yBLow = y1;
            }
            if (y2 < yEHigh)
            {
                yEHigh = y2;
            }
            if (y2 > yELow)
            {
                yELow = y2;
            }
            if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
            {
                if (mp.y >= yBHigh - 2 && mp.y <= yBLow + 2)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
            {
                if (mp.y >= yEHigh - m_lineWidth * 2.5f && mp.y <= yELow + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            if (mp.y >= y1 - m_lineWidth * 2.5f && mp.y <= y1 + m_lineWidth * 2.5f)
            {
                float bigX = x1 >= x2 ? x1 : x2;
                float smallX = x1 < x2 ? x1 : x2;
                if (mp.x >= smallX - m_lineWidth * 2.5f && mp.x <= bigX + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡʱ��ߵĲ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns>ʱ��ߵĲ���</returns>
        private double[] getTimeRulerParams(HashMap<int, PlotMark> pList)
        {
            if (pList.size() == 0)
            {
                return null;
            }
            FCChart chart = Chart;
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            double bHigh = chart.divMaxOrMin(bIndex, m_div, 0);
            double bLow = chart.divMaxOrMin(bIndex, m_div, 1);
            double eHigh = chart.divMaxOrMin(eIndex, m_div, 0);
            double eLow = chart.divMaxOrMin(eIndex, m_div, 1);
            return new double[] { bHigh, bLow, eHigh, eLow };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// �ƶ�����
        /// </summary>
        public override void onMoving()
        {
            FCPoint mp = getMovingPoint();
            //��ȡ��ǰ��������yֵ
            FCChart chart = Chart;
            int touchIndex = chart.getTouchOverIndex();
            double y = getNumberValue(mp);
            if (touchIndex < 0)
            {
                touchIndex = 0;
            }
            if (touchIndex > chart.LastVisibleIndex)
            {
                touchIndex = chart.LastVisibleIndex;
            }
            //���ݲ�ͬ������������
            switch (m_action)
            {
                case ActionType.MOVE:
                    move(mp);
                    break;
                case ActionType.AT1:
                    m_marks.put(0, new PlotMark(0, m_dataSource.getXValue(touchIndex), y));
                    m_marks.put(1, new PlotMark(1, m_marks.get(1).Key, y));
                    break;
                case ActionType.AT2:
                    m_marks.put(1, new PlotMark(1, m_dataSource.getXValue(touchIndex), y));
                    m_marks.put(0, new PlotMark(0, m_marks.get(0).Key, y));
                    break;
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            double[] param = getTimeRulerParams(pList);
            float yBHigh = py(param[0]);
            float yBLow = py(param[1]);
            float yEHigh = py(param[2]);
            float yELow = py(param[3]);
            if (y1 < yBHigh)
            {
                yBHigh = y1;
            }
            if (y1 > yBLow)
            {
                yBLow = y1;
            }
            if (y2 < yEHigh)
            {
                yEHigh = y2;
            }
            if (y2 > yELow)
            {
                yELow = y2;
            }
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, yBHigh, x1, yBLow);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, yEHigh, x2, yELow);
            int subRecord = Math.Abs(eIndex - bIndex) + 1;
            //������
            String recordStr = subRecord.ToString() + "(T)";
            FCSize sizeF = textSize(paint, recordStr, m_font);
            drawText(paint, recordStr, lineColor, m_font, (x2 + x1) / 2 - sizeF.cx / 2, y1 - sizeF.cy / 2);
            if (Math.Abs(x1 - x2) > sizeF.cx)
            {
                if (x2 >= x1)
                {
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, (x2 + x1) / 2 - sizeF.cx / 2, y1);
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, (x2 + x1) / 2 + sizeF.cx / 2, y1, x2, y1);
                }
                else
                {
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, y1, (x2 + x1) / 2 - sizeF.cx / 2, y1);
                    drawLine(paint, lineColor, m_lineWidth, m_lineStyle, (x2 + x1) / 2 + sizeF.cx / 2, y1, x1, y1);
                }
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ̩��ˮƽ��
    /// </summary>
    public class TironeLevels : FCPlot
    {
        /// <summary>
        /// ����̩��ˮƽ��
        /// </summary>
        public TironeLevels()
        {
            PlotType = "TIRONELEVELS";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡ��λ��
            FCPoint mp = getTouchOverPoint();
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //��ȡ����
            double[] param = getTironelLevelsParams(m_marks);
            double nHigh = param[0];
            double nLow = param[4];
            float highY = py(nHigh);
            float lowY = py(nLow);
            //��ȡ�ϴ��X�ͽ�С��X
            float smallX = x1 > x2 ? x2 : x1;
            float bigX = x1 > x2 ? x1 : x2;
            if ((mp.y >= highY - m_lineWidth * 2.5f && mp.y <= highY + m_lineWidth * 2.5f)
            || (mp.y >= lowY - m_lineWidth * 2.5f && mp.y <= lowY + m_lineWidth * 2.5f))
            {
                if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (mp.x >= x2 - m_lineWidth * 2.5f && mp.x <= x2 + m_lineWidth * 2.5f)
                {
                    action = ActionType.AT2;
                    return action;
                }
            }
            //ѡ���������
            if (mp.y >= highY - m_lineWidth * 2.5f && mp.y <= highY + m_lineWidth * 2.5f)
            {
                if (mp.x >= smallX - m_lineWidth * 2.5f && mp.x <= bigX + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //ѡ���������
            else if (mp.y >= lowY - m_lineWidth * 2.5f && mp.y <= lowY + m_lineWidth * 2.5f)
            {
                if (mp.x >= smallX - m_lineWidth * 2.5f && mp.x <= bigX + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            //ˮƽ���ж�
            for (int i = 1; i < param.Length - 1; i++)
            {
                float y = py(param[i]);
                if (mp.y >= y - m_lineWidth * 2.5f && mp.y <= y + m_lineWidth * 2.5f)
                {
                    action = ActionType.MOVE;
                    return action;
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ̩��ˮƽ�ߵĲ���
        /// </summary>
        /// <param name="pList">���󼯺�</param>
        /// <returns>̩��ˮƽ�ߵĲ���</returns>
        private double[] getTironelLevelsParams(HashMap<int, PlotMark> pList)
        {
            double[] hl = getCandleRange(pList);
            if (hl != null)
            {
                double nHigh = hl[0];
                double nLow = hl[1];
                return new double[] { nHigh, nHigh - (nHigh - nLow) / 3, nHigh - (nHigh - nLow) / 2, nHigh - 2 * (nHigh - nLow) / 3, nLow };
            }
            else
            {
                return null;
            }
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2CandlePoints(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeNS;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float smallX = x1 > x2 ? x2 : x1;
            float bigX = x1 > x2 ? x1 : x2;
            //��ȡ����
            double[] param = getTironelLevelsParams(pList);
            double nHigh = param[0];
            double nLow = param[4];
            float highY = py(nHigh);
            float lowY = py(nLow);
            float mid = x1 >= x2 ? (x2 + (x1 - x2) / 2) : (x1 + (x2 - x1) / 2);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, highY, x2, highY);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, lowY, x2, lowY);
            drawLine(paint, lineColor, m_lineWidth, 1, mid, lowY, mid, highY);
            for (int i = 1; i < param.Length - 1; i++)
            {
                float y = py(param[i]);
                //��ֱ��
                drawLine(paint, lineColor, m_lineWidth, 1, 0, y, WorkingAreaWidth, y);
                String str = i.ToString() + "/3";
                if (i == 2)
                {
                    str = "1/2";
                }
                FCSize sizeF = textSize(paint, str, m_font);
                drawText(paint, str, lineColor, m_font, WorkingAreaWidth - sizeF.cx, y - sizeF.cy);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, smallX, highY);
                drawSelect(paint, lineColor, smallX, lowY);
                drawSelect(paint, lineColor, bigX, highY);
                drawSelect(paint, lineColor, bigX, lowY);
            }
        }
    }

    /// <summary>
    /// ������
    /// </summary>
    public class Triangle : FCPlot
    {
        /// <summary>
        /// ����������
        /// </summary>
        public Triangle()
        {
            PlotType = "TRIANGLE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡѡ��λ��
            float y1 = py(m_marks.get(0).Value);
            float y2 = py(m_marks.get(1).Value);
            float y3 = py(m_marks.get(2).Value);
            int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            int cIndex = m_dataSource.getRowIndex(m_marks.get(2).Key);
            float x1 = px(aIndex);
            float x2 = px(bIndex);
            float x3 = px(cIndex);
            FCPoint mp = getTouchOverPoint();
            if (m_moveTimes == 1)
            {
                action = ActionType.AT3;
                return action;
            }
            else
            {
                if (selectPoint(mp, x1, y1) || m_moveTimes == 1)
                {
                    action = ActionType.AT1;
                    return action;
                }
                else if (selectPoint(mp, x2, y2))
                {
                    action = ActionType.AT2;
                    return action;
                }
                else if (selectPoint(mp, x3, y3))
                {
                    action = ActionType.AT3;
                    return action;
                }
            }
            if (selectTriangle(mp, x1, y1, x2, y2, x3, y3))
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            int rIndex = m_dataSource.RowsCount;
            if (rIndex > 0)
            {
                int currentIndex = getIndex(mp);
                double y = getNumberValue(mp);
                double date = m_dataSource.getXValue(currentIndex);
                m_marks.clear();
                m_marks.put(0, new PlotMark(0, date, y));
                int si = currentIndex + 10;
                FCChart chart = Chart;
                if (si > chart.LastVisibleIndex)
                {
                    si = chart.LastVisibleIndex;
                }
                m_marks.put(1, new PlotMark(1, m_dataSource.getXValue(si), y));
                m_marks.put(2, new PlotMark(2, date, y));
                return true;
            }
            return false;
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
                m_startMarks.put(2, m_marks.get(2));
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            float y3 = py(pList.get(2).Value);
            int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int bIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            int cIndex = m_dataSource.getRowIndex(pList.get(2).Key);
            float x1 = px(aIndex);
            float x2 = px(bIndex);
            float x3 = px(cIndex);
            //����
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x2, y2);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, y1, x3, y3);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x2, y2, x3, y3);
            //��ѡ�е�
            if (Selected || (x1 == x2 && x2 == x3 && y1 == y2 && y2 == y3))
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
                drawSelect(paint, lineColor, x3, y3);
            }
        }
    }

    /// <summary>
    /// ���Ǽ�ͷ
    /// </summary>
    public sealed class UpArrow : FCPlot
    {
        /// <summary>
        /// �������Ǽ�ͷ
        /// </summary>
        public UpArrow()
        {
            PlotType = "UPARROW";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //��ȡֵ������
            double fValue = m_marks.get(0).Value;
            int aIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            //��ȡ�������������
            float x1 = px(aIndex);
            float y1 = py(fValue);
            //��ȡ�������
            int width = 10;
            FCRect rect = new FCRect(x1 - width / 2, y1, x1 + width / 2, y1 + width * 3 / 2);
            FCPoint mp = getTouchOverPoint();
            //�ж��Ƿ�ѡ��
            if (mp.x > rect.left && mp.x <= rect.right && mp.y >= rect.top && mp.y <= rect.bottom)
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            double fValue = pList.get(0).Value;
            int aIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int x1 = (int)px(aIndex);
            int y1 = (int)py(fValue);
            int width = 10;
            FCPoint point1 = new FCPoint(x1, y1);
            FCPoint point2 = new FCPoint(x1 + width / 2, y1 + width);
            FCPoint point3 = new FCPoint(x1 + width / 4, y1 + width);
            FCPoint point4 = new FCPoint(x1 + width / 4, y1 + width * 3 / 2);
            FCPoint point5 = new FCPoint(x1 - width / 4, y1 + width * 3 / 2);
            FCPoint point6 = new FCPoint(x1 - width / 4, y1 + width);
            FCPoint point7 = new FCPoint(x1 - width / 2, y1 + width);
            FCPoint[] points = new FCPoint[7] { point1, point2, point3, point4, point5, point6, point7 };
            fillPolygon(paint, lineColor, points);
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1 - width / 2, y1);
            }
        }
    }

    /// <summary>
    /// ��ֱ��
    /// </summary>
    public sealed class VLine : FCPlot
    {
        /// <summary>
        /// ������ֱ��
        /// </summary>
        public VLine()
        {
            PlotType = "VLINE";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            //�ж�ѡ��
            FCPoint mp = getTouchOverPoint();
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            float x1 = px(bIndex);
            if (mp.x >= x1 - m_lineWidth * 2.5f && mp.x <= x1 + m_lineWidth * 2.5f)
            {
                action = ActionType.MOVE;
            }
            return action;
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return createPoint(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                Cursor = FCCursors.Hand;
                m_startMarks.put(0, m_marks.get(0));
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            float x1 = px(bIndex);
            //����
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, 0, x1, WorkingAreaHeight);
        }
    }

    /// <summary>
    /// ���˳�
    /// </summary>
    public sealed class WaveRuler : FCPlot
    {
        /// <summary>
        /// �������˳�
        /// </summary>
        public WaveRuler()
        {
            PlotType = "WAVERULER";
        }

        /// <summary>
        /// ��ȡ��������
        /// </summary>
        /// <returns>��������</returns>
        public override ActionType getAction()
        {
            ActionType action = ActionType.NO;
            if (m_marks.size() == 0)
            {
                return action;
            }
            FCPoint mp = getTouchOverPoint();
            //��ȡ������
            float[] param = getWaveRulerParams(m_marks.get(0).Value, m_marks.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(m_marks.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(m_marks.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            float y1 = py(m_marks.get(0).Value);
            float y2 = param[param.Length - 1];
            if (selectPoint(mp, x1, y1) || m_moveTimes == 1)
            {
                action = ActionType.AT1;
                return action;
            }
            else if (selectPoint(mp, x2, y2))
            {
                action = ActionType.AT2;
                return action;
            }
            //�ж�ѡ��
            float smallY = param[0] < param[param.Length - 1] ? param[0] : param[param.Length - 1];
            float bigY = param[0] >= param[param.Length - 1] ? param[0] : param[param.Length - 1];
            float mid = x1 >= x2 ? (x2 + (x1 - x2) / 2) : (x1 + (x2 - x1) / 2);
            if (mp.x >= mid - m_lineWidth * 2.5f && mp.x <= mid + m_lineWidth * 2.5f && mp.y >= smallY - m_lineWidth * 2.5f && mp.y <= bigY + m_lineWidth * 2.5f)
            {
                action = ActionType.MOVE;
                return action;
            }
            float top = 0;
            float bottom = WorkingAreaWidth;
            if (mp.y >= top && mp.y <= bottom)
            {
                foreach (float p in param)
                {
                    if (mp.x >= 0 && mp.x <= WorkingAreaWidth && mp.y >= p - m_lineWidth * 2.5f && mp.y <= p + m_lineWidth * 2.5f)
                    {
                        action = ActionType.MOVE;
                        return action;
                    }
                }
            }
            return action;
        }

        /// <summary>
        /// ��ȡ���˳߲���
        /// </summary>
        /// <param name="value1">ֵ1</param>
        /// <param name="value2">ֵ2</param>
        /// <returns>���˳߲���</returns>
        private float[] getWaveRulerParams(double value1, double value2)
        {
            float y1 = py(value1);
            float y2 = py(value2);
            float y0 = 0, yA = 0, yB = 0, yC = 0, yD = 0, yE = 0, yF = 0, yG = 0, yH = 0, yI = 0, yMax = 0;
            y0 = y1;
            yA = y1 <= y2 ? y1 + (y2 - y1) * (0.236f / 2.618f) : y2 + (y1 - y2) * (1 - 0.236f / 2.618f);
            yB = y1 <= y2 ? y1 + (y2 - y1) * (0.362f / 2.618f) : y2 + (y1 - y2) * (1 - 0.362f / 2.618f);
            yC = y1 <= y2 ? y1 + (y2 - y1) * (0.5f / 2.618f) : y2 + (y1 - y2) * (1 - 0.5f / 2.618f);
            yD = y1 <= y2 ? y1 + (y2 - y1) * (0.618f / 2.618f) : y2 + (y1 - y2) * (1 - 0.618f / 2.618f);
            yE = y1 <= y2 ? y1 + (y2 - y1) * (1 / 2.618f) : y2 + (y1 - y2) * (1 - 1 / 2.618f);
            yF = y1 <= y2 ? y1 + (y2 - y1) * (1.382f / 2.618f) : y2 + (y1 - y2) * (1 - 1.382f / 2.618f);
            yG = y1 <= y2 ? y1 + (y2 - y1) * (1.618f / 2.618f) : y2 + (y1 - y2) * (1 - 1.618f / 2.618f);
            yH = y1 <= y2 ? y1 + (y2 - y1) * (2 / 2.618f) : y2 + (y1 - y2) * (1 - 2 / 2.618f);
            yI = y1 <= y2 ? y1 + (y2 - y1) * (2.382f / 2.618f) : y2 + (y1 - y2) * (1 - 2.382f / 2.618f);
            yMax = y2;
            return new float[] { y0, yA, yB, yC, yD, yE, yF, yG, yH, yI, yMax };
        }

        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="mp">����</param>
        /// <returns>�Ƿ��ʼ���ɹ�</returns>
        public override bool onCreate(FCPoint mp)
        {
            return create2PointsB(mp);
        }

        /// <summary>
        /// ��ʼ�ƶ����߹���
        /// </summary>
        public override void onMoveStart()
        {
            m_moveTimes++;
            m_action = getAction();
            m_startMarks.clear();
            m_startPoint = getTouchOverPoint();
            if (m_action != ActionType.NO)
            {
                if (m_action == ActionType.MOVE)
                {
                    Cursor = FCCursors.Hand;
                }
                else
                {
                    Cursor = FCCursors.SizeWE;
                }
                m_startMarks.put(0, m_marks.get(0));
                m_startMarks.put(1, m_marks.get(1));
            }
        }

        /// <summary>
        /// ����ͼ��Ĳ�Ӱ
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        public override void onPaintGhost(FCPaint paint)
        {
            if (m_moveTimes > 1)
            {
                onPaint(paint, m_startMarks, SelectedColor);
            }
        }

        /// <summary>
        /// ����ͼ��ķ���
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="pList">����ֵ����</param>
        /// <param name="lineColor">��ɫ</param>
        protected override void onPaint(FCPaint paint, HashMap<int, PlotMark> pList,long lineColor)
        {
            if (pList.size() == 0)
                return;
            //��ȡ���λ��
            float y1 = py(pList.get(0).Value);
            float y2 = py(pList.get(1).Value);
            int bIndex = m_dataSource.getRowIndex(pList.get(0).Key);
            int eIndex = m_dataSource.getRowIndex(pList.get(1).Key);
            float x1 = px(bIndex);
            float x2 = px(eIndex);
            //�����ֺ�����
            float[] lineParam = getWaveRulerParams(pList.get(0).Value, pList.get(1).Value);
            String[] str = new String[] { "0.00%", "23.60%", "38.20%", "50.00%", "61.80%", "100.00%", "138.20%", "161.80%", "200%", "238.20%", "261.80%" };
            float mid = x1 >= x2 ? (x2 + (x1 - x2) / 2) : (x1 + (x2 - x1) / 2);
            drawLine(paint, lineColor, m_lineWidth, m_lineStyle, mid, lineParam[0], mid, lineParam[lineParam.Length - 1]);
            for (int i = 0; i < lineParam.Length; i++)
            {
                FCSize sizeF = textSize(paint, str[i], m_font);
                float yP = lineParam[i];
                drawLine(paint, lineColor, m_lineWidth, m_lineStyle, x1, yP, x2, yP); ;
                drawText(paint, str[i], lineColor, m_font, mid, yP - sizeF.cy);
            }
            //��ѡ�е�
            if (Selected)
            {
                drawSelect(paint, lineColor, x1, y1);
                drawSelect(paint, lineColor, x2, y2);
            }
        }
    }

    /// <summary>
    /// ���߹��߹�����
    /// </summary>
    public class PFactory {
        /// <summary>
        /// �������ʹ�������
        /// </summary>
        /// <param name="plotType">����</param>
        /// <returns>���߹��߶���</returns>
        public static FCPlot createPlot(String plotType) {
            FCPlot iplot = null;
            switch (plotType) {
                case "ANDREWSPITCHFORK":
                    iplot = new AndrewsPitchfork();
                    break;
                case "ANGLELINE":
                    iplot = new Angleline();
                    break;
                case "CIRCUMCIRCLE":
                    iplot = new CircumCircle();
                    break;
                case "ARROWSEGMENT":
                    iplot = new ArrowSegment();
                    break;
                case "DOWNARROW":
                    iplot = new DownArrow();
                    break;
                case "DROPLINE":
                    iplot = new Dropline();
                    break;
                case "ELLIPSE":
                    iplot = new Ellipse();
                    break;
                case "FIBOELLIPSE":
                    iplot = new FiboEllipse();
                    break;
                case "FIBOFANLINE":
                    iplot = new FiboFanline();
                    break;
                case "FIBOTIMEZONE":
                    iplot = new FiboTimezone();
                    break;
                case "GANNBOX":
                    iplot = new GannBox();
                    break;
                case "GANNLINE":
                    iplot = new GannLine();
                    break;
                case "GOLDENRATIO":
                    iplot = new GoldenRatio();
                    break;
                case "HLINE":
                    iplot = new HLine();
                    break;
                case "LEVELGRADING":
                    iplot = new LevelGrading();
                    break;
                case "LINE":
                    iplot = new Line();
                    break;
                case "LRBAND":
                    iplot = new LrBand();
                    break;
                case "LRCHANNEL":
                    iplot = new LrChannel();
                    break;
                case "LRLINE":
                    iplot = new LrLine();
                    break;
                case "NULLPOINT":
                    iplot = new NullPoint();
                    break;
                case "PARALLEL":
                    iplot = new Parallel();
                    break;
                case "PERCENT":
                    iplot = new Percent();
                    break;
                case "PERIODIC":
                    iplot = new Periodic();
                    break;
                case "PRICE":
                    iplot = new Price();
                    break;
                case "RANGERULER":
                    iplot = new RangeRuler();
                    break;
                case "RASELINE":
                    iplot = new RaseLine();
                    break;
                case "RAY":
                    iplot = new Ray();
                    break;
                case "FCRect":
                    iplot = new Rect();
                    break;
                case "SEGMENT":
                    iplot = new Segment();
                    break;
                case "SINE":
                    iplot = new Sine();
                    break;
                case "SPEEDRESIST":
                    iplot = new SpeedResist();
                    break;
                case "SECHANNEL":
                    iplot = new SeChannel();
                    break;
                case "SYMMETRICLINE":
                    iplot = new SymmetricLine();
                    break;
                case "SYMMETRICTRIANGLE":
                    iplot = new SymemetrictriAngle();
                    break;
                case "TIMERULER":
                    iplot = new TimeRuler();
                    break;
                case "TRIANGLE":
                    iplot = new Triangle();
                    break;
                case "UPARROW":
                    iplot = new UpArrow();
                    break;
                case "VLINE":
                    iplot = new VLine();
                    break;
                case "WAVERULER":
                    iplot = new WaveRuler();
                    break;
                case "TIRONELEVELS":
                    iplot = new TironeLevels();
                    break;
                case "RAFFCHANNEL":
                    iplot = new RaffChannel();
                    break;
                case "QUADRANTLINES":
                    iplot = new QuadrantLines();
                    break;
                case "BOXLINE":
                    iplot = new BoxLine();
                    break;
                case "PARALLELOGRAM":
                    iplot = new ParalleGram();
                    break;
                case "CIRCLE":
                    iplot = new Circle();
                    break;
                case "PRICECHANNEL":
                    iplot = new PriceChannel();
                    break;
                case "GP":
                    iplot = new Gp();
                    break;
                case "GA":
                    iplot = new Ga();
                    break;
            }
            return iplot;
        }
    }
}
