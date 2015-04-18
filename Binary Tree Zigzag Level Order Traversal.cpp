#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		stack<TreeNode*> s[2];
		int l = 0;

		if(root)
			s[l].push(root);

		while (!s[l].empty()){
			vector<int> row;
			while(!s[l].empty()){
				TreeNode* t = s[l].top();
				s[l].pop();
				row.push_back(t->val);
				if(l == 0){
					if(t->left)
						s[1].push(t->left);
					if(t->right)
						s[1].push(t->right);
				}else{
					if(t->right)
						s[0].push(t->right);
					if(t->left)
						s[0].push(t->left);
				}
			}
			ans.push_back(row);
			l = (l+1) % 2;
		}

		return ans;
	}
};