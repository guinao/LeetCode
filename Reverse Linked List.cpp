#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *t1 = NULL, *t2 = head;

		while(t2 != NULL){
			ListNode *temp = t2->next;
			t2->next = t1;
			t1 = t2;
			t2 = temp;
		}

		return t1;
	}
};