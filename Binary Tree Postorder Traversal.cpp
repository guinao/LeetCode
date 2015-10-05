#include <cstdio>
#include <vector>
#include <utility>
#include <stack>
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		if(!root)
			return ans;
		stack<pair<TreeNode*,int> > s;

		s.push(make_pair(root, 0));
		while(!s.empty()){
			TreeNode *n = s.top().first;
			if(s.top().second == 1){
				ans.push_back(n->val);
				s.pop();
			}else{
				s.top().second = 1;
				if(n->right)
					s.push(make_pair(n->right, 0));
				if(n->left)
					s.push(make_pair(n->left, 0));
			}
		}

		return ans;
	}
};