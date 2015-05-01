#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int ret = -1;
		vector<int> margin;
		int n = gas.size();
		margin.resize(n);
		for(int i=0; i<n; ++i)
			margin[i] = gas[i] - cost[i];

		int s = 0, e = 0;
		int sum = 0;
		do{
			if(sum >= 0)
				sum += margin[e++];
			else{
				--s;
				if(s < 0)
					s += n;
				sum += margin[s];
			}
		}while((s-e+n)%n != 0);

		if(sum >= 0)
			ret = s;
		return ret;
	}
};

int main()
{
	vector<int> cost;
	vector<int> gas;
	Solution s;
	int n, a;
	while(EOF != scanf("%d", &n)){
		gas.resize(n);
		cost.resize(n);
		for(int i=0; i<n; ++i){
			scanf("%d", &a);
			gas[i] = a;
		}
		for(int i=0; i<n; ++i){
			scanf("%d", &a);
			cost[i] = a;
		}
		printf("%d\n", s.canCompleteCircuit(gas, cost));
	}
	return 0;
}