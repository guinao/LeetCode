#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		if(ratings.size() <= 1)
			return ratings.size();

		vector<int> nums(ratings.size(), 1);
		for(int i=1; i<ratings.size(); ++i)
			if(ratings[i] > ratings[i-1])
				nums[i] = nums[i-1]+1;

		for(int i=ratings.size()-1; i>0; --i)
			if(ratings[i-1] > ratings[i])
				nums[i-1] = max(nums[i-1], nums[i]+1);

		return accumulate(nums.begin(), nums.end(), 0);
	}
};

//int main()
//{
//	int n;
//	Solution s;
//	while(EOF != scanf("%d", &n)){
//		vector<int> ratings(n);
//		int x;
//		for(int i=0; i<n; ++i){
//			scanf("%d", &x);
//			ratings[i] = x;
//		}
//		printf("%d\n", s.candy(ratings));
//	}
//	return 0;
//}