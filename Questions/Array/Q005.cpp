// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void moveNeg(int arr[], int n){
    int j = -1;
    for(int i = 0 ; i< n ;i++){
        if(arr[i]<0){
            j++;
            swap(arr[i],arr[j]);
        }
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
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveNeg(arr, n);
    printArray(arr, n);
    return 0;
}