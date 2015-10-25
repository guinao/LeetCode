#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(head==NULL || head->next==NULL)
			return head;

		ListNode* fast = head;
		int n = 0;
		while(fast != NULL){
			++n;
			fast = fast->next;
		}
		k %= n;

		fast = head;
		for(int i=0; i<k; ++i)
			fast = fast->next? fast->next : head;

		ListNode* slow = head;
		while(fast->next != NULL){
			fast = fast->next;
			slow = slow->next? slow->next : head;
		}

		ListNode* ans = slow->next? slow->next : head;
		if(ans != head){
			fast->next = head;
			slow->next = NULL;
		}

		return ans;
	}
};