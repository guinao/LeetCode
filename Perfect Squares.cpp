#include <queue>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		int ans = 0;
		queue<int> q;
		q.push(0);
		q.push(-1);
		vector<bool> mark(n, false);
		while(!q.empty()){
			int a = q.front();
			q.pop();
			if(a == -1){
				ans++;
				q.push(-1);
			}else{
				for(int i=1; i*i+a <= n; ++i){
					if(i*i+a == n)
						return ans+1;
					else if(!mark[i*i+a]){
						mark[i*i+a] = true;
						q.push(i*i+a);
					}
				}
			}
		}
		return 0;
	}
};