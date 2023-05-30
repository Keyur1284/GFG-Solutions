//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    bool isValid (int &x, int &y, int &row, int &col)
    {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    
    bool DFS (int x, int y, int &n, int &m, int index, vector<vector<char>>& board, string &word)
    {
        if (index == word.size())
            return true;
            
        board[x][y] = '$';
        
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if (isValid(newx, newy, n, m) && board[newx][newy] == word[index])
            {
                if (DFS (newx, newy, n, m, index + 1, board, word))
                    return true;
            }
        }
        
        board[x][y] = word[index - 1];
        
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string &word) {
        
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    int index = 1;
                    
                    if (DFS (i, j, n, m, index, board, word))
                        return true;  
                }
                
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends