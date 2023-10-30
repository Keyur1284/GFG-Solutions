//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	long long sum = 0;
    	
    	for (int pos = 0; pos < 32;  pos++)
    	{
    	    long long ones = 0;
    	    
    	    for (int i = 0; i < n; i++)
    	    {
    	        ones += (arr[i] & (1 << pos)) ? 1 : 0;
    	    }
    	    
    	    sum += (ones * (n - ones) * (1 << pos));
    	}
    	
    	return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends