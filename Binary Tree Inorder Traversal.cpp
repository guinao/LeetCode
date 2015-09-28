#include <cstdio>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		if(!root)
			return ans;

		visitor(root, ans);

		return ans;
	}

	void visitor(TreeNode* root, vector<int>& ans){
		if(root->left)
			visitor(root->left, ans);

		ans.push_back(root->val);

		if(root->right)
			visitor(root->right, ans);
	}
};