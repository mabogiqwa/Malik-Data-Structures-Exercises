#include <iostream>
#include <list>
using namespace std;

const int NUM = 5;

void bubbleSort(int list[], int length);

int main()
{
    int list[NUM] = {10, 7, 19, 5, 16};

    bubbleSort(list, NUM);

	for (const auto& i: list)
	{
		cout << i << " ";
	}

    //for(int i = 0; i < NUM; i++)
        //cout << list[i] << " ";

    return 0;
}
void bubbleSort(int list[], int length)
{
 	for (int iteration = 1; iteration < length; iteration++)
 	{
 		for (int index = 0; index < length - iteration; index++)
 		{
 			if (list[index] > list[index + 1])
 			{
 				int temp = list[index];
 				list[index] = list[index + 1];
 				list[index + 1] = temp;
		    }
 		}
 	}
}