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
    
    sort (arr, arr + n);
    
    pair<int, int> ans = {-1, -1};
    
    int low = 0, high = n - 1, mid;
    
    while (low <= high)
    {
        mid = (low + high) >> 1;
        
        if (arr[mid] <= x)
        {
            ans.first = arr[mid];
            low = mid + 1;
        }
        
        else
            high = mid - 1;
    }
    
    low = 0, high = n - 1;
    
    while (low <= high)
    {
        mid = (low + high) >> 1;
        
        if (arr[mid] >= x)
        {
            ans.second = arr[mid];
            high = mid - 1;
        }
        
        else
            low = mid + 1;
    }
    
    return ans;
}