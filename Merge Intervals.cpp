#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


static bool cmp(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		if(intervals.size() == 0)
			return ans;

		sort(intervals.begin(), intervals.end(), cmp);

		int s = intervals[0].start, e = intervals[0].end;
		for(int i=1; i<intervals.size(); ++i){
			if(intervals[i].start <= e)
				e = max(e, intervals[i].end);
			else{
				ans.push_back(Interval(s, e));
				s = intervals[i].start;
				e = intervals[i].end;
			}
		}
		ans.push_back(Interval(s, e));
		return ans;
	}
};