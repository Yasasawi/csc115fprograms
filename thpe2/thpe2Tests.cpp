#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"

//trig testing
TEST_CASE("convert - testing 45")
{
    double radians;
    
    radians = convert(45);
    
    REQUIRE(Approx(radians) == PI/4);
}
TEST_CASE("convert - testing 180")
{
    double radians;
    
    radians = convert(180);
    
    REQUIRE(Approx(radians) == PI);
}
TEST_CASE("convert - testing 60")
{
    double radians;
    
    radians = convert(60);
    
    REQUIRE(Approx(radians) == PI/3);
}
TEST_CASE("trig - testing 0")
{
    double sin;
    double cos;
    double tan;
    double num = 0;
    SECTION("myTanD - 0")
    {
        tan = myTanD(num);
        
        REQUIRE(fabs(tan) - 0 < ERRORTOLERANCE); 
    }
    SECTION("myTan - 0")
    {
        tan = myTan(num);
        
        REQUIRE(fabs(tan) - 0 < ERRORTOLERANCE); 
    }
    SECTION("myCosD - 0")
    {
        cos = myCosD(num);
        
        REQUIRE(fabs(cos) - 1 < ERRORTOLERANCE); 
    }
    SECTION("myCos - 0")
    {
        cos = myCos(num);
        
        REQUIRE(fabs(cos) - 1 < ERRORTOLERANCE); 
    }
    SECTION("mySin - 0")
    {
        sin = mySin(num);
        
        REQUIRE(fabs(sin) - 0 < ERRORTOLERANCE); 
    }
    SECTION("mySinD - 0")
    {
        sin = mySinD(num);
        
        REQUIRE(fabs(sin) - 0 < ERRORTOLERANCE); 
    }
}

TEST_CASE("trig - testing PI or 180")
{
    double sin;
    double cos;
    double tan;
    SECTION("myTanD - 180")
    {
        tan = myTanD(180);
        
        REQUIRE(fabs(tan - 0) < ERRORTOLERANCE); 
    }  
    SECTION("myTan - PI")
    {
        tan = myTan(PI);
        
        REQUIRE(fabs(tan - 0) < ERRORTOLERANCE); 
    }   
    SECTION("myCos - PI")
    {
        cos = myCos(PI);
        
        REQUIRE(fabs(cos + 1) < ERRORTOLERANCE); 
    }
    SECTION("myCosD - PI")
    {
        cos = myCosD(180);
        
        REQUIRE(fabs(cos + 1) < ERRORTOLERANCE); 
    }
    SECTION("mySin - PI")
    {
        sin = mySin(PI);
        
        REQUIRE(fabs(sin - 0) < ERRORTOLERANCE); 
    }
    SECTION("mySinD - 180")
    {
        sin = mySinD(180);
        
        REQUIRE(fabs(sin) - 0 < ERRORTOLERANCE); 
    }
}

TEST_CASE("trig - testing PI/4 or 45")
{ 
    double sin;
    double cos;
    double tan;
    SECTION("myTanD - 45")
    {
        tan = myTanD(45);
        
        REQUIRE(fabs(tan - 1) < ERRORTOLERANCE); 
    }   
    SECTION("myTan - PI/4")
    {
        tan = myTan(PI/4);
        
        REQUIRE(fabs(tan - 1) < ERRORTOLERANCE); 
    }   
    SECTION("myCos - PI/4")
    {
        cos = myCos(PI/4);
        
        REQUIRE(fabs(cos) - 0.7071067812 < ERRORTOLERANCE); 
    }
    SECTION("myCos - PI/4")
    {
        cos = myCos(PI/4);
        
        REQUIRE(fabs(cos) - 0.7071067812 < ERRORTOLERANCE); 
    }
    SECTION("mySin - PI/4")
    {
        sin = mySin(PI/4);
        
        REQUIRE(fabs(sin) - 0.7071067812 < ERRORTOLERANCE); 
    }
    SECTION("mySinD - 45")
    {
        sin = mySinD(45);
        
        REQUIRE(fabs(sin) - 0.7071067812 < ERRORTOLERANCE); 
    }
}

//factorial testing
TEST_CASE("factorial - the number 5") 
{
    double sum; 
    
    sum = factorial(5);
    
    REQUIRE(sum == 120);
}

TEST_CASE("factorial - the number 3") 
{
    double sum; 
    
    sum = factorial(3);
    
    REQUIRE(sum == 6);
}

TEST_CASE("factorial - the number 10") 
{
    double sum; 
    
    sum = factorial(10);
    
    REQUIRE(sum == 3628800);
}


//myLog testing
TEST_CASE("myLog - testing for 3 base 28")
{
    double base = 3;
    double x = 28;
    double logNum; 
    
    logNum = myLog(x, base);
    
    REQUIRE(Approx(logNum) == 3.033103256); 
}

TEST_CASE("myLog - testing for 100 base 10")
{
    double base = 10;
    double x = 1000;
    double logNum; 
    
    logNum = myLog(x, base);
    
    REQUIRE(Approx(logNum) == 3.0); 
}

TEST_CASE("myLog - testing for 2 base 4")
{
    double base = 2;
    double x = 4;
    double logNum; 
    
    logNum = myLog(x, base);
    
    REQUIRE(Approx(logNum) == 2.0); 
}
//roots testing - Cbrt and Sqrt
TEST_CASE("roots - testing for 0")
{
    double num = 0; 
    SECTION("mySqrt")
    {    
        double sqrt;
        sqrt = mySqrt(num);
        
        REQUIRE(Approx(sqrt) == 0);
    }
    SECTION("myCbrt")
    {
        double cbrt;
        cbrt = myCbrt(num);
        
        REQUIRE(Approx(cbrt) == 0);
    }
}

TEST_CASE("roots - testing for 64")
{
    double num = 64;
    SECTION("mySqrt")
    {    
        double sqrt;
        sqrt = mySqrt(num);
        
        REQUIRE(Approx(sqrt) == 8);
    }
    SECTION("myCbrt")
    {
        double cbrt;
        cbrt = myCbrt(num);
        
        REQUIRE(Approx(cbrt) == 4);
    }
}

TEST_CASE("roots - testing for 9.5")
{
    double num = 9.5; 
    SECTION("mySqrt")
    {
        double sqrt;
        sqrt = mySqrt(num);
        
        REQUIRE(Approx(sqrt) == 3.082207001);
    }
    SECTION("myCbrt")
    {
        double cbrt;
        cbrt = myCbrt(num);
        
        REQUIRE(Approx(cbrt) == 2.117911792);
    }
}

TEST_CASE("roots - testing for 1002.3242")
{
    double num = 1002.3242; 
    SECTION("mySqrt")
    {
        double sqrt;
        sqrt = mySqrt(num);
        
        REQUIRE(Approx(sqrt) == 31.6595041);
    }
    SECTION("myCbrt")
    {
        double cbrt;
        cbrt = myCbrt(num);
        
        REQUIRE(Approx(cbrt) == 10.00774134);
    }
}
//copy array testing
TEST_CASE("copyArray - testing for 7 digits")
{
    int size = 10;
    double destin[11];
    double source[11] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int i;
    
    copyArray(destin, source, size);
    
    for(i = 0; i < size; i++) 
    {
        REQUIRE(destin[i] == source[i]);
    }
}

TEST_CASE("copyArray - testing for 10 digits with varying decimal places")
{
    int size = 11;
    double destin[11];
    double source[11] = {1.3, 9.8, 14.3, 1034.2, 123.21, 32.12, 43.2, 5321.23, 53.23, 12.3432};
    int i;
    
    copyArray(destin, source, size);
    
    for(i = 0; i < size; i++) 
    {
        REQUIRE(destin[i] == source[i]);
    }
}

TEST_CASE("copyArray - testing for a lot of digits with varying decimal places")
{
    int size = 25;
    double destin[25];
    double source[25] = {1.3, 9.8, 14.3, 1034.2, 123.21, 32.12, 43.2, 5321.23, 53.23, 12.3432, 10.3, 13.2, 34.2, 9.77, 368.86, 89.9, 6.87, 800.79, 9.765, 0.89, 38.88, 91.847, 0.459, 79.1, 4.8};
    int i;
    
    copyArray(destin, source, size);
    
    for(i = 0; i < size; i++) 
    {
        REQUIRE(destin[i] == source[i]);
    }
}

//initialArray testing
TEST_CASE("initialArray - testing the number 0") 
{
    double init = 0;
    double initArray[10];
    int size = 10;
    int i;
    
    initialArray(initArray, size, init);
    
    for(i = 0; i < size; i++)
    {
        REQUIRE(initArray[i] == 0);
    }
}

