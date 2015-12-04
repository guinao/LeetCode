#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cstdlib>
using namespace std;

class Solution {
private:
	int calc(int op1, int op2, char oprand){
		switch(oprand){
		case '+':
			return op1+op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		}
	}
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ans;
		for(int i=0; i<input.length(); ++i){
			if(ispunct(input[i])){
				vector<int> ls = diffWaysToCompute(input.substr(0, i));
				vector<int> rs = diffWaysToCompute(input.substr(i+1, string::npos));
				for(int op1 : ls){
					for(int op2 : rs){
						ans.push_back(calc(op1, op2, input[i]));
					}
				}
			}
		}

		if(ans.empty())
			ans.push_back(stoi(input));
		return ans;
	}
};