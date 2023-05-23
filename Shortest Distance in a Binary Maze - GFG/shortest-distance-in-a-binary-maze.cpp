//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist (n, vector<int> (m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> BFS;

        BFS.push({0, source});
        dist[source.first][source.second] = 0;
        
        while (!BFS.empty())
        {
            auto it = BFS.top();
            int steps = it.first;
            int x = it.second.first;
            int y = it.second.second;
            BFS.pop();
            
            if (it.second == destination)
                return steps;
                
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy])
                {
                    if (steps + 1 < dist[newx][newy])
                    {
                        dist[newx][newy] = steps + 1;
                        BFS.push({dist[newx][newy], {newx, newy}});
                    }
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends