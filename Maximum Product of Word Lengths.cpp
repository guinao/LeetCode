#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
private:
	int encode(string &word){
		int a = 0;
		for(int i=0; i<word.size(); ++i){
			a |= 1<<(word[i]-'a');
		}
		return a;
	}
public:
	int maxProduct(vector<string>& words) {
		int ans = 0;
		vector<int> wb(words.size());
		sort(words.begin(), words.end(), compare);
		for(int i=0; i<words.size(); ++i)
			wb[i] = encode(words[i]);

		for(int i=0; i<words.size(); ++i){
			if(words[i].size() * words[i].size() <= ans) break;
			for(int j=i+1; j<words.size(); ++j){
				if(words[i].size()*words[j].size()<= ans) break;
				if((wb[i] & wb[j])==0)
					ans = words[i].size()*words[j].size();
			}
		}
		return ans;
	}

	static bool compare(string a, string b){
		return a.size() > b.size();
	}
};