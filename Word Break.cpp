#include <string>
#include <unordered_set>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
	int dp[4096];
	bool wordBreak(string s, unordered_set<string> &dict) {
		if(s.length() == 0)
			return true;

		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		int len = s.length();
		for(int i=1; i<=len ;++i){
			unordered_set<string>::iterator it = dict.begin();
			for(; it!=dict.end(); ++it){
				string w = *it;
				int l = w.length();
				if(i-l >=0 && dp[i-l]==1)
					if(!s.substr(i-l,l).compare(w))
						dp[i] = 1;
			}
		}
		return dp[len];
	}
};

int main()
{
	Solution s;
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	dict.insert("hello");
	dict.insert("world");
	dict.insert("lee");

	printf("%d\n", s.wordBreak("worldhellocodea", dict));

	scanf("\n");

	return 0;
}
