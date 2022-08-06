#include <iostream>
using namespace std;
void rotateByOne(int arr[],int n){
    int temp = arr[n-1];
    for(int i = n-1 ;i<0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}
int main(){
    return 0;
}