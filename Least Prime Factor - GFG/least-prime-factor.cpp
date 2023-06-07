//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        
        vector<int> factors (n + 1);
        iota (factors.begin(), factors.end(), 0);

        for (int p = 2; p * p <= n; p++)
        {
            if (factors[p] == p)
            {
                for (int i = p * p; i <= n; i += p)
                {
                    if (factors[i] == i)
                        factors[i] = p;
                }
            }
        }
        
        return factors;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends