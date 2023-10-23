//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
	    
	    for (int index = n - 1; index >= 0; index--)
	    {
	        for (int prev = index - 1; prev >= -1; prev--)
	        {
	            int notTake = dp[index + 1][prev + 1];
	            int take = 0;
	            
	            if (prev == -1 || arr[index] > arr[prev])
	                take = arr[index] + dp[index + 1][index + 1];
	                
	            dp[index][prev + 1] = max(take, notTake);
	        }
	    }
	    
	    return dp[0][-1 + 1];
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