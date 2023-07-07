//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
	    void solve (int index, int n, string &path, vector<string> &subseq, string &s)
	    {
	        if (index == n)
	        {
	            if (path.size())
	                subseq.emplace_back(path);
	                
	            return;
	        }
	        
	        path += s[index];
	        solve (index + 1, n, path, subseq, s);
	        path.pop_back();
	        solve (index + 1, n, path, subseq, s);
	    }
	
		vector<string> AllPossibleStrings(string &s){
		    
		    string path = "";
		    int n = s.length();
		    
		    vector<string> subseq;
		    
		    solve (0, n, path, subseq, s);
		    
		    sort (subseq.begin(), subseq.end());
		    
		    return subseq;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends