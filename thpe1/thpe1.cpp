/** ********************************************************************
* @file
************************************************************************/
#include "thpe1.h"

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the type of credit card passed in through a string using different parameters that define different credit cards, 
 * and returns the type of credit card. If its not a registered card, will return "Unknown".
 *
 * @par
 * The following values are computed
 * isDiscover(cc) == true          "Discover"<br/>
 * isAmericanExpress(cc) == true   "American Express"<br/>
 * isVisa(cc) == true              "Visa"<br/>
 * isMaster(cc) == true            "Mastercard"<br/>
 *
 *  @param[in] cc The credit card string to be checked.
 *
 *  @returns A string being the credit card type.
 *
 *  @par Example
 *  @verbatim
    string result;
    string cc = "6229267636070782";

    result = getCCType( cc ); // result would be "Discover";

    cc = "4794630503276178";
    result = getCCType( cc ); // result would be "Visa";

    cc = "5023589379548211";
    result = getCCType( cc ); // result would be "Mastercard";
    
    cc = "343669144240775";
    result = getCCType( cc ); // result would be "American Express";

    @endverbatim
 ************************************************************************/
//main getCCType function
string getCCType(string cc)
{
    //if statements using the helper functions 
    if(isDiscover(cc) == true)
    {
        return "Discover";
    }
    if(isAmericanExpress(cc) == true)
    {
        return "American Express";
    }
    if(isVisa(cc) == true)
    {
        return "Visa";
    }
    if(isMaster(cc) == true) 
    {
        return "Mastercard";
    }
    return "Unknown";
}

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the type of credit card passed in through a string using different parameters 
 * to check if it is an American Express card.
 *
 * @par
 * Determines if its american express if its 16 digits long and starts with 34 or 37 
 * if the card meets the criteria, returns a boolean true, otherwise returns false.
 * 
 *
 * @param[in] str The credit card string to be checked.
 *
 * @returns A boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string str = "343669144240775";

   result = isAmericanExpress( str ); // result would be true;

   str = "373669144240775";
   result = isAmericanExpress( str ); // result would be true;

   @endverbatim
 ************************************************************************/
//Checks the card against the American Express Criteria
bool isAmericanExpress(string str)
{
    int len = str.length();
    bool americanType = false; 
    //Checks if the length is 15 and that it has 34 or 37 at the beginning
    if(len == 15)
    {
        if(str.at(0) == '3' && (str.at(1) == '4' || str.at(1) == '7'))
        {
             americanType = true;
        }
    }
    return americanType; 
}

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the type of credit card passed in through a string using different parameters 
 * to check if it is a Visa card.
 *
 * @par
 * Determines if its a visa card if its 13 or 16 digits long that starts with 4 
 * if the card meets the criteria, returns a boolean true, otherwise returns false.
 * 
 *
 * @param[in] str The credit card string to be checked.
 *
 * @returns a boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string cc = "4794630503276178";

   result = isVisa( cc ); // result would be true;

   cc = "4794630503276";
   result = isVisa( cc ); // result would be true;

   @endverbatim
 ************************************************************************/
//checks agaist the visa criteria
bool isVisa(string str)
{
    int len = str.length();
    bool visaType = false; 
    
    //checks the length of the card is 13 or 16 and if it starts with 4
    if(len == 13 || len == 16)
    {
        if(str.at(0) == '4')
        {
             visaType = true;
        }
    }
    return visaType; 
}

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the type of credit card passed in through a string using different parameters 
 * to check if it is a Discover card
 *
 * @par
 * Determines if its a Discover card if its 16 digits long that starts with 
 * 65, 644 to 649, 6011, or 622126 to 622926 if the card meets the criteria, 
 * returns a boolean true, otherwise returns false.
 * 
 *
 * @param[in] str The credit card string to be checked.
 *
 * @returns a boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string str = "6229267636070782";

   result = isDiscover( str ); // result would be true;

   str = "6011747636070782";
   result = isDiscover( str ); // result would be true;
   
   str = "6440747636070782";
   result = isDiscover( str ); // result would be true;
   
   str = "6585288877768476";
   result = isDiscover( str ); // result would be true;

   @endverbatim
 ************************************************************************/
