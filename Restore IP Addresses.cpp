#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		return dfs(s, 4);
		//vector<string> ans = dfs(s, 4);
		//sort(ans.begin(), ans.end());
		//ans.erase(unique(ans.begin(), ans.end()), ans.end());
		//return ans;
	}

	vector<string> dfs(string s, int n){
		vector<string> ret;
		if(n == 1){
			int a = atoi(s.c_str());
			if(s[0] == '0'){
				if(a == 0 && s.length()==1)
					ret.push_back(s);
			}else if(0<a && a<256){
				ret.push_back(s);
			}
			return ret;
		}

		int len = s.length();
		if(s[0] == '0'){
			string seg = s.substr(0,1);
			if(n-1<=len-1 && len-1<=3*(n-1)){
				vector<string> part = dfs(s.substr(1,len-1), n-1);
				seg.push_back('.');
				for(int i=0; i<part.size(); ++i)
					ret.push_back(seg+part[i]);
			}
		}else{
			vector<string> ans;
			for(int i=1; i<=3; ++i){
				if(i > len) break;
				string seg = s.substr(0,i);
				if(atoi(seg.c_str())<256 && n-1<=len-i && len-i<=3*(n-1)){
					vector<string> part = dfs(s.substr(i,len-i), n-1);
					seg.push_back('.');
					for(int i=0; i<part.size(); ++i)
						ret.push_back(seg+part[i]);
				}
			}
		}
		return ret;
	}
};

int main()
{
	char buf[32];
	Solution s;
	while(gets(buf)){
		vector<string> ans = s.restoreIpAddresses(buf);
		for(int i=0; i<ans.size(); ++i)
			printf("%s\n", ans[i].c_str());
	}
	return 0;
}