//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool check (int dis, int n, int k, vector<int> &stalls)
    {
        int cows = 1, last = stalls[0];
        
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= dis)
            {
                cows++;
                last = stalls[i];
            }
        }
        
        return (cows >= k);
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort (stalls.begin(), stalls.end());
        
        int low = 0, high = 1e9, mid, ans;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            if (check(mid, n, k, stalls))
            {
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends