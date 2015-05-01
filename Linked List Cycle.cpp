#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(head == NULL)
			return false;

		ListNode *fast = head->next;
		ListNode *slow = head;

		while(fast != slow){
			if(fast == NULL)
				return false;
			fast = fast->next;
			if(fast == NULL)
				return false;
			fast = fast->next;
			slow = slow->next;
		}

		return true;
	}
};