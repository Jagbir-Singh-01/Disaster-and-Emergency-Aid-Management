/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// Revision History
// -----------------------------------------------------------
// Name Jagbir Singh    Date            Reason
***********************************************************************/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H
