#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	string longestCommonPrefix(vector<string> &strs){
	    if(strs.size() == 0) return "";
		string ans = "";
		int len = INT_MAX;
		for(int i=0; i<strs.size(); ++i){
			len = min(len, (int)strs[i].length());
		}
		for(int i=0; i<len; ++i){
			char a = strs[0][i];
			for(int j=1; j<strs.size(); ++j){
				if(a != strs[j][i])
					return ans;
			}
			ans.push_back(a);
		}
		return ans;
	}
};