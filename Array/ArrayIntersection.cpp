#include <iostream>
#include <vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector <int> ans;
    int size = (arr1.size()>arr2.size())?arr1.size():arr2.size();
    int ptr1=0;
    int ptr2=0;
    while(ptr1< arr1.size() && ptr2 < arr2.size()) {
        if(arr1[ptr1]==arr2[ptr2]){
          ans.push_back(arr1[ptr1]);
            ptr1++;
            ptr2++;
        }
        else if(arr1[ptr1]>arr2[ptr2])
            ptr2++;
        else
            ptr1++;
    }
    
    if (ans.size()==0 )
        ans.push_back(-1);
    
    return ans;
}
int main(){
    return 0;
}
