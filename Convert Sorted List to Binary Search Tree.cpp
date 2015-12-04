#include <cstdio>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* covert(ListNode* begin, ListNode* end=NULL){
		if(begin == end)
			return NULL;

		ListNode *slow = begin, *fast = begin;
		while(fast != end){
			fast = fast->next;
			if(fast != end)
				fast = fast->next;
			else
				break;
			slow = slow->next;
		}
		TreeNode *tn = new TreeNode(slow->val);
		tn->left = covert(begin, slow);
		tn->right = covert(slow->next, end);
		return tn;
	}

public:
	TreeNode* sortedListToBST(ListNode* head) {
		return covert(head);
	}
};