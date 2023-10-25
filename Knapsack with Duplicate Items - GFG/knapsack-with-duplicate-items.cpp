//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve (int index, int tar, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (index == -1)
            return 0;
            
        if (dp[index][tar] != -1)
            return dp[index][tar];
            
        int take = 0;
        
        if (tar >= wt[index])
            take += val[index] + solve(index, tar - wt[index], val, wt, dp);
            
        int notTake = solve(index - 1, tar, val, wt, dp);
        
        return dp[index][tar] = max(take, notTake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp (N, vector<int> (W + 1, -1));
        
        return solve (N - 1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends