class Solution {
public:
    bool isPalindrome(int x) {
		if(x < 0) return false;
        int n = 0;
		int t = x;
		while(x){
			n = n * 10 + x % 10;
			x /= 10;
		}
		return n == t;
    }
};

#include <cstdio>

int main()
{
	int a;
	Solution s;
	while(EOF != scanf("%d", &a)){
		printf("%d\n", s.isPalindrome(a));
	}
}