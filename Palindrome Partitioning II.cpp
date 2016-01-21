#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		vector<int> cut(s.length()+1);

		for(int i=1; i<cut.size(); ++i)
			cut[i] = i-1;

		for(int i=1; i+1<s.length(); ++i){
			for(int j=i,k=i; j>=0&&k<s.length()&&s[j]==s[k]; --j,++k)
				cut[k+1] = min(cut[k+1], cut[j]+1);

			for(int j=i-1, k=i; j>=0&&k<s.length()&&s[j]==s[k]; --j,++k)
				cut[k+1] = min(cut[k+1], cut[j]+1);
		}

		return cut[s.length()];
	}
};