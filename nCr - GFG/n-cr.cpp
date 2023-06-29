//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int MOD = 1e9 + 7;

    int mod_power (int base, int exp)
    {
        long long res = 1;
        
        while (exp)
        {
            if (exp & 1)
                res = (1LL * res * base) % MOD;
            
            exp /= 2;
            base = (1LL * base * base) % MOD;
        }
        
        return res;
    }
    
    int mod_inverse (int num)
    {
        return mod_power(num, MOD - 2);
    }

    int nCr(int n, int r){
        
        if (r > n)
            return 0;
        
        vector<int> fact(1001);
        fact[0] = 1;
        
        for (int i = 1; i <= 1000; i++)
            fact[i] = (1LL * i * fact[i - 1]) % MOD;
            
        int ans = (1LL * fact[n] * mod_inverse(fact[n - r])) % MOD;
        ans = (1LL * ans * mod_inverse(fact[r])) % MOD;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends