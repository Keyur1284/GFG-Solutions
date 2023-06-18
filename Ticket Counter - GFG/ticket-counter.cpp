//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        
        int left = 1, right = N;
        bool flag = true;
        
        while (right - left >= K)
        {
            if (flag)
                left += K;
            
            else
                right -= K;
            
            flag = !flag;
        }
        
        if (flag)
        {
            while (left != right)
                left++;
        }
        
        else
        {
            while (right != left)
                right--;
        }
        
        return (flag)? left : right;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends