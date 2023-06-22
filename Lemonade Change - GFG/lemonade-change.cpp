//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        
        int count5s = 0, count10s = 0;
        
        for (auto &it : bills)
        {
            if (it == 5)
                count5s++;
                
            else if (it == 10)
            {
                count10s++;
                count5s--;
            }
            
            else
            {
                if (count10s)
                {
                    count10s--;
                    count5s--;
                }
                
                else
                    count5s -= 3;
            }
            
            if (count5s < 0)
                return false;
            
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends