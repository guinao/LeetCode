#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
	void reverse(string &s, int start, int end){
		while(start < end){
			swap(s[start], s[end-1]);
			++start, --end;
		}
	}
public:
	void reverseWords(string &s) {
		reverse(s, 0, s.length());
		int pos = 0;
		for(int i=0; i<s.length(); ++i){
			if(s[i] == ' '){
				reverse(s, pos, i);
				pos = i+1;
			}
		}
		reverse(s, pos, s.length());

		pos = 0;
		for(int i=0; i<s.length(); ++i){
			if(s[i] != ' '){
				if(pos != 0)
					s[pos++] = ' ';
				while(i<s.length() && s[i] != ' ')
					s[pos++] = s[i++];
			}
		}
		s = s.substr(0, pos);
	}
};

int main()
{
	char buf[32];
	Solution s;
	while(gets(buf)){
		string str(buf);
		s.reverseWords(str);
		printf("%s\n", str.c_str());
	}
	return 0;
}