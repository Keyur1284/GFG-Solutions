//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void recc (int left, int &right, set<string> &permutations, string &s)
	    {
	        if (left == right)
	        {
	            permutations.emplace(s);
	            return;
	        }
	            
	        for (int index = left; index <= right; index++)
	        {
	            swap (s[left], s[index]);
	            recc (left + 1, right, permutations, s);
	            swap (s[left], s[index]);
	        }
	    }
	    
		vector<string>find_permutation(string s)
		{
		    set<string> permutations;
		    int right = s.length() - 1;
		    
		    recc (0, right, permutations, s);

            vector<string> ans(permutations.begin(), permutations.end());		    

		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends