#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		ll a = (ll)numerator;
		ll b = (ll)denominator;
		bool flag = true;
		if(a < 0)
			flag = !flag, a = -a;
		if(b<0 && a!=0)
			flag = !flag, b = -b;
		int ind = 0;
		map<ll, int> remain;
		vector<char> frac;
		int ls=-1;

		ll a1 = a / b;
		a %= b;
		remain[a] = ind++;

		while(a != 0){
			a *= 10;
			int next = a / b;
			frac.push_back(next+'0');
			a %= b;
			if(remain.find(a) != remain.end()){
				ls = remain[a];
				break;
			}else{
				remain[a] = ind++;
			}
		}

		char temp[64];
		memset(temp, 0, sizeof temp);
		sprintf(temp, "%lld", a1);
		string ans;
		if(!flag) ans.push_back('-');
		ans.append(temp);
		if(ls == -1){
			if(frac.size() > 0)
				ans.push_back('.');
			for(int i=0; i<frac.size(); ++i)
				ans.push_back(frac[i]);
		}else{
			ans.push_back('.');
			for(int i=0; i<ls; ++i)
				ans.push_back(frac[i]);
			ans.push_back('(');
			for(int i=ls; i<frac.size(); ++i)
				ans.push_back(frac[i]);
			ans.push_back(')');
		}
		return ans;
	}
};

int main()
{
	Solution s;
	int a, b;
	while(EOF != scanf("%d %d", &a, &b)){
		cout << s.fractionToDecimal(a, b) << endl;
	}
	return 0;
}