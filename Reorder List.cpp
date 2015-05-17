#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
		if(!head || !head->next) return ;

		// Find the midlle & last node;
        ListNode* slow = head;
		ListNode* fast = head;
		while(fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
		}
		
		// Reverse the last part
		ListNode* p1 = slow->next;
		ListNode* p2 = p1->next;
		p1->next = NULL;
		slow->next = NULL;
		while(p2){
			ListNode* t = p2->next;
			p2->next = p1;
			p1= p2;
			p2 = t;
		}

		// Reorder list
		p2 = head;
		while(p1){
			ListNode *t1 = p2->next;
			p2->next = p1;
			ListNode *t2 = p1->next;
			p1->next = t1;
			p2 = t1;
			p1 = t2;
		}
    }
};

int main()
{
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	for(int i=1; i<5; ++i){
		p->next = new ListNode(i);
		p = p->next;
	}
	Solution s;
	s.reorderList(head);
	p = head;
	while(p){
		printf("%d->", p->val);
		p = p->next;
	}
	printf("\n");
	getchar();
	return 0;
}