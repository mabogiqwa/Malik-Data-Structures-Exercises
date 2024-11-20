#include <iostream>
using namespace std;

const int NUM = 12;

void insertionSort(int list[], int length);

int main()
{
    int list[NUM] = {3,4,45,46,66,71,8,67,91,11,15,56};

    insertionSort(list, NUM);

    for(int i = 0; i < NUM; i++)
        cout << list[i] << " ";

    return 0;
}
void insertionSort(int list[], int length)
{
        int firstOutOfOrder;
        for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++) {
                int temp1 = firstOutOfOrder-1;
                if (list[firstOutOfOrder] < list[temp1])
                {
                        int temp = list[firstOutOfOrder];
                        int location = firstOutOfOrder;
                        do
                        {
                            list[location] = list[location - 1];
                            location--;
                        } while(location > 0 && list[location - 1] > temp);
                        list[location] = temp;
                }
        }

}
