//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DSU {

private:
    
    vector<int> parent, rank, size;

public:

    DSU (int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.emplace_back(i);
            rank.emplace_back(0);
            size.emplace_back(1);
        }
    }

    int findPar (int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void UnionRank (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }

        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    void UnionSize (int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }

        else if (rank[u] >= rank[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }    
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        int count = V;
        DSU dsu(V - 1);
        
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (adj[i][j] && dsu.findPar(i) != dsu.findPar(j))
                {
                    count--;
                    dsu.UnionSize(i, j);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends