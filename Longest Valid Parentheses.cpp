#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.length();
		int ans = 0;
		stack<int> stk;
		for(int i=0; i<len; ++i){
			if(s[i]=='('){
				stk.push(i);
			}else{
				if(!stk.empty()){
					if(s[stk.top()] == '(')
						stk.pop();
					else
						stk.push(i);
				}else{
					stk.push(i);
				}
			}
		}

		if(stk.empty())
			return len;

		int a=len, b;
		while(!stk.empty()){
			b = stk.top();
			stk.pop();
			ans = max(a-b-1, ans);
			a = b;
		}

		return max(ans, a-1);
	}
};