#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long low, long long mid, long long high){
        long long n1 = mid- low +1;
        long long n2 = high - mid;
        
        long long left[n1];
        long long right[n2];
        
        long long int count =0;
        for(long long i = 0 ; i< n1; i++)
        left[i]= arr[i+low];
        
        for(long long i = 0 ; i< n2 ;i++)
        right[i] = arr[i+mid+1];
        
        int i =0, j=0, p = low;
        while( i<n1 && j<n2){
            if( left[i] <= right[j] ){
                arr[p] = left[i];
                i++;
            }
            else {
                arr[p] = right[j];
                j++;
                count = count + n1 -i;
            }
             p++;
        }
        while (i < n1 ){
            arr[p]=left[i];
            i++;
            p++;
        }
        while(j < n2){
            arr[p]=right[j];
            j++;
            p++;
        }
        return count;
    }
    long long int mergeSort(long long arr[], long long left, long long right){
        long long int count =0 ;
       
        if(left < right){
            long long mid = left + (right-left)/2;
            count += mergeSort(arr,left,mid);
            count += mergeSort(arr,mid+1, right);
            count += merge(arr, left, mid , right);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count = mergeSort(arr,0,N-1);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends