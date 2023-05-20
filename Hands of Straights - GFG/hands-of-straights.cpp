//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        
        map<int, int> mp;
        
        for (auto &it : hand)
            mp[it]++;
            
        for (auto &it : mp)
        {
            if (mp[it.first] > 0)
            {
                int freq = mp[it.first];
                
                for (int k = 0; k < groupSize; k++)
                {
                    mp[it.first + k] -= freq;
                    
                    if (mp[it.first + k] < 0)
                        return false;
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends