#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe1.h"

//getCCType test cases
TEST_CASE("getCCType - testing for a blank string")
{
    string creditCard = " "; 
    string ccType = getCCType(creditCard);
    REQUIRE(ccType == "Unknown"); 
}

TEST_CASE("getCCType - testing for discover")
{
    string creditCard = "6440747636070782"; 
    string ccType = getCCType(creditCard);
    REQUIRE(ccType == "Discover"); 
}

TEST_CASE("getCCType - testing for american express")
{
    string creditCard = "343669144240775"; 
    string ccType = getCCType(creditCard);
    REQUIRE(ccType == "American Express"); 
}

TEST_CASE("getCCType - testing for visa")
{
    string creditCard = "4794630503276178"; 
    string ccType = getCCType(creditCard);
    REQUIRE(ccType == "Visa"); 
}

TEST_CASE("getCCType - testing for mastercard")
{
    string creditCard = "5023589379548211"; 
    string ccType = getCCType(creditCard);
    REQUIRE(ccType == "Mastercard"); 
}

TEST_CASE("getCCType - testing for invalid")
{
    string creditCard = "802358937954821123"; 
    string ccType = getCCType(creditCard);
    REQUIRE(ccType == "Unknown"); 
}
//credit card functions testing
//isAmericanExpress
TEST_CASE("isAmericanExpress - testing for american express")
{
    string creditCard = "343669144240775"; 
    bool americanType = isAmericanExpress(creditCard);
    REQUIRE(americanType == true); 
}

TEST_CASE("isAmericanExpress - testing for not an american express")
{
    string creditCard = "4794630503276178";
    bool americanType = isAmericanExpress(creditCard);
    REQUIRE(americanType == false);
}

//isVisa
TEST_CASE("isVisa - testing for visa")
{
    string creditCard = "4794630503276178"; 
    bool visaType = isVisa(creditCard);
    REQUIRE(visaType == true); 
}

TEST_CASE("isVisa - testing for not a visa card")
{
    string creditCard = "3436691442407750"; 
    bool visaType = isVisa(creditCard);
    REQUIRE(visaType == false); 
}

//isDiscover
TEST_CASE("isDiscover == testing for discover with 65")
{
    string creditCard = "6585288877768476";
    bool discoverType = isDiscover(creditCard);
    REQUIRE(discoverType == true);
}

TEST_CASE("isDiscover == testing for discover with 644")
{
    string creditCard = "6440747636070782";
    bool discoverType = isDiscover(creditCard);
    REQUIRE(discoverType == true);
}

TEST_CASE("isDiscover == testing for discover with 6011")
{
    string creditCard = "6011747636070782";
    bool discoverType = isDiscover(creditCard);
    REQUIRE(discoverType == true);
}

TEST_CASE("isDiscover == testing for discover with 622926")
{ 
    string creditCard = "6229267636070782";
    bool discoverType = isDiscover(creditCard);
    REQUIRE(discoverType == true);
}

TEST_CASE("isDiscover == testing for invalid discover")
{
    string creditCard = "6332276360707821";
    bool discoverType = isDiscover(creditCard);
    REQUIRE(discoverType == false);
}

//isMaster testing
TEST_CASE("isMaster = testing a valid mastercard")
{
    string creditCard = "5023589379548211";
    bool masterType = isMaster(creditCard);
    REQUIRE(masterType == true);
}

TEST_CASE("isMaster = testing an invalid mastercard")
{
    string creditCard = "5823589379548212";
    bool masterType = isMaster(creditCard);
    REQUIRE(masterType == false);
}
//isValidCC tests 
TEST_CASE("isValidCC - testing a letter in the card")
{
    string creditCard = "47946d0503276178";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == false);
}

TEST_CASE("isValidCC - testing a valid 16 digit number")
{
    string creditCard = "4794630503276178";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == true);
}

TEST_CASE("isValidCC - testing a invalid 16 digit number")
{                        
    string creditCard = "5385288768768674";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == false);
}

TEST_CASE("isValidCC - testing a 15 digit valid number")
{
    string creditCard = "345649595062090";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == true);
}

TEST_CASE("isValidCC - testing a 15 digit invalid number")
{
    string creditCard = "343669144240774";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == false);
}

TEST_CASE("isValidCC - testing a 13 digit valid number")
{
    string creditCard = "4456895832624";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == true);
}

TEST_CASE("isValidCC - testing a 13 digit invalid number")
{
    string creditCard = "3456305812624";
    bool calc = isValidCC(creditCard);
    REQUIRE(calc == false);
}

//isEvenValid tests
TEST_CASE("isEvenValid - testing a 16 digit valid number")
{
    string creditCard = "4716150722142577";
    bool evenCalc = isOddCalc(creditCard);
    REQUIRE(evenCalc == true);
}

TEST_CASE("isEvenValid - testing a 16 digit invalid number")
{
    string creditCard = "5385288768768674";
    bool evenCalc = isOddCalc(creditCard);
    REQUIRE(evenCalc == false);
}

//isOddValid tests 
TEST_CASE("isOddValid - testing a 15 digit valid number")
{
    string creditCard = "345649595062090";
    bool oddCalc = isOddCalc(creditCard);
    REQUIRE(oddCalc == true);
}

TEST_CASE("isOddValid - testing a 15 digit invalid number")
{
    string creditCard = "343669144240774";
    bool oddCalc = isOddCalc(creditCard);
    REQUIRE(oddCalc == false);
}

TEST_CASE("isOddValid - testing a 13 digit valid number")
{
    string creditCard = "4456895832624";
    bool oddCalc = isOddCalc(creditCard);
    REQUIRE(oddCalc == true);
}

TEST_CASE("isOddValid - testing a 13 digit invalid number")
{
    string creditCard = "3456305812624";
    bool oddCalc = isOddCalc(creditCard);
    REQUIRE(oddCalc == false);
}