#include <queue>
#include <utility>>
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
    int maxDepth(TreeNode *root) {
		if(!root)
			return 0;

        queue<pair<TreeNode*, int> > q;
		q.push(make_pair(root, 1));
		int d = 0;
		while(!q.empty()){
			TreeNode* t = q.front().first;
			d = q.front().second;
			if(t->left != NULL)
				q.push(make_pair(t->left, d+1));
			if(t->right != NULL)
				q.push(make_pair(t->right, d+1));
		}

		return d;
    }
};