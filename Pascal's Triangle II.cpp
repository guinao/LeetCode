#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v;
		v.resize(rowIndex+1);
		for(int i=0; i<=rowIndex; ++i){
			double up=1.;
			double down=1.;
			int t = i > rowIndex-i ? i : rowIndex-i;

			for(int j=2; j<=rowIndex-t; ++j)
				down *= j;
			for(int j=t+1; j<=rowIndex; ++j)
				up *= j;
			v[i] = up / down;
		}
		return v;
	}
private:
	double f[1024];
};

int main()
{
	Solution s;
	int k;
	while(EOF != scanf("%d", &k)){
		vector<int> ans = s.getRow(k);
		for(int i=0; i<ans.size()-1; ++i)
			printf("%d ", ans[i]);
		printf("%d\n", ans.back());
	}
	return 0;
}