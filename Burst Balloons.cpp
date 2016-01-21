#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		if(nums.size() <= 1)
			return nums.size()==0?0 : nums[0];

		vector<vector<int> > dp(nums.size(), vector<int>(nums.size()));

#define A(x) (0<=(x)&&(x)<nums.size()? nums[(x)] : 1)

		for(int l=0; l<nums.size(); ++l){
			for(int i=0; i+l<nums.size(); ++i){
				for(int k=i; k<=i+l; ++k){
					int a = k+1==nums.size()? 0 : dp[k+1][i+l];
					int b = k==0? 0 : dp[i][k-1];
					dp[i][i+l] = max(dp[i][i+l], A(i-1)*A(k)*A(i+l+1)+ a + b);
				}
			}
		}

		return dp[0][nums.size()-1];
	}
};

int main()
{
	Solution s;
	int n, x;
	vector<int> nums;
	while(EOF != scanf("%d", &n)){
		nums.resize(n);
		for(int i=0; i<n; ++i){
			scanf("%d", &x);
			nums[i] = x;
		}
		printf("%d\n", s.maxCoins(nums));
	}
	return 0;
}