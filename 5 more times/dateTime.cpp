//
//  dateTime.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/21/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//


#include "dateTime.h"
#



char* dateTime::todaysDate()
{
    time_t now = time(0);
    char * dt = ctime(&now);
    return dt;

}

char* dateTime::yesterdaysDate()
{
    time_t now = time(0);
    now = now - (60*60*24);
    char * dt = ctime(&now);
    return dt;
}



string dateTime::yesterdaysDateFormatted()
{
    string tempMonthYest;
    string tempDayYest;
    string tempYearYest;
    char* unformatted = yesterdaysDate();
    std::string addison(unformatted);
    addison += "x";
    
    
    for (int i(4); i <=6; i++)
    {
        tempMonthYest+= addison[i];
    }
    
    for (int i(8); i <=9; i++)
    {
        tempDayYest += addison[i];
    }
    
    for (int i(20); i <=23; i++)
    {
        tempYearYest += addison[i];
    }
    
    string convertMonth = monthToNumber(tempMonthYest);
    string tempReturn = convertMonth += tempDayYest += tempYearYest;
    
    return tempReturn;
}

string dateTime::todaysDateFormatted()
{
    string tempDay;
    string tempMonth;
    string tempYear;
    
    char* unformatted = todaysDate();
    
    std::string addison(unformatted);
    addison += "x";
    

    for (int i(4); i <=6; i++)
    {
        tempMonth += addison[i];
    }
    
    if(strcmp(&addison[8], ""))
    {
        tempDay += "0";
    }
    else
    {
        tempDay += addison[8];
    }
    
    tempDay += addison[9];
    
    
    
    for (int i(20); i <=23; i++)
    {
        tempYear += addison[i];
    }

    string convertMonth = monthToNumber(tempMonth);
    string tempReturn = convertMonth += tempDay += tempYear;
    
    return tempReturn;
}


string dateTime::monthToNumber(string month)
{
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string tempReturn;
    int index(0);
    for(int i(0); i <= 12; i++)
    {
        if (months[i] == month)
        {
            tempReturn += to_string(i+1);
            index = i;
            break;
        }
        index = i;
       
    }
    
    if(tempReturn.length() == 1)
    {
        tempReturn.insert(0, "0");
    }
    return tempReturn;
}