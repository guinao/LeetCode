#include <string>
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;

class Solution {
private:
	int eval(int a, int b, char op)
	{
		switch(op){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		};
	}

public:
	int calculate(string s) {
		int num = 0, ans = 0;
		stack<char> sign;
		stack<int> ns;
		ns.push(0);
		sign.push('+');

		for(int i=0; i<s.length(); ++i){
			if(isdigit(s[i])){
				num = num*10 + s[i] - '0';
			}else if(s[i] == '+' || s[i] == '-'){
				ns.top() = eval(ns.top(), num, sign.top());
				if(sign.top() == '*' || sign.top()=='/'){
					sign.pop();
					num = ns.top();
					ns.pop();
					ns.top() = eval(ns.top(), num, sign.top());
				}
				sign.pop();
				sign.push(s[i]);
				num = 0;
			}else if(s[i] == '*' || s[i] == '/'){
				ns.push(num);
				sign.push(s[i]);
				num = 0;
			}
		}

		while(!ns.empty()){
			num = eval(ns.top(), num, sign.top());
			ns.pop();
			sign.pop();
		}
		return num;
	}
};
