#include <string>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool check(unordered_map<char,int>& us, unordered_map<char,int>& cur){
		for(auto it=us.begin(); it!=us.end(); ++it){
			if(cur[it->first] < it->second)
				return false;
		}
		return true;
	}

public:
	string minWindow(string s, string t) {
		unordered_map<char,int> us, cur;
		for(int i=0; i<t.length(); ++i){
			++us[t[i]];
			cur[t[i]] = 0;
		}
		string ans = "";
		vector<pair<char, int> > rec;
		for(int i=0; i<s.size(); ++i){
			if(us.find(s[i]) != us.end())
				rec.push_back(make_pair(s[i], i));
		}
		int i=0,j=-1;
		while(i<rec.size()){
			if(!check(us, cur)){
				++j;
				if(j==rec.size())
					break;
				++cur[rec[j].first];
			}else{
				int x = rec[i].second, y = rec[j].second;
				if(ans=="" || ans.size() > y-x+1)
					ans = s.substr(x, y-x+1);
				--cur[rec[i].first];
				++i;
			}
		}
		return ans;
	}
};