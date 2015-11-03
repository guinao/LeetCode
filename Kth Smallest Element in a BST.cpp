#include <vector>
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
	int kthSmallest(TreeNode* root, int k) {
		return findkth(root, k);
	}

	int findkth(TreeNode* root, int& k){
		int ret;
		if(root->left)
			ret = findkth(root->left, k);

		if(--k == 0)
			ret = root->val;
		else if(k > 0 && root->right)
			ret = findkth(root->right, k);

		return ret;
	}
};