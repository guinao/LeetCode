#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
private:
	static int dx[4];
	static int dy[4];

	void bfs(vector<vector<char>>& board, int x, int y){
		board[x][y] = ' ';
		queue<pair<int,int> > q;
		int n = board.size(), m = board[0].size();
		q.push(make_pair(x,y));
		while(!q.empty()){
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for(int i=0; i<4; ++i){
				int nx = x+dx[i], ny=y+dy[i];
				if(0<=nx&&nx<n && 0<=ny && ny<m){
					if(board[nx][ny] == 'O'){
						board[nx][ny] = ' ';
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

public:
	void solve(vector<vector<char>>& board) {
		if(board.size() == 0)
			return;

		int n = board.size(), m = board[0].size();
		for(int i=0; i<m; ++i){
			if(board[0][i] == 'O')
				bfs(board, 0, i);
			if(board[n-1][i] == 'O')
				bfs(board, n-1, i);
		}

		for(int i=0; i<n; ++i){
			if(board[i][0] == 'O')
				bfs(board, i, 0);
			if(board[i][m-1] == 'O')
				bfs(board, i, m-1);
		}

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				// putchar(board[i][j]);
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == ' ')
					board[i][j] = 'O';
			}
			// 			putchar('\n');
		}
	}
};

int Solution::dx[4] = {0, 0, 1, -1};
int Solution::dy[4] = {1, -1, 0, 0};