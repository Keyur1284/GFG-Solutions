//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int columnNumber)
    {
        string title = "";

        while (columnNumber)
        {
            columnNumber--;

            title += ('A' + columnNumber % 26);
            columnNumber /= 26;
        }

        reverse(title.begin(), title.end());
        return title;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends