//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> fact (n);
        fact[0] = 1;
        
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i;
        

        vector<bool> vis (n + 1, false);
        k--;
        string ans = "";
        
        for (int i = 1; i <= n; i++)
        {
            int rem = n - i;
            int up = k / fact[rem];
            
            int val = 1;
            
            while (1)
            {
                if (!vis[val])
                {
                    if (up == 0)
                        break;
                        
                    up--;
                }
                
                val++;
            }
            
            ans += val + '0';
            k = k % fact[rem];
            vis[val] = true;
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
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends