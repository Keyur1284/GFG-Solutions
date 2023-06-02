//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    
    vector<int> primes;
    vector<bool> isPrime;
    int size = 1e6 + 1;
    
    void precompute(){
        
        isPrime.resize(size, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int p = 2; p * p <= size; p++)
        {
            if (isPrime[p])
            {
                for (int i = p * p; i <= size; i += p)
                    isPrime[i] = false;
            }
        }
        
        primes.emplace_back(-1);
        
        for (int p = 2; p <= size; p++)
        {
            if (isPrime[p])
                primes.emplace_back(p);
        }
    }
    
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
    
    int getSize (int u)
    {
        return size[u];
    }
};
    
    int helpSanta(int n, int m, vector<vector<int>> &adj){
        
        DSU dsu(n);
        
        for (int i = 1; i <= n; i++)
        {
            for (auto &it : adj[i])
                dsu.UnionSize(i, it);
        }

        int k = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (dsu.findPar(i) == i)
                k = max(k, dsu.getSize(i));
        }
        
        return (k > 1) ? primes[k] : -1;
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends