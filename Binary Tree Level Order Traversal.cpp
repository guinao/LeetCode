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

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if(!root)
			return ans;

        queue<TreeNode*> a[2];
		int cur = 0, pre = 1;
		a[cur].push(root);
		while(!a[cur].empty()){
			vector<int> t;
			while(!a[cur].empty()){
				TreeNode *node = a[cur].front();
				a[cur].pop();
				t.push_back(node->val);
				if(node->left)
					a[pre].push(node->left);
				if(node->right)
					a[pre].push(node->right);
			}
			ans.push_back(t);
			cur = pre;
			pre = (pre+1)%2;
		}
		return ans;
    }
};