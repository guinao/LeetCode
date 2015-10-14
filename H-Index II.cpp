#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if(citations.empty())
			return 0;

		long long lb = 0, ub = citations.size();

		while(lb+1 < ub){
			int mid = (lb+ub) / 2;
			if(citations[mid] <= citations.size()-mid){
				lb = mid;
			}else{
				ub = mid;
			}
		}

		int a = min((int)citations.size(), citations[(int)lb]);
		int b = citations.size() - 1 - lb;
		return max(a,b);
	}
};