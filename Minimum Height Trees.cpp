#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<vector<int> > g;
	vector<int> degree;

	void addEdge(int x, int y){
		g[x].push_back(y);
		g[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		g = vector<vector<int>>(n);
		degree.resize(n);
		fill(degree.begin(), degree.end(), 0);

		vector<int> leaf, next;

		for(int i=0; i<edges.size(); ++i){
			addEdge(edges[i].first, edges[i].second);
		}

		for(int i=0; i<n; ++i){
			if(degree[i] == 1)
				leaf.push_back(i);
		}

		while(n > 2){
			for(int i=0; i<leaf.size(); ++i){
				vector<int> &cur = g[leaf[i]];
				for(int j=0; j<cur.size(); ++j){
					if(--degree[cur[j]] == 1)
						next.push_back(cur[j]);
				}
			}
			leaf = next;
		}

		return leaf;
	}
};