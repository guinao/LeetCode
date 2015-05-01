#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if(!l1)
			return l2;


		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *ans = new ListNode(0);
		ListNode *cur = ans, *pre=NULL;
		int inc = 0;
        while(p1 || p2){
			int vv = inc;
			if(p1){
				vv += p1->val;
				p1 = p1->next;
			}
			if(p2){
				vv += p2->val;
				p2 = p2->next;
			}
			inc = 0;
			if(vv >= 10){
				vv -= 10;
				inc = 1;
			}
			cur->val = vv;
			pre = cur;
			cur->next = new ListNode(0);
			cur = cur->next;
		}
		if(inc)
			cur->val = inc;
		else{
			pre->next = NULL;
			delete cur;
		}

		return ans;
    }
};