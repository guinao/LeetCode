#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *h = new ListNode(0);
		h->next = head;
		ListNode *first = h->next;
		ListNode *second = h;

		while(first && first->next){
			ListNode *tmp = first->next;
			second->next = tmp;
			first->next = tmp->next;
			tmp->next = first;
			second = first;
			first = first->next;
		}

		return h->next;
	}
};