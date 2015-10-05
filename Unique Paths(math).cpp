class Solution {
public:
	int uniquePaths(int m, int n) {
		double ans = 1;
		int t = m+n-2;
		for(int i=n; i<=t; ++i){
			ans *= i;
		}
		for(int i=2; i<m; ++i){
			ans /= i;
		}

		return (int)ans;
	}
};