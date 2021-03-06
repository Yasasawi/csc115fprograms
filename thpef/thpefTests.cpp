#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpef.h"



const bool RUNCATCH = false;

int main(int argc, char **argv)
{
    Catch::Session session;
    int result;
    string inputFile;
    string purchase;
    string payment;
    string overdue;
    ifstream fin;
    ifstream finPurchase, finPayment, finOverdue;
    customer client;
    string date;

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
    if(argc != 5)
    {
        cout << "Usage: thpef.exe datafile template1 template2 template3" << endl;
        cout << "       datafile --name of input data file" << endl;
        cout << "       template1 --name of purchase template file" << endl; 
        cout << "       template2 --name of payment template file" << endl; 
        cout << "       template3 --name of overdue template file" << endl; 
        exit(0);
    }
    
    if(currDate == "")
    {
        date = getDate();
    }
    else
    {
        date = currDate; 
    }
    
    inputFile = argv[1];
    purchase = argv[2];
    payment = argv[3];
    overdue = argv[4];
    
    openInput(fin, inputFile);
    if(!fin.is_open())
    {
        cout << "Unable to open the input file: " << inputFile << endl;
        cleanUp(fin, finPurchase, finPayment, finOverdue);
    }
    
    openInput(finPurchase, purchase);
    if(!finPurchase.is_open())
    {
        cout << "Unable to open the template file: " << purchase << endl;
        cleanUp(fin, finPurchase, finPayment, finOverdue);
    }

    openInput(finPayment, payment);
    if(!finPayment.is_open())
    {
        cout << "Unable to open the template file: " << payment << endl;
        cleanUp(fin, finPurchase, finPayment, finOverdue);
    }
    
    openInput(finOverdue, overdue);
    if(!finOverdue.is_open())
    {
        cout << "Unable to open the template file: " << overdue << endl;
        cleanUp(fin, finPurchase, finPayment, finOverdue);
    }
    
    while(getClient(fin, client))
    {
        if(client.transAmount < 0) 
        {
            writeLetter(client, payment, date);
        }
        if(client.transAmount > 0) 
        {
            writeLetter(client, purchase, date);
        }
        if(client.transAmount == 0) 
        {
            writeLetter(client, overdue, date);
        }
    }
    cleanUp(fin, finPurchase, finPayment, finOverdue);
    return 0;
}

//write test cases here
TEST_CASE("getClient - testing if the function read")
{
    string fileName = "datafile1.txt";
    customer steve; 
    ifstream fin; 
    openInput(fin, fileName);
    bool client; 
    client = getClient(fin, steve);
    
    REQUIRE(steve.firstName == "James");
    REQUIRE(steve.balance == 12.5);
    REQUIRE(client == true);
    fin.close();
}

TEST_CASE("writeLetter - testing if the function works")
{
    string fileName = "datafile1.txt";
    customer steve; 
    ifstream fin; 
    openInput(fin, fileName);
    bool client; 
    string templateFile = "purchaseTemplate.txt";
    client = getClient(fin, steve);
    string date = getDate();
    
    writeLetter(steve, templateFile, date);
    
    REQUIRE(client == true);
}