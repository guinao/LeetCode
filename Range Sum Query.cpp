#include <vector>
#include <numeric>
using namespace std;

class NumArray {
private:
	vector<int> ps;
public:
	NumArray(vector<int> &nums) {
		ps.resize(nums.size());
		partial_sum(nums.begin(), nums.end(), ps.begin());
	}

	int sumRange(int i, int j) {
		return i == 0 ? ps[j] : ps[j]-ps[i-1];
	}
};
