#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string> > dp;
		dp.push_back(vector<string>(1, ""));
		for(int i=1; i<=n; ++i){
			dp.push_back(vector<string>());
			vector<string>& vs=dp[i];
			for(int j=0; j<i; ++j){
				for(int p=0; p<dp[j].size(); ++p)
					for(int q=0; q<dp[i-j-1].size(); ++q)
						vs.push_back("("+dp[j][p]+")"+dp[i-j-1][q]);
			}
		}
		return dp[n];
	}
};