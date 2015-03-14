#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ans;
		for(int i=1; i<=numRows; ++i){
			vector<int> v;
			v.resize(i);
			v[0] = 1;
			for(int j=1; j<i-1; ++j){
				v[j] = ans[i-2][j-1] + ans[i-2][j];
			}
			if(i > 1){
				v[i-1] = 1;
			}
			ans.push_back(v);
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > v = s.generate(5);
	return 0;
}