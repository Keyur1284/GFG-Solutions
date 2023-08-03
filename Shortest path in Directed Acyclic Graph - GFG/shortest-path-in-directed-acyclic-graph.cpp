//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        
        for (int i = 0; i < N - 1; i++)
        {
            for (auto &it : edges)
            {
                if (dist[it[0]] != 1e9 && dist[it[0]] + it[2] < dist[it[1]])
                    dist[it[1]] = dist[it[0]] + it[2];
            }
        }
        
        for (auto &it : dist)
        {
            if (it == 1e9)
                it = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends