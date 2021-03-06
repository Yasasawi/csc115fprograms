/** ********************************************************************
* @file
************************************************************************/
#include "thpe3.h"
//write functions here
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  Classifies the card into one of the hand types that are defined by the helper functions
 *
 *  @param[in] card the integer array to be checked
 *  @param[in] size the size of hte card array
 *
 *  @returns a integer representing the card type
 *
 *  @par Example
 *  @verbatim
    bool result;
    int card[5] = {13, 22, 23, 24, 25};
    int hand;
        
    hand = classifyHand(card, size); //hand would be 9;
    
    card[5] =  {44, 45, 46, 47, 48}
    hand = classifyHand(card, size); //hand would be 8;

    @endverbatim
 ************************************************************************/
int classifyHand(int card[], int size)
{
    int face[arrSize];
    int suit[arrSize];
    
    //essentially here just using the helper functions below to find the hand type 
    if(royalFlush(card, face, suit, size) == true)
    {
        return royalflushNum;
    }
    if(straightFlush(card, face, suit, size) == true)
    {
        return straightflushNum; 
    }
    if(fourKind(card, face, size) == true)
    {
        return fourofaKind; 
    }
    if(fullHouse(card, face, size) == true)
    {
        return fullhouseNum; 
    }
    if(isFlush(card, suit, size) == true)
    {
        return flushNum; 
    }
    if(straight(card, size) == true)
    {
        return straightNum; 
    }
    if(threeKind(card, face, size) == true)
    {
        return threeofaKind; 
    }
    if(twoPair(card, face, size) == true)
    {
        return twopairNum; 
    }
    if(twoKind(card, face, size) == true)
    {
        return twoofaKind; 
    }
    return highcardNum; 
}

//helper function
/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  opens the file and makes sure that its open for input files
 *
 *  @param[in] fin the file to be opened
 *  @param[in] fileName the name of the file that is being opened
 *
 *  @returns a boolean telling if the file has been opened
 *
 *  @par Example
 *  @verbatim
    ifstream fin;
    bool open;
    string file = "z:\\test.txt";
    open = openInput(fin, file);
    
    open == false; //the file does not exist
    fin.close();

    @endverbatim
 ************************************************************************/
