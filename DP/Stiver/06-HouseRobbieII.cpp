#include <bits/stdc++.h> 
long long int spaceOpt(int n ,vector<int> nums){
    long long int prev2 = 0;
    long long int prev = nums[0];
    
    for(int i = 1 ; i< n+1; i++){
        long long int pick = nums[i] + prev2;
        long long int notPick = prev;
        
        prev2 = prev;
        prev = max(pick,notPick);
    }
    return prev;
}

// some Approch as in prev Question(MAX sum of non Adj elements) 
// just change in main function of code

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();

    if(n==1) // for edge case
        return valueInHouse[n-1];
    
    vector<int> temp1,temp2;

    for(int i =0 ; i< n ;i++){
        if(i != 0)
            temp1.push_back( valueInHouse[i]); // array without first element
        if( i != n-1)
            temp2.push_back(valueInHouse[i]); // array without last element
    }
    
    long long int res = max(spaceOpt(n-2,temp1),spaceOpt(n-2,temp2));
    
    return res;
}