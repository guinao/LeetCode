#include <cstdio>

class Solution {
public:
    int reverse(int x) {
		int flag = 1, ans = 0;
		long long test = 0;
        if(x < 0){
			flag = -1;
			x = -x;
		}
		while(x != 0 && ans>=0){
			int t = x % 10;
			ans = ans * 10 + t;
			test = test * 10 + t;
			x /= 10;
		}
		return test==ans&&ans>=0 ? ans * flag: 0;
    }
};

int main()
{
	Solution s;
	int a;
	while(EOF != scanf("%d", &a)){
		printf("%d\n", s.reverse(a));
	}
}