#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct TrieNode{
	TrieNode *next[26];
	bool leaf;

	TrieNode(){
		for(int i=0; i<26; ++i)
			next[i] = NULL;
		leaf = false;
	}
};

class Solution {
private:
	TrieNode *root;
	TrieNode *rev;
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		root = new TrieNode();
		for(auto it=wordDict.begin(); it!=wordDict.end(); ++it){
			string word = *it;
			TrieNode *cur = root;
			for(int i=0; i<word.size(); ++i){
				int x = word[i] - 'a';
				if(cur->next[x] == NULL)
					cur->next[x] = new TrieNode();
				cur = cur->next[x];
			}
			cur->leaf = true;
		}

		rev = new TrieNode();
		for(auto it=wordDict.begin(); it!=wordDict.end(); ++it){
			string word = *it;
			TrieNode *cur = rev;
			for(int i=word.size()-1; i>=0; --i){
				int x = word[i] - 'a';
				if(cur->next[x] == NULL)
					cur->next[x] = new TrieNode();
				cur = cur->next[x];
			}
			cur->leaf = true;
		}

		int len = s.length();
		TrieNode *cur = root;
		for(int i=0; i<len; ++i){
			int x = s[i] - 'a';
			if(cur->next[x] == NULL)
				return vector<string>();
			cur = cur->next[x];
			if(cur->leaf)
				break;
		}

		vector<vector<string> > dp(len+1);
		dp[len] = vector<string>(1, "");
		for(int i=len-1; i>=0; --i){
			cur = rev;
			bool flag = false;
			for(int j=len-1; j>=0; --j){
				int x = s[j] - 'a';
				if(cur->next[x] == NULL)
					break;
				cur = cur->next[x];
				if(cur->leaf){
					flag = true;
					break;
				}
			}
			if(!flag && i>0)
				continue;

			cur = root;
			for(int j=i; j<len; ++j){
				int x = s[j] - 'a';
				if(cur->next[x] == NULL)
					break;
				cur = cur->next[x];
				if(cur->leaf){
					string word = s.substr(i, j-i+1);
					for(int r=0; r<dp[j+1].size(); ++r)
						if(dp[j+1][r].size() > 0)
							dp[i].push_back(word + " " + dp[j+1][r]);
						else
							dp[i].push_back(word);
				}
			}
		}

		return dp[0];
	}
};

int main()
{
	int n;
	unordered_set<string> wordList;
	char buf[32];
	Solution s;
	while(EOF != scanf("%d", &n)){
		for(int i=0; i<n; ++i){
			scanf("%s", buf);
			wordList.insert(buf);
		}
		scanf("%s", buf);
		vector<string> ans = s.wordBreak(buf, wordList);
	}
	return 0;
}