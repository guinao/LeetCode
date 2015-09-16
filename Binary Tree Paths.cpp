#include <cstdio>
#include <string>
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
		if(root == NULL)
			return ans;

		char buf[32];
		sprintf(buf, "%d", root->val);
		string prefix(buf);
		if(root->left ==NULL && root->right==NULL){
			ans.push_back(prefix);
		}else{
			if(root->left)
				binaryTreePaths(root->left, prefix, ans);

			if(root->right)
				binaryTreePaths(root->right, prefix, ans);
		}

		return ans;
    }

	void binaryTreePaths(TreeNode* root, string prefix, vector<string>& ans){
		char buf[32];
		sprintf(buf, "->%d", root->val);
		prefix.append(buf);
		if(root->left==NULL && root->right==NULL)
			ans.push_back(prefix);
		else{
			if(root->left)
				binaryTreePaths(root->left, prefix, ans);

			if(root->right)
				binaryTreePaths(root->right, prefix, ans);
		}
	}
};