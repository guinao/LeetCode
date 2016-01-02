#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ans;
		if(intervals.size() == 0 || intervals[0].start>newInterval.end){
			ans.push_back(newInterval);
			for(int i=0; i<intervals.size(); ++i)
				ans.push_back(intervals[i]);
			return ans;
		}

		int i=0;
		for(; i<intervals.size(); ++i){
			if(intervals[i].end < newInterval.start)
				ans.push_back(intervals[i]);
			else
				break;
		}

		for(; i<intervals.size(); ++i){
			if(intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end)
				newInterval.start = intervals[i].start;
			else
				break;
		}

		for(; i<intervals.size(); ++i){
			if(intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end)
				newInterval.end = intervals[i].end;
			else
				break;
		}

		ans.push_back(newInterval);

		for(; i<intervals.size(); ++i)
			ans.push_back(intervals[i]);

		return ans;
    }
};