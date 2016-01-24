#include <cstdio>

struct TreeNode{
	TreeNode *left, *right;
	int val;
	TreeNode(int x):left(NULL), right(NULL), val(x){}
};

class Solution {
private:
	TreeNode* helper(TreeNode* root){
		if(root == NULL)
			return NULL;

		TreeNode* last = helper(root->left);
		if(last){
			TreeNode* tmp = root->right;
			root->right = root->left;
			root->left = NULL;
			last->right = tmp;
			return helper(tmp);
		}else{
			return helper(root->right);
		}
	}

public:
	void flatten(TreeNode* root) {
		helper(root);
	}
};