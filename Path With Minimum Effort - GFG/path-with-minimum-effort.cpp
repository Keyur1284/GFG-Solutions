//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    int MinimumEffort(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort (n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> BFS;
        
        BFS.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!BFS.empty())
        {
            auto it = BFS.top();
            int currEffort = it.first;
            int x = it.second.first;
            int y = it.second.second;
            BFS.pop();
            
            if (x == n - 1 && y == m - 1)
                return currEffort;

            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if (newx >= 0 && newx < n && newy >= 0 && newy < m)
                {
                    int newEffort = max(currEffort, abs(heights[newx][newy] - heights[x][y]));

                    if (newEffort < effort[newx][newy])
                    {
                        effort[newx][newy] = newEffort;
                        BFS.push({newEffort, {newx, newy}});
                    }
                }
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends