//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve (int start, int len, vector<vector<bool>> &dp, vector<int> &cost, string &s)
    {
        if (start == len)
            return 0;
            
        if (cost[start] != -1)
            return cost[start];
            
        int minCost = INT_MAX;
        
        for (int end = start; end < len; end++)
        {
            if (s[end] == s[start] && (end - start <= 2 || dp[start + 1][end - 1]))
            {
                dp[start][end] = true;
                int currcost = 1 + solve (end + 1, len, dp, cost, s);
                minCost = min(currcost, minCost);
            }
        }
        
        return cost[start] = minCost;
    }

    int palindromicPartition(string &str)
    {
        int len = str.length();
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        vector<int> cost(len, -1);
        
        return solve (0, len, dp, cost, str) - 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends