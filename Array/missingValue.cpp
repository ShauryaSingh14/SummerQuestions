#include <iostream>
#include <vector>

using namespace std;
class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        
        int arrSum =0;
        int nSum = 0;
        for(int i = 0 ; i< array.size();i++){
            arrSum += array[i];
        }
        for(int i = 0 ; i<=n ; i++){
            nSum = nSum + i;
        }
        
        int missingNum = nSum - arrSum;
        return missingNum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  