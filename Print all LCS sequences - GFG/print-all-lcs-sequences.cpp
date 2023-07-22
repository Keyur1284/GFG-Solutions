//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void findAllLCS (int inds, int indt, int n, int m, int maxLen, string path, string &s, string &t, unordered_set<string> &st)
    {
        if (path.length() == maxLen)
        {
            st.emplace(path);
            return;
        }
        
        for (int i = inds; i <= n; i++)
        {
            for (int j = indt; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    findAllLCS (i + 1, j + 1, n, m, maxLen, path + s[i - 1], s, t, st);
            }
        }
    }
    		
	vector<string> all_longest_common_subsequences(string &s, string &t)
	{
	    int n = s.length(), m = t.length();
	    vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
	    
	    for (int i = 1; i <= n; i++)
	    {
	        for (int j = 1; j <= m; j++)
	        {
	            if (s[i - 1] == t[j - 1])
	                dp[i][j] = 1 + dp[i - 1][j - 1];
	                
	            else
	                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	        }
	    }
	    
	    int longest = dp[n][m];
	    unordered_set<string> st;
	    
	    findAllLCS (1, 1, n, m, longest, "", s, t, st);
	    
	    vector<string> LCS;
	    
	    for (auto &str : st)
	        LCS.emplace_back(str);
	        
	    sort (LCS.begin(), LCS.end());
	    
	    return LCS;
	}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends