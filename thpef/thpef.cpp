/** ********************************************************************
* @file
************************************************************************/
#include "thpef.h"

//write functions here

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  gets the current date
 *
 *
 *  @returns a string being the date month and year
 *
 *  @par Example
 *  @verbatim
    string date;
    
    date = getDate(); //date would be whatevever the current date is

    @endverbatim
 ************************************************************************/
string getDate()
{
    //getting the current date and creating date variables 
    time_t myTimeT = time(NULL);
    string currentTime = ctime(&myTimeT);
    string day;
    string month;
    string year; 
    string date; 
    
    //putting all of the data into their respective variables 
    day = currentTime.substr(9,1);
    month = currentTime.substr(4,3);
    year = currentTime.substr(20,4);
     
    if(stod(day) < 10)
    {
        day = "0" + day;
    }
    //put it all into the formatted string 
    date = day + " " + month + ", " + year;
    
    //return the date
    return date;
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  gets all of the data needed for the customer and fills out the customer string and returns false if theres nothing on the line but true * if there is 
 *
 *  @param[in] fin the file to be opened
 *  @param[in] customer a customer and the data associated
 *
 *  @returns a boolean telling 
 *
 *  @par Example
 *  @verbatim
    ifstream fin;
    customer client;
    bool read;
    
    read = getClient(fin, client) //as long as there is a name associated with the line it returns true here

    @endverbatim
 ************************************************************************/
bool getClient(ifstream& fin, customer& customer)
{
    string tempAmount;
    string tempBalance;
    getline(fin, customer.firstName, ',');
    if(customer.firstName.empty()) //check if the line is empty 
    {
        return false;  
    }
    else
    {
        //put the rest of the data into its respective parts of a customer 
        getline(fin, customer.lastName, ',');
        getline(fin, customer.streetAddress, ',');
        getline(fin, customer.city, ',');
        getline(fin, customer.state, ',');
        getline(fin, customer.zipCode, ',');
        getline(fin, tempAmount, ',');
        getline(fin, tempBalance); 
        customer.transAmount = stod(tempAmount); //here change the strings that you put into temp variables into doubles
        customer.balance = stod(tempBalance);
        return true; 
    }
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  writes up the letter for the client using some templates that are in the file 
 *
 *  @param[in] customer a customer and all the data associated with
 *  @param[in] templateFile the name of the template file that we use to store the data in
 *  @param[in] currentDate the current date that we are in 
 *
 *  @returns nothing its void
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
void writeLetter(customer& customer, string templateFile, string currentDate)
{
    string line;
    ifstream fin;
    ofstream fout;
    string::size_type fullNamePos, addressPos, cityPos, statePos, zipCodePos, datePos, firstPos, transPos, balancePos, sincerlyPos, csePos, endingPos, endingPosTwo, overdueEnd;
    string outputFileName = customer.firstName + '.' + customer.lastName + ".txt";
    string balanceStr;
    string transStr;
    ostringstream myStream;
    
    myStream << fixed << setprecision(2);
    myStream << customer.balance + customer.transAmount; 
    balanceStr = myStream.str();
    
    myStream.str("");
    
    myStream << fixed << setprecision(2);
    myStream << abs(customer.transAmount); 
    transStr = myStream.str();
    
    myStream.str("");
    
    openInput(fin, templateFile);
    
    openOutput(fout, outputFileName);
    if(!fout.is_open())
    {
        cout << "Unable to open the output file: " << outputFileName << endl;
        fout.close();
    }
    while(getline(fin, line))
    {
        findAndReplace(line, "#FULLNAME", customer.firstName + " " + customer.lastName);
        findAndReplace(line, "#ADDRESS", customer.streetAddress);
        findAndReplace(line, "#CITY, #STATE #ZIP", customer.city + ", " + customer.state + " " + customer.zipCode);
        findAndReplace(line, "#DATE", currentDate);
        findAndReplace(line, "#FIRST", customer.firstName);
        findAndReplace(line, "#LAST", customer.lastName);
        findAndReplace(line, "#TRANSACTION", transStr);
        findAndReplace(line, "#BALANCE",  balanceStr);
        fout << line << endl;
    }
}
//helper functions
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
 *  @param[in] fin the file to be closed
 *  @param[in] fout1 the file to be closed
 *  @param[in] fout2 the file to be closed
 *  @param[in] fout3 the file to be closed
 *
 *  @returns nothing its void
 *
 *  @par Example
 *  @verbatim
    ifstream fin;
    ofstream fout1, fout2, fout3;
    
    cleanUp(fin, fout);//the files are closed

    @endverbatim
 ************************************************************************/
//closes the files
void cleanUp(ifstream& fin, ifstream& fin1, ifstream& fin2, ifstream& fin3)
{
    fin.close();
    fin1.close();
    fin2.close();
    fin3.close(); 
    exit(0);
}

/** **********************************************************************
 *  @author Yasas Wijesekara
 *
 *  @par Description
 *  find and replace a word with another in a string
 *
 *  @param[in] line the string to be passed in to be checked
 *  @param[in] stringSearch the string to be found in the line string
 *  @param[in] replace the string to replace the stringSearch with
 *
 *  @returns a boolean telling if the file has been opened
 *
 *  @par Example
 *  @verbatim
    string str = "yeehaw";
    
    findAndReplace(str, "yee", "knee"); //str would now be "kneehaw"
    
    @endverbatim
 ************************************************************************/
void findAndReplace(string& line, string stringSearch, string replace)
{
    // Get the position of the string
    size_t pos = line.find(stringSearch);
    while( pos != string::npos)
    {
        //replace the occurrence of the string
        line.replace(pos, stringSearch.size(), replace);
        //look for another instance just in case
        pos = line.find(stringSearch, pos + replace.size());
    }
}
