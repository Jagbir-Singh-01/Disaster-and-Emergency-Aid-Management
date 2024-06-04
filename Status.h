/* Citation and Sources...
Final Project Milestone ?
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
namespace sdds {
	class Status {
	private:
		char* m_description;
		int m_code;

	public:
		Status();
		Status(char* description);
		Status(const Status& source);
		~Status();
		Status& operator=(const char cString[]);
		Status& operator=(int value);
		operator int() const;
		operator const char* ()const;
		operator bool()const;
		Status& clear();
	};

	std::ostream& operator << (std::ostream& ostr, const Status& rightoperand);
}
#endif