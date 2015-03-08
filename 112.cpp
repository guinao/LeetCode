#include <cstdio>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
		if(root == NULL){
			return false;
		}else{
			sum -= root->val;
			if(root->left == NULL && root->right == NULL){
				return sum == 0;
			}else if(root->left != NULL && root->right == NULL){
				return hasPathSum(root->left, sum);
			}else if(root->left == NULL && root->right != NULL){
				return hasPathSum(root->right, sum);
			}else{
				return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
			}
		}
		return false;
	}
};