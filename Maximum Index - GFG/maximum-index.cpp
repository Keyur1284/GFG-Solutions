//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        
        vector<int> maxi(n), mini(n);
        mini[0] = arr[0];
        maxi[n - 1] = arr[n - 1];
        
        for (int i = 1; i < n; i++)
        {
            mini[i] = min(mini[i - 1], arr[i]);
        }
        
        for (int i = n - 2; i >= 0; i--)
        {
            maxi[i] = max(maxi[i + 1], arr[i]);
        }
        
        int left = 0, right = 0, maxDiff = 0;
        
        while (left < n && right < n)
        {
            if (mini[left] <= maxi[right])
            {
                maxDiff = max(maxDiff, right - left);
                right++;
            }
            
            else
                left++;
        }
        
        return maxDiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends