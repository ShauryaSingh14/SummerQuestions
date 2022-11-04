// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
     cout << "Enter the N: ";
    cin>> N;
    vector<int> v[N];
    // INPUT 
    for(int i =0 ; i< N ;i++){ // no. of vectors 
        cout << "Enter the size of vector"<<i <<" : ";
        int n ;
        cin >> n ;
        for(int j =0 ; j<n;j++){
    
            int x;
            cin>> x; // element want to insert into the vector
            v[i].push_back(x);
        }
    }
    cout << "Output"<<endl;
    //OutPut 
    for(auto i : v){
        for(auto j : i){
            cout << j<<" ";
        }
        cout << endl;
    }
    
    return 0;
}