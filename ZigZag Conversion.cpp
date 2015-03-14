#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int abs(int x)
	{
		return x > 0 ? x : -x;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

    string convert(string s, int nRows) {
		if(nRows <= 1)
			return s;
		int period = (nRows-1) * 2;
		int len = s.length();
		int cycles = len/period;
		int rest = len%period;
		string ret;
		ret.resize(len);
		for(int i=0; i<s.length(); i++){
			int pos = i % period;
			if(pos == 0){
				ret[i/period] = s[i];
				//printf("%c at %d\n", s[i], i/period + 1);
			}else if(pos == nRows - 1){
				int np = cycles*(period-1) + rest + i/period;
				if(rest >= nRows) --np;
				ret[np] = s[i];
				//printf("%c at %d\n", s[i], np + 1);
			}else{
				int level = nRows - abs(nRows - pos - 1);
				//printf("level %d\n", level);
				int np = ((level-1)*2-1) * cycles;
				if(rest < level-1){
					np += rest;
				}else{
					np += level - 1;
					if(rest > 2*nRows-level){
						np += rest - (2*nRows-level);
					}
				}
				np += i/period * 2;
				if(pos >= nRows) ++np;
				ret[np] = s[i];
				//printf("%c at %d\n", s[i], np + 1);
			}
		}
		return ret;
    }
};

int main()
{
	string str;
	int n;
	Solution s;
	while(cin>>str>>n){
		cout<<s.convert(str, n)<<endl;
	}
	return 0;
}