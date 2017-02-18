//
//  YahooController.cpp
//  5 more times
//
//  Created by Addison Lynch on 8/24/16.
//  Copyright © 2016 Addison Lynch. All rights reserved.
//

#include "YahooController.hpp"

YahooController::YahooController()
{
    m_quotes.push_back(QuoteType::previousClose);
}


std::queue<std::string> YahooController::downloadTodaysPrices(const std::queue<std::string> list)
{
    std::queue<std::string> temp = list;
    std::queue<std::string> send;
    if(list.size() == 0)
    {
        std::cout << "No symbols to download!" << std::endl;
        return temp;
    }
    else
    {
        while(temp.size() != 0)
        {
            std::string buffer= temp.front();
            std::string quotes= getLatestQuotesCsv(buffer, m_quotes);
            send.push(quotes);
            temp.pop();
        }
    }
    return send;
}