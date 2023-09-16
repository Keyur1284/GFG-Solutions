//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    
    int MOD = 1e9 + 7;
    
    long long solve (int index, int n, vector<long long> &dp)
    {
        if (index == n)
            return 1;
            
        if (dp[index] != -1)
            return dp[index];
            
        long long ways = 0;
        
        for (int i = 1; i <= 3; i++)
        {
            if (index + i <= n)
            {
                ways += solve(index + i, n, dp);
                ways %= MOD;
            }
            
            else
                break;
        }
        
        return dp[index] = ways;
    }
    
    long long countWays(int n)
    {
        vector<long long> dp(n + 5, -1);
        return solve(0, n, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends