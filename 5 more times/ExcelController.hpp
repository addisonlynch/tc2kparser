//
//  ExcelController.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/22/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef ExcelController_hpp
#define ExcelController_hpp



#include <iostream>
#include <queue>
#include "BasicExcel.hpp"
#include "ExcelFormat.h"
#include "utilities.hpp"
#include "dateTime.h"



using namespace ExcelFormat;



class ExcelController
{
public:
    bool createSheet(string inPath, string masterPath);
    bool wordenToQueue(const char* path);
    bool printQueue();
    string front(){return fromWorden.front();};
    void emptyQueue();
    void printCellType(const BasicExcelCell* cell);
    void addPrice();
    bool readCol(std::queue<const char*>& returnQueue, const char* fileName, const int wkstNumber, const int colNumber);
    bool addPrices(std::queue<double> sendQueue, const char* fileName);
    int rows(BasicExcelWorksheet worksheet) {return worksheet.GetTotalRows();};
    int cols(BasicExcelWorksheet worksheet) {return worksheet.GetTotalCols();};
    bool processTodaysSheet(queue<string>& todaysQueue);
private:
    std::queue<string> fromWorden;
    BasicExcel e;
    BasicExcel f;
    BasicExcel g;
    BasicExcel h;
};



#endif /* ExcelController_hpp */
