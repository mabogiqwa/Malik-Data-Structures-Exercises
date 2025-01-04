//Created: 28-11-2023
//Purpose: Driver program to test the
//function process_roman_numeral_i()

#include <iostream>

const int MAX_SIZE = 10;

int process_roman_numeral_i(char romanN[], int &iter);

void input_roman_numeral(char romanN[]);

int main()
{
    char romanN[MAX_SIZE];
    int stringPosition, total;

    input_roman_numeral(romanN);

    stringPosition = 0;
    total = process_roman_numeral_i(romanN, stringPosition);

    std::cout << "Total: " << total << std::endl;
    std::cout << "String position: " << stringPosition << std::endl;
    //The function process_roman_numeral_i() is fully functional.

    return 0;
}

void input_roman_numeral(char romanN[])
{
    //Gets input from the user.
    std::cout << "Enter a roman numeral between (1-4 and 9): ";
    std::cin.getline(romanN, MAX_SIZE);
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

