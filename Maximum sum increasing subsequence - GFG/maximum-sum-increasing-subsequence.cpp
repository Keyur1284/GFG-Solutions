//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n);
	    
	    for (int i = 0; i < n; i++)
	        dp[i] = arr[i];
	    
	    int maxi = 0;
	    
	    for (int index = 0; index < n; index++)
	    {
	        for (int prev = 0; prev < index; prev++)
	        {
	            if (arr[index] > arr[prev])
	                dp[index] = max(dp[index], arr[index] + dp[prev]);
	        }
	        
	        maxi = max(maxi, dp[index]);
	    }
	    
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends