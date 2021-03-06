#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"

const bool RUNCATCH = false;

int main(int argc, char *argv[])
{
    //declare variables
    Catch::Session session;
    int result;
    ifstream fin;
    ofstream fout; 
    int i = 0;
    int k = 0;
    int z = 0;
    int j = 0; 
    int hand[5];
    int cardarr[1000000];
    int lookup[51];
    string inputFile, outputFile;
    int royalflush = 0;
    int straightflush = 0;
    int fourkindCount = 0; 
    int fullhouse = 0; 
    int flushs = 0; 
    int straights = 0; 
    int threekindCount = 0; 
    int twopairCount = 0; 
    int twokindCount = 0;
    int highcardCount = 0; 
    int totalCount; 
    int seedCount;
    int handCount;
    double royalFlushProb;
    double straightFlushProb;
    double fourKindProb;
    double fullhouseProb;
    double flushProb;
    double straightProb;
    double threeKindProb;
    double twoKindProb;
    double twoPairProb;
    double highcardProb;
    

    if(RUNCATCH)
    {
        result = session.run();
        if(result != 0)
        {
            cout << "Test cases didn't pass" << endl;
            return result;
        }
    }
    //your code goes here.
    if(argc != 4)
    {
        cout << "Usage: thpe3.exe -s seedValue quantity" << endl;
        cout << "       seedValue - # is integer for random numbers" << endl;
        cout << "       quantity - # of hands to deal" << endl; 
        cout << endl;
        cout << "       thpe3.exe -f inputfilename outputfilename" << endl;
        cout << "       inputfilename - filename containing the poker hands to classify" << endl; 
        cout << "       outputfilename - filename to output the statistics in" << endl; 
        exit(0);
    }
    
    if(strcmp(argv[1], "-f") == 0)
    {
        //putting the files into the respective variables
        inputFile = argv[2];
        outputFile = argv[3];
        //opening the files and checking they opened
        openInput(fin, inputFile);
        if(!fin.is_open())
        {
            cout << "Unable to open the file: " << inputFile << endl;
            cleanUp(fin, fout);
        }
        openOutput(fout, outputFile);
        if(!fout.is_open())
        {
            cout << "Unable to open the file: " << outputFile << endl;
            cleanUp(fin, fout);
        }
        while(fin >> hand[i])
        {
            i++; 
            //every 5 numbers added we classify them and add it to the respective hand counter
            if(i == 5)
            {
                 if(classifyHand(hand, 5) == royalflushNum)
                {
                    royalflush++; 
                }  
                if(classifyHand(hand, 5) == straightflushNum)
                {
                    straightflush++; 
                }     
                if(classifyHand(hand, 5) == fourofaKind)
                {
                    fourkindCount++; 
                }
                if(classifyHand(hand, 5) == fullhouseNum)
                {
                    fullhouse++; 
                } 
                if(classifyHand(hand, 5) == flushNum)
                {
                    flushs++; 
                }    
                if(classifyHand(hand, 5) == straightNum)
                {
                    straights++; 
                }    
                if(classifyHand(hand, 5) == threeofaKind)
                {
                    threekindCount++; 
                }
                if(classifyHand(hand, 5) == twopairNum)
                {
                    twopairCount++; 
                }  
                if(classifyHand(hand, 5) == twoofaKind)
                {
                    twokindCount++; 
                }    
                if(classifyHand(hand, 5) == highcardNum)
                {
                    highcardCount++; 
                }                   
                i = 0;
            }
        }
        //calculating the total
        totalCount = royalflush + straightflush + fourkindCount + fullhouse + flushs + straights + threekindCount + twopairCount + twokindCount + highcardCount;
        
        //calculating the probabilities
        royalFlushProb = 100*(royalflush/double(totalCount));
        straightFlushProb = 100*(straightflush/double(totalCount));
        fourKindProb = 100*(fourkindCount/double(totalCount));
        fullhouseProb = 100*(fullhouse/double(totalCount));
        flushProb = 100*(flushs/double(totalCount));
        straightProb = 100*(straights/double(totalCount));
        threeKindProb = 100*(threekindCount/double(totalCount));
        twoPairProb = 100*(twopairCount/double(totalCount));
        twoKindProb = 100*(twokindCount/double(totalCount));
        highcardProb = 100*(highcardCount/double(totalCount));
        
        //formatting the data
        fout << fixed << setprecision(6);
        fout << "Hand Name" << setw(21) << "Dealt" << setw(15) <<"Chance" << endl;
        fout << "Royal Flush" << setw(19) << royalflush << setw(15) << royalFlushProb << "%" << endl;
        fout << "Straight Flush" << setw(16) << straightflush << setw(15) << straightFlushProb << "%" << endl;
        fout << "Four of a Kind" << setw(16) << fourkindCount << setw(15) << fourKindProb << "%" << endl;
        fout << "Full House" << setw(20) << fullhouse << setw(15) << fullhouseProb << "%" << endl;
        fout << "Flush" << setw(25) << flushs << setw(15) << flushProb << "%" << endl;
        fout << "Straights" << setw(21) << straights << setw(15) << straightProb << "%" << endl;
        fout << "Three of a Kind" << setw(15) << threekindCount << setw(15) << threeKindProb << "%" << endl;
        fout << "Two Pair" << setw(22) << twopairCount << setw(15) << twoPairProb << "%" << endl;
        fout << "Two of a Kind" << setw(17) << twokindCount << setw(15) << twoKindProb << "%" << endl;
        fout << "High Card" << setw(21) << highcardCount << setw(15) << highcardProb << "%" << endl;
        fout << endl << "Total Hands Dealt" << setw(13) << totalCount << endl;
        exit(0);
    }
    else if(strcmp(argv[1], "-s") == 0) //the code that runs when the user defines a -s in the code
    {
        int tempCard;
        //putting the seed and total hands into their respective variables
        seedCount = stoi(argv[2]);
        totalCount = stoi(argv[3]);
        //making the random number generator
        static default_random_engine engine(seedCount);
        uniform_int_distribution<int> deck(0,51);
            
        for(i = 0; i < totalCount; i++)
        {
            for(j = 0; j < 5; j++)
            {
                tempCard = deck(engine);
                for(z = 0; z < j; z++)
                {
                    if(hand[z] == tempCard)
                    {
                        tempCard = deck(engine);
                    }
                }
                hand[j] = tempCard;
            }
            if(classifyHand(hand, 5) == royalflushNum)
            {
                royalflush++; 
            }  
            if(classifyHand(hand, 5) == straightflushNum)
            {
                straightflush++; 
            }     
            if(classifyHand(hand, 5) == fourofaKind)
            {
                fourkindCount++; 
            }
            if(classifyHand(hand, 5) == fullhouseNum)
            {
                fullhouse++; 
            } 
            if(classifyHand(hand, 5) == flushNum)
            {
                flushs++; 
            }    
            if(classifyHand(hand, 5) == straightNum)
            {
                straights++; 
            }    
            if(classifyHand(hand, 5) == threeofaKind)
            {
                threekindCount++; 
            }
            if(classifyHand(hand, 5) == twopairNum)
            {
                twopairCount++; 
            }  
            if(classifyHand(hand, 5) == twoofaKind)
            {
                twokindCount++; 
            }    
            if(classifyHand(hand, 5) == highcardNum)
            {
                highcardCount++; 
            }
            j = 0;
        }
        //getting the probabilities
        royalFlushProb = 100*(royalflush/double(totalCount));
        straightFlushProb = 100*(straightflush/double(totalCount));
        fourKindProb = 100*(fourkindCount/double(totalCount));
        fullhouseProb = 100*(fullhouse/double(totalCount));
        flushProb = 100*(flushs/double(totalCount));
        straightProb = 100*(straights/double(totalCount));
        threeKindProb = 100*(threekindCount/double(totalCount));
        twoPairProb = 100*(twopairCount/double(totalCount));
        twoKindProb = 100*(twokindCount/double(totalCount));
        highcardProb = 100*(highcardCount/double(totalCount));
        
        //formatting the data
        cout << fixed << setprecision(6);
        cout << "Hand Name" << setw(21) << "Dealt" << setw(15) <<"Chance" << endl;
        cout << "Royal Flush" << setw(19) << royalflush << setw(15) << royalFlushProb << "%" << endl;
        cout << "Straight Flush" << setw(16) << straightflush << setw(15) << straightFlushProb << "%" << endl;
        cout << "Four of a Kind" << setw(16) << fourkindCount << setw(15) << fourKindProb << "%" << endl;
        cout << "Full House" << setw(20) << fullhouse << setw(15) << fullhouseProb << "%" << endl;
        cout << "Flush" << setw(25) << flushs << setw(15) << flushProb << "%" << endl;
        cout << "Straights" << setw(21) << straights << setw(15) << straightProb << "%" << endl;
        cout << "Three of a Kind" << setw(15) << threekindCount << setw(15) << threeKindProb << "%" << endl;
        cout << "Two Pair" << setw(22) << twopairCount << setw(15) << twoPairProb << "%" << endl;
        cout << "Two of a Kind" << setw(17) << twokindCount << setw(15) << twoKindProb << "%" << endl;
        cout << "High Card" << setw(21) << highcardCount << setw(15) << highcardProb << "%" << endl;
        cout << endl << "Total Hands Dealt" << setw(13) << totalCount << endl;
        exit(0);
    } 
    else //if an incorrect value is given, print invalid option
    {
        cout << "Invalid Option" << endl; 
    }
    return 0;
}

//write test cases here
TEST_CASE("classifyHand")
{
    SECTION("Testing for a royal flush")
    {
        const int size = 5;
        int card[size] = {13, 22, 23, 24, 25};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 9); 
    }
    SECTION("Testing for a straightFlush")
    {
        const int size = 5;
        int card[size] = {44, 45, 46, 47, 48};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 8); 
    }
    SECTION("Testing for a fourKind")
    {
        const int size = 5;
        int card[size] = {26, 39, 66, 13, 130};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 7); 
    }
    SECTION("Testing for a fullHouse")
    {
        const int size = 5;
        int card[size] = {13, 39, 15, 132, 41};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 6); 
    }
    SECTION("Testing for a flush")
    {
        const int size = 5;
        int card[size] = {27, 30, 33, 35, 38};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 5); 
    }
    SECTION("Testing for a straight")
    {
        const int size = 5;
        int card[size] = {4, 18, 19, 20, 34};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 4); 
    }
    SECTION("Testing for a threeKind")
    {
        const int size = 5;
        int card[size] = {26, 39, 65, 18, 131};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 3); 
    }
    SECTION("Testing for a twoPair")
    {
        const int size = 5;
        int card[size] = {15, 41, 7, 20, 51};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 2); 
    }
    SECTION("Testing for a two of a kind")
    {
        const int size = 5;
        int card[size] = {26, 39, 14, 35, 101};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 1);
    }
    SECTION("Testing for a high card")
    {
        const int size = 5;
        int card[size] = {0, 1, 16, 17, 34};
        int hand;
        
        hand = classifyHand(card, size);
        
        REQUIRE(hand == 0); 
    }
}


