//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int patLen = pat.length();
            string s = pat + "$" + txt;
            int n = s.size();
            
            vector<int> z(n, 0);
            
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
            
            vector<int> ans;
            
            for (int i = 1; i < n; i++)
            {
                if (z[i] == patLen)
                    ans.emplace_back(i - patLen);
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends