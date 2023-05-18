//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> ans (n, vector<int> (m, 0));
	    vector<vector<bool>> vis (n, vector<bool> (m, false));
	    
	    queue<vector<int>> q;
	    
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < m; j++)
	        {
	            if (grid[i][j])
	            {
	                q.push({i, j, 0});
	                vis[i][j] = true;
	            }
	        }
	    }
	    
	    while (!q.empty())
	    {
	        auto it = q.front();
	        int x = it[0], y = it[1], dist = it[2];
	        q.pop();
	        
	        ans[x][y] = dist;
	        
	        for (int i = 0; i < 4; i++)
	        {
	            int newx = x + dx[i];
	            int newy = y + dy[i];
	            
	            if (newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy])
	            {
	                vis[newx][newy] = true;
	                q.push({newx, newy, dist + 1});
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends