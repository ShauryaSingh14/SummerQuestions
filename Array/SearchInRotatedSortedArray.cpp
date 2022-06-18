#include <iostream>
#include <vector>
using namespace std;

int findPosition(vector<int>& arr, int n, int k)
{
    int s = 0 ;
    int e = n-1;
    while(s<e){
        int mid = s + (e - s)/2;
        if(arr[0]<=arr[mid])
            s = mid+1;
        else
            e = mid;
    }  
    int st1 = 0;
    int st2 = s;
    int en1 = s-1;
    int en2 = n-1;
    
    while(st1 <= en1){
        int mid = st1 + (en1 - st1)/2;
        if(arr[mid]==k)
            return mid;
        else if (arr[mid]<k)
            st1 = mid +1;
        else 
            en1 = mid -1;
    }
    while(st2 <=en2){
        int mid = st2 + (en2 - st2)/2;
        if(arr[mid]==k)
            return mid;
        else if (arr[mid]<k)
            st2 = mid +1;
        else 
            en2 = mid -1;
    }
    return -1; 
}
int main(){
    return 0;
}
