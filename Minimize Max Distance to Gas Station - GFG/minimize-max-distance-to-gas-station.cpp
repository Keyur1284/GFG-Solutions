//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool check (double mid, vector<int> &stations, int k)
    {
        int n = stations.size();
        
        int count = 0;

        for (int i = 0; i < n - 1; i++) 
        {
            count += (stations[i + 1] - stations[i]) / mid;
        }
        
        return count <= k;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k){
      
        double low = 0.0, high = stations.back() - stations[0], mid, ans;
        
        while (low + 1e-6 < high)
        {
            mid = low + (high - low)/2.0;
            
            if (check(mid, stations, k))
            {
                ans = mid;
                high = mid;
            }
            
            else
                low = mid;
        }
        
        return round(ans * 100)/100;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends