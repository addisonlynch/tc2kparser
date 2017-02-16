//
//  JSONController.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/25/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#include "JSONController.hpp"


JSONController::JSONController(const json& db) : database(db)
{
}

JSONController::JSONController(const char* fileName)
{
    ifstream file;
    file.open(fileName);
    string buffer;
    if(file)
    {
        file >> buffer;
        if(buffer == "")
        {
            database = blankDatabase;
            cerr << "Empty database file!" << endl;
        }
        else
            database = json::parse(buffer);
    }
    else
        cerr << "Database file could not be opened!" << endl;
    file.close();
    return;
    
}

bool JSONController::add(const std::queue<todayTicker> list)
{
    if(list.size() == 0)
        return false;
    
    
    std::queue<todayTicker> list2 = list;
    
    while(list2.size() != 0)
    {
        todayTicker buffer = list2.front();
        
        if(buffer.newStock)
        {
            database.update(buffer.tickerSymbol.c_str(), buffer.todaysClose, true, true);
        }
        else if(!buffer.newStock)
        {
            database.update(buffer.tickerSymbol.c_str(), buffer.todaysClose, true, false);
        }
        list2.pop();
    }
    return true;
}

bool JSONController::add(const std::queue<string> tickers, const std::queue<double> prices)
{
    std::queue<string> temp1 = tickers;
    std::queue<double> temp2 = prices;

    
    while(temp1.size() != 0 && temp2.size() != 0)
    {
        string buffer1 = temp1.front();
        double buffer2 = temp2.front();
        
        database.update(buffer1.c_str(), buffer2, false, false);
        
    }
    return false;
}

/*
bool JSONController::addQualify(const std::queue<string> list)
{
    std::queue<string> temp = list;
    while(temp.size() != 0)
    {
        const char* buffer = list.front().c_str();
        database.addQualifyDate(buffer, todaysClose3);
        temp.pop();
        
    }
    return true;
}
*/

bool JSONController::loadJSON(const char* fileName)
{
    return false;
}


bool writeToFile(std::vector<json> j, const char* path)
{
    std::ofstream outFile(path);
    
    
    return false;
    
    
    
}

void JSONController::printDatabase()
{
    database.print();
    return;
}


bool processFile(std::vector<json> store, const char* path)
{
    return false;
}


std::string JSONController::dumpJSON()
{
    return database.toString();
}

