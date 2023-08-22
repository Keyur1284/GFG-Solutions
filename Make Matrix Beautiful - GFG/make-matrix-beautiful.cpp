//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> &matrix, int n)
    {
        int maxSum = 0; 
        vector<int> sums;
        
        for (int i = 0; i < n; i++)
        {
            int rowSum = 0, colSum = 0;
            
            for (int j = 0; j < n; j++)
            {
                colSum += matrix[j][i];
                rowSum += matrix[i][j];
            }
            
            maxSum = max({maxSum, rowSum, colSum});
            sums.emplace_back(rowSum);
        }
        
        int ops = 0;
        
        for (auto &it : sums)
            ops += maxSum - it;
            
        return ops;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends