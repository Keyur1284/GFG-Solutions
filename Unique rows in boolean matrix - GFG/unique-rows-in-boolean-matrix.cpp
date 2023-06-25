//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends

class TrieNode {
public:

    vector<TrieNode*> child;

    TrieNode ()
    {
        child.assign(2, NULL);
    }

    bool containsKey (int k)
    {
        return (child[k] != NULL);
    }

    void put (int k, TrieNode* node)
    {
        child[k] = node;
    }

    TrieNode* get (int k)
    {
        return child[k];
    }
};

class Trie {
private:

    TrieNode* root;

public:

    Trie() 
    {
        
        root = new TrieNode();
    }
    
    void findUniqueRows(int mat[MAX][MAX], int row, int col, vector<vector<int>> &uniqueRows) {
        
        for (int i = 0; i < row; i++)
        {
            TrieNode* node = root;
            bool flag = false;
            vector<int> currRow;

            for (int j = 0; j < col; j++)
            {
                int num = mat[i][j];
                currRow.emplace_back(num);
                
                if (node->containsKey(num) == NULL)
                {
                    flag = true;
                    node->put(num, new TrieNode());
                }
    
                node = node->get(num);
            }
            
            if (flag)
                uniqueRows.emplace_back(currRow);
        }
    }
};


class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int mat[MAX][MAX],int row,int col)
    {
        Trie obj;
        vector<vector<int>> uniqueRows;
        
        obj.findUniqueRows(mat, row, col, uniqueRows);
        
        return uniqueRows;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends