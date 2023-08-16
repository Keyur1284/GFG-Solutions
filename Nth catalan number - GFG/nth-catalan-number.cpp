//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int MOD = 1e9 + 7;
    
    int modPow (int base, int exp)
    {
        int ans = 1;
        
        while (exp)
        {
            if (exp & 1)
                ans = (1LL * ans * base) % MOD;
                
            exp >>= 1;
            base = (1LL * base * base) % MOD;
        }
        
        return ans;
    }

    int modInv (int num)
    {
        return modPow(num, MOD - 2); 
    }
    
    int findCatalan(int n) 
    {
        vector<int> fact(2 * n + 1);
        fact[0] = 1;
        
        for (int i = 1; i <= 2 * n; i++)
        {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
        }
        
        int catalan = fact[2 * n];
        catalan = (1LL * catalan * modInv(fact[n + 1])) % MOD;
        catalan = (1LL * catalan * modInv(fact[n])) % MOD;
        
        return catalan;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends