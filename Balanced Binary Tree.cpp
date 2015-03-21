struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int max(int a, int b){
		return a > b ? a : b;
	}

	int abs(int x){
		return x > 0 ? x : -x;
	}

	bool isBalanced(TreeNode *root){
		if (NULL == root)
		{
			return true;
		}

        int l = getHeight(root->left);
		int r = getHeight(root->right);

		if(-1==l || -1==r || abs(l-r) > 1)
			return false;
		else
			return true;
    }
	
	int getHeight(TreeNode *node){
		if(NULL == node)
			return 0;
		
		int l = getHeight(node->left);
		int r = getHeight(node->right);

		if(-1==l || -1==r || abs(l-r) > 1)
			return -1;
		else
			return max(l, r) + 1;
	}
};