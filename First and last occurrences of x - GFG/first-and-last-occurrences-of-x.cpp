//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int first = -1, last = -1;
        
        int firstIndex = lower_bound(arr, arr + n, x) - arr;
        
        if (firstIndex < n && arr[firstIndex] == x)
            first = firstIndex;
            
        else
            return {first, last};
            
        int lastIndex = upper_bound(arr, arr + n, x) - arr;
        
        last = lastIndex - 1;
        
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends