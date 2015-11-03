#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size();
		while(left < right)
		{
			int mid = ((long long)left+right) / 2;
			bool l = mid==0 || nums[mid-1]<nums[mid];
			bool r = mid+1==nums.size() || nums[mid] > nums[mid+1];
			if(l && r)
				return mid;
			if(!l)
				right = mid;
			else
				left = mid+1;
//			printf("%d %d\n", left, right);
		}
		return left;
	}
};

//int main()
//{
//	int n;
//	Solution s;
//	while(EOF != scanf("%d", &n)){
//		vector<int> v(n);
//		int a;
//		for(int i=0; i<n; ++i){
//			scanf("%d", &a);
//			v[i] = a;
//		}
//		printf("%d\n", s.findPeakElement(v));
//	}
//	return 0;
//}