//opens the file and makes sure that its open for input files
bool openInput(ifstream& fin, string fileName)
{
    fin.open(fileName);
    return fin.is_open(); 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  opens the file and makes sure that its open for output files
 *
 *  @param[in] fout the file to be opened
 *  @param[in] fileName the name of the file that is being opened
 *
 *  @returns a boolean telling if the file has been opened
 *
 *  @par Example
 *  @verbatim
    ofstream fout;
    bool open;
    string file = "z:\\test.txt";
    open = openOutput(fout, file);
    
    open == false; 
    fout.close();

    @endverbatim
 ************************************************************************/
//opens the file and makes sure that its open for output files
bool openOutput(ofstream& fout, string fileName)
{
    fout.open(fileName); 
    return fout.is_open();
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  closes all the files
 *
 *  @param[in] input the file to be closed
 *  @param[in] output the file to be closed
 *
 *  @returns nothing its void
 *
 *  @par Example
 *  @verbatim
    ifstream fin;
    ofstream fout;
    
    cleanUp(fin, fout);//both the files are closed

    @endverbatim
 ************************************************************************/
//closes the files
void cleanUp(ifstream& input, ofstream& output)
{
    input.close();
    output.close();
    exit(0);
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  converts the cards to suits 
 *
 *  @param[in] card the integer array of card values
 *  @param[in] suit the integer array of suit values 
 *  @param[in] size the size of the arrays
 *
 *  @returns nothing its a void function
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {27, 30, 39, 35, 65};
    int suit[size];
    
    getSuit(card, suit, size); 
    
    suit[0] == 2;
    suit[2] == 3;
    suit[4] == 5;

    @endverbatim
 ************************************************************************/
//makes a parallel array of the suits
void getSuit(int card[], int suit[], int size)
{
    int i;
    
    for(i = 0; i < size; i++) 
    {
        suit[i] = (card[i]/13);
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  converts the cards to face
 *
 *  @param[in] card the integer array of card values
 *  @param[in] face the integer array of suit values 
 *  @param[in] size the size of the arrays
 *
 *  @returns nothing its a void function
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {27, 30, 39, 35, 65};
    int suit[size];
    
    getSuit(card, face, size); 
    
    face[0] == 2;
    face[2] == 3;
    face[4] == 5;

    @endverbatim
 ************************************************************************/
//makes a parallel array of the faces
void getFace(int card[], int face[], int size)
{
    int i;
    for(i = 0; i < size; i++) 
    {
        face[i] = (card[i] % 13);
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  converts the cards to face
 *
 *  @param[in] sortArray the integer array to be sorted
 *  @param[in] size the size of the arrays
 *
 *  @returns nothing its a void function
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {27, 30, 39, 35, 65};
    
    mySort(card, size); 
    
    card[0] == 27;
    card[2] == 35;
    card[4] == 39;

    @endverbatim
 ************************************************************************/
//a bubble sort algorithm to sort the numbers in ascending order
void mySort(int sortArray[], int size)
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
            if(sortArray[j] > sortArray[j+1])
            {
                tempSort = sortArray[j];
                sortArray[j] = sortArray[j+1];
                sortArray[j+1] = tempSort;
                swapStatus = true;
            }
        }
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card fits the criteria is twoPair
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {13, 26, 42, 20, 51};
    int face[size];
    bool hand;
    
    hand = twoPair(card, face, size);
    
    hand == false; 

    @endverbatim
 ************************************************************************/
//hand functions 
bool twoPair(int card[], int face[], int size)
{
    int count = 0; 
    int i;
    int j; 
    int totCount = 0; 
    
    //create array of faces and sort it 
    getFace(card, face, size); 
    mySort(face, size); 
    
    //a loop that checks each number and the one next to it, if it find a similar number it adds one to count 
    for(i = 0; i < size; i++)
    {
        if(face[i] == face[i+1])
        {
            count++;
        }
    }
    if(count == 2) //if the count is 2 return it because then theres 2 pairs
    {
        return true;
    }
    return false; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of royal flush
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] suit the suits of the card from the first array
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {13, 22, 23, 24, 25};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = royalFlush(card, face, suit, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool royalFlush(int card[], int face[], int suit[], int size)
{
    //get the faces and suits of the array and sort them
    getFace(card, face, size);
    getSuit(card, suit, size);
    mySort(face, size);
    mySort(suit, size); 
    
    //since theres one hand essnetially, hard code in the hand and check if it is a flush 
    if((face[0] == 0 && face[1] == 9 && face[2] == 10 && face[3] == 11 && face[4] == 12) && isFlush(card, suit, size) == true)
    {
        return true;
    }
    return false; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of straight flush
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] suit the suits of the card from the first array
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {44, 45, 46, 47, 48};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = straightFlush(card, face, suit, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool straightFlush(int card[], int face[], int suit[], int size)
{
    //get the faces and suits of the cards
    getFace(card, face, size);
    getSuit(card, suit, size);
    
    //check if the card is both a straight and a flush
    if(straight(card, size) == true && isFlush(card, suit, size) == true)
    {
        return true;
    }
    return false; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of straight
 *
 *  @param[in] card the card array to be tested
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {17, 18, 19, 20, 21};
    bool hand;
    
    hand = straight(card, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool straight(int card[], int size)
{
    //declare variables and find the faces and sort them 
    int i;
    int temp;
    int face[5];
    for(i = 0; i < size; i++)
    {
        temp = card[i] % 13;
        face[i] = temp; 
    }
    mySort(face, size);
    for(i = 0; i < size - 1; i++)
    {
        if(face[i] == 0)
        {
            if(face[i + 1] != 1 && face[i + 1] != 9)
            {
                return false; 
            }
        }
        else if(face[i + 1] != face[i] + 1)
        {
            return false;
        }
    }
    return true; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of full house
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {13, 39, 15, 132, 41};
    int face[size];
    bool hand;
    
    hand = fullHouse(card, face, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool fullHouse(int card[], int face[], int size)
{
    //get the faces and sort them 
    getFace(card, face, size);
    mySort(face, size); 
    
    //there are only two possibilies for a full house, meaning it just depends on which side the 2 of a kind is on, so I hard coded it to both sides 
    if(face[0] == face[1] && face[2] == face[3] && face[2] == face[4])
    {
        return true; 
    }
    if(face[0] == face[1] && face[0] == face[2] && face[3] == face[4])
    {
        return true; 
    }  
    return false;
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of two of a kind
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {13, 39, 16, 131, 41};
    int face[size];
    bool hand;
    
    hand = twoKind(card, face, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool twoKind(int card[], int face[], int size)
{
/*     int lookup[13];
    createFaceLookup(lookup, card, size);
    if(countIf(lookup, 13, 2) == 1)
    {
        return true; 
    }
    else
    {
        return false; 
    } */
    int i;
     //declare variables and make a count and simCount
    int j;
    int count = 0; 

    //get the face values and sort them 
    getFace(card, face, size);
    mySort(face, size);
    
    //check each value with the entire array adding to count if its the same
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size && j != i; j++)
        {
            if(face[i] == face[j])
            {
                count++;
            }
        }
    }
    if(count == 1) // check if the array only had one pair 
    {
        return true;
    }
    return false;  
}

int countIf(int arr[], int size, int val)
{
    int i;
    int num = 0;
    for(i = 0; i < size; i++)
    {
        if(arr[i] == val)
            num++;
    }
    return num;
}

void createFaceLookup(int lookup[], int input[], int size)
{
    int i, idx;
    for(i=0;i<13;i++)
    {
        lookup[i] = 0;
    }
   
    for(i=0;i<size;i++)
    {
        idx = input[i]%13;
        lookup[idx]++;
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of three of a kind
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {13, 39, 65, 131, 41};
    int face[size];
    bool hand;
    
    hand = threeKind(card, face, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool threeKind(int card[], int face[], int size)
{
     //declare variables and make a simcount set to 0 
    int i; 
    int j;
    int simCount = 0; 

    //get the face values and sort them 
    getFace(card, face, size);
    mySort(face, size);
    //same algorithm as two of a kind instead you add one to simcount when you find a similar number 
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++) 
        {
            if(face[i] == face[j])
            {
                simCount++;
            }
        }
        if(simCount == 3) // return true if simcount is 3 because that means that there are 3 similar numbers
        {
            return true;
        }
        else
        {
            simCount = 0; //if the number is not getting three values reset the counter
        }
    }
    return false; 
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of four of a kind
 *
 *  @param[in] card the card array to be tested
 *  @param[in] face the faces of the cards from the first array 
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {13, 39, 65, 130, 41};
    int face[size];
    bool hand;
    
    hand = fourKind(card, face, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
//four kind is the exact same algorithm as 3 kind but you set the simCount to check for 4 instead of 3 
bool fourKind(int card[], int face[], int size)
{
    int i; 
    int j;
    int simCount = 0; 

    getFace(card, face, size);
    mySort(face, size);
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++) 
        {
            if(face[i] == face[j])
            {
                simCount++;
            }
        }
        if(simCount == 4)
        {
            return true;
        }
        else
        {
            simCount = 0;
        }
    }
    return false;
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  checks if the card hand fits the criteria of a flush
 *
 *  @param[in] card the card array to be tested
 *  @param[in] suit the suits of the cards from the first array 
 *  @param[in] size the size of the arrays
 *
 *  @returns bool if the card fits the criteria
 *
 *  @par Example
 *  @verbatim
    const int size = 5;
    int card[size] = {26, 39, 14, 35, 101};
    int suit[size];
    bool hand;
    
    hand = isFlush(card, face, size);
    
    hand == true; 

    @endverbatim
 ************************************************************************/
bool isFlush(int card[], int suit[], int size)
{
    //get the suits of the cards and set the first value of the array to an integer variables
    int i; 
    getSuit(card, suit, size);
    int firstNum = suit[0];
    //make a for loop that check if the entire array is equal
    for(i = 0; i < size; i++)
    {
        if(firstNum != suit[i])
        {
            return false;
        }
    }
    return true; 
} 

