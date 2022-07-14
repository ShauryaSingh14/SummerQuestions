// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void rvereseArray(int arr[], int n){
   int i = 0;
   int j = n-1;
   while(i<j){
       swap(arr[i],arr[j]);
       i++;
       j--;
   }
}
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
 
   cout << endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
     
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // To print original array
    printArray(arr, n);
     
    // Function calling
    rvereseArray(arr, n);
     
    cout << "Reversed array is" << endl;
     
    // To print the Reversed array
    printArray(arr, n);
     
    return 0;
}