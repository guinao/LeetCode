#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct TrieNode{
	TrieNode* next[26];
	bool isLeaf;
	string word;

	TrieNode(){
		isLeaf = false;
		word = "";
		for(int i=0; i<26; ++i)
			next[i] = NULL;
	}
};

class Solution {
private:
	TrieNode *root;
	int target;

	void helper(unordered_set<string>& ans, vector<vector<char> >& board, vector<vector<bool> >& mark, TrieNode* cur, int x, int y){
		static int dx[] = {1, -1, 0, 0};
		static int dy[] = {0, 0, 1, -1};
		int n = board.size(), m = board[0].size();

		if(cur->isLeaf)
			ans.insert(cur->word);

		if(ans.size() == target)
			return;

		for(int i=0; i<4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(0<=nx && nx<n && 0<=ny && ny<m && !mark[nx][ny]){
				int p = board[nx][ny] - 'a';
				if(cur->next[p] != NULL){
					mark[nx][ny] = true;
					helper(ans, board, mark, cur->next[p], nx, ny);
					mark[nx][ny] = false;
				}
			}
		}
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if(board.size()==0 || words.size()==0)
			return vector<string>();

		root = new TrieNode();
		for(int i=0; i<words.size(); ++i){
			TrieNode* cur = root;
			for(int j=0; j<words[i].size(); ++j){
				int x = words[i][j] - 'a';
				if(cur->next[x] == NULL)
					cur->next[x] = new TrieNode();

				cur = cur->next[x];
			}
			cur->isLeaf = true;
			cur->word = words[i];
		}

		target = words.size();
		int n = board.size(), m = board[0].size();
		vector<vector<bool> > mark(n, vector<bool>(m, false));
		unordered_set<string> set;
		for(int i=0; i<n&&set.size()<target; ++i){
			for(int j=0; j<m&&set.size()<target; ++j){
				int x = board[i][j] - 'a';
				if(root->next[x] != NULL){
					mark[i][j] = true;
					helper(set, board, mark, root->next[x], i, j);
					mark[i][j] = false;
				}
			}
		}

		return vector<string>(set.begin(), set.end());
	}
};