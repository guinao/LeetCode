#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if(tokens.size() == 0)
			return 0;

		stack<int> s;
		for(int i=0; i<tokens.size(); ++i){
			const char *buf = tokens[i].c_str();
			if(buf[0] == '+' && buf[1]=='\0'){
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(a + b);
			}else if(buf[0] == '-' && buf[1]=='\0'){
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(b - a);
			}else if(buf[0] == '*'){
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(a * b);
			}else if(buf[0] == '/'){
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(b / a);
			}else{
				s.push(atoi(buf));
			}
		}

		return s.top();
	}
};