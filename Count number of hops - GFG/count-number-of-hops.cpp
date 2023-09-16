//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    
    int MOD = 1e9 + 7;
    
    long long countWays(int n)
    {
        vector<long long> dp(n + 5, 0);
        dp[n] = 1;
        
        for (int index = n - 1; index >= 0; index--)
        {
            long long ways = 0;
            
            for (int steps = 1; steps <= 3; steps++)
            {
                if (index + steps <= n)
                {
                    ways += dp[index + steps];
                    ways %= MOD;
                }
                
                else
                    break;
            }
            
            dp[index] = ways;
        }
        
        return dp[0];
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