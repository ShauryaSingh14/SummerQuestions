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
    int st;
    int en;
    if(arr[s] <= k && arr[n-1] >= k){
       st = s;
       en = n-1;
    }
    else{
       st = 0;
       en = s-1;
    }    
    while(st <= en){
        int mid = st + (en - st)/2;
        if(arr[mid]==k)
            return mid;
        else if (arr[mid]<k)
            st = mid +1;
        else 
            en = mid -1;
    }
    return -1; 
}


int main(){
    return 0;
}
