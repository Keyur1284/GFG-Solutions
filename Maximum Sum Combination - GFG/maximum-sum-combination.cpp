//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;
        vector<int> ans;
        
        pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
        vis.emplace(N - 1, N - 1);
        
        
        while(K--)
        {
            auto it = pq.top();
            pq.pop();
            
            int sum = it.first;
            ans.emplace_back(sum);
            
            auto indices = it.second;
            int indA = indices.first, indB = indices.second;
            
            if (indA - 1 >= 0 && vis.find({indA - 1, indB}) == vis.end())
            {
                pq.push({A[indA - 1] + B[indB], {indA - 1, indB}});
                vis.emplace(indA - 1, indB);
            }
                
            if (indB - 1 >= 0 && vis.find({indA, indB - 1}) == vis.end())
            {
                pq.push({A[indA] + B[indB - 1], {indA, indB - 1}});
                vis.emplace(indA, indB - 1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends