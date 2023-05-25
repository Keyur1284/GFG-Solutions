//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    string st;
    int len, target;
    vector<string> ans;
    
    void solve (int index, string path, long eval, long prev)
    {
        if (index == len)
        {
            if (eval == target)
                ans.emplace_back(path);
                
            return;
        }
        
        string next = "";
        long val = 0;
        
        for (int pos = index; pos< len; pos++)
        {
            if (pos > index && st[index] == '0')
                break;
                
            next += st[pos];
            val *= 10;
            val += st[pos] - '0';
            
            if (index == 0)
                solve (pos + 1, next, val, val);
                
            else
            {
                solve (pos + 1, path + '+' + next, eval + val, val);
                solve (pos + 1, path + '-' + next, eval - val, -val);
                solve (pos + 1, path + '*' + next, eval - prev + prev * val, prev * val);
            }
        }
    }
    
    vector<string> addOperators(string S, int target) {
        
        this->st = S;
        this->len = S.size();
        this->target = target;
        
        solve (0, "", 0, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends