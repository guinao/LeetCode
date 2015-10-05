#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if(board.empty())
			return;

		int n = board.size();
		int m = board[0].size();
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				int cnt = 0;
				for(int dx=-1; dx<=1; ++dx){
					for(int dy=-1; dy<=1; ++dy){
						int nx = i+dx, ny = j+dy;
						if(0<=nx && nx<n && 0<=ny && ny<m)
							cnt += board[nx][ny]&1;
					}
				}
				cnt -= board[i][j];
				if(board[i][j] && (cnt==2 || cnt==3))
					board[i][j] |= 2;
				if(board[i][j]==0 && cnt==3)
					board[i][j] |= 2;
			}
		}

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				board[i][j] >>= 1;
			}
		}
	}
};