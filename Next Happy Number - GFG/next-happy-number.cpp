//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool check (int num)
    {
        if (num == 1 || num == 7)
            return true;
        
        if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9)
            return false;
        
        int temp = 0;
        
        while (num)
        {
            int digit = num%10;
            num /= 10;
            
            temp += digit * digit;
        }
        
        return check(temp);
    }


    int nextHappy(int N){
        
        int i = N + 1;

        while (1)
        {
            if (check(i))
                return i;
                
            i++;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends