#include <stack>
#include <algorithm>
using namespace std;

class Queue {
private: 
	stack<int> s;
	stack<int> t;

public:

	// Push element x to the back of queue.
	void push(int x) {
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if(!t.empty())
			t.pop();
		else{
			while(!s.empty()){
				t.push(s.top());
				s.pop();
			}
			t.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if(!t.empty()){
			return t.top();
		}else{
			while(!s.empty()){
				t.push(s.top());
				s.pop();
			}
			return t.top();
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s.empty() && t.empty();
	}
};