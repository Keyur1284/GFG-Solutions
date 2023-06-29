//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    
	    int len = s.length(), odd = 0, even = 0;
	    
	    for (int i = 0; i < len; i++)
	    {
	        if (s[i] == '1')
	        {
	            (i & 1) ? odd++ : even++;
	        }
	    }
	    
	    return (abs(even - odd) % 3 == 0);
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends