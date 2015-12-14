#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public :
	string getPermutation(int n, int k){
		string ans;
		vector<int> fact(n+1, 1);
		vector<bool> mark(n+1, false);
		for(int i=1; i<=n; ++i)
			fact[i] = fact[i-1] * i;

		mark[0] = true;
		--k;
		for(int i=n; i>0; --i){
			int cnt = k / fact[i-1] + 1;
			k = k % fact[i-1];
			for(int j=1; j<=n; ++j){
				if(!mark[j])
					--cnt;
				if(cnt == 0){
					mark[j] = true;
					ans.push_back(j + '0');
					break;
				}
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	int n, k;
//	while(EOF != scanf("%d %d", &n, &k)){
//		printf("%s\n", s.getPermutation(n, k).c_str());
//	}
//	return 0;
//}