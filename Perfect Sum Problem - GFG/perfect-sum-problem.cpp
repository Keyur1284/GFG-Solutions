//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
    int MOD = 1e9 + 7;
    
    int solve (int index, int sum, vector<vector<int>> &dp, int arr[])
    {
        if (index == 0)
        {
            if (sum == 0 && arr[index] == 0)
                return 2;
            
            if (sum == 0 || arr[index] == sum)
                return 1;
            
            else
                return 0;
        }
            
        if (dp[index][sum] != -1)
            return dp[index][sum];
            
        int take = 0;
        int notTake = solve(index - 1, sum, dp, arr) % MOD;
        
        if (arr[index] <= sum)
            take = solve(index - 1, sum - arr[index], dp, arr) % MOD;
            
        return dp[index][sum] = (take + notTake) % MOD;
    }
    
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return solve(n - 1, sum, dp, arr);
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends