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
        
        vector<int> lps (n, 0);
        int len = 0;
        
		for (int i = 1; i < n; )
		{
			if (s[i] == s[len])
			{
				len++;
				lps[i] = len;
				i++;
			}
			
			else
			{
				if (len == 0)
					i++;
					
				else
					len = lps[len - 1];
			}
		}
		
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