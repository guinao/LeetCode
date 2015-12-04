#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;
		int cur;
		for(int i=0; i<nums.size(); ++i){
			if(pq.size() < k || pq.top()>-nums[i]){
				pq.push(-nums[i]);
			}
			if(pq.size() > k)
				pq.pop();
		}
		return -pq.top();
	}
};