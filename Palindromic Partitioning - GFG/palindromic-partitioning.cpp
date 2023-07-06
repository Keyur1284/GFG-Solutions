//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome (string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
    
    int solve (int start, int len, vector<int> &dp, string &s)
    {
        if (start == len)
            return 0;
            
        if (dp[start] != -1)
            return dp[start];
            
        int minCost = INT_MAX;
        
        for (int end = start; end < len; end++)
        {
            if (isPalindrome(s, start, end))
            {
                int cost = 1 + solve (end + 1, len, dp, s);
                minCost = min(cost, minCost);
            }
        }
        
        return dp[start] = minCost;
    }

    int palindromicPartition(string str)
    {
        int len = str.length();
        vector<int> dp(len, -1);
        
        return solve (0, len, dp, str) - 1;
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