#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;
//constants 
const int royalflushNum = 9; 
const int straightflushNum  = 8;
const int fourofaKind = 7; 
const int fullhouseNum = 6; 
const int flushNum = 5;
const int straightNum = 4;
const int threeofaKind = 3; 
const int twopairNum = 2;
const int twoofaKind = 1;
const int highcardNum = 0; 
const int arrSize = 5; 

//card functions
int classifyHand(int card[], int size);
bool twoPair(int card[], int face[], int size);
bool isFlush(int card[], int suit[], int size);
bool twoKind(int card[], int face[], int size);
bool threeKind(int card[], int face[], int size);
bool fourKind(int card[], int face[], int size);
bool fullHouse(int card[], int face[], int size);
bool straight(int card[], int size);
bool straightZero(int card[], int face[], int size);
bool straightFlush(int card[], int face[], int suit[], int size);
bool royalFlush(int card[], int face[], int suit[], int size);

//helper functions
void getSuit(int card[], int suit[], int size);
void getFace(int card[], int face[], int size); 
void mySort(int sortArray[], int size);
void cleanUp(ifstream& input, ofstream& output);
bool openOutput(ofstream& fout, string fileName);
bool openInput(ifstream& fout, string fileName);