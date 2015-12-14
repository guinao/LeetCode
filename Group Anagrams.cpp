#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, int> m;
		vector<vector<string>> ans;

		int id = 0;
		for(int i=0; i<strs.size(); ++i){
			string key = strs[i];
			sort(key.begin(), key.end());
			if(m.find(key) == m.end()){
				m[key] = ++id;
				ans.push_back(vector<string>());
			}
			ans[id].push_back(strs[i]);
		}

		for(vector<string> s : ans){
			sort(s.begin(), s.end());
		}
		return ans;
	}
};