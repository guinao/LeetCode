#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class NumArray {
private:
	vector<int> bit;

	int lowbit(int x){
		return x & (-x);
	}

	void add(int x, int v){
		while(x<bit.size()){
			bit[x] += v;
			x += lowbit(x);
		}
	}

	int sum(int x){
		int ret = 0;
		for(int i=x; i>0; i-=lowbit(i)){
			ret +=  bit[i];
		}
		return ret;
	}

public:
	NumArray(vector<int> &nums) {
		bit.resize(nums.size()+1, 0);
		for(int i=0; i<nums.size(); ++i){
			add(i+1, nums[i]);
		}
	}

	void update(int i, int val) {
		int pre = sumRange(i,i);
		add(i+1, val-pre);
	}

	int sumRange(int i, int j) {
		return sum(j+1) - sum(i);
	}
};
