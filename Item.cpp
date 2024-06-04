/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Item.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name Jagbir Singh    Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include <string>
#include <iomanip>
#include <limits>
#include "Item.h"

using namespace std;

namespace sdds
{
	bool Item::linear()const
	{
		return m_linear;
	}

	Item::Item() : m_state()
	{
		m_description = nullptr;
		m_linear = false;
		m_price = 0.0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_sku = 0;
	}

	Item::Item(const Item& source) : m_state(source.m_state)
	{
		m_description = nullptr;
		if (source.m_description != nullptr) {
			m_description = new char[strlen(source.m_description) + 1];
			strcpy(m_description, source.m_description);
		}
		else
		{
			m_description = nullptr;
		}
		m_linear = source.m_linear;
		m_price = source.m_price;
		m_qty = source.m_qty;
		m_qtyNeeded = source.m_qtyNeeded;
		m_sku = source.m_sku;
	}

	Item& Item::operator=(const Item& source)
	{
		if (this != &source)
		{
			delete[] m_description;
			if (source.m_description != nullptr)
			{
				m_description = new char[strlen(source.m_description) + 1];
				strcpy(m_description, source.m_description);
			}
			else
			{
				m_description = nullptr;
			}

			m_linear = source.m_linear;
			m_price = source.m_price;
			m_qty = source.m_qty;
			m_qtyNeeded = source.m_qtyNeeded;
			m_sku = source.m_sku;
			m_state = source.m_state.operator const char* ();
			m_state = source.m_state.operator int();
		}
		return *this;
	}

	Item::~Item()
	{
		delete[] m_description;
	}

	int Item::qtyNeeded()const
	{
		return m_qtyNeeded;
	}

	int Item::qty()const
	{
		return m_qty;
	}

	Item::operator double()const
	{
		return m_price;
	}

	Item::operator bool()const
	{
		return m_linear;
	}

	int Item::operator-=(int qty)
	{
		return m_qty -= qty;
	}

	int Item::operator+=(int qty)
	{
		return m_qty += qty;
	}

	void Item::linear(bool islinear)
	{
		m_linear = islinear;
	}

	void Item::clear()
	{
		m_state = nullptr;
		m_state = 0;
	}

	bool Item::operator==(int sku)const
	{
		return m_sku == sku;
	}

	bool Item::operator==(const char* description)const
	{
		bool ok = false;
		if (description == nullptr || m_description == nullptr) {
			ok = false;
		}
		else if (strstr(m_description, description) != nullptr) {
			ok = true;
		}

		return ok;
	}

	ofstream& Item::save(ofstream& ofstr)const
	{
		if (m_state)
		{
			ofstr << m_sku << '\t' << m_description << '\t' << m_qty << '\t' << m_qtyNeeded << '\t' << fixed << setprecision(2) << m_price << '\t';
		}
		return ofstr;
	}

	ifstream& Item::load(ifstream& ifstr)
	{
		char description[1024];
		delete[] m_description;
		ifstr >> m_sku;
		ifstr.ignore();
		ifstr.getline(description, 1023, '\t');
		m_description = new char[strlen(description) + 1];
		strcpy(m_description, description);
		ifstr >> m_qty;
		ifstr.ignore();
		ifstr >> m_qtyNeeded;
		ifstr.ignore();
		ifstr >> m_price;
		ifstr.ignore();

		if (ifstr.bad())
		{
			m_state = "Input file stream read failed!";
		}

		return ifstr;
	}

	ostream& Item::display(ostream& ostr)const
	{
		if (!m_state)
		{
			ostr << m_state;
		}
		else
		{
			if (m_linear)
			{
				ostr.fill(' ');
				ostr << setw(5) << m_sku << " | " << setw(35) << left << (strlen(m_description) > 35 ? string(m_description, 35) : m_description);
				ostr << " | " << setw(4) << right << m_qty << " | " << setw(4) << right << m_qtyNeeded << " | " << setw(7) << setprecision(2) << m_price << " |";
			}
			else
			{
				ostr << "AMA Item:" << endl << setw(5) << m_sku << ": " << m_description << endl << "Quantity Needed: " << m_qtyNeeded << endl << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << fixed << setprecision(2) << m_price << endl << setprecision(2) << "Needed Purchase Fund: $" << (m_qtyNeeded * m_price) - (m_qty * m_price) << endl;
			}
		}
		return ostr;
	}

	int Item::readSku(istream& istr)
	{
		m_state.clear();
		bool validInput = false;
		cout << "SKU: ";

		do {
			istr >> m_sku;

			if (istr.fail())
			{
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Invalid Integer, retry: ";
			}
			else if (m_sku < 40000 || m_sku > 99999)
			{
				cout << "Value out of range [40000<=val<=99999]: ";
			}
			else
			{
				validInput = true;
			}
		} while (validInput == false);

		return m_sku;
	}

	istream& Item::read(istream& istr)
	{
		char description[1024];

		delete[] m_description;
		m_state.clear();

		cout << "AMA Item:" << endl << "SKU: " << m_sku << endl << "Description: ";
		istr.ignore();
		istr.getline(description, 1023, '\n');
		m_description = new char[strlen(description) + 1];
		strcpy(m_description, description);
		cout << "Quantity Needed: ";
		bool validInput = false;

		do {
			istr >> m_qtyNeeded;

			if (istr.fail())
			{
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Invalid Integer, retry: ";
			}
			else if (m_qtyNeeded < 1 || m_qtyNeeded > 9999)
			{
				cout << "Value out of range [1<=val<=9999]: ";
			}
			else
			{
				validInput = true;
			}
		} while (validInput == false);

		cout << "Quantity On Hand: ";
		validInput = false;

		do {
			istr >> m_qty;

			if (istr.fail())
			{
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Invalid Integer, retry: ";
			}
			else if (m_qty < 0 || m_qty > m_qtyNeeded)
			{
				cout << "Value out of range [0<=val<=" << m_qtyNeeded << "]: ";
			}
			else
			{
				validInput = true;
			}
		} while (validInput == false);

		cout << "Unit Price: $";
		validInput = false;

		do {
			if (!(istr >> m_price))
			{
				istr.clear();
				istr.ignore(1000, '\n');
				cout << "Invalid number, retry: ";
			}
			else if (m_price < 0.0 || m_price > 9999.0)
			{
				cout << "Value out of range [0.00<=val<=9999.00]: ";
			}
			else
			{
				validInput = true;
			}
		} while (validInput == false);

		if (istr.fail())
		{
			m_state = "Console entry failed!";
		}

		return istr;
	}
}