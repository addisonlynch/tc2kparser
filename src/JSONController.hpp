//
//  JSONController.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/25/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef JSONController_hpp
#define JSONController_hpp

#include <stdio.h>

#include <fstream>
#include <vector>
#include <string>
#include "JSONObject.hpp"
#include <queue>
#include "StockBST.hpp"
#include "utilities.hpp"



using json = nlohmann::json;


class JSONController{
public:
    JSONController(const json& db);
    JSONController(const char* fileName);
    bool writeToFile(json j, const char* path);
    bool processFile(std::vector<json> store, const char* path);
    bool loadJSON(const char* fileName);
    bool add(const std::queue<todayTicker> list);
    bool add(const std::queue<string> tickers, const std::queue<double> prices);
    std::string dumpJSON();
    void printDatabase();
private:
    JSONObject database;
    double todaysClose3 = 32.23;
    JSONObject blankDatabase;
    
    
};


#endif /* JSONController_hpp */
