//
//  ExcelController.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/22/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#include "ExcelController.hpp"

#define FW_BOLD 700;


void ExcelController::printCellType(const BasicExcelCell* cell)
{
    switch(cell->Type())
    {
        case BasicExcelCell::UNDEFINED:
            cout << "UNDEFINED";
        case BasicExcelCell::INT:
            cout << "INT";
        case BasicExcelCell::DOUBLE:
            cout << "DOUBLE";
        case BasicExcelCell::STRING:
            cout << "STRING";
        case BasicExcelCell::WSTRING:
            cout << "WSTRING";
    }
}

void ExcelController::emptyQueue()
{
    while(!fromWorden.empty())
    {
        fromWorden.pop();
    }
    return;
}


bool ExcelController::printQueue()
{
    while(fromWorden.size() != 0)
    {
        string temp =  fromWorden.front();
        cout << "front: " << temp << endl;
        fromWorden.pop();
    }
    return true;
}

void doTodaysWork()
{
    
}


bool ExcelController::createSheet(string inPath, string masterPath)
{
    const char* inPathC = inPath.c_str();
    const char* masterPathC = masterPath.c_str();
    
    
    
    e.Load(inPathC);
    
    BasicExcelWorksheet* thisSheet = e.GetWorksheet(0);

    int totalRows = thisSheet->GetTotalRows();
   

    BasicExcelCell* cell;
    
    for(int row = 1; row < totalRows; row++)
    {
    cell = thisSheet->Cell(row, 0);
    char* temper;
    const wchar_t* temperest = cell->GetWString();
    wcstombs(temper, temperest, 6);
    fromWorden.push(charToString(temper));
    }
    

    f.Load(masterPathC);
    BasicExcelWorksheet* sheet = f.AddWorksheet(-1);
    
    /// Set the sheet name
    /*
    dateTime today;
    string date = today.todaysDateFormatted();
    const char* cDate = date.c_str();
    char* tempName;
    sheet->GetSheetName(tempName);
    f.RenameWorksheet(tempName, cDate);
    */
    ///
    
    XLSFormatManager fmt_mgr(f);
    
    ExcelFont font_bold;
    font_bold._weight = FW_BOLD;
    CellFormat fmt_bold(fmt_mgr);
    fmt_bold.set_font(font_bold);
    
    int col, row = 0;
    
    while(fromWorden.size() != 0)
    {
        BasicExcelCell* cell = sheet->Cell(row, col);
       
        string tempe;
        tempe = fromWorden.front();

        fromWorden.pop();
        
        char buffer[16];

        if(tempe.length() != 0)
        {
            const char* temp = tempe.c_str();
            sprintf(buffer, temp);
            
            cell->Set(buffer);
            
            
         //   fmt_bold.set_format_string(XLS_FORMAT_TEXT);
          //  cell->SetString(temp);
            //cell->SetFormat(fmt_bold);
            
            
        }
        row++;

    }
    
    f.SaveAs(masterPathC);
    return true;
}


bool ExcelController::readCol(std::queue<const char*>& returnQueue, const char* fileName, const int wkstNumber, const int colNumber)
{
    
    if(g.Load(fileName))
    {
    BasicExcelWorksheet* sheet = g.GetWorksheet(wkstNumber);
    int row, col;
    row = 0;
    col = colNumber;
    int totalRows = sheet->GetTotalRows();
    
    if(totalRows != 0)
    {
        BasicExcelCell* cell;
        
        while(row < totalRows)
        {
            cell = sheet->Cell(row, col);
            const char* tempVal = cell->GetString();
            returnQueue.push(tempVal);
            row++;
        }
    }
    return true;
    }
    else
        return false;
}


bool ExcelController::addPrices(std::queue<double> sendQueue, const char* fileName)
{
    BasicExcel e;
    e.Load(fileName);
    std::queue<double> tempDub = sendQueue;
    
    
    
    size_t worksheetNum = e.GetTotalWorkSheets();
    
    BasicExcelWorksheet* worksheet = e.GetWorksheet(1);
    
    int c = worksheet->GetTotalCols();
    int r = worksheet->GetTotalRows();
    int i(0);
    BasicExcelCell* cell;
    

    
    while(tempDub.size() != 0)
    {
    cell = worksheet->Cell(i, c+1);
        double temp = tempDub.front();
        cell->Set(temp);
        tempDub.pop();
        i++;
    }
    return true;


    
}

bool ExcelController::processTodaysSheet(queue<string>& todaysQueue)
{
    dateTime today;
    string inpath = today.todaysDateFormatted();
    inpath += ".xls";

    const char* inPathC = inpath.c_str();
    
    queue<string> temp;
    
    if(h.Load(inPathC))
       {
    BasicExcelWorksheet* thisSheet = h.GetWorksheet(0);
           
    if(!thisSheet)
    {
        cerr << "FAILURE /// Today's ticker list contains no worksheets!" << endl;
        return false;
    }
    
    int totalRows = thisSheet->GetTotalRows();

    
    BasicExcelCell* cell;
    
    for(int row = 2; row < totalRows; row++)
    {
        cell = thisSheet->Cell(row, 0);
        char buffer[6];
        const wchar_t* temperest = cell->GetWString();

        if(temperest == NULL)
        {
            cerr << "Cell (" << row << ", " << 0 << ") is NULL" << endl;
        }
        else
        {
            wcstombs(buffer, temperest, 6);

            temp.push(charToString(buffer));
            
    
        }
    }
 
    
    todaysQueue = temp;
       }
       else
       {
       cerr << "FAILURE: /// ExcelController::ProcessTodaysSheet: File could not be opened!" << endl;
           return false;
       }
    return true;
    

}


