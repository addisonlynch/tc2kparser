//
//  EliteControl.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/25/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#include "EliteController.hpp"

EliteController::EliteController(){
    mRemote = new MasterController("database09032016.json","masterlist.txt");
}

void EliteController::runToday()
{
    mRemote->dailyUpdate();
    
}