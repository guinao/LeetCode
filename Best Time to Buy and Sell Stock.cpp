#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef int elem_t;

struct sum{
	vector<elem_t> c;

	void init(int n){
		c.resize(n+1);
		fill(c.begin(), c.end(), INT_MAX);
	}

	int lowbit(int x){
		return x & (-x);
	}

	void update(int x, elem_t v){
		while(x <= c.size()){
			c[x] = min(c[x], v);
			x += lowbit(x);
		}
	}

	elem_t getsum(int x){
		elem_t ret = INT_MAX;
		while(x > 0){
			ret = min(c[x], ret);
			x -= lowbit(x);
		}
		return ret;
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() <= 1)
			return 0;

		int len = prices.size();
		sum s;
		s.init(len+1);
		for(int i=0; i<len; ++i){
			s.update(i+1, prices[i]);
		}
		int ret = 0;
		for(int i=1; i<len; ++i){
			ret = max(ret, prices[i] - s.getsum(i));
			printf("%d %d\n", i, ret);
		}

		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	int n, a;
	while(EOF != scanf("%d\n", &n)){
		v.resize(n);
		for(int i=0; i<n; ++i){
			scanf("%d", &a);
			v[i] = a;
		}
		printf("%d\n", s.maxProfit(v));
	}
	return 0;
}