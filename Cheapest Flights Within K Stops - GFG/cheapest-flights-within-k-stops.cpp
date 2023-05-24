//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    struct Flight {

        int price, node, steps;

        Flight (int a, int b, int c)
        {
            price = a;
            node = b;
            steps = c;
        }
    };

    struct comp {
        
        bool operator()(Flight &a, Flight &b)
        {
            return a.price > b.price;
        }
    };
    
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
        vector<pair<int, int>> adj[n];

        for (auto &it : flights)
            adj[it[0]].emplace_back(it[1], it[2]);

        priority_queue<Flight, vector<Flight>, comp> pq;
        vector<int> stops(n, INT_MAX);

        pq.emplace(Flight(0, src, 0));

        while (!pq.empty())
        {
            auto plane = pq.top();
            int price = plane.price;
            int node = plane.node;
            int steps = plane.steps;
            pq.pop();

            if (steps > stops[node] || steps > k + 1)
                continue;

            if (node == dst)
                return price;

            stops[node] = steps;

            for (auto &it : adj[node])
            {
                pq.emplace(Flight(price + it.second, it.first, steps + 1));
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends