#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums){
		int n = nums.size();
		auto mid = nums.begin() + n / 2;
		random_shuffle(nums.begin(), nums.end());
		nth_element(nums.begin(), mid, nums.end());
		int v = *mid;

#define A(i) nums[(1+2*(i)) % (n|1)]

		int i=0, j=0, k=n-1;
		while(j <= k){
			if(A(j) > v)
				swap(A(i++), A(j++));
			else if(A(j) < v)
				swap(A(j), A(k--));
			else
				j++;
		}
	}
};

//int main()
//{
//	int n, x;
//	vector<int> nums;
//	Solution s;
//	while(EOF != scanf("%d", &n)){
//		nums.resize(n);
//		for(int i=0; i<n; ++i){
//			scanf("%d", &x);
//			nums[i] = x;
//		}
//		s.wiggleSort(nums);
//	}
//	return 0;
//}