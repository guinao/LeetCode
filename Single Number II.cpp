#include <cstdio>

class Solution {
public:
	int singleNumber(int A[], int n) {
		int one=0, two=0;
		for(int i=0; i<n; ++i){
			one = (one^A[i]) & ~two;
			two = (two^A[i]) & ~one;
		}
		return one | two;
	}
};

int main()
{
	Solution s;
	int a[16];
	int n;
	while(EOF != scanf("%d", &n)){
		for(int i=0; i<n; ++i)
			scanf("%d", a+i);
		printf("%d\n", s.singleNumber(a,n));
	}
	return 0;
}