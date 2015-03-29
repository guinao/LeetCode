#include <string>
#include <cstring>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> cnt;
		int head=0, tail=0;
		int ans = 0, cur = 0;
		while(tail < s.length()){
			while(cnt.count(s[tail]) > 0){
				cnt.erase(s[head]);
				--cur, ++head;
			}
			cnt.insert(s[tail]);
			++cur, ++tail;
			if(cur > ans) ans = cur;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	char buf[1024];
	while(EOF != scanf("%s", buf)){
		printf("%d\n", s.lengthOfLongestSubstring(buf));
	}
	return 0;
}