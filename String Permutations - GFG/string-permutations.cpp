//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve (int index, int n, string &s, vector<string> &perms)
    {
        if (index == n)
        {
            perms.emplace_back(s);
            return;
        }
        
        for (int start = index; start < n; start++)
        {
            swap(s[index], s[start]);
            solve (index + 1, n, s, perms);
            swap(s[index], s[start]);
        }
    }
    
    vector<string> permutation(string S)
    {
        int n = S.length();
        vector<string> perms;
        
        solve(0, n, S, perms);
        
        sort(perms.begin(), perms.end());
        
        return perms;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends