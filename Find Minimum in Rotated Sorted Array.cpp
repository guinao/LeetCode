#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		long long lb = 0;
		long long ub = nums.size();

		while(lb+1 < ub){
			int mid = (lb+ub) / 2;
			if(nums[mid] > nums[lb])
				lb = mid;
			else
				ub = mid;
		}

		return nums[(lb+1)%nums.size()];
	}
};

int main()
{
	int n, a;
	Solution s;
	while(EOF != scanf("%d", &n)){
		vector<int> v;
		for(int i=0; i<n; ++i){
			scanf("%d", &a);
			v.push_back(a);
		}
		printf("%d\n", s.findMin(v));
	}
	return 0;
}