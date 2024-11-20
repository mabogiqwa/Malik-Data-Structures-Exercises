//This is from last year
//It has a bug in it
#include <iostream>
using namespace std;

const int NUM = 9;

int main()
{
   int arr[NUM] = {8,14,13,52,60,65,2,90,23};
   int temp;

  for(int i = 0; i < NUM; i++)
  {
     for(int j = 0; j < (NUM-1); j++) {
       if(arr[i] < arr[j+1]) {
         temp = arr[i];
         arr[i] = arr[j+1];
         arr[j+1] = temp;
       }
    }
  }

  for(int x = 0; x < NUM; x++)
  {
      cout << arr[x] << " ";
  }

  return 0;
}