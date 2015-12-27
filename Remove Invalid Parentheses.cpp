#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
	string strip(string s){
		int start = 0, end=s.length();
		for(;start<s.length() && s[start]==')'; ++start);
		for(;end>0 && s[end-1]=='('; --end);

		return s.substr(start, end-start);
	}

	void helper(set<string>& ans, int left_remove, int right_remove, int cnt, string& cur, int pos, string& source)
	{
		if(pos == source.length()){
			if(left_remove==0 && right_remove==0 && cnt==0){
				ans.insert(cur);
			}
		}else{
			if(source[pos]!='(' && source[pos]!=')'){
				cur.push_back(source[pos]);
				helper(ans, left_remove, right_remove, cnt, cur, pos+1, source);
				cur.pop_back();
			}else if(source[pos]=='('){
				if(left_remove!=0){
					helper(ans, left_remove-1, right_remove, cnt, cur, pos+1, source);
				}
				cur.push_back(source[pos]);
				helper(ans, left_remove, right_remove, cnt+1, cur, pos+1, source);
				cur.pop_back();
			}else if(source[pos]==')'){
				if(left_remove!=0){
					helper(ans, left_remove, right_remove-1, cnt, cur, pos+1, source);
				}
				if(cnt > 0){
					cur.push_back(')');
					helper(ans, left_remove, right_remove, cnt-1, cur, pos+1, source);
					cur.pop_back();
				}
			}
		}
	}

public:
	vector<string> removeInvalidParentheses(string s) {
		s = strip(s);
		int left_remove=0, right_remove=0, cnt=0;
		for(int i=0; i<s.length(); ++i){
			if(s[i]=='(')
				++left_remove;
			else if(s[i] == ')'){
				if(left_remove > 0)
					--left_remove;
				else{
					++right_remove;
				}
			}
		}

		set<string> ans;
		string tmp = "";
		helper(ans, left_remove, right_remove, 0, tmp, 0, s);
		return vector<string>(ans.begin(), ans.end());
	}
};