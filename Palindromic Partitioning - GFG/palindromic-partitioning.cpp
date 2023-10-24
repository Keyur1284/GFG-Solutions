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
    
    int func (int i, int n, vector <int> &dp, string &s)
    {
        if (i == n)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int mini = INT_MAX;
        
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                int cost = 1 + func (j + 1, n, dp, s);
                mini = min (mini, cost);
            }
        }
        
        return dp[i] = mini;
    }

    int palindromicPartition(string s)
    {
        int n = s.size();
        vector <int> dp (n, -1);
        
        return func (0, n, dp, s) - 1;
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