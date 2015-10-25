#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > ans;
		vector<string> cur;
		recursive(ans, s, 0, cur);
		return ans;
	}

	void recursive(vector<vector<string>>& ans,  string& s, int pos, vector<string>& cur){
		if(pos == s.length()){
			ans.push_back(cur);
			return;
		}

		for(int i=pos+1; i<=s.length(); ++i){
			string ns = s.substr(pos, i-pos);
			if(isPalindrome(ns)){
				cur.push_back(ns);
				recursive(ans, s, i, cur);
				cur.pop_back();
			}
		}
	}

	bool isPalindrome(const string& a) const{
		for(int i=0,j=a.length()-1; i<j; ++i,--j)
			if(a[i] != a[j])
				return false;

		return true;
	}
};