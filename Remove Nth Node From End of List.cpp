struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *a = head;
		ListNode *b = head;
		int cnt = 0;
		while(NULL != a){
			a = a->next;
			++cnt;
		}
		if(cnt == n){
			head = head->next;
		}else{
			for (int i=1; i<cnt-n; ++i)
			{
				b = b->next;
			}
			b->next = b->next->next;
		}
		return head;
    }
};