#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int inc = 1;
		vector<int> ret;
		ret.resize(digits.size());
		int i = ret.size() - 1;
		for(vector<int>::reverse_iterator it=digits.rbegin();
			it != digits.rend(); ++it){
				ret[i] = *it + inc;
				inc = ret[i] / 10;
				ret[i] %= 10;
				--i;
		}
		if(inc != 0)
			ret.insert(ret.begin(), inc);
		return ret;
    }
};