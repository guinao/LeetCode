#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
			return head;

		ListNode *cur = head;
		ListNode *nxt = cur->next;
		while(nxt){
			if(cur->val != nxt->val){
				cur->next = nxt;
				cur = nxt;
			}
			nxt = nxt->next;
		}

		cur->next = NULL;

		return head;
    }
};

int main()
{
	Solution s;
	ListNode *a1 = new ListNode(1);
	a1 = s.deleteDuplicates(a1);
	while(!a1){
		printf("%d ", a1->val);
		a1 = a1->next;
	}
	puts("");
	return 0;
}