//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.length(), MOD = 1e9 +7;
	    vector<int> dp(n + 1), last(26, -1);
	    dp[0] = 1;
	    
	    for (int i = 1; i <= n; i++)
	    {
	        dp[i] = (dp[i - 1] << 1LL) % MOD;
	        
	        if (last[s[i - 1] - 'a'] != -1)
	        {
	            dp[i] -= dp[last[s[i - 1] - 'a']];
	            dp[i] += MOD;
	            dp[i] %= MOD;
	        }
	        
	        last[s[i - 1] - 'a'] = i - 1;
	    }
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends