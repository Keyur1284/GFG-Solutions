//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void expand (int left, int right, int &n, string &ans, string &s)
    {
        while (left >= 1 && right <= n && s[left] == s[right])
        {
            left--;
            right++;
        }

        int len = right - left - 1;

        if (ans.size() < len)
            ans = s.substr(left + 1, len); 
    }
  
    string longestPalin (string s) {
        
        int n = s.size();
        s = '!' + s;
        string ans = "";

        for (int i = 1; i <= n; i++)
        {
            expand(i, i, n, ans, s);
            expand(i, i + 1, n, ans, s);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends