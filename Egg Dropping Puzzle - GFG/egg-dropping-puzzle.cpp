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
            
        int ans = INT_MAX;
        
        int low = 1, high = k, mid;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            int left = solve (n - 1, mid - 1, dp);
            int right = solve (n, k - mid, dp);
            
            if (left < right)
                low = mid + 1;
                
            else
                high = mid - 1;
                
            int steps = 1 + max(left, right);
            ans = min(ans, steps);
        }
        
        return dp[n][k] = ans;
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