#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > outedges(numCourses);
		vector<int> indegree(numCourses);

		for(int i=0; i<prerequisites.size(); ++i){
			pair<int,int> p = prerequisites[i];
			outedges[p.second].push_back(p.first);
			indegree[p.first]++;
		}

		queue<int> q;
		for(int i=0; i<numCourses; ++i){
			if(indegree[i] == 0)
				q.push(i);
		}

		int cnt = 0;
		while(!q.empty()){
			int v = q.front();
			q.pop();
			++cnt;

			for(auto u=outedges[v].begin(); u!=outedges[v].end(); ++u){
				indegree[*u]--;
				if(indegree[*u] == 0)
					q.push(*u);
			}
		}

		return cnt == numCourses;
	}
};