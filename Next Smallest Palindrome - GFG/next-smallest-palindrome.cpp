//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int nums[], int n) {
	    
        bool change = true;
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[n - i - 1])
                change = true;
                
            else if (nums[i] > nums[n - i - 1])
                change = false;
                
            nums[n - i - 1] = nums[i];
        }
        
        vector<int> ans(nums, nums + n);
        int index = n/2;
        
        while (change && index < n)
        {
            if (ans[index] == 9)
            {
                ans[index] = 0;
                ans[n - index - 1] = ans[index];
            }
            
            else
            {
                ans[index]++;
                ans[n - index - 1] = ans[index];
                change = false;
            }
            
            index++;
        }
        
        if (change)
        {
            ans[0] = 1;
            ans.emplace_back(1);
        }
        
        return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends