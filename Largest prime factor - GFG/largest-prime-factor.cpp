//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        
        long long maxPrimeFactor = 1;

        for (int i = 2; i * i <= N; i++)
        {
            while (N % i == 0)
            {
                maxPrimeFactor = i;
                N /= i;
            }
        }
        
        if (N != 1)
            maxPrimeFactor = N;
            
        return maxPrimeFactor;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends