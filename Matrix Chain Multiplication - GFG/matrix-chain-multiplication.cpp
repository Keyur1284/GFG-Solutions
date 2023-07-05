//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve (int left, int right, vector<vector<int>> &dp, int arr[])
    {
        if (left == right)
            return 0;
            
        if (dp[left][right] != -1)
            return dp[left][right];
            
        int minCost = INT_MAX;
            
        for (int k = left; k < right; k++)
        {
            int cost = arr[left - 1] * arr[k] * arr[right] + solve (left, k, dp, arr) + solve (k + 1, right, dp, arr);
            minCost = min(cost, minCost);
        }
        
        return dp[left][right] = minCost; 
    }

    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp (n, vector<int> (n, -1));
        
        return solve (1, n - 1, dp, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends