//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       
        bool neg = false;
        
        if (s1[0] == '-')
        {
           neg ^= true;
           s1 = s1.substr(1);
        }
        
        if (s2[0] == '-')
        {
           neg ^= true;
           s2 = s2.substr(1);
        }
        
        int n = s1.length(), m = s2.length();
        vector<int> prod(n + m + 20, 0);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for (int i = 0; i < n; i++)
        {
           int index = i;
           int dig1 = s1[i] - '0';
           
            for (int j = 0; j < m; j++)
            {
                int dig2 = s2[j] - '0';
                int mul = dig1 * dig2;
               
                prod[index] += mul;
                
                if (prod[index] > 9)
                {
                    prod[index + 1] += prod[index] / 10;
                    prod[index] %= 10;
                }
                
                index++;
            }
        }
       
        string ans = "";
        bool nonZero = false;
       
        for (int i = n + m + 19; i >= 0; i--)
        {
            if (prod[i])
                nonZero = true;
                
            if (nonZero)
                ans += '0' + prod[i];
        }
       
        if (neg)
            ans = '-' + ans;
            
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends