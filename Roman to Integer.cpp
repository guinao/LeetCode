#include <cstring>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	Solution()
	{
		mm.clear();
		mm['I'] = 1;
		mm['V'] = 5;
		mm['X'] = 10;
		mm['L'] = 50;
		mm['C'] = 100;
		mm['D'] = 500;
		mm['M'] = 1000;
	}

    int romanToInt(string s) {
		if(s.length() == 0) return 0;
		int ans = 0;
		int cnt = 0;
		int c, pre;
		pre = mm[toupper(s[0])];
        for(int i=0; i<s.length()-1; ++i){
			c = mm[toupper(s[i+1])];
			if(pre < c)
				ans -= pre;
			else
				ans += pre;
			pre = c;
		}
		ans += pre;
		return ans;
    }
private:
	map<char, int> mm;
};

int main()
{
	Solution s;
	char roman[128];
	while(EOF != scanf("%s", roman)){
		printf("%d\n", s.romanToInt(roman));
	}
	return 0;
}