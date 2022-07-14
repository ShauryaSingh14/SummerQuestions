#include <iostream>
using namespace std;

int union(int arr2[],int n1, int arr2[],int n2){
    int ptr1 =0;
    int ptr2 =0;
    int i=0;
    int *arr = new int[n1+n2];
    while(ptr1<n1 && ptr2<n2){
        if(arr1[ptr1]<=arr2[ptr2]){
            arr[i]=arr1[ptr1];
            ptr1++;
        }
        else {
             arr[i]=arr2[ptr2];
            ptr2++;
        }
        i++;
    }
    return arr;
}
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
 
   cout << endl;
}
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    return 0;
}
