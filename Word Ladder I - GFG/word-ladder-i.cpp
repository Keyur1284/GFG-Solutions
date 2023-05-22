//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        unordered_set<string> dict (wordList.begin(), wordList.end());
        
        if (dict.find(targetWord) == dict.end())
            return 0;
            
        queue<pair<string, int>> BFS;
        
        BFS.emplace(startWord, 1);
        dict.erase(startWord);
        
        while (!BFS.empty())
        {
            string word = BFS.front().first;
            int steps = BFS.front().second;
            BFS.pop();
            
            if (word == targetWord)
                return steps;
                
            for (int index = 0; index < word.size(); index++)
            {
                char old = word[index];
                
                for (char k = 'a'; k <= 'z'; k++)
                {
                    word[index] = k;
                    
                    if (dict.find(word) != dict.end())
                    {
                        BFS.emplace(word, steps + 1);
                        dict.erase(word);
                    }
                    
                    word[index] = old;
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends