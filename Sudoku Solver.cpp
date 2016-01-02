#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool helper(vector<vector<char>>& board, vector<vector<bool>>& mask, int pos = 0){
		for(; pos < 81; ++pos){
			int x = pos / 9, y = pos%9;
			if(board[x][y] == '.'){
				vector<bool> &v1 = mask[x], &v2=mask[y+9], &v3 = mask[x/3*3+y/3+18];
				for(int i=1; i<=9; ++i){
					if(!v1[i] && !v2[i] && !v3[i]){
						//						    printf("%d %d %d\n", x, y, i);
						board[x][y] = i+'0';
						v1[i] = v2[i] = v3[i] = true;
						if(helper(board, mask, pos+1)){
							return true;
						}
						board[x][y] = '.';
						v1[i] = v2[i] = v3[i] = false;
					}
				}
				return false;
			}
		}
		return true;
	}

public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<bool> > mask(27, vector<bool>(10, false));
		vector<vector<int> > map;

		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j){
				if(isdigit(board[i][j])){
					int id = board[i][j] - '0';
					mask[i][id] = true;
					mask[j+9][id] = true;
					mask[i/3*3+j/3+18][id] = true;
				}
			}
		}

		helper(board, mask);
	}
};