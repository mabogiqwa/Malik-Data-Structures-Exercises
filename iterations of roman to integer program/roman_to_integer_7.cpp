//Created: 28-11-2023
//Purpose: Driver program to test out the function
//process_roman_numeral_v()

#include <iostream>
#include <cstring>

const int MAX_SIZE = 10;

void input_roman_numeral(char romanN[]);

int process_roman_numeral_v(char romanN[], int &iter);

int main()
{
    char romanN[MAX_SIZE];
    int total, stringPosition;

    /*
    input_roman_numeral(romanN);

    stringPosition = 0;
    total = process_roman_numeral_v(romanN, stringPosition);

    std::cout << "Total: " << total << std::endl;
    std::cout << "String position: " << stringPosition << std::endl;
    */

    std::string v = "Hello";

    std::cout << v.length() << std::endl;

    for (int i = 0; i < v.length(); i++)
        romanN[i] = v[i];

    std::cout << strlen(romanN) << std::endl;

    for (int i = 0; i < v.length(); i++)
         std::cout << romanN[i];

    return 0;
}

void input_roman_numeral(char romanN[])
{
    //Gets input from the user.
    std::cout << "Enter a roman numeral between (5-8): ";
    std::cin.getline(romanN, MAX_SIZE);
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
