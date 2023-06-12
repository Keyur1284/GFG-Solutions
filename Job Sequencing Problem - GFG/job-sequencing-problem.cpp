//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool comp (Job &j1, Job &j2)
    {
        return j1.dead < j2.dead;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort (arr, arr + n, comp);
        
        priority_queue<int> pq;
            
        int jobs = 0, profit = 0;
        
        for (int i = n - 1; i >= 0; i--)
        {
            int slots;
            
            if (i == 0)
                slots = arr[i].dead;
                
            else
                slots = arr[i].dead - arr[i - 1].dead;
                
            pq.emplace(arr[i].profit);
            
            while(slots-- && !pq.empty())
            {
                profit += pq.top();
                jobs++;
                pq.pop();
            }
        }
        
        return {jobs, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends