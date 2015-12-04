#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void helper(vector<vector<int> >& ans, vector<int> &cur, TreeNode* root, int sum){
		if(!root)
			return;

		sum -= root->val;
		cur.push_back(root->val);
		if(root->left==NULL && root->right==NULL){
			if(sum == 0)
				ans.push_back(cur);
		}
		if(root->left)
			helper(ans, cur, root->left, sum);
		if(root->right)
			helper(ans, cur, root->right, sum);

		cur.pop_back();
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		vector<int> cur;
		helper(ans, cur, root, sum);
		return ans;
	}
};