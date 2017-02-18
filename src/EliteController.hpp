//
//  EliteControl.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/25/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef EliteControl_hpp
#define EliteControl_hpp

#include <stdio.h>
#include "MasterController.hpp"
#include <cassert>



class EliteController
{
public:
    EliteController();
    void runToday();
private:
    MasterController* mRemote;
    
};

static bool runStocks();

static bool runStocks()
{
    EliteController* elite = new EliteController;
   if(elite)
   {
       cerr << "Elite Controller Created." << endl;
       return true;
   }
    else
    {
        cerr << "Failure to create Elite Controller!" << endl;
        return false;
    }
    
    // elite->runToday();
    
}

#endif /* EliteControl_hpp */
