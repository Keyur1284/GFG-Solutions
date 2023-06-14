//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int K)
    {
        int i = 0, j = 0, k = 0;
        int arr[n + m];

        while (i < n && j < m) 
            arr[k++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];

        while (i < n)
            arr[k++] = arr1[i++];

        while (j < m)
            arr[k++] = arr2[j++];
            
        return arr[K - 1];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends