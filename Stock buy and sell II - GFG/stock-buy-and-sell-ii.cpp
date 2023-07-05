//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    
    int solve (int index, int buy, int &n, vector<vector<int>> &dp, vector<int> &prices)
    {
        if (index == n)
            return 0;
            
        if (dp[index][buy] != -1)
            return dp[index][buy];
        
        int take, notTake;
        
        if (buy)
        {
            take = -prices[index] + solve (index + 1, 0, n, dp, prices);
            notTake = solve (index + 1, 1, n, dp, prices);
        }
        
        else
        {
            take = prices[index] + solve (index + 1, 1, n, dp, prices);
            notTake = solve (index + 1, 0, n, dp, prices);
        }
        
        return dp[index][buy] = max(take, notTake);
    }
    
    int stockBuyAndSell(int n, vector<int> &prices) {
        
        vector<vector<int>> dp (n, vector<int> (2, -1));
        return solve (0, 1, n, dp, prices);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends