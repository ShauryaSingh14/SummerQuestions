// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;
int kthSmallest(int arr[], int n,int k){
   priority_queue <int> pq;
    for(int i =0 ; i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k)
        pq.pop();
    }
    return pq.top();
}
int main() {
    int arr[] = { 1000, 11, 445, 
                  1, 330, 3000 };
    int arr_size = 6;
    cout << kthSmallest(arr,6,3);

    return 0;
}