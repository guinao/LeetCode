class Solution {
public:
	int mySqrt(int x) {
		if(x == 0 || x==1)
			return x;
		int lb = 1, ub = x/2;
		while(lb+1 < ub){
			long long mid = ((long long)lb+ub) / 2;
			if(mid * mid > x)
				ub = mid;
			else
				lb = mid;
		}
		return lb;
	}
};