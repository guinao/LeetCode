#include <cstdlib>
#include <cstdio>
#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(NULL == l1)
			return l2;
		if(NULL == l2)
			return l1;
		if(NULL == l1 && NULL == l2)
			return NULL;

		ListNode *t1 = l1;
		ListNode *t2 = l2;
		ListNode *head = NULL;
		ListNode *cur = NULL;

		if(t1->val < t2->val){
			head = cur = t1;
			t1 = t1->next;
		}else{
			head = cur = t2;
			t2 = t2->next;
		}
        while(t1 != NULL && t2 != NULL){
			if(t1->val < t2->val){
				cur->next = t1;
				t1 = t1->next;
				cur = cur->next;
			}else{
				cur->next = t2;
				t2 = t2->next;
				cur = cur->next;
			}
		}
		if(NULL != t1)
			cur->next = t1;
		if(NULL != t2)
			cur->next = t2;
		return head;
    }
};

int main()
{
	Solution s;
	ListNode *a = new ListNode(5);
	ListNode *b = new ListNode(1);
	ListNode *c = new ListNode(2);
	ListNode *d = new ListNode(4);
	b->next = c;
	c->next = d;
	ListNode *mm = s.mergeTwoLists(b, a);
	while(mm != NULL){
		printf("%d ", mm->val);
		mm = mm->next;
	}
	printf("\n");
	scanf("\n");
}