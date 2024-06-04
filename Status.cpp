/* Citation and Sources...
Final Project Milestone ?
Module: Status
Filename: Status.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Status.h"

using namespace std;

namespace sdds {
	// Constructor
	Status::Status() {
		m_description = nullptr;
		m_code = 0;
	}

	Status::Status(char* description) {
		m_description = nullptr;
		if (description != nullptr)
		{
			m_description = new char[strlen(description) + 1];
			strcpy(m_description, description);
		}
		m_code = 0;
	}

	Status::Status(const Status& source) {
		m_description = nullptr;
		if (source.m_description != nullptr) {
			m_description = new char[strlen(source.m_description) + 1];
			strcpy(m_description, source.m_description);
		}

		m_code = source.m_code;
	}

	// Deconstructor
	Status::~Status() {
		delete[] m_description;
		m_description = nullptr;
	}

	// Copy Assignment Operator
	Status& Status::operator=(const char cString[]) {
		delete[] m_description;
		m_description = nullptr;
		if (cString != nullptr) {
			m_description = new char[strlen(cString) + 1];
			strcpy(m_description, cString);
		}
		return *this;
	}

	Status& Status::operator=(int value) {
		(*this).m_code = value;

		return *this;
	}

	// Type conversion overloaded
	Status::operator int() const {
		return m_code;
	}

	Status::operator const char* () const {
		return m_description;
	}

	Status::operator bool()const {
		bool ok = false;
		if ((*this).m_description == nullptr) {
			ok = true;
		}
		return ok;
	}

	// Clearing Values of Status
	Status& Status::clear() {
		delete[] m_description;
		m_description = nullptr;

		m_code = 0;

		return *this;
	}

	// Helper insertion operator overloaded
	ostream& operator << (ostream& ostr, const Status& ro) {
		if (!bool(ro)) {
			if (int(ro) != 0) {
				ostr << "ERR#" << int(ro) << ": " << (const char*)(ro);
			}
			else {
				ostr << (const char*)(ro);
			}
		}
		return ostr;
	}
}