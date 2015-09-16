#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int> si, ti;
		si.resize(s.length());
		ti.resize(t.length());

		unordered_map<char,int> mm;
		mm.clear();
		for(int i=0,cnt=0; i<s.length(); ++i){
			if(mm.find(s[i]) != mm.end()){
				si[i] = mm[s[i]];
			}else{
				si[i] = mm[s[i]] = ++cnt;
			}
		}

		mm.clear();
		for(int i=0,cnt=0; i<t.length(); ++i){
			if(mm.find(t[i]) != mm.end()){
				ti[i] = mm[t[i]];
			}else{
				ti[i] = mm[t[i]] = ++cnt;
			}
		}

		for(int i=0; i<si.size(); ++i){
			if(si[i] != ti[i])
				return false;
		}

		return true;
	}
};