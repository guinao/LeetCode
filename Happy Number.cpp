#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		set<int> s;
		while(n != 1){
			if(s.find(n) != s.end())
				return false;
			s.insert(n);
			int w = 0;
			while(n){
				int t = n % 10;
				w += t*t;
				n /= 10;
			}
			n = w;
		}
		return true;
	}
};