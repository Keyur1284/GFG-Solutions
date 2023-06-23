//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        
        vector<int> freq(26, 0);
        int maxFreq = 0;
        
        for (auto &it : tasks)
        {
            freq[it - 'A']++;
            maxFreq = max(maxFreq, freq[it - 'A']);
        }
        
        int maxFreqCount = 0;
        
        for (auto &it : freq)
        {
            if (it == maxFreq)
                maxFreqCount++;
        }
        
        int ans = maxFreq + (maxFreq - 1) * K + maxFreqCount - 1;
        
        return max(N, ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends