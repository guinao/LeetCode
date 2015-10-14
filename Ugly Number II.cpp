#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int factor[] = {2,3,5};
		priority_queue<int> pq;
		set<int> s;
		pq.push(-1);
		int ans;

		for(int i=1; i<=n; ++i){
			ans = pq.top();
			pq.pop();
			s.insert(ans);
			for(int j=0; j<3; ++j)
				if(s.find(ans*factor[j]) == s.end()){
					pq.push(ans * factor[j]);
					s.insert(ans * factor[j]);
				}
		}

		return -ans;
	}
};

int main()
{
	Solution s;
	int n;
	while(EOF != scanf("%d", &n)){
		printf("%d\n", s.nthUglyNumber(n));
	}
	return 0;
}