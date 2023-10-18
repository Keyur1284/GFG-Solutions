//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        int n = V;
        vector<int> adjRev[n], indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto &it : adj[i])
            {
                adjRev[it].emplace_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.emplace_back(node);

            for (auto &it : adjRev[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends