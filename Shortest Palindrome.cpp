#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		if(s.size() <= 1)
			return s;

		// compute prefix
		vector<int> pi(s.size(), -1);
		int k = -1;
		for(int i=1; i<s.size(); ++i){
			while(k>=0 && s[k+1]!=s[i])
				k = pi[k];
			if(s[k+1]==s[i])
				++k;
			pi[i] = k;
		}

		// kmp match
		string rev = s;
		reverse(rev.begin(), rev.end());
		vector<int> kmp(s.size());
		k = -1;
		for(int i=0; i<rev.size(); ++i){
			while(k>=0 && s[k+1]!=rev[i])
				k = pi[k];
			if(s[k+1] == rev[i])
				++k;
			kmp[i] = k;
		}

		int n = s.size();
		return rev.substr(0, n-kmp[n-1]-1) + s;
	}
};