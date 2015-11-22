#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if(!root)
			return 0;
		queue<pair<TreeNode*,int> > q;
		int ans = 0;
		q.push(make_pair(root, root->val));
		while(!q.empty()){
			TreeNode* cur = q.front().first;
			int num = q.front().second;
			q.pop();
			if(!cur->left && !cur->right){
				ans += num;
				continue;
			}
			if(cur->left){
				q.push(make_pair(cur->left, num*10+cur->left->val));
			}
			if(cur->right)
				q.push(make_pair(cur->right, num*10+cur->right->val));
		}

		return ans;
	}
};
