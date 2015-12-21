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
	bool helper(
		unordered_set<string>& wordList, 
		unordered_set<string>& s1, 
		unordered_set<string>& s2, 
		unordered_map<string, vector<string>>& next,
		queue<string>& q,
		bool rev
		)
	{
		bool ret = false;
		vector<string> nxt;
		while(!q.empty()){
			string word = q.front();
			q.pop();
			for(int i=0; i<word.length(); ++i){
				for(char c='a'; c<='z'; ++c){
					string tmp = word;
					tmp[i] = c;
					if(tmp == word) continue;
					if(s2.find(tmp) != s2.end()){
						ret = true;
						if(rev)
							next[tmp].push_back(word);
						else
							next[word].push_back(tmp);
					}else{
						if(wordList.find(tmp) != wordList.end()){
							nxt.push_back(tmp);
							if(rev)
								next[tmp].push_back(word);
							else
								next[word].push_back(tmp);
						}
					}
				}
			}
		}
		for(int i=0; i<nxt.size(); ++i){
			s1.insert(nxt[i]);
			q.push(nxt[i]);
			wordList.erase(nxt[i]);
		}
		return ret;
	}

	void dfs(vector<vector<string>>& ans, vector<string>& cur, unordered_map<string, vector<string>>& next, string& endWord){
		string word = cur.back();
		if(word == endWord){
			ans.push_back(cur);
			return ;
		}
		vector<string>& n = next[word];
		for(int i=0; i<n.size(); ++i){
			cur.push_back(n[i]);
			dfs(ans, cur, next, endWord);
			cur.pop_back();
		}
	}

public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<vector<string> > ans;
		if(beginWord == endWord){
			ans.push_back(vector<string>(1, beginWord));
			return ans;
		}
		queue<string> bq, eq;
		unordered_set<string> bset, eset;
		unordered_map<string, vector<string> > next;
		bq.push(beginWord);
		eq.push(endWord);
		bset.insert(beginWord);
		eset.insert(endWord);
		wordList.erase(beginWord);
		wordList.erase(endWord);
		bool found = false;
		while(!found){
			if(bq.size()==0 && eq.size()==0)
				return ans;
			if(bq.size()==0 || bq.size() > eq.size()){
				found = helper(wordList, eset, bset, next, eq, true);
			}else{
				found = helper(wordList, bset, eset, next, bq, false);
			}
		}

		vector<string> cur(1, beginWord);
		dfs(ans, cur, next, endWord);
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
};