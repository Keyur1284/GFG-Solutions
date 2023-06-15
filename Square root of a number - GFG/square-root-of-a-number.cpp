//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long low = 1, high = x, mid, ans;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            long long square = mid * mid;
            
            if (square == x)
                return mid;
                
            if (square < x)
            {
                ans = mid;
                low = mid + 1;
            }
                
            else
                high = mid - 1;
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends