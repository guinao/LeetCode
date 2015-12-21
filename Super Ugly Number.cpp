#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> nums(n);
		vector<int> idx(primes.size());
		vector<int> cur(primes);

		nums[0] = 1;
		
		for(int i=1; i<n; ++i){
			int pos = 0;
			for(int j=0; j<primes.size(); ++j){
				cur[j] = primes[j] * nums[idx[j]];
				if(cur[j] > cur[pos])
					pos = j;
			}
			nums[i] = cur[pos];
			for(int j=0; j<primes.size(); ++j){
				if(cur[pos] == cur[j])
					++idx[j];
			}
		}

		return nums[n-1];
	}
};