#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.length(), m = t.length();
		vector<vector<int>> dp(n+1, vector<int>(m+1));
		for(int i=0; i<=n; ++i)
			dp[i][0] = 1;

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				dp[i+1][j+1] = dp[i][j+1];
				if(s[i] == t[j])
					dp[i+1][j+1] += dp[i][j];
			}
		}

		return dp[n][m];
	}
};