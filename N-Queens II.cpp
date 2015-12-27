#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

class Solution {
private:
	void helper(vector<vector<string>>& ans, vector<string>& cur, int d, int k){
		if(d == cur.size()){
			vector<string> tmp(cur);
			for(int i=0; i<tmp.size(); ++i){
				for(int j=0; j<tmp[i].size(); ++j){
					if(tmp[i][j] == 'X')
						tmp[i][j] = '.';
				}
			}
			ans.push_back(tmp);
			return;
		}
		int dx[] = {1,1,-1,-1, 0, 0, -1, 1};
		int dy[] = {1,-1,1,-1, 1, -1, 0, 0};
		int n = cur.size();
		vector<pair<int,int> > pp;
		for(int i=d; i<d+1; ++i) for(int j=0; j<n; ++j){
			if(cur[i][j] == '.'){
				cur[i][j] = 'Q';
				pp.clear();
				for(int r=0; r<8; ++r){
					int nx = i+dx[r];
					int ny = j+dy[r];
					while(0<=nx && nx<n && 0<=ny && ny<n){
						assert(cur[nx][ny] != 'Q');
						if(cur[nx][ny] == '.'){
							pp.push_back(make_pair(nx, ny));
							cur[nx][ny] = 'X';
						}
						nx += dx[r];
						ny += dy[r];
					}
				}
				helper(ans, cur, d+1, k+1);
				cur[i][j] = '.';
				for(int r=0; r<pp.size(); ++r){
					cur[pp[r].first][pp[r].second] = '.';
				}
			}
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string> > ans;
		vector<string> grid(n, string(n, '.'));
		helper(ans, grid, 0, 0);
		return ans;
	}
};

//int main()
//{
//	int n;
//	Solution s;
//	while(EOF != scanf("%d", &n)){
//		s.solveNQueens(n);
//	}
//}