TEST_CASE("initialArray - testing the number 20.1234124") 
{
    double init = 20.1234124;
    double initArray[13];
    int size = 13;
    int i;
    
    initialArray(initArray, size, init);
    
    for(i = 0; i < size; i++)
    {
        REQUIRE(initArray[i] == 20.1234124);
    }
}

TEST_CASE("initialArray - testing the number 137988933462633019958147167898950857823263644146032701234630589796572875326467929141888025447325738718790088384527056259294005146040569787648084805116623574907705224770849675156451363631778526570436839456924624275061489490634430626794471205950071552654553588550336512.0") 
{
    double init = 137988933462633019958147167898950857823263644146032701234630589796572875326467929141888025447325738718790088384527056259294005146040569787648084805116623574907705224770849675156451363631778526570436839456924624275061489490634430626794471205950071552654553588550336512.0;
    double initArray[21];
    int size = 21;
    int i;
    
    initialArray(initArray, size, init);
    
    for(i = 0; i < size; i++)
    {
        REQUIRE(initArray[i] == 137988933462633019958147167898950857823263644146032701234630589796572875326467929141888025447325738718790088384527056259294005146040569787648084805116623574907705224770849675156451363631778526570436839456924624275061489490634430626794471205950071552654553588550336512.0);
    }
}

//sumArray testing
TEST_CASE("sumArray - testing for adding up 7 digits")
{
    int size = 10;
    double sumArr[11] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int i;
    double sum = 0; 
    
    sum += sumArray(sumArr, size);
    
    REQUIRE(sum == 28);

}

TEST_CASE("sumArray - testing for adding up numbers with varying lengths and decimals")
{
    int size = 11;
    double sumArr[11] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3};
    int i;
    double sum = 0; 
    
    sum += sumArray(sumArr, size);
    
    REQUIRE(sum == Approx(129.4051));
}

TEST_CASE("sumArray - testing adding up the same number")
{
    int size = 11;
    double sumArr[11] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    int i;
    double sum = 0; 
    
    sum += sumArray(sumArr, size);
    
    REQUIRE(sum == Approx(8.0));
}


//averageArray testing
TEST_CASE("avgArray - testing for 11 digits with varying decimal counts")
{
    int size = 11;
    double avgArr[11] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21};
    int i;
    double avg; 
    
    avg = averageArray(avgArr, size);
    
    REQUIRE(avg == Approx(12.27682727));

}

TEST_CASE("avgArray - testing for 7 digits")
{
    int size = 7;
    double avgArr[11] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int i;
    double avg; 
    
    avg = averageArray(avgArr, size);
    
    REQUIRE(avg == 4);

}

TEST_CASE("avgArray - testing the same digit")
{
    int size = 7;
    double avgArr[11] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    int i;
    double avg; 
    
    avg = averageArray(avgArr, size);
    
    REQUIRE(avg == 1.0);

}

//minLocation testing
TEST_CASE("minLocation - testing for 7 digits")
{
    int size = 7;
    double minArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    int i;
    double min; 
    
    min = minLocation(minArr, size);
    
    REQUIRE(min == 4);
}

TEST_CASE("minLocation - testing for 11 digits with varying decimal counts")
{
    int size = 11;
    double minArr[11] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21};
    int i;
    double min; 
    
    min = minLocation(minArr, size);
    
    REQUIRE(min == 9);
}

//minValue testing 
TEST_CASE("minValue - testing for 7 digits")
{
    int size = 7;
    double minArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    int i;
    double min; 
    
    min = minValue(minArr, size);
    
    REQUIRE(min == 1.0);
}

TEST_CASE("minValue - testing for 11 digits with different amounts of decimal places") 
{
    int size = 11;
    double minArr[11] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21};
    int i;
    double min; 
    
    min = minValue(minArr, size);
    
    REQUIRE(min == 0.12);
}

//maxLocation testing
TEST_CASE("maxLocation - testing for 7 digits")
{
    int size = 7;
    double maxArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    int i;
    double max; 
    
    max = maxLocation(maxArr, size);
    
    REQUIRE(max == 0);
}

TEST_CASE("maxLocation - testing for 11 digits with different numbers of decimals")
{
    int size = 11;
    double maxArr[11] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21};
    int i;
    double max; 
    
    max = maxLocation(maxArr, size);
    
    REQUIRE(max == 6);
}

//maxValue testing
TEST_CASE("maxValue - testing for 15 digits with different numbers of decimals")
{
    int size = 21;
    double maxArr[21] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21, 93.1342, 1234.232, 34912.432, 90341.34, 103002.2, 1.0, 2.1, 3.2, 6.4};
    int i;
    double max; 
    
    max = maxValue(maxArr, size);
    
    REQUIRE(max == 103002.2);
}

TEST_CASE("maxValue - testing for 15 digits with different numbers of decimals and negatives")
{
    int size = 21;
    double maxArr[32] = {-6.0, 2.5321, 9.243, 4.32, -10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21, 93.1342, 1234.232, 34912.432, 90341.34, -103002.2, 1.0, 2.1, 3.2, 6.4};
    int i;
    double max; 
    
    max = maxValue(maxArr, size);
    
    REQUIRE(max == 90341.34);
}

//countIf testing 
TEST_CASE("countIf - testing for 1 number")
{
    int size = 7;
    double target = 2.0;
    double countArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    int i;
    int count; 
    
    count = countIf(countArr, size, target);
    
    REQUIRE(count == 1);
}

TEST_CASE("countIf - testing for multiple number")
{
    int size = 10;
    double target = 2.0;
    double countArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 2.0, 5.0, 6.0, 2.0, 2.0};
    int i;
    int count; 
    
    count = countIf(countArr, size, target);
    
    REQUIRE(count == 4);
}

//sortArray testing
TEST_CASE("sorts - size 10 array no decimals")
{
    double data[10] = {997, 995, 34, 56, 78, 12, -10, 25, -98, -100};
    
    SECTION("ascending order")
    {
        mySort(data, 10, "ASC");
    
        REQUIRE(data[0] == -100);
        REQUIRE(data[1] == -98);
        REQUIRE(data[8] == 995);
        REQUIRE(data[9] == 997);
    }
        SECTION("descending order")
    {
        mySort(data, 10, "DSC");
    
        REQUIRE(data[9] == -100);
        REQUIRE(data[8] == -98);
        REQUIRE(data[1] == 995);
        REQUIRE(data[0] == 997);
    }
}

TEST_CASE("sorts - size 11 array with decimals")
{
    double data[11] = {991.587, 995.3421, 34.2, 56.54, 78.92, 12.12, -10.0, 25, -98.1, -100.8, -101.2};
    
    SECTION("ascending order")
    {
        mySort(data, 11, "ASC");
    
        REQUIRE(data[0] == -101.2);
        REQUIRE(data[1] == -100.8);
        REQUIRE(data[9] == 991.587);
        REQUIRE(data[10] == 995.3421);
    }
        SECTION("descending order")
    {
        mySort(data, 11, "DSC");
    
        REQUIRE(data[10] == -101.2);
        REQUIRE(data[9] == -100.8);
        REQUIRE(data[1] == 991.587);
        REQUIRE(data[0] == 995.3421);
    }
}

//searches testing
TEST_CASE("searches - size 10 array no decimals")
{
    double data[10] = {997, 995, 34, 56, 78, 12, -10, 25, -98, -100};
    
    SECTION("binarySearch - size 10")
    {
        mySort(data, 10, "ASC");
        int search = binarySearch(data, 10, 997);
        
        REQUIRE(search == 9);
    }
    SECTION("linearSearch - size 10")
    {
        int search = linearSearch(data, 10, 997);
    
        REQUIRE(search == 0);
    }
}

TEST_CASE("searches - size 11 array with decimals")
{
    double data[11] = {991.587, 995.3421, 34.2, 56.54, 78.92, 12.12, -10.0, 25, -98.1, -100.8, -101.2};
    
    SECTION("binarySearch - size 11")
    {
        mySort(data, 11, "ASC");
        int search = binarySearch(data, 11, -100.8);
        
        REQUIRE(search == 1);
    }
       SECTION("binarySearch - checking for value not in array")
    {
        mySort(data, 11, "ASC");
        int search = binarySearch(data, 11, 10000);
        
        REQUIRE(search == -1);
    }
    SECTION("linearSearch - size 11")
    {
        int search = linearSearch(data, 11, 34.2);
        
        REQUIRE(search == 2);
    }
        SECTION("linearSearch - checking for value not in array")
    {
        int search = linearSearch(data, 11, 10000);
        
        REQUIRE(search == -1);
    }
}

