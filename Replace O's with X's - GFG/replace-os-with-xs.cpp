//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    void DFS (int x, int y, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &mat)
    {
        vis[x][y] = true;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx >= 0 && newx < n && newx >= 0 && newy < m && mat[newx][newy] == 'O' && !vis[newx][newy])
                DFS (newx, newy, n, m, vis, mat);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 || i == n - 1 || j == m - 1) && mat[i][j] == 'O' && !vis[i][j])
                    DFS (i, j, n, m, vis, mat);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends