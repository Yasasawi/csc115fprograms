/** ********************************************************************
* @file
************************************************************************/
#pragma once
#include <cctype>
#include <string> 

using namespace std; 

string getCCType(string cc); 
bool isAmericanExpress(string str);
bool isVisa(string str); 
bool isDiscover(string str);
bool isMaster(string str); 
bool isOddCalc(string cc);
bool isValidCC(string cc);
bool isEvenCalc(string cc);
