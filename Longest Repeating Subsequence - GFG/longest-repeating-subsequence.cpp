//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    
       int LongestRepeatingSubsequence(string str){
		    
		    int n = str.length();
		    vector<int> dp (n + 1, 0);
		    
		    for (int i = n - 1; i >= 0; i--)
		    {
		        vector<int> curr (n + 1, 0);
		        
		        for (int j = n - 1; j >= 0; j--)
		        {
		            if (str[i] == str[j] && i != j)
		            {
		                curr[j] = 1 + dp[j + 1];
		            }
		            
		            else
		            {
		                curr[j] = max(dp[j], curr[j + 1]);
		            }
		        }
		        
		        dp = curr;
		    }
		    
		    return dp[0];
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