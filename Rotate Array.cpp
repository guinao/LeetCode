#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
	
    void rotate(int nums[], int n, int k) {
		int i = 0;
		int rest = n;
		k %= n;
		while(k != 0){
			for(int j=0; j<k; ++j){
				int t = nums[i];
				nums[i] = nums[n-k+j];
				nums[n-k+j] = t;
				++i;
			}
			rest -= k;
			k = k % rest;
			for(int i=0; i<n; ++i){
				printf("%d ", nums[i]);
			}
			puts("");
		}
    }
};

int main()
{
	int n, k, buf[1024];
	Solution s;
	while(EOF != scanf("%d %d", &n, &k)){
		for(int i=0; i<n; ++i){
			scanf("%d", buf+i);
		}
		s.rotate(buf, n, k);
		for(int i=0; i<n; ++i){
			printf("%d ", buf[i]);
		}
		puts("");
	}

	return 0;
}