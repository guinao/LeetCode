#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if(!head) return NULL;

        ListNode *fast = head;
		ListNode *slow = head;

		while(fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				ListNode *ans = head;
				while(slow != ans){
					slow = slow->next;
					ans = ans->next;
				}
				return ans;
			}
		}

		return NULL;
    }
};