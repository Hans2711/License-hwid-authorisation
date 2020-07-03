#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mysql.h>
#include <Windows.h>
#include <string>
#include <random>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <cstdio>
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
void Init()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "88.99.204.168", "kehpgfap_root", "awdk123k1oo*we!423..", "kehpgfap_Sip", 3306, NULL, 0);
}
std::string random_string(std::string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    thread_local static std::mt19937 rg{ std::random_device{}() };
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::string s;
    s.reserve(length);
    while (length--)
        s += chrs[pick(rg)];
    return s;
}
int main()
{
    Init();
	int count;
    std::cout << "Enter the amount of keys" << std::endl;
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
        std::string days;
        printf("How many Days?\n");
        std::cin >> days;
        std::string Token = random_string(15);
        
        std::string down = "";
        std::ifstream f("SipAuth\\SipAuth.cpp");
        std::stringstream buffer;
        buffer << f.rdbuf();
        down = buffer.str();
        std::cin.get();
        f.close();


        for (int i = 213; i < (213 + 15); i++)
        {
            down[i] = Token[i - 213];
        }

        std::ofstream out("SipAuth\\SipAuth.cpp");
        out << down;
        out.close();
        

        std::string p = "INSERT INTO Tokens (Name, Days) VALUES ('";
        p += Token + "', '" + days +  "');";
        int tmp = mysql_query(conn, p.c_str());
        res = mysql_store_result(conn);

        system("build.lnk");
        printf("Done you can get the file now");
        system("pause");
	}
}
