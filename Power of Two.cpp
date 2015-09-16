#include <cstdio>

class Solution {
public:
	bool isPowerOfTwo(int n) {
		int cnt = 0;
		while(n && cnt<=1){
			if(n & 1)
				++cnt;
			n >>= 1;
		}
		return cnt==1;
	}
};