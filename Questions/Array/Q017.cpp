// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& arr) {
        int profit = 0;
        int buy = arr[0];
        int sell = arr[0];
        
        for(int i = 1 ; i< arr.size();i++){
            if(arr[i] < buy)
                sell = buy = arr[i];
            else 
                sell = arr[i];
            
            profit = max(profit, sell - buy);
            
        }
        return profit;
    }
int main() {
    vector <int> arr ={7,1,5,3,6,4};
    cout << maxProfit(arr);

    return 0;
}