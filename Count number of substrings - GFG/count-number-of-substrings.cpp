//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    long long slidingWindow (string &s, int k)
    {
        int n = s.length(), unique = 0;
    	vector<int> freq(26, 0); 
    	long long count = 0;
    	
    	for (int start = 0, end = 0; end < n;  end++)
    	{
    	    freq[s[end] - 'a']++;
    	    
    	    if (freq[s[end] - 'a'] == 1)
    	        unique++;
    	    
    	    while (unique > k && start <= end)
    	    {
    	        freq[s[start] - 'a']--;
    	        
    	        if (freq[s[start] - 'a'] == 0)
    	            unique--;
    	            
    	        start++;
    	    }
    	    
	        int len = end - start + 1;
	        count += len;
    	}
    	
    	return count;
    }
  
    long long int substrCount (string s, int k) {
    	
    	long long ans = slidingWindow(s, k) - slidingWindow(s, k - 1);
    	return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends