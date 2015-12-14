#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ans;
		vector<vector<int>> g;
		vector<int> degree(numCourses, 0);
		g.resize(numCourses);
		for(int i=0; i<prerequisites.size(); ++i){
			pair<int,int> &p = prerequisites[i];
			g[p.second].push_back(p.first);
			++degree[p.first];
		}
		queue<int> q;
		for(int i=0; i<numCourses; ++i){
			if(degree[i] == 0)
				q.push(i);
		}
		while(!q.empty()){
			int c = q.front();
			q.pop();
			ans.push_back(c);
			for(int i=0; i<g[c].size(); ++i){
				degree[g[c][i]]--;
				if(degree[g[c][i]] == 0)
					q.push(g[c][i]);
			}
		}
		if(ans.size() < numCourses)
			ans.clear();
		return ans;
	}
};