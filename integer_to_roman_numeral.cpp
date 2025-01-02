//Created: 20-11-2023
//Author: Mabo Giqwa
//Specification: Converts positive
//integers less than 9999 into roman numerals

#include <iostream>
#include <string>

int inputInteger();
//Returns a positive integer between 1-9999 entered from the
//keyboard
void convertNumeral(int positiveInteger);
//Converts positive integer into roman numeral.
//Postcondition: The numeral must be less than 9999.

std::string convert_unit_to_roman_numeral(int positiveInt, std::string romanN);
//Converts the unit number of a digit into a roman numeral.
//For instance, the 9 in 19 is converted to XI.

std::string convert_tens_to_roman_numeral(int positiveInt, std::string romanN);
//Converts the tens value of a digit into a roman numeral.
//For instance, the 1 in 19 is converted to X.

std::string convert_hundreds_to_roman_numeral(int positiveInt, std::string romanN);
//Converts the hundreds value of a digit into a roman numeral.
//For instance, the 1 in 119 is converted to C.

std::string convert_thousands_to_roman_numeral(int positiveInt, std::string romanN);
//Comverts the thousands value of a digit into a roman numeral.
//For instance, the 1 in 1119 is converted to M.

int main()
{
    int positiveIntValue;
    std::string n = "";

    positiveIntValue =  inputInteger();
    convertNumeral(positiveIntValue);

    return 0;
}

int inputInteger()
{
    int positiveInteger;

    do
    {
      std::cout << "Enter a positive integer(1 - 9999): ";
      std::cin >> positiveInteger;
    } while (positiveInteger < 1 || positiveInteger > 9999);

    return positiveInteger;
}

void convertNumeral(int positiveInteger)
{
    int lengthOfPositiveInteger;
    std::string stringPositiveInteger, romanNumeral;

    stringPositiveInteger = std::to_string(positiveInteger);
    //Converts int data type to string
    lengthOfPositiveInteger = stringPositiveInteger.length();
    //Everything works fine up till this point

    //The following code executes if the input digit is between 1 - 9
    if (lengthOfPositiveInteger == 1)
    {
        std::string u; //Unit value
        romanNumeral = "";
        u = convert_unit_to_roman_numeral(positiveInteger, romanNumeral);
        romanNumeral = u;
    }
    //The following if executes if the input digit is between 10 - 99
    if (lengthOfPositiveInteger == 2)
    {
        std::string u; //Unit value
        std::string t; //Tens value
        int unitIntValue;
        int tensIntValue;
        
        std::string unitVal, tensVal;

        romanNumeral = "";

        //The following clock of code retrieves the
        //tens value in the positive integer string
        tensVal = stringPositiveInteger.substr(0,1);
        tensIntValue = std::stoi(tensVal);
        t = convert_tens_to_roman_numeral(tensIntValue, romanNumeral); //Converts the 'tens'
        //value into a roman numeral.

        //The following block of code retrieves the
        //unit value in the positive integer string
        unitVal = stringPositiveInteger.substr(1,1);
        unitIntValue = std::stoi(unitVal);
        //The preceding code does what intended.
        u = convert_unit_to_roman_numeral(unitIntValue, romanNumeral); //Converts the 'unit'
        //value into a roman numeral.

        romanNumeral = t + u;
    }
    //The following if statement executes if the input digit is between 100 - 999
    if (lengthOfPositiveInteger == 3)
    {
        std::string u; //Unit value
        std::string t; //Tens value
        std::string h; //Hundreds value
        int unitIntValue, tensIntValue;
        int hundredsIntValue;

        std::string hundredsVal, tensVal, unitVal;

        romanNumeral = "";
        hundredsVal = stringPositiveInteger.at(0);
        hundredsIntValue = std::stoi(hundredsVal);

        h = convert_hundreds_to_roman_numeral(hundredsIntValue, romanNumeral);

        tensVal = stringPositiveInteger.at(1);
        tensIntValue = std::stoi(tensVal);

        t = convert_tens_to_roman_numeral(tensIntValue, romanNumeral);

        unitVal = stringPositiveInteger.at(2);
        unitIntValue = std::stoi(unitVal);

        u = convert_unit_to_roman_numeral(unitIntValue, romanNumeral);

        romanNumeral = h + t + u;
    }
    //The following if statement executes if the input digit is between 1000 - 9999
    if (lengthOfPositiveInteger == 4) 
    {
        std::string u; //Unit value
        std::string t; //Tens value
        std::string h; //Hundreds value
        std::string ts; //Thousands value
        int unitIntValue, tensIntValue;
        int hundredsIntValue, thousandsIntValue;

        std::string unitVal, tensVal, hundredsVal, thousandsVal;

        romanNumeral = "";
        thousandsVal = stringPositiveInteger.at(0);
        thousandsIntValue = std::stoi(thousandsVal);

        ts = convert_thousands_to_roman_numeral(thousandsIntValue, romanNumeral);

        hundredsVal = stringPositiveInteger.at(1);
        hundredsIntValue = std::stoi(hundredsVal);

        h = convert_hundreds_to_roman_numeral(hundredsIntValue, romanNumeral);

        tensVal = stringPositiveInteger.at(2);
        tensIntValue = std::stoi(tensVal);

        t = convert_tens_to_roman_numeral(tensIntValue, romanNumeral);

        unitVal = stringPositiveInteger.at(3);
        unitIntValue = std::stoi(unitVal);

        u = convert_unit_to_roman_numeral(unitIntValue, romanNumeral);

        romanNumeral = ts + h + t + u;
    }

    std::cout << romanNumeral;
}

std::string convert_unit_to_roman_numeral(int positiveInt, std::string romanN)
{
        if (positiveInt == 0)
        {
            return "";
        }
        int iter = 0;
        do
        {
            iter++;
            if (iter > 0 && iter < 4)
                romanN = romanN + "I";
            if (iter == 4)
                romanN = "IV";
            if (iter >= 5 && iter < 9) {
                romanN = "V";
                    if (iter > 5) {
                        //If executes to add the extra 'I' symbols
                        //if the unit number is greater than 5
                        int iterations = positiveInt - 5;
                        for(int i = 0; i < iterations; i++)
                        {
                            romanN = romanN + "I";
                        }
                    }
            }
            if (iter == 9) {
                romanN = "IX";
            }
        } while (iter != positiveInt);

        return romanN;
}

std::string convert_tens_to_roman_numeral(int positiveInt, std::string romanN)
{
   if (positiveInt == 0)
   {
        return "";
   }

    int iter = 0;
    do
    {
        iter++;
        if (iter > 0 && iter < 4)
            romanN = romanN + "X";
        if (iter == 4)
            romanN = "XL";
        if (iter >= 5 && iter < 9) {
            romanN = "L";
            if (iter > 5) {
                int iterations = positiveInt - 5;
                for (int i = 0; i < iterations; i++) {
                    romanN = romanN + "X";
                }
            }
        }
        if (iter == 9) {
            romanN = "XC";
        }
    } while (iter != positiveInt);

    return romanN;
}

std::string convert_hundreds_to_roman_numeral(int positiveInt, std::string romanN)
{
    if (positiveInt == 0)
    {
        return "";
    }

    int iter = 0;
    do
    {
        iter++;
        if (iter > 0 && iter < 4)
            romanN = romanN + "C";
        if (iter == 4)
            romanN = "CD";
        if (iter >= 5 && iter < 9) {
            romanN = "D";
            if (iter > 5) {
                int iterations = positiveInt - 5;
                for (int i = 0; i < iterations; i++) 
                {
                    romanN = romanN + "C";
                }
            }
        }
        if (iter == 9)
            romanN = "CM";
    } while (iter != positiveInt);
    
    return romanN;
}

std::string convert_thousands_to_roman_numeral(int positiveInt, std::string romanN)
{
    if (positiveInt == 0)
        return "";

    int iter = 0;
    do 
    {
        iter++;
        if (iter > 0 && iter < 10)
            romanN = romanN + "M";
    } while (iter != positiveInt);

    return romanN;
}