//helper function testing


TEST_CASE("getSuit - checking for a suit of all of the same number")
{
    const int size = 5;
    int card[size] = {27, 30, 33, 35, 38};
    int suit[size];
    
    getSuit(card, suit, size); 
    
    REQUIRE(suit[0] == 2);
    REQUIRE(suit[2] == 2);
    REQUIRE(suit[4] == 2);
}

TEST_CASE("getSuit - checking for a suit of different numbers")
{
    const int size = 5;
    int card[size] = {27, 30, 39, 35, 65};
    int suit[size];
    
    getSuit(card, suit, size); 
    
    REQUIRE(suit[0] == 2);
    REQUIRE(suit[2] == 3);
    REQUIRE(suit[4] == 5);
}

TEST_CASE("getFace - checking for a face of different numbers")
{
    const int size = 5;
    int card[size] = {25, 5, 39, 35, 65};
    int face[size];
    
    getFace(card, face, size); 
    
    REQUIRE(face[0] == 12);
    REQUIRE(face[2] == 0);
    REQUIRE(face[4] == 0);
}

TEST_CASE("getFace - checking for a face of same numbers")
{
    const int size = 5;
    int card[size] = {78, 130, 39, 26, 65};
    int face[size];
    
    getFace(card, face, size); 
    
    REQUIRE(face[0] == 0);
    REQUIRE(face[2] == 0);
    REQUIRE(face[4] == 0);
}

