#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if(s.length() <= 1)
			return s;

		int str = 0, len = 1;
		for(int i=0; i+len/2<s.length(); ++i){
			int x = i, y = i;
			while(x>=0 && y<s.length() && s[x]==s[y])
				--x, ++y;
			++x, --y;
			if(y-x+1 > len)
				str = x, len = y-x+1;

			x = i, y = i+1;
			while(x>=0 && y<s.length() && s[x]==s[y])
				--x, ++y;
			++x, --y;
			if(y-x+1 > len)
				str = x, len = y-x+1;
		}
		return s.substr(str, len);
	}
};