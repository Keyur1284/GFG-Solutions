//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    unordered_map<int, string> mp = {{0, "D"}, {1, "U"}, {2, "R"}, {3, "L"}};
    
    bool isValid (int x, int y, int n, vector<vector<int>> &grid)
    {
        return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y]);
    }
    
    void DFS (int x, int y, int n, string &path, vector<string> &paths, vector<vector<int>> &grid)
    {
        if (x == n - 1 && y == n - 1)
        {
            paths.emplace_back(path);
            return;
        }
        
        grid[x][y] = 0;
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (isValid(newx, newy, n, grid))
            {
                path += mp[i];
                DFS (newx, newy, n, path, paths, grid);
                path.pop_back();
            }
        }
        
        grid[x][y] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        
        string path = "";
        vector<string> paths;
        
    if (isValid (0, 0, n, grid))    
        DFS (0, 0, n, path, paths, grid);
        
        return paths;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends