//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> left (n, -1), right (n, n), temp (n + 1, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if (!st.empty())
                left[i] = st.top();
                
            st.emplace(i);
        }
        
        while (!st.empty())
            st.pop();
            
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
                
            if (!st.empty())
                right[i] = st.top();
                
            st.emplace(i);
        }
        
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;
            temp[len] = max(temp[len], arr[i]);
        }
        
        for (int i = n - 1; i >= 1; i--)
            temp[i] = max(temp[i], temp[i + 1]);
            
        vector<int> ans;
        
        for (int i = 1; i <= n; i++)
            ans.emplace_back(temp[i]);
            
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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends