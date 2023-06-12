//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int solve (int index, int n, vector<vector<int>> &dp, int price[])
    {
        if (index == 0)
            return n * price[index];
            
        if (dp[index][n] != -1)
            return dp[index][n];
            
        int notCut = 0 + solve (index - 1, n, dp, price);
        int cut = INT_MIN;
        int rodLength = index + 1;
        
        if (rodLength <= n)
            cut = price[index] + solve (index, n - rodLength, dp, price);
            
        return dp[index][n] = max (cut, notCut);
    }
  
    int cutRod(int price[], int n) {
        
        vector<vector<int>> dp (n, vector<int> (n + 1, -1));
        return solve (n - 1, n, dp, price);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends