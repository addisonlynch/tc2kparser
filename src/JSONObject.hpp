//
//  JSONObject.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/25/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef JSONObject_hpp
#define JSONObject_hpp

#include <stdio.h>
#include "json.hpp"
#include <map>
#include "dateTime.h"
#include <string>




using json = nlohmann::json;

class JSONObject
{
public:
    JSONObject();
    JSONObject(const json& file);
    JSONObject& operator=(const JSONObject& rhs);
    void print();
    void send(json& jObject);
    template <class T>
    bool edit(const char* key, T val);
    bool update(const char* ticker, double closePrice, bool qualifiedToday, bool newStock);
    bool addQualifyDate(const char* ticker, const double closePrice);
    std::string toString();
    
    
private:
    json j;
};



#endif /* JSONObject_hpp */
