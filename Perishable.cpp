/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Perishable.cpp
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
#include <fstream>
#include "Perishable.h"
#include "Status.h"

using namespace std;
namespace sdds {

    Perishable::Perishable() : Item(), m_expiry()
    {
        m_handling = nullptr;
    }

    Perishable::Perishable(const Perishable& source) : Item(source), m_expiry(source.m_expiry)
    {
        if (source.m_handling != nullptr)
        {
            m_handling = new char[strlen(source.m_handling) + 1];
            strcpy(m_handling, source.m_handling);
        }
        else
        {
            m_handling = nullptr;
        }
    }

    Perishable& Perishable::operator=(const Perishable& source)
    {
        if (this != &source)
        {
            Item::operator=(source);

            delete[] m_handling;
            m_expiry = source.m_expiry;

            if (source.m_handling != nullptr)
            {
                m_handling = new char[strlen(source.m_handling) + 1];
                strcpy(m_handling, source.m_handling);
            }
            else
            {
                m_handling = nullptr;
            }
        }
        return *this;
    }

    Perishable::~Perishable()
    {
        delete[] m_handling;
    }

    Perishable::operator bool() const
    {
        return m_sku != 0;
    }

    const Date& Perishable::expiry() const
    {
        return m_expiry;
    }

    ofstream& Perishable::save(ofstream& ofstr) const
    {
        if (m_state)
        {
            Item::save(ofstr);

            if (m_handling != nullptr)
            {
                ofstr << m_handling << "\t";
            }
            else
            {
                ofstr << "\t";
            }
            ofstr << m_expiry.format();
        }
        return ofstr;
    }

    ifstream& Perishable::load(ifstream& ifstr)
    {
        Item::load(ifstr);

        if (ifstr.fail())
        {
            m_state = "Input file stream read (perishable) failed!";
            return ifstr;
        }

        delete[] m_handling;
        m_handling = nullptr;

        char handling[1024];
        ifstr.getline(handling, 1023, '\t');
        m_handling = new char[strlen(handling) + 1];
        strcpy(m_handling, handling);

        ifstr >> m_expiry;
        ifstr.ignore();

        return ifstr;
    }

    ostream& Perishable::display(ostream& ostr) const
    {
        if (!m_state)
        {
            ostr << m_state;
        }
        else
        {
            if (Item::linear())
            {
                Item::display(ostr);

                ostr << (m_handling && *m_handling ? '*' : ' ');
                ostr << m_expiry;
            }
            else
            {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                ostr << m_expiry;
                cout << endl;
                if (m_handling && *m_handling)
                {
                    ostr << "Handling Instructions: " << m_handling << endl;
                }
            }
        }
        return ostr;
    }

    istream& Perishable::read(istream& istr)
    {
        char handling[1024];
        Item::read(istr);
        delete[] m_handling;
        m_handling = nullptr;

        std::cout << "Expiry date (YYMMDD): ";
        istr >> m_expiry;
        istr.ignore();

        std::cout << "Handling Instructions, ENTER to skip: ";
        char ch = istr.peek();
        if (ch != '\n')
        {
            istr.getline(handling, 1023, '\n');
            m_handling = new char[strlen(handling) + 1];
            strcpy(m_handling, handling);
        }
        else
        {
            istr.ignore();
        }

        if (istr.fail())
        {
            m_state = "Perishable console date entry failed!";
        }

        return istr;
    }

    int Perishable::readSku(istream& istr)
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
            else if (m_sku < 10000 || m_sku > 39999)
            {
                cout << "Value out of range [10000<=val<=39999]: ";
            }
            else
            {
                validInput = true;
            }
        } while (validInput == false);

        return m_sku;
    }


}
