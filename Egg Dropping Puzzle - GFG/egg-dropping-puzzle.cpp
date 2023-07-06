//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int solve (int n, int k, vector<vector<int>> &dp)
    {
        if (n == 1 || k <= 1)
            return k;
        
        if (dp[n][k] != -1)
            return dp[n][k];
            
        int steps = INT_MAX;
        
        for (int flr = 1; flr <= k; flr++)
        {
            int ans = 1 + max(solve (n - 1, flr - 1, dp), solve (n, k - flr, dp));
            steps = min(ans, steps);
        }
        
        return dp[n][k] = steps;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp (n + 1, vector<int> (k + 1, -1));
        
        return solve (n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends