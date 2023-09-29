//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    
    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    void DFS (int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        vis[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isValid(newx, newy, n, m) && grid[newx][newy] && !vis[newx][newy])
                DFS (newx, newy, n, m, vis, grid);
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 || i == n - 1 || j == m - 1) && grid[i][j] && !vis[i][j])
                    DFS (i, j, n, m, vis, grid);
            }
        }
        
        int enclaves = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !vis[i][j])
                    enclaves++;
            }
        }
        
        return enclaves;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends