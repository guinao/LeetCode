#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
	bool operator()(const ListNode* l1, const ListNode* l2){
		return l1->val > l2->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, compare> pq;
		for(int i=0; i<lists.size(); ++i){
			if(lists[i] != NULL)
				pq.push(lists[i]);
		}

		ListNode* pre = new ListNode(0);
		ListNode* cur = pre;
		while(!pq.empty()){
			ListNode* node = pq.top();
			pq.pop();
			cur->next = node;
			cur = cur->next;
			if(node->next)
				pq.push(node->next);
		}

		return pre->next;
	}
};