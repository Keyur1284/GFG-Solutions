//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int ones = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                ones++;
                a[i] = -1;
            }
            
            else
                a[i] = 1;
        }
        
        int flip = 0, maxFlip = 0;
        
        for (int i = 0; i < n; i++)
        {
            flip += a[i];
            maxFlip = max(flip, maxFlip);
            flip = max(0, flip);
        }
        
        return ones + maxFlip;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends