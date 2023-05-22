//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        
        vector<int> indegree(N, 0);
        
        for (int i = 1; i < N; i++)
        {
            indegree[i]++;
            indegree[p[i]]++;
        }
        
        int edges = N - 1;
        
        for (auto &it : indegree)
        {
            if (it == 1)
                edges--;
        }
        
        return edges;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends