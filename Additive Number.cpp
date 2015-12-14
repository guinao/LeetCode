#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
private:
	string add(string& s1, string& s2){
		string ans = "";
		int len = max(s1.length(), s2.length());
		int incre = 0;
		for(int i=0; i<len; ++i){
			int a1 = i<s1.length()? s1[s1.length()-i-1]-'0' : 0;
			int a2 = i<s2.length()? s2[s2.length()-i-1]-'0' : 0;
			ans = char('0'+(a1+a2+incre)%10) + ans;
			incre = (a1+a2+incre) / 10;
		}
		if(incre != 0)
			ans = "1" + ans;
		return ans;
	}

	bool helper(string s1, string s2, string num){
		if(s1[0]=='0' && s1.size()>1)
			return false;
		if(s2[0]=='0' && s2.size()>1)
			return false;
		if(num.empty())
			return true;
		string s = add(s1, s2);
		if(num.size()>=s.size() && s==num.substr(0,s.size()))
			return helper(s2, s, num.substr(s.size()));
		else
			return false;
	}

public:
	bool isAdditiveNumber(string num) {
		for(int i=1; i<=num.size()/2; ++i){
			for(int j=1; i+j<num.size(); ++j){
				if(helper(num.substr(0,i), num.substr(i,j), num.substr(i+j)))
					return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	char buf[32];
	while(EOF != scanf("%s", buf)){
		printf("%d\n", s.isAdditiveNumber(buf));
	}
	return 0;
}