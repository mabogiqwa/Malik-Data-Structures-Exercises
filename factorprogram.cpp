#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool isPrime(long long number);

void printFactors(long long number);

void printPrimeFactors(long long number);

void printPrimesOfNumber(long long number)
{
    int prime;
    ifstream ins;
    ins.open("primenumbers.txt");

    while(ins >> prime)
    {
        if(number%prime == 0)
            cout << prime << " ";
    }
    ins.close();
}

int main()
{
    long long number = 3614457253;

    cout << "The prime numbers of " << number << endl;
    printPrimesOfNumber(number);

    return 0;

}
bool isPrime(long long number)
{
    int sentinel; 
    int oddNumIterator;
    bool prime = false;

    if(number == 1 || number == 2)
            return true;
    else if(number%2 == 0)
            return false;
    else if(number%2 != 0) {
        sentinel = 1;
        oddNumIterator = 3;
        while((sentinel != 0))
        {
            if((number%oddNumIterator == 0) && (oddNumIterator != number)) {
                    return false;
                    sentinel = 0;
            } else if(number/oddNumIterator == 1) {
                    sentinel = 0;
                    return true;
            }
            oddNumIterator += 2;
        }
    }
}
void printFactors(long long number)
{
    int arraySize = 0;
    int factors[11];
    int index = 0;
    
    for(int i = 0; i < 50; i++) {
        if(number%(i+1) == 0) {
            factors[index] = (i+1);
            cout << factors[index] << " ";
            arraySize++;
            index++;
        }
    }
    cout << endl;
}
void printPrimeFactors(long long number)
{
    int arraySize = 0;
    int factors[11], primeFactors[7];
    int index = 0;
    
    for(int i = 0; i < 50; i++) {
        if(number%(i+1) == 0) {
            factors[index] = (i+1);
            arraySize++;
            index++;
        }
    }
    index = 0;
    for(int i = 0; i < arraySize; i++) {
        if(isPrime(factors[i])) {
            primeFactors[index] = factors[i];
            cout << primeFactors[index] << " ";
            index++;
        }
    }
    cout << endl;
}