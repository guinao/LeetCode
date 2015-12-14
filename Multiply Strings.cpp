#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution  {
public:
	string multiply(string num1, string num2) {
		string ans;
		ans.resize(num1.length() + num2.length());
		fill(ans.begin(), ans.end(), '0');

		int ca = 0;
		for(int i=(int)num1.size()-1; i>=0; --i){
			int x = num1[i] - '0';
			int cb = 0;
			for(int j=(int)num2.size()-1; j>=0; --j){
				int y = num2[j] - '0';
				int pos = num1.length() + num2.length() - ca - cb + 1;
				int v = x*y;
				while(v != 0){
					v += ans[pos] - '0';
					ans[pos] = v % 10;
					v /= 10;
					--pos;
				}
				++cb;
			}
			++ca;
		}

		for(ca=0; ca<ans.length()-1; ++ca){
			if(ans[ca] != '0')
				break;
		}
		ans = ans.substr(ca);
		return ans;
	}
};