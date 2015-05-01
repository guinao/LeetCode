#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	map<int, UndirectedGraphNode*> mm;

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node)
			return NULL;

		if(mm.find(node->label) != mm.end())
			return mm[node->label];

		UndirectedGraphNode *g = new UndirectedGraphNode(node->label);
		mm[node->label] = g;
		vector<UndirectedGraphNode*> &ns = node->neighbors;
		for(int i=0; i<ns.size(); ++i){
			g->neighbors.push_back(cloneGraph(ns[i]));
		}
		return g;
	}
};