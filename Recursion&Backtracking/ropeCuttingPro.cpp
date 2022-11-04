// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int ropeCutting(int n , int a, int b, int c){
    if(n < 0)
    return 0;
    if(n == 0)
    return 1;
    return ropeCutting(n-a,a,b,c) + ropeCutting(n-b,a,b,c) + ropeCutting(n-c,a,b,c);    
}

void RopeCu(int n, int a, int b, int c,int &count){ // My Try
    if(n <= 0){
        
        if(n == 0)
        count ++;
        
        return ;
    }
    RopeCu(n-a,a,b,c,count);
    RopeCu(n-b,a,b,c,count);
    RopeCu(n-c,a,b,c,count);
} 

int main() {
    cout << ropeCutting(5,2,5,1);
    cout << endl;
  
    return 0;
}