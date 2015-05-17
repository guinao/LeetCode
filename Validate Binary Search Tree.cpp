#include <cstdio>
#include <cstdlib>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef long long ll;

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return valid(root);
	}

	bool valid(TreeNode *t, ll lb=(ll)INT_MIN-1, ll ub=(ll)INT_MAX+1){
		if(!t) return true;

		ll v = (ll)t->val;
		bool ret = v>lb && v<ub;
		if(ret){
			ret = valid(t->left, lb, v) 
				&& valid(t->right, v, ub);
		}
		return ret;
	}
};