//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    bool reachedDestination (int x, int y, int X, int Y)
    {
        return (x == X && y == Y);
    }
    
    int shortestDistance(int n, int m, vector<vector<int>> &A, int X, int Y) {
        
        if (A[0][0] == 0 || A[X][Y] == 0)
            return -1;
            
        if (reachedDestination(0, 0, X, Y))
            return 0;
        
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        vector<vector<bool>> vis (n, vector<bool> (m, false));
        queue<pair<int, int>> BFS;
        BFS.emplace(0, 0);
        vis[0][0] = true;
        int steps = 1;
        
        while(!BFS.empty())
        {
            int size = BFS.size();
            
            while(size--)
            {
                auto it = BFS.front();
                BFS.pop();
                int x = it.first, y = it.second;
                
                for (int dir = 0; dir < 4; dir++)
                {
                    int newx = x + dx[dir], newy = y + dy[dir];
                    
                    if (isValid(newx, newy, n, m) && A[newx][newy] && !vis[newx][newy])
                    {
                        if (reachedDestination(newx, newy, X, Y))
                            return steps;
                            
                        BFS.emplace(newx, newy);
                        vis[newx][newy] = true;
                    }
                        
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends