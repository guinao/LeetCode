#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		char buf[1024];
		int len = 0;
		while(n > 0){
			int t = n%26;
			if(t == 0){
				buf[len] = 'Z';
				n = n / 26 - 1;
			}else{
				buf[len] = 'A' + t - 1;
				n /= 26;
			}
			len++;
		}
		string ans;
		ans.resize(len);
		for(int i=len; i>0; --i){
			ans[len-i] = buf[i-1];
		}
		return ans;
	}
};

int main()
{
	Solution s;
	int n;
	while(EOF != scanf("%d", &n)){
		printf("%s\n", s.convertToTitle(n).c_str());
	}
	return 0;
}