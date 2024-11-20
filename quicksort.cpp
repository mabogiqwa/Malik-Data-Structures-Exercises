#include <iostream>
using namespace std;

const int NUM = 9;

int partition(int list[], int first, int last);

void swap(int list[], int first, int second);

int main()
{
    int first_1 = 0;
    int last_1 = 8;
    int list[NUM] = {45,82,25,94,50,60,78,32,92};

    partition(list,first_1,last_1);
    
	for (const auto& element : list)
	{
		cout << element << " ";
	}
    //partition(list,first_1,last_1);

    return 0;
 }
int partition(int list[], int first, int last)
{
 	int pivot;
 	int smallIndex;
 	swap(list, first, (first + last) / 2);
 	pivot = list[first];
 	smallIndex = first;
 	for (int index = first + 1; index <= last; index++) {
 		if (list[index] < pivot)
 		{
			 smallIndex++;
 			 swap(list, smallIndex, index);
 		}
        cout << "List " << index << ":" << endl;
        for(int j = 0; j <= last; j++)
            cout << list[j] << " ";
        cout << endl;
     }
  	swap(list, first, smallIndex);

 	return smallIndex;
}
void swap(int list[], int first, int second)
{
 	int temp;
 	temp = list[first];
 	list[first] = list[second];
 	list[second] = temp;
} 