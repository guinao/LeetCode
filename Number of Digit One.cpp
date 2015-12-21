class Solution {
public:
	int countDigitOne(int n) {
		int ans = 0;
		long long fact = 1;
		while(n < fact){
			fact *= 10;
			int k = n % fact / (fact/10);
			if(k>1)
				ans += (n+8)/fact;
			else if(k == 1)
				ans += n/fact + n%(fact/10)+1;
		}
		return ans;
	}
}; 