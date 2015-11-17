#include <string>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
	static const char* lessThan20[];
	static const char* Tens[];
	static const char* Thousands[];
public:
	string numberToWords(int num) {
		if(num == 0)
			return "Zero";

		int cnt = 0;
		string ans = "";
		while(num > 0){
			ans = helper(num%1000) + " " + Thousands[cnt] + " " + ans;
			num /= 1000;
			++cnt;
		}
		ans.pop_back();
		ans.pop_back();
		if(ans[0] == ' ')
			ans = ans.substr(1);
		return ans;
	}

	string helper(int num){
		string ret = "";
		if(num >= 100){
			ret = ret + lessThan20[num/100-1] + " Hundred";
			num %= 100;
		}
		if(num >= 20){
			ret = ret + " " + Tens[num/10-2];
			num %= 10;
		}
		if(num > 0){
			ret = ret + " " + lessThan20[num-1];
		}
		return ret;
	}
};

const char* Solution::lessThan20[] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char* Solution::Tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* Solution::Thousands[] = {"", "Thousand", "Million", "Billion"};

int main()
{
	Solution s;
	int n;
	while(EOF != scanf("%d", &n)){
		printf("%s\n", s.numberToWords(n).c_str());
	}
	return 0;
}