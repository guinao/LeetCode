#include <stack>
using namespace std;

class MinStack {
public:
    void push(int x) {
		s.push(x);
		if(minv.empty() || minv.top()>x){
			minv.push(x);
		}else{
			minv.push(minv.top());
		}
    }

    void pop() {
		if(!s.empty())
			s.pop();
		if(!minv.empty())
			minv.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minv.top();
    }
private:
	stack<int> s;
	stack<int> minv;
};