//card functions
TEST_CASE("twoPair - checking a valid hand")
{
    const int size = 5;
    int card[size] = {15, 41, 101, 20, 23};
    int face[size];
    bool hand;
    
    hand = twoPair(card, face, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("twoPair - checking a invalid hand")
{
    const int size = 5;
    int card[size] = {13, 26, 42, 20, 51};
    int face[size];
    bool hand;
    
    hand = twoPair(card, face, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("royalFlush - checking a straightFlush")
{
    const int size = 5;
    int card[size] = {44, 45, 46, 47, 48};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = royalFlush(card, face, suit, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("royalFlush - checking a hand without an ace")
{
    const int size = 5;
    int card[size] = {21, 22, 23, 24, 25};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = royalFlush(card, face, suit, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("royalFlush - checking a valid hand")
{
    const int size = 5;
    int card[size] = {13, 22, 23, 24, 25};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = royalFlush(card, face, suit, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("straightFlush - checking a flush but not a straight")
{
    const int size = 5;
    int card[size] = {27, 30, 33, 35, 38};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = straightFlush(card, face, suit, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("straightFlush - checking a straight but not a flush")
{
    const int size = 5;
    int card[size] = {4, 18, 19, 20, 34};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = straightFlush(card, face, suit, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("straightFlush - checking a valid hand")
{
    const int size = 5;
    int card[size] = {44, 45, 46, 47, 48};
    int face[size];
    int suit[size];
    bool hand;
    
    hand = straightFlush(card, face, suit, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("fullHouse - checking for a valid hand")
{
    const int size = 5;
    int card[size] = {13, 39, 15, 132, 41};
    int face[size];
    bool hand;
    
    hand = fullHouse(card, face, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("fullHouse - checking for a invalid hand")
{
    const int size = 5;
    int card[size] = {13, 39, 15, 132, 45};
    int face[size];
    bool hand;
    
    hand = fullHouse(card, face, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("isFlush - checking for a valid hand")
{
    const int size = 5;
    int card[size] = {27, 30, 33, 35, 28};
    int suit[size];
    bool flush;
    
    flush = isFlush(card, suit, size);
    
    REQUIRE(flush == true); 
}

TEST_CASE("isFlush - checking for a invalid hand")
{
    const int size = 5;
    int card[size] = {27, 30, 13, 35, 100};
    int suit[size];
    bool flush;
    
    flush = isFlush(card, suit, size);
    
    REQUIRE(flush == false); 
}

TEST_CASE("twoKind - checking for a valid hand")
{
    const int size = 5;
    int card[size] = {26, 39, 14, 35, 101};
    int face[size];
    bool two;
    
    two = twoKind(card, face, size);
    
    REQUIRE(two == true); 
}

TEST_CASE("straight - checking for a valid hand")
{
    const int size = 5;
    int card[size] = {17, 18, 19, 20, 21};
    int face[size];
    bool hand;
    
    hand = straight(card, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("straight - checking for a invalid hand")
{
    const int size = 5;
    int card[size] = {4, 18, 19, 20, 51};
    int face[size];
    bool hand;
    
    hand = straight(card, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("twoKind - checking for a invalid hand")
{
    const int size = 5;
    int card[size] = {13, 44, 17, 133, 41};
    int face[size];
    bool two;
    
    two = twoKind(card, face, size);
    
    REQUIRE(two == false); 
}

TEST_CASE("threeKind - checking for a valid hand")
{
    const int size = 5;
    int card[size] = {26, 39, 65, 18, 101};
    int face[size];
    bool hand;
    
    hand = threeKind(card, face, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("threeKind - checking for a invalid hand")
{
    const int size = 5;
    int card[size] = {32, 32, 13, 13, 1};
    int face[size];
    bool hand;
    
    hand = threeKind(card, face, size);
    
    REQUIRE(hand == false); 
}

TEST_CASE("fourKind - checking for a valid hand")
{
    const int size = 5;
    int card[size] = {26, 39, 66, 13, 130};
    int face[size];
    bool hand;
    
    hand = fourKind(card, face, size);
    
    REQUIRE(hand == true); 
}

TEST_CASE("fourKind - checking for a invalid hand")
{
    const int size = 5;
    int card[size] = {26, 39, 66, 13, 100};
    int face[size];
    bool hand;
    
    hand = fourKind(card, face, size);
    
    REQUIRE(hand == false); 
}