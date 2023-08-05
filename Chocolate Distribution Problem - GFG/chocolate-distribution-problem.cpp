//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
        sort(a.begin(), a.end());
        long long minDiff = LLONG_MAX;
        
        for (int start = 0, end = 0; end < n; end++)
        {
            int len = end - start + 1;
            
            if (len == m)
            {
                long long diff = a[end] - a[start++];
                minDiff = min(diff, minDiff);
            }
        }
        
        return minDiff;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends