//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    
    int solve (int i, int j, vector<vector<int>> &dp, string &s)
    {
        if (i > j)
            return 0;
        
        if (i == j)
            return 1;
            
        if (dp[i][j] != -1)
            return dp[i][j];
            
        if (s[i] == s[j])
            return dp[i][j] = 2 + solve (i + 1, j - 1, dp, s);
            
        return dp[i][j] = max(solve(i + 1, j, dp, s), solve(i, j - 1, dp, s));
    }
  
    int longestPalinSubseq(string A) {
        
        int len = A.length();
        vector<vector<int>> dp (len, vector<int> (len, -1));
        
        return solve (0, len - 1, dp, A);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends