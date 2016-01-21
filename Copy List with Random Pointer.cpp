#include <cstdio>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur = head;
		while(cur){
			RandomListNode *tmp = new RandomListNode(cur->label);
			RandomListNode* next = cur->next;
			cur->next = tmp;
			tmp->next = next;
			cur = next;
		}

		cur = head;
		while(cur){
			RandomListNode *copy = cur->next;
			if(cur->random)
				copy->random = cur->random->next;
			cur = copy->next;
		}

		cur = head;
		RandomListNode *pre = new RandomListNode(0);
		RandomListNode *tmp = pre;
		while(cur){
			tmp->next = cur->next;
			tmp = tmp->next;
			cur->next = tmp->next;
			cur = cur->next;
		}

		return pre->next;
    }
};