#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int abs(int x)	{
		return x > 0 ? x : -x;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		vector<int> v(nums.begin(), nums.end());
		sort(v.begin(), v.end());

		int ans = v[0]+v[1]+v[2];
		for(int i=0; i<v.size(); ++i){
			int s = i+1, e = v.size()-1;
			while(s < e){
				int val = v[i] + v[s] + v[e];
				if(abs(val-target) < abs(ans-target))
					ans = val;
				if(val > target)
					--e;
				else if(val < target)
					++s;
				else
					return val;
			}
		}

		return ans;
	}
};

int main()
{
	int n, target;
	Solution s;
	vector<int> v;
	while(EOF != scanf("%d%d", &n, &target)){
		v.resize(n);
		for(int i=0; i<n; ++i){
			int a;
			scanf("%d", &a);
			v[i] = a;
		}
		printf("%d\n", s.threeSumClosest(v, target));
	}

	return 0;
}