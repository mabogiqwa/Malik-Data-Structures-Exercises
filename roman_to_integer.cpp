//Date created: 28-11-2023
//Author: Mabo Giqwa
//Purpose: Converted roman numerals to positive integers
//Fallbacks: The program still needs functions which will 
//verify whether the given input is valid. So input checker
//functions. The program still converts the invalid roman
//numeral ordering, LIXIX.

#include <iostream>
#include <cstring>

const int MAX_SIZE = 10;

void input_roman_numeral(char romanN[]);
//Precondition: The input from the user must be
//a roman numeral and less than 10 in length.
//Postcondition: Stores user input into a cstring.

int convert_roman_numeral_to_number(char romanN[]);
//Postcondition: Converts the roman numeral stored
//in romanN into a positive integer.

int process_roman_numeral_m(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'M'
//Postcondition: Returns the total of the roman numerals
//succeeding M, including the character M itself. 
//Ex. Returns 1500 for roman numeral MD

int process_roman_numeral_d(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'D'
//Postcondition: Returns the total of the roman numerals
//succeeding D, including the character D itself. 
//Ex. Returns 515 for roman numeral DXV

int process_roman_numeral_c(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'C'
//Postcondition: Returns the total of the roman numerals
//succeeding C, including the character C itself. 
//Ex. Returns 128 for roman numeral CXXVIII

int process_roman_numeral_l(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'L'
//Postcondition: Returns the total of the roman numerals
//succeeding L, including the character L itself. 
//Ex. Returns 84 for roman numeral LXXXIV

int process_roman_numeral_x(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'X'
//Postcondition: Returns the total of the roman numerals
//succeeding X, including the character X itself. 
//Ex. Returns 15 for roman numeral XV

int process_roman_numeral_i(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'I'
//Postcondition: Returns the total of the roman numerals
//succeeding I, including the character I itself. 
//Ex. Returns 9 for roman numeral IX

int process_roman_numeral_v(char romanN[], int &iter);
//Precondition: The value of romanN[index] must be 'V'
//Postcondition: Returns the total of the roman numerals
//succeeding V, including the character V itself. 
//Ex. Returns 8 for roman numeral VIII

void print_converted_roman_numeral(char romanN[], int value);
//Postcondition: Prints the integer value for the roman numeral

int main()
{
    char romanN[MAX_SIZE];
    int positiveNumber;

    input_roman_numeral(romanN);

    positiveNumber = convert_roman_numeral_to_number(romanN);

    print_converted_roman_numeral(romanN, positiveNumber);

    return 0;
}

int convert_roman_numeral_to_number(char romanN[])
{
    int c_string_position, positiveNumber;

    c_string_position = 0;
    if (romanN[0] == 'M')
        positiveNumber = process_roman_numeral_m(romanN, c_string_position);
    if (romanN[0] == 'D')
        positiveNumber = process_roman_numeral_d(romanN, c_string_position);
    if (romanN[0] == 'C')
        positiveNumber = process_roman_numeral_c(romanN, c_string_position);
    if (romanN[0] == 'L')
        positiveNumber = process_roman_numeral_l(romanN, c_string_position);
    if (romanN[0] == 'I')
        positiveNumber = process_roman_numeral_i(romanN, c_string_position);
    if (romanN[0] == 'V')
        positiveNumber = process_roman_numeral_v(romanN, c_string_position);

    return positiveNumber;
}

void print_converted_roman_numeral(char romanN[], int value)
{
    std::string roman_numeral;

    roman_numeral = "";
    for (int i = 0; i < strlen(romanN); i++)
        roman_numeral = roman_numeral + romanN[i];

    std::cout << "The positive integer value for " << roman_numeral;
    std::cout << " is: " << value << std::endl;
    
}

void input_roman_numeral(char romanN[])
{
    //Gets input from the user.
    std::cout << "Enter a roman numeral between (10-390) in the tens(no units): ";
    std::cin.getline(romanN, MAX_SIZE);
}

int process_roman_numeral_m(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'M')
    {
        total = total + 1000;
        iter = iter + 1;

        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'M') {
                total = total + 1000;
                iter = iter + 1;
            }
            if (romanN[iter] == 'C') {
                subtotal = process_roman_numeral_c(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'D') {
                subtotal = process_roman_numeral_d(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'X') {
                subtotal = process_roman_numeral_x(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_numeral_l(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v(romanN, iter);
                total = total + subtotal;
            }
        }
    }

    return total;
}

int process_roman_numeral_d(char romanN[], int &iter)
{
    int total = 0;
    int sentinel = 0;
    int subtotal;
    if (romanN[iter] == 'D')
    {
        total = total + 500;
        iter = iter + 1;
        
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'C') {
                subtotal = process_roman_numeral_c(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_numeral_l(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v(romanN, iter);
                total = total + subtotal;
            }
        }
    }

    return total;
}

int process_roman_numeral_c(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'C')
    {
        total = total + 100;
        iter++;
    
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'C') {
                total = total + 100;
                iter = iter + 1;
            }
            if (romanN[iter] == 'X') {
                subtotal = process_roman_numeral_x(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_numeral_l(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'D') {
                total = 400;
                iter = iter + 1;
            }
            if (romanN[iter] == 'M') {
                total = 900;
                iter = iter + 1;
            }
        }
    }

    return total;
}

int process_roman_numeral_l(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'L')
    {
        total = total + 50;
        iter++;
        
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'X') {
                subtotal = process_roman_numeral_x(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'I') {
                subtotal = process_roman_numeral_i(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'V') {
                subtotal = process_roman_numeral_v(romanN, iter);
                total = total + subtotal;
            }
        }
    }

    return total;
    //At this point in time, this function returns the total of whatever
    //segment of the roman numeral it processed and 'leaves' the cstring
    //index position of the next character in the cstring.
}

int process_roman_numeral_x(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'X')
    {
        total = total + 10;
        iter++;
        
        while (sentinel != -1)
        {
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
        }
    }

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
