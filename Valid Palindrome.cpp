#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if(s.length() <= 1)
			return true;
		bool flag = true;
		for(int i = 0,j = s.length() - 1 ; i < j; ++i,--j){
			while(i<j && !isalnum(s[i])) ++i;
			while(i<j && !isalnum(s[j])) --j;
//			printf("%c %c\n", s[i], s[j]);
			if(isalnum(s[i]) && isalnum(s[j]) && toupper(s[i]) != toupper(s[j])){
				flag = false;
				break;
			}
		}
		return flag;
    }
};

int main()
{
	Solution s;
	char buf[1024];
	while(NULL != gets(buf)){
		printf("%d\n", s.isPalindrome(buf)?1:0);
	}
	return 0;
}