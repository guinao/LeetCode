#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
private:
	int n, m;
public:
	void fill(vector<vector<char>>& grid, vector<vector<bool>>& mark, int x, int y){
		static int dx[] = {1,-1,0,0};
		static int dy[] = {0, 0,1,-1};
		queue<pair<int,int> > q;
		mark[x][y] = true;
		q.push(make_pair(x,y));
		while(!q.empty()){
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for(int i=0; i<4; ++i){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(0<=nx && nx<n && 0<=ny && ny<m){
					if(grid[nx][ny]=='1' && !mark[nx][ny]){
						mark[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		n = grid.size();
		m = grid[0].size();

		int ans = 0;

		vector<vector<bool> > mark(n, vector<bool>(m, false));

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(grid[i][j]=='1' && !mark[i][j]){
					fill(grid, mark, i, j);
					++ans;
				}
			}
		}

		return ans;
	}
};