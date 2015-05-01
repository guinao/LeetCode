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
			for(int j=i+1; j<v.size(); ++j){
				int k = lower_bound(v.begin()+j+1, v.end(), target-v[i]-v[j]) - v.begin();
				if(k < v.size()){
					int p = v[i] + v[j] + v[k];
					if(abs(ans-target) > abs(p-target))
						ans = p;
				}
				k--;
				if(k > j){
					int p = v[i] + v[j] + v[k];
					if(abs(ans-target) > abs(p-target))
						ans = p;
				}
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
}