#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	const static string letter[9];
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		ans.push_back("");
		for(int i=0; i<digits.length(); ++i){
			vector<string> tmp;
			int num = digits[i] - '1';
			if(num < 0) continue;
			for(int k=0; k<ans.size(); ++k)
				for(int j=0; j<letter[num].length(); ++j){
					tmp.push_back(ans[k]+letter[num][j]);
				}
				ans = tmp;
		}
		return ans;
	}
};

const string Solution::letter[9] = {"", "abc", "def", "ghi", "jkf", "mno", "pqrs", "tuv", "wxyz"};