#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if(head==NULL || head->next==NULL)
			return head;

		ListNode *odd = head, *even = head->next;
		ListNode *cur1 = odd, *cur2 = even;

		while(cur2 && cur2->next){
			cur1->next = cur2->next;
			cur1 = cur1->next;
			cur2->next = cur1->next;
			cur2 = cur2->next;
		}
		cur1->next = even;

		return odd;
    }
};