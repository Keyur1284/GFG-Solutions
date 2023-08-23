//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
    int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
    
    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    
    void DFS (int x, int y, int startX, int startY, int index, int len, int n, int m, int dir, vector<vector<char>>& grid, string &word, set<vector<int>> &st)
    {
        if (index == len)
        {
            st.insert({startX, startY});
            return;
        }
        
        int newx = x + dx[dir];
        int newy = y + dy[dir];
        
        if (isValid(newx, newy, n, m) && grid[newx][newy] == word[index] && st.find({startX, startY}) == st.end())
            DFS (newx, newy, startX, startY, index + 1, len, n, m, dir, grid, word, st);
    }

	vector<vector<int>>searchWord(vector<vector<char>>& grid, string &word){
	    
	    int n = grid.size(), m = grid[0].size();
	    set<vector<int>> indices;
	    
	    int len = word.length();
	    
	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < m; j++)
	        {
	            if (grid[i][j] == word[0] && indices.find({i, j}) == indices.end())
	            {
	                for (int k = 0; k < 8; k++)
	                {
	                    DFS (i, j, i, j, 1, len, n, m, k, grid, word, indices);
	                }
	            }
	        }
	    }
	    
	    vector<vector<int>> found (indices.begin(), indices.end());
	    return found;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends