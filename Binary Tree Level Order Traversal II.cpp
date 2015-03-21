#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > v;
		if(!root)
			return v;

		stack<vector<int> > s;
		vector<TreeNode*> vt[2];
		vector<TreeNode*> &cur = vt[0], &pre = vt[1];
		cur.push_back(root);
		while(cur.size() != 0){
			vector<int> temp;
			pre.clear();
			for(int i=0; i<cur.size(); ++i){
				temp.push_back(cur[i]->val);
				if(cur[i]->left != NULL)
				{
					pre.push_back(cur[i]->left);
				}
				if(cur[i]->right != NULL)
				{
					pre.push_back(cur[i]->right);
				}
			}
			s.push(temp);
			vector<TreeNode*> &swa = cur;
			cur = pre;
			pre = swa;
		}

		while(!s.empty()){
			v.push_back(s.top());
			s.pop();
		}
		return v;
    }
};