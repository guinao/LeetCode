#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if(head==NULL || head->next==NULL)
			return true;

		ListNode *slow = head;
		ListNode *fast = head;
		while(fast->next!=NULL && fast->next->next!=NULL){
			fast = fast->next->next;
			slow = slow->next;
		}

		slow = reverseLinkedList(slow->next);
		while(slow != NULL){
			if(slow->val != head->val)
				return false;
			head = head->next;
			slow = slow->next;
		}
		return true;
	}

	ListNode* reverseLinkedList(ListNode *head){
		ListNode* s = NULL;
		ListNode* t = head;
		while(t){
			ListNode* temp = t->next;
			t->next = s;
			s = t;
			t = temp;
		}
		return s;
	}
};

int main()
{
	Solution S;
	ListNode* s1 = new ListNode(1);
	ListNode* s2 = new ListNode(2);
	s1->next = s2;
	printf("%d\n", S.isPalindrome(s1));
	getchar();
	delete s1;
	delete s2;
}