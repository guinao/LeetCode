#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int i=0;
		for(; s[i] == ' '; ++i);

		if(s[i] == '+' || s[i] == '-') ++i;

		int n_nm, n_pt;
		for(n_nm=0, n_pt=0; isdigit(s[i])||s[i]=='.'; ++i)
			s[i] == '.' ? n_pt++ : n_nm++;

		if(n_pt > 1 || n_nm<1)
			return false;

		if(s[i] == 'e'){
			++i;
			if(s[i] == '+' || s[i] == '-') ++i;
			for(n_nm = 0; isdigit(s[i]); ++i, ++n_nm);
			if(n_nm < 1)
				return false;
		}

		for(; s[i] == ' '; ++i);

		return s[i] == '\0';
	}
};