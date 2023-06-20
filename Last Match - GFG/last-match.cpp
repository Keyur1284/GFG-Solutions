//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string s,string t){
        
        int n = s.size(), m = t.size(), ans = -1;
        
        vector<int> lps(m, 0);
        int len = 0;
        
        for (int i = 1; i < m;)
        {
            if (t[len] == t[i])
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
        
        for (int i = 0, j = 0; i < n;)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
                
                if (j == m)
                {
                    ans = i - j + 1;
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
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends