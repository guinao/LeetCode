#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int h = 0;
		int n = citations.size();
		sort(citations.begin(), citations.end());

		for(int i=1; i<=citations.size(); ++i){
			h = max(h, min(i, citations[n-i]));
		}

		return h;
	}
};