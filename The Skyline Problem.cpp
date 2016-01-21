#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int,int>> ans;
		if(buildings.size() == 0)
			return ans;

		priority_queue<pair<int,int> > living;
		int i=0, h = -1;
		while(i<buildings.size() || !living.empty()){
			int cur = living.empty() ? buildings[i][0] : living.top().second;

			if(i>=buildings.size() || buildings[i][0] > cur){
				while(!living.empty() && living.top().second <= cur)
					living.pop();
			}else{
				cur = buildings[i][0];
				while(i<buildings.size() && buildings[i][0] == cur){
					living.push(make_pair(buildings[i][2], buildings[i][1]));
					++i;
				}
			}

			h = living.empty()? 0 : living.top().first;
			if(ans.empty() || ans.back().second!=h)
				ans.push_back(make_pair(cur, h));
		}

		return ans;
	}
};