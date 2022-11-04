#include <iostream>
#include <vector>
using namespace std;
bool checkP(string s,int l, int r){
    if(l>r)
    return true;

    if(s[l]!=s[r])
    return false;

    return checkP(s,l+1,r-1);
}
void reverse(int arr[],int n,int l){
    if(l<n){
         swap(arr[n-1],arr[l]);
         reverse(arr,n-1,l+1);
    }
}
int main(){
    int arr[]={2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    reverse(arr,n,0);
    return 0;
}