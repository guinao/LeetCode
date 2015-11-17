class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor == 0 || (dividend==INT_MIN && divisor==-1))
			return INT_MAX;

		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int ans = 0;
		while(dvd >= dvs){
			long long temp = dvs, multiple = 1;
			while(dvd >= (temp << 1)){
				temp <<= 1;
				multiple <<= 1;
			}
			dvd -= temp;
			ans += multiple;
		}

		if(flag)
			return ans;
		else
			return -ans;
	}
};