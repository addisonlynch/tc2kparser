//
//  debugging.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/26/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#include <stdio.h>


std::queue<string> temp;
while(temp.size() != 0)
{
    
    cout << temp.front() << endl;
    temp.pop();
    }
    exit(0);
}


// yRemote testing
    /*
     YahooController yRemote;
     queue<string> send;
     
     send.push("AAPL");
     send.push("MSFT");
     send.push("BTG");
     
     queue<string> store;
     store = yRemote.downloadTodaysPrices(send);
     
     while(store.size() != 0)
     {
     cout << store.front() << endl;
     store.pop();
     }
     */
    
    
    
    



//jsoncontroller::writeJSON

    const char* temper = today.todaysDateFormatted().c_str();
    const char* txt = ".json";
    char* h;
    
    strcat(h, fileNameFormatted);
    
    strcat(h, temper);
    strcat(h, txt);
    
    cout << "JSON file name (test)" << fileNameFormatted << endl;
    
    //
    
    
    m_masterList.display();
    cout << endl << endl << endl;


//excelcontroller  read in
            cout << "temper " << row<< ": " << buffer << endl;