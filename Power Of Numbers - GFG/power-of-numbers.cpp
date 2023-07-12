//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    long long mod_power (int base, int exp)
    {
        long long MOD = 1e9 + 7;
        long long ans = 1;
        
        while (exp)
        {
            if (exp & 1)
                ans = (1LL * ans * base) % MOD;
                
            exp /= 2;
            base = (1LL * base * base) % MOD;
        }
        
        return ans;
    }
    
    long long power(int N,int R)
    {
       return mod_power(N, R);
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends