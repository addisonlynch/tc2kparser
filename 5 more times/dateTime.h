//
//  dateTime.h
//  5 more times
//
//  Created by Addison Lynch on 8/21/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//



#ifndef dateTime_h
#define dateTime_h

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;


class dateTime
{
public:
    int day(){return m_day;};
    int month(){return m_month;};
    int year(){return m_year;};
    char* todaysDate();
    char* yesterdaysDate();
    string todaysDateFormatted();
    string yesterdaysDateFormatted();
    string monthToNumber(string month);
    
private:
    int m_day;
    int m_month;
    int m_year;
};





#endif /* dateTime_h */
