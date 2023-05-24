//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    
	    int n = matrix.size(), inf = INT_MAX;

	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < n; j++)
	        {
	            if (matrix[i][j] == -1)
	                matrix[i][j] = inf;
	        }
	    }

	    for (int via = 0; via < n; via++)
	    {
	        for (int i = 0; i < n; i++)
    	    {
    	        for (int j = 0; j < n; j++)
    	        {
					if (matrix[i][via] < inf && matrix[via][j] < inf && matrix[i][via] + matrix[via][j] < inf)
    	            	matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
    	        }
    	    }
	    }

        // For detection of negative cycle, we have to write following code

        /*
            bool checkNegativeCycle (vector<vector<int>>&matrix)
            {
                int n = matrix.size();

                for (int node = 0; node < n; node++)
                {
                    if (matrix[node][node] < 0)
                        return true;
                }

                return false
            }
        */

	    for (int i = 0; i < n; i++)
	    {
	        for (int j = 0; j < n; j++)
	        {
	            if (matrix[i][j] == inf)
	                matrix[i][j] = -1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends