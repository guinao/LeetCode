#include <cstdio>
#include <vector>
#include <string>
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
	TreeNode *mistake1=NULL, *mistake2=NULL;
	TreeNode *pre=new TreeNode(INT_MIN);

	void inorder(TreeNode* root){
		if(root == NULL)
			return ;

		inorder(root->left);

		if(mistake1==NULL && pre->val > root->val)
			mistake1 = pre;

		if(mistake1!=NULL && pre->val > root->val)
			mistake2 = root;

		pre = root;

		inorder(root->right);
	}

public:
	void recoverTree(TreeNode* root) {
		inorder(root);

		int t = mistake1->val;
		mistake1->val = mistake2->val;
		mistake2->val = t;
	}
};