//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int solve (int index, int prev, int &n, vector<vector<int>> &dp, int arr[])
	{
	    if (index == n)
	        return 0;
	        
	    if (dp[index][prev + 1] != -1)
	        return dp[index][prev + 1];
	    
	    int notTake = solve (index + 1, prev, n, dp, arr);
	    int take = 0;
	         
	    if (prev == -1 || arr[index] > arr[prev])
	        take = arr[index] + solve (index + 1, index, n, dp, arr);
	        
	    return dp[index][prev + 1] = max(take, notTake);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp (n, vector<int> (n + 1, -1));
	    
	    return solve (0, -1, n, dp, arr);
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