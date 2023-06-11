//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vec;
        
        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(end[i], start[i]);
        }
        
        sort (vec.begin(), vec.end());
        
        int meetings = 1, last = vec[0].first;
        
        for (int i = 1; i < n; i++)
        {
            if (vec[i].second > last)
            {
                last = vec[i].first;
                meetings++;
            }
        }
        
        return meetings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends