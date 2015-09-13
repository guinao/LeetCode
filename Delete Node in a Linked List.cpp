class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode *n = node->next;
		node->val = node->next->val;
		node->next = node->next->next;
		free(n);
	}
};