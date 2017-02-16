//
//  JSONObject.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/25/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#include "JSONObject.hpp"

dateTime today;
string todayDate = today.todaysDateFormatted();


JSONObject::JSONObject()
{
    json j;
}

JSONObject::JSONObject(const json& file): j(file)
{
}

bool JSONObject::addQualifyDate(const char* ticker, const double closePrice)
{
    j[ticker]["qualify"][todayDate] = closePrice;
    return true;
}



bool JSONObject::update(const char* ticker, double closePrice, bool qualifiedToday, bool newStock)
{
    // Check to see if the ticker is already in the DB
    
    
    
    
    if(!newStock)
    {
        j[ticker]["closePrice"] = closePrice;
        j[ticker]["prices"][todayDate] = closePrice;
        if(qualifiedToday)
        j[ticker]["qualify"][todayDate] = closePrice;
        return true;

    }
    else if (newStock)
    {
        j[ticker];
        j[ticker]["ticker"] = ticker;
        j[ticker]["closePrice"] = closePrice;
        j[ticker]["prices"];
        j[ticker]["prices"][todayDate] = closePrice;
        j[ticker]["qualify"];
        j[ticker]["qualify"][todayDate] = closePrice;
        return true;
    }
    
    return false;
    
    

    
}

void JSONObject::print()
{
    std::string dumper = j.dump(4);
    if (dumper == "")
        cerr << "Empty database!" << endl;
    else
        cout << dumper;
}

void JSONObject::send(json& jObject)
{
    jObject = j;
    return;
}


template <class T>
bool JSONObject::edit(const char* key, T val)
{
    
    j[key]=val;
    return true;
}

std::string JSONObject::toString()
{
    return j.dump();
}



JSONObject& JSONObject::operator=(const JSONObject& rhs)
{
    this->j = rhs.j;
    return *this;
}

/*
bool JSONObject::update(const char* ticker, double closePrice, bool qualifiedToday, bool newStock)
{
    dateTime today;
    string todayDate = today.todaysDateFormatted();
    
    j["closePrice"] = closePrice;
    j["prices"][todayDate] = closePrice;
    
    if(qualifiedToday)
    {
        j["qualify"][todayDate] = closePrice;
    }
    else
        return true;
    return true;
}
 */

