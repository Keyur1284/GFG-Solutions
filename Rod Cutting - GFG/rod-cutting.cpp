//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int cutRod(int price[], int n) {
        
        vector<int> dp (n + 1, 0);

        for (int index = 0; index < n; index++)
        {
            int rodLength = index + 1;
            vector<int> temp (n + 1, 0);
            
            for (int k = 1; k <= n; k++)
            {
                if (index == 0)
                {
                    temp[k] = k * price[index];
                    continue;
                }
                
                int notCut = 0 + dp[k];
                int cut = INT_MIN;
                
                if (rodLength <= k)
                    cut = price[index] + temp[k - rodLength];
                    
                temp[k] = max(cut, notCut);
            }
            
            dp = temp;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends