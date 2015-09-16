#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(p->val > q->val){
			TreeNode *t = p;
			p = q;
			q = t;
		}

        while(root){
			if(p->val <= root->val && root->val <= q->val)
				break;

			if(p->val >= root->val)
				root = root->right;
			else
				root = root->left;
		}

		return root;
    }
};