//helper function that checks whether the card is a discover card
bool isDiscover(string str)
{
    string nStr;
    int b;
    int i;
    int a;
    int j;
    int z;
    int len = str.length(); 
    //checks if the length is 16 and starts with 65
    if(len == 16 && str.at(0) == '6') 
    {
        if(str.at(1) == '5')
        {
            return true; 
        }
        //checks for if it starts with 644 to 649
        if(str.at(1) == '4')
        {
            for(b = 4; b <= 9; b++)
            {
                if(str.at(2) == (char)(b + '0'))
                {
                    return true; 
                }
            }
        }
        //checks if it starts with 6011
        if(str.at(1) == '0' && str.at(2) == '1' && str.at(3) == '1')
            return true; 
        //checks if it starts with 622126 - 622926
        if(str.at(1) == '2' && str.at(2) == '2')
        {
            nStr = ""; 
            a = 0;
            for(j = 3; j <= 5; j++)
            {
                nStr += str.at(j);
                for (i = 0; i<nStr.length(); i++) 
                { 
                    a = (int)(nStr.at(i));
                    for(z = 126; z <= 926; z++)
                    {
                        if(a = z);
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the type of credit card passed in through a string using different parameters 
 * to check if it is a Mastercard
 *
 * @par
 * Determines if its a Discover card if its 16 digits long that starts with 50 to 55
 * 
 *
 * @param[in] str The credit card string to be checked.
 *
 * @returns a boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string str = "502358937954821";

   result = isMaster( str ); // result would be true;

   @endverbatim
 ************************************************************************/
//checks the card against the mastercard criteria
bool isMaster(string str)
{
    int len = str.length(); 
    int i;
    //checks if the length is 16 and that it starts with 5
    if(len == 16 && str.at(0) == '5')
    {
        //loop to check if the second number after the 5 is 0 to 5
        for(i = 0; i <= 5; i++)
        {
            if(str.at(1) == (char)(i + '0'))
            {
                return true; 
            }
        }
    }
    return false;
}



/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the validity of the card  
 *
 * @par
 * Uses the helper functions isOddCalc and isEvenCalc to determine the validity of the card through luhns algorithm
 * 
 *
 * @param[in] cc The credit card string to be checked.
 *
 * @returns a boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string cc = "345649595062090";

   result = isValidCC( cc ); // result would be true;

   cc = "4456895832624";
   result = isValidCC( cc ); // result would be true;
   
   cc = "4716150722142577"
   result = isValidCC( cc ); // result would be true;

   @endverbatim
 ************************************************************************/
//checks if the card is a valid credit card
bool isValidCC(string cc)
{
    //two if statements using the helper functions to check if the card is valid
    int len = cc.length();
    //validity for length 16
    if(len == 16)
    {
        return isEvenCalc(cc);
    }
    //validity of length 13 or 15
    if(len == 13 || len == 15)
    {
        return isOddCalc(cc);
    }
    return false; 
}

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the validity of the card in the case that it is a card of length 13 or 15 
 *
 * @par
 * Runs the Luhns algorithm for the case of 13 and 15 length cards
 * 
 *
 * @param[in] cc The credit card string to be checked.
 *
 * @returns a boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string cc = "345649595062090";

   result = isOddCalc( cc ); // result would be true;

   cc = "4456895832624";
   result = isOddCalc( cc ); // result would be true;

   @endverbatim
 ************************************************************************/
//function that is for when the cc is 13 or 15 long to check if the card is valid
bool isOddCalc(string cc) 
{
    int sum = 0;
    int oddSum = 0; 
    int evenSum = 0; 
    int normOddSum = 0; 
    int doubOddSum = 0;
    int i;
    int j;
    int len = cc.length(); 
    //adds all of the oddnumbers to the sum
    for (i = 0; i < len; i += 2) 
    {
        evenSum += (cc.at(i) - '0');
    }
    //for loop that splits the numbers that are over 9 into their own sum and the ones below into their own sum
    for (j = 1; j < len; j+=2) 
    {
        if((cc.at(j) - '0') * 2 > 9)
        {
            doubOddSum += ((cc.at(j) - '0') * 2) - 9;
        }
        else
        {
            normOddSum += ((cc.at(j) - '0') * 2);
        }
        //adds the two sums to get the sum of the odd numbers
        oddSum = normOddSum + doubOddSum;

    }
    //adds the sum of the odd and even numbers
    sum = oddSum + evenSum;
    //checks if the card is valid
    if(sum % 10 == 0)
    {
        return true;
    }
    if(sum % 10 != 0)
    {
        return false;
    }       
    return false;
}

/** **********************************************************************
 * @author Yasas Wijesekara
 *
 * @par Description
 * Checks the validity of the card in the case that it is a card of length 16
 *
 * @par
 * Runs the Luhns algorithm for the case of 16 length cards
 * 
 *
 * @param[in] cc The credit card string to be checked.
 *
 * @returns a boolean true or false value 
 *
 * @par Example
 * @verbatim
   string result;
   string cc = "4716150722142577";

   result = isEvenCalc( cc ); // result would be true;

   @endverbatim
 ************************************************************************/
//function that is for when the cc is 16 long to check if the card is valid
bool isEvenCalc(string cc) 
{
    int sum = 0;
    int oddSum = 0; 
    int evenSum = 0; 
    int normEvenSum = 0; 
    int doubEvenSum = 0;
    int i;
    int j;
    int len = cc.length(); 
    //adds up all of the numbers in the odd places
    for (i = 1; i < len; i += 2) 
    {
        oddSum += (cc.at(i) - '0');
    }
    //same algorithm as the isOddCalc but for the even numbers
    for (j = 0; j < len; j+=2) 
    {
        if((cc.at(j) - '0') * 2 > 9)
        {
            doubEvenSum += ((cc.at(j) - '0') * 2) - 9;
        }
        else
        {
            normEvenSum += ((cc.at(j) - '0') * 2);
        }
        //sums the evens
        evenSum = normEvenSum + doubEvenSum;

    }
    //sums the two sums
    sum = oddSum + evenSum;
    //checks the validity of the sum
    if(sum % 10 == 0)
    {
        return true;
    }
    if(sum % 10 != 0)
    {
        return false;
    }       
    return oddSum;
}
