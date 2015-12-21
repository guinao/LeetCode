#include <cstdio>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> cnt(26, 0);
		for(int i=0; i<s.size(); ++i)
			cnt[s[i] - 'a']++;

		string ans;
		vector<bool> mark(26, false);
		for(int i=0; i<s.size(); ++i){
			int x = s[i] - 'a';
			--cnt[x];
			if(mark[x])
				continue;
			while(!ans.empty() && ans.back()>s[i] && cnt[ans.back()-'a']>0){
				mark[ans.back()-'a'] = false;
				ans.pop_back();
			}
			ans.push_back(s[i]);
			mark[x] = true;
		}
		return ans;
	}
};