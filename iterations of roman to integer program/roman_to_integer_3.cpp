//Created: 27-11-2023
//Purpose: This is going to be the merge file, the file where
//I merge all the separate functionalities to see how everything
//works.

#include <iostream>

const int MAX_SIZE = 10;

void input_roman_numeral(char romanN[]);

int process_roman_character_c(char romanN[], int &iter);

int process_roman_character_x(char romanN[], int &iter);

int process_roman_character_l(char romanN[], int &iter);

int process_roman_numeral_i(char romanN[], int &iter);

int process_roman_numeral_v(char romanN[], int &iter);

int main()
{
    char romanN[MAX_SIZE];
    int total, stringPosition;

    input_roman_numeral(romanN);

    stringPosition = 0;
    total = process_roman_character_c(romanN, stringPosition);

    std::cout << "Total: " << total << std::endl;
    std::cout << "String position is: " << stringPosition << std::endl;
    
    return 0;
}
void input_roman_numeral(char romanN[])
{
    //Gets input from the user.
    std::cout << "Enter a roman numeral between (10-390) in the tens: ";
    std::cin.getline(romanN, MAX_SIZE);
}

int process_roman_character_c(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'C')
    {
        total = total + 100;
        iter++;
        //if(romanN[iter] == '\0')
            //return total;
        while (sentinel != -1)
        {
            //The reason the condition iter > 7 is
            //because the longest roman numeral so 
            //at this point is CCCLXXX, so 380
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'C') {
                total = total + 100;
                iter = iter + 1;
            }
            if (romanN[iter] == 'X') {
                subtotal = process_roman_character_x(romanN, iter);
                total = total + subtotal;
            }
            if (romanN[iter] == 'L') {
                subtotal = process_roman_character_l(romanN, iter);
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
/*Redundant code
int process_roman_character_x(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
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
*/
int process_roman_character_x(char romanN[], int &iter)
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
/*Redundant code
int process_roman_character_l(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    if (romanN[iter] == 'L')
    {
        total = total + 50;
        iter++;
        //if(romanN[iter] == '\0')
            //return total;
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'X') {
                total = total + 10;
                iter = iter + 1;
            }
        }
    }

    return total;
    //At this point in time, this function returns the total of whatever
    //segment of the roman numeral it processed and 'leaves' the cstring
    //index position of the next character in the cstring.
}
*/
int process_roman_character_l(char romanN[], int &iter)
{
    int sentinel = 0;
    int total = 0;
    int subtotal;
    if (romanN[iter] == 'L')
    {
        total = total + 50;
        iter++;
        //if(romanN[iter] == '\0')
            //return total;
        while (sentinel != -1)
        {
            if (romanN[iter] == '\0')
                sentinel = -1;
            if (romanN[iter] == 'X') {
                total = total + 10;
                iter = iter + 1;
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
