#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *ret = new ListNode(0);
		ret->next = head;
		ListNode *cur = ret;
		while(cur->next && cur->next->next){
			if(cur->next->val == cur->next->next->val){
				ListNode *next = cur->next;
				int val = cur->next->val;
				while(next && next->val == val){
					next = next->next;
				}
				cur->next = next;
			}else
				cur = cur->next;
		}
		return ret->next;
	}
};