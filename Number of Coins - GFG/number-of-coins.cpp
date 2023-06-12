//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve (int index, int val, vector<vector<int>> &dp, int coins[])
	{
	    if (index == 0)
	    {
	        if (val % coins[index] == 0)
	            return val/coins[index];
	            
	        else
	            return 1e9;
	    }
	    
	    if (dp[index][val] != -1)
	        return dp[index][val];
	    
	    int notTake = 0 + solve (index - 1, val, dp, coins);
	    int take = INT_MAX;
	    
	    if (coins[index] <= val)
	        take = 1 + solve (index, val - coins[index], dp, coins);
	        
	    dp[index][val] = min (take, notTake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp (M, vector<int> (V + 1, -1));
	    int ans = solve (M - 1, V, dp, coins);
	    
	    if (ans >= 1e9)
	        return -1;
	        
	   return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends