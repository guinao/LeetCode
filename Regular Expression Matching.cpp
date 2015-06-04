#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1<<10;

int dp[maxn][maxn];

class Solution {
public:
	bool isMatch(string s, string p) {
		memset(dp, -1, sizeof dp);
		dp[0][0] = 1;
		for(int i=1; i<=s.size(); ++i){
			dp[i][0] = 0;
		}
		return match(s, p, s.size(), p.size()) == 1;

	}

	int match(string s, string p, int i, int j){
		if(i<0 || j<0)
			return 0;

		if(dp[i][j] != -1)
			return dp[i][j];

		if(i==0 && j!=0){
			dp[i][j] = p[j-1] == '*' && match(s,p,i,j-2)==1;
			return dp[i][j];
		}

		if(p[j-1] == '.'){
			dp[i][j] = match(s, p, i-1, j-1);
			return dp[i][j];
		}
		
		if(p[j-1] == '*'){
			dp[i][j] = match(s, p, i, j-2);
			if(dp[i][j] != 1){
				char a = p[j-2];
				if(a == s[i-1] || a=='.'){
					dp[i][j] = match(s, p, i-1, j);
//					if(dp[i][j] != 1)
//						dp[i][j] = match(s,p,i-1,j-2);
				}
			}
			return dp[i][j];
		}
		else{ // two chars
			dp[i][j] = s[i-1]==p[j-1] && match(s,p,i-1,j-1)==1;
			return dp[i][j];
		}
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.isMatch("aab", "c*a*b"));
	printf("%d\n", s.isMatch("aa", "a"));
	printf("%d\n", s.isMatch("aa", "aa"));
	printf("%d\n", s.isMatch("aaa", "aa"));
	printf("%d\n", s.isMatch("aa", "a*"));
	printf("%d\n", s.isMatch("aa", ".*"));
	printf("%d\n", s.isMatch("ab", ".*"));
	getchar();
	return 0;
}