//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    long long int substrCount (string s, int k) {
    	
    	int n = s.length(), unique = 0, extra = 0;
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
    	        extra = 0;
    	    }
    	    
	        if (unique == k)
	        {
	            while(freq[s[start] - 'a'] > 1)
	            {
	                extra++;
	                freq[s[start++] - 'a']--;
	            }
	            
	            count += extra + 1;
	        }
    	}
    	
    	return count;
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