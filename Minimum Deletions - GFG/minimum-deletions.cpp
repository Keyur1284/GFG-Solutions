//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve (int left, int right, vector<vector<int>> &dp, string &s)
    {
        if (left >= right)
            return 0;
            
        if (dp[left][right] != -1)
            return dp[left][right];
        
        int ans;
            
        if (s[left] == s[right])
            ans = solve(left + 1, right - 1, dp, s);
            
        else
            ans = 1 + min(solve(left + 1, right, dp, s), solve(left, right - 1, dp, s));
            
        return dp[left][right] = ans;
    }
  
    int minimumNumberOfDeletions(string s) { 
        
        int n = s.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));
        
        return solve (0, n - 1, dp, s);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends