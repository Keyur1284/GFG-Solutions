//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int expand (int left, int right, int &n, string &s)
    {
        while (left >= 1 && right <= n && s[left] == s[right])
        {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
  
    string longestPalin (string s) {
        
        int n = s.size(), start = 1, end = 1, len = 1;
        s = '!' + s;
        
        for (int i = 1; i <= n; i++)
        {
            int len1 = expand(i, i, n, s);
            int len2 = expand(i, i + 1, n , s);
            
            len = max(len1, len2);
            
            if (len > end - start + 1)
            {
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }
        
        return s.substr(start, end - start + 1);
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