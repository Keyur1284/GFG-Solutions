//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    pair<int, int> ans = {-1, INT_MAX};
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= x)
            ans.first = max (ans.first, arr[i]);
            
        if (arr[i] >= x)
            ans.second = min (ans.second, arr[i]);
    }
    
    if (ans.second == INT_MAX)
        ans.second = -1;
    
    return ans;
}