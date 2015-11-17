#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if(s.length() == 0)
			return 0;

		vector<int> dp(s.length()+1);
		dp[0] = 1;
		if(s[0] != '0')
			dp[1] = 1;
		for(int i=1; i<s.length(); ++i){
			if(s[i] != '0')
				dp[i+1] += dp[i];
			if(s[i-1]!='0') if((s[i-1]-'0')*10+s[i]-'0' <= 26)
				dp[i+1] += dp[i-1];
		}
		return dp[s.length()];
	}
};