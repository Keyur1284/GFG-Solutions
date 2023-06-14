//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        for (int i = 0; i < r; i++)
        {
            mini = min (mini, matrix[i][0]);
            maxi = max (maxi, matrix[i][c - 1]);
        }
        
        int low = mini, high = maxi, req = (r * c)/2, mid, ans;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            int pos = 0;
            
            for (int i = 0; i < r; i++)
            {
                pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
 
            if (pos <= req)
                low = mid + 1;
                
            else
                high = mid - 1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends