//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
                     
        vector<pair<int, int>> adj[n];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        int city = -1, minCount = n, inf = INT_MAX;

        for (int src = 0; src < n; src++)
	    {
	        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, inf);

            pq.emplace(0, src);
            dist[src] = 0;

            while (!pq.empty())
            {
                auto vertex = pq.top();
                int steps = vertex.first;
                int node = vertex.second;
                pq.pop();

                for (auto &it : adj[node])
                {
                    if (steps + it.second < dist[it.first])
                    {
                        dist[it.first] = steps + it.second;
                        pq.emplace(dist[it.first], it.first);
                    }
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++)
            {
                count += (dist[i] <=  distanceThreshold);
            }

            if (count <= minCount)
            {
                minCount = count;
                city = src;
            }
        }

        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends