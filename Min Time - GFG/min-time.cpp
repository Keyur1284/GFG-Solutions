//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        
        map<int, vector<int>> pos;
        
        for (int i = 0; i < n; i++)
        {
            if (pos.find(types[i]) == pos.end())
            {
                pos[types[i]] = {locations[i], locations[i]};
            }
            
            else
            {
                pos[types[i]][0] = min (pos[types[i]][0], locations[i]);
                pos[types[i]][1] = max (pos[types[i]][1], locations[i]);
            }
        }
        
        vector<vector<int>> fruits;
        
        fruits.push_back({0, 0});
        
        for (auto &it : pos)
        {
            fruits.emplace_back(it.second);
        }
        
        fruits.push_back({0, 0});
        
        int size = fruits.size();
        
        vector<vector<long long>> dp (size, vector<long long> (2, 0));
        
        for (int i = 1; i < size; i++)
        {
            dp[i][0] = dp[i - 1][0] + abs(fruits[i - 1][1] - fruits[i][0]) + abs(fruits[i][1] - fruits[i][0]);
            
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(fruits[i - 1][0] - fruits[i][0]) + abs(fruits[i][1] - fruits[i][0]));
            
            dp[i][1] = dp[i - 1][0] + abs(fruits[i - 1][1] - fruits[i][1]) + abs(fruits[i][1] - fruits[i][0]);
            
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(fruits[i - 1][0] - fruits[i][1]) + abs(fruits[i][1] - fruits[i][0]));
        }
        
        return dp[size - 1][0];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends