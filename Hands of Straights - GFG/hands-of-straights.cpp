//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        
        multiset<int> ms;
        
        for (auto &it : hand)
            ms.emplace(it);
            
        while ((int)ms.size())
        {
            auto it = *ms.begin();
            
            for (int k = 0; k < groupSize; k++)
            {
                if (ms.count(it + k) == 0)
                    return false;
                    
                ms.erase(ms.find(it + k));
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