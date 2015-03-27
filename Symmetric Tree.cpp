#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	bool isSymmetric(TreeNode *root) {
//		if(!root)
//			return true;
//		return compare(root->left, root->right);
//	}
//
//	bool compare(TreeNode *left, TreeNode *right){
//		if(NULL==left || NULL==right)
//			return left == right;
//		if(left->val != right->val)
//			return false;
//		return compare(left->left, right->right) 
//			&& compare(left->right, right->left);
//
//	}
//};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if(!root)
			return true;
		if(root->left==NULL || root->right==NULL)
			return root->left == root->right;

		bool ret = true;

		queue<TreeNode*> q;
		q.push(root->left);
		q.push(root->right);
		while(!q.empty() && ret){
			TreeNode *a = q.front();
			q.pop();
			TreeNode *b = q.front();
			q.pop();
			if(NULL==a || NULL==b){
				ret &= a==b;
			}else{
				ret &= a->val == b->val;
				q.push(a->left);
				q.push(b->right);
				q.push(a->right);
				q.push(b->left);
			}
		}

		return ret;
	}
};