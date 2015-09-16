#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if(n <= 2)
			return 0;

		vector<bool> v;
		v.resize(n);
		v[0] = v[1] = true;
		int cnt = 0;
		for(int i=2; i<n; ++i){
			if(!v[i]){
				++cnt;
				for(int j=i*2; j<n; j+=i)
					v[j] = true;
			}
		}

		return cnt;
	}
};