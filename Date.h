/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"
#include "Utils.h"
const int maxYear = 2030;

namespace sdds {
	class Date {
	private:
		int m_year;
		int m_month;
		int m_day;
		Status m_state;
		bool m_formatted;

		bool validate();
		int uniqueValue(int year, int month, int day);

	public:
		Date();
		Date(int year, int month, int day);
		bool operator == (const Date& date);
		bool operator != (const Date& date);
		bool operator <  (const Date& date);
		bool operator >  (const Date& date);
		bool operator <= (const Date& date);
		bool operator >= (const Date& date);
		const Status& state();
		Date& formatted(bool attribute);
		operator bool() const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		int format()const;
	};

	std::ostream& operator << (std::ostream& ostr, const Date& date);
	std::istream& operator >> (std::istream& istr, Date& date);
}
#endif // !SDDS_DATE_H
