#include <vector>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long ll;

class Solution {
private:
	void helper(vector<string>& ans, string exp, ll num, ll prev, const char* rest, int target){
		if(rest[0] == 0){
			if(num == target)
				ans.push_back(exp);
			return;
		}

		for(int i=1; rest[i]!='\0'; ++i){
			string cur(rest, rest+i);
			if(cur[0]=='0' && cur.length()>1)
				return;

			ll v = stoll(cur);
			if(exp.length() != 0){
				helper(ans, exp+"*"+cur, (num-prev)+prev*v, prev*v, rest+i, target);
				helper(ans, exp+"+"+cur, num+v, v, rest+i, target);
				helper(ans, exp+"-"+cur, num-v, -v, rest+i, target);
			}else{
				helper(ans, cur, v, v, rest+i, target);
			}
		}
	}

public:
	vector<string> addOperators(string num, int target) {
		vector<string> ans;
		helper(ans, "", 0, 0, num.c_str(), target);
		return ans;
	}
};