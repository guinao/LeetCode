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
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int l1, int l2, int len) {
		if(len == 0)
			return NULL;
		int val = postorder[l2+len-1];
		TreeNode *root = new TreeNode(val);
		for(int i=0; i<len; ++i){
			if(inorder[l1+i] == val){
				root->left = helper(inorder, postorder, l1, l2, i);
				root->right = helper(inorder, postorder, l1+i+1, l2+i, len-i-1);
			}
		}
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return helper(inorder, postorder, 0, 0, inorder.size());
	}
};