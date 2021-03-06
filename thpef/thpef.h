#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <istream>
#include <sstream>
#include <iomanip>
#include "ourDate.h"


using namespace std;

//structure
struct customer
{
    string firstName; 
    string lastName;
    string streetAddress;
    string city; 
    string state;
    string zipCode;
    double transAmount;
    double balance; 
};

//actual functions
string getDate();
bool getClient(ifstream& fin, customer& customer);
void writeLetter(customer& customer, string templateFile, string currentDate);

//helper functions
void cleanUp(ifstream& fin, ifstream& fin1, ifstream& fin2, ifstream& fin3);
bool openOutput(ofstream& fout, string fileName);
bool openInput(ifstream& fin, string fileName);
void findAndReplace(string& line, string stringSearch, string replace);
