/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Item.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name Jagbir Singh    Date            Reason
***********************************************************************/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"

namespace sdds
{
	class Item : public iProduct
	{
		char* m_description;
		bool m_linear;
		double m_price;
		int m_qty;
		int m_qtyNeeded;

	protected:
		int m_sku;
		Status m_state;

		bool linear()const;

	public:
		Item();
		Item(const Item& source);
		Item& operator=(const Item& source);
		~Item();
		int qtyNeeded()const override;
		int qty()const override;
		operator double()const override;
		operator bool()const override;
		int operator-=(int qty)override;
		int operator+=(int qty)override;
		void linear(bool isLinear)override;
		void clear();
		bool operator==(int sku)const override;
		bool operator==(const char* description)const override;
		std::ofstream& save(std::ofstream& ofstr)const override;
		std::ifstream& load(std::ifstream& ifstr)override;
		std::ostream& display(std::ostream& ostr)const override;
		std::istream& read(std::istream& istr)override;
		int readSku(std::istream& istr)override;
	};
}

#endif