//
//  YahooController.hpp
//  5 more times
//
//  Created by Addison Lynch on 8/24/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#ifndef YahooController_hpp
#define YahooController_hpp

#include <stdio.h>
#include "quote.h"
#include <queue>
#include <iostream>

using namespace  quote;

class YahooController
{
private:
    std::vector<QuoteType> m_quotes;
    
    
public:
    YahooController();
    
    std::queue<std::string> downloadTodaysPrices(const std::queue<std::string> list);
    
};

#endif /* YahooController_hpp */
