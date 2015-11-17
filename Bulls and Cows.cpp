#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		stringstream ans;
		vector<int> va(10), vb(10);
		int cow = 0, bull = 0;

		for(int i=0; i<secret.length(); ++i){
			if(secret[i] == guess[i])
				++bull;
			else
				++va[secret[i]-'0'], ++vb[guess[i]-'0'];
		}
		for(int i=0; i<10; ++i)
			cow += min(va[i], vb[i]);
		ans << bull << 'A' << cow << 'B';

		return ans.str();
	}
};