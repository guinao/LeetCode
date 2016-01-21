#include <cstdio>
#include <cstring>

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head = NULL;
		TreeLinkNode* pre = NULL;
		TreeLinkNode* cur = root;
		while(cur){
			while(cur){
				if(cur->left){
					if(pre)
						pre->next = cur->left;
					else
						head = cur->left;
					pre = cur->left;
				}
				
				if(cur->right){
					if(pre)
						pre->next = cur->right;
					else
						head = cur->right;
					pre = cur->right;
				}

				cur = cur->next;
			}
			cur = head;
			pre = NULL;
			head = NULL;
		}
    }
};