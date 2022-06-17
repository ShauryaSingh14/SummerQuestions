#include <iostream>
#include <vector>
using namespace std;
int firstOcc(vector <int> &arr, int k){
    int s = 0;
    int e = arr.size()-1;
    int ans = -1 ;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==k){
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid]>k)
            e = mid -1;
        else 
            s = mid+1;
    }
    return ans;
}
int lastOcc(vector <int> &arr, int k){
    int s = 0;
    int e = arr.size()-1;
    int ans = -1 ;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==k){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid]>k)
            e = mid -1;
        else 
            s = mid+1;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair <int,int> pr ;
    pr.first = firstOcc(arr,k);
    pr.second = lastOcc(arr,k);
    return pr;
}
int main(){
    return 0;
}