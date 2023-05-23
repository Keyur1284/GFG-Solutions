//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        
        int n = s.size();
        string st = string(2 * n + 1, '!');

        for (int i = 0; i < n; i++)
        {
            st[2 * i + 1] = s[i];
        }

        vector<int> pal(2 * n + 1, 0);
        int longestLength = 0, longestCenter = 0, center = 0, right = 0;
        
        for (int i = 0; i < 2 * n + 1; i++)
        {
            int mirror = 2 * center - i;
            
            if (right - i > 0)
            {
                pal[i] = min(right - i, pal[mirror]);
            }
            
            int l = i - pal[i] - 1;
            int r = i + pal[i] + 1;
            
            while (l >= 0 && r < 2 * n + 1 && st[l] == st[r])
            {
                l--;
                r++;
                pal[i]++;
            }
            
            if (pal[i] > longestLength)
            {
                longestLength = pal[i];
                longestCenter = i;
            }
            
            if (i + pal[i] > right)
            {
                right = i + pal[i];
                center = i;
            }
        }
        
        string ans = "";
        
        for (int index = longestCenter - longestLength + 1; index < longestCenter + longestLength; index += 2)
            ans += st[index];
            
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