//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long MOD = 1e9 + 7;
    
    long long modPower (long long base, long long exp)
    {
        long long ans = 1;
        
        while (exp)
        {
            if (exp & 1)
                ans = (1LL * ans * base) % MOD;
                
            exp >>= 1;
            base = (1LL * base * base) % MOD;
        }
        
        return ans;
    }
    
    long long modInv(long long num)
    {
        return modPower(num, MOD - 2);
    }
    
    long long  numberOfPaths(int m, int n)
    {
        long long ways = 1;
        
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
        {
            ways = (ways * i) % MOD;
            ways = (ways * modInv(j)) % MOD;
        }
        
        return ways;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends