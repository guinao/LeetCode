#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		for(int i=0; i<nums.size(); ++i){
			while(nums[i] != i){
				if(nums[i] == n)
					break;
				int index = nums[i];
				nums[i] = nums[index];
				nums[index] = index;
			}
		}

		for(int i=0; i<nums.size(); ++i){
			if(nums[i] != i)
				return i;
		}

		return n;
	}
};

int main()
{
	Solution S;
	int n,x;
	vector<int> v;
	while(EOF != scanf("%d", &n)){
		v.resize(n);
		for(int i=0; i<n; ++i){
			scanf("%d", &x);
			v[i] = x;
		}
		printf("%d\n", S.missingNumber(v));
	}
	return 0;
}