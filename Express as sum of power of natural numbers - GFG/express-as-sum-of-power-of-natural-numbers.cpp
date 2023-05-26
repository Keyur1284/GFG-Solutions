//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution{
    public:
    
    int MOD = 1e9 + 7;
    
    long long mod_power (long long base, long long exp)
    {
        long long res = 1;
        
        while (exp)
        {
            if (exp % 2)
                res = (res * base) % MOD;
                
            exp /= 2;
            base = (base * base) % MOD;
        }
        
        return res;
    }
    
    
    int numOfWays(int n, int x)
    {
        vector<int> powers;
        
        for (int base = 1; ; base++)
        {
            int value = mod_power(base, x);
            
            if (value > n)
                break;
            
            powers.emplace_back(value);
        }
            
        int size = powers.size();
        vector<int> dp (n + 1, 0);
        dp[0] = 1;
        
        for (int base = 0; base < size; base++)
        {
            vector<int> temp (n + 1, 0);
            
            for (int sum = 0; sum <= n; sum++)
            {
                int take, notTake;
                
                take = 0;
                notTake = dp[sum];
                
                if (sum >= powers[base])
                    take = dp[sum - powers[base]];
                    
                temp[sum] = (take + notTake) % MOD;
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
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends