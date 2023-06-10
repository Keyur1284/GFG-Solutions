//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
    
        void merge (int start, int mid, int end, int arr[])
        {
            int left = start, right = mid + 1;
                
            while (left <= mid && arr[left] < 0)
                left++;
                
            while (right <= end && arr[right] < 0)
                right++;
                
            reverse (arr + left, arr + mid + 1);
            reverse (arr + mid + 1, arr + right);
            reverse (arr + left, arr + right);
        }
        
        void mergeSort (int left, int right, int arr[])
        {
            if (left < right)
            {
                int mid = (left + right) >> 1;
                
                mergeSort (left, mid, arr);
                mergeSort (mid + 1, right, arr);
                merge (left, mid, right, arr);
            }
        }
    
        void Rearrange(int arr[], int n)
        {
            mergeSort (0, n - 1, arr);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends