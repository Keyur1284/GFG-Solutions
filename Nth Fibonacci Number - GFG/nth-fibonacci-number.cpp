//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        
        int prev2 = 0, prev = 1;
        int MOD = 1e9 + 7;
            
        for (int i = 2; i <= n; i++)
        {
            int curr = (prev + prev2) % MOD;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends