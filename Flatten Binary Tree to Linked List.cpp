#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* helper(TreeNode *root, TreeNode *pre){
		if(root == NULL)
			return pre;

		pre = helper(root->right, pre);
		pre = helper(root->left, pre);
		root->right = pre;
		root->left = NULL;
		return root;
	}

public:
	void flatten(TreeNode* root) {
		if(root == NULL)
			return;

		helper(root, NULL);
	}
};