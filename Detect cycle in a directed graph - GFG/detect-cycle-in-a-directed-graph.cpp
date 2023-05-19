//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool checkCycle (int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[])
    {
        vis[node] = true;
        dfsVis[node] = true;
        
        for (auto &it : adj[node])
        {
            if (!vis[it])
                if (checkCycle(it, vis, dfsVis, adj))
                    return true;
                    
            if (vis[it] && dfsVis[it])
                return true;
        }
        
        dfsVis[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, false), dfsVis(V, false);
        
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (checkCycle(i, vis, dfsVis, adj))
                    return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends