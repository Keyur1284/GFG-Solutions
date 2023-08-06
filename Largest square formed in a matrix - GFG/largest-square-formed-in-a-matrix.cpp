//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve (int x, int y, int n, int m, vector<vector<int>> &dp, vector<vector<int>>& matrix)
    {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return 0;

        if (dp[x][y] != -1)
            return dp[x][y];

        if (matrix[x][y] == 0)
            return dp[x][y] = 0;

        int up = solve (x - 1, y, n, m, dp, matrix);
        int left = solve (x, y - 1, n, m, dp, matrix);
        int leftD = solve (x - 1, y - 1, n, m, dp, matrix);

        return dp[x][y] = 1 + min({up, left, leftD});
    }

    int maxSquare(int n, int m, vector<vector<int>> &matrix){
        
        vector<vector<int>> dp (n, vector<int> (m, -1));
        int maxSide = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (matrix[row][col])
                {
                    int side = solve (row, col, n, m, dp, matrix);
                    maxSide = max(maxSide, side);
                }
            }
        }

        return maxSide;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends