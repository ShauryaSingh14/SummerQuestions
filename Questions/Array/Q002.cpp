// Online C++ compiler to run C++ program online
#include <iostream>
#include <utility>
using namespace std;
pair<int,int> getMinMax(int arr[],int n){
    pair<int,int> pr;
    pr.first = arr[0];
    pr.second = arr[0];
    
    for(int i = 1 ;i<n;i++){
        
        if(pr.first > arr[i])
        pr.first = arr[i];
        
        if(pr.second < arr[i])
        pr.second = arr[i];
        
    }
    return pr;
}
int main() 
{
    int arr[] = { 1000, 11, 445, 
                  1, 330, 3000 };
    int arr_size = 6;
      
    pair<int,int> minmax = getMinMax(arr, arr_size);
      
    cout << "Minimum element is " 
         << minmax.first << endl;
    cout << "Maximum element is " 
         << minmax.second;
           
    return 0;
} 
  

  