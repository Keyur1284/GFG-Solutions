//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            string ans = "";
            int len = s.length();
            
            for (int i = len - 1; i >= 0; )
            {
                string temp = "";
                    
                while (i >= 0 && s[i] >= '0' && s[i] <= '9')
                    temp += s[i--];
                    
                reverse(temp.begin(), temp.end());
                
                ans += temp;
                
                if (i >= 0)
                    ans += s[i--];
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
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends