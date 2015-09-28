#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		if(n == 0)
			return ans;

		for(int i=1,s=1; i<=n; ++i,s<<=1){
			for(int j=s-1; j>=0; --j){
				ans.push_back(ans[j]+s);
			}
		}

		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> ans = s.grayCode(1);
	return 0;
}