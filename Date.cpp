/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Date.cpp
Version 1.0
Author	Jagbir Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/10/23  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

namespace sdds {

	int currentYear;
	int currentMonth;
	int currentDay;

	// Function to check validity of date
	bool Date::validate() {
		bool ok = true;

		int daysInMonth = ut.daysOfMon(m_month, m_year);

		if (m_year < currentYear || m_year > maxYear) {
			(*this).m_state = "Invalid year in date";
			(*this).m_state = 1;
			ok = false;
		}
		else if (m_month < 1 || m_month > 12) {
			(*this).m_state = "Invalid month in date";
			(*this).m_state = 2;
			ok = false;
		}
		else if (m_day < 1 || m_day > daysInMonth) {
			(*this).m_state = "Invalid day in date";
			(*this).m_state = 3;
			ok = false;
		}

		if (ok) {
			m_state.clear();
		}

		return ok;
	}

	// Converting date to an Int value
	int Date::uniqueValue(int year, int month, int day) {
		return year * 372 + month * 31 + day;
	}

	// Constructor
	Date::Date() {
		ut.getSystemDate(&currentYear, &currentMonth, &currentDay);

		m_year = currentYear;
		m_month = currentMonth;
		m_day = currentDay;
		m_formatted = validate();
	}

	Date::Date(int year, int month, int day) {
		ut.getSystemDate(&currentYear, &currentMonth, &currentDay);

		m_year = year;
		m_month = month;
		m_day = day;
		m_formatted = validate();
	}

	// Relational operators overloading 
	bool Date::operator == (const Date& date) {
		bool check = false;
		if (uniqueValue(m_year, m_month, m_day) == uniqueValue(date.m_year, date.m_month, date.m_day)) {
			check = true;
		}
		return check;
	}

	bool Date::operator != (const Date& date) {
		bool check = false;
		if (uniqueValue(m_year, m_month, m_day) != uniqueValue(date.m_year, date.m_month, date.m_day)) {
			check = true;
		}
		return check;
	}

	bool Date::operator < (const Date& date) {
		bool check = false;
		if (uniqueValue(m_year, m_month, m_day) < uniqueValue(date.m_year, date.m_month, date.m_day)) {
			check = true;
		}
		return check;
	}

	bool Date::operator > (const Date& date) {
		bool check = false;
		if (uniqueValue(m_year, m_month, m_day) > uniqueValue(date.m_year, date.m_month, date.m_day)) {
			check = true;
		}
		return check;
	}

	bool Date::operator <= (const Date& date) {
		bool check = false;
		if (uniqueValue(m_year, m_month, m_day) <= uniqueValue(date.m_year, date.m_month, date.m_day)) {
			check = true;
		}
		return check;
	}

	bool Date::operator >= (const Date& date) {
		bool check = false;
		if (uniqueValue(m_year, m_month, m_day) >= uniqueValue(date.m_year, date.m_month, date.m_day)) {
			check = true;
		}
		return check;
	}

	// Accessing State type
	const Status& Date::state() {
		return (*this).m_state;
	}

	// Modifying format type
	Date& Date::formatted(bool attribute) {
		(*this).m_formatted = attribute;
		return *this;
	}

	// Type operator overloading
	Date::operator bool() const {
		return m_state;
	}

	// Insertion Method
	ostream& Date::write(ostream& ostr) const {
		if (m_formatted) {
			ostr << setfill('0') << setw(4) << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day;
		}
		else {
			ostr << setfill('0') << setw(2) << m_year % 100 << setw(2) << m_month << setw(2) << m_day;
		}
		return ostr;
	}

	// Extraction Method
	istream& Date::read(istream& istr) {
		int date;
		istr >> date;

		if (istr.fail()) {
			m_state = "Invalid date value";
			m_state = 0;
			istr.setstate(ios::badbit);
		}
		else {
			if (date >= 1000 && date <= 9999) {
				m_year = currentYear;
				m_month = date / 100;
				m_day = date % 100;
				m_formatted = validate();
			}
			else if (date >= 100000 && date <= 999999) {
				m_year = (date / 10000) + 2000;
				m_month = (date / 100) % 100;
				m_day = date % 100;
				m_formatted = validate();
			}
			else if (date >= 1 && date <= 99)
			{
				m_state = "Invalid month in date";
				m_state = 2;
				istr.setstate(ios::badbit);
			}
			else
			{
				istr.setstate(ios::badbit);
			}

			int daysInMonth = ut.daysOfMon(m_month, m_year);

			if (m_year < currentYear || m_year > maxYear) {
				m_state = "Invalid year in date";
				m_state = 1;
				istr.setstate(ios::badbit);
			}
			else if (m_month < 1 || m_month > 12) {
				m_state = "Invalid month in date";
				m_state = 2;
				istr.setstate(ios::badbit);
			}
			else if (m_day < 1 || m_day > daysInMonth) {
				m_state = "Invalid day in date";
				m_state = 3;
				istr.setstate(ios::badbit);
			}
		}


		return istr;
	}

	// Insertion operator overloaded
	ostream& operator << (ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

	// Extraction operator overloaded
	istream& operator >> (istream& istr, Date& date) {
		return date.read(istr);
	}

	int Date::format()const
	{
		int num;
		int year = m_year % 100;
		num = year * 10000;
		num += m_month * 100;
		num += m_day;

		return num;
	}
}