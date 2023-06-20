//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        
        int m = str.size();
        
        string s = str + "$";
        reverse(str.begin(), str.end());
        s += str;
        
        int n = s.size();
        
        vector<int> z (n, 0), lps(n, 0);
        
        int left = 0, right = 0;
		
		for (int i = 1; i < n; i++)
		{
			if (right - i > 0)
				z[i] = min(right - i, z[i - left]);
				
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				z[i]++;
				
			if (i + z[i] > right)
			{
				left = i;
				right = i + z[i];
			}
		}
		
		for (int i = 1; i < n; i++)
                lps[i + z[i] - 1] = max(lps[i + z[i] - 1], z[i]);
		
		return m - lps.back();
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends