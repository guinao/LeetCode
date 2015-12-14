#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int height(TreeNode* root){
		int ret = -1;
		while(root){
			++ret;
			root = root->left;
		}
		return ret;
	}
public:
	int countNodes(TreeNode* root) {
		TreeNode* cur=root;
		int ans = 0, h = height(root);

		while(cur != NULL){
			if(height(cur->right) == h-1){
				ans += 1<<h;
				cur = cur->right;
			}else{
				ans += 1<<h-1;
				cur = cur->left;
			}
			--h;
		}

		return ans;
	}
};