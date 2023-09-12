//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        
        long long sum = 0;
        
        for (long long i = 1; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                sum += i;
                sum += (i * i != N) ? N/i : 0;
            }
        }
        
        return (sum == 2 * N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends