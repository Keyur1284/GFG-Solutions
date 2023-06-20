//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n = txt.size(), m = pat.size();
            
            vector<int> lps(m, 0);
            int len = 0;
            
            for (int i = 1; i < m; )
            {
                if (pat[i] == pat[len])
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
            
            vector<int> ans;
            
            for (int i = 0, j = 0; i < n; )
            {
                if (txt[i] == pat[j])
                {
                    i++;
                    j++;
                    
                    if (j == m)
                    {
                        ans.emplace_back(i - j + 1);
                        j = lps[j - 1];
                    }
                }
                
                else
                {
                    if (j == 0)
                        i++;
                        
                    else
                        j = lps[j - 1];
                }
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