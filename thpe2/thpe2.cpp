/** ********************************************************************
* @file
************************************************************************/
#include "thpe2.h"
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the tangent value of the value given in degree form
 *
 *  @param[in] degrees The value to be given the tangent of
 *
 *  @returns A double result being the tangent of the value
 *
 *  @par Example
 *  @verbatim
    double tan

    tan = myTanD(180); // result would be 0.0

    tan = myTanD(0); // result would be 0.0

    tan = myTanD(45); // result would be 1.0

    @endverbatim
 ************************************************************************/
     
double myTanD(double degrees)
{
    double sum;
    double radian;
    //converting radians to degrees
    radian = degrees *  (PI/180);
    
    //just uses sin/cos to get tan
    sum = (mySin(radian)/myCos(radian));
    
    return sum;
}
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the tangent value of the value given in radian form
 *
 *  @param[in] radian The value to be given the tangent of
 *
 *  @returns A double result being the tangent of the value
 *
 *  @par Example
 *  @verbatim
    double tan

    tan = myTan(180); // result would be 0.0

    tan = myTan(0); // result would be 0.0

    tan = myTan(45); // result would be 1.0

    @endverbatim
 ************************************************************************/
double myTan(double radian)
{
    double sum;
    //just uses sin/cos to get tan
    sum = (mySin(radian)/myCos(radian));
    
    return sum;
}
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the cosine value of the value given in degree form
 *
 *  @param[in] degree the value to be given the cosine of
 *
 *  @returns A double result being the cosine of the value
 *
 *  @par Example
 *  @verbatim
    double cos

    cos = myCosD(180); // result would be -1.0
    
    cos = myCosD(0); // result would be 1.0

    cos = myCosD(45); // result would be squareroot(2)/2

    @endverbatim
 ************************************************************************/
double myCosD(double degree)
{
    int i;
    double sum = 0; 
    double radian;
    //converting radians to degrees
    radian = degree *  (PI/180);
    //pretty much just using the sigma notation of the fos function and adding it to the amount of TERMS
    for(i = 0; i <= TERMS; i++)
    {
        sum += (pow(-1, i) * (pow(radian, (2*i)))) / (factorial((2*i)));
    }
    return sum;
}
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the cosine value of the value given in radian form
 *
 *  @param[in] radian The value to be given the cosine of
 *
 *  @returns A double result being the cosine of the value
 *
 *  @par Example
 *  @verbatim
    double cos

    cos = myCos(pi); // result would be -1.0
    
    cos = myCos(0); // result would be 1.0

    cos = myCos(pi/4); // result would be squareroot(2)/2

    @endverbatim
 ************************************************************************/
double myCos(double radian)
{
    int i;
    double sum = 0; 
    //pretty much just using the sigma notation of the cos function and adding it to the amount of TERMS
    for(i = 0; i <= TERMS; i++)
    {
        sum += (pow(-1, i) * (pow(radian, (2*i)))) / (factorial((2*i)));
    }
    return sum;
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the sine value of the value given in radian form
 *
 *  @param[in] radian The value to be given the sine of
 *
 *  @returns A double result being the sine of the value
 *
 *  @par Example
 *  @verbatim
    double sin

    sin = mySin(pi); // result would be 0
    
    sin = mySin(0); // result would be 0

    sin = mySin(pi/4); // result would be squareroot(2)/2

    @endverbatim
 ************************************************************************/
//mySin function takes a radian and calculates the sin 
double mySin(double radian)
{
    int i;
    double sum = 0; 
    //pretty much just using the sigma notation of the sin function and adding it to the amount of TERMS
    for(i = 0; i <= TERMS; i++)
    {
        sum += (pow(-1, i) * (pow(radian, (2*i) + 1))) / (factorial((2*i) + 1));
    }
    return sum;
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the sine value of the value given in degree form
 *
 *  @param[in] degree The value to be given the sine of
 *
 *  @returns A double result being the sine of the value
 *
 *  @par Example
 *  @verbatim
    double sin

    sin = mySinD(180); // result would be 0
    
    sin = mySinD(0); // result would be 0

    sin = mySinD(45); // result would be squareroot(2)/2

    @endverbatim
 ************************************************************************/
//mySin function takes a radian and calculates the sin 
double mySinD(double degree)
{
    return mySin(convert(degree)); 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Finds the factorial value of the value given in integer form
 *
 *  @param[in] num The value that we want to find the factorial of 
 *
 *  @returns A double result being the cosine of the value
 *
 *  @par Example
 *  @verbatim
    double num

    num = factorial(3); // result would be 6
    
    num = factorial(4); // result would be 24

    num = factorial(2); // result would be 2

    @endverbatim
 ************************************************************************/
//factorial finds the factorial of a number
double factorial(double num)
{
    int i; 
    double sum = 1; 
    //if the number is less than 0 just return 1;
    if(num < 0)
    {
        return 1; 
    }
    //multiplies all of the previous numbers including the number to get the factorial
    for(i = 1; i <= num; i++)
    {
        sum *= i;
    }
    return sum; 
}
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Copies one array into another
 *
 *  @param[in] destinArr[] the array that we want to copy into 
 *  @param[in] sourceArr[] that array that we are copying from
 *  @param[in] size the size of the arrays 
 *
 *  @returns nothing its a void function
 *
 *  @par Example
 *  @verbatim

    int size = 10;
    double destin[11];
    double source[11] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    
    copyArray(destin, source, size); //result would be destin[11] == {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0}
    
    @endverbatim
 ************************************************************************/
//copies the array to another blank array
void copyArray(double destinArr[], double sourceArr[], int size)       
{
    int i;
    
    //for loop to set all of the values in the array to the same values as the source
    for(i = 0; i < size; i++) 
    {
        destinArr[i] = sourceArr[i]; 
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  initialArray sets all of the values of the array to the given value 
 *
 *  @param[in] initArr[] the array we are putting all of the values into 
 *  @param[in] initVal[] the value we are setting the array to 
 *  @param[in] size the size of the arrays 
 *
 *  @returns nothing its a void function
 *
 *  @par Example
 *  @verbatim

    int size = 10;
    double initVal = 1.0;
    double arr[11];

    initialArray(arr, size, initVal); //result would be arr[11] == {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
    
    @endverbatim
 ************************************************************************/
//initialArray sets all of the values of the array to the given value 
void initialArray(double initArr[], int size, double initVal)
{
    int i;
    
    //for loop that goes through the entire array and sets it to the given value
    for(i = 0; i < size; i++) 
    {
        initArr[i] = initVal; 
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  sumArray adds up everything in the array
 *
 *  @param[in] sumArray[] the array we are summing the values 
 *  @param[in] size the size of the arrays 
 *
 *  @returns double of the sum that we get from the array 
 *
 *  @par Example
 *  @verbatim

    int size = 10;
    double arr[11] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};

    sumArray(arr, size); //result would be 28.0
    
    @endverbatim
 ************************************************************************/
//sumArray adds up everything in the array
double sumArray(double sumArray[], int size)
{
    int i;
    double sum = 0; 
    
    //for loop that adds up all of the values in the array 
    for(i = 0; i < size; i++)
    {
        sum += sumArray[i];
    }
    //return the sum
    return sum; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  averageArray function finds the average of the entire array based off of its size
 *
 *  @param[in] avgArray[] the array we are averaging from 
 *  @param[in] size the size of the arrays 
 *
 *  @returns double of the average that we get from the array 
 *
 *  @par Example
 *  @verbatim

    int size = 11;
    double avgArr[11] = {6.3, 2.5321, 9.243, 4.32, 10.24, 12.34, 73.13, 11.3, 2.31, 0.12, 3.21};
    double avg; 
    
    avg = averageArray(avgArr, size); // avg would be 12.27682727
    
    @endverbatim
 ************************************************************************/
//averageArray function finds the average of the entire array based off of its size
double averageArray(double avgArray[], int size)
{
    //declare the average and the sum as doubles
    double avg;
    double sum;
    
    //set the sum to use sumArray function to get the sum of the array
    sum = sumArray(avgArray, size);
    
    //divide the sum by the size and put into avg
    avg = sum/size;
    
    //return average
    return avg; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  minLocation function that finds the minimum value in the array and returns its index
 *
 *  @param[in] minArray[] the array we getting the min index of  
 *  @param[in] size the size of the arrays 
 *
 *  @returns the minimum index that we get from the array 
 *
 *  @par Example
 *  @verbatim

    int size = 7;
    double minArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    double min; 
    
    min = minLocation(minArr, size); //min would be 4
    
    @endverbatim
 ************************************************************************/
//minLocation function that finds the minimum value in the array and returns its index
int minLocation(double minArray[], int size)
{
    //declare variables, min should be set to the first value of the array 
    int i;
    double min = minArray[0]; 
    int minLoc; 
    
    //for loop that checks whether the value in the array is less than the first value in the array, if it is it sets it to min and sets minLoc to its index
    for(i = 0; i < size - 1; i++)
    {
        if(min > minArray[i])
        {
            min = minArray[i];
            minLoc = i; 
        }
    }
    //return the index of the min
    return minLoc; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  minValue function that finds the minimum value in the array and returns it
 *
 *  @param[in] minArray[] the array we getting the min of  
 *  @param[in] size the size of the arrays 
 *
 *  @returns the minimum that we get from the array 
 *
 *  @par Example
 *  @verbatim

    int size = 7;
    double minArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    double min; 
    
    min = minValue(minArr, size); //min would be 1.0
    
    @endverbatim
 ************************************************************************/
//minValue function that finds the minimum value in the array and returns it
double minValue(double minArray[], int size)
{
    //declare variables, min should be set to the first value of the array 
    int i;
    double min = minArray[0]; 
    
    //for loop that checks whether the value in the array is less than the first value in the array, if it is it sets it to min
    for(i = 0; i < size - 1; i++)
    {
        if(min > minArray[i])
        {
            min = minArray[i];
        }
    }
    //return the minimum value
    return min; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  maxLocation function that finds the maximum value in the array and returns its index
 *
 *  @param[in] maxArray[] the array we getting the max index of  
 *  @param[in] size the size of the arrays 
 *
 *  @returns the maximum index that we get from the array 
 *
 *  @par Example
 *  @verbatim

    int size = 7;
    double maxArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    double max; 
    
    max = maxLocation(maxArr, size); //min would be 0
    
    @endverbatim
 ************************************************************************/
//maxLocation function that finds the maximum value in the array and returns its index
int maxLocation(double maxArray[], int size)
{
    //declare variables, max should be set to the first value of the array 
    int i;
    double max = maxArray[0]; 
    int maxLoc; 
    
    //for loop that checks whether the value in the array is greater than the first value in the array, if it is it sets it to max and also sets that index to maxLoc 
    for(i = 0; i < size - 1; i++)
    {
        if(max < maxArray[i])
        {
            max = maxArray[i];
            maxLoc = i; 
        }
    }
    //return the index of the max
    return maxLoc;  
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  maxValue function that finds the maximum value in the array and returns it
 *
 *  @param[in] maxArray[] the array we getting the max of  
 *  @param[in] size the size of the arrays 
 *
 *  @returns the maximum that we get from the array 
 *
 *  @par Example
 *  @verbatim

    int size = 7;
    double maxArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 5.0, 6.0};
    double max; 
    
    max = maxValue(minArr, size); //max would be 7.0
    
    @endverbatim
 ************************************************************************/
//maxValue function that finds the maximum value in the array and returns it
double maxValue(double maxArray[], int size)
{
    //declare variables, max should be set to the first value of the array 
    int i;
    double max = maxArray[0]; 
    
    //for loop that checks whether the value in the array is greater than the first value in the array, if it is it sets it to max
    for(i = 0; i < size - 1; i++)
    {
        if(max < maxArray[i])
        {
            max = maxArray[i];
        }
    }
    //return the max
    return max;  
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  countIf function that counts how many of one item there are in an array
 *
 *  @param[in] countArray[] the array we are going through  
 *  @param[in] size the size of the arrays 
 *  @param[in] item the item that we want to count
 *
 *  @returns the amount of the item that we find in the array
 *
 *  @par Example
 *  @verbatim

    int size = 10;
    double target = 2.0;
    double countArr[11] = {7.0, 2.0, 3.0, 4.0, 1.0, 2.0, 5.0, 6.0, 2.0, 2.0};
    int count; 
    
    count = countIf(countArr, size, target); // count would be 4
    
    @endverbatim
 ************************************************************************/
//countIf function that counts how many of one item there are in an array
int countIf(double countArray[], int size, double item)
{
    int i;
    int count = 0; 
    
    //for loop that literally just checks whether the item is in the array and then increments count by one if it finds it
    for(i = 0; i < size; i++)
    {
        if(countArray[i] == item)
        {
            count++; 
        }
    }
    return count; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 * sorting function to sort any array in a certain order
 *
 *  @param[in] sortArray[] the array we are going through  
 *  @param[in] size the size of the arrays 
 *  @param[in] order the way that we want the array sorted in
 *
 *  @returns nothing its a void function
 *
 *  @par Example
 *  @verbatim

    double data[10] = {997, 995, 34, 56, 78, 12, -10, 25, -98, -100};
    
        mySort(data, 10, "ASC");
    
        /What the array looks like after in ascending order
        data[0] == -100;
        data[1] == -98;
        data[8] == 995;
        data[9] == 997;
        
        mySort(data, 10, "DSC");
    
        //What the array looks like after in decending order
        data[9] == -100;
        data[8] == -98;
        data[1] == 995;
        data[0] == 997;
    
    @endverbatim
 ************************************************************************/
//sorting function, I decided to go with improved bubbleSort
void mySort(double sortArray[], int size, string order)
{
    double tempSort;
    int i;
    int j;
    bool swapStatus = true; 
    
    for(i = 0; i < size - 1 && swapStatus == true; i++)
    {
        swapStatus = false; 
        for(j = 0; j < size - 1 - i; j++)
        {
            if(order == "ASC")
            {
                if(sortArray[j] > sortArray[j+1])
                {
                    tempSort = sortArray[j];
                    sortArray[j] = sortArray[j+1];
                    sortArray[j+1] = tempSort;
                    swapStatus = true;
                }
            }
            if(order == "DSC")
            {
                if(sortArray[j] < sortArray[j+1])
                {
                    tempSort = sortArray[j];
                    sortArray[j] = sortArray[j+1];
                    sortArray[j+1] = tempSort;
                    swapStatus = true;
                }
            }
        }
    }
}

//search functions

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  searches for a value and returns its index through the binarySearch Method so only works if the array is sorted    
 *
 *  @param[in] searchArray[] the array we are going through  
 *  @param[in] size the size of the arrays 
 *  @param[in] searchVal the value that we are searching for 
 *
 *  @returns the index of the value that we are looing for 
 *
 *  @par Example
 *  @verbatim

    double data[11] = {991.587, 995.3421, 34.2, 56.54, 78.92, 12.12, -10.0, 25, -98.1, -100.8, -101.2};
    
        mySort(data, 11, "ASC");
        int search = binarySearch(data, 11, -100.8); //result is 1
    
    @endverbatim
 ************************************************************************/
//binarySearch function 
int binarySearch(double searchArray[], int size, double searchVal)
{
    //declare left as 0 and right as the length of the array, as well as a middle variable
    int left = 0;
    int right = size - 1;
    int mid;
    
    //while loop that goes as long as left is less than or equal to right so that it checks the whole length of the array
    while(left <= right)
    {
        //define the middle variable as the length of the array plus the current minimum value to approximate the middle value
        mid = (left + right) / 2;
        //checks whether the middle index of the array equals the name and returns it if it does
        //other wise if the value is greater than the middle index value, you set left to the middle + 1 
        //else set the right value to the middle - 1, because the value is less than the right one. 
        if(searchArray[mid] == searchVal)
        {
            return mid;
        }
        if(searchArray[mid] < searchVal)
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;
        }
    }
    //return -1 if you can't find anything
    return -1; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  searches for a value and returns its index through the linearSearch Method so can work if the array isn't sorted
 *
 *  @param[in] searchArray[] the array we are going through  
 *  @param[in] size the size of the arrays 
 *  @param[in] searchVal the value that we are searching for 
 *
 *  @returns the index of the value that we are looing for 
 *
 *  @par Example
 *  @verbatim
 
        double data[11] = {991.587, 995.3421, 34.2, 56.54, 78.92, 12.12, -10.0, 25, -98.1, -100.8, -101.2};
        int search = linearSearch(data, 11, 34.2);// returns 2
    
    @endverbatim
 ************************************************************************/
//linearSearch function
int linearSearch(double searchArray[], int size, double searchVal)
{
    //declare variables
    int i; 
    //for loop that iterates through the array and checks whether any of the values in it are equal to the searchVal, then returns that index
    for(i = 0; i < size; i++)
    {
        if(searchArray[i] == searchVal)
        {
            return i;
        }
    }
    //if the for loop can't find the index, the function returns -1 
    return -1;
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  gets the square root of a number through newtons method
 *
 *  @param[in] num the number that we are getting the squareroot of
 *
 *  @returns the square root of the number 
 *
 *  @par Example
 *  @verbatim
 
    double num = 64;  
    double sqrt;
    sqrt = mySqrt(num); //sqrt would be 8
    
    @endverbatim
 ************************************************************************/
double mySqrt(double num)
{
    //declare variables, set low to 0 and ab to 1 
    double low = 0;
    double high;
    double mid ; 
    double ab = 1; 

    //if the number given is 0, return 0
    if(num == 0)
    {
        return 0;
    }
    //if the number is greater than or equal to 1 set high to num, other wise set high to 1 
    if(num >= 1)
    {
        high = num; 
    }
    else
    {
        high = 1; 
    }
    //while loop that goes as long as the calculated error is less than the errorvalue 
    while(ab > ERRORVALUE)
    {
        //find the midpoint of the two numbers and if that number equared is greater than the num, set high to mid, otherwise set low to mid
        mid = (high + low)/2;
        if(pow(mid, 2) > num)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        ab = abs(pow(mid, 2) - num);
    }
    //return the mid
    return mid; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  gets the cube root of a number through newtons method
 *
 *  @param[in] num the number that we are getting the cuberoot of
 *
 *  @returns the cube root of the number 
 *
 *  @par Example
 *  @verbatim
 
    double cbrt;
    cbrt = myCbrt(num); //cbrt would be 4
    
    @endverbatim
 ************************************************************************/
double myCbrt(double num)
{
    //declare variables, set low to 0 and ab to 1 
    double low = 0;
    double high;
    double mid ; 
    double ab = 1; 

    //if the number given is 0, return 0
    if(num == 0)
    {
        return 0;
    }
    //if the number is greater than or equal to 1 set high to num, other wise set high to 1 
    if(num >= 1)
    {
        high = num; 
    }
    else
    {
        high = 1; 
    }
    //while loop that goes as long as the calculated error is less than the errorvalue 
    while(ab > ERRORVALUE)
    {
        //find the midpoint of the two numbers and if that number equared is greater than the num, set high to mid, otherwise set low to mid
        mid = (high + low)/2;
        if(pow(mid, 3) > num)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        ab = abs(pow(mid, 3) - num);
    }
    //return the mid
    return mid; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  gets the log of a number through newtons method
 *
 *  @param[in] base the base of the log
 *  @param[in] x the argument of the log
 *  @returns the log of the number 
 *
 *  @par Example
 *  @verbatim
 
    double base = 2;
    double x = 4;
    double logNum; 
    
    logNum = myLog(x, base); //logNum is 2
    
    @endverbatim
 ************************************************************************/
double myLog(double x, int base)
{
    //declare variables, set low to 0 and ab to 1 and high
    double low = 0;
    double high = 1;
    double mid; 
    double ab = 1; 
    while(pow(base, high) <= x)
    {
        high++; 
    }
    low = high - 1;
    //while loop that goes as long as the calculated error is less than the errorvalue 
    //return the mid
    while(ab > ERRORVALUE)
    {
        //find the midpoint of the two numbers and if that number equared is greater than the num, set high to mid, otherwise set low to mid
        mid = (high + low)/2;
        if(pow(base, mid) > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        ab = abs(pow(base, mid) - x);
    }
    //return the mid
    return mid; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  //converts degrees to radians
 *
 *  @param[in] degrees the degrees to convert
 *
 *  @returns the radians from the degrees
 *
 *  @par Example
 *  @verbatim
 
    convert(45) //result would be PI/4
    convert(180) //result would be PI
    
    @endverbatim
 ************************************************************************/
//converts degrees to radians
double convert(double degrees)
{
    double radians;
    
    radians = degrees * PI/180;
    
    return radians;
}