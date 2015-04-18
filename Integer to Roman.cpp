#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		vector<pair<int, string> > dict;
		dict.push_back(make_pair(1000, "M"));
		dict.push_back(make_pair(900, "CM"));
		dict.push_back(make_pair(500, "D"));
		dict.push_back(make_pair(400, "CD"));
		dict.push_back(make_pair(100, "C"));
		dict.push_back(make_pair(90, "XC"));
		dict.push_back(make_pair(50, "L"));
		dict.push_back(make_pair(40, "XL"));
		dict.push_back(make_pair(10, "X"));
		dict.push_back(make_pair(9, "IX"));
		dict.push_back(make_pair(5, "V"));
		dict.push_back(make_pair(4, "IV"));
		dict.push_back(make_pair(1, "I"));
		
		string ans;
		for(int i=0; i<dict.size()&&num; ++i){
			int a = dict[i].first;
			string s = dict[i].second;
			while(num >= a){
				num -= a;
				ans.append(s);
			}
		}

		return ans;
	}
};

int main()
{
	Solution s;
	int a;
	while(EOF != scanf("%d",&a)){
		puts(s.intToRoman(a).c_str());
	}
	return 0;
}