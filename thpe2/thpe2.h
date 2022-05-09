#pragma once 

//libraries and namespaces
#include <cmath> 
#include <cctype>
#include <string>

using namespace std; 

//constants
const int TERMS = 10;
const double PI = atan(1.0) * 4;
const double ERRORVALUE = .000000000001;
const int ITERATIONMAX = 5000; 
const double ERRORTOLERANCE = .000001;

//prototypes

//array functions
void copyArray(double destinArr[], double sourceArr[], int size);
void initialArray(double initArr[], int size, double initVal);
double sumArray(double sumArray[], int size);
double averageArray(double avgArray[], int size);
int minLocation(double minArray[], int size);
double minValue(double minArray[], int size);
int maxLocation(double maxArray[], int size);
double maxValue(double maxArray[], int size);
int countIf(double countArray[], int size, double item);
void mySort(double sortArray[], int size, string order);
int linearSearch(double searchArray[], int size, double searchVal);
int binarySearch(double searchArray[], int size, double searchVal);
  
//Logs and powers functions
double mySqrt(double num);
double myCbrt(double num);
double myLog(double x, int base);

//Trig Functions
double factorial(double num);
double mySin(double radian);
double mySinD(double degree);
double myCos(double radian);
double myCosD(double degree);
double myTan(double radian);
double myTanD(double degrees);
double convert(double degrees);