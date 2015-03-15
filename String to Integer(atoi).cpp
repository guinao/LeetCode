#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include<string>
using namespace std;

class Solution {
public:
    int atoi(string str) {
		int flag = 0;
        long long ans = 0;
		int len = str.length();
		int i = 0;
		for(; i<len ;++i){
			if(str[i] == '-'){
				flag = -1;
				break;
			} else if(str[i] == '+'){
				flag = 1;
				break;
			} else if(isdigit(str[i])){
				flag = 1;
				--i;
				break;
			} else if(str[i] == ' '){
				continue;
			} else
				break;
		}
		for(++i; i<len && ans<INT_MAX; ++i){
			int a = str[i] - '0';
			if(0<=a && a<=9){
				ans = ans * 10 + a;
			}else{
				break;
			}
		}

		ans *= flag;
		if(INT_MIN >= ans)
			return INT_MIN;
		else if(ans >= INT_MAX)
			return INT_MAX;
		return ans;
    }
};

int main()
{
	Solution s;
	char buf[1024];
	while(EOF != scanf("%s", buf)){
		printf("%d\n", s.atoi(buf));
	}
	return 0;
}