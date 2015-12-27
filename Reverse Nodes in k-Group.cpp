#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* reverse(ListNode* head, ListNode* tail){
		ListNode *pre = tail;
		ListNode *cur = head;
		while(cur != tail){
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}

public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *pre = new ListNode(0);
		pre->next = head;
		ListNode *fast=head, *slow=pre;
		while(fast){
			for(int i=0; i<k; ++i){
				if(fast)
					fast = fast->next;
				else
					return pre->next;
			}
			slow->next = reverse(slow->next, fast);
			for(int i=0; i<k; ++i)
				slow = slow->next;
		}
		return pre->next;
	}
};
