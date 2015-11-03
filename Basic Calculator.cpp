#include <vector>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> num;
		stack<int> sign;
		num.push(0);
		sign.push(1);
		int pre = 0;
		for(int i=0; i<s.length(); ++i){
			if(isdigit(s[i])){
				pre = pre*10+s[i]-'0';
			}else if(s[i] == '+'){
				num.top() += pre * sign.top();
				sign.pop();
				sign.push(1);
				pre = 0;
			}else if(s[i] == '-'){
				num.top() += pre * sign.top();
				sign.pop();
				sign.push(-1);
				pre = 0;
			}else if(s[i] == '('){
				num.push(0);
				sign.push(1);
				pre = 0;
			}else if(s[i] == ')'){
				int k = num.top() + pre * sign.top();
				num.pop();
				sign.pop();
				num.top() += k * sign.top();
				sign.pop();
				sign.push(1);
				pre = 0;
			}
		}
		return num.top() + pre*sign.top();
	}
};