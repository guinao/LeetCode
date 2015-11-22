#include <cstdio>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	stack<TreeNode*> s;

public:
    BSTIterator(TreeNode *root) {
		TreeNode *cur = root;
        while(cur){
			s.push(cur);
			cur = cur->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = s.top();
		s.pop();
		int ret = cur->val;
		cur = cur->right;
		while(cur){
			s.push(cur);
			cur = cur->left;
		}
		return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */