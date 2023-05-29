//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        
        vector<string> matchingStrings;
        
        for (auto &str : Dictionary)
        {
            string pattern = "";
            
            for (auto &ch : str)
            {
                if (ch >= 'A' && ch <= 'Z')
                    pattern += ch;
                    
                if (pattern == Pattern)
                {
                    matchingStrings.emplace_back(str);
                    break;
                }
            }
        }
        
        if (matchingStrings.empty())
            return {"-1"};
        
        return matchingStrings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends