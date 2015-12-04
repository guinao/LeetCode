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
	vector<TreeNode*> helper(int lb, int ub) {
		vector<TreeNode*> ans;
		if(ub-lb == 0){
			ans.push_back(NULL);
			return ans;
		}
		if(ub-lb == 1){
			ans.push_back(new TreeNode(lb));
			return ans;
		}
		printf("%d %d %d\n", n, lb, ub);
		for(int i=lb; i<ub; ++i){
			vector<TreeNode*> left = helper(lb, i);
			vector<TreeNode*> right = helper(i+1, ub);
			for(TreeNode* l : left){
				for(TreeNode* r : right){
					TreeNode* t = new TreeNode(i);
					t->left = l;
					t->right = r;
					ans.push_back(t);
				}
			}
		}
		return ans;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if(n == 0)
			return vector<TreeNode*>();
		return helper(1, n+1);
	}
};