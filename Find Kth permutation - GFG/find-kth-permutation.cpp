//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> vec (n + 1);
        iota (vec.begin(), vec.end(), 0);
        k--;
        
        while (k--)
        {
            next_permutation(vec.begin() + 1, vec.end());
        }
        
        string ans = "";
        
        for (int i = 1; i <= n; i++)
            ans += vec[i] + '0';
            
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends