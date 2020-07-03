#pragma once
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <sstream> 
#include <atlstr.h>
#include <Windows.h>
#include <WinUser.h>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <atlbase.h>
#include <atlstr.h>
#include <comutil.h>
#include<sstream>  
#include <wbemidl.h>
#include <string>
#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include <Urlmon.h>
#include <iostream>
#include <fstream>
#include <iphlpapi.h>
#include <intrin.h>
#include <Winternl.h>#include<iphlpapi.h>
#include<stdlib.h>
#include<tlhelp32.h>
#include<tchar.h>
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>
using namespace std;


string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
char* convertToChar(string str)
{
	char* cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	return cstr;
}
string convertToString(int a)
{
	stringstream ss;
	ss << a;
	string s;
	ss >> s;
	return s;
}
int convertCharstoInt(char a, char b)
{
	char to[2];
	to[0] = a;
	to[1] = b;

	string toStringed = convertToString(to, sizeof(to));
	stringstream stream(toStringed);
	int Intvar = 0;
	stream >> Intvar;
	return Intvar;
}
int convertCharstoInt(char* a)
{

	string toStringed = convertToString(a, sizeof(a));
	stringstream stream(toStringed);
	int Intvar = 0;
	stream >> Intvar;
	return Intvar;
}