//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	       
	   int solve (int i, int j, vector<vector<int>> &dp, string &str)
	   {
	       if (i < 0 || j < 0)
	           return 0;
	           
	       if (dp[i][j] != -1)
	           return dp[i][j];
	           
	       if (str[i] == str[j] && i != j)
	           return 1 + solve (i - 1, j - 1, dp, str);
	           
	       return dp[i][j] = max(solve(i, j - 1, dp, str), solve(i - 1, j, dp, str));
	   }
	    
       int LongestRepeatingSubsequence(string str){
		    
		    int n = str.length();
		    vector<vector<int>> dp (n, vector<int> (n, -1));
		    
		    return solve (n - 1, n - 1, dp, str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends