//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    vector<vector<int>> merge (vector<vector<int>> &range)
    {
        int n = range.size();
        vector<vector<int>> merged;
        vector<int> temp = range[0];
        
        for (int i = 1; i < n; i++)
        {
            if (temp[1] >= range[i][0])
                temp[1] = max(temp[1], range[i][1]);
                
            else
            {
                merged.emplace_back(temp);
                temp = range[i];
            }
        }
        
        merged.emplace_back(temp);
        
        return merged;
    }
    
    int find (vector<vector<int>> &merged, int k)
    {
        int n = merged.size();
        
        for (int i = 0; i < n; i++)
        {
            if (k <= merged[i][1] - merged[i][0] + 1)
                return (merged[i][0] + k - 1);
                
            k -= (merged[i][1] - merged[i][0] + 1);
        }
        
        if (k)
            return -1;
    }
    
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        
        sort(range.begin(), range.end());
        
        vector<vector<int>> merged = merge(range);
        vector<int> ans;
        
        for (auto &it : queries)
        {
            int num = find(merged, it);
            ans.emplace_back(num);
        }
        
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends