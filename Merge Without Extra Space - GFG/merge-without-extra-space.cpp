//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long long mask = (1 << 25) - 1;
            int i = 0, j = 0, k = 0;
            
            while (i < n && j < m)
            {
                long long newVal, org1, org2;
                
                org1 = (arr1[i] & mask);
                org2 = (arr2[j] & mask);
                
                newVal = (org1 < org2) ? (org1 << 30) : (org2 << 30);
                (org1 < org2) ? i++ : j++;
                
                (k < n) ? arr1[k++] |= newVal : arr2[k++ - n] |= newVal;
            }
            
            while (i < n)
            {
                long long newVal, org1;
                
                org1 = (arr1[i] & mask);

                newVal = (org1 << 30);
                i++;
                
                (k < n) ? arr1[k++] |= newVal : arr2[k++ - n] |= newVal;
            }
            
            while (j < m)
            {
                long long newVal, org2;
                
                org2 = (arr2[j] & mask);

                newVal = (org2 << 30);
                j++;
                
                (k < n) ? arr1[k++] |= newVal : arr2[k++ - n] |= newVal;
            }
            
            for (int i = 0; i < n; i++)
                arr1[i] >>= 30;
                
            for (int j = 0; j < m; j++)
                arr2[j] >>= 30;
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends