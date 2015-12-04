#include <cstdio>
#include <vector>
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
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l1, int l2, int len){
		if(len == 0)
			return NULL;

		int val = preorder[l1];
		TreeNode *root = new TreeNode(val);
		for(int i=0; i<len; ++i){
			if(inorder[l2+i] == val){
				root->left = helper(preorder, inorder, l1+1, l2, i);
				root->right = helper(preorder, inorder, l1+1+i, l2+i+1, len-i-1);
				return root;
			}
		}
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helper(preorder, inorder, 0, 0, preorder.size());
	}
};