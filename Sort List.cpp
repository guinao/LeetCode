#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* merge(ListNode* h1, ListNode* h2){
		ListNode* pre = new ListNode(0);
		ListNode* cur = pre;
		ListNode* p1 = h1, *p2 = h2;
		while(p1 && p2){
			if(p1->val < p2->val){
				cur->next = p1;
				p1 = p1->next;
			}else{
				cur->next = p2;
				p2 = p2->next;
			}
			cur = cur->next;
		}

		if(p1){
			cur->next = p1;
		}else{
			cur->next = p2;
		}

		return pre->next;
	}

public:
	ListNode* sortList(ListNode* head) {
		if(head==NULL || head->next==NULL)
			return head;

		ListNode* slow=head, *fast=head;

		while(fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = NULL;

		return merge(sortList(head), sortList(fast));
	}
};