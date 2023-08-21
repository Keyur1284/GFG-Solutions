//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    bool isValid (int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    int Count(vector<vector<int> >& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
        int ones = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j])
                {
                    int zeroes = 0;
                    
                    for (int k = 0; k < 8; k++)
                    {
                        int newi = i + dx[k], newj = j + dy[k];
                        zeroes += (isValid(newi, newj, n, m) && matrix[newi][newj] == 0);
                    }
                    
                    ones += (zeroes > 0 && zeroes % 2 == 0);
                }
            }
        }
        
        return ones;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends