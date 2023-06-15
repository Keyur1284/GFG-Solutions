//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> &arr, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }
    
        vector<int> merged;
    
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
    
            merged.emplace_back(it.first);
    
            auto pair = it.second;
            int arrIndex = pair.first;
            int eleIndex = pair.second;
    
            if (eleIndex + 1 < arr[arrIndex].size())
            {
                pq.push({arr[arrIndex][eleIndex + 1], {arrIndex, eleIndex + 1}});
            }
        }
    
        return merged;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends