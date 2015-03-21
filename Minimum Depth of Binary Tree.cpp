#include <queue>
#include <utility>
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
    int minDepth(TreeNode *root) {
		if(!root)
			return 0;
        queue<pair<TreeNode*, int> > q;
		q.push(make_pair(root, 1));
		while(!q.empty()){
			TreeNode *t = q.front().first;
			int d = q.front().second;
			q.pop();
			if(NULL == t->left && NULL == t->right)
				return d;
			if(NULL != t->left)
				q.push(make_pair(t->left, d+1));
			if(NULL != t->right)
				q.push(make_pair(t->right, d+1));
		}
		return 0;
    }
};