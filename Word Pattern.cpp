#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		stringstream stream;
		string word;
		map<string, char> m;
		vector<bool> mark(26, false);
		stream<<str;
		int i=0;
		while(stream >> word){
			if(i >= pattern.length())
				return false;

			char c = pattern[i];
			if(m.find(word)!=m.end() && m[word] != c)
				return false;
			if(m.find(word)==m.end() && mark[c-'a'])
				return false;
			m[word] = c;
			mark[c-'a'] = true;
			++i;
		}

		if(i != pattern.length())
			return false;

		return true;
	}
};