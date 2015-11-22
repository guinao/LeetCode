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
private:
	int globalmax;
	int maxPathSumHelper(TreeNode* root) {
		if(!root)
			return INT_MIN;
		else{
			int l = max(maxPathSumHelper(root->left), 0);
			int r = max(maxPathSumHelper(root->right), 0);
			globalmax = max(l+r+root->val, globalmax);
			return max(l + root->val, r + root->val);
		}
	}
public:
	int maxPathSum(TreeNode* root) {
		globalmax = INT_MIN;
		maxPathSumHelper(root);
		return globalmax;
	}
};
