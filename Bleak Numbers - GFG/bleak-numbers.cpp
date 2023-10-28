//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    int start = n - ceil(log2(n));
	    
	    for (int i = start; i < n; i++)
	    {
	        int setBits = __builtin_popcount(i);
	        
	        if (n == i + setBits)
	            return 0;
	    }
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends