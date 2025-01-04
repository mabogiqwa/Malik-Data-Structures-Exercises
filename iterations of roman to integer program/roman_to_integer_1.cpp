//Created: 27-11-2023
//This file is for testing whether the function
//process_roman_character_x(char someRomanCharacter, int &iter)
//functions optimally
//New update at 28-11-2023 where the function can now process units
#include <iostream>
#include <cstring>

const int MAX_SIZE = 10;

void input_roman_numeral(char romanN[]);

int process_roman_character_x(char romanN[], int &iter);

int process_roman_character_x1(char romanN[], int &iter);

int process_roman_numeral_i(char romanN[], int &iter);

int process_roman_numeral_v(char romanN[], int &iter);

int main()
{
    char romanN[MAX_SIZE];
    int positionOfString, total;

    input_roman_numeral(romanN);
    //Is functional

    positionOfString = 0;
    total = process_roman_character_x1(romanN, positionOfString);

    std::cout << "Total: " << total << std::endl;
    std::cout << "Position of string: " << positionOfString << std::endl;
    //Program works optimally, that is, the function process_roman_character_x
    //does what it is intended to do.

    return 0;
}
void input_roman_numeral(char romanN[])
{
      //Gets input from the user.
      std::cout << "Enter a roman numeral between (10-90) in the tens: ";
      std::cin.getline(romanN, MAX_SIZE);
}

/* Redundant Code
int process_roman_character_x(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    while(sentinel != -1)
    {
        
        if (romanN[iter] == 'X')
        {
            //iter++;
            //The following if statement ensures that
            //the code does not count more than 3 X characters
            //and ensures that the loop terminates once it reads the
            //character '\0'.
            if(romanN[iter] == '\0' || iter > 3) {
                sentinel = -1;
            }
            //The following for processing the character
            //group of XC which relates to the number 90
            if (romanN[iter] == 'C') {
                total = total + 90;
                iter++;
                sentinel = -1;
            }
            //The following if processes the character grouping
            //of XL which relates to number 40
            //terminates the loop.
            if (romanN[iter] == 'L')
            {
                total = total + 40;
                iter++;
                sentinel = -1;
                //The following else is for X, XX and XXX
            }
            if (romanN[iter] == 'X')
            {
                total = total + 10;
                iter++;
            }
        }
    }

    return total;
}
*/

int process_roman_character_x1(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'X')
    {
        total = total + 10;
        iter++;
        //if(romanN[iter] == '\0')
            //return total;
        while (sentinel != -1)
        {
            std::cout << "Value of iter is: " << iter << std::endl;
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'X') 
            {
                total = total + 10;
                iter = iter + 1;
            }
            if (romanN[iter] == 'L')
            {
                total = 40;
                iter = iter + 1;
                sentinel = -1;
            }
            if (romanN[iter] == 'C') {
                total = 90;
                iter = iter + 1;
                sentinel = -1;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v(romanN, iter);
                total = total + subtotal;
            }
            //std::cout << "Value of romanN[iter]: " << romanN[iter] << std::endl;
        }
        //std::cout << "Value of iter before if is: " << iter << std::endl;
    }

    //std::cout << "Value of iter after while: " << iter << std::endl;

    return total;
    //At this point in time, this function returns the total of whatever
    //segment of the roman numeral it processed and 'leaves' the cstring
    //index position of the next character in the cstring.
}

int process_roman_numeral_i(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'I')
    {
        total = total + 1;
        iter = iter + 1;

        while (sentinel != -1)
        {
            //Ensures that the while loop
            //terminates when the end of the
            //cstring is reached.
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'I') {
                total = total + 1;
                iter = iter + 1;
            }
            if (romanN[iter] == 'V') {
                total = 4;
                iter = iter + 1;
                sentinel = -1;
            }
            if (romanN[iter] == 'X') {
                total = 9;
                iter = iter + 1;
                sentinel = -1;
            }
        }
    }

    return total;
}

int process_roman_numeral_v(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'V')
    {
        total = total + 5;
        iter = iter + 1;

        while (sentinel != -1)
        {
            //Ensures that the while loop
            //terminates when the end of the
            //cstring is reached.
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'I') {
                total = total + 1;
                iter = iter + 1;
            }
        }
    }

    return total;
}
