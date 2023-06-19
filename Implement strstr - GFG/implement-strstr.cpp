//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends


//Function to locate the occurrence of the string x in the string s.
int strstr(string text, string pat)
{
    int n = text.size(), m = pat.size();
    int MOD = INT_MAX;
    int k = 256, expo = 1;
    int patHash = 0, textHash = 0;
    
    for (int i = 0; i < m - 1; i++)
        expo = (expo * k) % MOD;
        
    for (int i = 0; i < m; i++)
    {
        patHash = (k * patHash + pat[i]) % MOD;
        textHash = (k * textHash + text[i]) % MOD;
    }
    
    for (int i = 0; i <= n - m; i++)
    {
        if (patHash == textHash)
        {
            bool flag = true;
            
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                return i;
        }
        
        if (i + m < n)
        {
            textHash = (k * (textHash - text[i] * expo) + text[i + m]) % MOD;
            
            if (textHash < 0)
                textHash += MOD;
        }
    }
    
    return -1;
}