//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int n = s.length(), maxLen = -1; 
        unordered_map<char, int> freq;
        
        for (int start = 0, end = 0; end < n; end++)
        {
            freq[s[end]]++;
            
            while (freq.size() > k && start < end)
            {
                freq[s[start]]--;
                
                if (freq[s[start]] == 0)
                    freq.erase(s[start]);
                    
                start++;
            }
            
            if (freq.size() == k)
            {
                int len = end - start + 1;
                maxLen = max(len, maxLen);
            }
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends