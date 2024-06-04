/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Perishable.h
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {

    class Perishable :public Item {
    private:
        Date m_expiry;
        char* m_handling;

    public:
        Perishable();
        Perishable(const Perishable& sourcd);
        Perishable& operator=(const Perishable& source);
        ~Perishable();
        operator bool() const override;
        const Date& expiry() const;
        std::ofstream& save(std::ofstream& ofstr)const override;
        std::ifstream& load(std::ifstream& ifstr)override;
        std::ostream& display(std::ostream& ostr)const override;
        std::istream& read(std::istream& istr)override;
        int readSku(std::istream& istr)override;
    };
}
#endif