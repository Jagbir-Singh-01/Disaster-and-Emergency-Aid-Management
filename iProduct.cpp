/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: iProduct.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name Jagbir Singh    Date            Reason
***********************************************************************/
#include "iProduct.h"

using namespace std;

namespace sdds
{
	ostream& operator<<(ostream& ostr, const iProduct& print)
	{
		print.display(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, iProduct& scan)
	{
		scan.read(istr);
		return istr;
	}
}