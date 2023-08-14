//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorVal = 0;
        
        for (auto &it : nums)
            xorVal ^= it;
            
        vector<int> ans(2, 0);
        int rightMost = (xorVal & (xorVal - 1)) ^ xorVal;
        
        for (auto &it : nums)
        {
            if (it & rightMost)
                ans[0] ^= it;
                
            else
                ans[1] ^= it;
        }
        
        if (ans[1] < ans[0])
            swap(ans[1], ans[0]);
            
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends