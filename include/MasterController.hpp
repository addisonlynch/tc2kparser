//
//  Master Control.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/22/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef Master_Control_hpp
#define Master_Control_hpp

#include <stdio.h>
#include <fstream>
#include <string>


#include "quote.h"
#include "exception/exception.hpp"


#include "JSONController.hpp"
#include "YahooController.hpp"
#include "ExcelController.hpp"







class MasterController
{
public:
    
    // Constructor
    
    MasterController(const char* databaseName, const char* masterListName);
    
    // Daily
    bool dailyUpdate(); // process today's prices, add them to the JSON DB
    
    
    // Process
    bool processJSON(const char* fileName); // load JSON db from file
    bool processMaster(const char* fileName); // load master list from file,
    bool processToday(); // load today's sheet from worden export  | init todaysQueue, addToMaster
    
    
    // Update
    
    bool updateDatabase();
    bool updateMaster();
    bool retrievePrices();
    bool updatePrices();
    
    // Write
    bool writeMaster(const char* fileName);
    bool writeJSONFile(std::string fileName); // write json file, will concatenate date and .txt to end of fileName (send database)

    // AUX
    
    bool checkNew(const char* ticker, const BST masterList) const;
    std::queue<std::string> tickerToString(const queue<todayTicker>& todaysQueue);
    
    // Test
    void print(const char* queueName);

    
    // DESTRUCTOR
    ~MasterController();
    
private:
    ExcelController* eRemote;
    YahooController* yRemote;
    JSONController*  jRemote;
    dateTime* today;
    queue<todayTicker> m_todaysQueue;
    BST m_masterList;
    queue<string> addToMaster;
    queue<string> masterQueue;
};



#endif /* Master_Control_hpp */
