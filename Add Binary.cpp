#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int lena = a.length();
		int lenb = b.length();
		int n = max(lena, lenb);
		char *tmp = (char*)malloc((n+2)*sizeof(char));
		memset(tmp, 0, (n+2)*sizeof(char));
		int inc = 0;
		for(int i=1; i<=n; ++i){
			int opa = i<=lena ? a[lena-i]-'0' : 0;
			int opb = i<=lenb ? b[lenb-i]-'0' : 0;
			tmp[n+1-i] = (opa+opb+inc)%2 + '0';
			inc = (opa+opb+inc) / 2;
		}
		tmp[0] = inc+'0';

		string ans("0");
		for(int i=0; i<n+2; ++i){
			if(tmp[i] == '1'){
				ans = string(tmp+i);
				break;
			}
		}
		free(tmp);

		return ans;
    }
};

int main()
{
	Solution s;
	printf("%s\n", s.addBinary("11111110", "111111110").c_str());
	scanf("%*c");
	return 0;
}