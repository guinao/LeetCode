#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(0);
		ListNode *h2 = new ListNode(0);
		ListNode *p1 = h1, *p2 = h2, *cur = head;

		while(cur){
			if(cur->val < x){
				p1->next = cur;
				cur = cur->next;
				p1 = p1->next;
			}else{
				p2->next = cur;
				cur = cur->next;
				p2 = p2->next;
			}
		}

		p1->next = h2->next;
		p2->next = NULL;

		return h1->next;
    }
};