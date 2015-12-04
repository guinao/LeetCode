#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode *pre = new ListNode(0);
		ListNode *cur = head;
		while(cur){
			ListNode *next = cur->next;
			ListNode *i = pre;
			while(i->next && cur->val >= i->next->val)
				i = i->next;
			cur->next = i->next;
			i->next = cur;
			cur = next;
		}
		return pre->next;
	}
};