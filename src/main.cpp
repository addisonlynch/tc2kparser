




#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shellapi.h>
#include <crtdbg.h>

#else // _WIN32

#define	FW_NORMAL	400
#define	FW_BOLD		700


#include <iostream>

#include "EliteController.hpp"


#include "YahooController.hpp"
#include <queue>


using json = nlohmann::json;

using namespace std;

int main()
{
    EliteController* runThisShit = new EliteController;

}




#endif // _WIN32






/*   ExcelController remote;
 queue<string> temp;
 remote.processToday(temp);
 
 while(temp.size() !=0)
 {
 cout << temp.front() << endl;
 temp.pop();
 
 }
 */