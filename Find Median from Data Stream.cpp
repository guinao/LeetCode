#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class MedianFinder {
private:
	priority_queue<double> big, little;

public:

	// Adds a number into the data structure.
	void addNum(int num) {
		little.push(num);
		big.push(-little.top());
		little.pop();
		while(little.size() < big.size()){
			little.push(-big.top());
			big.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if(little.size() == big.size()){
			return (little.top()-big.top()) / 2;
		}else{
			return little.top();
		}
	}
};

int main()
{
	MedianFinder mf;
	mf.addNum(1);
	mf.addNum(2);
	printf("%lf\n", mf.findMedian());
	mf.addNum(3);
	printf("%lf\n", mf.findMedian());
	return 0;
}
// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();