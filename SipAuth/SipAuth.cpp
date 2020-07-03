#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mysql.h>
#include <Windows.h>
#include <string>
#include <time.h>
#include "Util.h"
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
std::string Serial = "b4iKhfW8Ss8XEyn";
void Init()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "IP", "USERNAME", "PASSWORD", "DB", 3306, NULL, 0);
}
std::string gethwid()
{
    //Do your hwid here
    return "m12312fawdasd";
}
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%S-%M-%d-%m", &tstruct);
    return buf;
}
bool validateDate(std::string Server)
{
    std::string loc = currentDateTime();

    int iDays = convertCharstoInt(Server[6], Server[7]);
    int iSec = convertCharstoInt(Server[0], Server[1]);
    int iMin = convertCharstoInt(Server[3], Server[4]);
    int iMonth = convertCharstoInt(Server[9], Server[10]);

    int iiDays = convertCharstoInt(loc[6], loc[7]);
    int iiSec = convertCharstoInt(loc[0], loc[1]);
    int iiMin = convertCharstoInt(loc[3], loc[4]);
    int iiMonth = convertCharstoInt(loc[9], loc[10]);

    if (iMonth < iiMonth)
    {
        return false;
    }
    if (iMonth == iiMonth)
    {
        if (iDays > iiDays)
        {
            return true;
        }
        if (iDays < iiDays)
        {
            return false;
        }
        if (iDays == iiDays)
        {
            if (iMin < iiMin)
            {
                return false;
            }
            if (iMin > iiMin)
            {
                return true;
            }
            if (iMin == iiMin)
            {
                if (iSec < iiSec)
                {
                    return false;
                }
                if (iSec > iiSec)
                {
                    return true;
                }
                if (iSec == iiSec)
                {
                    return true;
                }
            }
        }
    }
    if (iMonth > iiMonth)
    {
        return true;
    }

    return true;
}
bool AuthToken()
{
    std::string p = "SELECT * FROM Tokens WHERE Name='";
    std::string query = p + Serial + "';";
    int tmp = mysql_query(conn, query.c_str());
    res = mysql_store_result(conn);
    std::string rlHwid = "";
    std::string startDate = "";
    std::string name = "";
    std::string Days = "";
    while (row = mysql_fetch_row(res))
    {
        name = row[1];
        rlHwid = row[2];
        startDate = row[3];
        Days = row[4];
    }
    if (rlHwid == "" && startDate == "" && name == "" && Days == "")
    {
        return false;
    }
    if (rlHwid == "" && startDate == "" && name != "")
    {
        std::string p = "UPDATE Tokens SET Hwid='";
        p += gethwid() + "' WHERE Name='" + name + "';";
        tmp = mysql_query(conn, p.c_str());
        res = mysql_store_result(conn);
        char* tmp1 = convertToChar(Days);

        int adDays = convertCharstoInt(tmp1);

        std::string curDate = currentDateTime();
        int iDays = convertCharstoInt(curDate[6], curDate[7]);
        int iMonths = convertCharstoInt(curDate[9], curDate[10]);
        iDays = iDays + adDays;
        while (iDays > 30)
        {
            
            iMonths++;
            iDays = iDays - 30;
        }
        std::string tmp = convertToString(iMonths);
        char* dd = convertToChar(tmp);
        if (iMonths <= 9)
        {
            curDate[9] = '0';
            curDate[10] = dd[0];
        }
        else
        {
            curDate[9] = dd[0];
            curDate[10] = dd[9];
        }

        tmp = convertToString(iDays);
        char* d = convertToChar(tmp);
        if (iDays <= 9)
        {
            curDate[6] = '0';
            curDate[7] = d[0];
        }
        else
        {
            curDate[6] = d[0];
            curDate[7] = d[1];
        }

        p = "UPDATE Tokens SET StartDate='";
        p += curDate + "' WHERE Name='" + name + "';";
        tmp = mysql_query(conn, p.c_str());
        res = mysql_store_result(conn);
    }
    if (rlHwid != "" && startDate != "" && name != "")
    {
        if (rlHwid != gethwid())
        {
            return false;
        }
        std::string locDate = currentDateTime();
        if (validateDate(startDate))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    Init();
    if (AuthToken())
    {
        std::cout << "yes";
    }
    else
    {
        std::cout << "no";
    }
    std::cin.get();

}
