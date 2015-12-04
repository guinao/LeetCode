#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
		if(n == 0)
			return x;
		if(n < 0)
			return 1/x * myPow(1/x, -(n+1));
		double ans = 1;
		while(n){
			if(n & 1)
				ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
    }
};