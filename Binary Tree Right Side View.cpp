#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> ans;
		if(!root)
			return ans;

		int val;
		queue<TreeNode*> q[2];
		queue<TreeNode*> &cur = q[0], &nxt = q[1];
		cur.push(root);
		while(!cur.empty()){
			while(!cur.empty()){
				TreeNode* t = cur.front();
				cur.pop();
				val = t->val;
				if(t->left)
					nxt.push(t->left);
				if(t->right)
					nxt.push(t->right);
			}
			ans.push_back(val);
			swap(cur, nxt);
		}

		return ans;
	}
};

int main()
{
	Solution s;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->left = t2;
	vector<int> ans = s.rightSideView(t1);
	for(int i=0; i<ans.size(); ++i){
		cout << ans[i] << " ";
	}
	cout<<endl;
	getchar();
	return 0;
}