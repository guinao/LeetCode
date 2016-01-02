#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if(s.length() == 0 || words.size() == 0)
			return ans;

		unordered_map<string, int> tf;
		for(int i=0; i<words.size(); ++i)
			++tf[words[i]];

		int wl = words[0].size();
		for(int i=0; i<wl; ++i){
			int start = i;
			int cnt = 0;
			unordered_map<string, int> cur;
			for(int j=i; j+wl<=s.length(); j+=wl){
				string word = s.substr(j, wl);
				if(tf[word] != 0){
					++cur[word];
					cnt++;
					if(cur[word] > tf[word]){
						for(; start<=j; start+=wl){
							string tmp = s.substr(start, wl);
							--cur[tmp];
							if(tmp == word)
								break;
						}
					}
					if(cnt == word.size()){
						ans.push_back(start);
					}
				}else{
					cur.clear();
					start = j+wl;
				}
			}
		}
		return ans;
	}
};