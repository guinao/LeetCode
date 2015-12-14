#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	bool find(vector<vector<char>>& board, vector<vector<bool>>& mark, string& word, int pos, int x, int y){
		static int dx[] = {0, 0, 1, -1};
		static int dy[] = {1, -1, 0, 0};
		int n = board.size(), m = board[0].size();
		if(pos == word.length())
			return true;
		else{
			for(int i=0; i<4; ++i){
				int nx = x + dx[i], ny = y + dy[i];
				if(0<=nx && nx < n && 0<=ny && ny<m 
					&& board[nx][ny] == word[pos] && !mark[nx][ny]){
						mark[nx][ny] = true;
						bool ret = find(board, mark, word, pos+1, nx, ny);
						mark[nx][ny] = false;
						if(ret)
							return ret;
				}
			}
		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		int n = board.size(), m = board[0].size();
		vector<vector<bool> > mark(n, vector<bool>(m, false));

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(board[i][j] == word[0]){
					mark[i][j] = true;
					if(find(board, mark, word, 1, i, j))
						return true;
					mark[i][j] = false;
				}
			}
		}
		return false;
	}
};