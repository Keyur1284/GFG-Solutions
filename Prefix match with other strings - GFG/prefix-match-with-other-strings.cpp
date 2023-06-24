//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class TrieNode {
public:
    
    int count;
    vector<TrieNode*> child;
    
    TrieNode ()
    {
        count = 0;
        child.assign(26, NULL);
    }
    
    bool containsKey (char k)
    {
        int index = k - 'a';
        return (child[index] != NULL);
    }
    
    TrieNode* get (char k)
    {
        int index = k - 'a';
        return child[index];
    }
    
    void put (char k, TrieNode* node)
    {
        int index = k - 'a';
        child[index] = node;
    }
    
    void increaseCount ()
    {
        count++;
    }
    
    int getCount ()
    {
        return count;
    }
};

class Trie {
private:
    
    TrieNode* root;

public: 
    
    Trie ()
    {
        root = new TrieNode();
    }
    
    void insert (string &word)
    {
        TrieNode* node = root;
        
        for (auto &ch : word)
        {
            if (node->containsKey(ch) == NULL)
                node->put(ch, new TrieNode());
                
            node = node->get(ch);
            node->count++;
        }
    }
    
    int findPrefix (string &str, int &k)
    {
        TrieNode* node = root;
        
        for (int i = 0; i < k; i++)
        {
            node = node->get(str[i]);
        }
        
        return node->count - 1;
    }
};

class Solution{   
public:
    
    int klengthpref(string arr[], int n, int k, string str){    
        
        int len = str.length();
        
        if (k > len)
            return 0;
        
        Trie obj;
        obj.insert(str);
        
        for (int i = 0; i < n; i++)
            obj.insert(arr[i]);
            
        int kLenPref = obj.findPrefix(str, k);
        
        return kLenPref;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends