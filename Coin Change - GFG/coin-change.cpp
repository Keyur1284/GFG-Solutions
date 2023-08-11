//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long>> dp (N, vector<long long> (sum + 1, 0));
        
        for (int k = 0; k <= sum; k++)
            dp[0][k] = (k % coins[0] == 0);
            
        for (int index = 1; index < N; index++)
        {
            for (int tar = 0; tar <= sum; tar++)
            {
                long long notTake = dp[index - 1][tar];
                long long take = 0;
                
                if (coins[index] <= tar)
                    take = dp[index][tar - coins[index]];
                    
                dp[index][tar] = take + notTake;
            }
        }
        
        return dp[N - 1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends