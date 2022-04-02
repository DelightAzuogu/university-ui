#include <mysql.h>
#include "login.h"
#include <ctime>
#include <string>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]


void main(array<String^>^ args)
{
    using namespace std;
    std::time_t t = std::time(nullptr);
    std::tm* const pTInfo = std::localtime(&t);
    int year = 1900 + pTInfo->tm_year;

    int month = 1 + pTInfo->tm_mon;
    if (month == 1)
        year--;
    string semester = (month >= 2 && month <= 6) ? "spring" : (month >= 7 && month <= 9) ? "summer" : "fall";

    String^ s = gcnew String(semester.c_str());

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project::login^ form = gcnew Project::login(year,s);
    Application::Run(form);
}
