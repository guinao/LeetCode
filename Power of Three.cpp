#include <cmath>

class Solution {
public:
	bool isPowerOfThree(int n) {
		if(n < 1)
			return false;
		double v = log10((double)n) / log10((double)3);
		return floor(v) == v;
	}
};