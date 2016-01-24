#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if(matrix.size() == 0)
			return 0;

		int m = matrix.size(), n = matrix[0].size();

		vector<pair<int, pair<int,int> > > s;
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				s.push_back(make_pair(matrix[i][j], make_pair(i,j)));
			}
		}
		sort(s.begin(), s.end());

		vector<vector<int> > dp(m, vector<int>(n, 1));
		static int dx[] = {1, -1, 0, 0};
		static int dy[] = {0, 0, 1, -1};

		int ans = 1;
		for(int i=s.size()-1; i>=0; --i){
			int x = s[i].second.first;
			int y = s[i].second.second;
			for(int j=0; j<4; ++j){
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(0<=nx && nx<m && 0<=ny && ny<n && matrix[x][y]<matrix[nx][ny]){
					dp[x][y] = max(dp[x][y], 1+dp[nx][ny]);
				}
			}
			ans = max(ans, dp[x][y]);
		}

		return ans;
	}
};