//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void DFS (int x, int y, int N, int M, vector<vector<bool>> &vis, vector<vector<int>>& matrix)
    {
        vis[x][y] = true;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (newx < N && newx >= 0 && newy < M && newy >= 0 && matrix[newx][newy] == 1 && !vis[newx][newy])
                DFS (newx, newy, N, M, vis, matrix);
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        
        vector<vector<bool>> vis (N, vector<bool> (M, false));
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((i * j == 0 || i == N - 1 || j == M - 1) && (matrix[i][j] && !vis[i][j]))
                    DFS (i, j, N, M, vis, matrix);
            }
        }
        
        int count = 0;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j] && !vis[i][j])
                {
                    DFS (i, j, N, M, vis, matrix);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends