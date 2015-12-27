#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool test(const char* s1, const char* s2, int len){
		vector<int> cnt(26);
		for(int i=0; i<len; ++i)
			++cnt[s1[i]-'a'];
		for(int i=0; i<len; ++i)
			--cnt[s2[i]-'a'];
		for(int i=0; i<26; ++i)
			if(cnt[i] != 0)
				return false;

		return true;
	}

	bool helper(const char* s1, const char* s2, int len){
		if(len == 0)
			return true;

		if(strncmp(s1, s2, len) == 0)
			return true;

		if(!test(s1, s2, len))
			return false;

		for(int i=1; i<len; ++i){
			if(helper(s1, s2, i) && helper(s1+i, s2+i, len-i))
				return true;
			if(helper(s1, s2+len-i, i) && helper(s1+i, s2, len-i))
				return true;
		}

		return false;
	}

public:
	bool isScramble(string s1, string s2) {
		return helper(s1.c_str(), s2.c_str(), s1.length());
	}
};