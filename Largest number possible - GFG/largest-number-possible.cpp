//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        
        if ((S == 0 && N > 1) || S > 9 * N)
            return "-1";
        
        string number = "";
        
        for (int i = 1; i <= N; i++)
        {
            number += (S >= 9) ? '9' : S + '0';
            S -= (S >= 9) ? 9 : S;
        }
        
        return number;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends