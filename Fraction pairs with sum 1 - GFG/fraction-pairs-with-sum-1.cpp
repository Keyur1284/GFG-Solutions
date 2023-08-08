//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int> mp;
        int count = 0;
        
        for (int i = 0; i < n; i++)
        {
            int hcf = __gcd(numerator[i], denominator[i]);
            numerator[i] /= hcf;
            denominator[i] /= hcf;
            
            int diff = denominator[i] - numerator[i];
            count += mp[{diff, denominator[i]}];
            mp[{numerator[i], denominator[i]}]++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends