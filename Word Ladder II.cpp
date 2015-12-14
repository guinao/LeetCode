#include <cstdio>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool helper(unordered_set<string>& wordList, unordered_set<string>& src, unordered_set<string>& dest, queue<string>& cur, queue<string>& nxt)
	{
		while(!cur.empty()){
			string str = cur.front();
			cur.pop();
			for(int i=0; i<str.length(); ++i){
				for(int j=0; j<26; ++j){
					string s = str;
					s[i] = 'a'+j;
					if(dest.find(s) != dest.end())
						return true;
					if(wordList.find(s) != wordList.end()){
						wordList.erase(s);
						src.insert(s);
						nxt.push(s);
					}
				}
			}
		}
		swap(cur, nxt);
		return false;
	}

	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if(beginWord == endWord)
			return 1;

		unordered_set<string> bs, es;
		queue<string> q[4];
		int cnt = 2;

		bs.insert(beginWord);
		es.insert(endWord);
		q[0].push(beginWord);
		q[2].push(endWord);
		while(!q[0].empty() && !q[2].empty()){
			if(q[0].size() > q[2].size()){
				if(helper(wordList, es, bs, q[2], q[3]))
					return cnt;
			}else{
				if(helper(wordList, bs, es, q[0], q[1]))
					return cnt;
			}
			++cnt;
		}
		return 0;
	}

	void dfs(string& beginWord, string& endWord, unordered_set<string> &wordList, int cnt, vector<vector<string>>& ans, vector<string>& cur){
		if(cnt == 1){
			if(beginWord == endWord){
				ans.push_back(cur);
			}
		}else{
			for(int i=0; i<beginWord.length(); ++i){
				for(char j='a'; j<='z'; ++j){
					string str = beginWord;
					str[i] = j;
					if(str == endWord){
						cur.push_back(str);
						ans.push_back(cur);
						cur.pop_back();
					}else if(wordList.find(str) != wordList.end()){
						cur.push_back(str);
						wordList.erase(str);
						dfs(str, endWord, wordList, cnt-1, ans, cur);
						wordList.insert(str);
						cur.pop_back();
					}
				}
			}
		}
	}
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		unordered_set<string> record(wordList);
		vector<vector<string> > ans;
		vector<string> cur;
		cur.push_back(beginWord);
		dfs(beginWord, endWord, record, ladderLength(beginWord, endWord, wordList), ans, cur);
		return ans;
	}
};

int main()
{
	Solution s;
	int n;
	char buf[32];
	while(EOF != scanf("%d", &n)){
		unordered_set<string> wordList;
		string beginWord, endWord;
		for(int i=0; i<n; ++i){
			scanf("%s", buf);
			wordList.insert(buf);
		}
		scanf("%s", buf);
		beginWord = buf;
		scanf("%s", buf);
		endWord = buf;
		vector<vector<string> > ans = s.findLadders(beginWord, endWord, wordList);
	}
	return 0;
}