//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        int rightMax[N], leftMin[N];
        rightMax[N - 1] = A[N - 1];
        leftMin[0] = A[0];
        
        for (int i = N - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], A[i]);
        }
        
        for (int i = 1; i < N; i++)
        {
            leftMin[i] = min(leftMin[i - 1], A[i]);
        }
        
        int left = 0, right = 0, maxLen = 0;
        
        while (left < N && right < N)
        {
            if (leftMin[left] <= rightMax[right])
            {
                int len = right - left;
                maxLen = max(maxLen, len);
                right++;
            }
            
            else
                left++;
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends