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
    /// ���ڲ�
    /// </summary>
    public class YearDiv {
        /// <summary>
        /// �������ڲ�
        /// </summary>
        public YearDiv(FCCalendar calendar) {
            m_calendar = calendar;
            onLoad();
        }

        /// <summary>
        /// �����ķ���
        /// </summary>
        protected int m_am_Direction;

        /// <summary>
        /// ������ǰ֡��
        /// </summary>
        protected int m_am_Tick;

        /// <summary>
        /// ������֡��
        /// </summary>
        protected int m_am_TotalTick = 40;

        /// <summary>
        /// �µİ�ť
        /// </summary>
        public ArrayList<YearButton> m_yearButtons = new ArrayList<YearButton>();

        /// <summary>
        /// �µĶ�����ť
        /// </summary>
        public ArrayList<YearButton> m_yearButtons_am = new ArrayList<YearButton>();

        protected FCCalendar m_calendar;

        /// <summary>
        /// ��ȡ�����������ؼ�
        /// </summary>
        public virtual FCCalendar Calendar {
            get { return m_calendar; }
            set { m_calendar = value; }
        }

        protected int m_startYear;

        /// <summary>
        /// ��ȡ��ʼ���
        /// </summary>
        public virtual int StartYear {
            get { return m_startYear; }
        }

        /// <summary>
        /// ���ٷ���
        /// </summary>
        public virtual void delete() {
            m_yearButtons.clear();
            m_yearButtons_am.clear();
        }

        /// <summary>
        /// ����
        /// </summary>
        public virtual void hide() {
            int yearButtonSize = m_yearButtons.size();
            for (int i = 0; i < yearButtonSize; i++) {
                YearButton yearButton = m_yearButtons.get(i);
                yearButton.Visible = false;
            }
        }

        /// <summary>
        /// �����������
        /// </summary>
        /// <param name="touchInfo">������Ϣ</param>
        public void onClick(FCTouchInfo touchInfo) {
            FCPoint mp = touchInfo.m_firstPoint;
            int yearButtonsSize = m_yearButtons.size();
            for (int i = 0; i < yearButtonsSize; i++) {
                YearButton yearButton = m_yearButtons.get(i);
                if (yearButton.Visible) {
                    FCRect bounds = yearButton.Bounds;
                    if (mp.x >= bounds.left && mp.x <= bounds.right && mp.y >= bounds.top && mp.y <= bounds.bottom) {
                        yearButton.onClick(touchInfo);
                        return;
                    }
                }
            }
            int yearButtonAmSize = m_yearButtons_am.size();
            for (int i = 0; i < yearButtonAmSize; i++) {
                YearButton yearButton = m_yearButtons_am.get(i);
                if (yearButton.Visible) {
                    FCRect bounds = yearButton.Bounds;
                    if (mp.x >= bounds.left && mp.x <= bounds.right && mp.y >= bounds.top && mp.y <= bounds.bottom) {
                        yearButton.onClick(touchInfo);
                        return;
                    }
                }
            }
        }

        /// <summary>
        /// ��ӿؼ�����
        /// </summary>
        public virtual void onLoad() {
            if (m_calendar != null) {
                FCHost host = m_calendar.Native.Host;
                if (m_yearButtons.size() == 0 || m_yearButtons_am.size() == 0) {
                    m_yearButtons.clear();
                    m_yearButtons_am.clear();
                    for (int i = 0; i < 12; i++) {
                        YearButton yearButton = new YearButton(m_calendar);
                        m_yearButtons.add(yearButton);
                        YearButton yearButtonAm = new YearButton(m_calendar);
                        yearButtonAm.Visible = false;
                        m_yearButtons_am.add(yearButtonAm);
                    }
                }
            }
        }

        /// <summary>
        /// �ػ淽��
        /// </summary>
        /// <param name="paint">��ͼ����</param>
        /// <param name="clipRect">�ü�����</param>
        public virtual void onPaint(FCPaint paint, FCRect clipRect) {
            int yearButtonsSize = m_yearButtons.size();
            for (int i = 0; i < yearButtonsSize; i++) {
                YearButton yearButton = m_yearButtons.get(i);
                if (yearButton.Visible) {
                    FCRect bounds = yearButton.Bounds;
                    yearButton.onPaintBackGround(paint, bounds);
                    yearButton.onPaintForeground(paint, bounds);
                    yearButton.onPaintBorder(paint, bounds);
                }
            }
            int yearButtonAmSize = m_yearButtons_am.size();
            for (int i = 0; i < yearButtonAmSize; i++) {
                YearButton yearButton = m_yearButtons_am.get(i);
                if (yearButton.Visible) {
                    FCRect bounds = yearButton.Bounds;
                    yearButton.onPaintBackGround(paint, bounds);
                    yearButton.onPaintForeground(paint, bounds);
                    yearButton.onPaintBorder(paint, bounds);
                }
            }
        }

        /// <summary>
        /// ��������ͼ��
        /// </summary>
        /// <param name="state">״̬</param>
        public virtual void onResetDiv(int state) {
            if (m_calendar != null) {
                int thisStartYear = m_startYear;
                int lastStartYear = m_startYear - 12;
                int nextStartYear = m_startYear + 12;
                int left = 0;
                int headHeight = m_calendar.HeadDiv.Height;
                int top = headHeight;
                int width = m_calendar.Width;
                int height = m_calendar.Height;
                height -= m_calendar.TimeDiv.Height;
                int yearButtonHeight = height - top;
                if (yearButtonHeight < 1) {
                    yearButtonHeight = 1;
                }
                int toY = 0;
                ArrayList<YearButton> yearButtons = new ArrayList<YearButton>();
                if (m_am_Direction == 1) {
                    toY = yearButtonHeight * m_am_Tick / m_am_TotalTick;
                    if (state == 1) {
                        thisStartYear = nextStartYear;
                        lastStartYear = thisStartYear - 12;
                        nextStartYear = thisStartYear + 12;
                    }
                }
                else if (m_am_Direction == 2) {
                    toY = -yearButtonHeight * m_am_Tick / m_am_TotalTick;
                    if (state == 1) {
                        thisStartYear = lastStartYear;
                        lastStartYear = thisStartYear - 12;
                        nextStartYear = thisStartYear + 12;
                    }
                }
                if (state == 0) {
                    yearButtons = m_yearButtons;
                }
                else if (state == 1) {
                    yearButtons = m_yearButtons_am;
                }
                int dheight = yearButtonHeight / 3;
                int buttonSize = yearButtons.size();
                for (int i = 0; i < buttonSize; i++) {
                    if (i == 8) {
                        dheight = height - top;
                    }
                    YearButton yearButton = yearButtons.get(i);
                    yearButton.Year = thisStartYear + i;
                    int vOffSet = 0;
                    if (state == 1) {
                        if (m_am_Tick > 0) {
                            yearButton.Visible = true;
                            if (m_am_Direction == 1) {
                                vOffSet = toY - yearButtonHeight;
                            }
                            else if (m_am_Direction == 2) {
                                vOffSet = toY + yearButtonHeight;
                            }
                        }
                        else {
                            yearButton.Visible = false;
                            continue;
                        }
                    }
                    else {
                        vOffSet = toY;
                    }
                    if ((i + 1) % 4 == 0) {
                        FCPoint dp = new FCPoint(left, top + vOffSet);
                        FCSize ds = new FCSize(width - left, dheight);
                        yearButton.Bounds = new FCRect(dp.x, dp.y, dp.x + ds.cx, dp.y + ds.cy);
                        left = 0;
                        if (i != 0 && i != buttonSize - 1) {
                            top += dheight;
                        }
                    }
                    else {
                        FCPoint dp = new FCPoint(left, top + vOffSet);
                        FCSize ds = new FCSize(width / 4 + ((i + 1) % 4) % 2, dheight);
                        yearButton.Bounds = new FCRect(dp.x, dp.y, dp.x + ds.cx, dp.y + ds.cy);
                        left += ds.cx;
                    }
                }
            }
        }

        /// <summary>
        /// ���������
        /// </summary>
        public virtual void onTimer() {
            if (m_am_Tick > 0) {
                m_am_Tick = (int)((double)m_am_Tick * 2 / 3);
                if (m_calendar != null) {
                    m_calendar.update();
                    m_calendar.invalidate();
                }
            }
        }

        /// <summary>
        /// ѡ��ʼ���
        /// </summary>
        /// <param name="startYear">��ʼ���</param>
        public void selectStartYear(int startYear) {
            if (m_calendar != null) {
                if (m_startYear != startYear) {
                    if (startYear > m_startYear) {
                        m_am_Direction = 1;
                    }
                    else {
                        m_am_Direction = 2;
                    }
                    if (m_calendar.UseAnimation) {
                        m_am_Tick = m_am_TotalTick;
                    }
                    m_startYear = startYear;
                }
            }
        }

        /// <summary>
        /// ��ʾ
        /// </summary>
        public virtual void show() {
            int yearButtonSize = m_yearButtons.size();
            for (int i = 0; i < yearButtonSize; i++) {
                YearButton yearButton = m_yearButtons.get(i);
                yearButton.Visible = true;
            }
        }

        /// <summary>
        /// ���²��ַ���
        /// </summary>
        public virtual void update() {
            onResetDiv(0);
            onResetDiv(1);
        }
    }
}
