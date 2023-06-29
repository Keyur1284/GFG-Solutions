//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check (int pages, int arr[], int n, int m)
    {
        int students = 1, curr = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > pages)
                return false;
                
            if (curr + arr[i] > pages)
            {
                students++;
                curr = arr[i];
                
                if (students > m)
                    return false;
            }
            
            else
                curr += arr[i];
        }
        
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        if (m > n)
            return -1;
        
        int low = *max_element(arr, arr + n);
        int high = accumulate(arr, arr + n, 0);
        int mid;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;
            
            if (check(mid, arr, n, m))
                high = mid - 1;
            
            else
                low = mid + 1;
        }
        
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends