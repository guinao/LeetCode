#include <cstdio>
#include <string>
#include <unordered_set>
#include <queue>
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

public:
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
};

