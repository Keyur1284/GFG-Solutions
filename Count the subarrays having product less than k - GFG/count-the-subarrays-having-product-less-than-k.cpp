//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        long long prod = 1;
        int count = 0;
        deque<int> dq;
        
        for (int i = 0; i < n; i++)
        {
            prod *= a[i];
            dq.push_back(a[i]);
            
            while (!dq.empty() && prod >= k)
            {
                prod /= dq.front();
                dq.pop_front();
            }
            
            count += dq.size();
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends