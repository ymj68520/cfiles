#include "..\\..\\stdafx.h"
#include "..\\..\\include\\date\\MonthButton.h"

namespace FaceCat{
    Long MonthButton::getPaintingBackColor(){
        return FCColor_Back;
    }

    Long MonthButton::getPaintingBorderColor(){
        return FCColor_Border;
    }

    Long MonthButton::getPaintingTextColor(){
        return FCColor_Text;
    }

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	MonthButton::MonthButton(FCCalendar *calendar){
		m_bounds.left = 0;
		m_bounds.top = 0;
		m_bounds.right = 0;
		m_bounds.bottom = 0;
		m_calendar = calendar;
		m_month = 0;
		m_visible = true;
		m_year = 0;
	}

	MonthButton::~MonthButton(){
		m_calendar = 0;
	}

	FCRect MonthButton::getBounds(){
		return m_bounds;
	}

	void MonthButton::setBounds(const FCRect& bounds){
		m_bounds = bounds;
	}

	FCCalendar* MonthButton::getCalendar(){
		return m_calendar;
	}

	void MonthButton::setCalendar(FCCalendar *calendar){
		m_calendar = calendar;
	}

	int MonthButton::getMonth(){
		return m_month;
	}

	void MonthButton::setMonth(int month){
		m_month = month;
	}

	bool MonthButton::isVisible(){
		return m_visible;
	}

	void MonthButton::setVisible(bool visible){
		m_visible = visible;
	}

	int MonthButton::getYear(){
		return m_year;
	}

	void MonthButton::setYear(int year){
		m_year = year;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	String MonthButton::getMonthStr(){
		 switch (m_month){
            case 1:
                return L"һ��";
            case 2:
                return L"����";
            case 3:
                return L"����";
            case 4:
                return L"����";
            case 5:
                return L"����";
            case 6:
                return L"����";
            case 7:
                return L"����";
            case 8:
                return L"����";
            case 9:
                return L"����";
            case 10:
                return L"ʮ��";
            case 11:
                return L"ʮһ��";
            case 12:
                return L"ʮ����";
            default:
                return L"";
        }
	}

	void MonthButton::onClick(FCTouchInfo touchInfo){
	    if (m_calendar){
            CMonth *month = m_calendar->getYears()->getYear(m_calendar->getMonthDiv()->getYear())->Months.get(m_month);
            m_calendar->setMode(FCCalendarMode_Day);
            m_calendar->setSelectedDay(month->m_days.get(1));
			m_calendar->update();
			m_calendar->invalidate();
        }
	}

	void MonthButton::onPaintBackGround(FCPaint *paint, const FCRect& clipRect){
        Long backColor = getPaintingBackColor();
        paint->fillRect(backColor, m_bounds); 
	}

	void MonthButton::onPaintBorder(FCPaint *paint, const FCRect& clipRect){
        Long borderColor = getPaintingBorderColor();
        paint->drawLine(borderColor, 1, 0, m_bounds.left, m_bounds.bottom - 1, m_bounds.right - 1, m_bounds.bottom - 1);
        paint->drawLine(borderColor, 1, 0, m_bounds.right - 1, m_bounds.top, m_bounds.right - 1, m_bounds.bottom - 1);
	}

	void MonthButton::onPaintForeground(FCPaint *paint, const FCRect& clipRect){
		int width = m_bounds.right - m_bounds.left;
		int height = m_bounds.bottom - m_bounds.top;
		String monthStr = getMonthStr();
		FCFont *font = getFont();
		FCSize textSize = paint->textSize(monthStr.c_str(), font);
		int tLeft = m_bounds.left + (width - textSize.cx) / 2;
		int tTop = m_bounds.top + (height - textSize.cy) / 2;
		FCRect textRect = {tLeft, tTop, tLeft + textSize.cx, tTop + textSize.cy};
		paint->drawText(monthStr.c_str(), getPaintingTextColor(), font, textRect);
	}
}