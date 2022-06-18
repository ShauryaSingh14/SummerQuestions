// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int getPivot(int arr[],int n){
    int s = 0 ;
    int e = n - 1;
    while(s < e){
        int mid = s + (e - s )/2;
        if(arr[0]<=arr[mid])
            s = mid+1;
        else{
            e = mid;
        }
    }
    return s;
}
int main() {
    int arr[] = {5,7,1,2,4};
    int size = sizeof(arr)/sizeof(int);
    cout <<"Index of Pivot element " <<getPivot(arr,size) << endl;
    return 0;
}